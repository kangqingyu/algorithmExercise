#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	
}

int searchInsert(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size(); ++i) {
		if (target == nums[i]) return i;
	}
	return 0;
}

int searchInsert(int A[], int n, int target) {
	if (target > A[n-1] || target < A[0])	{
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (target == A[i]) 
		    return i;
		else {
			
		}
	}
	return 0;
	
	
}