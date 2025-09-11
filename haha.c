#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], status[n];
    float avg_tat = 0, avg_wt = 0;

    // Input
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        status[i] = 0; // 0 = not completed, 1 = completed
    }

    int time = 0, completed = 0;

    // FCFS Scheduling
    while (completed < n) {
        int idx = -1;

        // Find process with minimum AT which is not completed yet
        for (int i = 0; i < n; i++) {
            if (!status[i]) {
                if (idx == -1 || at[i] < at[idx]) {
                    idx = i;
                }
            }
        }

        // If CPU is idle
        if (time < at[idx])
            time = at[idx];

        // Execute process
        ct[idx] = time + bt[idx];
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        time = ct[idx];
        status[idx] = 1; // Mark as completed
        completed++;
    }

    // Print results
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f", avg_tat / n);
    printf("\nAverage WT  = %.2f\n", avg_wt / n);

    return 0;
}



















##########################









#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], status[n];
    float avg_tat = 0, avg_wt = 0;

    // Input
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        status[i] = 0; // 0 = not completed, 1 = completed
    }

    int time = 0, completed = 0;

    // SJF Scheduling (Non-preemptive)
    while (completed < n) {
        int idx = -1;
        int min_bt = 1e9;

        // Select process with minimum BT among available processes
        for (int i = 0; i < n; i++) {
            if (!status[i] && at[i] <= time) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        // If no process has arrived yet, jump to the earliest arriving process
        if (idx == -1) {
            int earliest = -1;
            for (int i = 0; i < n; i++) {
                if (!status[i]) {
                    if (earliest == -1 || at[i] < at[earliest]) {
                        earliest = i;
                    }
                }
            }
            time = at[earliest];
            idx = earliest;
        }

        // Execute selected process
        ct[idx] = time + bt[idx];
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        time = ct[idx];
        status[idx] = 1; // Mark as completed
        completed++;
    }

    // Print results
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f", avg_tat / n);
    printf("\nAverage WT  = %.2f\n", avg_wt / n);

    return 0;
}














#####################















#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], status[n];
    int rem_bt[n]; // remaining burst times
    float avg_tat = 0, avg_wt = 0;

    // Input
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rem_bt[i] = bt[i];
        status[i] = 0; // 0 = not completed, 1 = completed
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, completed = 0;

    // Round Robin Scheduling
    while (completed < n) {
        int done_any = 0; // check if at least one process executed in this cycle
        for (int i = 0; i < n; i++) {
            if (!status[i] && at[i] <= time) {
                done_any = 1;

                if (rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    rem_bt[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    status[i] = 1;
                    completed++;
                }
            }
        }

        // If no process was ready, move time forward
        if (!done_any) {
            int next_arrival = -1;
            for (int i = 0; i < n; i++) {
                if (!status[i]) {
                    if (next_arrival == -1 || at[i] < at[next_arrival])
                        next_arrival = i;
                }
            }
            time = at[next_arrival];
        }
    }

    // Print results
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f", avg_tat / n);
    printf("\nAverage WT  = %.2f\n", avg_wt / n);

    return 0;
}



















#######################











#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], status[n];
    int rem_bt[n];  // remaining burst time
    float avg_tat = 0, avg_wt = 0;

    // Input
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rem_bt[i] = bt[i];
        status[i] = 0; // 0 = not completed, 1 = completed
    }

    int time = 0, completed = 0;

    // SRTF Scheduling (preemptive)
    while (completed < n) {
        int idx = -1;
        int min_bt = 1e9;

        // Pick process with shortest remaining time among available
        for (int i = 0; i < n; i++) {
            if (!status[i] && at[i] <= time && rem_bt[i] < min_bt && rem_bt[i] > 0) {
                min_bt = rem_bt[i];
                idx = i;
            }
        }

        // If no process is ready, move time forward
        if (idx == -1) {
            time++;
            continue;
        }

        // Run the chosen process for 1 unit
        rem_bt[idx]--;
        time++;

        // If process finishes
        if (rem_bt[idx] == 0) {
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            status[idx] = 1;
            completed++;
        }
    }

    // Print results
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f", avg_tat / n);
    printf("\nAverage WT  = %.2f\n", avg_wt / n);

    return 0;
}














####################










#include <stdio.h>

