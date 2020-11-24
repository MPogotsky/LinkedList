#ifndef LISTNODE_LIST_H
#define LISTNODE_LIST_H

template<typename T>
class List {
public:
    List();

    ~List();

    void pop_front();

    void pop_back();

    void push_back(T data);

    void push_front(T data);

    void clear();

    void insert(T data, int index);

    void erase_at(int index);

    void showList();

    int getSize() {
        return size;
    }

    T &operator[](int index) const;

private:

    template<typename Type>
    class Node {
    public:
        Node(const Type &val)
                : value(val), next(nullptr) {};

        Node *next;
        Type value;

        ~Node() {};
    };

    int size;

    //Pointer to the first element of the list
    Node<T> *head;

};

#include "List.cpp"

#endif //LISTNODE_LIST_H
