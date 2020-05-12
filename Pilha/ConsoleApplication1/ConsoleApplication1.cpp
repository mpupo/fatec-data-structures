#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{

    Stack<std::string> pilha = Stack<std::string>(50);
    std::string frase;
    int opcao;
    do
    {
        std::cout << "Palindromos:" << std::endl;
        std::cout << "1 - Inserir nova frase" << std::endl;
        std::cout << "9 - Fim" << std::endl;
        std::cout << "Selecione:";
        std::cin >> opcao;
        switch (opcao)
        {
        case 1:
            std::cout << "Digite a frase:";
            std::cin.clear();
            std::cin.ignore();
            //std::cin >> frase;
            std::getline(std::cin, frase);

            std::cout << "A palavra digitada foi: " << frase << std::endl;
            pilha.insertPhrase(frase);

            if (pilha.sao_palindromos(frase))
            {
                std::cout << "A palavra " << frase << " eh palindroma!" << std::endl;
            }
            else
            {
                std::cout << "A palavra " << frase << " nao eh pali'ndroma!" << std::endl;
            }

            pilha.clear();
            system("pause");
            system("cls");
            break;
        case 9:
        {
            std::cout << "Fim..." << std::endl;
            system("pause");
            system("cls");
            break;
        }
        default:
        {
            std::cout << "opcao invalida" << std::endl;
            system("pause");
            system("cls");
            break;
        }
        }
    } while (opcao != 9);

    return 0;
}
