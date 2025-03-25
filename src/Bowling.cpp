//============================================================================
// Name        : Bowling.cpp
// Author      : vijay
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Game.hpp"
using namespace std;

int main() {
	Player p1("Vijay",1,0);
	p1.rolls(5);
	p1.score();
	p1.Display();
	return 0;
}
