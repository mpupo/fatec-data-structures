#include <iostream>
#include "Duplafila.h"

using namespace std;

int main()
{
    cout << "DUPLA FILA - AULA 26-05-2020" << endl;
    cout << "Murilo Pupo de Oliveira" << endl;
    int opc;   
    int valor; 
    int tamanho_escolhido;

    cout << "Digite um tamanho de fila: ";
    cin >> tamanho_escolhido;

    Deck<int> dupla_fila = Deck<int>(tamanho_escolhido);

    do
    {
        cout << "Menu:" << endl;
        cout << "1 - Insere no fim da fila" << endl;
        cout << "2 - Insere no inicio da fila" << endl;
        cout << "3 - Remove do inicio da fila" << endl;
        cout << "4 - Remove do fim da fila" << endl;
        cout << "5 - Exibe o primeiro elemento" << endl;
        cout << "6 - Exibe o ultimo elemento" << endl;
        cout << "7 - Exibe a fila" << endl;
        cout << "8 - Fim" << endl;
        cout << "Selecione: ";
        cin >> opc;

        switch (opc)
        {
        case 1: {
            cout << "Digite o valor para inserir no fim da fila: ";
            cin >> valor;

            if (dupla_fila.isFull())
            {
                cout << "Fila cheia..." << endl;

            }
            else
            {
                dupla_fila.insertInTheEnd(valor);
                cout << "Valor inserido no fim da fila!" << endl;
            }
            system("pause");

            system("cls");
        }break;
        case 2:
        {
            cout << "Digite o valor para inserir no inicio da fila: ";
            cin >> valor;

            if (dupla_fila.isFull())
            {
                cout << "Fila cheia..." << endl;

            }
            else
            {
                dupla_fila.insertInStart(valor);
                cout << "Valor inserido no inicio da fila!" << endl;
            }
            system("pause");
            system("cls");
        }
        break;
        case 3:
        {
            if (dupla_fila.isEmpty())
            {
                cout << "Fila vazia..." << endl;
            }
            else
            {
                cout << " Removido do inicio da fila: " << dupla_fila.removeInStart() << endl;
            }
            system("pause");
            system("cls");
        }
        break;
        case 4:
        {
            if (dupla_fila.isEmpty())
            {
                cout << "Fila vazia..." << endl;
            }
            else
            {
                cout << " Removido do fim da fila: " << dupla_fila.removeInTheEnd() << endl;
            }
            system("pause");
            system("cls");
        }
        break;
        case 5:
        {
            if (dupla_fila.isEmpty())
            {
                cout << "Fila vazia..." << endl;
            }
            else
            {
                cout << " Primeiro elemento: " << dupla_fila.first() << endl;
            }
            system("pause");
            system("cls");
        }
        break;
        case 6:
        {
            if (dupla_fila.isEmpty())
            {
                cout << "Fila vazia..." << endl;
            }
            else
            {
                cout << " Ultimo elemento: " << dupla_fila.last() << endl;
            }
            system("pause");
            system("cls");
        }
        break;
        case 7:
        {
            if (dupla_fila.isEmpty())
            {
                cout << "Nao ha conteudo para exibir pois a fila vazia..." << endl;
            }
            else
            {
                cout << "Conteudo da fila: " << endl;

                if (dupla_fila.start <= dupla_fila.end) {
                    for (int i = dupla_fila.start; i <= dupla_fila.end; i++) {
                        if (i < dupla_fila.end) {
                            cout << dupla_fila.vector[i] << ",";
                        }
                        else if (i == dupla_fila.end - 1) {
                            cout << dupla_fila.vector[i] << endl;
                        }
                    }
                }
                else {
                    for (int i = dupla_fila.start; i < dupla_fila.size; i++) {
                        if (i < dupla_fila.size) {
                            cout << dupla_fila.vector[i] << ",";
                        }
                        else if (i == dupla_fila.size - 1) {
                            cout << dupla_fila.vector[i] << endl;
                        }

                    }
                    for (int i = 0; i <= dupla_fila.end;i++) {
                        if (i == dupla_fila.end) {
                            cout << dupla_fila.vector[i] << ",";
                        }
                        else {
                            cout << dupla_fila.vector[i] << endl;
                        }
                    }
                }
            }
            system("pause");
            system("cls");
        }
        break;
        case 8:
        {
            cout << "Fim do programa." << endl;
        }
        break;
        default:
        {
            cout << "Opcao invalida. Insira novamente a opcao desejada." << endl;
            system("pause");
            system("cls");
        }
        break;
        }
    } while (opc != 8);

    return 0;
}