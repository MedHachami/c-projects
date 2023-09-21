#include "./stats.h"

void completeIncTask(sqlite3* db) {
    int rc1, rc2;
    sqlite3_stmt* stmt1 = NULL;
    sqlite3_stmt* stmt2 = NULL;

    const char* sqlcompleteTask = "SELECT COUNT(*) FROM Task WHERE status = 'Done';";
    const char* sqlIncTask = "SELECT COUNT(*) FROM Task WHERE status != 'Done';";

    rc1 = sqlite3_prepare_v2(db, sqlcompleteTask, -1, &stmt1, NULL);
    rc2 = sqlite3_prepare_v2(db, sqlIncTask, -1, &stmt2, NULL);

    if (rc1 != SQLITE_OK || rc2 != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt1);
        sqlite3_finalize(stmt2);
        sqlite3_close(db);
        return; // Exit the function on error
    }

    rc1 = sqlite3_step(stmt1);
    rc2 = sqlite3_step(stmt2);

    printf("\t\t\t\t\t************************TASKS**********************\n");

    if (rc1 == SQLITE_ROW && rc2 == SQLITE_ROW) {
        int taskCompleted = sqlite3_column_int(stmt1, 0);
        int taskIncompleted = sqlite3_column_int(stmt2, 0);

        printf("\t\t\t\t\t Complete Task: %d , Incomplete Task %d  \n", taskCompleted, taskIncompleted);
        printf("\t\t\t\t\t------------------------------------------------\n");
    }

    sqlite3_finalize(stmt1);
    sqlite3_finalize(stmt2);
}
