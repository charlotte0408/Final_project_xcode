//
//  main.cpp
//  Final_project
//
//  Created by 黄逸欢 on 2/2/19.
//  Copyright © 2019 Yihuan Huang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
    Matrix();
    bool left();
    bool right();
    bool up();
    bool down();
private:
    vector<vector<int>> m;
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
