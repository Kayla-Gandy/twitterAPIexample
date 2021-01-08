/*
* Author:   Kayla Gandy
* File:     DataProcessing.hpp
* Project:  TwitterAPIProj
*/
#ifndef TWIT_PROJ_KG
#define TWIT_PROJ_KG

#include <twitcurl.h>
#include <oauthlib.h>
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>
#include <iostream>

namespace twit_data{

class APIKeys{
    std::string _API_key;
    std::string _API_secret_key;
    std::string _bearer_token;
public:
    APIKeys() = default;
    explicit APIKeys(const nlohmann::json& json_containing_keys):
            APIKeys(from_json(json_containing_keys)){}
    APIKeys(const std::string& API_key, const std::string& API_secret_key, const std::string& bearer_token):
        _API_key{API_key}, _API_secret_key{API_secret_key}, _bearer_token{bearer_token} {}
    APIKeys(const APIKeys& keys) = default;
    APIKeys(APIKeys&& keys) = default;
    APIKeys& operator=(const APIKeys& keys) = default;
    APIKeys& operator=(APIKeys&& keys) = default;
    ~APIKeys() = default;
    [[nodiscard]] static APIKeys from_json(const nlohmann::json& json_containing_keys);
};

APIKeys parse_keys(const std::string& path_to_json);

void test_func()
{

    auto twt_obj = twitCurl();
    // twt_obj.getOAuth().setConsumerKey(TWITTER_API_KEY);
    // twt_obj.getOAuth().setConsumerSecret(TWITTER_SECRET_KEY);
    std::cout << "uwu" << std::endl;
}

}// twit_data

#endif // TWIT_PROJ_KG