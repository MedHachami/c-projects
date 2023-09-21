#include "main.h"

int main(){
    
    int choice,rc;
    sqlite3* db = NULL;
    rc = initDb(&db);
    if(rc != SQLITE_OK){
        return 1;
    }
    
    while(1){
        printf("\t\t\t\t\t****************\033[31mTASK MANAGEMENT SYSTEM\033[0m**************\n");
        printf("\t\t\t\t\t\t\t  1 : TASK  \n");
        printf("\t\t\t\t\t\t\t  2 : COLLABORATORS  \n");
        printf("\t\t\t\t\t\t\t  3 : Tasks-Collaborators  \n");
        printf("\t\t\t\t\t\t\t  4 : Exit  \n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1 :
            task();
            
            break;
        case 2 :
            collab();
            break;
        case 3 :
            taskCollab(db);
            break;
        case 4 :
            return 0;
            break;
        
        default:
            printf("\t\t\t\t\t\t\t Invalid choice \n");
            break;
        }
    }
    
}