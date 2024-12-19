#include "NPC.h"

std::ostream& operator<<(std::ostream& os, const NPC& npc) {
    npc.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, NPC& npc) {
    npc.read(is);
    return is;
}
