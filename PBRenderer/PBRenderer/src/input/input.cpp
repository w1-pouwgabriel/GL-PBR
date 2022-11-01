#include "input.h"
#include "../graphics/camera.h"

Input::Input(Camera* cam)
    : isAlive(true),
    isFirstMouse(true)
{
    lastX = 800.0f / 2.0;
    lastY = 600.0 / 2.0;
    theCam = cam;
}

void Input::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        theCam->MoveForward();
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        theCam->MoveBackward();
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        theCam->MoveLeft();
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        theCam->MoveRight();
}

void Input::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (isFirstMouse)
    {
        lastX = (float)xpos;
        lastY = (float)ypos;
        isFirstMouse = false;
    }

    float xoffset = (float)xpos - lastX;
    float yoffset = lastY - (float)ypos;
    lastX = (float)xpos;
    lastY = (float)ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    float yaw = theCam->getYaw() + xoffset;
    float pitch = theCam->getPitch() + yoffset;

    theCam->setYaw(yaw);
    theCam->setPitch(pitch);

    if (pitch > 89.0f)
        theCam->setPitch(89.0f);
    if (pitch < -89.0f)
        theCam->setPitch(-89.0f);

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw) * cos(glm::radians(pitch)));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    theCam->setCameraFront(glm::normalize(direction));
}

void Input::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    float fov = theCam->getFov() - (float)yoffset;
    theCam->setFov(fov);

    if (fov < 1.0f)
        theCam->setFov(1.0f);
    if (fov > 45.0f)
        theCam->setFov(45.0f);
}