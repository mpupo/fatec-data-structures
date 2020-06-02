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

    ~Stack()
    {
        delete stack;
    }

    void push(char x)
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
            std::cout << stack[i] << std::endl;
        }
    }

    void insertPhrase(std::string phrase)
    {
        for (int letter = 0; letter < phrase.size(); letter++)
        {
            push(phrase.at(letter));
        };
    }

    std::string removeCapitalLetter(std::string input)
    {
        std::string output = "";
        for (int letter = 0; letter < input.size(); letter++)
        {
            output += char(tolower(input.at(letter)));
        }
        return output;
    }

    std::string removePunctuation(std::string input)
    {
        std::vector<char> punctuations = {'!', ';', ',', '.', '#', '?', '-', '_'};

        for (int letter = 0; letter < input.size(); letter++)
        {
            for (int pont = 0; pont < punctuations.size(); pont++)
            {
                if (input[letter] == punctuations[pont])
                {
                    input.at(letter) = ' '; // '' pois é um unico elemento de char
                }
            }
        }
        return input;
    }

    std::string removeBlankSpaces(std::string input)
    {
        std::string output = ""; // "" pois é uma array de string que vai ser concatenada

        for (int letter = 0; letter < input.size(); letter++)
        {
            if (input.at(letter) != ' ')
            {
                output += input.at(letter);
            }
        }
        return output;
    }

    bool sao_palindromos(std::string input)
    {
        input = removePunctuation(input);
        input = removeBlankSpaces(input);
        input = removeCapitalLetter(input);
        insertPhrase(input);

        std::string letter;
        std::string stack_letter;


        bool isPalindromo = true;
        for (int i = 0; i < input.length(); i++)
        {
            letter = input[i];
            stack_letter = firstElement();
            if (letter == stack_letter)
            {
                pop();
            }
            else
            {
                isPalindromo = false;
                break;
            }
        }
        return isPalindromo;
    };
};
