#pragma once
#include <glfw/glfw3.h>

class Input
{
public:
    Input() : isAlive(true) {};
    ~Input() {};

    void processInput(GLFWwindow* window);
private:
    int isAlive;
};