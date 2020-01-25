#include "turtle.hpp"
#include "lsystem.hpp"
#include <vector>
#include <iostream>
const int WIDTH = 600, HEIGHT = 600;

Lsystem *lsys;
Turtle *turtle;

void setup(){
    std::vector<Rule> ruleset;
    ruleset.push_back(Rule('F', "FF+[+F-F-F]-[-F+F+F]"));
    std::cout << "ruleset[0].pred: " << ruleset[0].predecessor << std::endl;
    lsys = new Lsystem("F", ruleset);
    turtle = new Turtle(WIDTH/4, 25);
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
}
void draw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glTranslatef(WIDTH/2, HEIGHT, 0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(WIDTH/2, HEIGHT/2);
    glVertex2f(WIDTH/2 + 5, HEIGHT/2 + 5);
    glEnd();
    turtle->render();
    glutSwapBuffers();

}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_UP){
            std::cout << "left mouse click pressed. " << std::endl;
            lsys->generate();
            std::cout << "generated" << std::endl;
            turtle->setSentence(lsys->getSentence());
            glutPostRedisplay();
        }
    }
}
int main(int argc, char** argv){
    setup();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowPosition(100, 500);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("program");
    glutDisplayFunc(draw);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}