#include<bits/stdc++.h>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'X';
bool is_tie = false;
string n1 = "", n2 = "";

void FunctionOne() {
    //-----------To create the structure-------------//
    cout << "    |     |    \n";
    cout << " " << space[0][0] << "  | " << space[0][1] << "   | " << space[0][2] << "  \n";
    cout << "____|_____|____\n";
    cout << "    |     |    \n";
    cout << " " << space[1][0] << "  | " << space[1][1] << "   | " << space[1][2] << "  \n";
    cout << "____|_____|____\n";
    cout << "    |     |    \n";
    cout << " " << space[2][0] << "  | " << space[2][1] << "   | " << space[2][2] << "  \n";
    cout << "    |     |    \n";
}

void FunctionTwo() {
    int digit;
    if(token == 'X') {
        cout << n1 << ", please enter: ";
        cin >> digit;
    } else if(token == 'O') {
        cout << n2 << ", please enter: ";
        cin >> digit;
    }

    if(digit == 1) {
        row = 0; column = 0;
    } else if(digit == 2) {
        row = 0; column = 1;
    } else if(digit == 3) {
        row = 0; column = 2;
    } else if(digit == 4) {
        row = 1; column = 0;
    } else if(digit == 5) {
        row = 1; column = 1;
    } else if(digit == 6) {
        row = 1; column = 2;
    } else if(digit == 7) {
        row = 2; column = 0;
    } else if(digit == 8) {
        row = 2; column = 1;
    } else if(digit == 9) {
        row = 2; column = 2;
    } else {
        cout << "INVALID!" << endl;
        FunctionTwo();
        return;
    }

    if(space[row][column] != 'X' && space[row][column] != 'O') {
        space[row][column] = token;
        if(token == 'X') token = 'O';
        else token = 'X';
    } else {
        cout << "There is no empty space!" << endl;
        FunctionTwo();
    }
    FunctionOne();
}

bool FunctionThree() {
    for(int i = 0; i < 3; i++) {
        if((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
           (space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
            return true;
        }
    }
    if((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
       (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(space[i][j] != 'X' && space[i][j] != 'O') {
                return false;
            }
        }
    }
    is_tie = true;
    return false;
}

int main() {
    cout << "Enter the name of the first player: ";
    getline(cin, n1);
    cout << "Enter the name of the second player: ";
    getline(cin, n2);
    cout << n1 << " is Player 1 so he/she will play first\n";
    cout << n2 << " is Player 2 so he/she will play second\n";

    while(!FunctionThree()) {
        FunctionOne();
        FunctionTwo();
    }

    if(is_tie) {
        cout << "It's a DRAW." << endl;
    } else if(token == 'O') {
        cout << n1 << " wins!" << endl;
    } else {
        cout << n2 << " wins!" << endl;
    }

    return 0;
}
