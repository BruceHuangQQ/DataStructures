
// COS30008 - Tutorial 9, 2026
#include <cassert>
#include <optional>

template<typename T>
class DynamicStack
{
public:
    
  DynamicStack() noexcept; //done
  ~DynamicStack() noexcept; //done

  DynamicStack( const DynamicStack& aOther ) = delete; //disallow copy
  DynamicStack& operator=( const DynamicStack& aOther ) = delete;
    
  size_t size() const noexcept; //access the size of the stack
    
  std::optional<T> top() const noexcept; // access the last element of the stack  --- the element about to be poped
  void push( const T& aValue ) noexcept; // first in
  void pop() noexcept;  // last out
  void pop( size_t k ) noexcept; // last out - fixed size

private:
  T* fElements; // element on the stack
  size_t fStackPointer; // always points to the next free slot
  size_t fCurrentSize; // current stack size
    
  void resize( size_t aNewSize );
  void ensure_capacity();
  void adjust_capacity();
};

template<typename T>
DynamicStack<T>::DynamicStack() noexcept {
    fElements = new T[1];
    fStackPointer = 0;
    fCurrentSize = 1;
}

template<typename T>
DynamicStack<T>::~DynamicStack() noexcept {
    delete[] fElements;
}

template<typename T>
std::optional<T> DynamicStack<T>::top() const noexcept {
    if (fStackPointer == 0) {
        //what to return?
        return  std::optional<T>();
    }
    return fElements[fStackPointer - 1];
}

template<typename T>
size_t DynamicStack<T>::size() const noexcept {
    //access the size of the stack
    return fStackPointer; // the actual size of the stack not including the empty slots. 
}


template<typename T> 
void DynamicStack<T>::push(const T& aValue) noexcept {
    ensure_capacity();
    fElements[fStackPointer] = aValue;
    fStackPointer++;
}

template<typename T>
void DynamicStack<T>::pop() noexcept {
   //remove the last element
    if (fStackPointer > 0) {
        fStackPointer--;
        adjust_capacity();
    }
}

template<typename T>
void DynamicStack<T>::pop(size_t k) noexcept {
    for (size_t i = 0; i < k; i++) {
        this->pop();
    }
}

template<typename T>
void DynamicStack<T>::resize(size_t aNewSize) {
    T* lNewElements = new T[aNewSize];
    for (size_t i = 0; i < fStackPointer; i++)
        lNewElements[i] = fElements[i];
    delete[] fElements;
    fElements = lNewElements;
    fCurrentSize = aNewSize;
}

template<typename T>
void DynamicStack<T>::ensure_capacity() {
    if (fStackPointer == fCurrentSize)
        resize(fCurrentSize * 2);
}

template<typename T>
void DynamicStack<T>::adjust_capacity() {
    if (fCurrentSize > 1 && fStackPointer * 4 <= fCurrentSize)
        resize(fCurrentSize / 2);
}