//
//  main.cpp
//  42_2_LeftRotateString
//
//  Created by kqy on 08/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
void reverseWord(char *pStart, char *pEnd) {
    char temp;
    while (pStart < pEnd) {
        temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        ++pStart;
        -- pEnd;
    }
}
void leftRotatedStr(char *str, int index) {
    char *pStart = str;
    char *pEnd = str + index - 1;
    reverseWord(pStart, pEnd);
    pStart = pEnd + 1;
    while (*pEnd) ++pEnd;
    --pEnd;
    if (*pStart) {
        reverseWord(pStart, pEnd);
    }
    reverseWord(str, pEnd);
}
int main(int argc, const char * argv[]) {
    char str[100] = "abcdefgh";
    cout << str << endl;
    leftRotatedStr(str, 1);
    cout << str << endl;
    return 0;
}
void reverseWord0508(char *start, char *end) {
    if (start >= end) {
        return;
    }
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        ++start, --end;
    }
}
void leftRotatedStr0508(char *str, int startLocation) {
    char *pStart = str;
    char *pEnd = str;
    while (*pEnd) ++pEnd;
    --pEnd;
    char *pMiddle = pStart;
    for (int i = 1; i < startLocation; ++i)  ++ pMiddle;
    reverseWord0508(pStart, pMiddle);
    reverseWord0508(++pMiddle, pEnd);
    reverseWord0508(pStart,  pEnd);

}

