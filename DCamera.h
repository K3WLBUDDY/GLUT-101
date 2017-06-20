#ifndef DCAMERAH
#define DCAMERAH

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <iostream>


class DCamera
{
    private:

    glm::vec3 cameraPosition;
    glm::vec3 cameraTarget; 
    glm::vec3 cameraDirection; 
    glm::vec3 up; 
    glm::vec3 cameraRight;
    glm::vec3 cameraUp; 
    glm::vec3 cameraFront; 
    glm::mat4 view;
    GLfloat cameraSpeed;
    

    public:

    DCamera () : cameraPosition(glm::vec3(0.0f, 0.0f, 3.0f)), cameraTarget(glm::vec3(0.0f, 0.0f, 0.0f)),
                 cameraDirection(glm::normalize(cameraPosition - cameraTarget)), up(glm::vec3(0.0f, 1.0f, 0.0f)),
                 cameraRight(glm::normalize(glm::cross(up, cameraDirection))), cameraUp(glm::cross(cameraDirection, cameraRight)), cameraFront(glm::vec3 (0.0f, 0.0f, -1.0f)),
                 cameraSpeed(0.05f)
                 {}
    void init();
    void updateCameraPosition(SDL_Keycode);
    void updateCameraSpeed(GLfloat);
    void updateCameraFront(glm::vec3);
    glm::mat4 camView();

    glm::vec3 getCameraPosition() const;
    glm::vec3 getCameraUp() const;
    glm::vec3 getCameraFront() const;
    
};
#endif