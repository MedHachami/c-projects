#include "taskCollab.h"

int taskCollab(){
    int choice,rc;
    char another;
    sqlite3* db = NULL;
    rc = initDb(&db);
    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return rc;
    }
    while(1){
        printf("\t\t\t\t\t****************\033[31mTASK Collaborators\033[0m***************************\n");
        printf("\t\t\t\t\t\t\t 1 : Task-Collaborators  \n");
        printf("\t\t\t\t\t\t\t 2 : Done Tasks \n");
        printf("\t\t\t\t\t\t\t 3 : Back \n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1 :
            printf("\e[1;1H\e[2J");
            showTaskCollab(db);
        break;
        case 2 :
            printf("\e[1;1H\e[2J");
            doneTaskCollab(db);
        break;
        case 3 :
            return 0;
        break;
        }
    }
}