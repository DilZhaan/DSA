#include "header\linkList.h"

int main(){

    linkList<int> list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    list.print();
    list.printRev();

    list.removeByID(4);
    list.print();
    cout << list.search(3) << endl;
    list.printRev();
    return 0;
}