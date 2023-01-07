#include "app.h"
#include "MLL.h"

int main() {
    // Whole list is here
    listParent L1; createParentList(L1);
    listChild L2; createChildList(L2);

    // Setup for reading input
    ifstream inParent, inChild;
    setFilestream(inParent, "./inputParent.txt");
    setFilestream(inChild, "./inputChild.txt");
    
    parentInfo PInfo;
    childInfo CInfo;

    // Insert default parent and child data
    if(inParent.good()) {
        while(inParent >> PInfo.postID) {
            inParent >> PInfo.like;
            getline(inParent >> ws, PInfo.tanggal);
            getline(inParent >> ws, PInfo.isi);
            addParentFirst(L1, createParent(PInfo));
        }
    }
    
    if(inChild.good()) {
        while(inChild >> CInfo.userID) {
            inChild >> CInfo.username >> CInfo.asal;
            addChildFirst(L2, createChild(CInfo));
        }
    }
  
    // Main menu goes here
    int userChoice = 0;
    do {
        clearScreen();
        showMenu();
        askAction(userChoice);

        // Do action
        string userID, postID;
        adrChild tempUser;
        adrParent tempPost;
        clearScreen();
        switch(userChoice % N_ACTION) {
            case TAMBAH_USER_BARU: cout << "MENU: Menambahkan user baru" << endl;
                cout << "Masukkan detail user" << endl;
                cout << "ID: "; cin >> CInfo.userID;
                cout << "username: "; cin >> CInfo.username;
                cout << "asal: "; cin >> CInfo.asal;
                addChild(L2, createChild(CInfo));
                break;
            case TAMPIL_USER_X: cout << "MENU: Menampilkan data user X" << endl;
                askUserID(userID);
                tempUser = findChild(L2, userID);
                if(tempUser != NULL) {
                    showUserData(L1, tempUser);
                } else {
                    userNotFound(userID);
                }
                break;
            case HAPUS_USER_X: cout << "MENU: Menghapus user X" << endl;
                if(first(L2) != NULL) { tempUser = deleteChild(L1, L2, userID); }
                break;
            case CARI_USER_X: cout << "MENU: Mencari user X" << endl;
                askUserID(userID);
                if(findChild(L2, userID) != NULL) {
                    cout << "Data user dengan ID " << userID << " ditemukan!" << endl;
                } else {
                    userNotFound(userID);
                }
                break;
            case TAMBAH_POST_USER_X: cout << "MENU: Menambah post baru oleh user X" << endl;
                askUserID(userID);
                tempUser = findChild(L2, userID);

                if(tempUser != NULL) {
                    cout << "Masukkan detail post" << endl;
                    cout << "ID: "; cin >> PInfo.postID;
                    cout << "tanggal post: "; getline(cin >> ws, PInfo.tanggal);
                    cout << "banyak like: "; cin >> PInfo.like;
                    cout << "isi: "; getline(cin >> ws, PInfo.isi);
                    tempPost = createParent(PInfo);
                    addRelasi(tempPost, tempUser);
                    addParent(L1, tempPost);
                } else {
                    userNotFound(userID);
                }
                break;
            case HAPUS_POST_USER_X: cout << "MENU: Menghapus post Y dari user X" << endl;
                if(first(L1) != NULL) {
                    askUserID(userID); tempUser = findChild(L2, userID);
                    askPostID(postID); tempPost = findParent(L1, postID);
                    if(tempUser != NULL && tempPost != NULL) {
                        if(first(L1) == tempPost) { 
                            tempPost = deleteParentFirst(L1);
                        } else {
                            tempPost = first(L1); // prev dari post dengan ID yang dimasukkan
                            while(next(tempPost) != first(L1) && info(next(tempPost)).postID != postID) {
                                tempPost = next(tempPost);
                            }

                            if(next(next(tempPost)) == first(L1)) {
                                tempPost = deleteParentLast(L1);
                            } else {
                                tempPost = deleteParentAfter(L1, tempPost);
                            }
                        }
                            deleteRelasi(tempPost);
                    } else {
                        if(tempUser == NULL) { userNotFound(userID);}
                        if(tempPost == NULL) { postNotFound(postID);}
                    }
                }
                break;
            case TAMPIL_POST_USER_X: cout << "MENU: Menampilkan seluruh post yang dibuat user X" << endl;
                askUserID(userID);
                if(findChild(L2, userID) != NULL) { showAllPostFromUser(L1, userID);
                } else { userNotFound(userID);
                }
                break;
            case CARI_POST_USER_X: cout << "MENU: Mencari post yang dibuat oleh user X" << endl;
                askUserID(userID); tempUser = findChild(L2, userID);
                askPostID(postID); tempPost = findParent(L1, postID);
                if(tempUser != NULL && tempPost != NULL && child(tempPost) != NULL) {
                    tempPost = findParentOfChild(L1, tempUser, postID);
                    if(tempPost != NULL) { 
                        printParentInfo(tempPost);
                    } else {
                        cout << "post ini tidak dibuat oleh user dengan ID: " << userID << endl;
                    }
                } else if(tempPost != NULL && child(tempPost) == NULL) {
                    cout << "Post ini dibuat oleh user anonymous!" << endl;
                } else {
                    if(tempUser == NULL) { userNotFound(userID); }
                    if(tempPost == NULL) { postNotFound(postID); }
                }
                break;
            case BUAT_RELASI_POST_KE_USER: cout << "MENU: Membuat Relasi post Y ke User X" << endl;
                askPostID(postID); tempPost = findParent(L1, postID);
                askUserID(userID); tempUser = findChild(L2, userID); 

                if(tempPost != NULL && tempUser != NULL) {
                    addRelasi(tempPost, tempUser);
                } else {
                    if(tempUser == NULL) { userNotFound(userID); }
                    if(tempPost == NULL) { postNotFound(postID); }
                }
                break;
            case HAPUS_RELASI_POST_KE_USER: cout << "MENU: Menghapus Relasi post Y ke User X" << endl;
                askPostID(postID); tempPost = findParent(L1, postID);

                if(tempPost != NULL) {
                    deleteRelasi(tempPost);
                } else {
                    postNotFound(postID);
                }
                break;
            case TAMPIL_USER_POST_TERBANYAK: cout << "MENU: Menampilkan data user pembuat post terbanyak" << endl;
                showMax(L1, L2);
                break;
            case CARI_USER_POST_Y: cout << "MENU: Cari dan menampilkan user yang membuat post Y" << endl;
                askPostID(postID);
                tempPost = findParent(L1, postID);
                if(tempPost != NULL) {
                    cariUserDariPost(L1, L2, postID);
                } else {
                    postNotFound(postID);
                }
                break;
            case TAMPIL_SEMUA_POST: cout << "MENU: Menampilkan seluruh data post" << endl;
                showAllParent(L1);
                break;
            case TAMPIL_SEMUA_USER: cout << "MENU: Menampilkan seluruh data user" << endl;
                showAllChild(L2);
                break;
        }
        if(userChoice != USER_EXIT) {
            cout << "Masukkan apa saja untuk melanjutkan: ";
            cin >> postID;
        }
    } while(userChoice != USER_EXIT);

    clearScreen();
    cout << "PROGRAM HAS FINISHED!";
}
