#ifndef NPCFACTORY_H
#define NPCFACTORY_H

#include "NPC.h"
#include "Bear.h"
#include "Bittern.h"
#include "Desman.h"
#include <memory>
#include <fstream>

class NPCFactory {
public:
    static std::unique_ptr<NPC> createNPC(const std::string& type, int x, int y, const std::string& name);
    static std::unique_ptr<NPC> loadNPC(std::istream& is);
};

#endif 
