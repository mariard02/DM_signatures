import numpy as np 
import matplotlib.pyplot as plt

file = "../build/PMT.txt"
scintillator, energy, event = np.loadtxt(file, usecols=[0, 1, 2], skiprows=1, unpack=True)

# Separate through events
num_events = int(max(event) + 1)  # Number of events based on the maximum event index
num_data = len(energy)  # Number of data points

# Create empty lists to store energy and scintillator data for each event
energy_split = [ [] for i in range(num_events) ]
scintillator_split = [ [] for i in range(num_events) ]

# Split the energy and scintillator data according to the event number
for i in range(num_data):
    energy_split[int(event[i])].append(energy[i])
    scintillator_split[int(event[i])].append(scintillator[i])

# Calculate the total energy in each scintillator for each event
energy_scintillator = [ {} for i in range(num_events)]  # A dictionary for each event

for event_idx in range(num_events):
    # Iterate through the scintillator and energy values in the event
    for scint, en in zip(scintillator_split[event_idx], energy_split[event_idx]):
        # Sum the energies per scintillator
        if scint in energy_scintillator[event_idx]:
            energy_scintillator[event_idx][scint] += en
        else:
            energy_scintillator[event_idx][scint] = en

# (Optional) Print total energy per scintillator for each event (currently commented out)
# for i, event_energy in enumerate(energy_scintillator):
#     print(f"Event {i+1}:")
#     for scint, total_energy in event_energy.items():
#         print(f"  Scintillator {scint}: Total Energy = {total_energy:.2f} eV")

# Calculate the total energy deposit per event
energy_event = []

for i in range(num_events):
    energy_event.append(sum(energy_split[i]))  # Sum energies of all scintillators in each event

# Print the total energy for each event (in MeV)
for i, event_energy in enumerate(energy_event):
    print(f"Event {i + 1}: energy = {event_energy} MeV")

# Set the event number to analyze
event = 11
energy_matrix = np.zeros((8, 12))  # Initialize a matrix to store energy values for a grid (8x12)

# Create a histogram of the total energy per event
hist, bin_edges = np.histogram(energy_event, bins=8)

# Calculate the bin centers to place the points in the histogram
bin_centers = (bin_edges[:-1] + bin_edges[1:]) / 2

# Weighted histogram, multiplying the histogram counts by the squared bin centers
hist_weighted = hist * bin_centers**2

# Plot the weighted histogram as a scatter plot
plt.figure() 
plt.scatter(bin_centers, hist_weighted, color='skyblue')
plt.xlabel("Energy (MeV)")
plt.ylabel("dN/dE")
# Uncomment the following lines to use logarithmic scaling for the axes
# plt.xscale("log")
# plt.yscale("log")
# plt.title("Histograma de energía total de todos los eventos (con puntos)")

# Limit the x-axis to values greater than 500 MeV
plt.xlim(500, None)

# Display the scatter plot
# plt.show()

# Fill the energy_matrix with energy values from the selected event
for i in list(energy_scintillator[event].keys()):
    if i < 100:  # Only consider scintillators with an index less than 100
        x = int(i) % 10  # Calculate the x-coordinate in the grid
        y = int(i) // 10  # Calculate the y-coordinate in the grid
        energy_matrix[y, x] = energy_scintillator[event][i]  # Assign energy to the matrix

# Plot the energy deposit matrix using imshow
plt.figure()
plt.imshow(energy_matrix)
plt.colorbar(label="Energy deposit (MeV)")  # Add a color bar to indicate energy values
plt.xlabel("x")  # Label for the x-axis
plt.ylabel("y")  # Label for the y-axis
plt.show()
