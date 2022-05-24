#pragma once
template<typename T>
class PrioQNode
{
private:
    T item;
    int priority;
    PrioQNode<T>* next;
public:
    //THIS CLASS IS THE SAME AS NODE CLASS USED FOR LINKED LIST , THE ONLY DIFFERENCE IS PRIORITY DATA MEMBER AND NON-DEFAULT CONSTRUCTOR AND GETKEY FUNCTION
    PrioQNode() //default constructor
    {
        next = nullptr;
    }
    PrioQNode(T newItem, int pri) //non-default constructor
    {
        item = newItem;
        priority = pri;
        next = nullptr;
    }
    void setItem(T newItem)
    {
        item = newItem;
    } // end setItem

    void setNext(PrioQNode<T>* nextNodePtr)
    {
        next = nextNodePtr;
    } // end setNext
    T getItem() const
    {
        return item;
    } // end getItem

    PrioQNode<T>* getNext() const
    {
        return next;
    }
    int getKey() //returns the key or priority of node
    {
        return priority;
    }
};
#pragma once
