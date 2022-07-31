#include "../headerfiles/structs.hpp"


LL_Node* createLLNode
        (
            int val
        )
    {
        LL_Node *newNode = ( LL_Node* )malloc( sizeof( LL_Node ) );
        newNode -> nextPtr = NULL;
        newNode -> val = val;
        return newNode;
    }

/*
BST_Node* createBSTNode
        (
            int value
        )
    {
        BST_Node *newNode = ( BST_Node* )malloc( sizeof( BST_Node ) );
        newNode -> leftChild = NULL;
        newNode -> rightChild = NULL;
        newNode -> val = value;
        return newNode;
    }
*/
/*
================================================================================
                            LinkedStack
================================================================================
*/
LinkedStack::LinkedStack
        (

        )
    : head( NULL )
    {

    }

LinkedStack::~LinkedStack
        (

        )
    {
        LL_Node *wkgPtr = head;
        LL_Node *tmpPtr = wkgPtr;

        if( wkgPtr != NULL )
        {
            while( wkgPtr != NULL )
            {
                tmpPtr = wkgPtr;
                wkgPtr = wkgPtr -> nextPtr;
                delete tmpPtr;
            }
        }
        else
        {
            delete tmpPtr;
        }

        head = NULL;
    }

bool LinkedStack::isEmpty
        (

        )
    {
        return head == NULL;
    }

void LinkedStack::push
        (
            int val
        )
    {
        LL_Node *newNode = createLLNode( val );
        LL_Node *wkgPtr = head;

        if( this->isEmpty() )
        {
            head = newNode;
        }
        else
        {
            while( wkgPtr -> nextPtr != NULL )
            {
                wkgPtr = wkgPtr -> nextPtr;
            }

            wkgPtr -> nextPtr = newNode;
        }
    }

// Size not zero based. Tells real number of values
int LinkedStack::size
        (

        )
    {
        if( head == NULL )
        {
            return 0;
        }

        LL_Node *wkgPtr = head;
        int size = 1;
        while( wkgPtr -> nextPtr != NULL )
        {
            size++;
            wkgPtr = wkgPtr -> nextPtr;
        }

        return size;
    }

LL_Node* LinkedStack::pop
        (

        )
    {
        LL_Node *wkgPtr = head, *tmpPtr = NULL;
        LL_Node *returnNode = NULL;

        if( this->isEmpty() )
        {
            cout << "Linked Stack is empty" << endl;
        }
        else if( head -> nextPtr == NULL )
        {
            returnNode = createLLNode( head->val );
            delete head;
            head = NULL;
        }
        else
        {
            while( wkgPtr -> nextPtr -> nextPtr != NULL )
            {
                wkgPtr = wkgPtr -> nextPtr;
            }

            tmpPtr = wkgPtr -> nextPtr;
            returnNode = createLLNode( tmpPtr -> val );
            delete  tmpPtr;
            wkgPtr -> nextPtr = NULL;
        }

        return returnNode;
    }

void LinkedStack::printStack
        (

        )
    {
        LL_Node *wkgPtr = head;

        if( this->isEmpty() )
        {
            cout << "Linked Stack is empty" << endl;
        }
        else
        {
            while( wkgPtr != NULL )
            {
                cout << wkgPtr -> val;
                cout << " -> ";
                wkgPtr = wkgPtr -> nextPtr;
            }

            cout << "NULL" << endl;
        }
    }

void LinkedStack::peekTop
        (

        )
    {
        LL_Node *wkgPtr;

        if( this->isEmpty() )
        {
            cout << "Linked Stack is empty" << endl;
        }
        else
        {
            wkgPtr = head;
            while( wkgPtr -> nextPtr != NULL )
            {
                wkgPtr = wkgPtr -> nextPtr;
            }

            cout << "Stack Top: " << wkgPtr -> val << endl;
        }
    }

/*
================================================================================
                                Array Stack
================================================================================
*/

LinkedQueue::LinkedQueue
        (

        )
    : head( NULL )
    {

    }

LinkedQueue::~LinkedQueue
        (

        )
    {
        LL_Node *wkgPtr = head;
        LL_Node *tmpPtr = wkgPtr;

        if( !this->isEmpty() )
        {
            while( wkgPtr != NULL )
            {
                tmpPtr = wkgPtr;
                wkgPtr = wkgPtr -> nextPtr;
                delete tmpPtr;
            }
        }
        else
        {
            delete tmpPtr;
        }

        head = NULL;
    }

int LinkedQueue::size
        (

        )
    {
        if( head == NULL )
        {
            return 0;
        }

        LL_Node *wkgPtr = head;
        int size = 1;
        while( wkgPtr -> nextPtr != NULL )
        {
            size++;
            wkgPtr = wkgPtr -> nextPtr;
        }

        return size; 
    }

