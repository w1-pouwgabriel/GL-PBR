#include "camera.h"

Camera::Camera()
{
	cameraSpeed = 0.05f; 
	yaw = -90.0f;			// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
	pitch = 0.0f;
	fov = 45.0f;

	cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	cameraDirection = glm::normalize(cameraPos - cameraTarget);

	up = glm::vec3(0.0f, 1.0f, 0.0f);
	cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::cross(cameraDirection, cameraRight);
}

Camera::~Camera()
{
	
}

void Camera::Update(float deltaTime)
{
	cameraSpeed = 2.5f * deltaTime;
}

void Camera::MoveForward()
{
	cameraPos += cameraSpeed * cameraFront;
}

void Camera::MoveBackward()
{
	cameraPos -= cameraSpeed * cameraFront;
}

void Camera::MoveLeft()
{
	cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

void Camera::MoveRight()
{
	cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

void Camera::setYaw(float newYaw)
{
	yaw = newYaw;
}
void Camera::setPitch(float newPitch)
{
	pitch = newPitch;
}
void Camera::setFov(float newFov)
{
	fov = newFov;
}
float Camera::getYaw() const
{
	return yaw;
}
float Camera::getPitch() const
{
	return pitch;
}
float Camera::getFov() const
{
	return fov;
}
void Camera::setCameraPos(glm::vec3 newCameraPos)
{
	cameraPos = newCameraPos;
}
void Camera::setCameraFront(glm::vec3 newCameraFront)
{
	cameraFront = newCameraFront;
}
glm::mat4 Camera::getView()
{
	return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
glm::mat4 Camera::getProject()
{
	return glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);
}