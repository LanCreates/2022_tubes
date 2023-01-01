#include "app.h"
#include "MLL.h"

int main() {
    // Whole list is here
    listParent L1;
    listChild L2;

    // Setup for reading input
    ifstream inParent, inChild;
    setFilestream(inParent, "./inputParent.txt");
    setFilestream(inChild, "./inputChild.txt");
    

    // Insert default parent and child data
    if(inParent.good()) {
        parentInfo temp;
        while(!inParent.eof()) {
            inParent >> temp.nama >> temp.username >> temp.asal;
            addParentFirst(L1, createParent(temp));
        }
    }

    if(inChild.good()) {
        childInfo temp;
        while(!inChild.eof()) {
            inChild >> temp.tanggal >> temp.isi >> temp.like;
            addChildFirst(L2, createChild(temp));
        }
    }

    // Main menu goes here
    int userChoice = 0;
    do {
        clearScreen();
        showMenu();
        askAction(userChoice);

        // Do action
        parentInfo tempPInfo;
        childInfo tempCInfo;
        clearScreen();
        switch(userChoice % N_ACTION) {
            case ADD_NEW_PARENT:
                addParentFirst(L1, createParent(tempPInfo));
                break;
            case SHOW_ALL_PARENT:
                showAllParent(L1);
                break;
            case DELETE_PARENT:
                deleteParent(L1, tempPInfo);
                break;
            case FIND_PARENT:
                findParent(L1, tempPInfo);
                break;
            case ADD_CHILD_FIRST:
                addChildFirst(L2, createChild(tempCInfo));
                break;
            case CONNECT_PARENT_CHILD:
                connect(L1, L2, tempPInfo, tempCInfo);
                break;
            case SHOW_PARENT_CHILD:
                showAllParentChild(L1, L2);
                break;
            case FIND_CHILD:
                break;
            case DELETE_CHILD:
                deleteChild(L1, L2, tempCInfo);
                break;
            case COUNT_PARENT_CHILD:
                countParentChild(L1, L2);
                break;
        }
    } while(userChoice != EXIT);

    clearScreen();
    cout << "PROGRAM HAS FINISHED!";
}
