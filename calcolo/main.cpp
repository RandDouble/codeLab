#include <iostream>
#include <fstream>
#include "calcoloLib/function.h"
#include <string>


using namespace std;

int main(int argc, char **argv) {

    std::locale::global( std::locale( "it_IT.UTF-8" ) );
    //****variabili****//
    arrayDati dat;
    arrayDati out;
    ofstream fout;
    string nameFile=argv[1];
    char type=argv[2][0];
    int count=0;
    //****parte operativa****//
    /*  PARTE OBSOLETA, UTILE SE SI VUOLE FAR PARTIRE IL CODICE MANUALMENTE 
    cout<<"inserire il nome del file da analizzare senza l'estensione,\n
    da notare che deve essere in questa cartella"<<endl;, 
    cin>>nameFile;
    */
    count=init(&dat,"./caricaFile/"+nameFile+".dat");
    if(count==-2){
        cout<<"errore nel caricamento del file"<<endl;
        return -1;
    }
    else cout<<"numero di elementi da analizzare trovati : "<<dat.size<<endl;
    fout.open("./massimi/"+nameFile+".csv");
    /*PARTE OBSOLETA IN FASE DI DEBUG PER VEDERE I DATI PRODOTTI
    for(int i=0; i<dat.size; i++){
        stampa(&fout, &dat.raw[i], i);    }
    */
    //vettore con i massimi
    massimo(dat, &out, type);
    //trasferimento dei dati completi
    for(int i=0; i<out.size; i++){
        stampa(&fout, &out.raw[i], i);
    }
    fout.close();
    //rimozione spazzatura
    cout<<endl;
    delete [] dat.raw;
    delete [] out.raw;
    return 0;
    //****fine****//
} 