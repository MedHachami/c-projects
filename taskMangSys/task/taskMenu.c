#include "taskMenu.h"

int task(){
    int choice,rc;
    char another;
    sqlite3* db = NULL;
    rc = initDb(&db);
    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return rc;
    }
    while(1){
        printf("\t\t\t\t\t****************\033[31mTASK MENU\033[0m***************************\n");
        printf("\t\t\t\t\t\t\t 1 : Add new task  \n");
        printf("\t\t\t\t\t\t\t 2 : Update Task  \n");
        printf("\t\t\t\t\t\t\t 3 : Change Status \n");
        printf("\t\t\t\t\t\t\t 4 : Get User Details  \n");
        printf("\t\t\t\t\t\t\t 5 : Assing Task to Collaborator \n");
        printf("\t\t\t\t\t\t\t 6 : Back \n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1 :
                int addResult = addTask(db);
                if(addResult == 0){
                    printf("\t\t\t\t\t\t\t Task added successfully\n");
                }
        break;
        case 2 :
            int editResult = updateTask(db);
            if(editResult == 0){
                printf("\t\t\t\t\t\t\t Task edit successfully");
            }
            break;
        // case 3 :
        //     changeStatus();
        //     break;
        // case 4 :
        //     assignTask();
        //     break;
        // case 5 :
        //     getUserDetails();
        //     break;
        case 6 :
            return 0;
        
        default:
            printf("\t\t\t Invalid choice \n");
            break;
        }
    }
}