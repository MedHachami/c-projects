#include<stdio.h>
#include<linux/string.h>


#include "../initDB/initDB.h"
#include "../task.h"
#include "../collaborator.h"

extern int collab();
extern int addCollab(sqlite3*);
extern int updateCollab(sqlite3*);
extern void showCollab(sqlite3*);
extern int deleteCollab(sqlite3*);
