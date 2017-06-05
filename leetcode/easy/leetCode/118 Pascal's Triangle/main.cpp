//
//  main.cpp
//  118 Pascal's Triangle
//
//  Created by kqy on 04/06/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vals;
        vals.resize(numRows);
        for (int i = 0; i < numRows; ++i) {
            vals[i].resize(i+1);//要先开辟空间，否则就错
            vals[i][0] = 1;
            for (int j = 1; j < i ; ++j) {
                vals[i][j] = vals[i-1][j] + vals[i-1][j-1];
            }
            vals[i][i] = 1;
        }
        return vals;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    solution s1 = *new solution( );
    vector<vector<int>> vals = s1.generate(5);
    for (int i = 0; i < vals.size();  ++i) {
        for (int j = 0; j < vals[i].size(); ++j) {
            cout << vals[i][j];
        }
        cout << endl;
    }
    return 0;
}
