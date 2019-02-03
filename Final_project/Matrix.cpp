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
    m.resize(3);
    for (int i = 0; i <3; i++)
        for (int j = 0; i < 3; j++)
            m[i][j] = 0;
}

