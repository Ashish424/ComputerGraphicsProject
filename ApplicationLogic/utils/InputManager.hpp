//
// Created by Priyanshu Singh on 30/11/15.
//

#ifndef CGPROJECT_INPUTMANAGER_HPP
#define CGPROJECT_INPUTMANAGER_HPP


class InputManager {

public:
    enum KEYS{
        W,
        S,
        D,
        A,
        COUNT
    };

    static bool getKey(KEYS k){
        return keys[k];
    }

    static void setKey(KEYS k, bool val){
        keys[k] = val;
    }

private:
    static bool keys[KEYS::COUNT];


};


#endif //CGPROJECT_INPUTMANAGER_HPP
