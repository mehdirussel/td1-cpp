//
// Created by MEHDI on 04/11/2024.
//

#include "TrainerCard.h"

#include <iostream>
#include <cstring>

TrainerCard::TrainerCard(const string& trainerCardName,const string& trainerEffect)
    : trainerEffect(trainerEffect) {
    setCardName(trainerCardName);
}

void TrainerCard::applyCardEffect() {
    cout << "Applying card effect: " << trainerEffect << endl;
    if(strcmp(trainerEffect.c_str(), "heal all your action pokemon") == 0) {
        cout << "Healing all your action pokemon" << endl;
    }
}

void TrainerCard::displayInfo() const {
    cout << "Card Name: " << getCardName() << endl;
    cout << "Effect: " << trainerEffect << endl;
}

void TrainerCard::getTrainerEffect() const {
    cout << "Effect: " << trainerEffect << endl;
}
