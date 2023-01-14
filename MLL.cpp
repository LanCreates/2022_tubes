#include "MLL.h"

// Fungsionalitas dasar
adrParent createParent(parentInfo pInfo) {
    adrParent p = new Parent;
    info(p) = pInfo;
    child(p) = NULL;
    next(p) = NULL;
    return p;
}

adrChild createChild(childInfo cInfo) {
    adrChild c = new Child;
    info(c) = cInfo;
    next(c) = NULL;
    return c;
}

void createParentList(listParent &P) {
    first(P) = NULL;
}

void createChildList(listChild &C) {
    first(C) = NULL;
}

void addParentFirst(listParent &P, adrParent p) {
    if(first(P) == NULL) {
        next(p) = p;
    } else {
        adrParent q;
        next(p) = first(P);
        q = first(P);
        while(next(q) != first(P)) {
            q = next(q);
        }
        next(q) = p;
    }
    first(P) = p;
}

void addParentLast(listParent &P, adrParent p) {
    if(first(P) == NULL) {
        first(P) = p;
    } else {
        adrParent q = first(P);
        while(next(q) != first(P)) {
            q = next(q);
        }
        next(q) = p;
    }
    next(p) = first(P);
}

void addParentAfter(listParent &P, adrParent p, adrParent q) {
    if(next(q) == first(P)) { // Jika elemen terakhir
        next(p) = first(P);
    } else {
        next(p) = next(q);
    }
    next(q) = p;
}

adrParent deleteParentFirst(listParent &P) {
    adrParent deleted = first(P);
    if(next(first(P)) == first(P)) {
        first(P) = NULL;
    } else {
        adrParent q = first(P);
        while(next(q) != first(P)) {
            q = next(q);
        }
        first(P) = next(deleted);
        next(q) = next(deleted);
    }
    next(deleted) = NULL;
    return deleted;
}

adrParent deleteParentLast(listParent &P) {
    adrParent deleted;
    if(next(first(P)) == first(P)) { // 1 elemen
        deleted = first(P);
        first(P) = NULL;
    } else {
        adrParent p = first(P);
        while(next(next(p)) != first(P)) {
            p = next(p);
        }
        deleted = next(p);
        next(p) = first(P);
    }
    next(deleted) = NULL;
    return deleted;
}

adrParent deleteParentAfter(listParent &P, adrParent p) {
    adrParent deleted = NULL;
    if(next(p) != first(P)) { // Tak bisa menghapus setelah elemen akhir (meski circular)
        deleted = next(p);
        next(p) = next(deleted);
        next(deleted) = NULL;
    }
    return deleted;
}

adrParent findParent(listParent P, string IDParent) {
    adrParent p = first(P);
    bool hadLooped = false;
    if(first(P) != NULL) {
        do {
            if(info(p).postID == IDParent) {
                return p;
            }
            p = next(p);
            hadLooped = p == first(P);
        } while(!hadLooped);
        
        // last element
        if(info(p).postID == IDParent) {
            return p;
        }
    }
    return NULL;
}

adrParent findParentOfChild(listParent P, adrChild c, string IDParent) {
    if(first(P) != NULL) {
        adrParent p = first(P);
        bool loopedOnce = false;
        while(!loopedOnce) {
            if(info(p).postID == IDParent && child(p) == c) {
                return p;
            }
            p = next(p);
            loopedOnce = (p == first(P));
        }
    }
    return NULL;
}

void addChildFirst(listChild &C, adrChild c) {
    next(c) = first(C);
    first(C) = c;
}

void addChildLast(listChild &C, adrChild c) {
    if(first(C) == NULL) {
        first(C) = c;
    } else {
        adrChild d = first(C);
        while(next(d) != NULL) {
            d = next(d);
        }
        next(d) = c;
    }
}

void addChildAfter(listChild &C, adrChild c, adrChild d) {
    if(next(d) != NULL) { // Jika bukan elemen terakhir
        next(c) = next(d);
    }
    next(d) = c;
}

adrChild deleteChildFirst(listParent &P, listChild &C) {
    adrChild deleted = first(C);

    adrParent parentDeleted = first(P);
    while(next(parentDeleted) != first(P) && child(parentDeleted) != deleted) {
        parentDeleted = next(parentDeleted);
    }
    if(parentDeleted != NULL) { deleteRelasi(parentDeleted); }

    first(C) = next(first(C));
    next(deleted) = NULL;
    return deleted;
}

