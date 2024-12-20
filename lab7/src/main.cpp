#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <thread>
#include <coroutine>
#include "NPCFactory.h"
#include "BattleVisitor.h"
#include "ScreenLogger.h"
#include "FileLogger.h"

std::vector<std::unique_ptr<NPC>> npcs;
ScreenLogger screenLogger;
FileLogger fileLogger("log.txt");

// Пример добавления NPC
void addNPC(const std::string& type, int x, int y, const std::string& name) {
    npcs.push_back(NPCFactory::createNPC(type, x, y, name));
}

// Пример сохранения и загрузки NPC
void saveNPCs(const std::string& filename) {
    std::ofstream outFile(filename);
    for (const auto& npc : npcs) {
        outFile << *npc << std::endl;
    }
    outFile.close();
}

void loadNPCs(const std::string& filename) {
    std::ifstream inFile(filename);
    npcs.clear();
    while (inFile) {
        npcs.push_back(NPCFactory::loadNPC(inFile));
    }
    inFile.close();
}

// Пример печати NPC
void printNPCs() {
    for (const auto& npc : npcs) {
        std::cout << *npc << std::endl;
    }
}

// Пример боевого режима
void battleMode(int range) {
    BattleVisitor battleVisitor(range);
    battleVisitor.visit(npcs);
}

// Пример логирования
void logMessage(const std::string& message) {
    screenLogger.log(message);
    fileLogger.log(message);
}

// Пример использования coroutine
std::coroutine::coroutine_handle<void> startBattle(int range) {
    co_await std::async(std::launch::async, [range]() {
        battleMode(range);
    });
}

int main() {
    // Пример добавления NPC
    addNPC("Bear", 100, 200, "Bear1");
    addNPC("Bittern", 300, 400, "Bittern1");
    addNPC("Desman", 50, 60, "Desman1");

    // Пример сохранения и загрузки NPC
    saveNPCs("npcs.txt");
    loadNPCs("npcs.txt");

    // Пример печати NPC
    printNPCs();

    // Пример боевого режима
    battleMode(100);

    // Пример логирования
    logMessage("Battle started");

    // Пример использования coroutine
    startBattle(100);

    return 0;
}
