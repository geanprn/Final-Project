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

    void searchByName(const string& keyword) const {Add commentMore actions
        Kontak* cur = head; int idx = 1; bool found = false;
        while (cur) {
            if (cur->nama.find(keyword) != string::npos) {
                cout << "Ditemukan di posisi " << idx << ":\nNama: " << cur->nama << ", Nomor: " << cur->nomor << ", Email: " << cur->email << "\n";
                found = true;
            }
            cur = cur->next; idx++;
        }
        if (!found) cout << "Kontak dengan nama \"" << keyword << "\" tidak ditemukan.\n";
    }

    void edit(int pos) {Add commentMore actions
        if (!head || pos < 1) { cout << "List kosong/posisi tidak valid!\n"; return; }
        Kontak* cur = head; int idx = 1;
        while (cur && idx < pos) { cur = cur->next; idx++; }
        if (!cur) { cout << "Posisi tidak ditemukan!\n"; return; }
        string n, no, e;
        cout << "Edit Nama (lama: " << cur->nama << "): "; getline(cin, n);
        cout << "Edit Nomor (lama: " << cur->nomor << "): "; getline(cin, no);
        cout << "Edit Email (lama: " << cur->email << "): "; getline(cin, e);
        if (!n.empty()) cur->nama = n;
        if (!no.empty()) cur->nomor = no;
        if (!e.empty()) cur->email = e;
        cout << "Kontak pada posisi " << pos << " berhasil diedit.\n";
    }

    void exportCSV(const string& filename = "kontak.csv") const {Add commentMore actions
        ofstream file(filename);
        if (!file) { cout << "Gagal membuka file untuk menulis.\n"; return; }
        file << "No,Nama,Nomor,Email\n";
        Kontak* cur = head; int idx = 1;
        while (cur) {
            file << idx++ << ',' << '"' << cur->nama << '"' << ',' << '"' << cur->nomor << '"' << ',' << '"' << cur->email << '"' << '\n';
            cur = cur->next;
        }
        file.close();
        cout << "Daftar kontak berhasil diekspor ke " << filename << "\n";
    }

    void menu() {Add commentMore actions
        int pil, pos;
        string n, no, e;
        do {
    #ifdef _WIN32
            system("cls");
    #else
            cout << "\033[2J\033[H";
    #endif
            cout << "\n=== MENU DAFTAR KONTAK ===\n"
                 << "1. Tambah Awal\n2. Tambah Akhir\n3. Tambah Tengah\n4. Hapus\n5. Tampilkan\n6. Urutkan Nama\n7. Cari Kontak\n8. Edit Kontak\n9. Ekspor ke CSV\n0. Keluar\nPilih: ";
            cin >> pil; cin.ignore();
            switch (pil) {
                case 1:
                    cout << "Nama: "; getline(cin, n);
                    cout << "Nomor: "; getline(cin, no);
                    cout << "Email: "; getline(cin, e);
                    addFirst(n, no, e); pause(); break;
                case 2:
                    cout << "Nama: "; getline(cin, n);
                    cout << "Nomor: "; getline(cin, no);
                    cout << "Email: "; getline(cin, e);
                    addLast(n, no, e); pause(); break;
                case 3:
                    cout << "Nama: "; getline(cin, n);
                    cout << "Nomor: "; getline(cin, no);
                    cout << "Email: "; getline(cin, e);
                    cout << "Posisi: "; cin >> pos; cin.ignore();
                    insert(n, no, e, pos); pause(); break;
                case 4:
                    cout << "Posisi yang dihapus: "; cin >> pos; cin.ignore();
                    remove(pos); pause(); break;
                case 5:
                    print(); pause(); break;
                case 6:
                    sortByName(); pause(); break;
                case 7: {
                    string key;
                    cout << "Masukkan nama yang dicari: "; getline(cin, key);
                    searchByName(key); pause(); break; }
                case 8:
                    cout << "Masukkan posisi kontak yang akan diedit: "; cin >> pos; cin.ignore();
                    edit(pos); pause(); break;
                case 9:
                    exportCSV(); pause(); break;
            }
        } while (pil != 0);
    }

    void pause() const { cout << "Tekan ENTER untuk lanjut..."; cin.get(); }
};

int main() {
    KontakList daftar;
    daftar.menu();
    return 0;
}