adrChild deleteChildLast(listParent &P, listChild &C) {
    adrChild prevDeleted, deleted = first(C);
    while(next(deleted) != NULL) {
        prevDeleted = deleted;
        deleted = next(deleted);
    }

    adrParent parentDeleted = first(P);
    while(next(parentDeleted) != first(P) && child(parentDeleted) != deleted) {
        parentDeleted = next(parentDeleted);
    }
    if(parentDeleted != NULL) { deleteRelasi(parentDeleted); }

    next(prevDeleted) = NULL;
    next(deleted) = NULL;
    return deleted;
}

adrChild deleteChildAfter(listParent &P, adrChild &c) {
    adrChild deleted = next(c);
    if(deleted != NULL) { // Bukan elemen akhir
        next(c) = next(next(c));
        adrParent parentDeleted = first(P);
        while(next(parentDeleted) != first(P) && child(parentDeleted) != deleted) {
            parentDeleted = next(parentDeleted);
        }
        if(parentDeleted != NULL) { deleteRelasi(parentDeleted); }
    }
    return deleted;
}

adrChild findChild(listChild C, string IDChild) {
    if(first(C) != NULL) {
        adrChild c = first(C);
        while(c != NULL) {
            if(info(c).userID == IDChild) {
                return c;
            }
            c = next(c);
        }
    }
    return NULL;
}

// Fungsionalitas lainnya
void addParent(listParent &P, adrParent p) {
    string parentID;
    int option;
    showMethod();
    askInput(option);
    
    adrParent temp;
    switch(option % 3) {
        case 0:
            addParentFirst(P, p);
            break;
        case 1:
            cout << "Masukkan ID parent sebelum parent baru: "; cin >> parentID;
            temp = findParent(P, parentID);
            if(temp != NULL) {
                addParentAfter(P, p, temp);
            } else {
                cout << "Parent tersebut tak ditemukan! Silakan ulangi input" << endl;
                delete p;
            }
            break;
        case 2:
            addParentLast(P, p);
            break;
    }
}

void printParentInfo(adrParent p) {
    cout << "=============== "
        << "\npostID\t" << "tanggal\t\n"
        << info(p).postID << "\t"
        << info(p).tanggal << "\t"
        << "\n=b " << info(p).like << " orang menyukai ini"
        << "\n[+] Dibuat oleh @";

    if(child(p) != NULL) { cout << info(child(p)).username;
    } else { cout << "anonymous";
    }

    cout << "\n===== Isi ===== \n" << info(p).isi << endl << endl;
}

void addChild(listChild &C, adrChild c) {
    string childID;
    int option;
    showMethod();
    askInput(option);
    
    adrChild temp;
    switch(option % 3) {
        case 0:
            addChildFirst(C, c);
            break;
        case 1:
            cout << "Masukkan ID dari child sebelum child baru: ";
            cin >> childID;
            temp = findChild(C, childID);
            if(temp != NULL) {
                addChildAfter(C, c, temp);
            } else {
                cout << "Child tersebut tak ditemukan! "
                     << "Silakan ulangi input!" 
                     << endl;
                delete c;
            }
            break;
        case 2:
            addChildLast(C, c);
            break;
    }
}

adrChild deleteChild(listParent &P, listChild &C, string IDChild) {
    adrChild d;
    if(first(C) != NULL) {
        cout << "Masukkan id child yang ingin dihapus: ";
        cin >> IDChild;
        adrChild c = findChild(C, IDChild);
        if(c != NULL) {
            if(first(C) == c) {
                d = deleteChildFirst(P, C);
            } else {
                c = first(C);
                while(next(c) != NULL && info(next(c)).userID != IDChild) {
                    c = next(c);
                }

                if(c != NULL) {
                    if(next(c) == NULL) {
                        d = deleteChildLast(P, C);
                    } else {
                        d = deleteChildAfter(P, c);
                    }
                }
            }
        } else {
            cout << "Child tersebut tak ditemukan! "
                << "Pengahapusan dibatalkan" 
                << endl;
        }
    }
    return d;
}

