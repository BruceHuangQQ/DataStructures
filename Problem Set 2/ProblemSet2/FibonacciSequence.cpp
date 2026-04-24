#include "FibonacciSequence.h"

FibonacciSequence::FibonacciSequence() noexcept
	: fPrevious(0), fCurrent(1){}

const uint64_t& FibonacciSequence::operator*() const noexcept {
	return fCurrent;
}

FibonacciSequence& FibonacciSequence::operator++() noexcept {
	fCurrent = fCurrent + fPrevious;
	fPrevious = fCurrent - fPrevious;
	return *this; //object itself
}

// what is this?
FibonacciSequence FibonacciSequence::operator++(int) noexcept {
	FibonacciSequence temp = *this;
	++(*this);
	return temp;
}

bool FibonacciSequence::operator==(const FibonacciSequence& aOther) const noexcept {
	return fPrevious == aOther.fPrevious && fCurrent == aOther.fCurrent;
}

void FibonacciSequence::begin() noexcept {
	fPrevious = 0;
	fCurrent = 1;
}

void FibonacciSequence::end() noexcept {
	fPrevious = 0;
	fCurrent = 0;
}