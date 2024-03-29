#include "stdafx.h"
#include "Particle.h"
#include <gl\glut.h>
#include <iostream>

#define delta_t 0.001
#define damping 0

Particle::Particle(){
	inFieldCount = 0;
	pNum = 8 * 8 * 8;
	mass = 5.0;
	force = make_vector(0.0, 0.0, 0.0);
	acc = make_vector(0.0, 0.0, 0.0);
	velocity = make_vector(0.0, 0.0, 0.0);
	density = 0;
	csGradient = make_vector(0.0, 0.0, 0.0);
	csLaplaceian = 0;
	inFieldCount = 0;

	inField = new myField[pNum];
	this->clearInField();
}

Particle::~Particle(){
	delete [] inField;
}

void Particle::draw() {
	GLfloat DiffuseMaterial[] = {0.0, 0.0, 1.0}; 
	GLfloat SpecularMaterial[] = {1.0, 1.0, 1.0}; 
	GLfloat EmissiveMaterial[] = {0.0, 0.0, 1.0};
	GLfloat mShininess[] = {128}; 

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularMaterial);
    glMaterialfv(GL_FRONT, GL_SHININESS, mShininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseMaterial);
	//glMaterialfv(GL_FRONT, GL_EMISSION, EmissiveMaterial);

	GLUquadricObj* quadratic;
	quadratic =gluNewQuadric();  
	glTranslatef(position.x, position.y, position.z); 	 
	gluSphere(quadratic, 0.25, 10, 10); 
	glPopMatrix();
}

void Particle::clearInField() {
	for (int i = 0; i < pNum; i++) {
		inField[i].index = 0;
	}
}

void Particle::applyForce() {
	float constraint = 2.5;

	acc = force / mass;

	velocity += acc * delta_t;

	int vConstraint = 150;
	if (velocity.x > vConstraint) {
		velocity.x  = vConstraint;
	}
	if (velocity.y > vConstraint) {
		velocity.y  = vConstraint;
	}
	if (velocity.z > vConstraint) {
		velocity.z  = vConstraint;
	}
	
	position += velocity * delta_t;

	if (position.y > constraint) {
		position.y = constraint;
		velocity.y = -damping * velocity.y;
		acc.y = 0;
	}

	if (position.y < -constraint) {
		position.y = -constraint;
		velocity.y = -damping * velocity.y;
		acc.y = 0;
	}

	if (position.x < -constraint) {
		position.x = -constraint;
		velocity.x = -damping * velocity.x;
		acc.x = 0;
	}

	if (position.x > constraint) {
		position.x = constraint;
		velocity.x = -damping * velocity.x;
		acc.x = 0;
	} 
	if (position.z < -constraint) {
		//std::cout<<"Prev: "<<position<<std::endl;
		position.z = -constraint;
		velocity.z = -damping * velocity.z;
		acc.z = 0;
		//std::cout<<"After: "<<position<<std::endl;
	} 
	if (position.z > constraint) {
		position.z = constraint;
		velocity.z = -damping * velocity.z;
		acc.z =0;
	}

}

/*void Particle::applyForce() {
	float constraint = 5;
	Vector3f zero = make_vector<float>(0.0, 0.0, 0.0);

	acc = force / mass;
	velocity += acc * delta_t;
	
	position += velocity * delta_t;

	if (position.y < 0) {
		position.y = 0;
		velocity.y = -damping * velocity.y;
		acc.y = -acc.y;
	}

	if (position.x < -1) {
		velocity = zero;
		acc.x = -damping * acc.x;
	}

	if (position.x > constraint) {
		velocity = zero;
		acc.x = -damping * acc.x;
	} 
	if (position.z < -1) {
		velocity = zero;
		acc.z = -damping * acc.z;
		//std::cout<<"After: "<<position<<std::endl;
	} 
	if (position.z > constraint) {
		velocity = zero;
		acc.z = -damping * acc.z;;
	}

}*/