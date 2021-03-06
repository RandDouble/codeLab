#include "dati.h"

using namespace std;


void leggiFile(ifstream*inf, dati* a){
    *inf>>a->time>>a->amp;
    
}

void initPunto(dati*arr){
    arr->time=0;
    arr->amp=0;
}

void stampa(ofstream*off, dati* el, int i){
    cout<<"\ndescrizine dati nr : "<<i+1<<endl;
    cout<<setw(10)<<el->time;
    cout<<setw(10)<<el->amp;
    (*off)<<setw(10)<<el->time;
    (*off)<<setw(10)<<el->amp<<endl;
}

void copia(dati*arr, dati source){
    arr->time=source.time;
    arr->amp=source.amp;

}