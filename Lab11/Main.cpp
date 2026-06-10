
// COS30008, Tutorial 11, 2026

#include <iostream>
#include <string>
#include <algorithm>

#define P1
//#define P2

#ifdef P1

#include "DoublyLinkedList.h"

void testP1()
{
    std::cout << "Test DoublyLinkedList:" << std::endl;
    
    using StringList = DoublyLinkedList<std::string>;
    using ListNode = StringList::node;

    std::string lA( "AAAA" );
    std::string lD( "DDDD" );
    std::string lF( "FFFF" );
    
    StringList lNodeC( "CCCC" );
    StringList lNodeD( lD );

    ListNode One = StringList::makeNode( lA );
    ListNode Two = StringList::makeNode( "BBBB" );

    ListNode Three = StringList::makeNode( lNodeC );
    ListNode Four = StringList::makeNode( lNodeD );

    ListNode Five = StringList::makeNode( StringList( "EEEE" ) );

    ListNode Six = StringList::makeNode( StringList( lF ) );

    // link nodes
    One->link( Six, Two );
    Two->link( One, Three );
    Three->link( Two, Four );
    Four->link( Three, Five );
    Five->link( Four, Six );
    Six->link( Five, One );
    
    std::cout << "Traverse links in the forward direction:" << std::endl;
    
    ListNode lForward = Four;

    do
    {
        std::cout << "Value: " << lForward->data << std::endl;
        lForward = lForward->next;
    } while ( lForward != Four );

    std::cout << "Traverse links in the backward direction:" << std::endl;

    ListNode lBackwards = Four;

    do
    {
        std::cout << "Value: " << lBackwards->data << std::endl;
        lBackwards = lBackwards->previous.lock();
    } while ( lBackwards != Four );

    std::cout << "Traverse links in the forward direction (Four <==> Six):" << std::endl;

    std::swap( Four->data, Six->data );
    
    ListNode lForward2 = Four;

    do
    {
        std::cout << "Value: " << lForward2->data << std::endl;
        lForward2 = lForward2->next;
    } while ( lForward2 != Four );

    std::cout << "Traverse links in the forward direction (isolate Three):" << std::endl;

    Three->isolate();
    
    ListNode lForward3 = Four;

    do
    {
        std::cout << "Value: " << lForward3->data << std::endl;
        lForward3 = lForward3->next;
    } while ( lForward3 != Four );
    
    One->isolate();
    Two->isolate();
    Four->isolate();
    Five->isolate();
    Six->isolate();
    
    std::cout << "Test complete." << std::endl;
}

#endif

#ifdef P2

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

void testP2()
{
    std::cout << "Test DoublyLinkedListIterator:" << std::endl;

    using StringList = DoublyLinkedList<std::string>;
    using ListNode = StringList::node;

    std::string lA( "AAAA" );
    std::string lD( "DDDD" );
    std::string lF( "FFFF" );
    StringList lNodeC( "CCCC" );
    StringList lNodeD( lD );

    ListNode NIL;
    ListNode One = StringList::makeNode( lA );
    ListNode Two = StringList::makeNode( "BBBB" );
    ListNode Three = StringList::makeNode( lNodeC );
    ListNode Four = StringList::makeNode( lNodeD );
    ListNode Five = StringList::makeNode( StringList( "EEEE" ) );
    ListNode Six = StringList::makeNode( StringList( lF ) );

    // link nodes
    One->link( NIL, Two );
    Two->link( One, Three );
    Three->link( Two, Four );
    Four->link( Three, Five );
    Five->link( Four, Six );
    Six->link( Five, NIL );

    using Iterator = DoublyLinkedListIterator<std::string>;
 
    Iterator lIter( One, Six );
    
    std::cout << "Forward iteration:" << std::endl;
    
    for ( auto& item : lIter )
    {
        std::cout << item << std::endl;
    }
    
    std::cout << "Backwards iteration:" << std::endl;
    
    for ( auto iter = lIter.rbegin(); iter != --iter.begin(); --iter )
    {
        std::cout << *iter << std::endl;
    }
    
    std::cout << "Test complete." << std::endl;
}

#endif

int main()
{
    
#ifdef P1

    testP1();
    
#endif
    
#ifdef P2
    
    testP2();
    
#endif
    
#ifndef P1
    
    #ifndef P2
    
    std::cout << "No test enabled." << std::endl;
    
    #endif
    
#endif
    
    return 0;
}
