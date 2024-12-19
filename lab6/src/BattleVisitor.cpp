#include "BattleVisitor.h"

BattleVisitor::BattleVisitor(int range) : range(range) {}

void BattleVisitor::visit(std::vector<std::unique_ptr<NPC>>& npcs) {
    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = i + 1; j < npcs.size(); ++j) {
            if (npcs[i]->canAttack(*npcs[j]) && npcs[j]->canAttack(*npcs[i])) {
                int dx = npcs[i]->getX() - npcs[j]->getX();
                int dy = npcs[i]->getY() - npcs[j]->getY();
                if (dx * dx + dy * dy <= range * range) {
                    npcs.erase(npcs.begin() + j);
                    npcs.erase(npcs.begin() + i);
                    --i;
                    --j;
                }
            }
        }
    }
}
