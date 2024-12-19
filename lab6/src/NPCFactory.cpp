#include "NPCFactory.h"

std::unique_ptr<NPC> NPCFactory::createNPC(const std::string& type, int x, int y, const std::string& name) {
    if (type == "Bear") {
        return std::make_unique<Bear>(x, y, name);
    } else if (type == "Bittern") {
        return std::make_unique<Bittern>(x, y, name);
    } else if (type == "Desman") {
        return std::make_unique<Desman>(x, y, name);
    } else {
        throw std::invalid_argument("Unknown NPC type");
    }
}

std::unique_ptr<NPC> NPCFactory::loadNPC(std::istream& is) {
    std::string type;
    is >> type;
    int x, y;
    std::string name;
    is >> x >> y >> name;
    return createNPC(type, x, y, name);
}
