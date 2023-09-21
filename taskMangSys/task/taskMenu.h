#include<stdio.h>
#include<linux/string.h>


#include "../initDB/initDB.h"

#include "../task.h"
#include "../collaborator.h"

#include "./showTasks/showTasks.h"
#include "./findTask/findTask.h"
#include "./stats/stats.h"
extern int task();
extern int addTask(sqlite3*);
extern int updateTask(sqlite3*);
extern int deleteTask(sqlite3*);
extern void assignTask(sqlite3*);
// extern void taskCollab(sqlite3*)

