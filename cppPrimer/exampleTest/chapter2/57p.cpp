#include <iostream>
using namespace std;
int main() {
    const int x = 5;
    const int *  p1 = &x;
// wrong: int * const p1 = &x;
    cout << *p1 << "," << p1 << endl;
    int y = 6;
    const int z = 7;
    p1 = &z;
    cout << *p1 << "," << p1 << endl;
    return 0;
}
