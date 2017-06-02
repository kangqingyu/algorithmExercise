//
//  main.cpp
//  qsort&sort
//
//  Created by kqy on 15/05/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
void displayArray(int *array, int length) {
    for (int i = 0; i < length; ++i) {
        cout << array[i] << " ";
    }
}
int sortcmp(int a, int b) {
    if (a > b) return 1;
    else return 0;////升序排列，如果改为 a >b，则为降序,要注意sort()中cmp()的返值只有1和0，不像qsort中存在－1.
}
void testSort(int *array, int length) {
    sort(array, array+length, sortcmp);//默认sort排序后是升序，如果想让他降序排列，可以使用自己编的cmp函数.
    cout << endl <<" sort" << endl;
    displayArray(array, length);
}
int acompare(const void *arg1, const void *arg2) {
    return *(int *) arg1 - *(int *) arg2;
}
void testQsort(int *array, int length) {
    qsort(array, length, sizeof(int), acompare);
    cout <<endl<< "Qsort" << endl;
    displayArray(array, length);
}
int main(int argc, const char * argv[]) {
    int array[10] = {8, 23, 12, 89, 7, 37, 59, 85, 98, 29};
    testSort(array, 10);
    testQsort(array, 10);
    return 0;
    //
}
