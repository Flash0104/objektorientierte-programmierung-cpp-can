//
// Created by Thies Josten on 31.10.24.
//

#ifndef INC_04_EXERCISE_STRUCTS_H
#define INC_04_EXERCISE_STRUCTS_H

struct Pizza{
    float diameter;
    float price;

    float price_per_cm2(){
        float radius = diameter/2;
        return price/(radius*radius*3.14159);
    }

    float five_euro_get_you_x_cm2(){
        return 5/price_per_cm2();
    }
};


#endif //INC_04_EXERCISE_STRUCTS_H
