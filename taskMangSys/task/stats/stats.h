#include<stdio.h>
#include<linux/string.h>
#include <time.h>

#include "../../initDB/initDB.h"
#include "../../task.h"

extern int stats(sqlite3*);
extern void countTask(sqlite3*);
extern void completeIncTask(sqlite3*);
extern void remainingDays(sqlite3*);