void LinkedQueue::printQueue
        (

        )
    {
        LL_Node *wkgPtr = head;

        if( !this->isEmpty() )
        {
            cout << "Front of queue -> ";
            while( wkgPtr != NULL )
            {
                cout << wkgPtr -> val;
                if( wkgPtr -> nextPtr != NULL )
                {
                    cout << ", ";
                }
                wkgPtr = wkgPtr -> nextPtr;
            }
            cout << " <- Back of queue" << endl;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
    }

void LinkedQueue::peekFront
        (

        )
    {
        if( !this->isEmpty() )
        {
            cout << "Front: " << this->head->val << endl;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
    }


bool LinkedQueue::isEmpty
        (

        )
    {
        return head == NULL;
    }

void LinkedQueue::enqueue
        (
            int val
        )
    {
        LL_Node *wkgPtr = head;
        LL_Node *newNode = createLLNode( val );

        if( this->isEmpty() )
        {
            head = newNode;
        }
        else
        {
            while( wkgPtr -> nextPtr != NULL )
            {
                wkgPtr = wkgPtr -> nextPtr;
            }

            wkgPtr -> nextPtr = newNode;
        }
    }

LL_Node* LinkedQueue::dequeue
        (

        )
    {
        LL_Node *tmpPtr = NULL;
        if( this->isEmpty() )
        {
            cout << "Queue is empty" << endl;
        }
        else if( head -> nextPtr == NULL )
        {
            cout << "Queue is empty" << endl;
            head = NULL;
        }
        else
        {
            tmpPtr = head;
            head = head -> nextPtr;
        }
        return tmpPtr;
    }

/*
================================================================================
                             Array Stack
================================================================================
*/


ArrayStack::ArrayStack
        (

        )
    : capacity( DEFAULT_CAPACITY ), size( 0 )
    {
        stack = new int[ DEFAULT_CAPACITY ];
    }

ArrayStack::ArrayStack
        (
            int stackSize
        )
        : size( stackSize )
    {

    }

ArrayStack::~ArrayStack
        (

        )
    {
        delete[] stack;
    }

ArrayStack::ArrayStack
        (
            ArrayStack &Stack
        )
    {
        size = Stack.size;
        capacity = Stack.capacity;
        
        if( !this->isEmpty() )
        {
            for( int index; index < size; index++ )
            {
                stack[ index ] = Stack.stack[ index ];
            }
        }
    }

int ArrayStack::stackSize
        (

        )
    {
        return size;
    }

bool ArrayStack::isEmpty
        (

        )
    {
        return size == 0;
    }


void ArrayStack::push
        (
          int val   
        )
    {
        stack[ size ] = val;
        size++;
    }

int ArrayStack::pop
        (

        )
    {
        int returnValue = 0;
        if( !this->isEmpty() )
        {
            returnValue = stack[ size - 1 ];
            size--;
        }
        else
        {
            cout << "Stack is empty\n";
        }
        return returnValue;
    }

void ArrayStack::peekTop
        (

        )
    {
        if( !this->isEmpty()  )
        {
            cout << "Top: ";
            cout << stack[ size - 1 ];
            cout << "\n";
        }
        else
        {
            cout << "Stack is empty\n";
        }
    }

void ArrayStack::resizeStack
        (

        )
    {
        int index;
        if( size == capacity )
        {
            int newCapacity = capacity * 2;
            int *newStack = ( int* )malloc( newCapacity * sizeof( int ) );
            for( index = 0; index < capacity; index++ )
            {
                newStack[ index ] = stack[ index ];
            }
            capacity = newCapacity;
            stack = newStack;
        }
    }

void ArrayStack::printStack
        (

        )
    {
        int index;

        if( !this->isEmpty() )
        {
            cout << "[ ";
            for( index = 0; index < size; index++ )
            {
                cout << stack[ index ];
                if( index != size - 1 )
                {
                    cout << ", ";
                }
            }

            cout << " ]";
            cout << "\n";
        }
        else
        {
            cout << "Stack is Empty\n";
        }
    }

/*
================================================================================
                            Linked List
================================================================================
*/

LinkedList::LinkedList
        (

        )
    : head( NULL )
    {

    }

LinkedList::~LinkedList
        (

        )
    {
        LL_Node *wkgPtr = head;
        LL_Node *tmpPtr = wkgPtr;

        if( !this->isEmpty() )
        {
            while( wkgPtr != NULL )
            {
                tmpPtr = wkgPtr;
                wkgPtr = wkgPtr -> nextPtr;
                delete tmpPtr;
            }
        }
        else
        {
            delete tmpPtr;
        }

        head = NULL;
    }

bool LinkedList::isEmpty
        (

        )
    {
        return head == NULL;
    }

void LinkedList::printLinkedList
        (

        )
    {
        if( this->isEmpty() )
        {
            cout << "Linked list is empty" << endl;
        }
        else
        {
            LL_Node *wkgPtr = head;
            while( wkgPtr != NULL )
            {
                cout << wkgPtr->val;
                cout << " -> ";
                wkgPtr = wkgPtr -> nextPtr;
            }

            cout << "NULL" << endl;
        }
    }

void LinkedList::appendNode
        (
            int val
        )
    {
        LL_Node *wkgPtr = head;
        LL_Node *newNode = createLLNode( val );

        if( this->isEmpty() )
        {
            head = newNode;
        }
        else
        {
            while( wkgPtr -> nextPtr != NULL )
            {
                wkgPtr = wkgPtr -> nextPtr;
            }

            wkgPtr -> nextPtr = newNode;
        }
    }

int LinkedList::linkedListSize
        (

        )
    {
        if( head == NULL )
        {
            return 0;
        }

        LL_Node *wkgPtr = head;
        int size = 1;
        while( wkgPtr -> nextPtr != NULL )
        {
            wkgPtr = wkgPtr -> nextPtr;
            size++;
        }

        return size;
    }

LL_Node* LinkedList::removeNthNode
        (
            int n
        )
    {
        LL_Node *tmpPtr;
        LL_Node *returnNode = NULL;
        // Not zero based here for size
        int listSize = this->linkedListSize() - 1;

        if( this->isEmpty() )
        {
            cout << "Linked list is empty";
        }
        else
        {
            if( n == 0 )
            {
                if( head -> nextPtr != NULL )
                {
                    tmpPtr = head;
                    head = head -> nextPtr;
                    delete tmpPtr;
                }
                else
                {
                    delete head;
                    head = NULL;
                }
                return createLLNode( head->val );
            }
            else
            {
                if( n > listSize || n < 0 )
                {
                    cout << "N is not within the bounds of the linked list" << endl;
                }
                else
                {
                    LL_Node *wkgPtr = head;
                    int index = 0;
                    while( index < n - 1 )
                    {
                        wkgPtr = wkgPtr -> nextPtr;
                        index++;
                    }
                    
                    tmpPtr = wkgPtr->nextPtr;

                    if( wkgPtr -> nextPtr -> nextPtr != NULL )
                    {
                        wkgPtr -> nextPtr = wkgPtr -> nextPtr -> nextPtr;
                    }
                    else
                    {
                        wkgPtr -> nextPtr = NULL;
                    }

                    delete tmpPtr;
                    return createLLNode( wkgPtr -> val );
                }
            }
        }
        return returnNode;
    }

LL_Node* LinkedList::removeNodeValue
        (
            int value
        )
    {
        LL_Node *returnNode = NULL;
        LL_Node *tmpPtr = NULL;

        if( this->isEmpty() )
        {
            cout << "Linked list is empty" << endl;
        }
        else
        {
            if( head -> val == value )
            {
                if( head -> nextPtr != NULL )
                {
                    tmpPtr = head;
                    head = head -> nextPtr;
                    delete tmpPtr;
                }
                else
                {
                    delete head;
                    head = NULL;
                }

                return createLLNode( head -> val );
            }
            LL_Node *wkgPtr = head;
            while( wkgPtr != NULL )
            {
                if( wkgPtr -> val == value )
                {
                    if( wkgPtr -> nextPtr != NULL )
                    {
                        tmpPtr = wkgPtr;
                        wkgPtr = wkgPtr -> nextPtr;
                        delete tmpPtr;
                    }
                    else
                    {
                        delete wkgPtr;
                        wkgPtr = NULL;
                    }
                    return createLLNode( wkgPtr -> val );
                }
                wkgPtr = wkgPtr -> nextPtr;
            }
            cout << "Node with that value not found" << endl;
        }
        return returnNode;
    }

// FIX THIS
LL_Node* LinkedList::sort
        (

        )
    {
        LL_Node *returnList = NULL;
        if( this->isEmpty() )
        {
            cout << "Cannot sort an empty list" << endl;
        }
        else
        {
            int listSize = this -> linkedListSize();
            int *linkedListValues = ( int* )malloc( sizeof( int ) * listSize - 1 );
            LL_Node *wkgPtr = head;
            int tempValue;

            for( int index = 0; index < listSize; index++ )
            {
                linkedListValues[ index ] = wkgPtr -> val;
                wkgPtr = wkgPtr -> nextPtr;
            }

            // N^2 bubble sort
            for( int index = 0; index < listSize; index++ )
            {
                for( int probeIndex = 0; probeIndex < listSize - index; probeIndex++ )
                {
                    if( linkedListValues[ probeIndex ] >= linkedListValues[ probeIndex + 1 ] )
                    {
                        tempValue = linkedListValues[ probeIndex ];
                        linkedListValues[ probeIndex ] = linkedListValues[ probeIndex + 1 ];
                        linkedListValues[ probeIndex + 1 ] = tempValue;
                    }
                }
            }

            LL_Node *tempHead;
            for( int index = 0; index < listSize; index++ )
            {
                if( returnList == NULL )
                {
                    returnList = createLLNode( linkedListValues[ index ] );
                    tempHead = returnList -> nextPtr;
                }
                else
                {
                    tempHead = createLLNode( linkedListValues[ index ] );
                    tempHead = tempHead -> nextPtr;
                }
            }
            delete linkedListValues;
            return returnList;
        }
        
        return returnList;
    }