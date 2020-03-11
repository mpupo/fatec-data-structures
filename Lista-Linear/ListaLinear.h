#ifndef LISTALINEAR_H_INCLUDED
#define LISTALINEAR_H_INCLUDED

#include <iostream>

using namespace std;

template <typename Tipo>
struct ListaLinear
{
    Tipo *elementos;
    int tamanho;
    int indice;

public:
    ListaLinear();
    ListaLinear(int);
    void insere(Tipo x);
    Tipo remover();
    bool preencher();
    bool esvaziar_lista();
    bool esta_ordenada();
    bool esta_vazia();
    Tipo copiar_lista();
    Tipo copiar_e_remover_elementos();
    void printar_elementos();
};

template <typename Tipo>
ListaLinear<Tipo>::ListaLinear(int tam)
{
    indice = -1;
    tamanho = tam;
    elementos = new Tipo[tamanho];
}

template <typename Tipo>
void ListaLinear<Tipo>::insere(Tipo x)
{
    elementos[++indice] = x;
}

template <typename Tipo>
Tipo ListaLinear<Tipo>::remover()
{
    Tipo temp = elementos[indice];
    indice--;
    return temp;
}

template <typename Tipo>
bool ListaLinear<Tipo>::preencher()
{
    return indice == tamanho - 1;
}

template <typename Tipo>
bool ListaLinear<Tipo>::esvaziar_lista()
{
    return indice == -1;
}

template <typename Tipo>
bool ListaLinear<Tipo>::esta_vazia()
{
    if (indice == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Tipo>
bool ListaLinear<Tipo>::esta_ordenada()
{
    for (int index = 0; index <= tamanho; index++)
    {
        if (index < tamanho)
        {
            if (elementos[index + 1] < elementos[index])
            {
                return false;
            }
        }
    }

    return true;
}

template <typename Tipo>
Tipo ListaLinear<Tipo>::copiar_lista()
{
    ListaLinear<Tipo> lista_copiada = ListaLinear<Tipo>(tamanho);

    for (int index = 0; index < tamanho; index++)
    {
        lista_copiada.elementos[index] = elementos[index];
    }

    return lista_copiada;
}

template <typename Tipo>
Tipo ListaLinear<Tipo>::copiar_e_remover_elementos()
{
    ListaLinear<Tipo> nova_lista = ListaLinear<Tipo>(tamanho);

    for (int index = 0; index < tamanho; index++)
    {
        nova_lista.elementos[index] = elementos[index];
    }

    esvaziar_lista();

    return nova_lista;
}

template <typename Tipo>
void ListaLinear<Tipo>::printar_elementos()
{
    for (int elem = 0; elem < tamanho; elem++)
    {
        cout << elementos[elem] << " ";
    }
    cout << endl;
}

#endif // LISTALINEAR_H_INCLUDED