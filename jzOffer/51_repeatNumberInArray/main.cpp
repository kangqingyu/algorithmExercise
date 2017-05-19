//
//  main.cpp
//  51_repeatNumberInArray
//
//  Created by kqy on 09/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
int firstRepeatNumber(int *nums, int length) {
    for (int i = 0; i < length; ++i) {
        while (nums[i] !=i) {
            int temp = nums[i];
            if (nums[i] == nums[temp]) {
                return nums[i];
            } else {
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    int array[7] = {6, 3, 1, 0 , 2, 5, 3};
    cout << firstRepeatNumber(array, 7) << endl;
    int array2[7] = {1, 3, 1, 0 , 2, 5, 3};
    cout << firstRepeatNumber(array2, 7) << endl;
    int array3[7] = {4, 3, 1, 0 , 2, 5, 3};
    cout << firstRepeatNumber(array3, 7) << endl;
    return 0;
}
int firstRepeatNumber056(int *array, int length) {
    for (int i = 0; i < length; ++i) {
        int temp = array[i];
        if (array[i] == array[temp]) {
            return temp;
        } else if (array[i] == i) continue;
        else {
            while (array[i] != array[temp]) {
                temp = array[i];
                array[i] = array[temp];
                array[temp] = temp;
            }
        }
    }
    return -1;
}

int firstRepeatNumber0509(int *array, int length) {
    if (length < 1 ) {
        return -1;
    }
    int temp;
    for (int i = 0; i < length; ++i) {
        while (array[i] != i) {
            if (array[i] == array[array[i]]) {
                return array[i];
            }
            temp = array[i];
            array[i] = array[temp];
            array[temp] = temp;
        }
    }
    return -1;
}

