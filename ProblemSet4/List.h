
// COS30008, Problem Set 4, 2026

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

template<typename T>
class List
{
private:
    using node = typename DoublyLinkedList<T>::node;
    
    node fHead;
    node fTail;
    size_t fSize;
    
public:

    using iterator = DoublyLinkedListIterator<T>;

    List() noexcept
        : fHead(nullptr), fTail(nullptr), fSize(0)
    {} // default constructor (2)

    ~List()
    {
        while (fTail)
        {
            fTail->next.reset();    // sever the forward link
            fTail = fTail->previous.lock();
        }
    }
    // destructor (16)

    // copy semantics
    List(const List& aOther) : fHead(nullptr), fTail(nullptr), fSize(0)
    {
        for (auto iter = aOther.begin(); iter != aOther.end(); ++iter)
        {
            push_back(*iter);
        }
    }// copy constructor (10)

    List& operator=(const List& aOther)
    {
        if (this != &aOther)
        {
            List lTemp(aOther);
            swap(lTemp);
        }
        return *this;
    } // copy assignment (14)

    // move semantics
    List(List&& aOther) noexcept : fHead(nullptr), fTail(nullptr), fSize(0)
    {
        swap(aOther);
    } // move constructor (4)

    List& operator=(List&& aOther) noexcept
    {
        if (this != &aOther)
        {
            swap(aOther);
        }
        return *this;
    } // move assignment (8)

    void swap(List& aOther) noexcept
    {
        std::swap(fHead, aOther.fHead);
        std::swap(fTail, aOther.fTail);
        std::swap(fSize, aOther.fSize);
    }
    // swap elements (9)

    // basic operations
    size_t size() const noexcept
    {
        return fSize;
    } // list size (2)
    
    template<typename U>
    void push_front(U&& aData)
    {
        node lNode = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));

        // link: previous=nullptr, next=fHead
        node lNullNode;
        lNode->link(lNullNode, fHead);

        if (fHead)
        {
            fHead->previous = lNode;
        }
        else
        {
            fTail = lNode;  // list was empty
        }

        fHead = lNode;
        fSize++;
    }// add element at front (24)
    
    template<typename U>
    void push_back(U&& aData)
    {
        node lNode = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));

        // link: previous=fTail, next=nullptr
        node lNullNode;
        lNode->link(fTail, lNullNode);

        if (fTail)
        {
            fTail->next = lNode;
        }
        else
        {
            fHead = lNode;  // list was empty
        }

        fTail = lNode;
        fSize++;
    } // add element at back (24)
    
    void remove(const T& aElement) noexcept
    {
        node lCurrent = fHead;

        while (lCurrent)
        {
            if (lCurrent->data == aElement)
            {
                // Adjust head/tail if needed before isolating
                if (lCurrent == fHead)
                {
                    fHead = lCurrent->next;
                }
                if (lCurrent == fTail)
                {
                    fTail = lCurrent->previous.lock();
                }

                lCurrent->isolate();    // unlinks and resets next/previous
                fSize--;

                return; // remove only first occurrence
            }

            lCurrent = lCurrent->next;
        }
    } // remove element (36)
    
    const T& operator[](size_t aIndex) const
    {
        node lCurrent = fHead;

        for (size_t i = 0; i < aIndex; i++)
        {
            lCurrent = lCurrent->next;
        }

        return lCurrent->data;
    }// list indexer (14)
    
    // iterator interface
    iterator begin() const noexcept
    {
        return iterator(fHead, fTail).begin();
    }

    iterator end() const noexcept
    {
        return iterator(fHead, fTail).end();
    }

    iterator rbegin() const noexcept
    {
        return iterator(fHead, fTail).rbegin();
    }

    iterator rend() const noexcept
    {
        return iterator(fHead, fTail).rend();
    }
};
