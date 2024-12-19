#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include "NPCFactory.h"
#include "BattleVisitor.h"
#include "ScreenLogger.h"
#include "FileLogger.h"

int main() {
    std::vector<std::unique_ptr<NPC>> npcs;
    ScreenLogger screenLogger;
    FileLogger fileLogger("log.txt");

    // Пример добавления NPC
    npcs.push_back(NPCFactory::createNPC("Bear", 100, 200, "Bear1"));
    npcs.push_back(NPCFactory::createNPC("Bittern", 300, 400, "Bittern1"));
    npcs.push_back(NPCFactory::createNPC("Desman", 50, 60, "Desman1"));

    // Пример сохранения и загрузки NPC
    std::ofstream outFile("npcs.txt");
    for (const auto& npc : npcs) {
        outFile << *npc << std::endl;
    }
    outFile.close();

    std::ifstream inFile("npcs.txt");
    npcs.clear();
    while (inFile) {
        npcs.push_back(NPCFactory::loadNPC(inFile));
    }
    inFile.close();

    // Пример печати NPC
    for (const auto& npc : npcs) {
        std::cout << *npc << std::endl;
    }

    // Пример боевого режима
    BattleVisitor battleVisitor(100);
    battleVisitor.visit(npcs);

    // Пример логирования
    screenLogger.log("Battle started");
    fileLogger.log("Battle started");

    return 0;
}