void printChildInfo(adrChild c) {
    cout << "userID\t: " << info(c).userID
        << "\nusername: "<< info(c).username
        << "\nasal\t: "<< info(c).asal
        << endl << endl;
}

void showAllParent(listParent P) {
    adrParent p = first(P);
    if(p == NULL) {
        cout << "List kosong!" << endl;
    } else {
        printParentInfo(p);
        while(next(p) != first(P)) {
            p = next(p);
            printParentInfo(p);
        }
    }
}

void showAllChild(listChild C) {
    adrChild c;
    if(first(C) == NULL) {
        cout << "List kosong!" << endl;
    } else {
        c = first(C);
        while(c != NULL) {
            printChildInfo(c);
            c = next(c);
        }
    }
}

void showAllParentChild(listParent P, listChild C) {
    adrParent p = first(P);
    if(p == NULL) {
        cout << "List kosong!" << endl;
    } else {
        while(next(p) != first(P)) {
            if(child(p) != NULL) { // Yang tak ada child tak akan muncul
                cout << "postID |\t" << " tanggal\t"<< endl;
                cout << "Oleh: " << info(child(p)).username << endl;
                cout << info(p).postID << " |\t "
                    << info(p).tanggal << "\t"
                    << "\n===== Isi ===== \n" << info(p).isi 
                    << endl << endl;
            }
            p = next(p);
        }
    }
}

void showUserData(listParent P, adrChild c) {
    if(c != NULL && first(P) != NULL) {
        printChildInfo(c);
        cout << "Daftar Post yang dibuat =====\n";

        adrParent p = first(P);
        while(next(p) != first(P)) {
            if(child(p) == c) {
                printParentInfo(p);
            }
            p = next(p);
        }
    }
}

void showAllPostFromUser(listParent P, string IDChild) { // Nama sebelumnya: ShowAllPost
    cout << "Post dari user dengan ID: " << IDChild << endl;
    if(first(P) != NULL) {
        adrParent p = first(P);
        int post_no = 1;
        bool looped_once = false;
        while(!looped_once) {
            if(child(p) != NULL && info(child(p)).userID == IDChild) {
                printf("[%d] ", post_no);
                cout << string(25, '-') << endl;
                printParentInfo(p);
                post_no++;
            }
            p = next(p);
            looped_once = p == first(P);
        }
    }
}

void addRelasi(adrParent p, adrChild c) {
    if(p != NULL && c != NULL) {
        child(p) = c;
    }
}


void deleteRelasi(adrParent p) {
    if(p != NULL) {
        child(p) = NULL;
    }
}

void cariUserDariPost(listParent P, listChild C, string IDParent) {
    adrParent p = findParent(P, IDParent);
    if(p == NULL) {
        cout << "Post ini tidak ada di dalam list tersebut" << endl;
    } else if(first(P) != NULL && first(C) != NULL) {
        adrChild c = first(C);
        while(c != NULL && child(p) != c) {
            c = next(c);
        }

        if(c != NULL) {
            printChildInfo(c);
        } else {
            cout << "Tidak ditemukan pembuat dari post ini! "
                << "Coba perhatikan data relasi!"
                << endl;
        }
    }
}

void showMax(listParent P, listChild C) {
    int max_post = 0;
    adrChild max_user = first(C);
    
    if(first(C) != NULL) {
        adrChild c = first(C);
        while(c != NULL) {
            int n_post = 0;
            adrParent p = first(P);
            bool loopedOnce = false;
            while(!loopedOnce) {
                if(child(p) == c) {
                    n_post++;
                }
                p = next(p);
                loopedOnce = (p == first(P));
            }
            if(max_post < n_post) {
                max_post = n_post;
                max_user = c;
            }
            c = next(c);
        }
        
        printf("Profil ini membuat post terbanyak (%d post)\n", max_post);
        printChildInfo(max_user);
        showAllPostFromUser(P, info(max_user).userID);
    } else {
        cout << "Tidak ada data pengguna";
    }
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
        << "\nBanyak Child : " << n_child << endl;
}

// Out of Topic
void showMethod() {
    cout << "Pilihan hapus/tambah data:\n[0] first\t[1] after x\t[2]last\n"
        << "Masukkan pilihan: ";
}

void askInput(int &input) {
    cin >> input;
}
