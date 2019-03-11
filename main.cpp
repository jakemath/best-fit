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
#include "routines.h"

int main (int argc, char *argv[])
{
    int total_blocks, total_processes;
    total_processes = atoi(argv[1]);
    total_blocks = atoi(argv[2]);
    int total = 0;
    for (int i = 0; i < 1000; ++i)
        total += best_fit (total_blocks, total_processes);
    std::cout << (total/1000) << std::endl;
}
