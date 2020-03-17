#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED
#define PI 3.14

#include <iostream>

using namespace std;

class Cilindro
{
    static int cont;
    int id;
    float raio;
    float altura;
    float volume;

public:
    Cilindro();
    Cilindro(float r, float a);
    void contar_cilindro();
    void printar_valores();
};
int Cilindro::cont = 1;

Cilindro::Cilindro(){

}

Cilindro::Cilindro(float r, float a){
    id = cont++;
    raio = r;
    altura = a;
    volume = PI * (raio * raio) * altura;
}

void Cilindro::printar_valores()
{
    std::cout << "Cilindro ID: " << id << " | ";
    std::cout << "Altura: " << altura << " | ";
    std::cout << "Volume: " << volume << " | ";
    std::cout << "Raio: " << raio << endl;

}

#endif // CILINDRO_H_INCLUDED
