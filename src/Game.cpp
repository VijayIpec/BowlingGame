/*
 * Bowling.cpp
 *
 *  Created on: 23 Mar 2025
 *      Author: vpsingh
 */
#include <iostream>
#include "Game.hpp"
using namespace std;
#define MAX_PIN_IN_SHOT 10
#define TOTAL_FRAME 10

//This api checked wheather this is a strike
bool BowlingGame::isThisStrikeShot(int frameIndex)
{
   return(TotalCount[frameIndex] == MAX_PIN_IN_SHOT);
}
//check for spare
bool BowlingGame::isThisSpareShot(int frameIndex)
{
	 return(( TotalCount[frameIndex] + TotalCount[frameIndex + 1]) == MAX_PIN_IN_SHOT);
}
//if no strike no spare
int BowlingGame::NormalFrameBall(int frameIndex)
{
   return(TotalCount[frameIndex] + TotalCount[frameIndex + 1]);
}

//Bonus is  next shot
int BowlingGame::SpareBonus(int frameIndex)
{
	 return(TotalCount[frameIndex + 2]);
}
//Bonus is next + next to next
int BowlingGame::StrikeBonus(int frameIndex)
{
	 return(TotalCount[frameIndex + 1] + TotalCount[frameIndex + 2]);
}
//constructor
Player::Player(string name , int id, int score )
{
	playerName_ = name;
	Id_ = id;
	Score_ = score;
}
//store every shot in aray index total 21 index
void Player::rolls(int pin)
{
	TotalCount[CurrentCount++] = pin;
}

int Player::GetCurrentScore()
{
  return Score_	;
}
//this is api is use to cal the score of each player
void Player::score()
{
	 int frameIndex = 0;
	 for(int frame = 0 ; frame < TOTAL_FRAME ; frame++)
	  {
		 if(isThisStrikeShot(frameIndex))
		 {
			 Score_ += MAX_PIN_IN_SHOT + StrikeBonus(frameIndex);
			 frameIndex++;
		 }
		 else if(isThisSpareShot(frameIndex))
		 {
			 Score_ += MAX_PIN_IN_SHOT + SpareBonus(frameIndex);
			 frameIndex += 2;
		 }
		 else
		 {
			 Score_ += NormalFrameBall(frameIndex);
			 frameIndex += 2;
		 }

		 cout<<"Frame "<<frame<<"score = "<<Score_<<endl;
	 }
}
//const function to display the score
void Player::Display()const
{
	  cout<<"playerName = "<<" "<<playerName_<<"  ";
	  cout<<"playerId = "<<" "<<Id_<<"  ";
	  cout<<"playerScore = "<<" "<<Score_<<"  ";
}
