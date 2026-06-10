
// COS30008, Tutorial 12, 2026

#pragma once

#include <cstddef>
#include <memory>
#include <cassert>
#include <iostream>

#include "Visitors.h"

template<typename T>
class BTree
{
public:
	using node = std::unique_ptr<BTree>;

	BTree( const T& aKey = T{} ) noexcept :
		fKey(aKey)
	{}

	BTree( T&& aKey ) noexcept :
		fKey(std::move(aKey))
	{}
    
    ~BTree()
    {
        std::cout << "Deleting " << fKey << std::endl;
    }

	template<typename... Args>
	static node makeNode( Args&&... args )
	{
		return std::make_unique<BTree>( std::forward<Args>(args)... );
	}

	BTree( const BTree& aOther ) :
		fKey(aOther.fKey)
	{
		if ( aOther.hasLeft() )
		{
			// copy non-empty subtree
			fLeft = std::move(makeNode(aOther.left()));
		}

		if ( aOther.hasRight() )
		{
			// copy non-empty subtree
			fRight = std::move(makeNode(aOther.right()));
		}
	}

	BTree& operator=( const BTree& aOther )
	{
		if ( this != &aOther )
		{
			this->~BTree();

			new (this) BTree( aOther );
		}

		return *this;
	}

	BTree( BTree&& aOther ) noexcept :
		BTree()
	{
		swap(aOther);
	}

	BTree& operator=( BTree&& aOther ) noexcept
	{
		if ( this != &aOther )
		{
			swap(aOther);
		}

		return *this;
	}

	void swap( BTree& aOther ) noexcept
	{
		std::swap(fKey, aOther.fKey);
		std::swap(fLeft, aOther.fLeft);
		std::swap(fRight, aOther.fRight);
	}

	const T& operator*() const noexcept
	{
		return fKey;
	}

	bool hasLeft() const noexcept
	{
		return fLeft ? true : false;
	}

	BTree& left() const noexcept
	{
		// valid node
		assert(fLeft);

		return *fLeft;
	}

	bool hasRight() const noexcept
	{
		return fRight ? true : false;
	}

	BTree& right() const noexcept
	{
		// valid node
		assert(fRight);

		return *fRight;
	}

	void attachLeft( node& aNode )
	{
		// transfers ownership from aNode to fLeft

		// valid free node
		assert(!fLeft);

		fLeft = std::move(aNode);
	}

	void attachRight( node& aNode )
	{
		// transfers ownership from aNode to fRight

		// valid free node
		assert(!fRight);

		fRight = std::move(aNode);
	}

	node detachLeft()
	{
		// transfers ownership from fLeft to result

		// valid index and node
		assert(fLeft);

		return std::move(fLeft);
	}

	node detachRight()
	{
		// transfers ownership from fRight to result

		// valid index and node
		assert(fRight);

		return std::move(fRight);
	}
    
    bool leaf() const noexcept
    {
        return !fLeft && !fRight;
    }
    
    size_t height() const noexcept
    {
        size_t Result = 0;
        
        if ( !leaf() )
        {
            Result = std::max(fLeft ? fLeft->height() + 1 : 0,
                              fRight ? fRight->height() + 1 : 0);
        }
        
        return Result;
    }

    const T& findMax() const noexcept
    {
        // use tail recursion
        const BTree* lCurrent = this;
        
        while ( lCurrent->hasRight() )
        {
            lCurrent = &lCurrent->right();
        }
        
        return **lCurrent;
    }

    const T& findMin() const noexcept
    {
        // use tail recursion
        const BTree* lCurrent = this;
        
        while ( lCurrent->hasLeft() )
        {
            lCurrent = &lCurrent->left();
        }
        
        return **lCurrent;
    }
    
    void doDepthFirstSearch( const TreeVisitor<T>& aVisitor ) const noexcept
    {
        aVisitor.preVisit( **this );
        
        if ( hasLeft() )
        {
            left().doDepthFirstSearch( aVisitor );
        }
        else
        {
            aVisitor.emitEmpty();
        }
        
        aVisitor.inVisit( **this );

        if ( hasRight() )
        {
            right().doDepthFirstSearch( aVisitor );
        }
        else
        {
            aVisitor.emitEmpty();
        }

        aVisitor.postVisit( **this );
    }

private:

    T fKey;
	node fLeft;
	node fRight;
};
