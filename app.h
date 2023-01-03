#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "MLL.h"

using namespace std;

// User action enums goes here
enum action {
    USER_EXIT = 0,
    TAMBAH_USER_BARU,
    TAMPIL_USER_X,
    HAPUS_USER_X,
    CARI_USER_X,
    TAMBAH_POST_USER_X,
    HAPUS_POST_USER_X,
    TAMPIL_POST_USER_X,
    CARI_POST_USER_X,
    BUAT_RELASI_POST_KE_USER,
    HAPUS_RELASI_POST_KE_USER,
    TAMPIL_USER_POST_TERBANYAK,
    CARI_USER_POST_Y,
    N_ACTION
};

void setFilestream(ifstream &in, string filename);
void clearScreen();
void showMenu();
void askAction(int &action);
void askPostID(string &postID);
void askUserID(string &userID);
void postNotFound(string postID);
void userNotFound(string userID);
void mainLoop();
#endif
