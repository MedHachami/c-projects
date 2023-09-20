#include "initDB.h"

int initDb(sqlite3** db){
    
    int rc = sqlite3_open("tasksDB.db",db);

    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(*db));
        return rc;
    }

    const char* table_Task = "CREATE TABLE IF NOT EXISTS Task ("
                                "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                                "title TEXT NOT NULL ,"
                                "description TEXT NOT NULL ,"
                                "status TEXT NOT NULL ,"
                                "dueDate TEXT NOT NULL "
                                ");";

    const char* table_Collab = "CREATE TABLE IF NOT EXISTS Collaborator ("
                                "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                                "fullName TEXT NOT NULL ,"
                                "email TEXT NOT NULL "
                                ");";
    const char* tableTaskCollab = "CREATE TABLE IF NOT EXISTS TaskCollaborators("
                                "taskID INTEGER ,"
                                "collaboratorID INTEGER,"
                                "PRIMARY KEY (taskID, collaboratorID),"
                                "FOREIGN KEY (taskID) REFERENCES Tasks(ID),"
                                "FOREIGN KEY (collaboratorID) REFERENCES Collaborators(ID)"
                                ");";
   
    
    if(sqlite3_exec(*db,table_Task,0,0,0) != SQLITE_OK || sqlite3_exec(*db,table_Collab,0,0,0) || sqlite3_exec(*db,tableTaskCollab,0,0,0)){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(*db));
        sqlite3_close(*db);
        return rc;
    }
    return SQLITE_OK;
}