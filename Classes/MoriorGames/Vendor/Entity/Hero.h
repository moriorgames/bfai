#ifndef MORIOR_GAMES_VENDOR_ENTITY_HERO_H
#define MORIOR_GAMES_VENDOR_ENTITY_HERO_H

#include <string>

namespace MoriorGames {

class Hero
{
public:
    static const std::string SIDE_PLAYER;
    static const std::string SIDE_ENEMY;

private:
    int id;
    std::string name, slug, side = SIDE_PLAYER;
    int damage, ranged, health, injury = 0, movement, moveFrames, attackFrames;

public:
    int getId() const;
    void setId(int id);
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getSlug() const;
    void setSlug(const std::string &slug);
    const std::string &getSide() const;
    void setSide(const std::string &side);
    int getDamage() const;
    void setDamage(int damage);
    int getRanged() const;
    void setRanged(int ranged);
    int getHealth() const;
    void setHealth(int health);
    int getInjury() const;
    int getMovement() const;
    void setMovement(int movement);
    int getMoveFrames() const;
    void setMoveFrames(int moveFrames);
    int getAttackFrames() const;
    void setAttackFrames(int attackFrames);

    void addInjury();

    void print();
};

}

#endif
