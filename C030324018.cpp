#include <iostream>Add commentMore actions
#include <string>
#include <iomanip>
#include <fstream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

struct Kontak {
    string nama, nomor, email;
    Kontak* next;
    Kontak(string n, string no, string e) : nama(n), nomor(no), email(e), next(nullptr) {}
};

class KontakList {
    Kontak* head = nullptr, *tail = nullptr;
public:
    ~KontakList() { while (head) { Kontak* t = head; head = head->next; delete t; } }

    void addFirst(const string& n, const string& no, const string& e) {Add commentMore actions
        Kontak* node = new Kontak(n, no, e);
        if (!head) head = tail = node;
        else { node->next = head; head = node; }
        cout << "Kontak ditambah di awal.\n";
    }
    
    void addLast(const string& n, const string& no, const string& e) {
        Kontak* node = new Kontak(n, no, e);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
        cout << "Kontak ditambah di akhir.\n";
    }

    void insert(const string& n, const string& no, const string& e, int pos) {Add commentMore actions
        if (!head || pos <= 1) { cout << "Posisi tidak valid!\n"; return; }
        Kontak* cur = head; int i = 1;
        while (cur && i < pos - 1) { cur = cur->next; i++; }
        if (!cur || !cur->next) { cout << "Posisi terlalu besar!\n"; return; }
        Kontak* node = new Kontak(n, no, e);
        node->next = cur->next; cur->next = node;
        cout << "Kontak ditambah di posisi " << pos << ".\n";
    }

    void remove(int pos) {Add commentMore actions
        if (!head || pos < 1) { cout << "List kosong/posisi tidak valid!\n"; return; }
        if (pos == 1) {
            Kontak* t = head; head = head->next; delete t;
            if (!head) tail = nullptr;
            cout << "Kontak posisi 1 dihapus.\n"; return;
        }
        Kontak* cur = head; int i = 1;
        while (cur->next && i < pos - 1) { cur = cur->next; i++; }
        if (!cur->next) { cout << "Posisi tidak ditemukan!\n"; return; }
        Kontak* t = cur->next; cur->next = t->next;
        if (t == tail) tail = cur;
        delete t;
        cout << "Kontak posisi " << pos << " dihapus.\n";
    }

    void print() const {Add commentMore actions
        if (!head) { cout << "Daftar kontak kosong.\n"; return; }
        cout << left << setw(5) << "No" << setw(18) << "Nama" << setw(16) << "Nomor" << setw(25) << "Email" << endl
             << string(64, '-') << endl;
        Kontak* cur = head; int idx = 1;
        while (cur) {
            cout << left << setw(5) << idx++ << setw(18) << cur->nama << setw(16) << cur->nomor << setw(25) << cur->email << endl;
            cur = cur->next;
        }
        cout << string(64, '-') << endl;
    }

    void sortByName() {Add commentMore actions
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Kontak* cur = head;
            while (cur->next) {
                if (cur->nama > cur->next->nama) {
                    swap(cur->nama, cur->next->nama);
                    swap(cur->nomor, cur->next->nomor);
                    swap(cur->email, cur->next->email);
                    swapped = true;
                }
                cur = cur->next;
            }
        } while (swapped);
        cout << "Kontak diurutkan berdasarkan nama.\n";
    }

    

};

int main() {
    KontakList daftar;
    // daftar.menu(); // menu akan ditambah di commit berikutnya
    return 0;
}