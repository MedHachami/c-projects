#include "taskMenu.h"

int addTask(sqlite3* db){
    
    sqlite3_stmt* stmt;
    int rc;
    struct Task newTask;
    const char* sql = "INSERT INTO task(taskName,description,newDate,assignedToUser,status) VALUES(?,?,?,?,?);";

    rc = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        printf("tttt");
        return rc;
    }
    printf("\t\t\t\tEnter task name : \n");
    scanf("%s",newTask.title);

    printf("\t\t\t\tEnter description : \n");
    scanf("%s",newTask.description);

    printf("\t\t\t\tEnter due Date  : \n");
    scanf("%s",newTask.dueDate);

    printf("\t\t\t\tEnter assigned id  : \n");
    scanf("%d",&newTask.assignedToUser);

    strcpy(newTask.status, "To do");

    sqlite3_bind_text(stmt,1,newTask.title,-1,SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, newTask.description, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, newTask.dueDate, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, newTask.assignedToUser);
    sqlite3_bind_text(stmt,5,newTask.status,-1,SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
       printf("aaaa");
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
    
    return rc;
}