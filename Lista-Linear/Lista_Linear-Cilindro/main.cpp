#include <iostream>
#include "..\ListaLinear.h"
#include "cilindro.h"

using namespace std;

int main()
{
    cout << "Lista Cilindro" << endl;
    int opc;    //Opcao a selecionar.
    float raio; //Valor de entrada.
    float altura;
    int tamanho_escolhido;

    cout << "Digite um tamanho para a lista de cilindros: ";
    cin >> tamanho_escolhido;

    ListaLinear<Cilindro> lista_de_cilindros = ListaLinear<Cilindro>(tamanho_escolhido); //a Lista Linear
    do
    {
        cout << "Menu:" << endl;
        cout << "1 - Insere" << endl;
        cout << "2 - Remove" << endl;
        cout << "3 - Quantidade de elementos" << endl;
        cout << "4 - Mostra os elementos" << endl;
        cout << "5 - Fim" << endl;
        cout << "Selecione: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
        {
            if (!lista_de_cilindros.esta_cheia())
            {
                cout << "Digite o valor do raio: " << endl;
                cin >> raio;
                cout << "Digite o valor a altura: " << endl;
                cin >> altura;

                Cilindro cilindro = Cilindro(raio, altura);
                lista_de_cilindros.insere(cilindro);

                cout << "Cilindro inserido!" << endl;
            }
            else
            {
                cout << "Lista cheia..." << endl;
            }
            system("pause");
            system("cls");
        }
        break;
        case 2:
        {
            if (lista_de_cilindros.esta_vazia())
            {
                cout << "Lista vazia..." << endl;
            }
            else
            {
                std::cout << "Removido: ";
                (std::cout,lista_de_cilindros.remover());
                std::cout << endl;
            }
            system("pause");
            system("cls");
        }
        break;
        case 3:
        {
            if (lista_de_cilindros.esta_vazia())
            {
                cout << "Lista vazia..." << endl;
            }
            else
            {
                cout << " Quantidade de elementos: " << lista_de_cilindros.indice + 1 << endl;
            }
            system("pause");
            system("cls");
        }
        break;
        case 4:
        {
            cout << "Elementos da lista de cilindros:" << endl;
            if (lista_de_cilindros.esta_vazia())
            {
                cout << "Lista vazia..." << endl;
            }
            else
            {
                for (int num_cilindro = 0; num_cilindro <= lista_de_cilindros.indice; num_cilindro++)
                {
                    lista_de_cilindros.elementos[num_cilindro].printar_valores();
                }
            }
            system("pause");
            system("cls");
        }
        break;
        case 5:
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
    } while (opc != 5);
    return 0;
}
