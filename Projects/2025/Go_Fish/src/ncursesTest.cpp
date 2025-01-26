#include <iostream>
#include <ncurses.h>
using namespace std;

int main() {
    cout << "something else" << "\n";
    initscr();
    move(10,20);
    printw("hello world");
    refresh();
    getch();
    endwin();
    return 0;
}