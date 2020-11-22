#ifndef LISTNODE_LIST_H
#define LISTNODE_LIST_H

template<typename T>
class List{
public:
    List();
    ~List();

    void push_back(T data);

    int getSize(){
        return size;
    }

    void showList();

private:

    template<typename Type>
    class Node{
    public:
        Node(const Type &val)
                :value(val), next(nullptr){};

        Node *next;
        Type value;

        ~Node(){};
    };

    int size;
    Node<T> *head;

};

#include "List.cpp"

#endif //LISTNODE_LIST_H
