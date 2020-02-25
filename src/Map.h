/*
 * Map.h
 *
 *  Created on: Feb 15, 2020
 *      Author: joshu
 */

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics.hpp>

class Map{
public:
	Map();
	int move(int);
	void draw(sf::RenderWindow&);
	void setFullScreenMode(bool);
private:
	sf::RectangleShape sprite;
	sf::RectangleShape exitSprite;
	sf::CircleShape cities[5];
	sf::Text labels[5];

	bool fullscreen;


};

int Map::move(int location){
	while(true){
		if(true /*Left Click*/){
			int x = 0; //Click Location
			int y = 0;
			if(true /*Location 0*/ && location != 0 ){
				cities[location].setFillColor(sf::Color::Blue);
				cities[0].setFillColor(sf::Color::Red);
				return 0;
			}else if(true /*Location 1*/ && location != 1){
				cities[location].setFillColor(sf::Color::Blue);
				cities[1].setFillColor(sf::Color::Red);
				return 1;
			}else if(true /*Location 2*/ && location != 2){
				cities[location].setFillColor(sf::Color::Blue);
				cities[2].setFillColor(sf::Color::Red);
				return 2;
			}else if(true /*Location 3*/ && location != 3){
				cities[location].setFillColor(sf::Color::Blue);
				cities[3].setFillColor(sf::Color::Red);
				return 3;
			}else if(true /*Location 4*/ && location != 4){
				cities[location].setFillColor(sf::Color::Blue);
				cities[4].setFillColor(sf::Color::Red);
				return 4;
			}else if(true /*Exit Marker*/){
				return -1;
			}
		}
	}
}

void Map::setFullScreenMode(bool full){
	if(full){
		fullscreen = true;
		//Adjust sizes and positions
	}else{
		fullscreen = false;
		//Adjust sizes and positions
	}
}

void Map::draw(sf::RenderWindow& window){
	window.draw(sprite);
	if(fullscreen){
		window.draw(exitSprite);
	}
	for(int i = 0; i < 5; i++){
		window.draw(cities[i]);
	}
}



#endif /* MAP_H_ */
