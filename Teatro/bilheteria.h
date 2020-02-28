#ifndef BILHETERIA_H_INCLUDED
#define BILHETERIA_H_INCLUDED
#include "teatro.h"


struct Bilheteria
{
    bool realizar_compra(Lugar lugar_a_comprar, int id_pessoa){
        if(lugar_a_comprar.getLugarOcupado() == true){
            return false;
        }

        else{
            lugar_a_comprar.setIdCompra(id_pessoa);
            lugar_a_comprar.setLugarComprado();

            return true;
        }
    }

    bool realizar_devolucao(Lugar lugar_a_devolver, int pessoa){
        if (lugar_a_devolver.getIdCompra() == pessoa){
            lugar_a_devolver.vagarLugar();

            return true;
        }
        else{
            return false;
        }
    }

    bool realizar_troca(Lugar lugar_a_trocar, Lugar lugar_desejado, int pessoa){
        if (lugar_desejado.getLugarOcupado() == false){
            
            lugar_a_trocar.vagarLugar();

            lugar_desejado.setIdCompra(pessoa);
            lugar_desejado.setLugarComprado();

            return true;
        }
        else
        {
            return false;
        }
        
    }

};


#endif // BILHETERIA_H_INCLUDED
