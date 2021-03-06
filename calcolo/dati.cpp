#include "dati.h"

using namespace std;


void leggiFile(ifstream*inf, dati* a){
    *inf>>a->time>>a->x>>a->v>>a->a;
    
}

void initPunto(dati*arr){
    arr->time=0;
    arr->x=0;
    arr->v=0;
    arr->a=0;
}

void stampa(ofstream*off, dati* el, int i){
    cout<<"\ndescrizine dati nr : "<<i+1<<endl;
    cout<<setw(10)<<el->time;
    cout<<setw(10)<<el->x;
    cout<<setw(10)<<el->v;
    cout<<setw(10)<<el->a;
    (*off)<<setw(10)<<el->time<<"\t";
    (*off)<<setw(10)<<el->x<<"\t";
    (*off)<<setw(10)<<el->v<<"\t";
    (*off)<<setw(10)<<el->a<<endl;
}

void copia(dati*arr, dati source){
    arr->time=source.time;
    arr->a=source.a;
    arr->x=source.x;
    arr->v=source.v;

}