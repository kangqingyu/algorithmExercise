//
//  main.cpp
//  7 Reverse Integer
//
//  Created by kqy on 04/06/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
class solution {
public:
    int reverse(int x) {
        int summer = 0;
        int multi = 1;
        int temp, flag;
        if (x > 0) {
            flag = 1;
        } else if (x < 0){
            x = -x;
            flag = 0;
        } else return 0;
        while (x) {
            temp = x % 10;
            summer += temp * multi;
            multi *= 10;
            x /= 10;
        }
        if (flag) return summer;
         else return -summer;
    }
};
int main(int argc, const char * argv[]) {
    solution s1 = * new  solution();
    cout << s1.reverse(5) << endl;
    cout << s1.reverse(15) << endl;
    cout << s1.reverse(135) << endl;
    cout << s1.reverse(-5) << endl;
    cout << s1.reverse(-135) << endl;

    return 0;
}
