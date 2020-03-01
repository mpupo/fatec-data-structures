#ifndef BILHETERIA_H_INCLUDED
#define BILHETERIA_H_INCLUDED
#include "teatro.h"


struct Bilheteria
{
    bool realizar_compra(Teatro teatro,Lugar lugar_a_comprar, int id_pessoa){
        Lugar* lugares = teatro.getLugares();
        for (int lugar = 0; lugar< teatro.num_lugares_total; ++lugar){
            if (lugares[lugar].getLugarId() == lugar_a_comprar.getLugarId()){
                if(lugares[lugar].getLugarOcupado() == true){
                    return false;
                }
                else{
                    lugar_a_comprar.setIdCompra(id_pessoa);
                    lugar_a_comprar.setLugarComprado();
                    lugares[lugar] = lugar_a_comprar;

                    return true;
                }
            }
            else
            {
                continue;
            }
        }
    }

    bool realizar_devolucao(Teatro teatro,Lugar lugar_a_devolver, int pessoa){
        Lugar* lugares = teatro.getLugares();

        if (lugar_a_devolver.getIdCompra() == pessoa){
            lugar_a_devolver.vagarLugar();

            for(int lugar = 0; lugar<teatro.num_lugares_total; ++lugar){
                if(lugares[lugar].getLugarId() == lugar_a_devolver.getLugarId()){
                    lugares[lugar] = lugar_a_devolver;
                }
                else
                {
                    continue;
                }
                
            }

            return true;
        }
        else{
            return false;
        }
    }

    bool realizar_troca(Teatro teatro, Lugar lugar_a_trocar, Lugar lugar_desejado, int pessoa){
        Lugar* lugares = teatro.getLugares();
        if (lugar_desejado.getLugarOcupado() == false){
            
            lugar_a_trocar.vagarLugar();

            lugar_desejado.setIdCompra(pessoa);
            lugar_desejado.setLugarComprado();

            for(int lugar = 0; lugar<teatro.num_lugares_total; ++lugar){
                if (lugares[lugar].getLugarId() == lugar_a_trocar.getLugarId()){
                    lugares[lugar] = lugar_a_trocar;
                }
                else if(lugares[lugar].getLugarId() == lugar_desejado.getLugarId()){
                    lugares[lugar] = lugar_desejado;
                }

                else
                {
                    continue;
                }
                
            }
            return true;
        }
        else
        {
            return false;
        }
        
    }

};


#endif // BILHETERIA_H_INCLUDED
