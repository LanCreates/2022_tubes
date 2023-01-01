#include "MLL.h"

// Fungsionalitas (Wajib)
void addParentFirst(listParent &P, adrParent p) {

}

void showAllParent(listParent P) {

}

adrParent deleteParent(listParent &P, parentInfo pInfo) {

}

adrParent findParent(listParent P, parentInfo pInfo) {

}

void addChildFirst(listChild &P, adrChild c) {

}

void connect(listParent &P, listChild C, parentInfo pInfo, childInfo cInfo) {

}

void showAllParentChild(listParent P, listChild C) {

}

adrChild findChild(listChild C, adrParent c) {

}

adrChild deleteChild(listParent &P, listChild &C, childInfo cInfo) {

}

void countParentChild(listParent P, listChild C) {

}


// Utils (Pembantu)
adrParent createParent(parentInfo pInfo) {
    return new Parent{pInfo, NULL, NULL};
}

adrChild createChild(childInfo cInfo) {
    return new Child{cInfo, NULL};
}

