#ifndef LIST_H
#define LIST_H

// ========================
// L1 = post (Single circular) => Parent
// L2 = user
// ========================

#include <iostream>
#include <string>
using namespace std;

// Aliases
#define nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define child(P) (P)->child
#define first(L) ((L).first)
typedef struct UserData childInfo;
typedef struct Parent *adrParent;
typedef struct PostData parentInfo;
typedef struct Child *adrChild;

// Structs
struct UserData {
    string userID, username, asal;
};

struct PostData {
    string postID, tanggal, isi;
    int like;
};

struct Parent {
    parentInfo info;
    adrChild child;
    adrParent next;
};

struct Child {
    childInfo info;
    adrChild next;
};

struct listParent { // Single Circular
    adrParent first;
};

struct listChild {
    adrChild first;
};

// Fungsionalitas (Wajib)
void addParentFirst(listParent &P, adrParent p); // Menambah user baru
void showAllParent(listParent P); // Menampilkan detail dari parent
adrParent deleteParent(listParent &P, string IDParent); // Menghapus user dengan ID tertentu
adrParent findParent(listParent P, string IDParent); // Mencari user dengan ID Tertentu
void addChildFirst(listChild &C, adrChild c); // Menambahkan post
void connect(listParent &P, listChild C, string IDParent, string IDChild); // Membuat relasi (Menghubungkan parent ke child)
void showAllParentChild(listParent P, listChild C); // Menampilkan semua parent dan child-nya
adrChild findChild(listChild C, string IDChild); // Mencari post dengan ID tertentu
adrParent findParentFromChild(listParent P, adrChild c, string IDChild); // Sama seperti findChild, tapi pada parent tertentu
adrChild deleteChild(listParent &P, listChild &C, string IDChild); // Menghapus post dari user x
void countParentChild(listParent P, listChild C, string IDParent); // Menghitung banyaknya child dari parent tertentu

// Tambahan
void showUserData(adrChild c); // Menampilkan data user X
void showAllPostFromUser(listParent P, string IDChild); // Menampilkan semua post dari user X
void hapusRelasi(listParent P, listChild C, string IDParent, string IDChild); // Memutus relasi parent ke child, tapi parent tidak dihapus
void showMax(listParent P, listChild C); // Menampilkan user dengan post terbanyak dan print semuanya
void cariUserDariPost(listParent P, listChild C, string IDParent); // Cari nama user dari post tertentu

// Utils (Pembantu)
adrParent createParent(parentInfo pInfo);
adrChild createChild(childInfo cInfo);

#endif

/* [] -> Me
void addParentFirst(listParent &P, adrParent p); []
void showAllParent(listParent P); 
adrParent deleteParent(listParent &P, string IDParent); [] 
adrParent findParent(listParent P, string IDParent); 
void addChildFirst(listChild &C, adrChild c); [] 
void connect(listParent &P, listChild C, string IDParent, string IDChild); [] 
void showAllParentChild(listParent P, listChild C);
adrChild findChild(listChild C, string IDChild); 
adrChild findChildFromParent(listChild C, adrParent p, string IDChild); []
adrChild deleteChild(listParent &P, listChild &C, string IDChild); 
void countParentChild(listParent P, listChild C, string IDParent); []
void showUserData(adrParent p);
void showAllPostFromUser(listChild C, adrParent p); []
void hapusRelasi(listParent P, listChild C, string IDParent, string IDChild); []
void showMax(listParent P, listChild C);
void cariUserDariPost(listParent P, listChild C);
*/
