//
// Created by MEHDI on 12/11/2024.
//

#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Player player1("Hadi");
    player1.addCardToBench(new EnergyCard("Electric", 0));
    player1.addCardToBench(new EnergyCard("Electric", 0));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 2, "thunder bolt", 20, 3, "thunder storm", 30));
    player1.activatePokemonCard(3);
    player1.attachEnergyCard(0, 0);
    player1.attachEnergyCard(0, 0);
    cout << endl;
    player1.displayBench();
    cout << endl;
    player1.displayAction();



    Player player2("Germain");
    player2.addCardToBench(new EnergyCard("Grass", 0));
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 2, "Leech Seed", 15, 3, "Vine Whip", 25));
    player2.activatePokemonCard(2);
    player2.attachEnergyCard(0, 0);
    cout << endl;
    player2.displayBench();
    cout << endl;
    player2.displayAction();

    player1.attack(0, 0, player2, 0);
    cout << endl;
    player2.displayAction();
    player2.useTrainer(0);
    cout << endl;
    player2.displayAction();

    return 0;
}