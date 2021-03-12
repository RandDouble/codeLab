#include "arrayDati.h"
#include <cmath>

using namespace std;

//inversione dei valori in assoluti
void assoluto(arrayDati*dat);
//output per side effect di un vettore dotato di soli massimi
void massimo(arrayDati origin, arrayDati*out, const char type);
//funzione che cerca i massimi
bool isMax(dati* ver, int i, const char type);
