#include "turtle.hpp"
#include "lsystem.hpp"

const int WIDTH = 600, HEIGHT = 600;

Lsystem lsys;
Turtle turtle;

void setup(){
    Rule ruleset[1];
    ruleset[0] = new Rule("F", "FF+[+F-F-F]-[-F+F+F]");
    lsys = new Lsystem("F", ruleset, 1);
}
void draw(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glTranslatef(WIDTH/2, HEIGHT, 0);
    turtle.render();

}

void glutMouseFunc(int button, int state, int x, int y){
    lsys.generate();
    turtle.setSentence(lsys.getSentence());
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 500);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("program");
    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}