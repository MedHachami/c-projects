#include "./findTask.h"

int findTask(sqlite3* db){
    sqlite3* db1 = db;
    int choice;
    while(1){
        printf("\t\t\t\t\t****************\033[31mFind Task\033[0m****************************\n");
        printf("\t\t\t\t\t\t\t 1 : Find Task by id \n");
        printf("\t\t\t\t\t\t\t 2 : Find Task by  name  \n");
        printf("\t\t\t\t\t\t\t 3 : Back \n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1 :
            findById(db1);
        break;
        case 2 :
           findByName(db1);
        break;
        case 3 :
           return 0;
        break;
        
            printf("\t\t\t Invalid choice \n");
            break;
        }
    }
}