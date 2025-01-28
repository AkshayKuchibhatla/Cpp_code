# Go Fish with ncurses library

This is an emulation of the card game Go Fish! in terminal using ncurses. As of now, **it only works with two players,** but future versions will implement multiplayer games.

## Setup

Both players recieve 7 cards at the start of every game. The set of cards that are face up at the bottom of the screen belong to the user, while the other set of cards is the computer's hand.

## GamePlay

In game play, the game prompts the user for a rank to ask the computer for. **Enter only one character to represent a rank. The specific character you should enter for each rank is mentioned below:**

| Rank    | What to enter |
| -------- | ------- |
| 2  | `2`  |
| 3  | `3`  |
| 4  | `4`  |
| 5  | `5`  |
| 6  | `6`  |
| 7  | `7`  |
| 8  | `8`  |
| 9  | `9`  |
| 10  | `1` (entering just 1 will be taken as 10.) |
| Jack  | `j`  |
| Queen  | `q`  |
| King  | `k`  |
| Ace  | `a`  |

Entering the corresponding character will make the user ask the computer for cards of that rank. **Note: only enter the one character and nothing else. Proper error handling is not implemented in this version of the game.**

When the user asks for a rank, the computer either hands over all cards of that rank or tells the user to Go Fish! (draw a card.)

### Books

**Books** are four-of-a-kind sets of cards that the user or computer has collected. The ranks of books that have been collected by each player will be displayed under the `Books` label.
