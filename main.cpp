#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // Para generar la lista ordenada
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// Función para ordenar una lista utilizando el algoritmo de burbuja
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break; // Si no hubo intercambios en esta pasada, la lista está ordenada
        }
    }
}

int main() {
    int n = 1000; // Tamaño de la lista

    // Generar una lista ordenada de menor a mayor (mejor caso)
    vector<int> mejorCaso(n);
    for (int i = 0; i < n; i++) {
        mejorCaso[i] = i + 1;
    }

    // Generar una lista ordenada de mayor a menor (peor caso)
    vector<int> peorCaso(n);
    for (int i = 0; i < n; i++) {
        peorCaso[i] = n - i;
    }

    cout << "Ingrese un número para buscar en las listas: ";
    int numero;
    cin >> numero;

    // Medir el tiempo de ejecución en el mejor caso
    auto start = high_resolution_clock::now();
    bubbleSort(mejorCaso);
    auto stop = high_resolution_clock::now();
    auto mejorCasoTime = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo en el mejor caso: " << mejorCasoTime.count() << " milisegundos" << endl;

    // Medir el tiempo de ejecución en el peor caso
    start = high_resolution_clock::now();
    bubbleSort(peorCaso);
    stop = high_resolution_clock::now();
    auto peorCasoTime = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo en el peor caso: " << peorCasoTime.count() << " milisegundos" << endl;

    return 0;
}


