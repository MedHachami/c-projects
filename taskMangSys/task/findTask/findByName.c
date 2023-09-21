#include "./findTask.h"

void findByName(sqlite3* db) {
    int rc;
    char name[20];
    sqlite3_stmt *stmt = NULL;

    const char *sql = "SELECT * FROM Task WHERE title = ?;";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt); // Clean up the statement
        sqlite3_close(db);
        return; // Exit the function on error
    }

    printf("\t\t\t\tEnter Task name: \n");
    scanf(" %[^\n]s", name);

    sqlite3_bind_text(stmt,1, name,-1,SQLITE_STATIC);
    rc = sqlite3_step(stmt);

    printf("\t\t\t\t\t************************TASKS**********************\n");

    while (rc == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *taskName = (const char *)sqlite3_column_text(stmt, 1);
        const char *description = (const char *)sqlite3_column_text(stmt, 2);
        const char *status = (const char *)sqlite3_column_text(stmt, 3);
        const char *dueDate = (const char *)sqlite3_column_text(stmt, 4);

        printf("\t\t\t\t\t %d ,  %s , %s , %s , %s \n", id, taskName, description, status, dueDate);
        printf("\t\t\t\t\t------------------------------------------------\n");

        rc = sqlite3_step(stmt); // Move to the next row
    }

    sqlite3_finalize(stmt); // Clean up the statement
}
