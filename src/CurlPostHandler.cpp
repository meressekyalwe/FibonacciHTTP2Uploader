#include "CurlPostHandler.h"
#include <iostream>

CurlPostHandler::CurlPostHandler(cpr::Url url)
{
    r = cpr::Response();
    PostUrl = cpr::Url(url);
}

void CurlPostHandler::Request(int n, long long fn)
{ 
    r = cpr::Post(PostUrl, cpr::Payload{{std::to_string(n).c_str(), (int)fn}});

    std::cout << r.text << std::endl;
}
