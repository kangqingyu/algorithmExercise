#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	
}

int searchInsert(vector<int>& nums, int target) {
	if (target < nums[0]) return 0;
	int i;
	for (i = 0; i < nums.size(); ++i) {
		if (target == nums[i]) return i;
	}
	return i;
}

int searchInsert(int A[], int n, int target) {
	if ( target < A[0])	{
		return 0;
	}
	int i;
	for (i = 0; i < n; ++i) {
		if (target == A[i]) 
		    return i;
		else {
			
		}
	}
	return i;
	
	
}