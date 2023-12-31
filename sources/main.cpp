#include <SFML/Graphics.hpp>

#include "headers/dimension.h"
#include "headers/field.h"
#include "headers/menu.h"

int main()
{
    //  Drawing the window and frame
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * COLUMNS + FRAME_THICK * 2, CELL_SIZE * ROWS + FRAME_THICK * 2 + FRAME_HEAD), "Minesweeper", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    //  Frame
    sf::Texture t_frame;
    t_frame.loadFromFile("sources/textures/Frame_v3.1264.png");
    sf::Sprite s_frame(t_frame);
    //  Cells
    sf::Texture t_cell;
    t_cell.loadFromFile("sources/textures/Cells_v2.64.png");
    sf::Sprite s_cell(t_cell);
    //  Button
    sf::Texture t_guy;
    t_guy.loadFromFile("sources/textures/Guy_v2.64.png");
    sf::Sprite s_guy(t_guy);
    //  Digits
    sf::Texture t_digits;
    t_digits.loadFromFile("sources/textures/Digits_v2.64.png");
    sf::Sprite s_digits(t_digits);

    Field field;        //  It's field
    Menu menu;          //  It's menu
    bool button_state = false;

    while (window.isOpen()) {
        sf::Event event;
        window.clear();

        //  Frame
        s_frame.setPosition(0, 0);
        window.draw(s_frame);
        //  Cells
        for (int i = 0; i < COLUMNS; i++) {     //  Cut and paste
            for (int j = 0; j < ROWS; j++) {
                s_cell.setTextureRect(sf::IntRect(field.get_view(i, j) * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
                s_cell.setPosition((i * CELL_SIZE) + FRAME_THICK, (j * CELL_SIZE) + FRAME_THICK + FRAME_HEAD);
                window.draw(s_cell);
            }
        }
        //  Button
        s_guy.setTextureRect(sf::IntRect(menu.get_guy_state() * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
        s_guy.setPosition(GUY_X, GUY_Y);
        window.draw(s_guy);
        //  Timer
        for (int i = 0; i < 2; i++) {           //  Seconds
            s_digits.setTextureRect(sf::IntRect(menu.get_timer(i) * DIGIT_WIDTH, 0, DIGIT_WIDTH, DIGIT_HEIGHT));
            s_digits.setPosition(TIMER_SEC_X + (1 - i) * DIGIT_WIDTH, TIMER_Y);
            window.draw(s_digits);
        }
        for (int i = 2; i < 4; i++) {           //  Minutes
            s_digits.setTextureRect(sf::IntRect(menu.get_timer(i) * DIGIT_WIDTH, 0, DIGIT_WIDTH, DIGIT_HEIGHT));
            s_digits.setPosition(TIMER_MIN_X + (3 - i) * DIGIT_WIDTH, TIMER_Y);
            window.draw(s_digits);
        }
        //  Counter
        for (int i = 0; i < 2; i++) {
            s_digits.setTextureRect(sf::IntRect(menu.get_counter(i) * DIGIT_WIDTH, 0, DIGIT_WIDTH, DIGIT_HEIGHT));
            s_digits.setPosition(COUNTER_X + (1 - i) * (CELL_SIZE / 2), COUNTER_Y);
            window.draw(s_digits);
        }

        window.display();

        sf::Vector2i pos = sf::Mouse::getPosition(window);  //  Where is the mouse?
        int field_x = (pos.x - FRAME_THICK) / CELL_SIZE;
        int field_y = (pos.y - FRAME_THICK - FRAME_HEAD) / CELL_SIZE;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();                             //  Bye!

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Q)
                    window.close();                         //  Bye-bye!
                if (event.key.code == sf::Keyboard::R) {
                    menu.restart();                         //  Oh, hi Mark!
                    field.generate();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (field_x >= 0 && field_x < ROWS && field_y >= 0 && field_y < COLUMNS) {  //  Don't touch the frame! -_-
                    if (event.key.code == sf::Mouse::Right)
                        field.flag_cell(field_x, field_y);                  //  Are you sure?
                    else if (event.key.code == sf::Mouse::Left)
                        field.open_cell(field_x, field_y);                  //  You are.
                }
                else if (pos.x >= GUY_X && pos.x < GUY_X + CELL_SIZE && pos.y >= GUY_Y && pos.y < GUY_Y + CELL_SIZE) {
                    if (event.key.code == sf::Mouse::Left) {
                        button_state = true;
                        menu.set_button_state(button_state);                   //  What's with the face?
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased && button_state) {
                menu.restart();                         //  Oh, hi Mark again!
                field.generate();
                button_state = false;
            }
        }

        //  Menu activity
        menu.check_menu(field.get_game_over(), field.get_victory(), field.get_flags());
    }
    return 0;
}