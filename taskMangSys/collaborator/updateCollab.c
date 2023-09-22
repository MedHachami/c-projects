#include "collaboratorMenu.h"

int updateCollab(sqlite3* db){
    struct Collaborator newCollab;
    int rc;
    sqlite3_stmt *stmt ;
    printf("\t\t\t\t\t****************\033[31mUPDATE COLLABORATOR\033[0m***************************\n");
    printf("\t\t\t\t\t\t Enter collaborator id: \n");
    scanf("%d", &newCollab.id);

    printf("\t\t\t\t\t\t Enter full name : \n");
    scanf(" %[^\n]s", newCollab.fullName);

    printf("\t\t\t\t\t\t Enter email: \n");
    scanf(" %[^\n]s", newCollab.email);

    
    const char * sql = "UPDATE collaborator SET fullName = ?, email = ? where ID = ?;";
                    

    rc = sqlite3_prepare_v2(db, sql,-1, &stmt,NULL);
    
    if (rc == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1,newCollab.fullName,-1,SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2,newCollab.email,-1,SQLITE_STATIC);
        sqlite3_bind_int(stmt, 3,newCollab.id);

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