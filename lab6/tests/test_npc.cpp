#include <gtest/gtest.h>
#include "NPCFactory.h"
#include "BattleVisitor.h"

TEST(NPCFactoryTest, CreateNPC) {
    auto bear = NPCFactory::createNPC("Bear", 100, 200, "Bear1");
    EXPECT_EQ(bear->getType(), "Bear");
    EXPECT_EQ(bear->getX(), 100);
    EXPECT_EQ(bear->getY(), 200);
    EXPECT_EQ(bear->getName(), "Bear1");

    auto bittern = NPCFactory::createNPC("Bittern", 300, 400, "Bittern1");
    EXPECT_EQ(bittern->getType(), "Bittern");
    EXPECT_EQ(bittern->getX(), 300);
    EXPECT_EQ(bittern->getY(), 400);
    EXPECT_EQ(bittern->getName(), "Bittern1");

    auto desman = NPCFactory::createNPC("Desman", 50, 60, "Desman1");
    EXPECT_EQ(desman->getType(), "Desman");
    EXPECT_EQ(desman->getX(), 50);
    EXPECT_EQ(desman->getY(), 60);
    EXPECT_EQ(desman->getName(), "Desman1");
}

TEST(BattleVisitorTest, Battle) {
    std::vector<std::unique_ptr<NPC>> npcs;
    npcs.push_back(NPCFactory::createNPC("Bear", 100, 200, "Bear1"));
    npcs.push_back(NPCFactory::createNPC("Bittern", 300, 400, "Bittern1"));
    npcs.push_back(NPCFactory::createNPC("Desman", 50, 60, "Desman1"));

    BattleVisitor battleVisitor(100);
    battleVisitor.visit(npcs);

    EXPECT_EQ(npcs.size(), 1);
    EXPECT_EQ(npcs[0]->getType(), "Bittern");
}
