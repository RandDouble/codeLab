#include "./calcoloLib/function.h"

using namespace std;

void assoluto(arrayDati*dat){
    for(int i=0; i<dat->used; i++){
        dat->raw[i].v=abs(dat->raw[i].v); //per ogni elemento del vettore di partenza ne calcola il modulo
    }
}

void massimo(arrayDati origin, arrayDati*out){
    arrayDati appo; //vettore di appoggio
    int counter=0; //contatore degli elementi del vettore
    
    //inizializzo appo in modo che sia uguale ai dati originali
    //si potrei sacrificare i dati originali senza problemi visto che
    //tendenzialmente non perdono, 
    //ma non si sa mai se volessi fare subito un raffronto dopo
    init(&appo, origin.size);
    //copio i dati 
    for(int i=0;i<origin.size;i++){
        copia(&appo.raw[i],origin.raw[i]);
        appo.used=i+1;
    }
    //rendo assoluto la copia fantoccio
    assoluto(&appo);
    init(out, 20);
    //ricerca dei punti di massimo che coincidono sia
    //ai massimi che ai minimi della funzione originale
    for(int i=1;i<(origin.size-1);i++){
        if(isMax(appo.raw, i)){ //controllo se ho a che fare con un massimo
            copia(&out->raw[counter],appo.raw[i]); //copia nel vettore risultante
            counter++; //incremento contatore elementi
            out->used = counter; //incremento elementi del vettore usati
            if(isFull(out)) resizeWithBlock(out, 2*(out->size)); //se il vettore è pieno provvedo a raddoppiarne la grandezza
        }
    }
    if(out->size!=out->used) resizeWithBlock(out, out->used); //elimino la memoria allocata inutilemente

    delete [] appo.raw;
}

bool isMax(dati* ver, int i){
    //"derivata sinistra" circa in realtà è il rapporto incrementale
    double derSin=(ver[i].v-ver[i-1].v)/(ver[i].time-ver[i-1].time);
    //"derivata destra" circa in realtà è il rapporto incrementale
    double derDex=(ver[i+1].v-ver[i].v)/(ver[i+1].time-ver[i].time);
    //cerco le condizioni di massimo
    return (derSin>=0 && derDex<=0)? true : false;
}