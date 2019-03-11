//
//  routines.cpp
//  best_fit_memory
//
//  Created by Jacob Mathai on 3/10/19.
//  Copyright © 2019 Jacob Mathai. All rights reserved.
//

#include "routines.h"

using std::vector;
using std::queue;

int best_fit (int t_blocks, int t_processes) // Simulation function
{
    vector<block> blocks (t_blocks, 0);
    queue<proc> processes;
    int i;
    for (i = 0; i < blocks.size(); ++i)
        blocks [i].size = (rand() % (t_blocks * 100) + 1);   // total_blocks blocks of random size between 1 and 100*total_blocks
    srand(time(NULL));
    for (i = 0; i < t_processes; ++i)
        processes.push (proc (rand() % (t_blocks * 100) + 1));    // Processes of random size between 1 and the maximum possible memory size
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
