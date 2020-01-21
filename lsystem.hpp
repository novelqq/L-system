#include <string>
#include <vector>

class Rule{
    public:
        Rule();
        Rule(char predecessor, std::string successor):
            predecessor(predecessor), successor(successor){}
        
        char predecessor;
        std::string successor;
};

class Lsystem{
    public:
        Lsystem(std::string axiom, std::vector<Rule>& ruleset);
        void generate();
        std::string getSentence();

    private:
        std::vector<Rule>& ruleset;
        int rslength;
        std::string current;
        

};