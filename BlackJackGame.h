/*
 * BlackJackGame.h
 *
 *  Created on: Oct 4, 2020
 *      Author: Saurabh
 */

#ifndef BLACKJACKGAME_H_
#define BLACKJACKGAME_H_

#include <array>
#include <vector>

#define PLAYER_MAX_SCORE 21
#define SIXTEEN 16
#define TEN 10
#define ONE 1

class Card
{
public:
  enum class Rank {
    RANK_UNDEFINED,
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
  };

  enum class Suit {
    SUIT_UNDEFINED,
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS
  };

private:
  Suit m_suit;
  Rank m_rank;

public:
  Card(Suit suit = Suit::SUIT_UNDEFINED, Rank rank = Rank::RANK_UNDEFINED)
    : m_suit{ suit }, m_rank{ rank }
  {
  }

  std::string getRankTypeString() const;

  std::string getSuitTypeString() const;

  void print() const;

  int value() const;
};

class Deck
{
private:
  std::array<Card, 52> m_deck;
  int m_currentCardIndex{ 0 };

public:
  Deck()
  {
    int numCards{ 0 };
    for (auto i = static_cast<int>(Card::Suit::SUIT_CLUB); i < static_cast<int>(Card::Suit::MAX_SUITS); ++i) {
      for (auto j = static_cast<int>(Card::Rank::RANK_2); j < static_cast<int>(Card::Rank::MAX_RANKS); ++j) {
        m_deck[numCards] = { static_cast<Card::Suit>(i), static_cast<Card::Rank>(j) };
        numCards++;
      }
    }
  }

  void print() const;

  void shuffle();

  const Card &dealCard();
};

class Player
{
private:
  std::vector<Card> m_CardList{};
  int m_score{ 0 };

public:
  Player()
  {
  }

  bool isBusted() const;

  void drawCard(Deck &deck);

  int getScore() const;
};

#endif /* BLACKJACKGAME_H_ */
