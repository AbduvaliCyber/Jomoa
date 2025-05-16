#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Stakan chizish - SFML");

    // Stakan tanasi uchun to‘rtburchak
    sf::RectangleShape glassBody(sf::Vector2f(150.f, 200.f));
    glassBody.setPosition(125.f, 100.f);
    glassBody.setFillColor(sf::Color(173, 216, 230)); // light blue
    glassBody.setOutlineThickness(2);
    glassBody.setOutlineColor(sf::Color::Black);

    // Stakan pastidagi oval (suv yuzasi)
    sf::CircleShape waterSurface(70.f, 100); // 100 burchakli doira yaqin ovalga o‘xshaydi
    waterSurface.setPosition(130.f, 280.f);
    waterSurface.setFillColor(sf::Color(135, 206, 235)); // sky blue
    waterSurface.setOutlineThickness(2);
    waterSurface.setOutlineColor(sf::Color::Blue);

    // Yorqinlik uchun oq ovoid (kichik doira)
    sf::CircleShape shine(20.f);
    shine.setPosition(230.f, 120.f);
    shine.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(glassBody);
        window.draw(waterSurface);
        window.draw(shine);
        window.display();
    }

    return 0;
}
