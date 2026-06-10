
// COS30008, Tutorial 11, 2026

#pragma once

#include <memory>

#include <iostream>
#include <iomanip>

template<typename T>
struct DoublyLinkedList
{
    using node = std::shared_ptr<DoublyLinkedList>;
    using node_w = std::weak_ptr<DoublyLinkedList>;

    T data;
    node next;
    node_w previous;

    DoublyLinkedList( const T& aData ) noexcept : data(aData) {}

    DoublyLinkedList( T&& aData ) noexcept : data(std::move(aData)) {}
    
    void link( node& aPrevious, node& aNext ) noexcept // link adjacent nodes
    {
        previous = aPrevious;
        next = aNext;
    }
    
    void isolate() noexcept                            // unlink node
    {
        if ( next )                        // Is there a next node?
        {
            next->previous = previous;
        }

        node lNode = previous.lock();        // lock std::weak_ptr

        if ( lNode )                        // Is there a previous node?
        {
            lNode->next = next;
        }
            
        previous.reset();
        next.reset();
        // lNode goes out of scope
    }

    // factory method for list nodes
    template<typename... Args>
    static node makeNode( Args&&... args )
    {
        // make_share<T, Args...>
        return std::make_shared<DoublyLinkedList>( std::forward<Args>(args)... );
    }
};
