import matplotlib.pyplot as plt 
import numpy as np
import math as mt

a=np.linspace(0.0,3.0,150)
omegaNat=1.53*2*np.pi
amp=0.45
gamma=0.1749
y=amp/np.sqrt((((omegaNat**2)-(a**2))**2)+gamma*(a**2))
plt.figure()
#plt.plot(a,y)
plt.style.use("ggplot")
plt.plot(a, amp/(np.sqrt((((1.5**2)-(a**2))**2)+((gamma**2)*(a**2)))))
plt.ylabel('ampiezza teorica [m]')
plt.xlabel('Frequenza della Forzante [Hz]')
plt.draw()
plt.show()
