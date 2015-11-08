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
    TESTPLANT
  };
  class LSystem {
   public:
    //TODO define L-system language
    LSystem(const std::string & start,const Rules & productionRules);
    //constructor for testing
    LSystem(const PlantTypes & type );
    //specify the depth of the string to be generated
    //TODO make it virtual for this base class of L-system
    std::shared_ptr<std::string> getLSysString(unsigned int level, bool saveIt);
    //TODO add virtual method parse for different plants
    //bracketed l-system
//    void parse(sh);
//    std::shared_ptr<std::string> currentString;
    std::string start;
    Rules productionRules;
  };




}
#endif //CGPROJECT_LSYSTEM_HPP
