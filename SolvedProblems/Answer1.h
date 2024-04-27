//
// Created by enes4 on 4/27/2024.
//

#ifndef SORULARSTACK_STACK_H
#define SORULARSTACK_STACK_H
using namespace std;
#include <iostream>

template<class T>
        struct Node
                {
                    T data;
                    Node<T>* back;
                };

template<class T>
class Stack {
Node<T> *top;
public:
    Stack();
    ~Stack();
    bool isEmpty();
    T stop();
    T pop();
    void push(const T&);
    void destroy();

    bool operator==(Stack<T>& otherStack);

};


/*Question:
 * Write a member function to overload the == operator
in the Stack class implemented with linked lists.
The function takes another stack as a parameter and
returns true if the contents of the parameter
stack are the same as the current stack, false otherwise.*/


template<class T>
bool Stack<T>::operator==(Stack<T> &otherStack)
        {
            if(this->isEmpty() && otherStack.isEmpty())
                return true;

            while(!otherStack.isEmpty())
            {
                if(this->pop() == otherStack.pop())
                    continue;
                else
                    return false;
            }
            if(this->isEmpty())
                return true;
            else
                return false;

        }




template<class T>
Stack<T>::Stack()
{
    top = nullptr;
}
template<class T>
Stack<T>::~Stack()
{
    destroy();
}

template<class T>
bool Stack<T>::isEmpty()
{
    return top == nullptr;
}

template<class T>
T Stack<T>::stop()
{
    if(top == nullptr)
    {
        cout << "cannot stop from empty list;";
        return;
    }

    return top->data;
}

template<class T>
T Stack<T>::pop()
{
    if(top == nullptr)
    {
        cout << "cannot pop from empty list;";
    }

    Node<T> *temp = top;
    top = top->back;
    T poppedData = temp->data;
    delete temp;
    return poppedData;


}

template<class T>
void Stack<T>::push(const T &item)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = item;
        newNode->back = top;
        top = newNode;

}

template<class T>
void Stack<T>::destroy()
{
    if(top == nullptr)
    {
        return;
    }

    Node<T> *temp = top;

    while(temp != nullptr)
    {
        temp = top;
        top = top->back;
        delete temp;
    }
}

#endif //SORULARSTACK_STACK_H
