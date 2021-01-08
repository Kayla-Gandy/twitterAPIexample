/*
* Author:   Kayla Gandy
* File:     DataProcessing.hpp
* Project:  TwitterAPIProj
*/
#ifndef TWIT_PROJ_KG
#define TWIT_PROJ_KG

#include <Twitconfig.h>
#include <twitcurl.h>
#include <oauthlib.h>
#include <nlohmann/json.hpp>

namespace twit_data{

void test_func()
{
    auto twt_obj = twitCurl();
    // twt_obj.getOAuth().setConsumerKey(TWITTER_API_KEY);
    // twt_obj.getOAuth().setConsumerSecret(TWITTER_SECRET_KEY);
    std::cout << "uwu" << std::endl;
}

}// twit_data

#endif // TWIT_PROJ_KG