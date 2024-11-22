import numpy as np 
import matplotlib.pyplot as plt

# Load data
# File path to the data file containing scintillator, energy, and event information.
file = "../build/PMT.txt"

# Load columns: scintillator ID, energy, and event ID.
scintillator, energy, event = np.loadtxt(file, usecols=[0, 1, 2], skiprows=1, unpack=True)

# Separate data by events
# Determine the total number of events and the number of data points.
num_events = int(max(event) + 1)
num_data = len(energy)

# Initialize lists to separate energy and scintillator data for each event.
energy_split = [[] for _ in range(num_events)]
scintillator_split = [[] for _ in range(num_events)]

# Fill the lists by iterating through the data.
for i in range(num_data):
    energy_split[int(event[i])].append(energy[i])
    scintillator_split[int(event[i])].append(scintillator[i])

# Calculate the total energy deposited in each scintillator for all events
# Create a list of dictionaries to store scintillator energy data for each event.
energy_scintillator = [{} for _ in range(num_events)]

# Accumulate energy per scintillator for each event.
for event_idx in range(num_events):
    for scint, en in zip(scintillator_split[event_idx], energy_split[event_idx]):
        # Add energy to the corresponding scintillator.
        if scint in energy_scintillator[event_idx]:
            energy_scintillator[event_idx][scint] += en
        else:
            energy_scintillator[event_idx][scint] = en

# Calculate the total energy deposited in each event
energy_event = [sum(energy_split[i]) for i in range(num_events)]

# Print total energy deposited per event
for i, event_energy in enumerate(energy_event):
    print(f"Event {i + 1}: energy = {event_energy} MeV")

# Create histogram of total energy deposits across all events
# Define the number of bins for the histogram and compute the bin centers.
hist, bin_edges = np.histogram(energy_event, bins=8)
bin_centers = (bin_edges[:-1] + bin_edges[1:]) / 2

# Compute weighted histogram values (bin counts multiplied by bin center squared).
hist_weighted = hist * bin_centers**2

# Plot histogram with scatter points
plt.figure()
plt.scatter(bin_centers, hist_weighted, color='skyblue')
plt.xlabel("Energy (MeV)")
plt.ylabel("dN/dE")
plt.xlim(500, None)  # Set a lower limit for x-axis.
plt.show()

# Visualize energy deposit for a selected event (e.g., event 11)
event = 11
energy_matrix = np.zeros((8, 12))  # Create an 8x12 matrix for visualization.

# Map scintillator IDs to x, y positions and fill the energy matrix.
for i in list(energy_scintillator[event].keys()):
    if i < 100:  # Assuming scintillator IDs below 100 are valid.
        x = int(i) % 10
        y = int(i) // 10
        energy_matrix[y, x] = energy_scintillator[event][i]

# Plot energy matrix as a heatmap.
plt.figure()
plt.imshow(energy_matrix, cmap="viridis")
plt.colorbar(label="Energy deposit (MeV)")
plt.xlabel("x")
plt.ylabel("y")
plt.title(f"Energy Deposit Heatmap for Event {event}")
plt.show()
