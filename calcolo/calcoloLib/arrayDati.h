#include "dati.h"
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;

struct arrayDati{
    int size, used;
    dati*raw;
};


#define INIT_SIZE 20

//Initialize to array of size dim
int init(arrayDati *pa, int dim);

//inizializza vettore normalmente da file
int init(arrayDati *pa, string fileName);

//Resize of Array
//Parameters: 
//--pa: reference to instance to modify
//--newS: new size 
int resize(arrayDati *pa, int newS);

//Same as resize, but with block copy (memcpy).
//Needs <cstring> != <string>
int resizeWithBlock(arrayDati *pa, int newS);


//Initialize reading from file (containing floats)
//This time we read the file only once, and resize the 
//array when needed by doubling its current size
//We are trading space for time....
int initResize(arrayDati *pa, string fileName);

bool isFull(arrayDati a);
bool isFull(arrayDati* a);

//ordinamento crescente
void merge_sort(arrayDati*,int low, int high);
void merge(arrayDati*,int low,int mid,int high);