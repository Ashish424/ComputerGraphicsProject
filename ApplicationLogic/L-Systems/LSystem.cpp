//
// Created by Ashish Aapan on 08/11/15.
//

#include "LSystem.hpp"

namespace TerrainDemo {

  LSystem::LSystem(const std::string &start, const Rules &productionRules, float amount, float angle, int level) :
      productionRules(productionRules),start(start),amount(amount),angle(angle),level(level) {




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
  LSystem LSystem::getLsystem(const PlantTypes &type) {
    if(type == PlantTypes::TESTPLANT_1){

      float angle,amount;
      TerrainDemo::Rules r1;
      r1["F"] = "F[+F]F[-F][F]";
      angle = 20;
      amount = 0.025;
      int level = 5;
      return LSystem("F", r1, amount, angle, level);



    }
    else if(type == PlantTypes::TESTPLANT_2){
      float angle,amount;
      TerrainDemo::Rules r1;
      r1["F"] = "F[+F]F[-F]F";
      angle = 25.7;
      amount = 0.006;
      int level = 5;
      return LSystem("F", r1, amount, angle, level);

    }
    else if(type == PlantTypes::TESTPLANT_3){
      float angle,amount;
      TerrainDemo::Rules r1;
      r1["F"] = "FF-[-F+F+F]+[+F-F-F]";
      angle = 22.5;
      amount = 0.03;
      int level = 4;
      return LSystem("F", r1, amount, angle, level);

    }
    else if(type == PlantTypes::TESTPLANT_4){
      float angle,amount;
      TerrainDemo::Rules r1;
      r1["F"] = "FF";
      r1["X"] = "F[+X]F[-X]+X";
      angle = 20.0;
      amount = 0.006;
      int level = 7;
      return LSystem("X", r1, amount, angle, 7);




    }
    else if(type == PlantTypes::TESTPLANT_5){
      float angle,amount;
      TerrainDemo::Rules r1;
      r1["F"] = "FF";
      r1["X"] = "F[+X][-X]FX";
      angle = 25.7;
      amount = 0.006;
      int level = 7;
      return LSystem("X", r1, amount, angle, 7);

    }
    else if(type == PlantTypes::TESTPLANT_6){
      float angle,amount;
      TerrainDemo::Rules r1;
      r1["F"] = "FF";
      r1["X"] = "F-[[X]+X]+F[+FX]-X";
      angle = 22.5;
      amount = 0.013;
      int level = 5;
      return LSystem("X", r1, amount, angle, 5);
    }

  }
}