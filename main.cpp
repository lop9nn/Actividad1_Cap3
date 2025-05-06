#include <iostream>
using namespace std;

class AcumuladorDeNumeros {
    int numeros[10];
    int cantidad = 0;

public:
    void agregarNumero(int valor) {
        if (cantidad < 10) {
            numeros[cantidad++] = valor;
        } else {
            cout << "No se pueden agregar m�s n�meros (l�mite alcanzado)" << endl;
}}
    int obtenerSuma() const {
        int suma = 0;
        for (int i = 0; i < cantidad; ++i) {
            suma += numeros[i];
        }
        return suma;}
    double obtenerPromedio() const {
        return cantidad == 0 ? 0.0 : static_cast<double>(obtenerSuma()) / cantidad;}
    int obtenerCantidad() const {
        return cantidad;
    }
};
int obtenerCantidadDeNumeros() {
    int totalNumeros;
    cout << "�Cu�ntos n�meros ingresar� (m�ximo 10)? ";
    cin >> totalNumeros;
    if (totalNumeros > 10) {
        cout << "Solo se permiten hasta 10 n�meros" << endl;
        totalNumeros = 10;
    }
    return totalNumeros;
}
// Funci�n para gestionar la entrada de n�meros
void ingresarNumeros(AcumuladorDeNumeros &acumulador, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        cout << "N�mero: ";
        int numero;
        cin >> numero;
        acumulador.agregarNumero(numero);
    }
}

int main() {
    system("chcp 65001 > nul"); // Para usar caracteres especiales en la consola

    AcumuladorDeNumeros acumulador;
    int cantidadNumeros = obtenerCantidadDeNumeros();

    ingresarNumeros(acumulador, cantidadNumeros);

    cout << "Suma = " << acumulador.obtenerSuma() << '\n';
    cout << "Promedio = " << acumulador.obtenerPromedio() << '\n';

    return 0;
}
