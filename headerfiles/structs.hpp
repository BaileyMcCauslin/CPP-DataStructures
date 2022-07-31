#ifndef STRUCTS_H
#define STRUCTS_H
#include <iostream>

using namespace std;

const int DEFAULT_CAPACITY = 10;

//Linked Node Struct
typedef struct LL_Node
{
    LL_Node *nextPtr;
    int val;
}LL_Node;

/*
//BST Node Struct
typedef struct BST_Node
{
    BST_Node *leftChild;
    BST_Node *rightChild;
    int val;
}BST_Node;
*/

LL_Node* createLLNode( int value );

//BST_Node* createBSTNode( int value );

class ArrayStack
{
    public:
        ArrayStack();
        ArrayStack( int stackSize );
        ArrayStack( ArrayStack &copiedStack );
        ~ArrayStack();
        void peekTop();
        bool isEmpty();
        void push( int value );
        int pop();
        void printStack();
        void resizeStack();
        int stackSize();
    private:
        int capacity;
        int size; 
        int *stack;
};

class LinkedStack
{
    public:
        LinkedStack();
        //LinkedStack( LL_Node &head );
        ~LinkedStack();
        bool isEmpty();
        void push( int value );
        LL_Node* pop();
        void peekTop();
        void printStack();
        int size();
    private:
        LL_Node *head;
};

class LinkedQueue
{
    public:
        LinkedQueue();
        ~LinkedQueue();
        //LinkedQueue( LL_Node &head );
        void printQueue();
        bool isEmpty();
        void enqueue( int value );
        LL_Node* dequeue();
        void peekFront();
        int size(); 
    private:
        LL_Node *head;
};

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        //LinkedList( LL_Node &head );
        void printLinkedList();
        bool isEmpty();
        LL_Node* sort();
        void appendNode( int val );
        LL_Node* removeNthNode( int n );
        LL_Node* removeNodeValue( int val );
        int linkedListSize();
    private:
        LL_Node *head;
};


#endif