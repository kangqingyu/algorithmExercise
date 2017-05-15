//
//  main.cpp
//  79p
//
//  Created by kqy on 13/05/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void test1(){
    string::size_type size = 5;
    cout << size << endl;
    size = -1;
    cout << size << endl;
    string s1 = "hello";
    string s3 = '#'+ "world" + s1;
    cout << s3 << endl;
}
void test2(){
    string s1 = "hello, world; can? ok";
    int count = 0;
    for ( int c : s1) {
        if (ispunct(c)) ++ count;
    }
    cout << count << endl;
}
void t3_83p2() {
    string s1("hello?World");
    for (char &c : s1) {
//        if (islower(c))
            c = toupper(c);
    }
    cout << s1 << endl;
}
void t4_85(){
    string s1("hello    worle good morning");
    for (char &c : s1) {
        if (isgraph(c)) c = toupper(c);
        else break;
    }
    cout << s1 << endl;
}
void dV(vector<int> v) {
    for (int i : v) cout << i ;
    cout << endl;
}

void t5_87p() {
    vector<int> v1(5, 3);
    vector<int> v2(v1);
    vector<int> v3 ;
    vector<int> v4 = {3, 8, 9, 2,23};
    vector<string> v5 = {"hello", "world", "ok"};
    dV(v1);
    dV(v2);
    dV(v3);
    dV(v4);
    for (string s : v5) cout << s << ";" ;
    cout << endl;
}

int main(int argc, const char * argv[]) {
    t5_87p();
    return 0;
}

