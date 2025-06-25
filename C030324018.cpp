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
    
};

int main() {
    KontakList daftar;
    // daftar.menu(); // menu akan ditambah di commit berikutnya
    return 0;
}