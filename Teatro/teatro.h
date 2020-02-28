#ifndef TEATRO_H_INCLUDED
#define TEATRO_H_INCLUDED
#include <string>

struct Lugar {
    int id;
    int id_compra;
    bool ocupado;

    Lugar(){
        ocupado = false;
    }

    Lugar(int id_lugar){
        id = id_lugar;
        ocupado = false;
    }

    int getLugarId(){
        return id;
    }

    int getIdCompra(){
        return id_compra;
    }

    bool getLugarOcupado(){
        return ocupado;
    }

    void setLugarComprado(){
        ocupado = true;
    }

    void vagarLugar(){
        ocupado = false;
        id_compra = 0;
    }

    void setIdCompra(int id){
        id_compra = id;
    }
};

struct Teatro
{
    Lugar* lugares_bilheteria = NULL;           // Lugares disponíveis para venda de ingressos.
    int qtd_pessoas_apoio = 10;      // Quantidade de funcionários do teatro.
    int limite_qtd_pessoas_total;    // Limite de pessoas no teatro (público+func).
    int lugares_comprados = 0;
    int num_lugares_total;

    Teatro(int num_lugares){
        lugares_bilheteria = new Lugar[num_lugares];
        limite_qtd_pessoas_total = num_lugares + qtd_pessoas_apoio;
        num_lugares_total = num_lugares;

        for(int num_lugar; num_lugar < sizeof(lugares_bilheteria); num_lugar++)
        {
            lugares_bilheteria[num_lugar] = Lugar(num_lugar);
        }
    }

    int* getLugaresLivres(){
        int lugares_livres[num_lugares_total]; // Lista de lugares disponíveis no momento

        for(int num_lugar = 0; num_lugar < sizeof(lugares_bilheteria); num_lugar++)
        {
            if (lugares_bilheteria[num_lugar].getLugarOcupado() == true)
            {
                continue;
            }
            else
            {
                lugares_livres[num_lugar] = lugares_bilheteria[num_lugar].getLugarId();
            }
        }

        return lugares_livres;
    }

    int* getLugaresOcupados(){
        int lugares_ocupados [num_lugares_total];
        
        for(int num_lugar = 0; num_lugar < sizeof(lugares_bilheteria); num_lugar++)
        {
            if (lugares_bilheteria[num_lugar].getLugarOcupado() == false)
            {
                continue;
            }
            else
            {
                lugares_ocupados[num_lugar] = lugares_bilheteria[num_lugar].getLugarId();
            }
        }

        return lugares_ocupados;
    }

    int getTotalDeLugaresComprados(){
        return lugares_comprados;
    }

    Lugar getLugar(int num_lugar){
        if (num_lugar > num_lugares_total || num_lugar <= 0){

        }
        return lugares_bilheteria[num_lugar];
    }

    bool verificarPropriedade(int num_lugar, int pessoa){
        Lugar lugar_inspecionado = lugares_bilheteria[num_lugar];

        if (lugar_inspecionado.getIdCompra() != pessoa){
            return false;
        }
        else
        {
            return true;
        }
        
    }

    void contCompra(){
        lugares_comprados++;
    }

    void contDevolucao(){
        lugares_comprados--;
    }
};


#endif // TEATRO_H_INCLUDED