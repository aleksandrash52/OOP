#ifndef NPC_H
#define NPC_H

#include <string>
#include <iostream>
#include <memory>
#include <shared_mutex>

class NPC {
public:
    virtual ~NPC() = default;

    virtual std::string getType() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual bool canAttack(const NPC& other) const = 0;

    int getX() const { return x; }
    int getY() const { return y; }
    const std::string& getName() const { return name; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setName(const std::string& name) { this->name = name; }

protected:
    int x, y;
    std::string name;
    std::shared_mutex mutex;
};

std::ostream& operator<<(std::ostream& os, const NPC& npc);
std::istream& operator>>(std::istream& is, NPC& npc);

#endif 
