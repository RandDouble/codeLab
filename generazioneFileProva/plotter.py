import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
import pandas as pan
import os
import time

def stampa(punti, grafico, file):
#funzione che si occupa di stampare il grafico e di salvarlo
    #creazione dei vettori
    deb=open("debug.txt", "a")
    at=punti[:,0]
    bt=grafico[:,0]
    if len(file)>=17:
        deb.write(file+" : "+'posizione\n')
        av=punti[:,1]
        bv=grafico[:,1]
    else:
        deb.write(file+" : "+'velocità\n')
        av=punti[:,2]
        bv=grafico[:,2]
    #inizio grafica
    fig=plt.figure()
    plt.style.use('ggplot')
    plt.plot(bt,bv,'gray', label='grafico dei dati')
    plt.plot( at, av,'co',label='punti stazionari')
    #setto il titolo degli assi
    plt.xlabel('tempo [t]')
    if len(file)>17:
        plt.ylabel('posizione [m]')
        deb.write(file+' inserità label posizione\n')
    else:
        plt.ylabel('velocità [m/s]')
        deb.write(file+' inserità label velocità\n')
    plt.title('estremi della funzione misurata')
    plt.legend()
    #plt.show()
    #salvataggio dei dati
    if os.name=='nt':
        fig.savefig("outputGrafici\\"+file+".png")
    else:
        fig.savefig("outputGrafici/"+file+".png")
    deb.close()

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
deb=open("debug.txt",'w')
for file in elFile:
    if len(file)>17:
        err=os.system("./main.exe "+file[:-4]+' H')
        deb.write("./main.exe "+file[:-4]+' H\n')
    else:
        err=os.system("./main.exe "+file[:-4]+' s')
        deb.write("./main.exe "+file[:-4]+' s\n')
deb.close()
time.sleep(2)
##########parte di raccolta dati e stampa#############
for file in elFile:
    a, b=letturaDati(file[:-4])
    stampa(a,b,file[:-4])
print("Programma terminato, grazie dell'uso,\nRicordati di ringraziare e venerare il mio sommo Creatore")
#########termine del programma########################