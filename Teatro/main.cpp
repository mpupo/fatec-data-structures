#include <iostream>
#include <stdlib.h>
#include "bilheteria.h"
#include "teatro.h"


using namespace std;

int main()
{
    Teatro teatro = Teatro();
    Bilheteria bilheteria = Bilheteria();
    int escolha;

    do{
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
            bilheteria.realizar_compra()
            break;
        
        case 2:
            bilheteria.realizar_devolucao();
            break;
        
        case 3:
            bilheteria.realizar_troca();
            break;
        
        case 4:
            //teatro.getTodosOsAssentos()
            break;

        case 5:
            cout << "O total de acentos comprados e':" << teatro.getTotalDeLugaresComprados() << endl;
            break;

        default:
            cout << "Opcao invalida. Tente novamente"<< endl
            system("cls");
            break;
        }
    } while (escolha != 0);

    

    return 0;
}
