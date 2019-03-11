//
//  routines.h
//  best_fit_memory
//
//  Created by Jacob Mathai on 3/10/19.
//  Copyright © 2019 Jacob Mathai. All rights reserved.
//

#ifndef routines_h
#define routines_h

#include <vector>
#include <queue>

struct block {  // Block struct for memory blocks
    int size;   // Size of block
    block (int s) : size(s) {};
};

struct proc {   // Process struct
    int size;   // Required memory block for process
    proc (int s) : size(s) {};
};

int best_fit (int t_blocks, int t_processes);

#endif /* routines_h */
