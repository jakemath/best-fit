//
//  main.cpp
//  best_fit_memory
//
//  Created by Jacob Mathai on 11/29/18.
//  Copyright © 2018 Jacob Mathai. All rights reserved.
//

/* A program to simulate the performance of the Best Fit algorithm for finding
 an appropriately sized memory partition for a process of a given size.
*/

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::cout;
using std::cin;
using std::endl;

struct block {  // Block struct for memory blocks
    int size;   // Size of block
    block (int s) : size(s) {};
};

struct proc {   // Process struct
    int size;   // Required memory block for process
    proc (int s) : size(s) {};
};

int total_blocks, total_processes;

int best_fit (int t_blocks, int t_processes)
{
    vector<block> blocks (t_blocks, 0);
    queue<proc> processes;
    int i;
    for (i = 0; i < blocks.size(); ++i)
        blocks [i].size = (rand() % (t_blocks * 100) + 1);   // total_blocks blocks of random size between 1 and 100*total_blocks
    for (i = 0; i < t_processes; ++i)
    {
        srand(time(NULL));
        processes.push (proc (rand() % (t_blocks * 100) + 1));    // Processes of random size between 1 and the maximum possible memory size
    }
    int t_assigned = 0;
    while (!processes.empty())   // Iterate through the processes
    {
        int index = -1; // Initialize optimal index to -1 before searching
        for (int i = 0; i < blocks.size(); ++i)  // Iterate through memory blocks
        {
            if (blocks [i].size >= processes.front().size)  // If an appropriately sized block found
            {
                if (index == -1)    // If first ideal memory block --> update index
                    index = i;
                else if (blocks [index].size > blocks [i].size) // If this memory location is better than the current ideal index --> update
                    index = i;
            }
        }
        if (index != -1)    // If an ideal memory block found
        {
            ++t_assigned;
            blocks [index].size -= processes.front().size;   // Subtract the size of the process memory requirement from the optimal block's size
        }
        processes.pop();
    }
    return (((1.0 * t_assigned) / t_processes) * 100);  // Return the assign rate
}

int main (int argc, char *argv[])
{
    total_processes = atoi(argv[1]);
    total_blocks = atoi(argv[2]);
    int total = 0;
    for (int i = 0; i < 1000; ++i)
    {
        total += best_fit (total_blocks, total_processes);
    }
    cout << (total/1000) << endl;
}
