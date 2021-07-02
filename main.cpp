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
  bool someOneBusted{ false };
  //	int someOneWon{0};
  int hitOrstand{ -1 };
  Deck deck{};
  deck.shuffle();
  //	deck.print();

  Player player;
  Player dealer;

  dealer.drawCard(deck);
  std::cout << "Dealer got: " << dealer.getScore() << "\n";

  player.drawCard(deck);
  player.drawCard(deck);
  std::cout << "You got: " << player.getScore() << "\n";

  //	while(!someOneBusted)
  {
    while (hitOrstand != 0) {
      std::cout << "Hit / stand? Choose 1/0:";
      std::cin >> hitOrstand;

      if (hitOrstand == 1) {
        player.drawCard(deck);
        std::cout << "You got: " << player.getScore() << "\n";
        if (player.isBusted()) {
          std::cout << "You Busted!! You've Lost\n";
          break;
        }
      } else {
        dealer.drawCard(deck);
        std::cout << "Dealer got: " << dealer.getScore() << "\n";

        if (dealer.getScore() <= SIXTEEN) {
          dealer.drawCard(deck);
          std::cout << "Dealer got: " << dealer.getScore() << "\n";

          if (dealer.isBusted()) {
            std::cout << "Dealer is Busted!! You've won\n";
            break;
          }
        }

        break;
      }
    }
    someOneBusted = player.isBusted() || dealer.isBusted();
    if (!someOneBusted) {
      if (player.getScore() > dealer.getScore()) {
        std::cout << "You've Won\n";
      } else {
        std::cout << "You've Lost\n";
      }
    }
  }

  return 0;
}
