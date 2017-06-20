#include "DCamera.h"

void DCamera::init()
{
    glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);//Sets the position of the Camera in the World
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f); //The Coordinates of the target i.e the object to be focused by the camera
    glm::vec3 cameraDirection = glm::normalize(cameraPosition - cameraTarget);//The Direction Vector from the Camera Position to the Target
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);//A Unit Vector that points in the +Y Direction in the world space
    glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));//Right Vector of the Camera
    glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);//Up Vector of the Camera
    glm::vec3 cameraFront = glm::vec3 (0.0f, 0.0f, -1.0f);


}

void DCamera::updateCameraPosition(SDL_Keycode k)
{
    std::cout<<"\n Updated Camera";
    if(k==SDLK_w)
        cameraPosition += cameraSpeed * cameraFront;
    if(k==SDLK_s)
        cameraPosition -= cameraSpeed * cameraFront;
    if(k==SDLK_a)
        cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)*cameraSpeed);
    if(k==SDLK_d)
        cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)*cameraSpeed);
}

void DCamera::updateCameraSpeed(GLfloat deltaTime)
{
    cameraSpeed = 1.0f*deltaTime;
}

void DCamera::updateCameraFront(glm::vec3 camFront)
{
    cameraFront = camFront;
}

glm::mat4 DCamera::camView()
{
    return(glm::lookAt(cameraPosition, cameraPosition+cameraFront, cameraUp));
}

glm::vec3 DCamera::getCameraPosition() const
{
    return cameraPosition;
}

glm::vec3 DCamera::getCameraUp() const
{
    return cameraUp;
}

glm::vec3 DCamera::getCameraFront() const
{
    return cameraFront;
}