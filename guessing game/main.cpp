//
//  main.cpp
//  guessing game
//
//  Created by Mohammed A. Alameedi on 11/12/20.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int rand_num(){
    // Random choose a number between 1 - 10 function
    int num;
    //srand(time(0));
    num = (rand() % 10);
    return num;
}
bool check_play(){
    // checking play status function
    char play_again;
    bool status;
    //do-while loop to ensure only y, Y, n, N entered by player
    do {
        cout << "Do you want to play again, ([Y]es,[n]o): ";
        cin >> play_again;
    } while (((play_again != 'y') && (play_again != 'Y')) && ((play_again != 'n') && (play_again != 'N')));
    
    if (tolower(play_again) == 'y') {
        status = true;
    }
    else {
        status = false;
    }
    return status;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int guest_num, player_num, move_count=0;
    bool play = true;
    guest_num = rand_num();
    while (play) {
        // do - while loop to ensure player enter number between 1 to 10
        do {
            cout << "Chose a number between 1 - 10: ";
            cin >> player_num;
            cout << player_num;
        } while ((player_num < 1) || (player_num > 10));
        move_count+=1;
        if (player_num > guest_num) {
            cout << "Chose lower number\n";
            continue;
        }
        else if (player_num < guest_num){
            cout << "Chose higher number\n";
            continue;
        }
        else {
            cout << "Good Chose, You Win\n";
            cout << "You did it in " << move_count << " move\n";
            //cout << move_count;
            //cout << " move\n";
        }
        // Function to check whatever play again or not.
        play = check_play();
        if (play) {
            guest_num = rand_num();
            move_count = 0;
            continue;
        }
        else cout << "See you again bye...!\n";
    }
    return 0;
}
