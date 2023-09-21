#include "./stats.h"

void remainingDays(sqlite3* db){
    sqlite3_stmt* stmt;
    const char* sql = "SELECT id, dueDate FROM Task;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return;
    }

    printf("\t\t\t\t\t************************TASKS**********************\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int taskId = sqlite3_column_int(stmt, 0);
        const char* dueDateString = (const char*)sqlite3_column_text(stmt, 1);

        struct tm currentTime;
        time_t now;

         // Get the current time as a time_t value
        time(&now);
        // Convert the time_t value to the local time structure using localtime_r
        localtime_r(&now, &currentTime);

        struct tm dueTime;
        memset(&dueTime, 0, sizeof(struct tm));

        // Parse the date string manually
        if (sscanf(dueDateString, "%d-%d-%d", &dueTime.tm_year, &dueTime.tm_mon, &dueTime.tm_mday) == 3) {
            dueTime.tm_year -= 1900; // Adjust year
            dueTime.tm_mon -= 1;     // Adjust month
            time_t currentTimeEpoch = mktime(&currentTime);
            time_t dueTimeEpoch = mktime(&dueTime);

            if (dueTimeEpoch != -1 && currentTimeEpoch != -1) {
                double secondsRemaining = difftime(dueTimeEpoch, currentTimeEpoch);
                int daysRemaining = (int)(secondsRemaining / (60 * 60 * 24));

                printf("\t\t\t\t\tTask ID: %d\n", taskId);
                printf("\t\t\t\t\tDays Remaining: %d\n", daysRemaining);
                printf("\t\t\t\t\t------------------------------------------------\n");
            }
        } else {
            fprintf(stderr, "Error parsing date: %s\n", dueDateString);
        }
    }

    sqlite3_finalize(stmt);
}