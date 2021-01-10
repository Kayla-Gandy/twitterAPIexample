/*
* Author:   Kayla Gandy
* File:     DataProcessing.cpp
* Project:  TwitterAPIProj
*/

#include <DataProcessing.hpp>

twit_data::APIAuth twit_data::APIAuth::from_json(const nlohmann::json& json_containing_auth)
{
    if(json_containing_auth.size() < 7)
    {throw std::runtime_error("Provided JSON incorrectly formatted.");}

    std::string username = json_containing_auth.at("username"); 
    std::string password = json_containing_auth.at("password");
    std::string api_key = json_containing_auth.at("API key");
    std::string secret_key = json_containing_auth.at("API secret key");
    std::string bearer_token  = json_containing_auth.at("bearer token");
    std::string auth_secret  = json_containing_auth.at("authentication token secret");
    std::string auth_key  = json_containing_auth.at("authentication token key");

    return APIAuth(username, password, api_key, secret_key, bearer_token, auth_secret, auth_key);
}

void request_auth(twitCurl& twt_obj, nlohmann::json& auth_json)
{
    std::string auth_url{};
    twt_obj.oAuthRequestToken(auth_url);
    bool successful_auth = twt_obj.oAuthHandlePIN(auth_url);
    std::cout << successful_auth << std::endl;
    twt_obj.oAuthAccessToken();
    std::string auth_token_key{};
    twt_obj.getOAuth().getOAuthTokenKey(auth_token_key);
    std::string auth_token_secret{};
    twt_obj.getOAuth().getOAuthTokenSecret(auth_token_secret);
    auth_json["authentication token key"] = auth_token_key;
    auth_json["authentication token secret"] = auth_token_secret;
}

void twit_data::authenticate_twitcurl_obj(twitCurl& twt_obj, const std::string& path_to_json)
{
    APIAuth auth;
    try{
        std::ifstream json_in(path_to_json);
        if(!json_in.good())
        {throw std::runtime_error("Cannot find JSON given path.");}
        nlohmann::json auth_json = nlohmann::json::parse(json_in);
        auth = twit_data::APIAuth(auth_json);

        twt_obj.setTwitterUsername(auth.get_username());
        twt_obj.setTwitterPassword(auth.get_password());
        twt_obj.getOAuth().setConsumerKey(auth.get_API_key());
        twt_obj.getOAuth().setConsumerSecret(auth.get_secret_key());
        if(auth_json["authentication token key"].empty() || auth_json["authentication token secret"].empty())
        {
            request_auth(twt_obj, auth_json);
            std::ofstream json_out;
            json_out << auth_json;
        }
        twt_obj.getOAuth().setOAuthTokenSecret(auth.get_auth_secret());
        twt_obj.getOAuth().setOAuthTokenKey(auth.get_auth_key());
        
    } catch(const std::runtime_error& err)
    {
        std::cout << err.what() << std::endl;
        throw;
    }

    std::cout << "uwu" << std::endl;
}