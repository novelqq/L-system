#include "lsystem.hpp"
#include <iostream>

Lsystem::Lsystem(std::string axiom, std::vector<Rule> ruleset): 
            current(axiom), ruleset(ruleset){};
       
void Lsystem::generate(){
    std::string next = "";
    std::cout << current[0] << " " << current.length() << std::endl;
    for(int i = 0; i < current.length(); i++){
        char c = current[i];
        //std::cout << "char c: " << c << std::endl;
        //std::cout << "ruleset[0]" << ruleset[0].predecessor << std::endl;
        std::string replace(1, c); 
        for(int k = 0; k < ruleset.size(); k++){
            //std::cout << "ruleset[" << k << "] pred: " <<ruleset[k].predecessor << std::endl;
            if(c == ruleset[k].predecessor){
                replace = ruleset[k].successor;
                break;
            }
        }
        next.append(replace);
    }
    current = next;
}

std::string Lsystem::getSentence(){
    return current;
}