#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

int main() {
    const int N = 5;
    Mahasiswa mhs[N];

    cout << "Input data mahasiswa:" << endl;
    for (int i = 0; i < N; i++) {
        cout <<endl<< "Mahasiswa " << i+1 << endl;
        cout << "Nama : "; cin >> mhs[i].nama;
        cout << "Nim  : "; cin >> mhs[i].nim;
        cout << "Ipk  : "; cin >> mhs[i].ipk;
    }

    int tinggi = 0;
    for (int i = 1; i < N; i++) {
        if (mhs[i].ipk > mhs[tinggi].ipk) {
            tinggi = i;
        }
    }

    cout <<endl<< "Mahasiswa dengan ipk paling ringii adalah " << mhs[tinggi].nama<< " Dengan IPK "<< mhs[tinggi].ipk << endl;

    return 0;
}
