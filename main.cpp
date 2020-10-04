/*
 * main.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: Saurabh
 */
#include <iostream>
#include "BlackJackGame.h"


int main()
{
	  Deck deck{};
//	  deck.print();
	  deck.shuffle();
	  deck.print();
	  std::cout<<"dealt card:\n";
	  deck.dealCard().print();
	  std::cout<<"dealt card:\n";
	  deck.dealCard().print();

	  return 0;
}


