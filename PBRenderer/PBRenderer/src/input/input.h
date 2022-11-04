#pragma once
#include <glfw/glfw3.h>

class Camera;

class Input
{
public:
    Input(Camera* cam);
    ~Input() {};

    void processInput(GLFWwindow* window);
    void mouse_callback(GLFWwindow* window, double xpos, double ypos); 
    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    
private:
    bool isAlive; 
    float lastX, lastY;
    bool isFirstMouse; 
    int isMouseHide;

    Camera* theCam;
};