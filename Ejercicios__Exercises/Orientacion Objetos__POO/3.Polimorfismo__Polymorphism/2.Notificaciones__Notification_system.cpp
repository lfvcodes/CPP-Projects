/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Ejercicio Práctico de Polimorfismo en C++: Sistema de Notificaciones
Este programa demuestra el polimorfismo en C++ a través de un sistema de notificaciones.
Utiliza una clase base abstracta 'Notificacion' y clases derivadas para diferentes
tipos de notificaciones (Email, SMS, Push), permitiendo enviar mensajes de forma uniforme
sin conocer el tipo específico de notificación en tiempo de compilación.

Practical C++ Polymorphism Exercise: Notification System
This program demonstrates polymorphism in C++ through a notification system.
It uses an abstract base class 'Notificacion' and derived classes for different
notification types (Email, SMS, Push), allowing messages to be sent uniformly
without knowing the specific notification type at compile-time.
*/

#include <iostream>  // Para entrada/salida (cout)
#include <vector>    // Para usar std::vector
#include <string>    // Para usar std::string

// Usamos el namespace std para no tener que escribir 'std::' repetidamente.
using namespace std;

// --- 1. Clase Base Abstracta: Notificacion ---
// Define la interfaz común para todos los tipos de notificaciones.
class Notificacion {
public:
    // Constructor con el mensaje que se va a enviar
    Notificacion(const string& mensaje) : _mensaje(mensaje) {}

    // Función virtual pura: Cada notificación DEBE implementar su propia forma de enviar.
    // Esto hace que Notificacion sea una clase abstracta.
    virtual void enviar() = 0;

    // Destructor virtual: Es CRUCIAL para liberar correctamente la memoria
    // cuando eliminamos objetos de clases derivadas a través de punteros de la clase base.
    virtual ~Notificacion() {
        cout << "Destructor de Notificacion base.\n";
    }

protected:
    string _mensaje; // El mensaje a notificar
};

// --- 2. Clases Derivadas Concretas ---

// Notificación de Email
class EmailNotificacion : public Notificacion {
public:
    EmailNotificacion(const string& destinatario, const string& mensaje)
        : Notificacion(mensaje), _destinatario(destinatario) {}

    // Implementación específica de 'enviar' para Email
    void enviar() override {
        cout << "Enviando Email a '" << _destinatario << "': '" << _mensaje << "'\n";
    }

    ~EmailNotificacion() override {
        cout << "Destructor de EmailNotificacion.\n";
    }

private:
    string _destinatario;
};

// Notificación de SMS
class SMSNotificacion : public Notificacion {
public:
    SMSNotificacion(const string& numeroTelefono, const string& mensaje)
        : Notificacion(mensaje), _numeroTelefono(numeroTelefono) {}

    // Implementación específica de 'enviar' para SMS
    void enviar() override {
        cout << "Enviando SMS al '" << _numeroTelefono << "': '" << _mensaje << "'\n";
    }

    ~SMSNotificacion() override {
        cout << "Destructor de SMSNotificacion.\n";
    }

private:
    string _numeroTelefono;
};

// Notificación Push
class PushNotificacion : public Notificacion {
public:
    PushNotificacion(const string& dispositivoID, const string& mensaje)
        : Notificacion(mensaje), _dispositivoID(dispositivoID) {}

    // Implementación específica de 'enviar' para Push
    void enviar() override {
        cout << "Enviando Push al dispositivo '" << _dispositivoID << "': '" << _mensaje << "'\n";
    }

    ~PushNotificacion() override {
        cout << "Destructor de PushNotificacion.\n";
    }

private:
    string _dispositivoID;
};

// --- 3. Función Principal (main) para Demostrar el Polimorfismo ---
int main() {
    // Creamos un vector de punteros a la clase base Notificacion.
    // Esto nos permite almacenar diferentes tipos de notificaciones en una sola colección.
    vector<Notificacion*> notificaciones;

    // Añadimos diferentes tipos de notificaciones al vector
    notificaciones.push_back(new EmailNotificacion("usuario@ejemplo.com", "¡Bienvenido a nuestra app!"));
    notificaciones.push_back(new SMSNotificacion("+1234567890", "Tu código de verificación es 8765."));
    notificaciones.push_back(new PushNotificacion("abc123def456", "Nueva oferta disponible: ¡50% de descuento!"));
    notificaciones.push_back(new EmailNotificacion("admin@ejemplo.com", "Reporte semanal generado."));

    cout << "--- Iniciando envío de Notificaciones ---\n";

    // Recorremos el vector y llamamos a 'enviar()' polimórficamente.
    // En cada iteración, se invocará la versión correcta de 'enviar()'
    // (EmailNotificacion::enviar, SMSNotificacion::enviar, etc.)
    // basada en el tipo real del objeto al que apunta 'notificacionActual'.
    for (Notificacion* notificacionActual : notificaciones) {
        notificacionActual->enviar();
    }

    cout << "--- Notificaciones enviadas. Liberando memoria ---\n";

    // Muy importante: Liberar la memoria asignada dinámicamente.
    // Gracias al destructor virtual en la clase base, se llamarán correctamente
    // los destructores de las clases derivadas y luego el de la base.
    for (Notificacion* notificacionActual : notificaciones) {
        delete notificacionActual;
    }

    // Opcional: Limpiar el vector de punteros después de eliminar los objetos.
    notificaciones.clear();

    cout << "--- Fin del programa ---\n";

    return 0;
}