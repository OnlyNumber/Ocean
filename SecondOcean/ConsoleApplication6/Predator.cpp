#include"Predator.h"
#include<iostream>

bool Predator::IsHunger(void) {
    if (Moves == 0) {
        return 0;
    }
    if (--TimeToFeed <= 0) {
        return 1;
    }
    return 0;
}

bool Predator::IsReproducible(void) {
    if (--TimeToReproduce <= 0) {
        TimeToReproduce = TIME_TO_REPRODUCE;
        return 1;
    }
    return 0;
}



