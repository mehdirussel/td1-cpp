#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "PokemonCard.h"
#include <vector>
#include <string>

class Player {
private:
    std::string playerName;
    std::vector<Card*> benchCards;
    std::vector<PokemonCard*> actionCards;

public:
    Player(std::string playerName);
    void addCardToBench(Card *card);
    void activatePokemonCard(int index);
    void attachEnergyCard(int benchIndex, int actionIndex);
    void displayBench() const;
    void displayAction() const;
    void attack(int attackerIndex, int attackIndex, Player& opponent, int defenderIndex);
    void useTrainer(int index);
};

#endif //PLAYER_H