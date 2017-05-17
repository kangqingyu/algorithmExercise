//
//  main.cpp
//  44_continousCards
//
//  Created by kqy on 08/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int array[8] = {10, 4, 5, 7, 0, 12, 6, 9};
    bool b1 = isContinous(array, sizeof(array) / sizeof(int));
    cout << b1 << endl;
    return 0;
}
int compare0516(const void* arg1, const void* arg2) {
    return *(int *)arg1- *(int *)arg2;
}
bool isContinous0516(int *array, int length) {
    int zeroCount = 0;
    int grapNum = 0;
    sort(array, array + length);
    for (int i = 0; i < length; ++i) {
        if (array[i] == 0) {
            ++zeroCount;
        } else break;
    }
    for (int i = zeroCount + 1; i < length; ++i) {
        if (array[i] == array[i-1]) {
            return false;
        }
        grapNum += (array[i] - array[i-1] - 1);
    }
    cout << zeroCount << "----0, dis: " << grapNum << endl;
    if (zeroCount >= grapNum) {
        return true;
    }
    return false;
}

int compare0509(const void *arg1, const void *arg2) {
    return *(int *)arg1 - *(int *)arg2;
}
bool isContinous0509(int *numbers, int length) {
    int zeroNumber = 0;
    int distance = 0;
    int front , back;
    qsort (numbers, length, sizeof(int), compare0509);
    for (int i = 0; i < length; ++ i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < length && numbers[i] == 0; ++i) ++zeroNumber;
    front = numbers[zeroNumber];
    back = numbers[zeroNumber];
    for (int i = zeroNumber + 1; i < length; ++i) {
        front = numbers[i];
        if (front == back) {
            return false;
        }
        distance += (front - back - 1);
        back = front;
    }
    if (zeroNumber >= distance) {
        return true;
    }
    return false;
}

