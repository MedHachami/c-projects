#include "taskMenu.h"

struct Task* searchTaskById(struct Task tasks[], int numTasks, int targetId) {
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == targetId) {
            return &tasks[i]; // Return a pointer to the matching Task
        }
    }
    return NULL; // Return NULL if no matching Task is found
}
struct Collaborator* searchCollabById(struct Collaborator collabs[], int numcollab, int targetId) {
    for (int i = 0; i < numcollab; i++) {
        if (collabs[i].id == targetId) {
            return &collabs[i]; // Return a pointer to the matching Task
        }
    }
    return NULL; // Return NULL if no matching Task is found
}

void assignTask(sqlite3* db){
    struct Task tasks[50];
    struct Collaborator collabs[50];
    int rc1, rc2;
    sqlite3_stmt* stmt1 = NULL;
    sqlite3_stmt* stmt2 = NULL;

    const char* sqlTable_Task = "SELECT * FROM Task";
    const char* sqlTable_Collab = "SELECT * from Collaborator ;";

    rc1 = sqlite3_prepare_v2(db, sqlTable_Task, -1, &stmt1, NULL);
    rc2 = sqlite3_prepare_v2(db, sqlTable_Collab, -1, &stmt2, NULL);

    if (rc1 != SQLITE_OK || rc2 != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt1);
        sqlite3_finalize(stmt2);
        sqlite3_close(db);
        return; // Exit the function on error
    }

    printf("\t\t\t\t\t****************\033[31mASIGN TASK\033[0m***************************\n");

    
    printf("\t\t\t\t\t Task :\n");
    int i=0,numTasks=1;
    while((rc1 = sqlite3_step(stmt1)) == SQLITE_ROW){
        int idTask = sqlite3_column_int(stmt1,0);
        const char* taskName = (const char*)sqlite3_column_text(stmt1,1);
        const char* description = (const char*)sqlite3_column_text(stmt1,2);
        const char* status = (const char*)sqlite3_column_text(stmt1,3);
        const char* dueDate = (const char*)sqlite3_column_text(stmt1,4);
        tasks[i].id = idTask;
        strcpy(tasks[i].title,taskName);
        strcpy(tasks[i].description,description);
        strcpy(tasks[i].status,status);
        i++;
        numTasks++;
        printf("\t\t\t\t\t %d ,  %s , %s ,%s ,%s \n", idTask, taskName,description,status,dueDate);
        printf("\t\t\t\t\t--------------------------------------\n");
    }
    
    

    printf("\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t Collaborator :\n");
    int j=0,numCollab=1;
    while ((rc2 = sqlite3_step(stmt2)) == SQLITE_ROW) {
       
       int idCollab = sqlite3_column_int(stmt2,0);
        const char* fullName = (const char*)sqlite3_column_text(stmt2,1);
        const char* email = (const char*)sqlite3_column_text(stmt2,2);
        
        collabs[j].id = idCollab;
        strcpy(collabs[j].fullName,fullName);
        strcpy(collabs[j].email,email);
        j++;
        numCollab++;

        printf("\t\t\t\t\t %d ,  %s , %s \n", idCollab, fullName,email);
        printf("\t\t\t\t\t--------------------------------------\n");
        
        
    }

    

    int taskTargetID,collabTargetID;
    printf("\t\t\t\t\t Assigning task to collaborator :\n");
    printf("\t\t\t\t\t Enter task id :\n");
    scanf("%d",&taskTargetID);

    printf("\t\t\t\t\t Enter collaborator id :\n");
    scanf("%d",&collabTargetID);

    sqlite3_stmt* stmt;
    int rc;
    const char* sql = "INSERT INTO TaskCollaborators(taskID,collaboratorID) VALUES(?,?);";

    rc = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        
    }

    sqlite3_bind_int(stmt,1,taskTargetID);
    sqlite3_bind_int(stmt,2,collabTargetID);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        
    }
    
    struct Task* foundTask = searchTaskById(tasks, numTasks, taskTargetID);
    struct Collaborator* foundCollab = searchCollabById(collabs, numCollab, collabTargetID);
    
    if(foundTask != NULL && foundCollab != NULL)
    printf("\t\t\t\t\t Task %s assigned to %s :\n",foundTask->title,foundCollab->fullName);
    else printf("\t\t\t\t\t Not found :\n");

    sqlite3_finalize(stmt);
    sqlite3_finalize(stmt1);
    sqlite3_finalize(stmt2);
    

}