//
//  main.cpp
//  42_1_ReverseWordsInSentence
//
//  Created by kqy on 08/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
void reverseWord(char *pStr, char *pEnd) {
//    char *pEnd = pStr;
    char temp;
//    while (*pEnd) ++pEnd;
    while (pStr < pEnd) {
        temp = *pStr;
        *pStr = *pEnd;
        *pEnd = temp;
        ++ pStr;
        -- pEnd;
    }
}
void reverseInSentence(char *str) {
    char *pStart = str;
    char *pEnd = str;
    char *pMove = str;
    int length = pEnd - pStart + 1;
    for ( ;*pMove; ++pMove) {
        //如果是空格就continue;
        if (*pMove == ' ') continue;
        pStart = pMove; // 指向了单词的第一个；
        pEnd = pMove;
        while (*pEnd && *pEnd != ' ') ++pEnd;
        pMove = pEnd;
        --pEnd;
        reverseWord(pStart, pEnd);
    }
    while (*pEnd) ++pEnd;
    --pEnd; //找到最后，全体翻转
    reverseWord(str, pEnd);
}
int main(int argc, const char * argv[]) {
    char str[100] = "abc    cd ef gh    wo";
    cout << str << endl;
    reverseInSentence(str);
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
void reverseInSentence0508(char *str) {
    char *pEnd = str;
    while (*pEnd) ++pEnd;
    reverseWord0508(str, --pEnd );
    char *pStart = str;
    pEnd = str;
    while (*pStart) {
        if (*pStart == ' ') {
            ++pEnd, ++pStart;
//        } else if (*pEnd == '\0' || *pEnd == ' ') {
        } else if (*pEnd == ' ' || *pEnd == '\0' ) {
            --pEnd;
            reverseWord0508(pStart, pEnd);
            pStart = ++pEnd;
        } else {
            ++pEnd;
        }
//        while (*pEnd != ' ') ++pEnd;
//        --pEnd; // --pend,  pend-1一样吗？
//        reverseWord(pStart, pEnd );
//        ++pEnd;
//        while (*pEnd == ' ') ++pEnd;
//        pStart = pEnd; // first我写的，这种写法太差。
    }
}

