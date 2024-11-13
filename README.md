# Dark Matter Indirect Detection Simulation with Geant4

This project aims to model the behavior of the Fermi Large Area Telescope (LAT) when it detects gamma rays, as part of efforts to understand indirect detection mechanisms for dark matter from space. The simulation is developed using the Geant4 library to simulate the interactions of gamma rays with the detector, focusing on their response at various energies.

## Project Overview

The main objectives of this simulation are:

- Modeling Fermi LAT response: Simulate how the LAT detector would interact with incoming gamma rays across different energy levels, aiding in the study of potential dark matter signatures.
- Gamma Ray Source Simulation: The simulation allows for two primary gamma ray sources:
1. Monoenergetic Gamma Rays: Single-energy gamma rays to study how the LAT responds to specific gamma-ray energies.
2. Diffuse Gamma-Ray Background: Simulates a realistic gamma-ray background, akin to cosmic sources, for broader spectral analysis.

## Configuration

The gamma ray source can be configured in the generator.cc file. Adjusting this file allows you to toggle between monoenergetic gamma ray generation and diffuse background sources, depending on your experimental setup or research needs.

## Requirements
Geant4: The simulation is developed in Geant4, which must be installed and properly configured to run this project.
Usage

- Modify generator.cc: Open the generator.cc file to specify the type of gamma ray source you want (monoenergetic or diffuse background).
- Compile and Run: Follow Geant4’s standard procedure to compile and execute the simulation.
- Analyze Results: The output can be analyzed to understand LAT’s detection characteristics for gamma rays at various energies, providing insights into indirect dark matter detection. This can be done using the Analysis folder, still under development.