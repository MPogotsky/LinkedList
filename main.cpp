#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List<int> lst;

    for(int i = 0; i < 10; i++){
        lst.push_back(rand()%100);
    }

    cout << "List: " << endl;
    lst.showList();
    cout << "List size: " <<lst.getSize() << endl;

    cout << endl <<"Operator overloading <lst[2]>: " << lst[2] << endl;

//    lst.push_front(5);
//    cout << endl << "List: " << endl;
//    lst.showList();
//    cout << "List size after push_front(5): " << lst.getSize() << endl;
//
//    lst.pop_back();
//    cout << endl << "List after pop_back(): " << endl;
//    lst.showList();
//    cout << "List size after pop_front(): " << lst.getSize() << endl;
//
//    lst.pop_front();
//    cout << endl << "List: " << endl;
//    lst.showList();
//    cout << "List size after pop_front(): " << lst.getSize() << endl;

    lst.insert(999,5);
    lst.insert(999,0);
    cout << endl << "List after insert() <999 at 5 & 0 pos> " << endl;
    lst.showList();
    cout << "List size after insert(): " << lst.getSize() << endl;

    lst.erase_at(5);
    cout << endl << "List after erase_at() <pos 5> " << endl;
    lst.showList();
    cout << "List size after erase_at(): " << lst.getSize() << endl;

    return 0;
}
