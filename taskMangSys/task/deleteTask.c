#include "taskMenu.h"

int deleteTask(sqlite3* db){
    
    int rc,targetID;
    sqlite3_stmt *stmt ;
    
    printf("\t\t\t\t\t\t Enter task id: \n");
    scanf("%d", &targetID);

    

    const char * sql = "DELETE FROM Task  where ID = ?;";
                    

    rc = sqlite3_prepare_v2(db, sql,-1, &stmt,NULL);
    
    if (rc == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1,targetID);

        rc = sqlite3_step(stmt);
        
        if (rc == SQLITE_DONE) {
            return 0;
        } else {
            fprintf(stderr, "DELETE failed: %s\n", sqlite3_errmsg(db));
            return 1;
        }
        
        sqlite3_finalize(stmt); // Clean up the statement
    } else {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    
    
    
}

