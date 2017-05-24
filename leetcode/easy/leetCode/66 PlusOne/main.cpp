//
//  main.cpp
//  66 PlusOne
//
//  Created by kqy on 22/05/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//plusOne2中用plusWithDigit
//看了key,还有更好的方法：
class solution {
public:
    vector<int> plusOne2(vector<int> &nums) {
//        return plusWithDigit(nums, 1);// 0523 ac leetcode
          addReverse(nums, 1); //0524 ac leetcode
        return nums;
    }
private:
    vector<int> plusWithDigit(vector<int> &nums, int digit) {
        int sum = 0;
        for (auto it = nums.end() -1; it >= nums.begin() ; --it) {
            cout << "---   " ;
            sum = digit + *it;
            cout <<  "sum:" << sum << "  *it:" << *it << "        ";
            *it = sum % 10;
//          j/  sum /= 10;
            digit = sum / 10;
            cout << "digit : " << digit << endl;
        }
        if (digit > 0) {
            nums.insert(nums.begin(), digit);
        }
        return nums;
    }
    /* plusWithDigit:  ac到leetcode整理。
     vector<int> plusWithDigit(vector<int> &digits ) {
     int digit = 1;
     int sum = 0;
     for (auto it = digits.end() -1; it >= digits.begin() ; --it) {
     sum = digit + *it;
    *it = sum % 10;
     digit = sum / 10;
     }
     if (digit > 0) {
     digits.insert(digits.begin(), digit);
     }
     return digits;
     }

     
     */
    void addReverse(vector<int> &nums, int digit) {
        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
//            int temp  = *it;// *it的计算分为2步，这样就不用 temp 这个变量了。
            *it = (*it + digit);
            cout << "*it: " << *it << "   digit: " << digit << endl;
            digit =  *it / 10;
            *it = *it %10;
        }
        if (digit > 0) {
            nums.insert(nums.begin(), digit);
        }
//        return nums;
    }
};
/*     addReverse:  ac到leetcode整理。
 vector<int> addReverse(vector<int> &digits, int digit) {
 int digit = 1;
 for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
 *it = (*it + digit);
 digit =  *it / 10;
 *it = *it %10;
 }
 if (digit > 0) {
 digits.insert(digits.begin(), digit);
 }
 return digits;
 */
vector<int> plusOne1(vector<int> &digits) {
    int one = 1;
    int sum = 0;
    for (int i = digits.size() - 1; i >= 0; --i) {
        sum = digits[i] + one;
        one = sum / 10;
        sum %= 10;
        digits[i] = sum;
    }
    if (one > 0) {
        //首位加一个0. insert函数。
        digits.insert(digits.begin(), one);
    }
    return digits;
}
int main(int argc, const char * argv[]) {
    vector<int> nums1 =  {9, 2, 9, 9, 8};
    nums1 = plusOne1(nums1);
    for (int i= 0; i < nums1.size(); ++i) {
        cout << nums1[i] << "  ";
    }
    cout << endl;
    vector<int> nums2 =  {9, 9, 9, 9, 9};
//    vector<int> nums2 =  {3, 4, 5, 6, 7};
    solution s2 = *new solution();
    s2.plusOne2(nums2);
    for (int i= 0; i < nums2.size(); ++i) {
        cout << nums2[i] << "  ";
    }
    return 0;
}
