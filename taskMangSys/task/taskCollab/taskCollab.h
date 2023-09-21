#include<stdio.h>
#include<linux/string.h>
#include <time.h>

#include "../../initDB/initDB.h"
#include "../../task.h"


extern int taskCollab();
extern void showTaskCollab(sqlite3*);
extern void doneTaskCollab(sqlite3*);