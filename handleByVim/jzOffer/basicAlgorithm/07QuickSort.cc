//20170514再写一次，上次有问题
#include <iostream>
using namespace std;
int param(int *array, int low, int high) {
    int randomN = rand()%(high - low + 1) + low;  
    int temp = array[randomN];
    array[randomN] = array[high];
    array[high] = temp;
    int small = low - 1;
    for (int index = low; index < high; ++ index) {
        if (array[index] < array[high]) {
	    ++small;
	    if (index != small) {
		temp = array[index];
		array[index] = array[small];
		array[small] = temp;
		}
	}
    }
    ++ small;
    temp = array[small];
    array[small] = array[high];
    array[high] = temp;
    return small;
}
int param02(int *array, int low, int high) {
	int pivot = array[low];
	while (low < high) {
	    while ((low < high) && array[high] > pivot) -- high;
	    array[low] = array[high];
	    while (low < high && array[low] < pivot) ++ low;
	    array[high] = array[low];
	}
    array[low] = pivot;
    return low;
}
void quickSort01(int *array, int low, int high) {
    if (low >= high) return;
    int pivot = param02(array, low, high);
    quickSort01(array, low, pivot -1);
    quickSort01(array, pivot + 1, high) ;
}

int main(int argc,const char *argv[]) {
    int array[9] = {34, 2, 89, 13, 48, 8, 98, 15, 28};
    quickSort01(array, 0, 8);
    for (int i = 0; i < 9; ++i) cout << array[i] << "  ";
    cout << endl;   
    return 0;
}
