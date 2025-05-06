
#include <iostream>
using namespace std;

class AcumuladorNumeros {
    int numeros[10];
    int cantidad = 0;

public:
    void agregarNumero(int valor) {
        if (cantidad < 10) {
            numeros[cantidad++] = valor;
        } else {
            cout << "No se pueden agregar mas numeros (límite alcanzado).\n";
        }
    }

    int obtenerSuma() {
        int suma = 0;
        for (int i = 0; i < cantidad; ++i) {
            suma += numeros[i];
        }
        return suma;
    }

    double obtenerPromedio() {
        return cantidad == 0 ? 0.0 : static_cast<double>(obtenerSuma()) / cantidad;
    }
};

int main() {
    // Solo para usuarios de Windows: cambiar codificación de la consola a UTF-8
    system("chcp 65001 > nul");

    AcumuladorNumeros acumulador;
    int totalNumeros;

    cout << "Cuantos numeros ingresara: "<<endl;
    cin >> totalNumeros;

    if (totalNumeros > 10) {
        cout << "Solo se permiten hasta 10 numeros"<<endl;
        totalNumeros = 10;
    }

    for (int i = 0; i < totalNumeros; ++i) {
        cout << "Numero: ";
        int numero;
        cin >> numero;
        acumulador.agregarNumero(numero);
    }

    cout << "Suma = " << acumulador.obtenerSuma() << '\n';
    cout << "Promedio = " << acumulador.obtenerPromedio() << '\n';

    return 0;
}
