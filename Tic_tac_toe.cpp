#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

void ii(int** map, int size) {
    int x, y;
    do {
        x = rand() % size;
        y = rand() % size;
    } while (map[x][y] != 0);
    map[x][y] = 2; 
}

void map_show(int** map, int size) {
    system("clear");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (map[j][i] == 0)
                cout << ".";
            else if (map[j][i] == 1)
                cout << "X";
            else if (map[j][i] == 2)
                cout << "O";
        }
        cout << endl;
    }
}

bool game_over(int** map, int val, int size) {
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (map[j][i] == val)  
                c0++;
            if (map[i][j] == val)  
                c1++;
            if (map[j][j] == val && i == j) 
                c2++;
            if (map[size - 1 - j][j] == val) 
                c3++;
        }
        if (c0 == size || c1 == size || c2 == size || c3 == size) { 
            cout << "You won!" << endl;
            return true;
        }
       
        c0 = 0;
        c1 = 0;
        c2 = 0;
        c3 = 0;
    }
    return false;
}

bool game_over2(int** map, int size) {
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (map[j][i] == 2) 
                c0++;
            if (map[i][j] == 2) 
                c1++;
            if (map[j][j] == 2 && i == j) 
                c2++;
            if (map[size - 1 - j][j] == 2) 
                c3++;
        }
        if (c0 == size || c1 == size || c2 == size || c3 == size) { 
            cout << "You lost!" << endl;
            return true;
        }
        
        c0 = 0;
        c1 = 0;
        c2 = 0;
        c3 = 0;
    }
    return false;
}

bool is_draw(int** map, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (map[j][i] == 0)
                return false;
        }
    }
    return true;
}

void display_rules(int mode) {
    cout << "Rules of the game:" << endl;
    cout << "1. The player takes turns with the computer to put signs on the empty squares of the field." << endl;
    cout << "2. The first player to line up his pieces vertically, horizontally, or diagonally wins." << endl;
    cout << "3. The first move is made by the player betting 1." << endl;
    if (mode == 2) {
        cout << "4. For the 4x4 mode, the player needs to line up 4 pieces instead of 3." << endl;
    }
    cout << "5. Enjoy the game!" << endl;
}

void display_high_scores() {
    // Add code for displaying high scores here
}

int main() {
    int choice;
    int size = 0;

    do {
        cout << "Game menu tic tac toe:" << endl;
        cout << "1. New game with computer" << endl;
        cout << "2. Rules" << endl;
        cout << "3. High Scores" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int sub_choice;
                do {
                    cout << "Choose the game mode:" << endl;
                    cout << "1. 3x3" << endl;
                    cout << "2. 4x4" << endl;
                    cout << "3. Back to main menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> sub_choice;
                    switch (sub_choice) {
                        case 1:
                            size = 3;
                            break;
                        case 2:
                            size = 4;
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                    if (size > 0) {
                        int** map = new int*[size];
                        for(int i = 0; i < size; i++) {
                            map[i] = new int[size];
                            for(int j = 0; j < size; j++) {
                                map[i][j] = 0;
                            }
                        }
                        srand(time(NULL));
                        int x = 0, y = 0;
                        while (true) {  
                            cout << "Entering coordinates (or enter -1 -1 to exit):";
                            cin >> x >> y;
                            if (x == -1 || y == -1) {
                                for(int i = 0; i < size; i++) {
                                    delete[] map[i];
                                }
                                delete[] map;
                                break;
                            }
                            map[x][y] = 1;  
                            map_show(map, size);  
                            if (game_over(map, 1, size)) {
                                cout << "You won!" << endl;
                                break;  
                            }
                            if (is_draw(map, size)) {
                                cout << "It's a draw!" << endl;
                                break;
                            }
                    
                            cout << "Computer progress..." << endl;
                            ii(map, size); 
                            if (game_over2(map, size)) {
                                cout << "You lost!" << endl;
                                break;
                            }
                        }
                        for(int i = 0; i < size; i++) {
                            delete[] map[i];
                        }
                        delete[] map;
                        size = 0;
                    }
                } while (sub_choice != 3);
                break;
            }
            case 2:
                int sub_choice;
                do {
                    cout << "Rules menu:" << endl;
                    cout << "1. Rules for 3x3" << endl;
                    cout << "2. Rules for 4x4" << endl;
                    cout << "3. Back to main menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> sub_choice;
                    switch (sub_choice) {
                        case 1:
                            display_rules(3);
                            break;
                        case 2:
                            display_rules(4);
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                } while (sub_choice != 3);
                break;
            case 3:
                display_high_scores();
                break;
            case 4:
                cout << "Exiting the game. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
    } while (choice != 4);
    
    return 0;
}
