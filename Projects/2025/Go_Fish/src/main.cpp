#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Card.h"
#include "GoFish.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    initscr();
    start_color();
    clear();
    GoFish theGame;

    refresh();
    getch();

    endwin();
    return 0;
}