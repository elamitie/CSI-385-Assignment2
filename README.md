# CSI-385-Assignment2

The given project was a simulation of a process scheduler using
a multitude of different scheduling algorithms. FIFO, Shortest-
time, priority, and FIFO Round Robin as well as priority Round
Robin.

The Makefile has a number of targets for building and running
the various different tests / algorithms:

  `make fifo`

  `make shortestTime`

  `make priority`

  `make fifoRoundRobin`

  `make priorityRoundRobin`

The Makefile will generate a build folder in the project root
where it will put the executable.
If the program is executed on the commandline without the
proper commandline arguments, it will default to running
as fifo. The proper commandline arguments are specificed
by each of the Makefile targets.
