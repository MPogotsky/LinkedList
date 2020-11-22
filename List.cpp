
#include "List.h"

using namespace std;

template<typename T>
List<T>::List()
        :size(0), head(nullptr) {}

template<typename T>
List<T>::~List() {

}

template<typename T>
void List<T>::push_back(T data) {
    //Check if list is empty. Empty when head of the list is pointing to NULL
    if (head == nullptr) {
        head = new Node<T>(data);
    }
        //If not, using while loop & pointer current to move through the list in order to find the
        // last element of the list(Pointer next of this element is NULL)
    else {
        Node <T> *current = this->head;

        while (current->next != nullptr) {
            current = current->next;
        }

        //After the last element is found, new node is created. It will be the last element from now.
        current->next = new Node<T>(data);
    }
    size++;
}

template<typename T>
void List<T>::showList() {

    Node <T> *current = this->head;

    while (current != nullptr) {
        cout << current -> value << endl;
        current = current -> next;
    }
}
