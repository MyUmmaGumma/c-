#include <iostream>
#include <stack>
#include <list>
using namespace std;
#include <time.h>

#define TRUE 1
#define FALSE (!TRUE)


class Card
{
    private:
		int suite;
		int num;
	public:
		Card(int i, int j) {
			suite = i;
			num = j;
		}

		Card() {
			suite = -1;
			num = -1;
		}

		bool isValid() 
		{
			return ((suite != -1) && (num != -1));
		}
		
		void printCard(void) const
		{
			switch(suite) {
				case 0:	cout<<"Hearts: ";
						break;
				case 1:	cout<<"Diamonds: ";
						break;
				case 2:	cout<<"Clubs: ";
						break;
				case 3:	cout<<"Spades: ";
						break;
				default: break;
			}

			switch(num) {
				case 0:	
						break;
				case 1: cout <<"Ace"<<endl; 
						break;	
				case 2:	
				case 3:	
				case 4:	
				case 5:	
				case 6:	
				case 7:	
				case 8:	
				case 9:	
				case 10:
						cout <<num<<endl;		
						break;
				case 11:
						cout <<"Jack"<<endl;
						break;
				case 12:
						cout <<"Queen"<<endl;
						break;
				case 13:
						cout <<"King"<<endl;
						break;
				default: break;
			}
		}
    
        int GetSuite() const
        {
            return suite;
        }

        int GetValue() const
        {
            return num;
        }

		void SetCard(int _num, int _suite) 
		{
			num = _num;
			suite = _suite;
		}
};

// Represents a deck of cards
class DeckOfCards
{
    private:
		// Suite: 0 - Hearts, 1 - Diamonds, 2 - Clubs, 3 - Spades
		//1 - A, 11 - J, 12 - Q, 13 - K
        char cards[4][14];
	public:
		DeckOfCards(void)
		{
			srand(time(NULL));
		}

		void markUsed(Card c);
		Card* draw();
		char getVal(Card c);
};

void DeckOfCards::markUsed(Card c)
{
	cards[c.GetSuite()][c.GetValue()] = 1;		
}

Card* DeckOfCards::draw()
{
	Card *c = new Card();
	c->SetCard(rand() % 4, rand() % 13 + 1);
	markUsed(*c);
	return c;
}

ostream & operator<<(ostream &os, DeckOfCards& c)
{
	os <<"A 1 2 3 4 5 6 7 8 9 10 J Q K"<<endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; i++) {
			os << c.getVal(Card(i, j)) << " ";
		}
		os<<endl;
	}
	return os;
}

class Player 
{
	protected:
		list<Card *> playerDeckOfCards;
		int _id;
	public:
		Player(int id) : _id(id) {}
 
		void assignCard(Card *c)
		{
			playerDeckOfCards.push_back(c);	
		}

		void printDeckOfCards() const
		{
			cout<<"Player "<<_id<<" Cards: "<<endl;
			list<Card *>::const_iterator it = playerDeckOfCards.cbegin();	
			for(; it != playerDeckOfCards.cend(); it++) {
				(*it)->printCard();		
			}
		}
		
		int GetID(void) { return _id; }
};

class BlackJackPlayer : public Player
{
    private:
        int sum;
    public:
        bool isBust(void) const
        {
            return sum > 21;
        }
        int getSum(void) const
        {
            return sum;
        }
		int choice()
		{
			int ch;
			cout<<"Hit:   Choose 1"<<endl;
			cout<<"Stand: Choose 2"<<endl;
			cout<<"Exit Program: Choose 3"<<endl;
			cout<<"Your choice: ";
			cin>>ch;
			return ch;
		}
};

class BlackJackDealer : public Player
{
	private:
        int sum;
		list<Card *> dealerCards;
    public:
		bool isBust(void) const
        {
            return sum > 21;
        }

		void assignDealerCard(Card *c) {
			dealerCards.push_back(c);
		}

		int getSum()
		{
			return sum;
		}
};


class BlackJack
{
	private:
		BlackJackDealer dealer;
		list<BlackJackPlayer> players;
		DeckOfCards cards;
		Card *holeCard;
		bool isPlayerBlackJack;
		bool isDealerBlackJack;
	public:
		void Hit();	
		void play();
		bool endGame();
		// Draws and Stores the card to be later flipped over
		void StoreCard(void);
		void DistributePlayerCards(bool);
		int AssignDealerCard(void);
		// Normalized Blackjack values of cards
		int Normalized(int);
		int checkForDealerBlackJack();
		bool getNextCard(int choice);
};
 
void BlackJack::StoreCard()
{
	holeCard = cards.draw();
}

bool BlackJack::getNextCard(int ch)
{
	return (ch == 1);	
}

bool
BlackJack::endGame()
{
	if (dealer.isBust()) {
		return 1;
	}
	list<BlackJackPlayer>::const_iterator it = players.cbegin();
	for(; it != players.cend(); it++) {
		if ((*it).isBust()) {
			return 1;
		}
	}
	return 0;
}

void
BlackJack::DistributePlayerCards(bool playerChoice)
{
	list<BlackJackPlayer>::iterator it = players.begin();
	for (; it != players.end(); ++it) {
		if (playerChoice) {
			if (getNextCard((*it).choice() == false)) {
				continue;
			}
		}
		Card *c = cards.draw();
		(*it).assignCard(c);
	}
}

int
BlackJack::Normalized(int cardval)
{
	if (cardval > 10) {
		return 10;
	}	
	return cardval;
}

int
BlackJack::AssignDealerCard()
{
	Card *c = cards.draw();
	dealer.assignDealerCard(c);
	return Normalized(c->GetValue());
}

int
BlackJack::checkForDealerBlackJack()
{
	if (holeCard->GetValue() + dealer.getSum() == 21) {
		isDealerBlackJack = TRUE;
	}
	return FALSE;
}

void
BlackJack::play()
{
	//Start the game
	StoreCard(); //First card for the dealer
	DistributePlayerCards(false);	
	if (AssignDealerCard() == 10) {
		checkForDealerBlackJack();		
	}
	DistributePlayerCards(false);
	//Distribute by player choice
}
