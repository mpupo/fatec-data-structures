#pragma once
#include <string>
#include <vector>
#include <iostream>
// Aluno: Murilo Pupo de Oliveira ADS 3 Noite

template <typename Generic>
struct Stack
{
    Generic *stack;
    int top;
    int size;

    Stack(int tam)
    {
        size = tam;
        top = -1;
        stack = new Generic[size];
    }
    /*
    ~Stack()
    {
        delete stack;
    }
    */

    void push(Generic x)
    {

        top++;
        stack[top] = x;
    }

    Generic pop()
    {
        Generic temp = stack[top];
        top--;
        return temp;
    }

    void clear()
    {
        top = -1;
    }

    Generic firstElement()
    {
        return stack[top];
    }

    bool is_full()
    {
        return top == size - 1;
    }

    bool is_empty()
    {
        return top == -1;
    }

    void showElements()
    {
        for (int i = top; i >= 0; i--)
        {
            if (i > 0) {
                std::cout << stack[i] << ", ";
            }
            else if (i == 0) {
                std::cout << stack[i] << std::endl;
            }
        }
    }

    void insertPhrase(Generic phrase)
    {
        for (int letter = 0; letter < phrase.size(); letter++)
        {
            push(phrase.at(letter));
        };
    }
};
