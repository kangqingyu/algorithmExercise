#include <iostream>
using namespace std;
int moreThanHalfNumber(int *nums, int length) {
    int count = 1;
    int temp = nums[0];
    for (int i = 1; i < length; ++i) {
	if (count == 0) {
	    temp = nums[i];
	    continue;
	}
	if (nums[i] == temp) ++count;
	else -- count;
    }
    return temp;
}
int main() {
    int nums[9] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout << moreThanHalfNumber(nums, 9) << endl;
    int nums2[9] = {5, 2, 9, 2, 5, 9, 9, 9, 9};
    cout << moreThanHalfNumber(nums2, 9) << endl;
    return 0;
}


//
