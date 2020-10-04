#include <algorithm>
#include <array>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>
#include "BlackJackGame.h"


std::string Card::getRankTypeString() const
{
	switch(m_rank)
	{
	case Rank::RANK_2: return "2";
		break;
	case Rank::RANK_3: return "3";
		break;
	case Rank::RANK_4: return "4";
		break;
	case Rank::RANK_5: return "5";
		break;
	case Rank::RANK_6: return "6";
		break;
	case Rank::RANK_7: return "7";
		break;
	case Rank::RANK_8: return "8";
		break;
	case Rank::RANK_9: return "9";
		break;
	case Rank::RANK_10: return "10";
		break;
	case Rank::RANK_JACK: return "JACK";
		break;
	case Rank::RANK_QUEEN: return "QUEEN";
		break;
	case Rank::RANK_KING: return "KING";
		break;
	case Rank::RANK_ACE: return "ACE";
		break;
	default: return "??";
		break;
	}
}

std::string Card::getSuitTypeString() const
{
	switch(m_suit)
	{
	case Suit::SUIT_CLUB : return "CLUB";
	case Suit::SUIT_DIAMOND : return "DIAMOND";
	case Suit::SUIT_HEART : return "HEART";
	case Suit::SUIT_SPADE : return "SPADE";
	default : return "??";
	}
}

void Card::print() const
{
	std::cout<<"Card : "<< getRankTypeString() << " of "<< getSuitTypeString()<<"'s\n";
}

int Card::value() const
{
	if(m_rank == Rank::RANK_JACK || m_rank == Rank::RANK_QUEEN ||
		m_rank == Rank::RANK_KING)
	{
		return 10;
	}
	else if(m_rank == Rank::RANK_ACE)
	{
		return 1;
	}
	else
	{
		return (static_cast<int>(m_rank) + 1);
	}
}


void Deck::print() const
{
	for(const auto &card : m_deck)
	{
		card.print();
	}
}

void Deck::shuffle()
{
	static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
	std::shuffle(m_deck.begin(), m_deck.end(), mt);
}

const Card& Deck::dealCard()
{
	assert(m_currentCardIndex < static_cast<int>(m_deck.size()));
	return m_deck[m_currentCardIndex++];
}

bool Player::isBusted()
{
	return(m_score > PLAYER_MAX_SCORE);
}

void Player::drawCard(Deck &deck)
{
	m_CardList.push_back(deck.dealCard());
	m_score += m_CardList.back().value();
}

int Player::getScore()
{
	return m_score;
}

