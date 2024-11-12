#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include "EnergyCard.h"
#include <vector>
#include <tuple>
#include <string>

class PokemonCard : public Card {
private:
    std::string pokemonType;
    std::string FamilyName;
    int HP;
    int evolutionLevel;
    int maxHP;
    std::vector<std::tuple<int, int, std::string, int>> attacks;

public:
    PokemonCard(const std::string& pokemonName, const std::string& pokemonType, const std::string& FamilyName, int evolutionLevel, int maxHP, int attackCost1, const std::string& attackDesc1, int attackDamage1, int attackCost2, const std::string& attackDesc2, int attackDamage2);
    void displayInfo() const override;
    void attachEnergy(EnergyCard* energyCard);
    int attack(int index);
    void reduceHP(int damage);
    void heal();
    std::string getAttackDescription(int index) const;
};

#endif //POKEMONCARD_H