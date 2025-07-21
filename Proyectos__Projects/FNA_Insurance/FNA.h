#include <iostream>
#include <iomanip>

class SeguroFNA {
private:
    double ingresoAnual;
    int aniosJubilacion;
    double deudas;
    double gastosFuturos;
    double ahorros;

public:
    void setDatos(double ingreso, int anios, double deudas, double gastos, double ahorros) {
        ingresoAnual = ingreso;
        aniosJubilacion = anios;
        this->deudas = deudas;
        gastosFuturos = gastos;
        this->ahorros = ahorros;
    }

    double calcularCobertura() const {
        return (ingresoAnual * aniosJubilacion) + deudas + gastosFuturos - ahorros;
    }
};