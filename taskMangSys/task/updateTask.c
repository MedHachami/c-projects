#include "taskMenu.h"

int updateTask(sqlite3* db){
    struct Task newTask;
    int rc;
    char status[20];
    sqlite3_stmt *stmt ;
    
    printf("\t\t\t\t\t\t Enter task id: \n");
    scanf("%d", &newTask.id);

    printf("\t\t\t\t\t\t Enter description : \n");
    scanf(" %[^\n]s", newTask.description);

    printf("\t\t\t\t\t\t Enter due Date (YYYY-MM-DD): \n");
    scanf(" %[^\n]s", newTask.dueDate);

    printf("\t\t\t\t\t\t Enter task status \n ");
    scanf(" %[^\n]s", status);

    const char * sql = "UPDATE Task SET description = ?, status = ?,dueDate = ? where ID = ?;";
                    

    rc = sqlite3_prepare_v2(db, sql,-1, &stmt,NULL);
    
    if (rc == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1,newTask.description,-1,SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2,status,-1,SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3,newTask.dueDate,-1,SQLITE_STATIC);
        sqlite3_bind_int(stmt, 4,newTask.id);

        rc = sqlite3_step(stmt);
        
        if (rc == SQLITE_DONE) {
            return 0;
        } else {
            fprintf(stderr, "UPDATE failed: %s\n", sqlite3_errmsg(db));
            return 1;
        }
        
        sqlite3_finalize(stmt); // Clean up the statement
    } else {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    
    
    
}

