#ifndef BFAI_MG_VENDOR_HERO_H
#define BFAI_MG_VENDOR_HERO_H

#include <string>

namespace MoriorGames {

class Hero
{
private:
    int id;
    std::string name, slug;

public:
    int getId() const;
    void setId(int id);
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getSlug() const;
    void setSlug(const std::string &slug);
};

}

#endif
