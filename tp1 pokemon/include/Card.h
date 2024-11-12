//
// Created by MEHDI on 04/11/2024.
//

#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;

class Card {
private:
    string cardName;

public:
    virtual ~Card() = default;

    virtual void displayInfo() const = 0;
    string getCardName() const;
    void setCardName(const string& name);
};



#endif //CARD_H
