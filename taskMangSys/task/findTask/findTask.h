#include<stdio.h>
#include<linux/string.h>


#include "../../initDB/initDB.h"
#include "../../task.h"

extern int findTask(sqlite3*);
extern void findById(sqlite3*);
extern void findByName(sqlite3*);
