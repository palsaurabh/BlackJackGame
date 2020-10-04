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

	  Player player;
	  Player dealer;

	  player.drawCard(deck);
	  std::cout<<"Player Score is :"<<player.getScore()<<"\n";

	  dealer.drawCard(deck);
	  std::cout<<"Dealer Score is :"<<dealer.getScore()<<"\n";

	  player.drawCard(deck);
	  std::cout<<"Player Score is :"<<player.getScore()<<"\n";

	  dealer.drawCard(deck);
	  std::cout<<"Dealer Score is :"<<dealer.getScore()<<"\n";


	  player.drawCard(deck);
	  std::cout<<"Player Score is :"<<player.getScore()<<"\n";

	  dealer.drawCard(deck);
	  std::cout<<"Dealer Score is :"<<dealer.getScore()<<"\n";

	  if(player.isBusted())
	  {
		  std::cout<<"Player is busted\n";
	  }

	  if(dealer.isBusted())
	  {
		  std::cout<<"Dealer is busted\n";
	  }
	  return 0;
}


