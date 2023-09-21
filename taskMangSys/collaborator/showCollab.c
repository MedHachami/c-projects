#include "collaboratorMenu.h"

void showCollab(sqlite3* db){
    int rc;
    sqlite3_stmt *stmt ;

    const char * sql = "SELECT * from collaborator ;";

    rc = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
    }

    printf("\t\t\t\t\t************************COLLABORATORS**********************\n");
    while((rc = sqlite3_step(stmt)) == SQLITE_ROW){
        int id = sqlite3_column_int(stmt,0);
        const char* fullName = (const char*)sqlite3_column_text(stmt,1);
        const char* email = (const char*)sqlite3_column_text(stmt,2);
        

        printf("\t\t\t\t\t %d ,  %s , %s \n", id, fullName,email);
        printf("\t\t\t\t\t--------------------------------------\n");
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        
    }
}