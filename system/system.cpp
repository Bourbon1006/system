#include <stdio.h>
#include <string.h>

// 进程控制块（PCB）的结构
struct PCB {
    int ID;
    int PRIORITY;
    int CPUTIME;
    int ALLTIME;
    char STATE[10];
};

// 打印当前状态
void printState(struct PCB queue[], int size) {
    int highestPriorityIndex = 0;
    for (int i = 1; i < size; i++) {
        if (strcmp(queue[i].STATE, "ready") == 0 &&
            queue[i].PRIORITY > queue[highestPriorityIndex].PRIORITY) {
            highestPriorityIndex = i;
        }
    }
    printf("当前正运行的进程: %d\n", queue[highestPriorityIndex].ID);
    printf("当前就绪队列: ");
    for (int i = 0; i < size; i++) {
        if (strcmp(queue[i].STATE, "ready") == 0) {
            printf("%d, ", queue[i].ID);
        }
    }
    printf("\n");
}

int main() {
    struct PCB readyQueue[5];
    int numProcesses = 5;

    // 初始化5个进程
    readyQueue[0] = { 0, 9, 0, 3, "ready" };
    readyQueue[1] = { 1, 30, 0, 6, "ready" };
    readyQueue[2] = { 2, 38, 0, 3, "ready" };
    readyQueue[3] = { 3, 29, 0, 9, "ready" };
    readyQueue[4] = { 4, 0, 0, 4, "ready" };

    //printState(readyQueue, numProcesses);
    while (numProcesses > 0) 
    {

        // 输出当前状态
        printState(readyQueue, numProcesses);

        // 寻找优先数最大的就绪进程
        int highestPriorityIndex = 0;
        for (int i = 1; i < numProcesses; i++) 
        {
            if (strcmp(readyQueue[i].STATE, "ready") == 0 && readyQueue[i].PRIORITY > readyQueue[highestPriorityIndex].PRIORITY) 
            {
                highestPriorityIndex = i;
            }
        }

        // 运行当前进程一个时间片
        readyQueue[highestPriorityIndex].CPUTIME += 1;
        readyQueue[highestPriorityIndex].ALLTIME -= 1;

        // 减小优先数
        readyQueue[highestPriorityIndex].PRIORITY -= 3;

        // 如果进程已完成，将其从数组中删除
        if (readyQueue[highestPriorityIndex].ALLTIME <= 0) 
        {
            strcpy_s(readyQueue[highestPriorityIndex].STATE, "completed");

            // 从数组中删除进程，将后续元素向前移动
            for (int i = highestPriorityIndex; i < numProcesses - 1; i++) 
            {
                readyQueue[i] = readyQueue[i + 1];
            }
            numProcesses--;
        }
    }
    if (numProcesses == 0)
    {
        printf("所以进程已结束！");
    }
    return 0;
}