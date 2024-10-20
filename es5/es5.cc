//intervalli scoperti

#include <iostream>
#include <fstream>
using namespace std;

struct libero {
    int start;
    int stop;
    int duration;
    libero* next;
};

void aggiungi(libero*& head, libero* nuovo) {
    if (head == nullptr) {
        head = nuovo;
    } else {
        libero* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nuovo;
    }
}

void scorri(int start[], int stop[], int n, libero* l) {
    for (int i = 0; i < n; i++) {
        libero* inizio = new libero();
        inizio->start = 0;
        inizio->stop = start[i]-1;
        inizio->duration = inizio->stop - inizio->start;
        inizio->next = nullptr;
    }
}



int main() {
    // Lettura da file
    ifstream in("input.txt");

    int n;
    in >> n;
    
    // Array da ordinare
    int start[n],stop[n];
    
    int temp;
    // Riempimento dell'array
    for (int x = 0; x < n; x++) {
        in >> start[x] >> stop[x];
    }

    libero l=new libero();

    return 0;

}
