/*
* Author:   Kayla Gandy
* File:     DataProcessingTest.cpp
* Project:  TwitterAPIProj
*/

#include <iostream>
#include <DataProcessing.hpp>


int main()
{
    auto twt_obj = twitCurl();
    twit_data::authenticate_twitcurl_obj(twt_obj, "../authentication.json");
    auto trend_json = twit_data::search_petitions(twt_obj, "blm", 1);
    std::cout << trend_json.size() << std::endl;
    return 0;
}