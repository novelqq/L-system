#include <GL/freeglut.h>
#include <string>
#include <vector>

class Turtle{
    public:
        Turtle(int width, int height, GLfloat len, GLfloat theta);
        ~Turtle();
        void render();
        GLfloat getx();
        GLfloat gety();
        void setSentence(std::string s);
        void changeLen(GLfloat diff);
        void move(GLfloat ds);
    private:
        void turn(GLfloat theta);
    private:  
        std::vector<GLfloat> x, y, mx, my;
        std::string sentence;
        GLfloat len, theta;
};
