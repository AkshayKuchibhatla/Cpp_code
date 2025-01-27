#include <iostream>
#include <vector>
#include <ncurses.h>
#include <string>
#include <cmath>
#include <string>
#include <codecvt>
#include <locale.h>
#include "Card.h"
using namespace std;

//============================CARD================================

Card::Card(Rank r, Suit s) {
    /* Creates the card of mentioned suit and rank.*/
    this->rank = r;
    this->suit = s;
}
Card::Card() {}

string Card::to_string() {
    string s;
    string r;
    switch (this->suit) {
    case NONE:
        s = "Joker";
        return s;
    case CLUBS:
        s = "Clubs"; 
        break;
    case DIAMONDS:
        s = "Diamonds"; 
        break;
    case HEARTS:
        s = "Hearts"; 
        break;
    case SPADES:
        s = "Spades"; 
        break;
    default:
        s = "CLUBS";
        break;
    }

    switch (this->rank) {   
    case JOKER:
        r = "Joker";
        return r;
    case TWO:
        r = "Two"; 
        break;
    case THREE:
        r = "Three"; 
        break;
    case FOUR:
        r = "Four"; 
        break;
    case FIVE:
        r = "Five"; 
        break;
    case SIX:
        r = "Six"; 
        break;
    case SEVEN:
        r = "Seven"; 
        break;
    case EIGHT:
        r = "Eight"; 
        break;
    case NINE:
        r = "Nine"; 
        break;
    case TEN:
        r = "Ten"; 
        break;
    case JACK:
        r = "Jack"; 
        break;
    case QUEEN:
        r = "Queen"; 
        break;
    case KING:
        r = "King"; 
        break;
    case ACE:
        r = "Ace"; 
        break;
    default:
        r = "";
        break;
    }

    return r + " of " + s;
}
bool Card::equals(Card card) {
    return (this->rank == card.rank && this->suit == card.suit);
}
bool Card::isGreaterThan(Card card) {
    if (this->suit > card.suit) return true;
    if (this->suit < card.suit) return false;

    if (this->rank > card.rank) return true;
    if (this->rank < card.rank) return false;

    return false;
}
bool Card::isLessThan(Card card) {
    if (this->suit < card.suit) return true;
    if (this->suit > card.suit) return false;

    if (this->rank < card.rank) return true;
    if (this->rank > card.rank) return false;

    return false;
}
// Draws based on top left corner coordinates.
// @param row: the row in the terminal of the top left corner.
// @param column: the column in the terminal of the top left corner.
// @param faceUp: draw card facing up or down?
// @param narrow: draw the card full width or slightly narrower?
void Card::draw(int row, int col, bool faceUp, bool narrow) {
    // cout << "Rendering " << this->to_string() << "\n\r";
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_RED, COLOR_WHITE);

    int CARD_HEIGHT, CARD_WIDTH;

    CARD_HEIGHT = 4;
    CARD_WIDTH = (narrow) ? 3 : 5;

    if (this->suit == 2 || this->suit == 3) {
        attron(COLOR_PAIR(2));
    } else {
        attron(COLOR_PAIR(1));
    }

    mvvline(row + 1, col, ACS_VLINE, CARD_HEIGHT - 2);
    mvvline(row + 1, col + CARD_WIDTH - 1, ACS_VLINE, CARD_HEIGHT - 2);
    mvhline(row, col, ACS_HLINE, CARD_WIDTH - 1);
    mvhline(row + CARD_HEIGHT - 1, col, ACS_HLINE, CARD_WIDTH - 1);
    mvaddch(row, col, ACS_ULCORNER);
    mvaddch(row, col + CARD_WIDTH - 1, ACS_URCORNER);
    mvaddch(row + CARD_HEIGHT - 1, col, ACS_LLCORNER);
    mvaddch(row + CARD_HEIGHT - 1, col + CARD_WIDTH - 1, ACS_LRCORNER);

    if (!faceUp) {
        if (narrow) {
            mvaddstr(row + 1, col + 1, "✪");
            mvaddstr(row + 2, col + 1, " ");
        } else {
            mvaddstr(row + 1, col + 1, " ✪ ");
            mvaddstr(row + 2, col + 1, "   ");
        }
        goto endOfDraw;
    }

    switch (this->suit) {
        case 0:
            mvaddstr(row + 2, col + 1, "O ");
            break;
        case 1:
            mvaddstr(row + 2, col + 1, "♣ ");
            break;
        case 2:            
            mvaddstr(row + 2, col + 1, "♦ ");
            break;
        case 3:
            mvaddstr(row + 2, col + 1, "♥ ");
            break;
        case 4:
            mvaddstr(row + 2, col + 1, "♠ ");
            break;
    }
    
    switch (this->rank) {
        case 0:
            mvaddstr(row + 1, col + 1, "J ");
            break;
        case 2:
            mvaddstr(row + 1, col + 1, "2 ");
            break;
        case 3:
            mvaddstr(row + 1, col + 1, "3 ");
            break;
        case 4:
            mvaddstr(row + 1, col + 1, "4 ");
            break;
        case 5:
            mvaddstr(row + 1, col + 1, "5 ");
            break;
        case 6:
            mvaddstr(row + 1, col + 1, "6 ");
            break;
        case 7:
            mvaddstr(row + 1, col + 1, "7 ");
            break;
        case 8:
            mvaddstr(row + 1, col + 1, "8 ");
            break;
        case 9:
            mvaddstr(row + 1, col + 1, "9 ");
            break;
        case 10:
            mvaddstr(row + 1, col + 1, "10");
            break;
        case 11:
            mvaddstr(row + 1, col + 1, "J ");
            break;
        case 12:
            mvaddstr(row + 1, col + 1, "Q ");
            break;
        case 13:
            mvaddstr(row + 1, col + 1, "K ");
            break;
        case 14:
            mvaddstr(row + 1, col + 1, "A ");
            break;
    }

    if (!narrow) {
        mvaddstr(row + 1, col + 3, " ");
        mvaddstr(row + 2, col + 3, " ");
    }
    endOfDraw:
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
}

