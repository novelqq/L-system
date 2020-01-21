#include <GL/freeglut.h>
#include <string>

class Turtle{
    public:
        Turtle();
        ~Turtle();
        void render();
        int getx();
        int gety();
        void setSentence(std::string s);
    private:
        void move(GLfloat ds);
        void turn(GLfloat theta);
    private:  
        GLfloat x, y, mx, my;
        std::string sentence;
};
