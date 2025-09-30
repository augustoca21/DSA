#include <iostream>
#include <vector>

using namespace std;

// Función para mezclar dos subarrays ordenados
void merge(vector<int>& arr, int left, int mid, int right) {
    // Tamaño de los subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Vectores temporales
    vector<int> L(n1), R(n2);

    // Copiamos los datos a los arrays temporales
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    // Mezclamos los arrays temporales de vuelta al original
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copiamos los elementos restantes (si hay)
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Función recursiva para dividir y ordenar el array
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar ambas mitades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mezclar ambas mitades ordenadas
        merge(arr, left, mid, right);
    }
}

// Función auxiliar para imprimir el array
void printArray(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// Ejemplo de uso
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    cout << "Array original: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Array ordenado: ";
    printArray(arr);
    return 0;
}
