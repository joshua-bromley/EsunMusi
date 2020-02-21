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
	int getId() const {
		return id;
	}

	const std::string& getName() const {
		return name;
	}

	const int* getPrices() const {
		return prices;
	}

private:
	int id;
	std::string name;
	int prices[4];

	sf::Text sign;
};



#endif /* MARKET_H_ */
