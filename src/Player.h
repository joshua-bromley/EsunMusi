/*
 * Player.h
 *
 *  Created on: Feb 12, 2020
 *      Author: joshu
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>

class Player{
public:
	Player();

	int getCapacity() const {
		return capacity;
	}

	void setCapacity(int capacity) {
		this->capacity = capacity;
	}

	void changeCapacity(int change){
		capacity += change;
	}

	int getDefence() const {
		return defence;
	}

	void setDefence(int defence) {
		this->defence = defence;
	}

	void changeDefence(int change){
		defence += change;
	}

	int getEfficiency() const {
		return efficiency;
	}

	void setEfficiency(int efficiency) {
		this->efficiency = efficiency;
	}

	void changeEfficiency(int change){
		efficiency += change;
	}

	void

	int getMoney() const {
		return money;
	}

	void setMoney(int money) {
		this->money = money;
	}

	void changeMoney(int change){
		money += change;
	}

	int getSpeed() const {
		return speed;
	}

	void setSpeed(int speed) {
		this->speed = speed;
	}

	void changeSpeed(int change){
		speed += change;
	}

	int getPossesion() const {
		return possesion;
	}

	void setPossesion(int possesion) {
		this->possesion = possesion;
	}

	int getResource(int);

	void addResource(int,bool);

	int getLocation() const {
		return location;
	}

	void setLocation(int location) {
		this->location = location;
	}

	void draw(sf::RenderWindow&);

private:
	int money;
	int possesion;
	int capacity;
	int speed;
	int efficiency;
	int defence;
	int location;
	int resources[4];

	sf::RectangleShape ship;

};

Player::Player(){
	money = 20;
	possesion = 0;
	capacity = 5;
	speed = 1;
	efficiency = 1;
	defence = 1;
	location = 0;
	resources = {};

	ship.setSize(sf::Vector2f(200,100));
	ship.setFillColor(sf::Color::Blue);
	ship.setPosition(sf::Vector2f(400,700));
}

void Player::addResource(int type, bool subtract){
	if(subtract){
		resources[type]--;
		possesion--;
	}else{
		resources[type]++;
		possesion++;
	}
}

int Player::getResource(int type){
	return resources[type];
}

void Player::draw(sf::RenderWindow& window){
	window.draw(ship);
}

#endif /* PLAYER_H_ */
