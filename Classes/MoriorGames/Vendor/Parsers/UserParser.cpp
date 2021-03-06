#include "UserParser.h"
#include "../../Services/Sole.hpp"
#include "../../Definitions.h"

UserParser::UserParser(std::string json)
    : JsonParser(json)
{
}

User *UserParser::parse()
{
    if (document.HasMember(ROW) && document[ROW].IsObject()) {

        const Value &data = document[ROW];
        auto user = new User;
        addData(user, data);

        return user;
    }

    return nullptr;
}

void UserParser::addData(User *item, const rapidjson::Value &data)
{
    item->setId(getInt(data, "id"));
    item->setName(getString(data, "name"));
    item->setSlug(getString(data, "slug"));
    item->setToken(getString(data, "token"));
    item->setExperience(getInt(data, "experience"));

    if (DEBUG_SCENE == 0) {
        // Auto assign uuid4 token each time the application starts
        auto u4 = sole::uuid4();
        item->setToken(u4.str());
    }
}

