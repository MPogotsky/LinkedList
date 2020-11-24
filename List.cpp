
#include "List.h"

using namespace std;

template<typename T>
List<T>::List()
        :size(0), head(nullptr) {}

template<typename T>
List<T>::~List() {
    clear();
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
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

template<typename T>
T &List<T>::operator[](int index) const {

    int count = 0;
    Node<int> *current = this->head;

    while (current != nullptr) {
        if (count == index) {
            return current->value;
        } else {
            count++;
            current = current->next;
        }
    }
}

template<typename T>
void List<T>::pop_front() {

    Node <T> *tmp = this->head;

    head = head->next;
    delete tmp;
    size--;
}

template<typename T>
void List<T>::clear() {
    while (size) {
        pop_front();
    }
}

template<typename T>
void List<T>::pop_back() {

    Node <T> *current = this->head;

    //Searching for last element of the list
    while (current->next->next != nullptr) {
        current = current->next;
    }
    //Deletes last element
    delete current->next;
    //Assigns nuttptr to the next pointer of last element, because it is the last element of the list
    current->next = nullptr;
    size--;
}

template<typename T>
void List<T>::push_front(T data) {

    Node <T> *current = this->head;

    //Creates new node and making it pointer next to point to the previous head pointer
    head = new Node<T>(data);
    head->next = current;

    size++;
}

template<typename T>
void List<T>::insert(T data, int index) {
    //If it is beginning of the list we can simply use push_front method
    if (index == 0) {
        push_front(data);

        //If it is last element of the list we use push_front method
    } else if (index == (size - 1)) {
        push_back(data);

    } else {

        Node <T> *previous = this->head;
        int count;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->next;
            count++;
        }

        //Creating new node to replace it with previous one
        auto *newNode = new Node<T>(data, previous->next);
        //Changing pointer to the previous element of the list to point to the new one
        // in order not to loose pointer connection
        previous->next = newNode;

        size++;
    }
}

template<typename T>
void List<T>::erase_at(int index) {
    if (index == 0) {
        pop_front();

    } else if (index == (size - 1)) {
        pop_back();

    } else {

        Node <T> *current = this-> head;

        for(int i = 0; i < index-1; i++){
            current = current -> next;
        }

        //Creating tmp pointer to have pointer to node to delete
        Node <T> *toDelete = current ->next;
        //Making pointer to the previous element to point to an element through one
        current ->next = current ->next -> next;

        delete toDelete;
        size --;
    }

}


