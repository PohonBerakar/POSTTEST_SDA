#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N];
    cout << "Masukkan elemen matrix 3x3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Baris " << i+1 << " Kolom " << j+1 << " : ";
            cin >> matriks[i][j];
        }
    }
    int jumlah = 0;
    for (int i = 0; i < N; i++) {
        jumlah += matriks[i][i];
        jumlah += matriks[i][N-1-i];
    }
    if (N % 2 == 1) {
        jumlah -= matriks[N/2][N/2];
    }
    cout << endl<<"Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    cout <<endl <<"Jumlah diagonal utama + sekunder = " << jumlah << endl;
    return 0;
}
