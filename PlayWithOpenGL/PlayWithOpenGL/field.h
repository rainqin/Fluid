#include "Particle.h"

class Field {
private:
	Particle* p;
	float fieldScope;
	int particleNum;

public:
	Field(Particle* particle, float scope, int num);
	~Field();
	
	void CalculateField();

	Vector3f CalculateWgradient(Vector3f r, float h);
	double CalculateWlaplaceian(Vector3f r, float h);
	double CalculateW(Vector3f r, float h);

	Vector3f PressureForce();
	Vector3f ViscosityForce();
	Vector3f SurfaceTension();
};