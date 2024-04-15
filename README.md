# Poisson-and-Exponential-Distribution-Simulation
This C++ program simulates the inter-arrival times and service times for processes using Poisson and exponential distributions respectively.  It generates 1000 such events, computes the total and average arrival and service times, and displays them.

Features
Simulates 1000 process arrivals with inter-arrival times following a Poisson distribution.
Simulates service times for these processes using an exponential distribution.
Computes and displays the average arrival rate and average service time for the processes.

Requirements
C++11 compatible compiler
C++ Standard Library (cmath for mathematical functions and tuple for handling grouped data)
Usage
The program doesn't require any command line arguments and can be executed directly after compilation.

Compilation Command
g++ -o distribution_simulation simulation.cpp -std=c++11
Running the Program
After compilation, run the program using:
./distribution_simulation
Output
The output will list all 1000 processes with their process number, arrival time, and service time in a tuple format [Process ID, Arrival Time, Service Time]. At the end of the output, it will also show the average arrival rate and average service time.

Explanation of Functions
float uniformRand(): Generates a uniform random number between 0 and 1.
float poissonDist(float lambda): Generates a float with Poisson distribution; lambda is the average number of events per interval, used here to simulate arrival times.
float expDist(float t): Generates a float with exponential distribution; t is the mean time between events, used here to simulate service times.

Internal Workings
The program uses the C++ tuple to store and manage the process ID, arrival time, and service time together.
srand(time(0)) initializes the random number generator to ensure different results for each run.
The Poisson distribution is used for simulating the time between arrivals of processes, while the exponential distribution is used for simulating the service time of each process.

Important Considerations
The program assumes a rate of 2 processes per second for the Poisson distribution and an average service time of 1 second for the exponential distribution.
The values can be adjusted in the source code if different simulation parameters are needed.
