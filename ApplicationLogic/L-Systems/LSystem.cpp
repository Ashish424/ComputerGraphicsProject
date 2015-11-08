//
// Created by Ashish Aapan on 08/11/15.
//

#include "LSystem.hpp"

namespace TerrainDemo {

  LSystem::LSystem(const std::string &start, const Rules & productionRules):
      productionRules(productionRules),start(start) {




  }
  LSystem::LSystem(const PlantTypes &type) {
    if(type == PlantTypes::TESTPLANT){
      //pass the predefined rules here
    }

  }


  std::shared_ptr<std::string> LSystem::getLSysString(unsigned int level, bool saveIt) {
    if(level == 0 ){
      std::shared_ptr<std::string> p(new std::string(start));
      return p;
    }
    //TODO see if this can be optimized
    std::shared_ptr<std::string> nextString(new std::string);
    std::shared_ptr<std::string> currentString(new std::string(start));
    for(int i = 0;i<level;i++){
      unsigned int len = currentString->length();


      //TODO replace with unique ptr for nextstring
      std::string & currentRef =  *currentString;
      std::string & nextRef = *nextString;
      for(int j = 0;j< len;j++){
        //does not exist,treat as constant
        std::string  current = currentRef.substr(j, 1);

        if(productionRules.count(current) == 0 ){
          nextRef+= current;
        }
          //parse the string character using the map
        else{
          nextRef+=productionRules[current];
        }
      }
      //transfer the pointer from next string to current string
      currentString = std::move(nextString);
      //reset the nextString
      nextString.reset(new std::string);
    }
    //TODO add save it code here
    return currentString;

  }
}