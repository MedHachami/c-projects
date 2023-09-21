#include "taskMenu.h"

void taskCollab(sqlite3* db){
    int rc;
    sqlite3_stmt* stmt;
    
    const char *sql = "SELECT Task.title, Collaborator.fullName FROM Task, Collaborator, TaskCollaborators "
                     "WHERE Task.ID = TaskCollaborators.taskID AND TaskCollaborators.collaboratorID = Collaborator.ID;";
    rc = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);

    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
    }

    printf("\t\t\t\t\t************************TASKS**********************\n");
    while((rc = sqlite3_step(stmt)) == SQLITE_ROW){
        
        const char* taskTitle = (const char*)sqlite3_column_text(stmt,0);
        const char* colabName = (const char*)sqlite3_column_text(stmt,1);
        

        printf("\t\t\t\t\t %s ,  %s  \n", taskTitle,colabName);
        printf("\t\t\t\t\t--------------------------------------\n");
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        
    }
}