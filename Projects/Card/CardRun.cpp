#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

bool equals(Card c1, Card c2) {
    return (c1.suit == c2.suit && c1.rank == c2.rank);
}

vector<Card> buildDeck() {
    vector<Card> deck(52);
    int i = 0;
    for (int s = 0; s < 4; s++) {
        for (int r = 2; r < 15; r++) {
            deck[i].suit = s;
            deck[i].rank = r;
            i++;
        }
    }
    return deck;
}

void print_deck(vector<Card>& deck) {
    for (int i = 0; i < deck.size(); i++) {
        cout << deck[i].to_string() << endl;
    }
}

int binarySearch(Card& card, vector<Card>& deck, int l, int h) {
    int mid = (l + h) / 2;
    cout << l << ", " << h << endl;
    if (h < l) return -1;
    if (deck[mid].equals(card)) return mid;

    if (deck[mid].isGreaterThan(card)) {
        return binarySearch(card, deck, l, mid-1);
    } else {
        return binarySearch(card, deck, mid+1, h);
    }
}

int main() {
    Card ace_of_spades(14,3);
    Card definitely_not_ace_of_spades(14,3);
    cout << equals(ace_of_spades, definitely_not_ace_of_spades) << endl << endl;

    vector<Card> newDeck = buildDeck();
    // print_deck(newDeck);
    int index = binarySearch(ace_of_spades, newDeck, 0, 51);
    cout << newDeck[index].to_string() << " found at index " 
    << index << "." << endl << endl;

    Card fakeCard(1, 15);
    index = binarySearch(fakeCard, newDeck, 0, 51);
    cout << newDeck[index].to_string() << " found at index " << index << ".";
    return 0;
}