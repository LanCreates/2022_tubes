#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

// Aliases
#define nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
typedef struct UserData parentInfo;
typedef struct Parent *adrParent;
typedef struct PostData childInfo;
typedef struct Child *adrChild;

// Structs
struct UserData {
    string nama, username, asal;
};

struct PostData {
    string tanggal, isi;
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
void addParentFirst(listParent &P, adrParent p);
void showAllParent(listParent P);
adrParent deleteParent(listParent &P, parentInfo pInfo);
adrParent findParent(listParent P, parentInfo pInfo);
void addChildFirst(listChild &P, adrChild c);
void connect(listParent &P, listChild C, parentInfo pInfo, childInfo cInfo);
void showAllParentChild(listParent P, listChild C);
adrChild findChild(listChild C, adrParent c);
adrChild deleteChild(listParent &P, listChild &C, childInfo cInfo);
void countParentChild(listParent P, listChild C);

// Utils (Pembantu)
adrParent createParent(parentInfo pInfo);
adrChild createChild(childInfo cInfo);

#endif
