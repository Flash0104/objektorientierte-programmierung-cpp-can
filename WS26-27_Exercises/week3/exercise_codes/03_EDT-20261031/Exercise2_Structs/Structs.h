//
// Created by Thies Josten on 31.10.24.
//

#ifndef INC_04_EXERCISE_STRUCTS_H
#define INC_04_EXERCISE_STRUCTS_H

struct Pizza {
    // Problem 3.2 a) Member variables
    float diameter; // Diameter of the pizza in cm
    float price;    // Price of the pizza in Euros

    // Problem 3.2 b) & c) Member function declarations
    float price_per_cm2();
    float five_euro_get_you_x_cm2();
};

#endif // INC_04_EXERCISE_STRUCTS_H
