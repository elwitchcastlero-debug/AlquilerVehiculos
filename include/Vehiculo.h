#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <vector>
#include <iostream>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    std::string placa;
    bool estado; // true = disponible, false = alquilado

public:
    Vehiculo(std::string mrc, std::string mdl, std::string plc, bool est = true);

    virtual void mostrarInfo() const;
    virtual std::string getPlaca() const; // Virtual para polimorfismo
    virtual bool estaDisponible() const;
    virtual void setDisponibilidad(bool est);

    virtual ~Vehiculo() = default; 
};

class Auto : public Vehiculo {
    int numPuertas;
    int capacidadMaletero;
    int numAsientos;
    int velocidadMaxima;
    bool automatico;

public:
    Auto(std::string mrc, std::string mdl, std::string plc, int np, int cm, int na, int vm, bool aut);
    void mostrarInfo() const override;

   
    std::vector<std::string> infoAuto() const;
};

class Bicicleta : public Vehiculo {
    int tamanoRuedas;
    int velocidadMaxima;
    std::string tipoFreno;
    double peso;
    bool cambio;

public:
    Bicicleta(std::string mrc, std::string mdl, std::string plc, int tr, int vm, std::string tf, double ps, bool tc);
    void mostrarInfo() const override;

    std::vector<std::string> infoBicicleta() const;
};

#endif 