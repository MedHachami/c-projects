#include "./stats.h"

void countTask(sqlite3* db) {
    int rc;
    sqlite3_stmt *stmt = NULL;

    const char *sql = "SELECT COUNT(*) FROM Task;";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt); // Clean up the statement
        sqlite3_close(db);
        return; // Exit the function on error
    }

    rc = sqlite3_step(stmt);

    printf("\t\t\t\t\t************************TASKS**********************\n");

    while (rc == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        

        printf("\t\t\t\t\t Number of Tasks : %d  \n", id);
        printf("\t\t\t\t\t------------------------------------------------\n");

        rc = sqlite3_step(stmt); // Move to the next row
    }

    sqlite3_finalize(stmt); // Clean up the statement
}

