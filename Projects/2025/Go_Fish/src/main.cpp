#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Card.h"
#include "GoFish.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    initscr();
    start_color();
    clear();
    // mvaddch(0,0,'^');
    // mvaddch(20,20,'^');
    // mvaddch(30,30,'^');
    // mvaddch(40,40,'^');
    // mvaddch(50,50,'^');
    // mvaddch(50,200, 'O');

    // Card c1(ACE, DIAMONDS);
    // Card c2(QUEEN, SPADES);
    // Card c3(JACK, CLUBS);
    // Card c4(JOKER, NONE);
    // c1.draw(20, 20, true, false);
    // c2.draw(20, 30, true, false);
    // c3.draw(20, 40, true, false);
    // c4.draw(20, 50, false, false);
    GoFish theGame;

    mvaddch(100,100, ' ');
    refresh();
    getch();

    endwin();
    return 0;
}