#include "MLL.h"

// (Me: Ganjil) 
// Fungsionalitas (Wajib) 
void addParentFirst(listParent &P, adrParent p) {
    if(first(P) != NULL) {
        adrParent q = first(P);
        while(next(q) != first(P)) {
            q = next(q);
        }
        next(q) = p;
        next(p) = first(P);
    } else {
        next(p) = p;
        first(P) = p;
    }
}

void showAllParent(listParent P) {
    if(first(P) != NULL) {
        adrParent q = first(P);
        while(next(q) != first(P)) {
            cout << "Post: " << info(q).postID << endl; 
            cout << "Diunggah pada: " << info(q).tanggal << endl;
            cout << info(q).isi << endl << endl;
            q = next(q);
        }
    }
}

adrParent deleteParent(listParent &P, string IDParent) {
    if(first(P) != NULL) {
        adrParent q = first(P);
        while(next(q) != first(P)) {
            if(info(q).postID == IDParent) {
                return q;
            }
            q = next(q);
        }
    }
    return NULL;
}

adrParent findParent(listParent P, string IDParent) {

}

void addChildFirst(listChild &C, adrChild c) {
    if(first(C) != NULL) {
        adrChild d = first(C);
        while(next(d) != NULL) {
            d = next(d);
        }
        next(d) = c;
    } else {
        first(C) = c;
    }
}

void connect(listParent &P, listChild C, string IDParent, string IDChild) {
    if(first(C) != NULL && first(P) != NULL) {
        adrParent p = findParent(P, IDParent);
        adrChild c = findChild(C, IDChild);
        if(c != NULL) {
            child(p) = c;
        }
    }
}

void showAllParentChild(listParent P, listChild C) {

}

adrChild findChild(listChild C, string IDChild) {
}

adrParent findParentFromChild(listParent P, adrChild c, string IDChild) {
    if(first(P) != NULL) {
        adrParent p = first(P);
        while(next(p) != first(P)) {
            if(child(p) == c && info(child(p)).userID == IDChild) {
                return p;
            }
            p = next(p);
        }
    }
    return NULL;
}

adrChild deleteChild(listParent &P, listChild &C, string IDChild) {

}

void countParentChild(listParent P, listChild C, string IDParent) {
    adrParent p = findParent(P, IDParent);
    int n_child = 0;
    if(p != NULL) {
        adrChild c = first(C);
        while(c != NULL) {
            n_child++;
            c = next(c);
        }
    }
    
    cout << "IDParent : " << IDParent 
        << "\nBanyak Child : " << n_child 
        << endl;
}

// Pembantu
void showUserData(adrChild c) {

}

void showAllPostFromUser(listParent P, string IDChild) { // Nama sebelumnya: ShowAllPost
    cout << "Post dari user dengan ID: " << IDChild << endl;
    if(first(P) != NULL) {
        adrParent p = first(P);
        int post_no = 1;
        while(next(p) != first(P)) {
            if(info(child(p)).userID == IDChild) {
                printf("[%d] ", post_no);
                cout << string(25, '-');
                cout << "postID: " << info(p).postID
                    << "\nDipost pada: " << info(p).tanggal
                    << "\nIsi\n" << info(p).isi
                    << endl;
                post_no++;
            }
            p = next(p);
        }
    }
}

void hapusRelasi(listParent P, listChild C, string IDParent, string IDChild) {
    if(first(C) != NULL && first(P) != NULL) {
        adrParent p = findParent(P, IDParent);
        adrChild c = findChild(C, IDChild);
        if(c != NULL) {
            child(p) = NULL;
        }
    }
}

void showMax(listParent P, listChild C) {

}

void cariUserDariPost(listParent P, listChild C, string IDParent) {

}


// Utils (Pembantu)
adrParent createParent(parentInfo pInfo) {
    return new Parent{pInfo, NULL, NULL};
}

adrChild createChild(childInfo cInfo) {
    return new Child{cInfo, NULL};
}

