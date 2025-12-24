#ifndef PENJUALAN_H
#define PENJUALAN_H

#include <iostream>
using namespace std;

struct Parent {
    int id;
    string nama;
    int omzet;
    Parent* next;
};

struct Child {
    int id;
    string nama;
    Child* next;
};

struct Relasi {
    Parent* parent;
    Child* child;
    Relasi* next;
};

struct ListParent {
    Parent* first;
};

struct ListChild {
    Child* first;
};

struct ListRelasi {
    Relasi* first;
};

void init(ListParent &LP, ListChild &LC, ListRelasi &LR);

void insertParentFirst(ListParent &LP);
void insertParentLast(ListParent &LP);
void deleteParent(ListParent &LP, ListRelasi &LR, int id);
Parent* findParent(ListParent LP, int id);
void showParent(ListParent LP);

void insertChildLast(ListChild &LC);
void deleteChild(ListChild &LC, ListRelasi &LR, int id);
Child* findChild(ListChild LC, int id);

void connectParentChild(ListRelasi &LR, Parent* p, Child* c);
void showAllRelation(ListParent LP, ListRelasi LR);
void showChildFromParent(ListRelasi LR, int idParent);
void deleteChildFromParent(ListRelasi &LR, int idParent, int idChild);
int countChildFromParent(ListRelasi LR, int idParent);

#endif