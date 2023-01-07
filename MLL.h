#ifndef LIST_H
#define LIST_H

// ========================
// L1 = post (single circular) => Parent
// L2 = user (single)
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

struct listParent {
    adrParent first;
};

struct listChild {
    adrChild first;
};

// Fungsionalitas dasar
adrParent createParent(parentInfo pInfo);
adrChild createChild(childInfo cInfo);
void createParentList(listParent &P);
void createChildList(listChild &C);
void addParentFirst(listParent &P, adrParent p); // Add p at first
void addParentLast(listParent &P, adrParent p); // Add p at last
void addParentAfter(listParent &P, adrParent p, adrParent q); // Add p after q
adrParent deleteParentFirst(listParent &P); // delete parent awal
adrParent deleteParentLast(listParent &P); // delete parent terakhir
adrParent deleteParentAfter(listParent &P, adrParent p); // delete parent setelah p
adrParent findParent(listParent P, string IDParent); // Mencari user dengan ID Tertentu
adrParent findParentOfChild(listParent P, adrChild c, string IDParent); // Sama seperti findChild, tapi pada parent tertentu
void addChildFirst(listChild &C, adrChild c); // add c at first
void addChildLast(listChild &C, adrChild c); // add c at last
void addChildAfter(listChild &C, adrChild c, adrChild d); // add c after d
adrChild deleteChildFirst(listParent &P, listChild &C); // delete parent akhir
adrChild deleteChildLast(listParent &P, listChild &C); // hapus child terakhir
adrChild deleteChildAfter(listParent &P, adrChild &c); // hapus child setelah c
adrChild findChild(listChild C, string IDChild); // Mencari post dengan ID tertentu

// Fungsionalitas lainnya
void addParent(listParent &P, adrParent p);
void printParentInfo(adrParent p);
void addChild(listChild &C, adrChild c);
adrChild deleteChild(listParent &P, listChild &C, string IDChild);
void printChildInfo(adrChild c);
void showAllParent(listParent P); // Menampilkan detail dari parent
void showAllParentChild(listParent P, listChild C); // Menampilkan semua parent dan child-nya
void showAllChild(listChild C); // Menampilkan detail dari parent

void showUserData(listParent P, adrChild c); // Menampilkan data user X
void showAllPostFromUser(listParent P, string IDChild); // Menampilkan semua post dari user X
void addRelasi(adrParent p, adrChild c); // Membuat relasi (Menghubungkan parent ke child)
void deleteRelasi(adrParent p); // Memutus relasi parent ke child, tapi parent tidak dihapus
void cariUserDariPost(listParent P, listChild C, string IDParent); // Cari nama user dari post tertentu
void showMax(listParent P, listChild C); // Menampilkan user dengan post terbanyak dan print semuanya
void countParentChild(listParent P, listChild C, string IDParent); // Menghitung banyaknya child dari parent tertentu

// Out of Topic
void showMethod();
void askInput(int &input);
#endif

/* [] -> Me
void addParentFirst(listParent &P, adrParent p); []
void showAllParent(listParent P); -> Parent kan circular, kondisinya kurang pas
adrParent deleteParent(listParent &P, string IDParent); [] 
adrParent findParent(listParent P, string IDParent); -> Parent kan circular, kondisinya kurang pas
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
