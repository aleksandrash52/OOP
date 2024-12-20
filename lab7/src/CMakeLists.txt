add_library(BalagurFate3
    NPC.cpp
    Bear.cpp
    Bittern.cpp
    Desman.cpp
    NPCFactory.cpp
    BattleVisitor.cpp
    Logger.cpp
    ScreenLogger.cpp
    FileLogger.cpp
)

target_include_directories(BalagurFate3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
