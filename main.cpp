#include "penjualan.h"

int main() {
    ListParent LP;
    ListChild LC;
    ListRelasi LR;
    init(LP, LC, LR);

    int pilih, idP, idC;

    do {
        cout << "\n=== MENU M ke N ===\n";
        cout << "1. Insert Parent First\n";
        cout << "2. Insert Parent Last\n";
        cout << "3. Show Parent\n";
        cout << "4. Delete Parent\n";
        cout << "5. Insert Child\n";
        cout << "6. Connect Parent-Child\n";
        cout << "7. Show All Parent & Child\n";
        cout << "8. Show Child from Parent\n";
        cout << "9. Delete Child from Parent\n";
        cout << "10. Count Child from Parent\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
        case 1: insertParentFirst(LP); break;
        case 2: insertParentLast(LP); break;
        case 3: showParent(LP); break;
        case 4:
            cout << "ID Parent: "; cin >> idP;
            deleteParent(LP, LR, idP);
            break;
        case 5: insertChildLast(LC); break;
        case 6:
            cout << "ID Parent: "; cin >> idP;
            cout << "ID Child : "; cin >> idC;
            connectParentChild(LR,
                findParent(LP, idP),
                findChild(LC, idC));
            break;
        case 7: showAllRelation(LP, LR); break;
        case 8:
            cout << "ID Parent: "; cin >> idP;
            showChildFromParent(LR, idP);
            break;
        case 9:
            cout << "ID Parent: "; cin >> idP;
            cout << "ID Child : "; cin >> idC;
            deleteChildFromParent(LR, idP, idC);
            break;
        case 10:
            cout << "ID Parent: "; cin >> idP;
            cout << "Jumlah Child: "
                 << countChildFromParent(LR, idP) << endl;
        }
    } while (pilih != 0);

    return 0;
}