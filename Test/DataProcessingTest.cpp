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
    auto trend_json = twit_data::trend_analysis(twt_obj);
    std::cout << trend_json.dump() << std::endl;
    return 0;
}