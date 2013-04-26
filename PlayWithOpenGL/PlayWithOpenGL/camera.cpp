#include "stdafx.h"

#include "camera.h"
#include <iostream>
using namespace std;

#define PI 3.1415926

Camera::Camera(Vector3f loc, Vector3f target, Vector3f up) {
	this->loc = loc;
	this->target = target;
	this->up = up;
	this->line = loc - target;
	this->theta_x = atan2(line.x, line.z);
	this->theta_y = atan2(line.y, sqrt(line.x * line.x + line.z * line.z));
	this->len = length(line);
}

Camera::~Camera() {

}

void Camera::LenCamera(float distant) {
	len += distant;
	loc.y = len * sin(theta_y);
	loc.x = len * cos(theta_y) * sin(theta_x);
	loc.z = len * cos(theta_y) * cos(theta_x);
}

void Camera::RotateCamera(float rotatex, float rotatey) {
	theta_x += rotatex;
	theta_y -= rotatey;

	while (theta_x < 0) {
		theta_x += 2 * PI;
	}
	while (theta_x > 2 * PI) {
		theta_x -= 2 * PI;
	}
	while (theta_y < 0) {
		theta_y += 2 * PI;
	}
	while (theta_y > 2 * PI) {
		theta_y -= 2 * PI;
	}

	loc.y = len * sin(theta_y);
	loc.x = len * cos(theta_y) * sin(theta_x);
	loc.z = len * cos(theta_y) * cos(theta_x);
}

Vector3f Camera::GetLoc() {
	return loc;
}

Vector3f Camera::GetTarget() {
	return target;
}

Vector3f Camera::GetUp() {
	return up;
}
