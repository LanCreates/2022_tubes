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
        "1. Tambahkan parent baru\n" <<
        "2. Cetak seluruh parent\n" <<
        "3. Hapus sebuah parent\n" <<
        "4. Cari parent tertentu\n" <<
        "5. Tambahkan child baru\n" <<
        "6. Hubungkan child ke parent\n" <<
        "7. Cetak seluruh parent dan child\n" <<
        "8. Cari sebuah child\n" <<
        "9. Hapus sebuah child\n" <<
        "10. Hitung banyak parent\n" <<
        "Masukkan angka sesuai menu yang tersedia: ";
}

void askAction(int &action) {
    cin >> action;
}
