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

//
//struct Player
//{
//	int score{ };
//};
//
//using deck_type = std::array<Card, 52>;
//using index_type = deck_type::size_type;
//
//// Maximum score before losing.
//constexpr int maximumScore
//{ 21 };
//
//// Minium score that the dealer has to have.
//constexpr int minimumDealerScore
//{ 17 };
//
//void printCard(const Card &card)
//{
//	switch (card.rank)
//	{
//	case CardRank::RANK_2:
//		std::cout << '2';
//		break;
//	case CardRank::RANK_3:
//		std::cout << '3';
//		break;
//	case CardRank::RANK_4:
//		std::cout << '4';
//		break;
//	case CardRank::RANK_5:
//		std::cout << '5';
//		break;
//	case CardRank::RANK_6:
//		std::cout << '6';
//		break;
//	case CardRank::RANK_7:
//		std::cout << '7';
//		break;
//	case CardRank::RANK_8:
//		std::cout << '8';
//		break;
//	case CardRank::RANK_9:
//		std::cout << '9';
//		break;
//	case CardRank::RANK_10:
//		std::cout << 'T';
//		break;
//	case CardRank::RANK_JACK:
//		std::cout << 'J';
//		break;
//	case CardRank::RANK_QUEEN:
//		std::cout << 'Q';
//		break;
//	case CardRank::RANK_KING:
//		std::cout << 'K';
//		break;
//	case CardRank::RANK_ACE:
//		std::cout << 'A';
//		break;
//	default:
//		std::cout << '?';
//		break;
//	}
//
//	switch (card.suit)
//	{
//	case CardSuit::SUIT_CLUB:
//		std::cout << 'C';
//		break;
//	case CardSuit::SUIT_DIAMOND:
//		std::cout << 'D';
//		break;
//	case CardSuit::SUIT_HEART:
//		std::cout << 'H';
//		break;
//	case CardSuit::SUIT_SPADE:
//		std::cout << 'S';
//		break;
//	default:
//		std::cout << '?';
//		break;
//	}
//}
//
//int getCardValue(const Card &card)
//{
//	if (card.rank <= CardRank::RANK_10)
//	{
//		return (static_cast<int>(card.rank) + 2);
//	}
//
//	switch (card.rank)
//	{
//	case CardRank::RANK_JACK:
//	case CardRank::RANK_QUEEN:
//	case CardRank::RANK_KING:
//		return 10;
//	case CardRank::RANK_ACE:
//		return 11;
//	default:
//		assert(false && "should never happen");
//		return 0;
//	}
//}
//
//void printDeck(const deck_type &deck)
//{
//	for (const auto &card : deck)
//	{
//		printCard(card);
//		std::cout << ' ';
//	}
//
//	std::cout << '\n';
//}
//
//deck_type createDeck()
//{
//	deck_type deck
//	{ };
//
//	index_type card
//	{ 0 };
//
//	auto suits
//	{ static_cast<index_type>(CardSuit::MAX_SUITS) };
//	auto ranks
//	{ static_cast<index_type>(CardRank::MAX_RANKS) };
//
//	for (index_type suit
//	{ 0 }; suit < suits; ++suit)
//	{
//		for (index_type rank
//		{ 0 }; rank < ranks; ++rank)
//		{
//			deck[card].suit = static_cast<CardSuit>(suit);
//			deck[card].rank = static_cast<CardRank>(rank);
//			++card;
//		}
//	}
//
//	return deck;
//}
//
//void shuffleDeck(deck_type &deck)
//{
//	static std::mt19937 mt
//	{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
//
//	std::shuffle(deck.begin(), deck.end(), mt);
//}
//
//bool playerWantsHit()
//{
//	while (true)
//	{
//		std::cout << "(h) to hit, or (s) to stand: ";
//
//		char ch
//		{ };
//		std::cin >> ch;
//
//		switch (ch)
//		{
//		case 'h':
//			return true;
//		case 's':
//			return false;
//		}
//	}
//}
//
//// Returns true if the player went bust. False otherwise.
//bool playerTurn(const deck_type &deck, index_type &nextCardIndex,
//		Player &player)
//{
//	while (true)
//	{
//		std::cout << "You have: " << player.score << '\n';
//
//		if (player.score > maximumScore)
//		{
//			return true;
//		}
//		else
//		{
//			if (playerWantsHit())
//			{
//				player.score += getCardValue(deck[nextCardIndex++]);
//			}
//			else
//			{
//				// The player didn't go bust.
//				return false;
//			}
//		}
//	}
//}
//
//// Returns true if the dealer went bust. False otherwise.
//bool dealerTurn(const deck_type &deck, index_type &nextCardIndex,
//		Player &dealer)
//{
//	while (dealer.score < minimumDealerScore)
//	{
//		dealer.score += getCardValue(deck[nextCardIndex++]);
//	}
//
//	return (dealer.score > maximumScore);
//}
//
//bool playBlackjack(const deck_type &deck)
//{
//	index_type nextCardIndex
//	{ 0 };
//
//	Player dealer
//	{ getCardValue(deck[nextCardIndex++]) };
//
//	std::cout << "The dealer is showing: " << dealer.score << '\n';
//
//	Player player
//	{ getCardValue(deck[nextCardIndex]) + getCardValue(deck[nextCardIndex + 1]) };
//	nextCardIndex += 2;
//
//	if (playerTurn(deck, nextCardIndex, player))
//	{
//		return false;
//	}
//
//	if (dealerTurn(deck, nextCardIndex, dealer))
//	{
//		return true;
//	}
//
//	return (player.score > dealer.score);
//}

