#include <iostream>
#include <vector>
#include <memory>
#include "Vehiculo.h"
using namespace std;

class Alquiler {
    vector<unique_ptr<Vehiculo>> vehiculos;

public:
    void Registrar(unique_ptr<Vehiculo> v) {                              //para ingresar un nuevo vehiculo al inventario para estar disponible para alquilar        
        for (const auto& vehiculo : vehiculos) {                          //aplicamos constant al necesitar flexibilidad para manejar el codigo, no genera problemas al bicicletas y autos tener placas
            if (vehiculo->getPlaca() == v->getPlaca()) {                  //es importante revisar que las placas no esten duplicadas, el tener una placa duplicada puede generar problemas legales
                cout << "Error: Ya existe un vehículo con la placa " << v->getPlaca() << endl;
                return;
            }
        }
        vehiculos.push_back(move(v));                              //añade el nuevo vehiculo dependiendo si es auto o bicicleta a su respectiva familia
    }

    void Alquilar(const string& placa) {                          //para realizar el alquiler del vehiculo(flexibilidad con const al todos los tipos de vehiculos tener placa
        for (auto& v : vehiculos) {                               //recorre todos los autos o bicicletas en poseción del negocio de alquiler
            if (v->getPlaca() == placa) {                         //hace la busqueda del auto querido mediante el valor unico de los vehiculos, sus placas para ver si se tiene el vehiculo
                if (v->estaDisponible()) {                        //revisa si el vehiculo está disponible o no para prestar
                    v->setDisponibilidad(false);                  //si se puede alquitar se cambia su estado a false al ya estar alquilado
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
        for (auto& v : vehiculos) {                          //el mismo proceso para alquilar pero al ser devuelto ahora su estado cambia a true al ya poderse alquilar a alguien mas
            if (v->getPlaca() == placa) {                           
                v->setDisponibilidad(true);
                cout << "Vehículo devuelto con éxito.\n";
                return;
            }
        }
        cout << "Vehículo no encontrado.\n";
    }

    void MostrarDisponibles() const {                           //mostrar al cliente que autos hay disponibles para su gusto
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

int main() {          //main para probar
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





