#pragma once

#include <cpr/cpr.h>

class CurlPostHandler
{
public:
    CurlPostHandler(cpr::Url url);

    void Request(int n, long long fn);

private:
    cpr::Response r;
    cpr::Url PostUrl;
};