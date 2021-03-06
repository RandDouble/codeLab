#include "arrayDati.h"

//Initialize to array of size dim
int init(arrayDati *pa, int dim){
	pa->size = dim;
	pa->used = 0;
	pa->raw = new dati[dim];
	//Compact if else
	//-1: error code for allocation issue
	return (pa->raw == NULL? -1:0); //Just for fun...

}

int init(arrayDati *pa, string fileName){
	ifstream fileIn;

	dati appo;
	int count = 0;

	fileIn.open(fileName);
	
	if(fileIn.fail()){
		return -2; //Error code for file problem.
	}

	leggiFile(&fileIn,&appo);
	while (!fileIn.eof()){
		count++;
		leggiFile(&fileIn,&appo);
	}

	pa->size = count;
	pa->used = 0;
	pa->raw = new dati[count];

	if(pa->raw == NULL){
		fileIn.close();
		return -1;
	}
	
	fileIn.clear(); //pulisce dalla condizione di eof
	fileIn.seekg(0,ios::beg); //riporta la testina all-inizio del file
	
	for(int i=0; i<pa->size; i++){
		leggiFile(&fileIn,&(pa->raw[i]));
		cout<<pa->raw[1].time<<endl;
	}
	pa->used  = count;
	
	fileIn.close();
	
	return 0;
}

//Resize of myArray
//Parameters: 
//--pa: reference to instance to modify
//--newS: new size 
int resize(arrayDati *pa, int newS){
	
	int top;
	//Create a new array
	dati *vappo = new dati[newS];
	
	if(vappo == NULL){
		return -1;
	}

	//Check the upper index
	top = (newS >= pa->size?pa->size:newS);

	for(int i=0; i<top; i++){
		copia(&vappo[i],pa->raw[i]);
	}

	//Update size
	pa->size = newS;
	//Update used;
	pa->used = top;
	//Detele the old array in heap
	delete [] pa->raw;
	//point to the new array
	pa->raw = vappo;
	
	return 0;
}

//Resize of myArray
//Parameters: 
//--pa: reference to instance to modify
//--newS: new size 
int resizeWithBlock(arrayDati *pa, int newS){
	
	int top;
	//Create a new array
	dati *vappo = new dati[newS];
	
	if(vappo == NULL){
		return -1;
	}

	//Check the upper index
	top = (newS >= pa->size?pa->size:newS);
	
	//Pay attention here
	//Copies a block of top*sizeof(float) bytes
	//starting from the memory address pa->raw (source) to the
	//to a block of memory of the same size starting
	//at vappo (destination)

	memcpy(vappo,pa->raw, top*sizeof(dati));

	//Smart!


	//Update size
	pa->size = newS;
	//Update used;
	pa->used = top;
	//Detele the old array in heap
	delete [] pa->raw;
	//point to the new array
	pa->raw = vappo;
	
	return 0;
	
}





//Initialize reading from file (containing floats)
//This time we read the file only once, and resize the 
//array when needed by doubling its current size
//We are trading space for time....
int initResize(arrayDati *pa, string fileName){
	ifstream fileIn;

	dati appo;
	initPunto(&appo);
	
	
	int count = 0;

	fileIn.open(fileName);
	
	if(fileIn.fail()){
		return -2; //Error code for file problem.
	}

	//Initial allocation of the array
	

	if(init(pa,20) == -1){
		fileIn.close();
		return -1; //Memory allocation error
	}
	
	//Ho un vettore di dimensione INIT_SIZE a disposizione
	leggiFile(&fileIn, &appo);
	while (!fileIn.eof()){
		
		//Is there space?
		if(isFull(*pa)){

			if( resize(pa, 2*pa->size) == -1) return -1;
		
		}


		//Array resized: there is space...
		pa->raw[count] = appo;
		pa->used++;
		count++;
		
		leggiFile(&fileIn, &appo);
	}

	fileIn.close();
	
	resize(pa,count);
	
	return count;

}

bool isFull(arrayDati a){
	if(a.size == a.used) return true;
		else return false;
}

bool isFull(arrayDati* a){
	if(a->size == a->used) return true;
		else return false;
}



/*
void merge_sort(arrayDati* a,int low,int high){
    int mid;
    if(low<high) {
        mid = low + (high-low)/2; //This avoids overflow when low, high are too large
        merge_sort(a,low,mid);
        merge_sort(a, mid+1,high);
        merge(a, low,mid,high);
    }
}
*/
/*
void merge(arrayDati* a, int low,int mid,int high){
//low: indice piu` piccolo dell'array da fondere
//mid: mezzo dell'array da fondere
//high: indice piu` grande dell'array da fondere

    int h,i,j,k;
    dati b[200]; //Abbiamo bisogno di un vettore di appoggio dove copiare i dati
    for(int i=0;i<200;i++){
        initPunto(&b[i]);
    }
    h=low; //Indice libero per scandire vettore di sinistra
    i=low; //Indica la prima posizione libera dell'array in cui stiamo copiando i dati
    j=mid+1; //Indice libero per scandire vettore di destra

    while((h<=mid)&&(j<=high)){ //Mentre non hai esaurito uno dei due sottovettori
        if(a->raw[h]<=a->raw[j]){
            copia(&b[i],a->raw[h]);
            h++; //Avanza di uno con l'indice libero dell'array di sinistra
        }
        else{
            copia(&b[i],a->raw[j]);
            j++; //Avanza di uno con l'indice libero dell'array di destra
        }
        i++; //
    }

    if(h>mid){ //Se hai esaurito il sottovettore di sinistra, riversa in b quanto rimane del sottovettore di destra
        for(k=j;k<=high;k++){
            copia(&b[i],a->raw[k]);
            i++;
        }
    }
    else{
        for(k=h;k<=mid;k++){ //Se hai esaurito il sottovettore di destra, riversa in b quanto rimane del sottovettore di sinistra
            copia(&b[i],a->raw[k]);
            i++;
        }
    }
    for(k=low;k<=high;k++) copia(&a->raw[k],b[k]); //Ricopia in a il vettore ordinato b. Questo passo si puo` ottimizzare usando vettori allocati dinamicamente.
}
*/
