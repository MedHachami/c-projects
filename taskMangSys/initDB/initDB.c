#include "initDB.h"

int initDb(sqlite3** db){
    
    int rc = sqlite3_open("tasksDB.db",db);

    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(*db));
        return rc;
    }

    const char* table_Task = "CREATE TABLE IF NOT EXISTS task ("
                                "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                                "taskName TEXT NOT NULL ,"
                                "description TEXT NOT NULL ,"
                                "newDate TEXT NOT NULL ,"
                                "assignedToUser INTEGER NOT NULL ,"
                                "status TEXT NOT NULL "
                                ");";

    const char* table_User = "CREATE TABLE IF NOT EXISTS user ("
                                "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                                "userName TEXT NOT NULL ,"
                                "email TEXT NOT NULL "
                                ");";

    
    rc = sqlite3_exec(*db,table_Task,0,0,0);
    rc = sqlite3_exec(*db,table_User,0,0,0);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(*db));
        sqlite3_close(*db);
        return rc;
    }
    return SQLITE_OK;
}