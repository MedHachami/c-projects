#include "collaboratorMenu.h"

int collab(){
    int choice,rc;
    char another;
    sqlite3* db = NULL;
    rc = initDb(&db);
    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return rc;
    }
    while(1){
        printf("\t\t\t\t\t****************\033[31mCOLLABORATOR MENU\033[0m***************************\n");
        printf("\t\t\t\t\t\t\t 1 : Add collaborator \n");
        printf("\t\t\t\t\t\t\t 2 : Update collaborator  \n");
        printf("\t\t\t\t\t\t\t 3 : Show collaborators \n");
        printf("\t\t\t\t\t\t\t 4 : Delete collaborator \n");
        printf("\t\t\t\t\t\t\t 5 : Back \n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1 :
                int addResult = addCollab(db);
                if(addResult == 0){
                     printf("\t\t\t\t\t\t\t Collaborator added successfully\n");
                }
        break;
        case 2 :
            int updateResult = updateCollab(db);
                if(updateResult == 0){
                     printf("\t\t\t\t\t\t\t Collaborator updated successfully\n");
                }
        break;
        case 3 :
            showCollab(db);
        break;
        case 4 :
            int deleteResult = deleteCollab(db);
            if(deleteResult == 0){
                     printf("\t\t\t\t\t\t\t Collaborator deleted successfully\n");
            }
            break;
        case 5 :
            return 0;

        default:
            printf("\t\t\t Invalid choice \n");
            break;
        }
    }
}