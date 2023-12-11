#pragma once
#include <sqlite3.h>
#include <string>


class Database
{
public:
    Database(std::string path);

    void CreateTable();

    void Update(int n, long long fn);

    ~Database();

private:
    sqlite3 *db = nullptr;
    int rc = 0;
};