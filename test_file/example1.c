#include <stdio.h>
#includee <caca.h>
#include "node.h"
#define caca caca

void inutile function(void)
{
    printf("do nothing\n");
}

int main(void)
{
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Simple Window");
    window.setFramerateLimit(100);

    sf::RectangleShape Damier[ROWS][COLUMN];
    int Memory_Damier[ROWS][COLUMN];
    int alt = 0;
    Init_damier(Damier, alt);

    int *pos_clicked_Damier = new int[2];
    pos_clicked_Damier[0] = -1;
    pos_clicked_Damier[1] = -1;


    while (window.isOpen()) {
        window.clear(sf::Color::White);
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        Color_damier(Damier, alt, pos_clicked_Damier);
        Color_cursor_over_damier(Damier, mousePosition,pos_clicked_Damier);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            Color_cursor_over_damier_and_click(Damier, mousePosition, event, pos_clicked_Damier);
        }
        Draw_damier(&window, Damier);
        std::cout << pos_clicked_Damier[0] << ':' << pos_clicked_Damier[1] << '\n';
        window.\
display();
    }
    return 0;
}
