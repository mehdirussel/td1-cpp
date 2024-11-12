//
// Created by MEHDI on 04/11/2024.
//

#include "Card.h"
#include<iostream>
#include<vector>
#include<tuple>
#include<cstring>
#include<string>

using namespace std;


#include "Card.h"

string Card::getCardName() const {
    return cardName;
}

void Card::setCardName(const string& name) {
    cardName = name;
}
