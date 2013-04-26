#include "Vector\Vector.hpp"
#include "camera.h"
#include <iostream>
#include <SDL\SDL.h>
#include <gl\glut.h>

void init(void);
void display(void);
void reshape (int w, int h);
void MouseFunc(int button, int state, int x, int y);
void MouseMotion(int x, int y);
void keyboard (unsigned char key, int x, int y);
void release();
void draw();