//
// Created by MEHDI on 04/11/2024.
//

#ifndef ENERGYCARD_H
#define ENERGYCARD_H



#include "Card.h"
#include <string>

using namespace std;

class EnergyCard : public Card {
private:
    string energyType;
    int energyAmount;

public:
    EnergyCard(const string& energyType, int energyAmount);
    void displayInfo() const override;
    void getEnergyType() const;
};



#endif //ENERGYCARD_H
