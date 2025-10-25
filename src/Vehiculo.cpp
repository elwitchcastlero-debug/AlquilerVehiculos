#include "Vehiculo.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// --- Vehiculo ---
Vehiculo::Vehiculo(string mrc, string mdl, string plc, bool est)
    : marca(mrc), modelo(mdl), placa(plc), estado(est) {}

void Vehiculo::mostrarInfo() const {
    cout << "Marca: " << marca << ", Modelo: " << modelo << ", Placa: " << placa
         << ", Estado: " << (estado ? "Disponible" : "No disponible") << endl;
}

string Vehiculo::getPlaca() const {
    return placa;
}

bool Vehiculo::estaDisponible() const {
    return estado;
}

void Vehiculo::setDisponibilidad(bool est) {
    estado = est;
}

// --- Auto ---
Auto::Auto(string mrc, string mdl, string plc, int np, int cm, int na, int vm, bool aut)
    : Vehiculo(mrc, mdl, plc), numPuertas(np), capacidadMaletero(cm),
      numAsientos(na), velocidadMaxima(vm), automatico(aut) {}

void Auto::mostrarInfo() const {
    cout << "Auto - Marca: " << marca << ", Modelo: " << modelo << ", Placa: " << placa
         << ", Puertas: " << numPuertas << ", Maletero: " << capacidadMaletero
         << "L, Asientos: " << numAsientos << ", Vel. Máx: " << velocidadMaxima
         << " km/h, " << (automatico ? "Automático" : "Manual")
         << ", Estado: " << (estado ? "Disponible" : "No disponible") << endl;
}

vector<string> Auto::infoAuto() const {
    vector<string> info;
    info.push_back("Marca: " + marca);
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

string Auto::getPlaca() const {
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
    cout << "Bicicleta - Marca: " << marca << ", Modelo: " << modelo << ", Placa: " << placa
         << ", Ruedas: " << tamanoRuedas << " pulgadas, Vel. Máx: " << velocidadMaxima
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
    return placa;
}

bool Bicicleta::estaDisponible() const {
    return estado;
}

void Bicicleta::setDisponibilidad(bool est) {
    estado = est;
}