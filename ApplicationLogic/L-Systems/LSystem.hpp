//
// Created by Ashish Aapan on 08/11/15.
//

#ifndef CGPROJECT_LSYSTEM_HPP
#define CGPROJECT_LSYSTEM_HPP

#include <string>
#include <map>
#include <memory>
namespace TerrainDemo {





//TODO see these are just basic rules see for parametric
  typedef std::map<std::string,std::string> Rules;
//TODO use this with shared_ptr
//  typedef std::string LSysString;
//  //RAII wrapper for string
//  class LSysStringManager{
//
//   public:
//    //acquire resource
//    LSysStringManager(LSysString * ptr):ptr(ptr) { }
//    //delete resource
//    ~LSysStringManager() {delete ptr; }
//   private: LSysString *ptr;
//  };


  enum class PlantTypes {
    TESTPLANT_1,
    TESTPLANT_2,
    TESTPLANT_3,
    TESTPLANT_4,
    TESTPLANT_5,
    TESTPLANT_6

  };
  class LSystem {
   public:
    //remove last two paramters
    LSystem(const std::string &start, const Rules &productionRules, float amount, float angle, int level);
    //constructor for testing
    //TODO temp function
    static LSystem getLsystem(const PlantTypes & type);

    //specify the depth of the string to be generated
    std::shared_ptr<std::string> getLSysString(unsigned int level, bool saveIt);



    //TODO add virtual method parse for different plants
    //bracketed l-system
    std::string start;
    Rules productionRules;
    //TODO removw this temp
    float amount;
    float angle;
    int level;
  };




}
#endif //CGPROJECT_LSYSTEM_HPP
