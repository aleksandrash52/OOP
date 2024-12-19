#ifndef BATTLEVISITOR_H
#define BATTLEVISITOR_H

#include "NPC.h"
#include <vector>
#include <memory>

class BattleVisitor {
public:
    BattleVisitor(int range);
    void visit(std::vector<std::unique_ptr<NPC>>& npcs);

private:
    int range;
};

#endif 
