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

Matrix :: Matrix(int value)
{
    m.resize(4);
    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <= 3; j++)
            m[i].push_back(i+j);
    
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
                        line[k] = 0;
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
    if (left() == false && right() == false && up() == false && down() == false && full() == true)
    {
        cout << "Unfortunately, you lose! BUT life goes on";
        return true;
    }
    if (find2048())
    {
        cout << "2048 GOTCHA. You win!!!!";
        return true;
    }
    return false;
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