int main() {
    int nb, np;   // number of blocks and processes
    
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int blockSize[nb], blockAllocated[nb];
    printf("Enter sizes of %d blocks:\n", nb);
    for (int i = 0; i < nb; i++) {
        scanf("%d", &blockSize[i]);
        blockAllocated[i] = -1;   // -1 means block is free
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int processSize[np], processAllocated[np];
    printf("Enter sizes of %d processes:\n", np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &processSize[i]);
        processAllocated[i] = -1;  // initially not allocated
    }

    // First Fit Allocation
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (blockAllocated[j] == -1 && blockSize[j] >= processSize[i]) {
                // allocate this block to process
                processAllocated[i] = j;
                blockAllocated[j] = i;   // mark block occupied
                break;
            }
        }
    }

    // Output allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (processAllocated[i] != -1)
            printf("%d\n", processAllocated[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}










##################











#include <stdio.h>

int main() {
    int nb, np;   // number of blocks and processes
    
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int blockSize[nb], blockAllocated[nb];
    printf("Enter sizes of %d blocks:\n", nb);
    for (int i = 0; i < nb; i++) {
        scanf("%d", &blockSize[i]);
        blockAllocated[i] = -1;   // -1 means block is free
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int processSize[np], processAllocated[np];
    printf("Enter sizes of %d processes:\n", np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &processSize[i]);
        processAllocated[i] = -1;  // initially not allocated
    }

    // Best Fit Allocation
    for (int i = 0; i < np; i++) {
        int bestIndex = -1;
        for (int j = 0; j < nb; j++) {
            if (blockAllocated[j] == -1 && blockSize[j] >= processSize[i]) {
                if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex]) {
                    bestIndex = j;
                }
            }
        }
        if (bestIndex != -1) {
            processAllocated[i] = bestIndex;
            blockAllocated[bestIndex] = i; // mark block occupied
        }
    }

    // Output allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (processAllocated[i] != -1)
            printf("%d\n", processAllocated[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
















###########












#include <stdio.h>

int main() {
    int nb, np;   // number of blocks and processes
    
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int blockSize[nb], blockAllocated[nb];
    printf("Enter sizes of %d blocks:\n", nb);
    for (int i = 0; i < nb; i++) {
        scanf("%d", &blockSize[i]);
        blockAllocated[i] = -1;   // -1 means block is free
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int processSize[np], processAllocated[np];
    printf("Enter sizes of %d processes:\n", np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &processSize[i]);
        processAllocated[i] = -1;  // initially not allocated
    }

    // Worst Fit Allocation
    for (int i = 0; i < np; i++) {#include <stdio.h>

int main() {
    int nb, np;   // number of blocks and processes
    
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int blockSize[nb], blockAllocated[nb];
    printf("Enter sizes of %d blocks:\n", nb);
    for (int i = 0; i < nb; i++) {
        scanf("%d", &blockSize[i]);
        blockAllocated[i] = -1;   // -1 means block is free
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int processSize[np], processAllocated[np];
    printf("Enter sizes of %d processes:\n", np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &processSize[i]);
        processAllocated[i] = -1;  // initially not allocated
    }

    // Worst Fit Allocation
    for (int i = 0; i < np; i++) {
        int worstIndex = -1;
        for (int j = 0; j < nb; j++) {
            if (blockAllocated[j] == -1 && blockSize[j] >= processSize[i]) {
                if (worstIndex == -1 || blockSize[j] > blockSize[worstIndex]) {
                    worstIndex = j;
                }
            }
        }
        if (worstIndex != -1) {
            processAllocated[i] = worstIndex;
            blockAllocated[worstIndex] = i; // mark block occupied
        }
    }

    // Output allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (processAllocated[i] != -1)
            printf("%d\n", processAllocated[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

        int worstIndex = -1;
        for (int j = 0; j < nb; j++) {
            if (blockAllocated[j] == -1 && blockSize[j] >= processSize[i]) {
                if (worstIndex == -1 || blockSize[j] > blockSize[worstIndex]) {
                    worstIndex = j;
                }
            }
        }
        if (worstIndex != -1) {
            processAllocated[i] = worstIndex;
            blockAllocated[worstIndex] = i; // mark block occupied
        }
    }

    // Output allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (processAllocated[i] != -1)
            printf("%d\n", processAllocated[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}



###################



#include <stdio.h>

int main() {
    int nb, np;   // number of blocks and processes
    
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int blockSize[nb], blockAllocated[nb];
    printf("Enter sizes of %d blocks:\n", nb);
    for (int i = 0; i < nb; i++) {
        scanf("%d", &blockSize[i]);
        blockAllocated[i] = -1;   // -1 means block is free
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int processSize[np], processAllocated[np];
    printf("Enter sizes of %d processes:\n", np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &processSize[i]);
        processAllocated[i] = -1;  // initially not allocated
    }

    // Next Fit Allocation
    int lastPos = 0;  // remember last allocated position
    for (int i = 0; i < np; i++) {
        int j, allocated = 0;
        for (j = 0; j < nb; j++) {
            int idx = (lastPos + j) % nb; // circular search
            if (blockAllocated[idx] == -1 && blockSize[idx] >= processSize[i]) {
                processAllocated[i] = idx;
                blockAllocated[idx] = i; // mark block occupied
                lastPos = (idx + 1) % nb; // update last position
                allocated = 1;
                break;
            }
        }
        if (!allocated) {
            processAllocated[i] = -1; // Not Allocated
        }
    }

    // Output allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (processAllocated[i] != -1)
            printf("%d\n", processAllocated[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}





##################





#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], ct[n], tat[n], wt[n], status[n];
    float avg_tat = 0, avg_wt = 0;

    // Input
    for (int i = 0; i < n; i++) {
        printf("Enter AT, BT and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        status[i] = 0; // 0 = not completed, 1 = completed
    }

    int time = 0, completed = 0;

    // Priority Scheduling (Non-preemptive)
    while (completed < n) {
        int idx = -1;
        int best_pr = 1e9;

        // Pick available process with highest priority (lowest PR value)
        for (int i = 0; i < n; i++) {
            if (!status[i] && at[i] <= time) {
                if (pr[i] < best_pr) {
                    best_pr = pr[i];
                    idx = i;
                }
            }
        }

        // If no process available, move time forward
        if (idx == -1) {
            time++;
            continue;
        }

        // Run chosen process
        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        status[idx] = 1;
        completed++;
    }

    // Print results
    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f", avg_tat / n);
    printf("\nAverage WT  = %.2f\n", avg_wt / n);

    return 0;
}



















###################
























