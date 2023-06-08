#include<string>
#include<vector>
#include "PersonaMax.hpp"

int main(){
    vector<Persona*> personas;
    Persona p1;

    personas.push_back(&p1);

    p1.escribirPersona();
    p1.leerPersona();
    p1.escribirPersona();
}