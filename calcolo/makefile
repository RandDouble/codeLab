compila: function.o dati.o arrayDati.o main.o
	g++ main.o function.o dati.o arrayDati.o -o main.exe
	mv main.exe function.o dati.o arrayDati.o main.o ../exeCalcolo
main.o:
	g++ -c main.cpp
function.o:
	g++ -c function.cpp
dati.o:
	g++ -c dati.cpp
arrayDati.o:
	g++ -c arrayDati.cpp
reset: resm resf resa resd
	rm ../exeCalcolo/main.exe 
resm:
	rm ../exeCalcolo/main.o 
resf:
	rm ../exeCalcolo/function.o 
resa:
	rm ../exeCalcolo/dati.o 
resd:
	rm ../exeCalcolo/arrayDati.o 