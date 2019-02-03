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
    for (int i = 0; i <= 3; i++)
    {
        vector <int> line = m[i];
        for (int j = 0; j< 3; j++)
        {
            if (line[j] != line[j+1] && line[j+1] != 0)
                continue;
            if (line[j] == 0)
                continue;
            for (int k = j+1; k <= 3; k++)
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
                        line[k] = line[j];
                        line[k] = 0;
                        order = true;
                        j = k;
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
        for (int j = 3; j >= 1; j--)
        {
            if (line[j] != line[j-1] && line[j-1] != 0)
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
                        j = k;
                        break;
                    }
                }
                
            }
        }
    }
    return order;
}
