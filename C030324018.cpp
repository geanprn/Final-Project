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
};

int main() {
    KontakList daftar;
    // daftar.menu(); // menu akan ditambah di commit berikutnya
    return 0;
}