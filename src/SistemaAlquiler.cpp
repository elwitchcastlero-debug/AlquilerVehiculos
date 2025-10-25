#include <iostream>
#include <vector>
#include <memory>
#include "Vehiculo.h"
using namespace std;

class Alquiler {
    vector<unique_ptr<Vehiculo>> vehiculos;

public:
    void Registrar(unique_ptr<Vehiculo> v) {
        for (const auto& vehiculo : vehiculos) {
            if (vehiculo->getPlaca() == v->getPlaca()) {
                cout << "Error: Ya existe un vehículo con la placa " << v->getPlaca() << endl;
                return;
            }
        }
        vehiculos.push_back(move(v));
    }

    void Alquilar(const string& placa) {
        for (auto& v : vehiculos) {
            if (v->getPlaca() == placa) {
                if (v->estaDisponible()) {
                    v->setDisponibilidad(false);
                    cout << "Vehículo alquilado con éxito.\n";
                } else {
                    cout << "El vehículo no está disponible.\n";
                }
                return;
            }
        }
        cout << "Vehículo no encontrado.\n";
    }

    void Devolver(const string& placa) {
        for (auto& v : vehiculos) {
            if (v->getPlaca() == placa) {
                v->setDisponibilidad(true);
                cout << "Vehículo devuelto con éxito.\n";
                return;
            }
        }
        cout << "Vehículo no encontrado.\n";
    }

    void MostrarDisponibles() const {
        cout << "\nVehículos disponibles:\n";
        bool hayDisponibles = false;
        for (const auto& v : vehiculos) {
            if (v->estaDisponible()) {
                v->mostrarInfo();
                hayDisponibles = true;
            }
        }
        if (!hayDisponibles) {
            cout << "No hay vehículos disponibles.\n";
        }
    }
};

int main() {
    Alquiler sistema;

    sistema.Registrar(make_unique<Auto>("Toyota", "Corolla", "ABC123", 4, 500, 5, 180, true));
    sistema.Registrar(make_unique<Bicicleta>("Giant", "Escape 3", "BIKE01", 28, 35, "Disco", 12.5, true));

    sistema.MostrarDisponibles();
    sistema.Alquilar("ABC123");
    sistema.MostrarDisponibles();
    sistema.Devolver("ABC123");
    sistema.MostrarDisponibles();
    sistema.Alquilar("DEF456");

    return 0;
}





