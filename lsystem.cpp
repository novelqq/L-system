#include "lsystem.hpp"

Lsystem::Lsystem(std::string axiom, std::vector<Rule>& ruleset): 
            current(axiom), ruleset(ruleset){};
       
void Lsystem::generate(){
    std::string next = "";
    for(int i = 0; i < current.length(); i++){
        char c = current[i];
        for(int k = 0; k < ruleset.size(); k++){
            if(c == ruleset[k].predecessor){
                next.append(ruleset[k].successor);
                break;
            }
        }
    }
    current = next;
}

std::string Lsystem::getSentence(){
    return current;
}