//============================DECK================================

Deck::Deck(int size) {
    this->cardsList = vector<Card> (size);
}
Deck::Deck() {
    vector<Card> deck(52);
    int i = 0;
    for (Suit s = CLUBS; s <= SPADES; s = Suit(s + 1)) {
        for (Rank r = TWO; r <= ACE; r = Rank(r + 1)) {
            deck[i].suit = s;
            deck[i].rank = r;
            i++;
        }
    }
    this->cardsList = deck;
}

void Deck::print() {
    // Prints every card in the deck, line by line.
    for (int i = 0; i < this->cardsList.size(); i++) {
        cout << this->cardsList[i].to_string() << "\n\r";
    }
}
void Deck::swapItems(int index1, int index2) {
    // Swaps the cards at the given indicies.
    vector<Card>* listPtr = &this->cardsList;
    Card* firstElementptr = &listPtr->at(index1);
    Card* secondElementptr = &listPtr->at(index2);
    Card temp;
    temp = *firstElementptr;
    *firstElementptr = *secondElementptr;
    *secondElementptr = temp;
}
void Deck::shuffle() {
    srand(time(NULL));
    for (int i = 0; i < this->cardsList.size(); i++) {
        // cout << rand() % this->cardsList.size() << endl;
        swapItems(i, rand() % this->cardsList.size());
    }
}
void Deck::addCard(Card card) {
    this->cardsList.push_back(card);
}
void Deck::selectionSort() {
    for (int i = 0; i < this->cardsList.size(); i++) {
        swapItems(i, this->lowestCardIndex(i, this->cardsList.size() - 1));
    }
}

int Deck::binarySearch(Card& card, int low, int high) {
    int middle = (low + high) / 2;
    if (low > high) return -1;
    if (this->cardsList[middle].equals(card)) return middle;
    
    if (this->cardsList[middle].isGreaterThan(card)) {
        return binarySearch(card, low, middle-1);
    } else {
        return binarySearch(card, middle+1, high);
    }
}
Deck Deck::subdeck(int lowerIndex, int upperIndex) {
    Deck sub(upperIndex - lowerIndex);

    for (int i = 0; i < sub.cardsList.size(); i++) {
        sub.cardsList[i] = this->cardsList[lowerIndex + i];
    }
    return sub;
}
int Deck::findCard(Card& card) {
    for (int i = 0; i < this->cardsList.size(); i++) {
        if (this->cardsList[i].equals(card)) return i;
    }
    return -1;
}
int Deck::lowestCardIndex(int low, int high) {
    int lowInd = low;
    for (int i = low; i <= high; i++){
        if (this->cardsList[i].isLessThan(this->cardsList[lowInd])) {
            lowInd = i;
        }
    }
    return lowInd;
}
Deck Deck::merge(Deck deck) {
    /* Merges 2 sorted decks into one sorted deck.*/
    Deck sumDeck = Deck(0);
    int iThis = 0; // Used for this cardsList.
    int iD = 0; // Used fot d's cardsList.
    while (iThis < this->cardsList.size() && iD < deck.cardsList.size()) {
        if (this->cardsList[iThis].isLessThan(deck.cardsList[iD])) {
            sumDeck.addCard(this->cardsList[iThis]);
            iThis++;
        } else {
            sumDeck.addCard(deck.cardsList[iD]);
            iD++;
        }
    }
    while (iThis < this->cardsList.size()) {
        sumDeck.addCard(this->cardsList[iThis]);
        iThis++;
    }

    while (iD < deck.cardsList.size()) {
        sumDeck.addCard(deck.cardsList[iD]);
        iD++;
    }
    return sumDeck;
}
Deck Deck::mergeSort() {
    if (this->cardsList.size() == 1) {
        return *this;
    }
    int mid = floor(this->cardsList.size() / 2);
    Deck leftDeck = this->subdeck(0,mid).mergeSort();
    Deck rightDeck = this->subdeck(mid,this->cardsList.size()).mergeSort();

    return leftDeck.merge(rightDeck);
}
Card Deck::drawCard() {
    srand(time(NULL));
    int index = rand() % this->cardsList.size();
    Card c = this->cardsList.at(index);
    this->cardsList.erase(this->cardsList.begin() + index);
    return c;
}