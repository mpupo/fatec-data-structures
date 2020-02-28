#include <iostream>
#include <stdlib.h>
#include "bilheteria.h"
#include "teatro.h"

using namespace std;

int main()
{
    int num_assentos_teatro;
    cout << "Digite a quantidade de assentos desejada para o teatro:" << endl;
    cin >> num_assentos_teatro;

    Teatro teatro = Teatro(num_assentos_teatro);
    Bilheteria bilheteria = Bilheteria();
    //Cliente cliente = Cliente();

    int assento;
    int assento_a_trocar;

    bool assento_comprado;
    bool assento_devolvido;

    bool troca;
    bool propriedade;


    int escolha;

    do
    {
        cout << "TEATRO FATEC RUBENS LARA";
        cout << "EVENTO: ENTREGA DE ATIVIDADE 18-02-2020" << endl;
        cout << "Menu:";
        cout << " 1 - Comprar assento" << endl;
        cout << " 2 - Devolver assento" << endl;
        cout << " 3 - Trocar assento" << endl;
        cout << " 4 - Ver todos os assentos" << endl;
        cout << " 5 - Ver total de pessoas" << endl;
        cout << " 0 - Sair" << endl;

        cin >> escolha;

        switch (escolha)
        {
        case 1:
            do
            {
                cout << "Escolha o assento para comprar:" << endl;
                cin >> assento;
                assento_comprado = bilheteria.realizar_compra(teatro.getLugar(assento), 1);
                if (assento_comprado)
                {
                    cout << "Assento comprado com sucesso!" << endl;
                    teatro.contCompra();
                }
                else
                {
                    cout << "O assento já está ocupado.Tente novamente" << endl;
                }

            } while (assento_comprado != true);
            break;

        case 2:
            do
            {
                do
                {
                    cout << "Escolha o assento que deseja devolver:" << endl;
                    cin >> assento;

                    if (assento > num_assentos_teatro)
                    {
                        cout << "Assento inexistente. Tente novamente!" << endl;
                    }

                    else if (assento <= 0)
                    {
                        cout << "Assento inválido. Tente novamente!" << endl;
                    }

                } while (assento > num_assentos_teatro || assento <= 0);

                assento_devolvido = bilheteria.realizar_devolucao(teatro.getLugar(assento), 1);

                if (assento_devolvido)
                {
                    cout << "Assento devolvido com sucesso!" << endl;
                    teatro.contDevolucao();
                }

                else
                {
                    cout << "Voce não possui permissao para devolver este assento. Tente novamente!" << endl;
                }

            } while (assento_devolvido != true);

            break;

        case 3:
            do
            {
                do
                {
                    cout << "Digite o assento que voce possui:" << endl;
                    cin >> assento;

                    propriedade = teatro.verificarPropriedade(assento, 1);

                    if (!propriedade)
                    {
                        cout << "Voce nao possui propriedade sobre este assento. Tente novamente!" << endl;
                    }
                } while (propriedade != true);

                cout << "Digite o novo assento que deseja comprar:" << endl;
                cin >> assento_a_trocar;

                troca = bilheteria.realizar_troca(teatro.getLugar(assento),teatro.getLugar(assento_a_trocar), 1);

                if (troca){
                    cout << "Troca realizada com sucesso!" << endl;
                }
                else
                {
                    cout << "O assento desejado está ocupado. Tente novamente!" << endl;
                }
                
            } while (troca != true);
            break;

        case 4:
            //teatro.getTodosOsAssentos()
            break;

        case 5:
            cout << "O total de acentos comprados e':" << teatro.getTotalDeLugaresComprados() << endl;
            break;

        default:
            cout << "Opcao invalida. Tente novamente" << endl;
            system("cls");
            break;
        }
    } while (escolha != 0);

    return 0;
}
