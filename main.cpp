//
//  main.cpp
//  Statistics & Probability
//
//  Created by Jose Bouza on 1/22/16.
//  Copyright (c) 2016 Jose Bouza. All rights reserved.
//

#include <iostream>
#include "DiscreteUniformDistribution.h"

int main(int argc, const char * argv[]) {
    
    std::vector<double> dice_rolls = {1,2,3,4,5,6,};
    Set<double> sample_space1(dice_rolls);
    
    DiscreteUniformDistribution<double> dist(sample_space1);
    return 0;
}
