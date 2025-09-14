#include <iostream>
using namespace std;

void tukar(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan x: ";
    cin >> x;
    cout << "Masukkan y: ";
    cin >> y;

    cout << endl<<"Sebelum ditukar: x = " << x << ", y = " << y << endl;

    int *px = &x, *py = &y;
    tukar(&px, &py);

    cout << "Sesudah ditukar: x = " << x << ", y = " << y << endl;

    return 0;
}
