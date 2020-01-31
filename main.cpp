#include "turtle.hpp"
#include "lsystem.hpp"
#include <vector>
#include <iostream>
const int WIDTH = 1920, HEIGHT = 1080;

Lsystem *lsys;
Turtle *turtle;

void setup(){
    std::vector<Rule> ruleset;
    ruleset.push_back(Rule('F', "FF"));
    ruleset.push_back(Rule('X', "F-[[X]+X]+F[+FX]-X"));
    std::cout << "ruleset[0].pred: " << ruleset[0].predecessor << std::endl;
    lsys = new Lsystem("X", ruleset);
    turtle = new Turtle(WIDTH+500, HEIGHT*2, 30, 0.26);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
}
void draw(){
    glColor3f(1.0, 1.0, 1.0);
    //glMatrixMode(GL_PROJECTION);
    //glTranslatef(WIDTH/2, HEIGHT, 0);
    //glMatrixMode(GL_MODELVIEW);
    //glRectd(0, 0, WIDTH/2, HEIGHT/2);
    turtle->render();
    //turtle->changeLen(2);
    glutSwapBuffers();

}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_UP){
            std::cout << "left mouse click pressed. " << std::endl;
            lsys->generate();
            std::cout << "generated " << lsys->getSentence() << std::endl;
            turtle->setSentence(lsys->getSentence());
            glutPostRedisplay();
        }
    }
}
int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowPosition(100, 500);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("program");

    setup();
    glutDisplayFunc(draw);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}