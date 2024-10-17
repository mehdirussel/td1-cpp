//
// Created by MEHDI on 18/10/2024.
//


#include <iostream>
#include "MatrixBase.h"
#include "MatrixNumerical.h"

int main() {

    MatrixNumerical<double> matrice(3, 3);


    matrice.addElement(1.0, 0, 0);
    matrice.addElement(2.0, 0, 1);
    matrice.addElement(3.0, 0, 2);
    matrice.addElement(4.0, 1, 0);
    matrice.addElement(5.0, 1, 1);
    matrice.addElement(6.0, 1, 2);
    matrice.addElement(7.0, 2, 0);
    matrice.addElement(8.0, 2, 1);
    matrice.addElement(9.0, 2, 2);


    std::cout << "Matrice:" << std::endl;
    matrice.Display();

    // Calcul et affichage du déterminant
    try {
        double determinant = matrice.getDeterminant();
        std::cout << "Le déterminant de la matrice est: " << determinant << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    // Création d'une autre matrice numérique de 3x3
    MatrixNumerical<double> autreMatrice(3, 3);
    autreMatrice.addElement(9.0, 0, 0);
    autreMatrice.addElement(8.0, 0, 1);
    autreMatrice.addElement(7.0, 0, 2);
    autreMatrice.addElement(6.0, 1, 0);
    autreMatrice.addElement(5.0, 1, 1);
    autreMatrice.addElement(4.0, 1, 2);
    autreMatrice.addElement(3.0, 2, 0);
    autreMatrice.addElement(2.0, 2, 1);
    autreMatrice.addElement(1.0, 2, 2);

    // Affichage de l'autre matrice
    std::cout << "Autre Matrice:" << std::endl;
    autreMatrice.Display();

    // Addition des deux matrices
    try {
        MatrixNumerical<double> somme = matrice + autreMatrice;
        std::cout << "Somme des matrices:" << std::endl;
        somme.Display();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}