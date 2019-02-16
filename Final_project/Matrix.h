//
//  Matrix.h
//  Final_project
//
//  Created by 黄逸欢 on 2/2/19.
//  Copyright © 2019 Yihuan Huang. All rights reserved.
//

#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
    
    Matrix(int row = 3, int col = 3);
    bool left();
    bool right();
    bool up();
    bool down();
    bool full();
    bool find2048();
    bool endgame();
    int left_find_nearest0(int row, int col);
    int right_find_nearest0(int row, int col);
    Matrix rotate_clock();
    Matrix rotate_counterclock();
    void print();
    void random();
private:
    vector<vector<int>> m;
    
};

#endif /* Matrix_h */
