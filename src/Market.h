/*
 * Market.h
 *
 *  Created on: Feb 12, 2020
 *      Author: joshu
 */

#ifndef MARKET_H_
#define MARKET_H_

#include <SFML/Graphics.hpp>

class Market{
public:
	Market(std::string, sf::Font, int);

	int getId() const {
		return id;
	}

	const std::string& getName() const {
		return name;
	}

	const int* getPrices() const {
		return prices;
	}

	void adjustPrices(int,int);

	void draw(sf::RenderWindow&);

private:
	int id;
	std::string name;
	int prices[4];

	sf::Text sign;
	sf::RectangleShape background;
};

void Market::adjustPrices(int type, int amount){
	prices[type] += amount;
}

void Market::draw(sf::RenderWindow& window){
	window.draw(background);
	window.draw(sign);
}

Market::Market(std::string iName, sf::Font font, int i){
	id = i;
	name = iName;
	sign.setFont(font);
	sign.setString(name);
	sign.setCharacterSize(20);
	sign.setPosition(sf::Vector2f(450,100));

	for(int i = 0; i < 4; i++){
		int a = rand()%4 + 1;
		prices[i] = a;
	}

}

#endif /* MARKET_H_ */
