#pragma once

template <typename Generic>

struct Queue
{

    Generic *vector;
    int size;
    int start;
    int end;
    int qty;

    Queue(int tam)
    {
        size = tam;
        vector = new Generic[size];
        qty = 0;
        end = -1;
        start = 0;
    }
    ~Queue()
    {
        delete(vector);
    }
    void insert(Generic x)
    {
        end++;
        if(end == size)
        {
            end = 0;
        }
        vector[end] = x;
        qty++;
    }
    Generic remove()
    {
        Generic temp = vector[start];
        start++;
        if(start == size)
        {
            start = 0;
        }
        qty--;
        return temp;
    }
    Generic firstElement()
    {
        return vector[start];
    }
    bool isFull(){
        return qty == size;
    }
    bool isEmpty(){
        return qty=0;
    }
};
