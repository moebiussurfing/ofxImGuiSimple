//
//  phasorClass.h
//  DGTL_Generator
//
//  Created by Eduard Frigola on 28/07/16.
//
//

#ifndef ranger_h
#define ranger_h

#pragma once

#include "ofMain.h"


class ranger{
public:
    ranger(){};
    ~ranger(){};
    void setup();

//    float getRange();    
//    void resetRange();
    
    void recalculate();

private:
    
    ofEventListeners listeners;
    
    ofParameter<float>  input;
    ofParameter<float>  minInput;
    ofParameter<float>  maxInput;
    ofParameter<float>  minOutput;
    ofParameter<float>  maxOutput;
    ofParameter<float>  output;

public:
    ofParameterGroup params{"params"};
    void addParameter(ofParameter<float> p)
    {
        params.add(p);
    }

};


#endif /* ranger_h */
