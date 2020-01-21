#include "turtle.hpp"

Turtle Turtle::Turtle(){
    x = WIDTH/2;
    y = HEIGHT/2;
    mx = 1;
    my = 0;
}

// void Turtle::move(GLfloat ds){
//         x += mx * ds;
//         y += my * ds;

// }

// void Turtle::turn(GLfloat theta){
//     GLfloat ux = mx;
//     GLfloat uy = my;
//     mx = ux * std::cos(theta) - uy * std::sin(theta);
//     my = uy * std::cos(theta) + ux * std::sin(theta);
// }

void Turtle::render(){
    glColor3f(1.0, 1.0, 1.0);
    for(int i = 0; i < sentence.length(); i++){
        char c = sentence[i];
        switch(c){
            case 'F':
                glBegin(GL_LINES);
                    
                break;
            case '+':
                rotate(theta);
                break;
            case '-':
                rotate(-theta);
                glrotat
                break;
            case '[':
                glPushMatrix();
                break;
            case ']':
                glPopMatrix();
                break;
        }
    }
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
