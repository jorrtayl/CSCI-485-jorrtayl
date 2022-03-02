If you want to add your own individual values, manually execute the code as follows:

gcc -pthread -Wall -Wextra -g -o filename filename.c
./filename value1 value2

value1 is the number of threads and value2 is the number of iterations. If you do not enter a value1, or value2, or neither, it defaults with 4 threads and 10,000 iterations.

To execute the code with a makefile, just type the following:

./makefile(filename)

This will execute that code with default values (4 threads, 10,000 iterations).