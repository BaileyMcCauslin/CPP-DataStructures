#include "../headerfiles/structs.hpp"

int main()
{
    /*
    ============================================================================
                            Testing ArrayStack
    ============================================================================
    ArrayStack testStack;
    int stackValues[] = { 5, 4, 56, 6, 12, 67, 5, 34, 12, 4, 78, 97};

    for( int index = 0; index < 12; index++ )
    {
        testStack.resizeStack();
        testStack.push( stackValues[ index ] );
    }

    testStack.printStack();

    int poppedValue = testStack.pop();

    for( int index = 0; index < 8; index++ )
    {
        testStack.pop();
    }

    testStack.printStack();

    testStack.push( 13 );
    testStack.printStack();
    */
    /*
    ============================================================================
                            Testing LinkedStack
    ============================================================================
    LinkedStack stack;
    int poppedValue;
    stack.push( 5 );
    stack.push( 24 );

    stack.printStack();
    poppedValue = stack.pop()->val;
    cout << "Popped " << poppedValue << " off the stack" << endl;
    stack.printStack();
    poppedValue = stack.pop()->val;
    cout << "Popped " << poppedValue << "off the stack" << endl;
    stack.printStack();
    cout << "Pushing\n";
    stack.push( 12 );
    stack.push( 45 );
    stack.printStack();
    */
   /*
   =============================================================================
                            Testing LinkedQueue
   ==============================================================================
   LinkedQueue queue;
   int values[] = { 4, 5, 6, 7, 8, 12, 45, 23 };
   int dequeued; 
   queue.peekFront();
   for( int index = 0; index < 8; index++ )
   {
    queue.enqueue( values[ index ] );
   }
   queue.printQueue();
   queue.peekFront();
   for( int index = 0; index < 4; index++ )
   {
    dequeued = queue.dequeue()->val;
    cout << "Dequeued Value: " << dequeued << endl;
   }
   queue.printQueue();
   */
   /*
   =============================================================================
                            Testing ArrayQueue
   =============================================================================
   LinkedList newList;
   LinkedList sortedList;
   LL_Node *returnedPtr;
   int values[] = { 3, 4, 5, 12, 43, 8 };

   for( int index = 0; index < 6; index++ )
   {
    newList.appendNode( values[index ] );
   }
   newList.printLinkedList();
   returnedPtr = newList.sort();
   LL_Node *wkgPtr = returnedPtr;
   while( wkgPtr != NULL )
   {
    cout << wkgPtr->val << ", ";
    wkgPtr = wkgPtr -> nextPtr;
   }

   cout << endl;

   newList.removeNthNode( 1 );
   cout << "Removing the value at index 1" << endl;
   newList.printLinkedList();
   newList.removeNodeValue( 43 );
   cout << "Removing 43 from LL" << endl;
   newList.printLinkedList();
   */
   return 0;
}