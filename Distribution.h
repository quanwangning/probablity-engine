//
//  Distribution.h
//  Statistics & Probability
//
//  Created by Jose Bouza on 1/22/16.
//  Copyright (c) 2016 Jose Bouza. All rights reserved.
//

//Base class for distributions, a child class must overload distribution_function.

#ifndef __Statistics___Probability__Distribution__
#define __Statistics___Probability__Distribution__

#include "Set.h"

template <class Element>
class Distribution
{
public:
    Distribution(Set<Element> sample_spacein) : sample_space(sample_spacein)
    {
        
    }
    
    double probability(Element x);
    
protected:
    Set<Element> sample_space;
    virtual double distribution_function(Element x) = 0;
};


template <class Element>
double Distribution<Element>::probability(Element x)
{
    if(sample_space.contains(x))
    {
        Distribution::distribution_function(x);
    }
    
    else
    {
        //Throw exception
        return 0;
    }
}
#endif /* defined(__Statistics___Probability__Distribution__) */
