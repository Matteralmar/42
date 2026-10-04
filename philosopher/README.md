*This project has been created as part of the 42 curriculum by gvasylie*

---

### Description
42 Philosophers is a project that teaches you how multithreading works and how to utilize functions to manage threads. The problem was modified version of dinning philosophers problem where we were instructed to lead philosophers through their routine without them dying. The task led me to creating threads, writting functions for them to run and freeing properly memory used by them. In general it was managing simultaneous access to shared resourses.

Each philosopher must pick up two forks to eat, and the program must ensure that:

- No philosopher starves.
- No data races occur.
- The simulation behaves deterministically and safely under concurrency.

This project strengthens understanding of:
- Threads and processes
- Mutexes and synchronization
- Deadlock and starvation prevention
- Timing and scheduling

---

### Instructions
Compilation & execution

- make, make re

- ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

---

### Resources
- Dining philosophers problem: 
https://en.wikipedia.org/wiki/Dining_philosophers_problem

- Multithreading in C:
https://www.geeksforgeeks.org/c/multithreading-in-c/

- What are race conditions:
https://youtu.be/FY9livorrJI

- What is a mutex:
https://youtu.be/oq29KUy29iQ

- 42 Philosophers Subject PDF


#### AI usage
AI was used to get a better grasp on the concepts of threads, mutexes, and how philosophers should work. It also helped to optimise and implement some project functionalities.