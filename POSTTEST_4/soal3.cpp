#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

// Menambahkan data ke queueue
void enqueue(Node* & front, Node* & rear, string document) {
    Node* newNode = new Node{document, nullptr};

    if (front == nullptr) {
        // Jika antrian kosong kepala dan ekor akan menunjuk ke data baru
        front = rear = newNode;
    } else {
        // jika antrean tidak kosong maka ekor akan ke node baru
        rear->next = newNode;
        rear = newNode;
    }
}

// hapus antrean, karena algoritma queueue maka yaang dihapus yabng depan
string dequeue(Node* & front, Node* & rear) {
    if (front == nullptr) return "";

    string doc = front->document;
    Node* temp = front;
    front = front->next;

    // Jika setelah hapus antrean jadi kosong maka update ekor menjadi nullpter 
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    return doc;
}

// Memproses data menjadi fifo (masuk pertama keluar pertama)
void processAllDocuments(Node* & front, Node* & rear) {
    while (front != nullptr) {
        cout << "Memproses: " << dequeue(front, rear) << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}