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
#include <algorithm>
#include <fstream>
#include <optional>
#include <iostream>

namespace twit_data{

class APIAuth{
    std::string _username;
    std::string _password;
    std::string _API_key;
    std::string _API_secret_key;
    std::string _bearer_token;
    std::optional<std::string> _auth_secret;
    std::optional<std::string> _auth_key;
public:
    APIAuth() = default;
    explicit APIAuth(const nlohmann::json& json_containing_auth):
            APIAuth(from_json(json_containing_auth)){}
    APIAuth(const std::string& username, const std::string& password,
            const std::string& API_key, const std::string& API_secret_key,
            const std::string& bearer_token, const std::optional<std::string>& auth_secret,
            const std::optional<std::string>& auth_key):
        _username{username}, _password{password}, 
        _API_key{API_key}, _API_secret_key{API_secret_key},
        _bearer_token{bearer_token}, _auth_secret{auth_secret},
        _auth_key{auth_key} {}
    APIAuth(const APIAuth& auth) = default;
    APIAuth(APIAuth&& auth) = default;
    APIAuth& operator=(const APIAuth& auth) = default;
    APIAuth& operator=(APIAuth&& auth) = default;
    ~APIAuth() = default;
    [[nodiscard]] static APIAuth from_json(const nlohmann::json& json_containing_auth);

    [[nodiscard]] const std::string& get_username() const noexcept {
        return _username;
    }
    [[nodiscard]] const std::string& get_password() const noexcept {
        return _password;
    }
    [[nodiscard]] const std::string& get_API_key() const noexcept {
        return _API_key;
    }
    [[nodiscard]] const std::string& get_secret_key() const noexcept {
        return _API_secret_key;
    }
    [[nodiscard]] const std::string& get_bearer_token() const noexcept {
        return _bearer_token;
    }
    [[nodiscard]] const std::optional<std::string>& get_auth_secret() const noexcept {
        return _auth_secret;
    }
    [[nodiscard]] const std::optional<std::string>& get_auth_key() const noexcept {
        return _auth_key;
    }
};

void authenticate_twitcurl_obj(twitCurl& twt_obj, const std::string& path_to_json);
nlohmann::json search_petitions(twitCurl& twt_obj, std::string topic, const unsigned int num_results_saved = 20);

}// twit_data

#endif // TWIT_PROJ_KG