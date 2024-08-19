/*
Create a program for playing "dice". The player names any number
in the range from 2 to 12 and the bet he makes this turn. The program, using a random number
generator, chooses numbers from 1 to 6 twice ("rolls a
dice" with numbers from 1 to 6 on its faces). If the sum of the points dropped is less than
or equal to 7 and the player named a number less than or equal to 7, he wins
the bet. If the sum of the numbers dropped is greater than 7 and the player bet on a number
greater than 7, he also wins the bet. If the player guessed the sum of the numbers, he receives
4 times more points than the bet made. The bet is lost if none of
the described situations take place. At the initial moment, the player and the computer have
100 points each. The game goes on until one of the players has 0 points left.
*/

#include <stdlib.h>
#include <time.h>

#include <iostream>

using namespace std;

int main() {
    time_t t;
    srand(time(&t));

    int n, game_bet;
    int points = 100;
    int comp_points = 100;

    int dice;

    cout << "[Task 4]" << endl;

    while (points > 0 && comp_points > 0) {
        cout << "\nEnter number(from 2 to 12): ";
        cin >> n;
        while (n < 2 || n > 12) {
            cout << "The number must be in the range from 2 to 12 \nEnter number: ";
            cin >> n;
        }

        cout << "Enter game bet (from 0 to " << points << "): ";
        cin >> game_bet;
        while (game_bet <= 0 || game_bet > points) {
            cout << "The game bet must be greater than 0 and less than the number of points \nEnter game bet "
                    "(from 0 to "
                 << points << "): ";
            cin >> game_bet;
        }

        dice = int(1 + rand() % (6 - 1 + 1)) + int(1 + rand() % (6 - 1 + 1));

        cout << "\nThere are " << dice << " points on the dice" << endl;

        if (dice == n) {
            cout << "\nYour winnings: " << game_bet * 4 << " points";
            points += game_bet * 4;
            comp_points -= game_bet;
        } else if (dice <= 7 && n <= 7 || dice > 7 && n > 7) {
            cout << "\nYour winnings: " << game_bet << " points";
            points += game_bet;
            comp_points -= game_bet;
        } else {
            cout << "\nYou lose: " << game_bet << " points";
            points -= game_bet;
            comp_points += game_bet;
        }

        cout << "\n\nYour points: " << points << "\nComputer points: " << comp_points;

        cout << "\n\n\n";
    }

    if (comp_points > points) {
        cout << "Computer won!";
    } else {
        cout << "You won!";
    }
}