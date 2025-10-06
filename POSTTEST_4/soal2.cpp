#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node* & top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node* & top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

// cek apakah kurung seimbang
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char c : expr) {
        // jika kurung buka masukan stak
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // Jika kruung tutup
        else if (c == ')' || c == '}' || c == ']') {
            // stak kosong = tidak seimbang
            if (stackTop == nullptr) return false;

            char open = pop(stackTop);
            // Periksa apakah kurung sama antara buka dan tutup
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                return false;
            }
        }
    }

    // jika stak masih berisi maka ada kurung yang belum ditutup
    return stackTop == nullptr;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}