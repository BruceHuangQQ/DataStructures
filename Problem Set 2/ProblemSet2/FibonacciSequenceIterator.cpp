#include "FibonacciSequenceIterator.h"

FibonacciSequenceIterator::FibonacciSequenceIterator(
    FibonacciSequence* aSequence, uint64_t aStart) noexcept
    : fSequence(aSequence), fIndex(aStart) {}

const uint64_t& FibonacciSequenceIterator::operator*() const noexcept {
    return **fSequence;
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept {
    ++(*fSequence);  // advance the sequence
    fIndex++;        // advance the position
    return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept {
    FibonacciSequenceIterator temp = *this;
    ++(*this);
    return temp;
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const noexcept {
    fSequence->begin();       // reset the underlying sequence
    return FibonacciSequenceIterator(fSequence, 1);  // start at position 1
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept {
    return FibonacciSequenceIterator(fSequence, MAX_FIBONACCI + 1);  // stop at 94
}

bool FibonacciSequenceIterator::operator==(
    const FibonacciSequenceIterator& aOther) const noexcept {
    return fIndex == aOther.fIndex;
}

