#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node * &head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: jika list kosong maka node baru menjadi datu satunya node selanjutnya dan sebelumnya
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node* head = head_ref;
    Node* tail = head->prev;

    // Kasus 2: jika data baru lebih kecil dari head maka tambahkan di awal
    if (data <= head->data) {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head_ref = newNode; // head di update ke data baru karena dia adalah elemen paling kecil
        return;
    }

    // Kasus 3: mencari posisi tengah atau akhir
    Node* current = head;
    // Cari node terakhir yang nilainya kurang dari data
    while (current->next != head && current->next->data < data) {
        current = current->next;
    }

    // tambahkan newNode setelah current
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node *head = nullptr;

    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);

    return 0;
}