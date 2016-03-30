//
//  DiscreteUniformDistribution.h
//  
//
//  Created by Jose Bouza on 1/22/16.
//
//

#ifndef ____DiscreteUniformDistribution__
#define ____DiscreteUniformDistribution__

#include <map>

#include "Distribution.h"

template <class Element>
class DiscreteUniformDistribution : private Distribution<Element>
{
public:
    //Checks that sample space is discrete, constructs
    //distribution function. 
    DiscreteUniformDistribution(Set<Element> sample_space_in1) : Distribution<Element>(sample_space_in1)
    {
        if(DiscreteUniformDistribution::sample_space.getType() == DISCRETE)
        {
            std::vector<Element> sample_space_elems = DiscreteUniformDistribution::sample_space.getElemList();
            unsigned int element_count = sample_space_elems.size();
            
            for(int i = 0; i < element_count; i++)
            {
                DiscreteUniformDistribution::prob_map[sample_space_elems[i]] = 1.0/element_count;
            }
        }
        
        else
        {
            //THROW EXCPETION
        }
    };
    
private:
    std::map<Element, double> prob_map;
    
    virtual double distribution_function(Element x)
    {
        return prob_map[x];
    }

};


#endif /* defined(____DiscreteUniformDistribution__) */
