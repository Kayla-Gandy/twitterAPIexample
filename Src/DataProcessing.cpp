/*
* Author:   Kayla Gandy
* File:     DataProcessing.cpp
* Project:  TwitterAPIProj
*/

#include <DataProcessing.hpp>

twit_data::APIKeys twit_data::APIKeys::from_json(const nlohmann::json& json_containing_keys)
{
    if(json_containing_keys.size() < 3)
    {throw std::runtime_error("Provided JSON incorrectly formatted.");}

    std::string api_key = json_containing_keys.at("API Key");
    std::string secret_key = json_containing_keys.at("API Secret Key");
    std::string bearer_token  = json_containing_keys.at("Bearer Token");

    return APIKeys(api_key, secret_key, bearer_token);
}

twit_data::APIKeys twit_data::parse_keys(const std::string& path_to_json)
{
    std::ifstream json_strm(path_to_json);
    if(!json_strm.good())
    {throw std::runtime_error("Cannot find JSON given path.");}
    nlohmann::json key_json = nlohmann::json::parse(json_strm);
    return APIKeys(key_json);
}