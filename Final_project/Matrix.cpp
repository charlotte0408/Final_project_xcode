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

Matrix :: Matrix()
{
    m.resize(4);
    for (int i = 0; i <= 3; i++)
        for (int j = 0; i <= 3; j++)
            m[i][j] = 0;
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

bool Matrix::up()
{
    bool order = false;
    
    return order;
}
