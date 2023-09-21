#include "./showTasks.h"

int showTasks(sqlite3* db){
    sqlite3* db1 = db;
    int choice;
    while(1){
        printf("\t\t\t\t\t****************\033[31mTasks lists\033[0m****************************\n");
        printf("\t\t\t\t\t\t\t 1 : Sort tasks alphabetically.  \n");
        printf("\t\t\t\t\t\t\t 2 : Sort tasks by deadline  \n");
        printf("\t\t\t\t\t\t\t 3 : Show tasks whose deadline is in 3 days or less. \n");
        printf("\t\t\t\t\t\t\t 4 : Back \n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1 :
            showTasksOrderByName(db1);
        break;
        case 2 :
            showTasksOrderByDeadline(db1);
        break;
        case 3 :
            deadlineTdays(db1);
        break;
        case 4:
            return 0;
        default:
            printf("\t\t\t Invalid choice \n");
            break;
        }
    }
}