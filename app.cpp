#include "app.h"

void setFilestream(ifstream &in, string filename) {
    in = ifstream(filename);
}

void clearScreen() {
    system("cls");
}

void showMenu() {
    cout << string(10, '=') << "  MENU UTAMA  " << string(10, '=') << endl;
    cout << 
        "0. Keluar dari aplikasi\n" <<
        "1. Tambah user baru\n" <<
        "2. Tampil user tertentu\n" <<
        "3. Hapus user tertentu\n" <<
        "4. Cari user tertentu\n" <<
        "5. Tambah post dari user tertentu\n" <<
        "6. Hapus post dari user tertentu\n" <<
        "7. Tampil semua post dari user tertentu\n" <<
        "8. Cari post dari user tertentu\n" <<
        "9. Tambah relasi post ke user tertentu\n" <<
        "10. Hapus relasi post ke user tertentu\n" <<
        "11. Tampil semua post dari user dengan post terbanyak\n" <<
        "12. Cari user yang membuat post tertentu\n" << 
        "[13]. Menampilkan semua post\n" <<
        "[14]. Menampilkan semua user\n" <<
        "Masukkan angka sesuai menu yang tersedia: ";
}

void askAction(int &action) {
    cin >> action;
}

void askPostID(string &postID) {
    cout << "Masukkan ID dari post: ";
    cin >> postID;
}

void askUserID(string &userID) {
    cout << "Masukkan ID dari user: ";
    cin >> userID;
}

void postNotFound(string postID) {
    cout << "Post dengan ID " << postID << " tidak ditemukan" << endl;
}
void userNotFound(string userID) {
    cout << "User dengan ID " << userID << " tidak ditemukan" << endl;
}
