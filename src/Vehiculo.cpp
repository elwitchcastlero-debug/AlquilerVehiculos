#include "Vehiculo.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// nuevamente la clase y elementos solo se definen en el archivo .h para mayor facilidad de compilación
// --- Vehiculo ---
Vehiculo::Vehiculo(string mrc, string mdl, string plc, bool est)
    : marca(mrc), modelo(mdl), placa(plc), estado(est) {}

void Vehiculo::mostrarInfo() const {                         //muestra informaciín caracteristica de vehiculo
    cout << "Marca: " << marca << ", Modelo: " << modelo << ", Placa: " << placa
         << ", Estado: " << (estado ? "Disponible" : "No disponible") << endl;
}

string Vehiculo::getPlaca() const {                     //retorna la placa
    return placa;
}

bool Vehiculo::estaDisponible() const {                   //retorna el estado del vehiculo, si está alquilado o no
    return estado;
}

void Vehiculo::setDisponibilidad(bool est) {          //para poder cambiar el estado actual del auto para realizar los prestamos
    estado = est;
}

// --- Auto ---
Auto::Auto(string mrc, string mdl, string plc, int np, int cm, int na, int vm, bool aut)
    : Vehiculo(mrc, mdl, plc), numPuertas(np), capacidadMaletero(cm),
      numAsientos(na), velocidadMaxima(vm), automatico(aut) {}

void Auto::mostrarInfo() const {                                                         //para mostrar información exclusiva de un auto de la que se digita
    cout << "Auto - Marca: " << marca << ", Modelo: " << modelo << ", Placa: " << placa
         << ", Puertas: " << numPuertas << ", Maletero: " << capacidadMaletero
         << "L, Asientos: " << numAsientos << ", Vel. Máx: " << velocidadMaxima
         << " km/h, " << (automatico ? "Automático" : "Manual")
         << ", Estado: " << (estado ? "Disponible" : "No disponible") << endl;
}

vector<string> Auto::infoAuto() const {                                                //para guardar la información del auto en un vector
    vector<string> info;                                                               //en el vector va toda la información del auto
    info.push_back("Marca: " + marca);                                                 //nuestro auto completo es el vector
    info.push_back("Modelo: " + modelo);
    info.push_back("Placa: " + getPlaca()); // Usar getter para consistencia
    info.push_back("Número de puertas: " + to_string(numPuertas));
    info.push_back("Capacidad del maletero: " + to_string(capacidadMaletero));
    info.push_back("Número de asientos: " + to_string(numAsientos));
    info.push_back("Velocidad máxima: " + to_string(velocidadMaxima));
    info.push_back(automatico ? "Automático" : "Manual");
    info.push_back(estaDisponible() ? "Disponible" : "No disponible"); // Usar getter
    return info;
}

string Auto::getPlaca() const {                        //repetimos lo escrito en la clase padre para evitar errores por falta de datos
    return placa;
}

bool Auto::estaDisponible() const {
    return estado;
}

void Auto::setDisponibilidad(bool est) {
    estado = est;
}

// --- Bicicleta ---
Bicicleta::Bicicleta(string mrc, string mdl, string plc, int tr, int vm, string tf, double ps, bool tc)
    : Vehiculo(mrc, mdl, plc), tamanoRuedas(tr), velocidadMaxima(vm),
      tipoFreno(tf), peso(ps), cambio(tc) {}

void Bicicleta::mostrarInfo() const {
    cout << "Bicicleta - Marca: " << marca << ", Modelo: " << modelo << ", Placa: " << placa   //mismo proceso para las bicicletas pero con sus respectivos
         << ", Ruedas: " << tamanoRuedas << " pulgadas, Vel. Máx: " << velocidadMaxima         //parametros
         << " km/h, Freno: " << tipoFreno << ", Peso: " << peso << " kg, "
         << (cambio ? "Con cambios" : "Sin cambios")
         << ", Estado: " << (estado ? "Disponible" : "No disponible") << endl;
}

vector<string> Bicicleta::infoBicicleta() const {
    vector<string> info;
    info.push_back("Marca: " + marca);
    info.push_back("Modelo: " + modelo);
    info.push_back("Placa: " + getPlaca()); // Usar getter
    info.push_back("Tamaño de ruedas: " + to_string(tamanoRuedas));
    info.push_back("Velocidad máxima: " + to_string(velocidadMaxima));
    info.push_back("Tipo de freno: " + tipoFreno);
    info.push_back("Peso: " + to_string(peso));
    info.push_back(cambio ? "Con cambios" : "Sin cambios");
    info.push_back(estaDisponible() ? "Disponible" : "No disponible"); // Usar getter
    return info;
}

string Bicicleta::getPlaca() const {
    return placa;                                                 //aplicamos los mismos metodos para las mismas variables en comun al nosotros 
} 
                                                                  //necesitar la placa, el estado y la posibilidad de cambiar este ultimo para poder alquilar
bool Bicicleta::estaDisponible() const {                          //tanto autos como bicicletas
    return estado;
}

void Bicicleta::setDisponibilidad(bool est) {
    estado = est;
}
