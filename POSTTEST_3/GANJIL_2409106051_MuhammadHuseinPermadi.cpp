#include <iostream>
#include <string>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
    Item* prev;
};

Item* head = nullptr;

const int JUMLAH_AWAL = 51;
const int SISIP = 2;

Item* buatItem(string nama, string tipe) {
    Item* baru = new Item;
    baru->namaItem = nama;
    baru->jumlah = JUMLAH_AWAL;
    baru->tipe = tipe;
    baru->next = nullptr;
    baru->prev = nullptr;
    return baru;
}

void tambahakhir(string nama, string tipe) {
    Item* baru = buatItem(nama, tipe);
    if (!head) {
        head = baru;
    } else {
        Item* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
        baru->prev = temp;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan dengan jumlah " 
         << JUMLAH_AWAL << "!\n";
}

void sisipItem(string nama, string tipe) {
    Item* baru = buatItem(nama, tipe);

    if (SISIP <= 1 || !head) {
        baru->next = head;
        if (head) {
            head->prev = baru;
        }
        head = baru;
    } else {
        Item* temp = head;
        int posisi = 1;
        while (temp->next && posisi < SISIP - 1) {
            temp = temp->next;
            posisi++;
        }
        baru->next = temp->next;
        baru->prev = temp;
        if (temp->next) {
            temp->next->prev = baru;
        }
        temp->next = baru;
    }
    cout << "Item \"" << nama << "\" berhasil disisipkan pada slot " 
         << SISIP << "!\n";
}

void hapusItemTerakhir() {
    if (!head) {
        cout << "Inventory kosong!\n";
        return;
    }
    if (!head->next) {
        cout << "Item \"" << head->namaItem << "\" dihapus.\n";
        delete head;
        head = nullptr;
        return;
    }
    Item* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    cout << "Item \"" << temp->namaItem << "\" dihapus.\n";
    temp->prev->next = nullptr;
    delete temp;
}

void gunakanItem(string nama) {
    if (!head) {
        cout << "Inventory kosong!\n";
        return;
    }
    Item* temp = head;
    while (temp) {
        if (temp->namaItem == nama) {
            temp->jumlah--;
            cout << "Menggunakan 1 " << nama << ". Sisa: " << temp->jumlah << "\n";
            if (temp->jumlah <= 0) {
                cout << "Item \"" << nama << "\" habis dan dihapus dari inventory.\n";
                if (temp == head) {
                    head = temp->next;
                    if (head) head->prev = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    if (temp->next) {
                        temp->next->prev = temp->prev;
                    }
                }
                delete temp;
            }
            return;
        }
        temp = temp->next;
    }
    cout << "Item \"" << nama << "\" tidak ditemukan!\n";
}

void tampilkanInventory() {
    if (!head) {
        cout << endl << "Tidak ada item, MAKANYA FARMING KOCAK !" << endl << endl;
        return;
    }
    cout << "\nDaftar Item\n";
    Item* temp = head;
    int i = 1;
    while (temp) {
        cout << i++ << ". " << temp->namaItem 
             << " (" << temp->tipe << ") - Jumlah: " << temp->jumlah << "\n";
        temp = temp->next;
    }
    cout << endl << endl;
}

void tampilkanTerbalik() {
    if (!head) {
        cout << endl << "Tidak ada item, MAKANYA FARMING KOCAK !" << endl << endl;
        return;
    }
    Item* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    cout << "\nDaftar Item (Dari Belakang)\n";
    Item* temp = tail;
    int i = 1;
    while (temp) {
        cout << i++ << ". " << temp->namaItem 
             << " (" << temp->tipe << ") - Jumlah: " << temp->jumlah << "\n";
        temp = temp->prev;
    }
    cout << endl << endl;
}

void tampilkanDetail(string nama) {
    if (!head) {
        cout << "Inventory kosong!\n\n";
        return;
    }
    Item* temp = head;
    while (temp) {
        if (temp->namaItem == nama) {
            cout << "\nDetail Item:\n";
            cout << "Nama: " << temp->namaItem << "\n";
            cout << "Tipe: " << temp->tipe << "\n";
            cout << "Jumlah: " << temp->jumlah << "\n\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Item \"" << nama << "\" tidak ditemukan!\n\n";
}

int main() {
    int pilihan;
    string nama, tipe;

    do {
        cout << "Husein - 2409106051" << endl;
        cout << "Manajemen Inventory" << endl;
        cout << "1. Tambah Item Baru" << endl;
        cout << "2. Sisipkan Item" << endl;
        cout << "3. Hancurkan Item Terakhir" << endl;
        cout << "4. Gunakan Item" << endl;
        cout << "5. Lihat Inventory" << endl;
        cout << "6. Tampilkan Inventory dari Belakang" << endl;
        cout << "7. Tampilkan Detail Item" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama item: ";
                cin >> nama;
                cout << "Masukkan tipe item: ";
                cin >> tipe;
                tambahakhir(nama, tipe);
                break;
            case 2:
                cout << "Masukkan nama item: ";
                cin >> nama;
                cout << "Masukkan tipe item: ";
                cin >> tipe;
                sisipItem(nama, tipe);
                break;
            case 3:
                hapusItemTerakhir();
                break;
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                cin >> nama;
                gunakanItem(nama);
                break;
            case 5:
                tampilkanInventory();
                break;
            case 6:
                tampilkanTerbalik();
                break;
            case 7:
                cout << "Masukkan nama item: ";
                cin >> nama;
                tampilkanDetail(nama);
                break;
            case 0:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}