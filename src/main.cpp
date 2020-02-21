//============================================================================
// Name        : testSFML.cpp
// Author      : Joshua
// Version     :
// Copyright   : Your copyright notice
// Description : Testing SFML Library
//============================================================================

#include <iostream>
#include <SFML\Graphics.hpp>


using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "EsunMusi");
    window.setFramerateLimit(60);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.display();
    }
	cout << "Hello" << endl; // prints Hello
	return 0;
}
