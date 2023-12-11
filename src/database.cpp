#include "database.h"

Database::Database(std::string path)
{
    rc = sqlite3_open(path.c_str(), &db);

    if(rc) 
    {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

    } 
    else 
    {
      fprintf(stderr, "Opened database successfully\n");
    }

    rc = 0;
    CreateTable();
}

void Database::CreateTable()
{
    char *zErrMsg = nullptr;
    const char* sql = "CREATE TABLE FIBONACCI_SEQUENCE(n INTEGER, Fn INTEGER);";

    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Table created successfully\n");
    }

    rc = 0;
}

void Database::Update(int n, long long fn)
{   
    char *zErrMsg = 0;

    fprintf(stdout, "Values received: n=%d, fn=%lld\n", n, fn);

    std::string sql = "INSERT INTO FIBONACCI_SEQUENCE (n, Fn) VALUES (" + std::to_string(n) + "," + std::to_string(fn) + ");";

    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Records created successfully\n");
    }

    rc = 0;
}

Database::~Database()
{
    sqlite3_close(db);
}
