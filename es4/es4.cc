#include <iostream>
#include <fstream>
using namespace std;

// Funzione per unire due sotto-array ordinati
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Array temporanei
    int L[n1], R[n2];

    // Copia i dati nei sotto-array temporanei
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Indici iniziali dei due sotto-array
    int i = 0, j = 0;
    // Indice iniziale dell'array unito
    int k = left;

    // Unisci gli array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia i rimanenti elementi di L[], se presenti
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia i rimanenti elementi di R[], se presenti
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Funzione ricorsiva per implementare il Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordina la prima e la seconda metà
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Unisci le due metà
        merge(arr, left, mid, right);
    }
}

int main() {
    // Lettura da file
    ifstream in("input.txt");

    int n;
    in >> n;
    
    // Array da ordinare
    int a[n];
    
    // Riempimento dell'array
    for (int x = 0; x < n; x++) {
        in >> a[x];
    }

    // Chiudi il file di input
    in.close();

    // Ordina l'array usando Merge Sort
    mergeSort(a, 0, n - 1);

    // Scrivi l'array ordinato in output.txt
    ofstream out("output.txt");
    for (int x = 0; x < n; x++) {
        out << a[x] << " ";
    }
    out << "\n";
    
    // Chiudi il file di output
    out.close();

    return 0;
}
