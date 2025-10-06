#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// tukar head dan tail
void exchangeHeadAndTail(Node* &head_ref) {
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return; // jika node hanya ada 0 atau 1 berarti tidak perlu ditukar karena sama aja
    }

    Node* head = head_ref;
    Node* tail = head->prev; // Karena circular maka tail = head->prev

    Node* head_next = head->next;
    Node* tail_prev = tail->prev;

    // Kasus khusus: jika hanya terdapat 2 node
    if (head_next == tail) {
        // maka hanya perlu tukar head ref
        head_ref = tail;
        return;
    }


    // 1. Sambungkan bagian tengah
    head_next->prev = tail;
    tail_prev->next = head;

    // 2. tail jadi head baru
    tail->next = head_next;
    tail->prev = tail_prev;

    // 3. head jadi tail baru
    head->next = tail;
    head->prev = tail_prev; 

    // 4. Update head ref ke tail lama
    head_ref = tail;
}

// cetak list
void printList(Node* head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node* current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

// sisip di akhir
void insertEnd(Node* &head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node* tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head);

    return 0;
}