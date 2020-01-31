#include "turtle.hpp"
#include <iostream>
#include <math.h>

Turtle::Turtle(int width, int height, GLfloat len, GLfloat theta): len(len), theta(theta){
    x.push_back(width/2);
    y.push_back(height/2);
    mx.push_back(0);
    my.push_back(-1);
}

void Turtle::move(GLfloat ds){
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        glVertex2f(x.back(), y.back());
        x.back() += mx.back() * ds;
        y.back() += my.back() * ds;
        glVertex2f(x.back(), y.back());
        glEnd();
}

void Turtle::turn(GLfloat theta){
    GLfloat ux = mx.back();
    GLfloat uy = my.back();
    mx.back() = ux * std::cos(theta) - uy * std::sin(theta);
    my.back() = uy * std::cos(theta) + ux * std::sin(theta);
}

void Turtle::render(){
    glColor3f(1.0, 1.0, 1.0);
    for(int i = 0; i < sentence.length(); i++){
        char c = sentence[i];
        switch(c){
            case 'F':
                move(len);
                break;
            case '+':
                turn(theta);
                break;
            case '-':
                turn(-theta);
                break;
            case '[':
                x.push_back(x.back());
                y.push_back(y.back());
                mx.push_back(mx.back());
                my.push_back(my.back());
                break;
            case ']':
                x.pop_back();
                y.pop_back();
                mx.pop_back();
                my.pop_back();
                break;
            case 'X':
                move(len/2);
                break;
        }
    }
}

void Turtle::changeLen(GLfloat diff){
    len /= diff;
}

GLfloat Turtle::getx(){
    return x.back();
}

GLfloat Turtle::gety(){
    return y.back();
}

void Turtle::setSentence(std::string s){
    sentence = s;
}
