#ifndef TEATRO_H_INCLUDED
#define TEATRO_H_INCLUDED

struct Lugar {
    int id;
    int id_compra;
    bool ocupado;
    int id_evento;

    Lugar(int id_lugar){
        id = id_lugar;
        ocupado = false;
    }
};

struct Teatro
{
    Lugar lugares_bilheteria[100];           // Lugares disponíveis para venda de ingressos.
    const int qtd_pessoas_apoio = 10;      // Quantidade de funcionários do teatro.
    const int limite_qtd_pessoas = 110;    // Limite de pessoas no teatro (público+func).
    int lugares_comprados = 0;

    Teatro(){
        for(int num_lugar; num_lugar < sizeof(lugares_bilheteria); num_lugar++)
        {
            lugares_bilheteria[num_lugar] = Lugar(num_lugar);
        }
    }

    int getLugaresLivres(){
        int lugares_livres [limite_qtd_pessoas-qtd_pessoas_apoio];

        for(int num_lugar = 0; num_lugar < sizeof(lugares_bilheteria); num_lugar++)
        {
            if (lugares_bilheteria[num_lugar].ocupado == true)
            {
                continue;
            }
            else
            {
                lugares_livres[num_lugar] = lugares_bilheteria[num_lugar];
            }
        }

        return lugares_livres;
    }

    void getLugaresOcupados(){
        int lugares_ocupados [limite_qtd_pessoas-qtd_pessoas_apoio];
        
        for(int num_lugar = 0; num_lugar < sizeof(lugares_bilheteria); num_lugar++)
        {
            if (lugares_bilheteria[num_lugar].ocupado == false)
            {
                continue;
            }
            else
            {
                lugares_ocupados[num_lugar] = lugares_bilheteria[num_lugar];
            }
        }

        return lugares_ocupados;
    }

    int getTotalDeLugaresComprados(){
        return lugares_comprados;
    }

};


#endif // TEATRO_H_INCLUDED