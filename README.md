# Best-Fit-Algorithm

A simulation of the Best Fit Algorithm used in Memory Management in a similar fashion to the Paging Algorithm simulation. The 
Best Fit algorithm aims to allocate a process with a given memory requirement to the smallest sufficient memory partition 
available. 
	
I approached this project by attempting to quantify the relationship between process assignment rate, process count, and memory
block count. To simulate the performance of the algorithm using C++, I defined two structures: block and proc, representing 
instances of a memory partition and a process, respectively. Both structs contain a size variable; for block, this variable is 
the amount of space available in the partition, and for proc, this variable is the required memory for the process. I 
incorporated these structs into the best_fit function which takes two command line arguments: int t_blocks for total number of 
blocks and int t_processes for total number of processes. I then initialize an STL vector of block structs of size t_blocks 
with size 0, and an STL queue of proc structs. I iterate through the block vector and assign sizes in ascending order 100, 200,
… 100*t_processes, and push proc structs onto the processes queue with memory requirements randomly selected in the interval 
[1, t_blocks*100]. Next, I initialize a variable t_assigned = 0 to track the number of processes in the queue that are assigned
to a memory block, so I can compute an assignment rate. The function then enters a while-loop which attempts to insert the 
process at the front of the queue into the ideal memory block in the block vector while the queue is not empty. For each 
process, the function enters a for-loop to iterate through the block vector to find an ideal block size. This is done by 
looking for a block that has a size greater than the process’s required size. If such a block is found, it is compared to the 
current ideal block. If the current block is less than the previous, the ideal index is updated to the current index and the 
loop continues through the vector. After the for-loop terminates, if the process was indeed assigned, the t_assigned variable 
is incremented and the size of the ideal block is reduced by the amount required by the process, in case it could accommodate 
another process. The process is popped from the queue and the next process is used. The return value is the 
(1.0*t_assigned/t_processes)*100 to get a percent assignment rate for the queue of processes.

In main(), the best_fit function with the command line parameters is ran 1000 times and the return values are averaged to get 
an overall picture of the performance. Using the shell script loop.sh, I recorded this data for 100. 200, … 1000 processes and 
10, 20, 30, … 1000 blocks in the excel file and plotted the averages and derived a heatmap using conditional formatting.

Common sense tells one that the less processes there are and the more memory blocks there are, the higher the assignment rate 
is. According to the plots and the data sheet, this appears to be true, as the red entries are clustered at points with around
100-300 processes and 400+ blocks. The graphs give a high-level overview of the various relationships tested.
