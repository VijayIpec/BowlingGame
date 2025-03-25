/*
 * Game.hpp
 *
 *  Created on: 23 Mar 2025
 *      Author: vpsingh
 */

#ifndef GAME_HPP_
#define GAME_HPP_
#include <string>
using namespace std;

class BowlingGame{
public:
	int TotalCount[21] = {0};
	int CurrentCount = 0;
	virtual void rolls(int) = 0;
	virtual void score() = 0;
	bool isThisStrikeShot(int);
	bool isThisSpareShot(int);
	int NormalFrameBall(int);
	int StrikeBonus(int);
	int SpareBonus(int);
	virtual ~BowlingGame(){}
};

class Player:public BowlingGame{
	string playerName_;
	int Id_;
	int Score_;
public:
	Player(string name , int id, int score );
	 void rolls(int);
	 void score();
	 int GetCurrentScore();
	 void Display()const;
};

#endif /* GAME_HPP_ */
