#include <iostream>

using namespace std;

//definisco le funzioni
float Tastiera_base();
float Tastiera_altezza();
float Tastiera_lato();
float perimetro(float base, float altezza);
float area(float base, float altezza);

int main() {
    //creo le variabili
    float base, altezza;

    //chiedo la dimensione dei lati
    base = Tastiera_lato(); // Tastiera_base();
    altezza = Tastiera_lato(); // Tastiera_altezza();

    //calcolo il perimetro e l'area
    float p = perimetro(base, altezza);
    float a = area(base, altezza);

    //stampo il risultato
    cout << "Perimetro: " << p << endl;
    cout<<"Area: "<<a<<endl;

    //fine
    return 0;
}

//funzione per inserire la base
float Tastiera_base(){
    float base;
    cout<<"Inserisci la base: ";
    cin>>base;
    return base;
}

//funzione per inserire l'altezza
float Tastiera_altezza(){
    float base;
    cout<<"Inserisci l'altezza': ";
    cin>>base;
    return base;
}

//funzione per inserire il lato 
//(alternativo all'utilizzo di due metodi distinti per base e altezza)
float Tastiera_lato() {
    float lato;
    cout << "Inserisci il lato: ";
    cin >> lato;
    return lato;
}

//funzione per calcolare il perimetro
float perimetro(float base, float altezza) {
    float p=2*(base+altezza);
    return p;
}

//funzione per calcolare l'area
float area(float base, float altezza) {
    float a=base*altezza;
    return a;
}

