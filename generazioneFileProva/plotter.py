import numpy as np
import matplotlib.pyplot as plt
import pandas as pan

a=pan.read_csv('../exeCalcolo/molla1-40g.csv', decimal=',',delimiter='\t').to_numpy()
b=pan.read_csv('../exeCalcolo/molla1-40g.dat', decimal=',',delimiter='\t').to_numpy()
#a=np.loadtxt('../exeCalcolo/molla1-40g.csv', converters = {0: lambda s: float(s.decode("UTF-8").replace(",", "."))})
#b=np.genfromtxt('/home/pilo/codeLab/exeCalcolo/molla1-40g.dat')
print(a)
#print(b)
at=a[:,0]
bt=b[:,0]
av=a[:,2]
bv=b[:,2]
#ax=10*a[:,1]
#aa=10*a[:,3]

print(a)
plt.figure()
#plt.subplot(111)
#plt.plot(at,ax, 'bo')
#plt.show()
#plt.subplot(212)
plt.plot( at, av,'bo', bt,bv,'y')
plt.show()
#plt.subplot(313)
#plt.plot( at,aa, 'r--')
#plt.show()