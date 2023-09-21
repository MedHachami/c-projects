#include "./showTasks.h"

void deadlineTdays(sqlite3* db){
     int rc;
    sqlite3_stmt *stmt ;

    const char * sql = "SELECT * FROM Task WHERE dueDate BETWEEN date('now') AND date('now', '+3 days');";

    rc = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
    }

    printf("\t\t\t\t\t************************TASKS**********************\n");
    while((rc = sqlite3_step(stmt)) == SQLITE_ROW){
        int id = sqlite3_column_int(stmt,0);
        const char* taskName = (const char*)sqlite3_column_text(stmt,1);
        const char* description = (const char*)sqlite3_column_text(stmt,2);
        const char* status = (const char*)sqlite3_column_text(stmt,3);
        const char* dueDate = (const char*)sqlite3_column_text(stmt,4);

        printf("\t\t\t\t\t %d ,  %s , %s ,%s ,%s \n", id, taskName,description,status,dueDate);
        printf("\t\t\t\t\t--------------------------------------\n");
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        
    }
}