//
// Created by MEHDI on 04/11/2024.
//

#ifndef TRAINERCARD_H
#define TRAINERCARD_H


#include "Card.h"
#include <string>

using namespace std;


class TrainerCard : public Card {
private:
    string trainerEffect;
public:
    TrainerCard(const string& trainerCardName, const string& trainerEffect);
    void applyCardEffect();
    void displayInfo() const override;
    void getTrainerEffect() const;
};



#endif //TRAINERCARD_H