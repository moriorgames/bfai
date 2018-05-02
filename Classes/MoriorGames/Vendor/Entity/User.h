#ifndef MORIOR_GAMES_VENDOR_ENTITY_USER_H
#define MORIOR_GAMES_VENDOR_ENTITY_USER_H

#include <string>

class User
{
public:
    int getId() const;
    void setId(int id);
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getSlug() const;
    void setSlug(const std::string &slug);
    const std::string &getToken() const;
    void setToken(const std::string &token);
    int getExperience() const;
    void setExperience(int experience);

    void print();

protected:
    int id = 0;
    std::string name = "", slug = "", token = "";
    int level = 0, experience = 0;
};

#endif
