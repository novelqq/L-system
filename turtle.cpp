#include "turtle.hpp"
#include <iostream>
Turtle::Turtle(GLfloat len, GLfloat theta): len(len), theta(theta){
    // x = WIDTH/2;
    // y = HEIGHT/2;
    // mx = 1;
    // my = 0;
}

void Turtle::move(GLfloat ds){
        // x += mx * ds;
        // y += my * ds;
        glColor3f(1.0, 1.0, 1.0);
        glutSolidCube(1.0);

}

// void Turtle::turn(GLfloat theta){
//     GLfloat ux = mx;
//     GLfloat uy = my;
//     mx = ux * std::cos(theta) - uy * std::sin(theta);
//     my = uy * std::cos(theta) + ux * std::sin(theta);
// }

void Turtle::render(){
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    for(int i = 0; i < sentence.length(); i++){
        char c = sentence[i];
        switch(c){
            case 'F':
                //std::cout << "Drawing" << std::endl;
                glColor3f(1.0, 1.0, 1.0);
                glBegin(GL_LINES);
                glVertex2f(0, 0);
                glVertex2f(0, len);
                glEnd();
                glTranslatef(0, len, 0);
                break;
            case '+':
                glRotated(theta, 0, 0, 1);
                break;
            case '-':
                glRotated(theta, 0, 0, 1);
                break;
            case '[':
                glPushMatrix();
                break;
            case ']':
                glPopMatrix();
                break;
        }
    }
    glPopMatrix();
}

void Turtle::changeLen(GLfloat diff){
    len /= diff;
}

GLfloat Turtle::getx(){
    return x;
}

GLfloat Turtle::gety(){
    return y;
}

void Turtle::setSentence(std::string s){
    sentence = s;
}
