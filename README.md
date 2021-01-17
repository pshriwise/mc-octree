# mc-octree
Octree for Monte Carlo Particle Transport Data Structures

This project is intended as a test-base for applying Octrees for fast spatial searches of tally data structures in Monte Carlo particle transport codes. It will be written in C++ for easy integration with [OpenMC](https://openmc.org).

Initially, it will be aimed at providing a general interface for bounded spatial objects, requiring only that that they provide a bounding box and method for determining point containment. 

Further on, the optional capability for ray marching will be included.
