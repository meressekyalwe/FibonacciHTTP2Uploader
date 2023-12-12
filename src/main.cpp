#include <iostream>
#include <ctime>
#include "database.h"
#include "CurlPostHandler.h"


#define DATABASE_FILE "fibonacci.db"
#define SERVER_URL "http://www.httpbin.org/post"


long long fibonacci(int n) 
{
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long f1 = 0;
    long long f2 = 1;
    long long result = 0;

    for (int i = 2; i <= n; ++i) 
    {
        result = f1 + f2;
        f1 = f2;
        f2 = result;
    }

    return result;
}

int main()
{  
    Database db(DATABASE_FILE);

    CurlPostHandler cp(cpr::Url(SERVER_URL));

    int n = 0;

    while (true)
    {
        int delay = 1;

        delay *= CLOCKS_PER_SEC;

        clock_t now = clock();

        db.Update(n + 1, fibonacci(n));
        cp.Request(n + 1, fibonacci(n));

        n += 1;

        while(clock() - now < delay);       
    }

    return 0;
}