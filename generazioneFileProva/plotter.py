import numpy as np
import matplotlib.pyplot as plt
import pandas as pan
import os
import time

def stampa(punti, grafico, file):
#funzione che si occupa di stampare il grafico e di salvarlo
    #creazione dei vettori
    at=punti[:,0]
    bt=grafico[:,0]
    av=punti[:,2]
    bv=grafico[:,2]
    #inizio grafica
    fig=plt.figure()
    plt.plot( at, av,'bo',label='punti stazionari')
    plt.plot(bt,bv,'y', label='grafico dei dati')
    plt.title('estremi della funzione misurata')
    plt.legend()
    plt.show()
    #salvataggio dei dati
    if os.name=='nt':
        fig.savefig("outputGrafici\\"+file+".png")
    else:
        fig.savefig("outputGrafici/"+file+".png")

def controlloCartelle():
#controlla che esistano le cartelle di partenza e se non esistono le fa
    directory=str(os.getcwd())
    print("la directory di partenza è : "+directory)
    if os.path.isdir("outputGrafici")==False:
        os.mkdir("outputGrafici")
        print("creata la cartelle di output dei grafici")
    else:
        print("bene cartella output grafico già presente")
    if os.path.isdir("massimi")==False:
        os.mkdir("massimi")
        print("creata la cartelle di calcolazione dei massimi dei grafici")
    else:
        print("bene cartella dei massimi è già presente")
    if os.path.isdir("caricaFile")==False:
        os.mkdir("caricaFile")
        print("creata la cartella di caricamento dei file")
    else:
        print("bene cartella di caricamento già presente")

def letturaDati(file):
#legge e carica i dati dalle cartelle di cui prima
    if os.name=='nt':
        district=os.getcwd()
        a=pan.read_csv(district+'\\massimi\\'+file+'.csv', decimal=',',delimiter='\t').to_numpy()
        b=pan.read_csv(district+'\\caricaFile\\'+file+'.dat', decimal=',',delimiter='\t').to_numpy()
    else:
        a=pan.read_csv(os.getcwd()+'/massimi/'+file+'.csv', decimal=',',delimiter='\t').to_numpy()
        b=pan.read_csv(os.getcwd()+'/caricaFile/'+file+'.dat', decimal=',',delimiter='\t').to_numpy()
    return a, b

##########parte principale del programma##############
controlloCartelle()
input("caricare i file nella cartella indicata, poi premere enter")
elFile=os.listdir(path='caricaFile')
for file in elFile:
    err=os.system("./main.exe "+file[:-4])

time.sleep(5)
##########parte di raccolta dati e stampa#############
for file in elFile:
    a, b=letturaDati(file[:-4])
    stampa(a,b,file[:-4])
print("Programma terminato, grazie dell'uso,\nRicordati di ringraziare e venerare il mio sommo Creatore")
#########termine del programma########################