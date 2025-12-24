#include "penjualan.h"

void init(ListParent &LP, ListChild &LC, ListRelasi &LR) {
    LP.first = NULL;
    LC.first = NULL;
    LR.first = NULL;
}

void insertParentFirst(ListParent &LP) {
    Parent* p = new Parent;
    cout << "ID Parent: "; cin >> p->id;
    cin.ignore();
    cout << "Nama      : "; getline(cin, p->nama);
    cout << "Omzet     : "; cin >> p->omzet;

    p->next = LP.first;
    LP.first = p;
}

void insertParentLast(ListParent &LP) {
    Parent* p = new Parent;
    cout << "ID Parent: "; cin >> p->id;
    cin.ignore();
    cout << "Nama      : "; getline(cin, p->nama);
    cout << "Omzet     : "; cin >> p->omzet;

    p->next = NULL;

    if (LP.first == NULL)
        LP.first = p;
    else {
        Parent* q = LP.first;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

Parent* findParent(ListParent LP, int id) {
    Parent* p = LP.first;
    while (p != NULL) {
        if (p->id == id)
            return p;
        p = p->next;
    }
    return NULL;
}

void showParent(ListParent LP) {
    Parent* p = LP.first;
    while (p != NULL) {
        cout << p->id << " | " << p->nama << " | " << p->omzet << endl;
        p = p->next;
    }
}

void deleteParent(ListParent &LP, ListRelasi &LR, int id) {
    // Hapus relasi
    Relasi *r = LR.first, *prevR = NULL;
    while (r != NULL) {
        if (r->parent->id == id) {
            Relasi* del = r;
            if (prevR == NULL)
                LR.first = r->next;
            else
                prevR->next = r->next;
            r = r->next;
            delete del;
        } else {
            prevR = r;
            r = r->next;
        }
    }

    // Hapus parent
    Parent *p = LP.first, *prev = NULL;
    while (p != NULL) {
        if (p->id == id) {
            if (prev == NULL)
                LP.first = p->next;
            else
                prev->next = p->next;
            delete p;
            return;
        }
        prev = p;
        p = p->next;
    }
}

/* =========================
   CHILD
========================= */
void insertChildLast(ListChild &LC) {
    Child* c = new Child;
    cout << "ID Child: "; cin >> c->id;
    cin.ignore();
    cout << "Nama     : "; getline(cin, c->nama);

    c->next = NULL;
    if (LC.first == NULL)
        LC.first = c;
    else {
        Child* p = LC.first;
        while (p->next != NULL)
            p = p->next;
        p->next = c;
    }
}

Child* findChild(ListChild LC, int id) {
    Child* c = LC.first;
    while (c != NULL) {
        if (c->id == id)
            return c;
        c = c->next;
    }
    return NULL;
}

void deleteChild(ListChild &LC, ListRelasi &LR, int id) {
    Relasi *r = LR.first, *prevR = NULL;
    while (r != NULL) {
        if (r->child->id == id) {
            Relasi* del = r;
            if (prevR == NULL)
                LR.first = r->next;
            else
                prevR->next = r->next;
            r = r->next;
            delete del;
        } else {
            prevR = r;
            r = r->next;
        }
    }

    Child *c = LC.first, *prev = NULL;
    while (c != NULL) {
        if (c->id == id) {
            if (prev == NULL)
                LC.first = c->next;
            else
                prev->next = c->next;
            delete c;
            return;
        }
        prev = c;
        c = c->next;
    }
}

void connectParentChild(ListRelasi &LR, Parent* p, Child* c) {
    Relasi* r = new Relasi;
    r->parent = p;
    r->child = c;
    r->next = LR.first;
    LR.first = r;
}

void showAllRelation(ListParent LP, ListRelasi LR) {
    Parent* p = LP.first;
    while (p != NULL) {
        cout << "\nParent: " << p->nama << endl;
        Relasi* r = LR.first;
        while (r != NULL) {
            if (r->parent == p)
                cout << " - " << r->child->nama << endl;
            r = r->next;
        }
        p = p->next;
    }
}

void showChildFromParent(ListRelasi LR, int idParent) {
    Relasi* r = LR.first;
    while (r != NULL) {
        if (r->parent->id == idParent)
            cout << r->child->nama << endl;
        r = r->next;
    }
}

void deleteChildFromParent(ListRelasi &LR, int idParent, int idChild) {
    Relasi *r = LR.first, *prev = NULL;
    while (r != NULL) {
        if (r->parent->id == idParent && r->child->id == idChild) {
            if (prev == NULL)
                LR.first = r->next;
            else
                prev->next = r->next;
            delete r;
            return;
        }
        prev = r;
        r = r->next;
    }
}

int countChildFromParent(ListRelasi LR, int idParent) {
    int count = 0;
    Relasi* r = LR.first;
    while (r != NULL) {
        if (r->parent->id == idParent)
            count++;
        r = r->next;
    }
    return count;
}