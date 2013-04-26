#include <SDL\SDL.h>
#include "Vector\Vector.hpp"

class Camera {
private:
	Vector3f loc;
	Vector3f target;
	Vector3f up;
	Vector3f line;
	float theta_x;
	float theta_y;
	float len;
public:
	Camera(Vector3f loc, Vector3f target, Vector3f up);
	~Camera();
	void RotateCamera(float rotatex, float rotatey);
	void LenCamera(float distant);
	Vector3f GetLoc();
	Vector3f GetTarget();
	Vector3f GetUp();
};