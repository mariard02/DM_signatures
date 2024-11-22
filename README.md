# Dark Matter Indirect Detection Simulation with Geant4

This project aims to model the behavior of the Fermi Large Area Telescope (LAT) when it detects gamma rays, as part of efforts to understand indirect detection mechanisms for dark matter from space. The simulation is developed using the Geant4 library to simulate the interactions of gamma rays with the detector, focusing on their response at various energies.

## Project Overview

The main objectives of this simulation are:

- Modeling Fermi LAT response: Simulate how the LAT detector would interact with incoming gamma rays across different energy levels, aiding in the study of potential dark matter signatures.
- Gamma Ray Source Simulation: The simulation allows for two primary gamma ray sources:
1. Monoenergetic Gamma Rays: Single-energy gamma rays to study how the LAT responds to specific gamma-ray energies.
2. Diffuse Gamma-Ray Background: Simulates a realistic gamma-ray background, akin to cosmic sources, for broader spectral analysis.

## Features

- World Volume: A simple air-based world volume containing the entire detector setup.
- Scintillator Layers: A series of scintillator layers made from Cesium Iodide (CsI) to simulate the interaction of particles with the scintillator material.
- Tracker Layers: Silicon and tungsten layers arranged in a tracker configuration, placed within the world to detect particle hits.
- Optical Properties: Scintillator layers are equipped with optical properties (e.g., refraction index and absorption) to model the physics of light emission and propagation.
- Material Setup: The materials used in the simulation are set up using NIST databases (e.g., air, silicon, tungsten) with customized properties for the scintillator.

## Configuration

The gamma ray source can be configured in the generator.cc file. Adjusting this file allows you to toggle between monoenergetic gamma ray generation and diffuse background sources, depending on your experimental setup or research needs.

## Instructions
### Requirements
- Geant4: The simulation is developed in Geant4, which must be installed and properly configured to run this project.
- CMake: Required to build the project. Install from CMake's official website.
- GCC/Clang: A C++ compiler (GCC or Clang) should be installed.

### Setting up the project
1. Clone the repository: 
```
git clone https://github.com/mariard02/DM_signatures
cd geant4-DM-signatures
```

2. Create a build directory:
```
mkdir build
cd build
```

3. Run CMake to run the project:
```
cmake ..
```

4. Build the project:
```
build
```

5. Run the simulation:
```
./DM_detection
```

## Usage

- Modify generator.cc: Open the generator.cc file to specify the type of gamma ray source you want (monoenergetic or diffuse background).
- Choose the number of events per run in the file DM_detection.cc
- Compile and Run: Follow Geant4’s standard procedure to compile and execute the simulation.
- Analyze Results: The output can be analyzed to understand LAT’s detection characteristics for gamma rays at various energies, providing insights into indirect dark matter detection. This can be done using the Analysis folder.