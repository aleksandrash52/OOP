#ifndef BEAR_H
#define BEAR_H

#include "NPC.h"

class Bear : public NPC {
public:
    Bear(int x, int y, const std::string& name);

    std::string getType() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    bool canAttack(const NPC& other) const override;
};

#endif 
