import numpy as np
import matplotlib.pyplot as plt


a=float(input("set tempo iniziale t0\n"))
b=float(input("set tempo finale tf\n"))
dt=float(input("set incremento tempo\n"))
t=np.arange(a, b, dt)
f=np.sin(np.pi*t)
fout=open("/home/pilo/codeLab/exeCalcolo/prova1.dat","w")
plt.plot(t,f)
plt.show()
for i in range(0, t.size):
    fout.write(str(format(t[i], ".2f"))+'\t'+str(format(f[i], ".2f"))+'\n')
fout.close()

