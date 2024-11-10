import numpy as np 
import matplotlib.pyplot as plt

file = "../build/PMT.txt"
scintillator, energy, event= np.loadtxt(file, usecols=[0, 1, 2], skiprows=1, unpack=True)

# Separate through events
num_events = int(max(event) + 1)
num_data = len(energy)

energy_split = [ [] for i in range(num_events) ]
scintillator_split = [ [] for i in range(num_events) ]

for i in range(num_data):
	energy_split[int(event[i])].append(energy[i])
	scintillator_split[int(event[i])].append(scintillator[i])

# Calculate the total energy in each scintillator

energy_scintillator = [ {} for i in range(num_events)] # We define a dictionary for each event

for event_idx in range(num_events):
    # Iterate through the scintillator and energy values in the event
    for scint, en in zip(scintillator_split[event_idx], energy_split[event_idx]):
        # Sum the energies per scintillator
        if scint in energy_scintillator[event_idx]:
            energy_scintillator[event_idx][scint] += en
        else:
            energy_scintillator[event_idx][scint] = en

for i, event_energy in enumerate(energy_scintillator):
    print(f"Event {i+1}:")
    for scint, total_energy in event_energy.items():
        print(f"  Scintillator {scint}: Total Energy = {total_energy:.2f} eV")

# Calculate the total energy deposit per event
energy_event = []

for i in range(num_events):
	energy_event.append(sum(energy_split[i]))

for i, event_energy in enumerate(energy_event):
	print(f"Event {i + 1}: energy = {event_energy} MeV")

event = 0
energy_matrix = np.zeros((8, 12))

for i in list(energy_scintillator[event].keys()):
    if i < 100:
        x = int(i) % 10
        y = int(i) // 10
        energy_matrix[y, x] = energy_scintillator[event][i]

# Representar la matriz de energía con imshow
plt.imshow(energy_matrix)
plt.colorbar(label="Energy deposit (eV)")
plt.xlabel("x")
plt.ylabel("y")
plt.show()



