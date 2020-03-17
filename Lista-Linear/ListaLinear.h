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
    void preencher();
    void esvaziar_lista();
    bool esta_ordenada();
    bool esta_vazia();
    bool esta_cheia();
    ListaLinear<Tipo> copiar_lista(ListaLinear<Tipo>);
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
void ListaLinear<Tipo>::preencher()
{
    indice = tamanho - 1;
}

template <typename Tipo>
void ListaLinear<Tipo>::esvaziar_lista()
{
    indice = -1;
}

template <typename Tipo>
bool ListaLinear<Tipo>::esta_vazia()
{
    if (indice != -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename Tipo>
bool ListaLinear<Tipo>::esta_cheia()
{
    if (indice == tamanho - 1)
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
    for (int index = 0; index <= indice; index++)
    {
        if (index < indice)
        {
            std::cout << elementos[index+1] << " e " << elementos[index] << endl;
            if (elementos[index + 1] < elementos[index])
            {
                return false;
            }
        }
    }

    return true;
}

template <typename Tipo>
ListaLinear<Tipo> ListaLinear<Tipo>::copiar_lista(ListaLinear<Tipo> lista_antiga)
{
    ListaLinear<Tipo> lista_copiada = ListaLinear<Tipo>(lista_antiga.tamanho);
    lista_copiada.indice = lista_antiga.indice;

    for (int index = 0; index < lista_antiga.tamanho; index++)
    {
        lista_copiada.elementos[index] = lista_antiga.elementos[index];
    }

    return lista_copiada;
}

template <typename Tipo>
void ListaLinear<Tipo>::printar_elementos()
{
    if (indice != -1)
    {
        for (int elem = 0; elem <= indice; elem++)
        {
            cout << elementos[elem] << " ";
        }
        cout << endl;
    }
    else
    {
        std::cout << "Lista vazia!" << endl;
    }
    
}

#endif // LISTALINEAR_H_INCLUDED
