#include <iostream>
#include <stdlib.h>
#include "fila.h"

using namespace std;

int main()
{
    Fila<int> f(10);
    int opc,x;
    cout << "Fila Sequencial" << endl;
    do{
        cout<<"1-insere"<<endl;
        cout<<"2-remove"<<endl;
        cout<<"3-primeiro"<<endl;
        cout<<"8-exibe fila"<<endl;
        cout<<"9-fim"<<endl;
        cout<<"Selecione:";
        cin>>opc;
        switch(opc){
        case 1:
            if(f.filacheia())
            {
                cout<<"fila cheia..."<<endl;
            }
            else
            {
                cout<<"digite o valor: ";
                cin>>x;
                f.insere(x);
                cout<<"sucesso!"<<endl<<endl;

            }
            break;
        case 2:
            if(f.filavazia())
            {
                cout<<"fila vazia..."<<endl;
            }
            else
            {
                cout<<"removido: "<<f.remover()<<endl<<endl;
            }
            break;
        case 3:
            if(f.filavazia())
            {
                cout<<"fila vazia..."<<endl;
            }
            else
            {
                cout<<"primeiro: "<<f.primeiro()<<endl<<endl;
            }
            break;
        case 8:
            break;
        case 9:
            cout<<"fim..."<<endl;
            break;
        default:
            cout<<"opcao invalida..."<<endl;
            break;

        }
    }while(opc != 9);
    return 0;
}
