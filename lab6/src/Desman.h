#ifndef DESMAN_H
#define DESMAN_H

#include "NPC.h"

class Desman : public NPC {
public:
    Desman(int x, int y, const std::string& name);

    std::string getType() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    bool canAttack(const NPC& other) const override;
};

#endif 
