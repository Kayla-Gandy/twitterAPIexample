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
    return 0;
}