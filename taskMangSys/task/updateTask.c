#include "taskMenu.h"

int updateTask(sqlite3* db){
    struct Task newTask;
    int rc;
    sqlite3_stmt *stmt ;
    
    printf("Enter task id: \n");
    scanf("%d", &newTask.id);

    printf("\t\t\t\tEnter description : \n");
    scanf(" %[^\n]s", newTask.description);

    printf("\t\t\t\tEnter due Date (YYYY-MM-DD): \n");
    scanf(" %[^\n]s", newTask.dueDate);

    // printf("Enter task status \n ");
    // scanf("%19s", newTask.som);

    // newTask.id = 1;
    // strcpy(newTask.description,"sdds");
    // strcpy(newTask.dueDate,"2020-11-11");
     strcpy(newTask.som,"done");

    printf("\t\t\t task  id  : %d \n",newTask.id);
    
    printf("\t\t\t\tEdit task description %s : \n",newTask.description);
    

    printf("\t\t\t\tEdit task deadline :%s  \n",newTask.dueDate);
    

    printf("\t\t\t\tEdit task status :  %s \n",newTask.som );
    

    

    
    // getchar();
    // const char * sql = "UPDATE Task SET description = ?,"
    //                 "status = ?, "
    //                 "dueDate = ? ,"
    //                 "WHERE ID = ?;";

    // rc = sqlite3_prepare_v2(db, sql,-1, &stmt,NULL);
    
    // if (rc == SQLITE_OK) {
    //     sqlite3_bind_text(stmt, 1,newTask.description,-1,SQLITE_STATIC);
    //     sqlite3_bind_text(stmt, 2,newTask.statu,-1,SQLITE_STATIC);
    //     sqlite3_bind_text(stmt, 3,newTask.dueDate,-1,SQLITE_STATIC);
    //     sqlite3_bind_int(stmt, 4,newTask.id);

    //     rc = sqlite3_step(stmt);
        
    //     if (rc == SQLITE_DONE) {
    //         // UPDATE statement executed successfully
    //         printf("UPDATE successful\n");
    //     } else {
    //         fprintf(stderr, "UPDATE failed: %s\n", sqlite3_errmsg(db));
    //     }
        
    //     sqlite3_finalize(stmt); // Clean up the statement
    // } else {
    //     fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    // }
    
    
    
}

