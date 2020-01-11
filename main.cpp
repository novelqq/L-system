#include "GL/glut.h"
#include <fstream>
#include <iostream>
#include <cmath>

const int WIDTH = 400, HEIGHT = 400;


class Rule{
    public:
        Rule(std::string predecessor, std::string successor):
            predecessor(predecessor), successor(successor){}
        
        std::string predecessor;
        std::string successor;
};
class Turtle{
    public:
        Turtle(){
            x = WIDTH/2;
            y = HEIGHT/2;
            mx = 1;
            my = 0;
        }
        void move(GLfloat ds){
            x += mx * ds;
            y += my * ds;
        }
        void turn(GLfloat theta){
            GLfloat ux = mx;
            GLfloat uy = my;
            mx = ux * std::cos(theta) - uy * std::sin(theta);
            my = uy * std::cos(theta) + ux * std::sin(theta);
        }
        void render(){
            
        }
        GLfloat getx(){
            return x;
        }
        GLfloat gety(){
            return y;
        }
    private:
        GLfloat x, y, mx, my;
};

std::string generate(std::string current, int iterations){
    for(int k = 0; k < iterations; k ++){
        std::string next = "";
        for(int i = 0; i < current.length(); i++){
            char c = current[i];
            if(c == 'F'){
                next += "FF+[+F-F-F]-[-F+F+F]";
            }
        }
        current = next;
    }
    return current;
}


void display(void){
    std::string axiom;
    axiom = 'F';
    std::string lsystem = generate(axiom, 5);

}


void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 500);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("program");
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}