#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

// User action enums goes here
enum action {
    EXIT = 0,
    ADD_NEW_PARENT,
    SHOW_ALL_PARENT,
    DELETE_PARENT,
    FIND_PARENT,
    ADD_CHILD_FIRST,
    CONNECT_PARENT_CHILD,
    SHOW_PARENT_CHILD,
    FIND_CHILD,
    DELETE_CHILD,
    COUNT_PARENT_CHILD,
    N_ACTION
};

void setFilestream(ifstream &in, string filename);
void clearScreen();
void showMenu();
void askAction(int &action);
#endif
