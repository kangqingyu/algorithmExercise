//
//  main.cpp
//  26RemoveDuplicatesFromSortedArray
//
//  Created by kqy on 14/05/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class solution{
public:
    int removeDuplicates_002(int *nums, int numsSize) {
        if (numsSize == 0) {
            return 0;
        }
        int lastIndex = 0;
        for (int i = 1; i < numsSize; ++i) {
            if (nums[i] != nums[lastIndex]) {
                nums[++lastIndex] = nums[i];
            }
        }
        return lastIndex + 1;
    }

    int removeDuplicates_001(int *array, int length) {
        int lastIndex = 0;
        array[lastIndex] = array[0];//本来就是一个数组，多些一举。
        for (int i = 1; i < length; ++i) {
            int x = array[i];
            int y = array[lastIndex];
            if (array[i] != array[lastIndex]) {
                array[++lastIndex] = array[i];
            }
        }
        return lastIndex + 1;
    }
    int removeDuplicates2_001(vector<int> nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int lastIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[lastIndex]) {
                nums[++lastIndex] = nums[i];
            }
        }
        return lastIndex + 1;
    }
};
int main(int argc, const char * argv[]) {
    solution c1 = *new solution();
    int array1[10]  = {2, 2, 9, 9, 9, 18, 25, 25, 29, 29};//
    int array2[8] = {2, 2, 3, 4, 5, 6, 8, 8};
    int array3[3] = {2, 2, 3};
    int array4[4] = {2, 2, 2, 3};
    int array5[4] = {1, 2, 3, 4};
    int array6[0];
    cout << c1.removeDuplicates_002(array1, 10 ) << endl;
    cout << c1.removeDuplicates_002(array2, 8 ) << endl;
    cout << c1.removeDuplicates_002(array3, 3 ) << endl;
    cout << c1.removeDuplicates_002(array4, 4 ) << endl;
    cout << c1.removeDuplicates_002(array5, 4 ) << endl;
    cout << c1.removeDuplicates_002(array6, 0 ) << endl;
    cout << "vector: "<< endl;
    vector<int> nums1 ={2, 2, 9, 9, 9, 18, 25, 25, 29, 29};
    vector<int> nums2 = {2, 2, 3, 4, 5, 6, 8, 8};
    vector<int> nums3 = {2, 2, 3};
    vector<int> nums4 ={2, 2, 2, 4};
    vector<int> nums5 = {1, 2, 3, 4};
    vector<int> nums6 ;
    
    cout << c1.removeDuplicates2_001(nums1 ) << endl;
    cout << c1.removeDuplicates2_001(nums2 ) << endl;
    cout << c1.removeDuplicates2_001(nums3 ) << endl;
    cout << c1.removeDuplicates2_001(nums4 ) << endl;
    cout << c1.removeDuplicates2_001(nums5 ) << endl;
    cout << c1.removeDuplicates2_001(nums6 ) << endl;
    return 0;
}
