//============================================================================
// Name        : BowlingTest.cpp
// Author      : vijay
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>
#include <Game.hpp>
using namespace std;

TEST(BowlingTest, myTest1)
{
    Player p1("Vijay",1 , 0);
	EXPECT_EQ(0, p1.GetCurrentScore());
	p1.rolls(5);
	p1.score();
	EXPECT_EQ(5, p1.GetCurrentScore());
}
TEST(BowlingTest, myTest2)
{
    Player p1("Vijay",1 , 0);
    for(int i = 0 ; i <20 ; i++)
    {
    	p1.rolls(1);
    }
    p1.score();
	EXPECT_EQ(20, p1.GetCurrentScore());
}

//Normal Scenario
TEST(BowlingTest, myTest3)
{
    Player p1("Vijay",1 , 0);
    for(int i = 0 ; i <20 ; i++)
    {
    	p1.rolls(2);
    }
    p1.score();
	EXPECT_EQ(40, p1.GetCurrentScore());
}
//Spare Bonus
TEST(BowlingTest, myTest4)
{
    Player p1("Vijay",1 , 0);
    for(int i = 0 ; i <20 ; i++)
    {
    	p1.rolls(5);
    }
    p1.score();
	EXPECT_EQ(145, p1.GetCurrentScore());
}

//All the shot is strike bonus 10
TEST(BowlingTest, myTest5)
{
    Player p1("Vijay",1 , 0);
    for(int i = 0 ; i <20 ; i++)
    {
    	p1.rolls(10);
    }
    p1.score();
	EXPECT_EQ(300, p1.GetCurrentScore());
}

//Given Scenarion in the Image verified
TEST(BowlingTest, myTest6)
{
    Player p1("Vijay",1 , 0);
	p1.rolls(1);
	p1.rolls(4);
	p1.rolls(4);
	p1.rolls(5);
	p1.rolls(6);
	p1.rolls(4);
	p1.rolls(5);
	p1.rolls(5);
	p1.rolls(10);
	p1.rolls(0);
	p1.rolls(1);
	p1.rolls(3);
	p1.rolls(7);
	p1.rolls(6);
	p1.rolls(4);
	p1.rolls(10);
	p1.rolls(2);
	p1.rolls(8);
	p1.rolls(6);
    p1.score();
    p1.Display();
	EXPECT_EQ(133, p1.GetCurrentScore());
}

TEST(BowlingTest, myTest7)
{
    Player p1("Vijay",1 , 0);
    p1.Display();
}
int main(int argc , char **argv) {
	testing::InitGoogleTest(&argc , argv);
	return RUN_ALL_TESTS();
}
