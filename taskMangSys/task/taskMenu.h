#include<stdio.h>
#include<linux/string.h>
#include "../initDB/initDB.h"
#include "../task.h"
extern int task();
extern int addTask(sqlite3*);
extern int updateTask();
extern int assignTask();
extern int getUserDetails();