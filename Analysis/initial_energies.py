import numpy as np 
import matplotlib.pyplot as plt

file = "../build/eventenergy.txt"
energy= np.loadtxt(file, skiprows=1, unpack=True)

hist, bin_edges = np.histogram(energy, bins=20)

# Tomar el centro de cada bin para ubicar los puntos
bin_centers = (bin_edges[:-1] + bin_edges[1:]) / 2

hist_weighted = hist# * bin_centers**2

plt.figure()
plt.scatter(bin_centers, hist_weighted, color='skyblue')
plt.xlabel("Energy (MeV)")
plt.ylabel("E^2 * dN/dE")
#plt.xscale("log")
#plt.yscale("log")
#plt.title("Histograma de energía total de todos los eventos (con puntos)")

#plt.xlim(None, 1e6)

plt.show()