#include <iostream>
#include <string>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
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
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan dengan jumlah " 
         << JUMLAH_AWAL << "!\n";
}

void sisipItem(string nama, string tipe) {
    Item* baru = buatItem(nama, tipe);

    if (SISIP <= 1 || !head) {
        baru->next = head;
        head = baru;
    } else {
        Item* temp = head;
        int posisi = 1;
        while (temp->next && posisi < SISIP - 1) {
            temp = temp->next;
            posisi++;
        }
        baru->next = temp->next;
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
    while (temp->next->next) {
        temp = temp->next;
    }
    cout << "Item \"" << temp->next->namaItem << "\" dihapus.\n";
    delete temp->next;
    temp->next = nullptr;
}

void gunakanItem(string nama) {
    if (!head) {
        cout << "Inventory kosong!\n";
        return;
    }
    Item* temp = head;
    Item* prev = nullptr;

    while (temp) {
        if (temp->namaItem == nama) {
            temp->jumlah--;
            cout << "Menggunakan 1 " << nama << ". Sisa: " << temp->jumlah << "\n";
            if (temp->jumlah <= 0) {
                cout << "Item \"" << nama << "\" habis dan dihapus dari inventory.\n";
                if (!prev) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Item \"" << nama << "\" tidak ditemukan!\n";
}

void tampilkanInventory() {
    if (!head) {
        cout << endl<<"Tidak ada item, MAKANYA FARMING KOCAK !"<<endl<<endl;
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
    cout <<endl<<endl;
}

int main() {
    int pilihan;
    string nama, tipe;

    do {
        cout << "Husein - 2409106051"<<endl;
        cout << "Manajemen Inventory"<<endl;
        cout << "1. Tambah Item Baru"<<endl;
        cout << "2. Sisipkan Item"<<endl;
        cout << "3. Hancurkan Item Terakhir"<<endl;
        cout << "4. Gunakan Item"<<endl;
        cout << "5. Lihat Inventory"<<endl;
        cout << "0. Keluar"<<endl;
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
            case 0:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
