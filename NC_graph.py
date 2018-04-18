import numpy as np
import matplotlib.pyplot as plt
#se importan los datos
data = np.loadtxt("tray.txt")
#se guardan los valores de x,v, t en array
x = data[:,0]
v = data[:,1]
t = data[:,2]
#imagen 1: posicion en funcion del tiempo
plt.plot(t,x,label="Posicion")
plt.title("x Vs t")
plt.legend()
plt.xlabel("Tiempo ")
plt.ylabel("Posicion")
plt.savefig("pos.png")
plt.close()
#imagen 2: velocidad en funcion del tiempo
plt.plot(t,v,label="Velocidad")
plt.title("v Vs t")
plt.legend()
plt.xlabel("Tiempo ")
plt.ylabel("Velocidad")
plt.savefig("vel.png")
plt.close()
#imagen 3: velocidad en funcion de la posicion
plt.plot(x,v,label="Fase")
plt.title("v Vs x")
plt.legend()
plt.xlabel("Posicion")
plt.ylabel("Velocidad")
plt.savefig("phase.png")
plt.close()
