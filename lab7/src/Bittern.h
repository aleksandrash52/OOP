#ifndef BITTERN_H
#define BITTERN_H

#include "NPC.h"

class Bittern : public NPC {
public:
    Bittern(int x, int y, const std::string& name);

    std::string getType() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    bool canAttack(const NPC& other) const override;
};

#endif 
