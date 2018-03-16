// 53  max subarray
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	
}

int maxSubArray(int A[], int n) {
    int tMax = 0;
    int maxNum = 0;
    int temp;
    for (int i = 0; i < n; ++i) {
	    if (tMax > maxNum) maxNum = tMax;
        temp = A[i];
        tMax += temp;
    }	
    return maxNum;
}