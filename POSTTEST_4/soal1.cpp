#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// menambahkan data ke dalam stak
void push(Node* & top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// menghapus data paling atas atau data terakhir yang masuk ke stak
char pop(Node* & top) {
    if (top == nullptr) return '\0'; // jika stak kosong maka akan mengembalikan nnilai 0 karena tidak ada yang bisa dihapus
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// membalik string
string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = ""; // Inisialisasi string kosong

    // Langkah 1: Masukkan data ke dalam stak
    for (char c : s) {
        push(stackTop, c);
    }

    // Langkah 2: Keluarkan semua data, karena jika dikeluarkan maka datanya bisa menjadi terbalik karena lifo
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli : " << text << endl;
    cout << "Teks terbalik : " << reverseString(text) << endl;
    return 0;
}