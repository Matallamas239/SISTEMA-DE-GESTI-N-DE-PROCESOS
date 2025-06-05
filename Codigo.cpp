

#include <iostream>
#include <string>
using namespace std;

// Estructura de nodo para pila y cola
struct Nodo {
    int id;
    string nombre;
    Nodo* siguiente;
};

// Declaración de punteros para pila y cola
Nodo* tope = NULL;      // Pila (memoria)
Nodo* frente = NULL;    // Cola (inicio)
Nodo* final = NULL;     // Cola (fin)

// -------------------- PILA --------------------

// Insertar en pila (LIFO)
void ingresarPila() {
    Nodo* nuevo = new Nodo();
    cout << "Ingrese ID: ";
    cin >> nuevo->id;
    cout << "Ingrese Nombre: ";
    cin >> nuevo->nombre;
    nuevo->siguiente = tope;
    tope = nuevo;
    cout << "Elemento ingresado a la pila.\n";
}

// Buscar en pila
void buscarPila() {
    int idBuscado;
    cout << "Ingrese ID a buscar en la pila: ";
    cin >> idBuscado;
    Nodo* aux = tope;
    bool encontrado = false;
    while (aux != NULL) {
        if (aux->id == idBuscado) {
            cout << "Proceso encontrado: " << aux->nombre << endl;
            encontrado = true;
            break;
        }
        aux = aux->siguiente;
    }
    if (!encontrado)
        cout << "ID no encontrado en la pila.\n";
}

// Actualizar en pila
void actualizarPila() {
    int idBuscado;
    cout << "Ingrese ID a actualizar en la pila: ";
    cin >> idBuscado;
    Nodo* aux = tope;
    bool encontrado = false;
    while (aux != NULL) {
        if (aux->id == idBuscado) {
            cout << "Nuevo nombre: ";
            cin >> aux->nombre;
            encontrado = true;
            break;
        }
        aux = aux->siguiente;
    }
    if (encontrado)
        cout << "Elemento actualizado en la pila.\n";
    else
        cout << "ID no encontrado en la pila.\n";
}

// Procesar pila (LIFO)
void procesarPila() {
    if (tope == NULL) {
        cout << "La pila esta vacia. No hay procesos por procesar.\n";
        return;
    }

    cout << "Procesando datos en la pila:\n";
    while (tope != NULL) {
        cout << "Procesando ID: " << tope->id << ", Nombre: " << tope->nombre << endl;
        Nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
    cout << "Todos los procesos de la pila fueron procesados y eliminados.\n";
}

// -------------------- COLA --------------------

// Insertar en cola (FIFO)
void ingresarCola() {
    Nodo* nuevo = new Nodo();
    cout << "Ingrese ID: ";
    cin >> nuevo->id;
    cout << "Ingrese Nombre: ";
    cin >> nuevo->nombre;
    nuevo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
    cout << "Elemento ingresado a la cola.\n";
}

// Buscar en cola
void buscarCola() {
    int idBuscado;
    cout << "Ingrese ID a buscar en la cola: ";
    cin >> idBuscado;
    Nodo* aux = frente;
    bool encontrado = false;
    while (aux != NULL) {
        if (aux->id == idBuscado) {
            cout << "Proceso encontrado: " << aux->nombre << endl;
            encontrado = true;
            break;
        }
        aux = aux->siguiente;
    }
    if (!encontrado)
        cout << "ID no encontrado en la cola.\n";
}

// Actualizar en cola
void actualizarCola() {
    int idBuscado;
    cout << "Ingrese ID a actualizar en la cola: ";
    cin >> idBuscado;
    Nodo* aux = frente;
    bool encontrado = false;
    while (aux != NULL) {
        if (aux->id == idBuscado) {
            cout << "Nuevo nombre: ";
            cin >> aux->nombre;
            encontrado = true;
            break;
        }
        aux = aux->siguiente;
    }
    if (encontrado)
        cout << "Elemento actualizado en la cola.\n";
    else
        cout << "ID no encontrado en la cola.\n";
}

// Procesar cola (FIFO)
void procesarCola() {
    if (frente == NULL) {
        cout << "La cola esta vacia. No hay procesos por procesar.\n";
        return;
    }

    cout << "Procesando datos en la cola:\n";
    while (frente != NULL) {
        cout << "Procesando ID: " << frente->id << ", Nombre: " << frente->nombre << endl;
        Nodo* temp = frente;
        frente = frente->siguiente;
        delete temp;
    }
    final = NULL;
    cout << "Todos los procesos de la cola fueron procesados y eliminados.\n";
}

// -------------------- MENÚ PRINCIPAL --------------------

int main() {
    int opcion;
    do {
        cout << "\nMENU PRINCIPAL\n";
        cout << "1. Ingresar proceso a pila\n";
        cout << "2. Ingresar proceso a cola\n";
        cout << "3. Buscar proceso en pila\n";
        cout << "4. Buscar proceso en cola\n";
        cout << "5. Actualizar proceso en pila\n";
        cout << "6. Actualizar proceso en cola\n";
        cout << "7. Procesar datos de la pila\n";
        cout << "8. Procesar datos de la cola\n";
        cout << "9. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: ingresarPila(); break;
            case 2: ingresarCola(); break;
            case 3: buscarPila(); break;
            case 4: buscarCola(); break;
            case 5: actualizarPila(); break;
            case 6: actualizarCola(); break;
            case 7: procesarPila(); break;
            case 8: procesarCola(); break;
            case 9: cout << "Saliendo...\n"; break;
            default: cout << "Opcion no valida\n";
        }
    } while (opcion != 9);

    return 0;
}
