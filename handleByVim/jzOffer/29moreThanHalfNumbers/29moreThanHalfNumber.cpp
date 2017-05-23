#include <iostream>
using namespace std;
int param(int *array, int low, int high) {
    if (low >= high) return -1;
    int small = low - 1;
    int random = rand() % (high - low + 1) + low;
    int temp = random ;
    random = high;
    high = temp;
    int pivot = array[high];  
    for (int index = low; index < high; ++index) {
	if (array[index] < pivot) {
	    ++ small;
	    if (index != small) {
		array[index] = array[index] + array[small];
		array[small] = array[index] - array[small];
		array[index] = array[index] - array[small];
	    }
	}
    }
    ++ small;
    array[small] = array[small] + array[high];  
    array[high] = array[small] - array[high];
    array[small] = array[small] - array[high];
    return small;
}

int moreThanHalfNumber(int *array, int length) {
    int low = 0;
    int high = length - 1; 
    int middle = (low + high) >> 1;
    while (low < high) {
	int result = param(array, low, high); 
	if (result == middle ) return array[middle];
	else if (result > middle) {
	    high = middle - 1;
	} else low = middle + 1;
    }
    return -2;
}
int main() {
    int nums[9] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout << moreThanHalfNumber(nums, 9);
    return 0;
}
