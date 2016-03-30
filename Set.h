//
//  Set.h
//  Statistics & Probability
//
//  Created by Jose Bouza on 1/22/16.
//  Copyright (c) 2016 Jose Bouza. All rights reserved.
//

//Implements a "set" class as typically defined in mathematics:
//A finite unordered container of elements. Cound be continous or discrete.

#ifndef __Statistics___Probability__Set__
#define __Statistics___Probability__Set__

#include <vector>
#include <typeinfo>    // for 'typeid'


enum SetDataType {CONTINOUS, DISCRETE};

template <class Element>
class Set{
public:
    //Discrete data
    Set(std::vector<Element> input);
    //Continous range
    Set(double xi, double xf);
    
    //Sees if element input exists in set
    bool contains(Element input);
    //Sees if subset exists in set
    bool contains(Set<Element> subset);
    //Gets data type
    SetDataType getType();
    
    //Gets vector containing Set, useful for copying.
    std::vector<Element> getElemList();
    
private:
    SetDataType type;
    double xi;
    double xf;
    std::vector<Element> elements;
};


template <class Element>
Set<Element>::Set(std::vector<Element> input)
{
    Set::elements = input;
    Set::type = DISCRETE;
}

template <class Element>
Set<Element>::Set(double xi_i, double xf_i)
{
    Set::xi = xi_i;
    Set::xf = xf_i;
    Set::type = CONTINOUS;
}


template <class Element>
bool Set<Element>::contains(Element input)
{
    if(Set::type == DISCRETE)
    {
        if((std::find(Set::elements.begin(), Set::elements.end(), input) != Set::elements.end()))
            return true;
        
        else
            return false;
    }
    
    if(Set::type == CONTINOUS)
    {
        if(input > Set::xi && input < Set::xf)
            return true;
        else
            return false;
    }
    
}

template <class Element>
SetDataType Set<Element>::getType()
{
    return Set::type;
}

template <class Element>
std::vector<Element> Set<Element>::getElemList()
{
    return Set::elements;
}
#endif /* defined(__Statistics___Probability__Set__) */
