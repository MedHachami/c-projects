#include<stdio.h>
#include<linux/string.h>


#include "../initDB/initDB.h"
#include "../task.h"
extern int task();
extern int addTask(sqlite3*);
extern int updateTask(sqlite3*);
extern int assignTask(sqlite3*);
extern int getUserDetails(sqlite3*);