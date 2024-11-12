#include "Player.h"
#include "TrainerCard.h"
#include <iostream>

Player::Player(std::string playerName)
    : playerName(playerName) {
}

void Player::addCardToBench(Card *card) {

    if (dynamic_cast<EnergyCard*>(card) || dynamic_cast<TrainerCard*>(card) || dynamic_cast<PokemonCard*>(card)) {
        benchCards.push_back(card);
    } else {
        std::cout << "Invalid card type" << std::endl;
    }
}

void Player::activatePokemonCard(int index) {
    if(dynamic_cast<PokemonCard*>(benchCards[index]) != nullptr){
        actionCards.push_back(dynamic_cast<PokemonCard*>(benchCards[index]));
        benchCards.erase(benchCards.begin() + index);
        std::cout << playerName << " is activating a Pokemon Card: " << actionCards.back()->getCardName() << std::endl;
    } else {
        std::cout << "Invalid card type!" << std::endl;
    }
}

void Player::attachEnergyCard(int benchIndex, int actionIndex) {
    if (benchCards[benchIndex]->getCardName() == "Energy" && actionIndex < actionCards.size()) {
        EnergyCard* energyCard = static_cast<EnergyCard*>(const_cast<Card*>(benchCards[benchIndex]));
        actionCards[actionIndex]->attachEnergy(energyCard);
        benchCards.erase(benchCards.begin() + benchIndex);
        //std::cout << playerName << " is attaching Energy Card of type " << energyCard->getEnergyType() << " to the Pokemon " << actionCards[actionIndex]->getCardName() << std::endl;
    } else {
        std::cout << "Invalid card type or index!" << std::endl;
    }
}

void Player::displayBench() const {
    std::cout << "Bench cards for Player " << playerName << ":" << std::endl;
    for (const auto& card : benchCards) {
        card->displayInfo();
    }
}

void Player::displayAction() const {
    std::cout << "Action cards for Player " << playerName << ":" << std::endl;
    for (const auto& card : actionCards) {
        card->displayInfo();
    }
}

void Player::attack(int attackerIndex, int attackIndex, Player& opponent, int defenderIndex) {
    if (attackerIndex < actionCards.size() && defenderIndex < opponent.actionCards.size()) {
        std::cout << playerName << " attacking " << opponent.playerName << "'s Pokemon " << opponent.actionCards[defenderIndex]->getCardName() << " with the Pokemon " << actionCards[attackerIndex]->getCardName() << " with its attack: " << actionCards[attackerIndex]->getAttackDescription(attackIndex) << std::endl;
        int damage = actionCards[attackerIndex]->attack(attackIndex);
        opponent.actionCards[defenderIndex]->reduceHP(damage);
    } else {
        std::cout << "Invalid card index" << std::endl;
    }
}

void Player::useTrainer(int index) {

    if (index < benchCards.size() && dynamic_cast<TrainerCard*>(benchCards[index])) {
        auto* trainerCard = dynamic_cast<TrainerCard*>(const_cast<Card*>(benchCards[index]));
        //std::cout << playerName << " is using the Trainer Card to \"" << trainerCard->getTrainerEffect() << "\"" << std::endl;
        trainerCard->applyCardEffect();
        for (auto& card : actionCards) {
            card->heal();
        }
        benchCards.erase(benchCards.begin() + index);
    } else {
        std::cout << "Invalid card type or index!!" << std::endl;
    }
}