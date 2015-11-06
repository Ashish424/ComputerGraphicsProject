//
// Created by Priyanshu Singh on 13/10/15.
//

#ifndef CGPROJECT_AGENT_H
#define CGPROJECT_AGENT_H


class Agent {
public:

    Agent(int tokens){this->tokens = (unsigned int) tokens;}
    //virtual destructor
    virtual ~Agent(){};
    unsigned int tokens; //deonte the life of a agent

};


#endif //CGPROJECT_AGENT_H