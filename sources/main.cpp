#include <SFML/Graphics.hpp>

#include "headers/dimension.h"
#include "headers/field.h"

int main()
{
    //  Drawing the window and frame
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * COLUMNS + FRAME_THICK * 2, CELL_SIZE * ROWS + FRAME_THICK * 2 + FRAME_HEAD), "Minesweeper", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    sf::Texture t_frame;
    t_frame.loadFromFile("sources/textures/Frame_v2.1264.png");
    sf::Sprite s_frame(t_frame);
    sf::Texture t_cell;
    t_cell.loadFromFile("sources/textures/MinesweeperSprite_v1.64.png");
    sf::Sprite s_cell(t_cell);
    sf::Texture t_guy;
    t_guy.loadFromFile("sources/textures/Guy_v1.64.png");
    sf::Sprite s_guy(t_guy);

    Field field;        //  It's field

    int guy_state = 0;

    while (window.isOpen()) {
        sf::Event event;
        window.clear(sf::Color::White);
        s_frame.setPosition(0, 0);
        window.draw(s_frame);

        for (int i = 0; i < COLUMNS; i++)       //  Cut and paste
            for (int j = 0; j < ROWS; j++) {
                s_cell.setTextureRect(sf::IntRect(field.get_view(i, j) * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
                s_cell.setPosition(i * CELL_SIZE + FRAME_THICK, j * CELL_SIZE + FRAME_THICK + FRAME_HEAD);
                window.draw(s_cell);
            }
        
        s_guy.setTextureRect(sf::IntRect(guy_state * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
        s_guy.setPosition(GUY_X, GUY_Y);
        window.draw(s_guy);

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
                if (event.key.code == sf::Keyboard::R)
                    field.generate();                       //Oh, hi Mark!
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (field_x >= 0 && field_x < ROWS && field_y >= 0 && field_y < COLUMNS) {  //  Don't touch the frame! -_-
                    if (event.key.code == sf::Mouse::Right)
                        field.flag_cell(field_x, field_y);                  //  Are you sure?
                    else if (event.key.code == sf::Mouse::Left)
                        field.open_cell(field_x, field_y);                  //  You are.
                }
                else if (pos.x >= GUY_X && pos.x < GUY_X + CELL_SIZE && pos.y >= GUY_Y && pos.y < GUY_Y + CELL_SIZE) {
                    guy_state++;
                    field.generate();
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
                if (pos.x >= GUY_X && pos.x < GUY_X + CELL_SIZE && pos.y >= GUY_Y && pos.y < GUY_Y + CELL_SIZE)
                    guy_state = 0;
        }
    }
    return 0;
}