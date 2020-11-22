#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List<int> lst;

    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(22);
    lst.showList();
    cout << "Size: " <<lst.getSize() << endl;

    return 0;
}
