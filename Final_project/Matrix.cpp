//
//  Matrix.cpp
//  Final_project
//
//  Created by 黄逸欢 on 2/2/19.
//  Copyright © 2019 Yihuan Huang. All rights reserved.
//

#include "Matrix.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

Matrix :: Matrix(int row, int col)
{
    m.resize(row+1);
    for (int i = 0; i <= row; i++)
        for (int j = 0; j <= col; j++)
            m[i].push_back(0);
    
}

bool Matrix :: left()
{
    bool order = false;
    for (int i = 0; i <= 3; i++) // loop through rows
    {
        for (int j = 0; j< 3; j++) // start from the most left
        {
            if (m[i][j+1] != 0 && m[i][j] != m[i][j+1]) // if jth is not equal to its next and its next is not empty, move to the next spot
                continue;
            if (m[i][j] == 0) // if jth is empty, move to the next spot
                continue;
            for (int k = j+1; k <= 3; k++) // if (j+1)th is empty or jth is equal to its next
            {
                if (m[i][j] == m[i][k])
                {
                    m[i][j] = 2 * m[i][j];
                    m[i][k] = 0;
                    order = true;
                    break;
                }
            }
                                             
        }
    }
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (m[i][j] == 0)
                continue;
            else
            {
                int index = left_find_nearest0(i,j);
                if (index != j){
                    m[i][index] = m[i][j];
                    m[i][j] = 0;
                    order = true;
                }
            }
        }
       /* for (int j = 1; j <= 3; j++)
        {
            if (line[j] == 0)
                continue;
            else
            {
                int k = 0;
                while (k < j)
                {
                    if (line[k] == 0){
                        m[i][k] = m[i][j];
                        m[i][j] = 0;
                        order = true;
                    }
                    k++;
                    break;
                }
            }
            
        }*/
    }
    return order;
}

bool Matrix::right()
{
    bool order = false;
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 3; j >= 1; j--) // start from the right most
        {
            if (m[i][j] != m[i][j-1] && m[i][j-1] != 0) // next two are nonempty and not the same
                continue;
            if (m[i][j] == 0)
                continue;
            for (int k = j-1; k >= 0; k--)
            {
                if (m[i][j] == m[i][k])
                {
                    m[i][j] = 2 * m[i][j];
                    m[i][k] = 0;
                    order = true;
                    break;
                }
            }
        }
    }
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 2; j >= 0; j--)
        {
            if (m[i][j] == 0)
                continue;
            else
            {
                int index = right_find_nearest0(i,j);
                if (index != j){
                    m[i][index] = m[i][j];
                    m[i][j] = 0;
                    order = true;
                }
            }
        }
    }
    return order;
}

int Matrix::left_find_nearest0(int row, int col)
{
    int index = col;
    int i = col - 1;
    while (i >= 0 && m[row][i] == 0){
        index = i;
        i--;
    }
    return index;
}

int Matrix::right_find_nearest0(int row, int col)
{
    int index = col;
    int i = col + 1;
    while (i <= 3 && m[row][i] == 0){
        index = i;
        i++;
    }
    return index;
}

Matrix Matrix::rotate_clock()
{
    for (int i = 0; i <= 3; i++)
    {
        for (int j = i; j <= 3; j++)
        {
            int tmp = m[j][i];
            m[j][i] = m[i][j];
            m[i][j] = tmp;
        }
    }
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            int copy = m[i][3-j];
            m[i][3-j] = m[i][j];
            m[i][j] = copy;
        }
    }
    return *this;
}

Matrix Matrix::rotate_counterclock()
{
    for (int i = 0; i <= 3; i++)
    {
        for (int j = i; j <= 3; j++)
        {
            int tmp = m[j][i];
            m[j][i] = m[i][j];
            m[i][j] = tmp;
        }
    }
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            int tmp = m[3-i][j];
            m[3-i][j] = m[i][j];
            m[i][j] = tmp;
        }
    }
    return *this;
}

bool Matrix::up()
{
    Matrix A = this -> rotate_counterclock();
    //A.print();
    //cout << endl;
    bool order = A.left();
    //A.print();
    //cout << endl;
    *this = A.rotate_clock();
    //A.print();
    //cout << endl;
    return order;
}

bool Matrix::down()
{
    Matrix A = this -> rotate_counterclock();
    bool order = A.right();
    *this = A.rotate_clock();
    return order;
}

bool Matrix::endgame()
{
    Matrix clone;
    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <= 3; j++)
            clone.m[i][j] = this -> m[i][j];
    if (clone.left() == false && clone.right() == false && clone.up() == false && clone.down() == false && clone.full() == true)
    {
        cout << "Unfortunately, you lose! BUT life goes on";
        return true;
    }
    if (clone.find2048())
    {
        cout << "2048 GOTCHA. You win!!!!";
        return true;
    }
    return false;
}

bool Matrix::full()
{
    for (int i = 0 ; i <= 3; i++)
        for (int j = 0 ; j <= 3; j++)
        {
            if (m[i][j] == 0)
                return false;
        }
    return true;
}

bool Matrix::find2048()
{
    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <= 3; j++)
        {
            if (m[i][j] == 2048)
                return true;
        }
    return false;
}

void Matrix::random()
{
    Matrix check (1,15);
    int count = 0;
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            if (m[i][j] == 0)
            {
                check.m[0][count] = i;
                check.m[1][count] = j;
                count ++;
            }
        }
    }
    int position = rand() % (count - 1);
    int rn = rand() % 9;
    int next = 0;
    if (rn <= 8)
        next = 2;
    else
        next = 4;
    int i = check.m[0][position];
    int j = check.m[1][position];
    m[i][j] = next;
}

void Matrix::print()
{
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
            cout << fixed << setw(6) << m[i][j] << " ";
        cout << endl;
        cout << endl;
    }
}


