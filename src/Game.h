/*
 * Game.h
 *
 *  Created on: Feb 12, 2020
 *      Author: joshu
 */

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Market.h"
#include "Map.h"

class Game{
public:
	Game();
	void run(sf::RenderWindow&);
private:
	Player player;
	Market markets[5];
	Map map;

	int date;

	sf::Text resourcePurchase[4];
	sf::Text upgradeText[4];
	sf::Text wealth;
	sf::Text inventory[5];
	sf::Text clock;

	void update();
	void upgrade(int);
	void buyResources(int, bool);
	void move();
	void draw(sf::RenderWindow&);
	std::string iToS(int);
};

void Game::run(sf::RenderWindow& window){
	while(window.isOpen() && true /*Game running condition*/){
		if(false/*Resource Click Condition*/){
			if(false/*Left Click*/){
				int type = 0; /*Do math to assign type*/
				buyResources(type,false);
			}else{/*Right Click*/
				int type = 0; /*Do math to assign type*/
				buyResources(type,true);
			}
		}else if(false/*Upgrade Click Condition*/){
			int type = 0; //Do math to assign type
			upgrade(type);
		}else if(false/*Map is clicked*/){
			move();
		}
	}
}

void Game::buyResources(int type, bool sell){
	if(!sell){
		if(player.getMoney() >= markets[player.getLocation()].getPrices()[type] && player.getPossesion() < player.getCapacity()){
			player.addResource(type,false);
			player.changeMoney(-markets[player.getLocation()].getPrices()[type]);
		}
	}else{
		if(player.getResource(type) > 0){
			player.addResource(type,true);
			player.changeMoney(-markets[player.getLocation()].getPrices()[type]);
		}
	}
}

void Game::upgrade(int type){
	switch(type){
	case 0:
		if(player.getMoney() > 2*player.getCapacity()){
			player.changeMoney(-2*player.getCapacity());
			player.changeCapacity(5);
		}
		break;
	case 1:
			if(player.getMoney() > 2*player.getSpeed()){
				player.changeMoney(-2*player.getSpeed());
				player.changeSpeed(5);
			}
			break;
	case 2:
			if(player.getMoney() > 2*player.getEfficiency()){
				player.changeMoney(-2*player.getEfficiency());
				player.changeEfficiency(5);
			}
			break;
	case 3:
			if(player.getMoney() > 2*player.getDefence()){
				player.changeMoney(-2*player.getDefence());
				player.changeDefence(5);
			}
			break;

	}
}

void Game::move(){
	map.setFullScreenMode(true);
	int destination = map.move(player.getLocation());
	map.setFullScreenMode(false);
	if(destination >= 0){
		player.setLocation(destination);
		date += 5;
	}

}

void Game::update(){
	for(int i = 0; i < 4; i++){
		resourcePurchase[i].setString(iToS(markets[player.getLocation()].getPrices()[i]));
	}

	wealth.setString(iToS(player.getMoney()));

	inventory[0].setString(iToS(player.getPossesion()) + "/" + iToS(player.getCapacity()));

	for(int i = 0; i < 4; i++){
		inventory[i+1].setString(iToS(player.getResource(i)));
	}

	upgradeText[0].setString(iToS(2*player.getCapacity()));
	upgradeText[1].setString(iToS(2*player.getSpeed()));
	upgradeText[2].setString(iToS(2*player.getEfficiency()));
	upgradeText[3].setString(iToS(2*player.getDefence()));

	clock.setString(iToS(date));

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			int a = rand()%5 - 2;
			markets[i].adjustPrices(j,a);
		}
	}


}

void Game::draw(sf::RenderWindow& window){
	markets[player.getLocation()].draw(window);

	for(int i = 0; i < 4; i++){
		window.draw(resourcePurchase[i]);
		window.draw(upgradeText[i]);
		window.draw(inventory[i]);
	}

	window.draw(inventory[5]);
	window.draw(wealth);
	window.draw(clock);

	player.draw(window);

	map.draw(window);
}

std::string Game:: iToS(int a){
	std::string b = "";
	int c = std::log(a);
	int d = std::pow(10,c);
	while(a > 0){
		b.push_back('0' + a/d);
		a /= 10;
		d /= 10;
	}
	return b;
}




#endif /* GAME_H_ */
