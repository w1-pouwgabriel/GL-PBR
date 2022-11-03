#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera();
	~Camera();

	//Methods
	void Update(float deltaTime);

	void MoveForward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();

	//Getters and setters
	glm::vec3 getPos();
	void setYaw(float newYaw);
	void setPitch(float newPitch);
	void setFov(float newFov);
	float getYaw() const;
	float getPitch() const;
	float getFov() const;
	void setCameraPos(glm::vec3 newCameraPos);
	void setCameraFront(glm::vec3 newCameraFront);
	glm::mat4 getView();
	glm::mat4 getProject();

private:
	float cameraSpeed; // adjust accordingly
	float yaw, pitch;
	float fov;

	//Positions and directions related to the camera
	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;
	glm::vec3 cameraDirection;

	glm::vec3 up;
	glm::vec3 cameraRight;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
};

#endif // CAMERA_H


