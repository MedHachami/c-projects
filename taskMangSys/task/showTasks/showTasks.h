#include<stdio.h>
#include<linux/string.h>


#include "../../initDB/initDB.h"
#include "../../task.h"


extern int showTasks(sqlite3*);
extern void showTasksOrderByName(sqlite3*);
extern void showTasksOrderByDeadline(sqlite3*);
extern void deadlineTdays(sqlite3*);