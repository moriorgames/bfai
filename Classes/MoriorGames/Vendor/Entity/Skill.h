#ifndef MORIOR_GAMES_VENDOR_ENTITY_SKILL_H
#define MORIOR_GAMES_VENDOR_ENTITY_SKILL_H

#include <string>

class Skill
{
public:
    static short TYPE_NEXT_TURN;
    static short TYPE_MOVE;
    static short TYPE_SHOT;

public:
    int getId() const;
    void setId(int id);
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getSlug() const;
    void setSlug(const std::string &slug);
    short getType() const;
    void setType(short type);

    void print();

protected:
    int id = 0;
    std::string name = "", slug = "";
    short type = 0;
};

#endif
