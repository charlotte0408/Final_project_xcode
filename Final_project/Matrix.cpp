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
        vector <int> line = m[i];
        for (int j = 0; j< 3; j++) // start from the most left
        {
            if (line[j+1] != 0 && line[j] != line[j+1]) // if jth is not equal to its next and its next is not empty, move to the next spot
                continue;
            if (line[j] == 0) // if jth is empty, move to the next spot
                continue;
            for (int k = j+1; k <= 3; k++) // if (j+1)th is empty or jth is equal to its next
            {
                if (line[j] == line[k])
                {
                    line[j] = 2 * line[j];
                    line[k] = 0;
                    order = true;
                    break;
                }
            }
                                             
        }
    }
    for (int i = 0; i <= 3; i++)
    {
        vector <int> line = m[i];
        for (int j = 0; j <= 3; j++)
        {
            if (line[j] == 0)
                continue;
            else
            {
                for (int k = j-1; k >= 0; k--)
                {
                    if (line[k] == 0)
                    {
                        line[k] = line[j]; // push the next non-empty sopt to the left first empty element
                        line[j] = 0;
                        cout << line[k] << endl;
                        order = true;
                        break;
                    }
                }
            }
        }
    }
    return order;
}

bool Matrix::right()
{
    bool order = false;
    for (int i = 0; i <= 3; i++)
    {
        vector <int> line = m[i];
        for (int j = 3; j >= 1; j--) // start from the right most
        {
            if (line[j] != line[j-1] && line[j-1] != 0) // next two are nonempty and not the same
                continue;
            if (line[j] == 0)
                continue;
            for (int k = j-1; k >= 0; k--)
            {
                if (line[j] == line[k])
                {
                    line[j] = 2 * line[j];
                    line[k] = 0;
                    order = true;
                    break;
                }
            }
        }
    }
    for (int i = 0; i <= 3; i++)
    {
        vector <int> line = m[i];
        for (int j = 2; j >= 0; j--)
        {
            if (line[j] == 0)
                continue;
            else
            {
                for (int k = j+1; k <= 3; k++)
                {
                    if (line[k] == 0)
                    {
                        line[k] = line[j];
                        line[j] = 0;
                        order = true;
                        break;
                    }
                }
                
            }
        }
    }
    return order;
}
 
Matrix Matrix::rotate_clock()
{
    Matrix A;
    for (int i = 0; i <= 3; i++)
    {
        for (int j = i; j <= 3; j++)
        {
            int tmp = A.m[j][i];
            A.m[j][i] = A.m[i][j];
            A.m[i][j] = tmp;
        }
    }
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            int copy = A.m[i][3-j];
            A.m[i][3-j] = A.m[i][j];
            A.m[i][j] = copy;
        }
    }
    return A;
}

Matrix Matrix::rotate_counterclock()
{
    Matrix A;
    for (int i = 0; i <= 3; i++)
    {
        for (int j = i; j <= 3; j++)
        {
            int tmp = A.m[j][i];
            A.m[j][i] = A.m[i][j];
            A.m[i][j] = tmp;
        }
    }
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            int tmp = A.m[3-i][j];
            A.m[3-i][j] = A.m[i][j];
            A.m[i][j] = tmp;
        }
    }
    return A;
}

bool Matrix::up()
{
    Matrix A = this -> rotate_clock();
    if (A.left() == true)
        return true;
    return false;
}

bool Matrix::down()
{
    Matrix A = this -> rotate_counterclock();
    if (A.right() == true)
        return true;
    return false;
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
            cout << m[i][j] << " ";
        cout << endl;
    }
}


