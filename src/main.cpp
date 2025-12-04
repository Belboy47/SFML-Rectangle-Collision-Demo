#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
int main()
{
    // create each rectangle and variables needed
    int numberOfRecs{};
    std::cout << "Enter number of rectangles: ";
    std::cin >> numberOfRecs;
    std::vector<sf::Vector2f> nextPos(numberOfRecs);
    std::vector<sf::Vector2f> velocity(numberOfRecs);
    std::vector<sf::RectangleShape> recs(numberOfRecs);
    std::vector<sf::Vector2f> recsPos(numberOfRecs);
    srand(time(NULL));

    // create window
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "Hello SFML");
    window.setFramerateLimit(60);
    //customize each rectangle
    for (int i = 0; i < numberOfRecs; i++)
    {
        recs[i] = sf::RectangleShape(sf::Vector2f(50, 50));
        velocity[i] = sf::Vector2f(rand() % 10 + 1, rand() % 10 + 1);
        recs[i].setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));

        bool valid;
        do
        {
            valid = true;
            recs[i].setPosition(sf::Vector2f(rand() % 750, rand() % 550));

            for (int j = 0; j < i; j++)
            {
                if (recs[i].getGlobalBounds().findIntersection(recs[j].getGlobalBounds()))
                {
                    valid = false;
                    break;
                }
            }
        } while (!valid);
        recsPos[i] = recs[i].getPosition();
    }
    // calculation and display
    while (window.isOpen())
    {
        window.handleEvents([&](const sf::Event::Closed&) { window.close(); });
        window.clear(sf::Color::Black);

        // checks wall collision
        for (int i = 0; i < numberOfRecs; i++)
        {
            window.draw(recs[i]);

            if (nextPos[i].x > 750 || nextPos[i].x < 0)
            {
                velocity[i].x = -velocity[i].x;
            }
            if (nextPos[i].y > 550 || nextPos[i].y < 0)
            {
                velocity[i].y = -velocity[i].y;
            }
            recs[i].move(velocity[i]);
            recsPos[i] = recs[i].getPosition();
        }
        // checks collision
        for (int i = 0; i < numberOfRecs; i++)
        {
            for (int j = i + 1; j < numberOfRecs; j++)
            {
                nextPos[i] = recs[i].getPosition() + velocity[i];
                nextPos[j] = recs[j].getPosition() + velocity[j];
                if (nextPos[i].x + 50 > nextPos[j].x && nextPos[i].x < nextPos[j].x + 50 &&
                    nextPos[i].y + 50 > nextPos[j].y && nextPos[i].y < nextPos[j].y + 50)
                {

                    velocity[i] = -velocity[i];
                    velocity[j] = -velocity[j];
                    recs[i].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
                    recs[j].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
                }
            }
        }
        window.display();
    }
}