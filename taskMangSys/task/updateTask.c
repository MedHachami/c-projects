#include "taskMenu.h"

int updateTask(sqlite3* db){
    struct Task newTask;
    int rc;
    sqlite3_stmt *stmt ;
    const char * sql = "UPDATE task SET taskName = ? , description = ? WHERE ID = ?;";

    rc = sqlite3_prepare_v2(db, sql,-1, &stmt,NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        printf("tttt");
        return rc;
    }

    printf("\t\t\t\tEnter task  id  : \n");
    scanf("%d",&newTask.id);

    printf("\t\t\t\tEnter task name : \n");
    scanf("%s",newTask.title);

    printf("\t\t\t\tEnter description : \n");
    scanf("%s",newTask.description);

    sqlite3_bind_text(stmt,1,newTask.title,-1,SQLITE_STATIC);
    sqlite3_bind_text(stmt,1,newTask.description,-1,SQLITE_STATIC);
    sqlite3_bind_int(stmt,3,newTask.id);
    rc = sqlite3_step(stmt);
    if(rc != SQLITE_OK){
        printf("aaaa");
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);

    return rc;
    
    
    
}