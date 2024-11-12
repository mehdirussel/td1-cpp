//
// Created by MEHDI on 04/11/2024.
//

#include "EnergyCard.h"

#include <iostream>

EnergyCard::EnergyCard(const string& energyType, int energyAmount)
    : energyType(energyType) {
    setCardName("Energy");
    this->energyAmount = energyAmount;
}

void EnergyCard::displayInfo() const {
    cout << "Card Name: " << getCardName() << endl;
    cout << "Energy Type: " << energyType << endl;
}

void EnergyCard::getEnergyType() const {
    cout << "Energy Type: " << energyType << endl;
}