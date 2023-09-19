
#ifndef TASK_H
#define TASK_H

struct Task {
    int id;
    char title[20];
    char description[50];
    char dueDate[10];
    int assignedToUser;
    char status[15];
    
};

#endif
