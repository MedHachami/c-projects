#include "stats.h"

int stats(sqlite3* db){
    sqlite3* db1 = db;
    int choice;
    while(1){
        printf("\t\t\t\t\t****************\033[31mTASK-STATS\033[0m****************************\n");
        printf("\t\t\t\t\t\t\t 1 : Number of tasks \n");
        printf("\t\t\t\t\t\t\t 2 : Complete and incomplete tasks.  \n");
        printf("\t\t\t\t\t\t\t 3 : Days remaining until each task's deadline.  \n");
        printf("\t\t\t\t\t\t\t 4 : Back \n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1 :
            printf("count");
        break;
        case 2 :
           printf("complete\n");
        break;
        case 3 :
           printf("remaining\n");
        break;
        case 4 :
            return 0;
        default :
            printf("\t\t\t Invalid choice \n");
        break;
        }
    }
}