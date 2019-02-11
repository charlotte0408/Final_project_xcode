//
//  main.cpp
//  Final_project
//
//  Created by 黄逸欢 on 2/2/19.
//  Copyright © 2019 Yihuan Huang. All rights reserved.
//
#include <iostream>
#include <vector>
#include <ctime>

#include "Matrix.h"

using namespace std;

int main(int argc, const char * argv[]) {
    srand((int) time(0));
    string response;
    do{
        cout << "Game started!!!" << endl;
        cout << "------------------------" << endl;
        Matrix A;
        A.random();
        A.random();
        A.print();
        int count = 0;
        while (!A.endgame())
        {
            string move = "";
            cout << "Enter your movement: w(move up), a(move left), s(move down), d(move right)";
            getline (cin, move);
            if (move == "w")
            {
                bool order = A.up();
                if (order)
                    count++;
                else{
                    cout << "Invalid move upwards. Try again";
                    continue;
                    }
            }
            else if (move == "a")
            {
                bool order = A.left();
                if (order)
                    count++;
                else{
                    cout << "Invalid move leftwards. Try again";
                    continue;
                }
            }
            else if (move == "s")
            {
                bool order = A.down();
                if (order)
                    count++;
                else{
                    cout << "Invalid move downwards. Try again";
                    continue;
                }
            }
            else if (move == "s")
            {
                bool order = A.down();
                if (order)
                    count++;
                else{
                    cout << "Invalid move downwards. Try again";
                    continue;
                }
            }
            else if (move == "d")
            {
                bool order = A.right();
                if (order)
                    count++;
                else{
                    cout << "Invalid move rightwards. Try again";
                    continue;
                }
            }
            A.print();
        }
        cout << "Do you want to play another round?(y or n) ";
        getline(cin, response);
    }while (response == "y");
}
