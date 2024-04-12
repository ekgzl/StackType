//
// Created by enes4 on 4/12/2024.
//

#ifndef STACK_STACKTYPE_H
#define STACK_STACKTYPE_H

using namespace std;
#include <iostream>
#include <cassert>

template <class T>
class stackType{
private:
    int maxStackSize;
    int stackTop;
    T* list;
public:
    stackType(int maxStackSize = 100)
    {
        if(maxStackSize <= 0)
        {
            cout << "it should be positive.";
            maxStackSize = 100;
        }
            this->maxStackSize = maxStackSize;
            stackTop = 0;
            list = new T[this->maxStackSize];
    }
    ~stackType()
    {
        delete[] list;
    }

    stackType(const stackType<T>& other)
    {
        list = nullptr;
        copyStack(other);
    }
    void initializeStack()
    {
        stackTop = 0;
    }
    bool isEmpty()
    {
        return stackTop==0;
    }

    bool isFull()
    {
        return stackTop==maxStackSize;
    }

    void push(const T& item)
    {
        if(!isFull())
            list[stackTop++] = item;
        else
            cout << "Cannot add to a full stack." << endl;
    }

    T top() const
    {
        assert(stackTop != 0);

        return list[stackTop -1];
    }

    void pop()
    {
        if(!isEmpty())
            stackTop--;
        else
            cout << "Cannot remove from an empty stack." << endl;
    }

    void copyStack(const stackType<T>& other)
    {
        delete [] list;
        maxStackSize = other.maxStackSize;
        stackTop = other.stackTop;
        list = new T[maxStackSize];

        for (int i = 0; i < other.stackTop; ++i) {
            list[i] = other.list[i];
        }
    }

    const stackType<T>& operator=(const stackType<T>& other)
            {
                if(this != &other)
                    copyStack(other);
                return *this;
            }

};
#endif //STACK_STACKTYPE_H
