//
//  main.cpp
//  27removeElement
//
//  Created by kqy on 14/05/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class solution{
public:
    int removeElement1_002(int* nums, int numsSize, int val) {
        int count = 0;
        int j = 0;
        for (int i = 0; i < numsSize; ++i) {
            int x = nums[i];
            int y = val;
            if (nums[i] != val) {
                nums[j++] = nums[i];
                ++count;
            }
        }
        nums[j] = '\0';//删除这一行，就是正解答案了！！！
        return count;
    }
    //我得到：0 2 2 0 3 1 3 0 3 4
//     input  :  [0,2,2,0,3,1,4,4,3,4]
    int removeElement1_001(int array[], int length, int target) {
        int count = 0;
        int j = 0;
        for (int i = 0; i < length; ++i) {
            if (array[i] == target) {
                continue;
            }
            array[j++] = array[i];
            ++count;
        }
        array[j] = '\0';
        return count;
    }
    /*001:
     Runtime Error Message:
     free(): invalid next size (fast): 0x00000000017c22d0 ***
     */
    int removeElement2_002(vector<int> &v, int target) {
        int count = 0;
        int j = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != target) {
                v[j++] = v[i];
                ++count;
            }
        }
        // \0不用了，如何处理最后一个元素？
#warning '\0'
        return count;
    }

    int removeElement2_001(vector<int> &v, int target) {
        int count = 0;
        int j = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == target) {
                continue;
            }
            v[j++] = v[i];
            ++count;
        }
        // \0不用了，如何处理最后一个元素？
#warning '\0'
        return count;
    }
};
int main(int argc, const char * argv[]) {
    int array1[10]  = {3, 8, 9, 2, 3, 8, 5, 2, 9, 3};// 3个3
    int array2[8] = {1, 2, 3, 4, 5, 6, 8, 8};
    int array001[10] = {0,2,2,0,3,1,4,4,3,4};
    solution c1 = *new solution();
//    cout << c1.removeElement1_001(array1, 10, 3) << endl;
//    cout << c1.removeElement1_001(array2, 8, 8) << endl;
    cout << "001error:" << c1.removeElement1_002(array001, 10, 4) << endl;
    for (int i = 0; i < 10; ++i)         cout << array001[i] << " ";
    cout << endl;
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 1};
    cout << c1.removeElement2_002(v1, 1);
    std::cout << endl;
    for (auto x = v1.begin(); x < v1.end(); ++x) {
        cout << *x;
    }
    return 0;
}
