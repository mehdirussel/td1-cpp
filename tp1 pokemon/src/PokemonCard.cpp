#include "PokemonCard.h"

#include <cstring>
#include <iostream>

PokemonCard::PokemonCard(const std::string& pokemonName, const std::string& pokemonType, const std::string& FamilyName, int evolutionLevel, int maxHP, int attackCost1, const std::string& attackDesc1, int attackDamage1, int attackCost2, const std::string& attackDesc2, int attackDamage2)
    : pokemonType(pokemonType), FamilyName(FamilyName), HP(maxHP), evolutionLevel(evolutionLevel), maxHP(maxHP) {
    setCardName(pokemonName);
    attacks.emplace_back(attackCost1, 0, attackDesc1, attackDamage1);
    attacks.emplace_back(attackCost2, 0, attackDesc2, attackDamage2);
}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name: " << getCardName() << ", Type: " << pokemonType << ", Evolution Level: " << evolutionLevel << " of the family \"" << FamilyName << "\", HP: " << HP << std::endl;
    std::cout << "Attacks:" << std::endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        std::cout << "Attack #" << i << ":" << std::endl;
        std::cout << "Attack cost: " << std::get<0>(attacks[i]) << std::endl;
        std::cout << "Attack current energy storage: " << std::get<1>(attacks[i]) << std::endl;
        std::cout << "Attack description: " << std::get<2>(attacks[i]) << std::endl;
        std::cout << "Attack damage: " << std::get<3>(attacks[i]) << std::endl;
    }
}

void PokemonCard::attachEnergy(EnergyCard* energyCard) {
    for (auto& attack : attacks) {
        if (std::get<1>(attack) < std::get<0>(attack)) {
            std::get<1>(attack)++;
            break;
        }
    }
}

int PokemonCard::attack(int index) {
    if (index < attacks.size() && std::get<1>(attacks[index]) >= std::get<0>(attacks[index])) {
        return std::get<3>(attacks[index]);
    }
    return 0;
}

void PokemonCard::reduceHP(int damage) {
    HP -= damage;
    std::cout << "Reducing " << damage << " from " << getCardName() << "'s HP" << std::endl;
    if (HP <= 0) {
        std::cout << "Pokemon " << getCardName() << " is knocked out" << std::endl;
    } else {
        std::cout << "Pokemon " << getCardName() << " is still alive" << std::endl;
    }
}

void PokemonCard::heal() {
    HP = maxHP;
}

std::string PokemonCard::getAttackDescription(int index) const {
    if (index < attacks.size()) {
        return std::get<2>(attacks[index]);
    }
    return "";
}