#include <iostream>
#include "ListaLinear.h"

using namespace std;

int main()
{
    cout << "LISTA LINEAR - AULA 10-03-2020" << endl;
    int opc;   // Opcao a selecionar.
    int valor; // Valor de entrada.
    int tamanho_escolhido;

    cout << "Digite um tamanho de lista: ";
    cin >> tamanho_escolhido;

    ListaLinear<int> lista = ListaLinear(tamanho_escolhido); // Lista linear.

    do
    {
        cout << "1 - Insere" << endl;
        cout << "2 - Remove" << endl;
        cout << "3 - Quantidade de elementos" << endl;
        cout << "4 - Mostra os elementos" << endl;
        cout << "5 - Verificar se a lista esta ordenada" << endl;
        cout << "6 - Fazer copia da Lista1 para a Lista 2" << endl;
        cout << "7 - Remover os elementos da Lista1 para a Lista2" << endl;
        cout << "8 - Fim" << endl;
        cout << "Selecione: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << "Digite o valor para inserir";
            cin >> valor;

            if (!lista.esta_vazia())
            {
                cout << "Lista cheia..." << endl;
            }
            else
            {
                lista.insere(valor);
            }
            break;
        case 2:
            if (lista.esta_vazia())
            {
                cout << "Lista vazia..." << endl;
            }
            else
            {
                cout << "Removido: " << lista.remover() << endl;
            }
            break;
        case 3:
            if (lista.esta_vazia())
            {
                cout << "Lista vazia..." << endl;
            }
            else
            {
                cout << " Quantidade de elementos: " << lista.indice + 1 << endl;
            }
            break;
        case 4:
            cout << "Elementos da lista:" << endl;
            if (lista.esta_vazia())
            {
                cout << "Lista vazia..." << endl;
            }
            else
            {
                for (int elem = 0; elem <= lista.indice; elem++)
                {
                    cout << lista.elementos[elem] << " ";
                    cout << endl;
                }
            }
            break;
        case 5:
            if (lista.esta_ordenada())
            {
                cout << "A lista esta ordenada." << endl;
            }
            else
            {
                cout << "A lista nao esta ordenada." << endl;
            }
            break;
        case 6:
            ListaLinear<int> nova_lista = lista.copiar_lista();

            cout << "Lista copiada!" << endl;

            cout << "Conteudo da lista 1: ";
            lista.printar_elementos();

            cout << "Conteudo da lista 2: ";
            nova_lista.printar_elementos();

            break;
        case 7:
            ListaLinear<int> nova_lista = lista.copiar_e_remover_elementos();

            cout << "Lista copiada. Os elementos da antiga lista foram removidos." << endl;

            cout << "Conteudo da lista 1: ";
            lista.printar_elementos();

            cout << "Conteudo da lista 2: ";
            nova_lista.printar_elementos();

            break;
        case 8:
            cout << "Fim do programa." << endl;
            break;
        default:
            cout << "Opcao invalida. Insira novamente a opcao desejada." << endl;
            break;
        }
    } while (opc != 8);

    return 0;
}

/*Exercícios:
1. Dada uma lista seqüencial ordenada L1, escreva os procedimentos que:
a. Verifique se L1 está ordenada ou não (a ordem pode ser crescente ou decrescente).
b. Faça uma cópia da lista L1 em outra lista L2;
c. Remova os elementos de L1 colocando-os em L2.*/
