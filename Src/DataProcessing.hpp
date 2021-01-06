#include <twitcurl.h>
#include <nlohmann/json.hpp>
#include <oauthlib.h>

namespace twit_data{

void test_func()
{
    nlohmann::json test_json;
    test_json["test"] = "OwO";
    std::cout << test_json.dump() << std::endl;
    std::cout << "uwu" << std::endl;
}

}//twit_data