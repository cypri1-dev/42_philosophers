##
<h1><img src="https://github.com/ayogun/42-project-badges/blob/main/covers/cover-philosophers.png?raw=true"</h1>

## Description
The philosophers project is a classic exercise in concurrent programming. Inspired by Dijkstra's dining philosophers problem, it involves creating a simulation where philosophers alternatively eat, think, and sleep. The challenge lies in managing shared resources (forks) and ensuring no philosopher starves or causes a deadlock.

## Project Compenents Table
This is an overview of the main components located in the "sources" directory of the philosophers project.

## Usage
To use the philosophers program, compile it using the provided Makefile. Then, run the program with the required arguments:
```bash
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
## Features
The philosophers project offers the following features:
- Concurrent Simulation: Simulates multiple philosophers engaging in eating, thinking, and sleeping concurrently.
- Resource Management: Uses mutexes to manage access to shared forks, preventing deadlocks and ensuring fairness.
- Customizable Parameters: Allows the user to specify the number of philosophers, and various time parameters to tailor the simulation.
- Error Handling: Properly handles errors and provides informative messages, ensuring robustness.
## Example
To see the philosophers simulation in action with 5 philosophers, where each philosopher dies if they do not eat within 800ms, takes 200ms to eat, and sleeps for 100ms:
```bash
./philo 5 800 200 100
```
For more detailed information, please refer to the project documentation and the source code comments.
