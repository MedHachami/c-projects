#include "taskMenu.h"

int  addTask(sqlite3* db){
    printf("\t\t\t\t\t****************\033[31mADD TASK\033[0m***************************\n");
    sqlite3_stmt* stmt;
    int rc;
    
    struct Task newTask;
    
        const char* sql = "INSERT INTO Task(title,description,status,dueDate) VALUES(?,?,?,?);";

    rc = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        printf("tttt");
        return 1;
    }
    // strcpy(newTask.status, "To do");
    printf("\t\t\t\tEnter task name : \n");
    scanf(" %[^\n]s", newTask.title);

    printf("\t\t\t\tEnter description : \n");
    scanf(" %[^\n]s", newTask.description);

    printf("\t\t\t\tEnter due Date (YYYY-MM-DD): \n");
    scanf(" %[^\n]s", newTask.dueDate);

    // getchar(); 
    sqlite3_bind_text(stmt,1, newTask.title,-1,SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, newTask.description, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, "To do",-1,SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, newTask.dueDate, -1, SQLITE_STATIC);
    
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