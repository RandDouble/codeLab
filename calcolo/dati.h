#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct dati{
    float time;
    double amp;
};

//caricamento di un dati da file
void leggiFile(ifstream*inf, dati*pa);

//inizializza punti per mergesort
void initPunto(dati*arr);

//stampa a video e in file
void stampa(ofstream*off, dati* pa, int i);

//copia due punti in ogni loro caratteristica
void copia(dati*arrivo, dati source);