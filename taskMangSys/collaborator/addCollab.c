#include "collaboratorMenu.h"



int  addCollab(sqlite3* db){
    
    sqlite3_stmt* stmt;
    int rc;
    
    struct Collaborator newCollab;
    
        const char* sql = "INSERT INTO Collaborator(fullName,email) VALUES(?,?);";

    rc = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        printf("tttt");
        return 1;
    }
    // strcpy(newTask.status, "To do");
    printf("\t\t\t\t\t****************\033[31mADD COLLABORATOR\033[0m***************************\n");
    printf("\t\t\t\tEnter collaborator full name: \n");
    scanf(" %[^\n]s", newCollab.fullName);

    printf("\t\t\t\tEnter collaborator email : \n");
    scanf(" %[^\n]s", newCollab.email);

    

    // getchar(); 
    sqlite3_bind_text(stmt,1, newCollab.fullName,-1,SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, newCollab.email, -1, SQLITE_STATIC);
    
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        printf("aaaa");
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 2;
    }
    
    sqlite3_finalize(stmt);
    
    
    
    return 0;
    
    
}