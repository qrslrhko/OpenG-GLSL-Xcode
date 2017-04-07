
#include <GL/glew.h>

#include "objects.h"


#include <glut/glut.h>
#include <iostream>

#include "Shader.h"
#include <vector>


#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLEW_STATIC

bool keys[1024];
bool firstMouse = true;
GLfloat lastX = 400, lastY = 300;


glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);

GLfloat yaw    = -90.0f;
GLfloat pitch  =  0.0f;


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    //GLFW_KEY_A   GLFW_KEY_D
    GLfloat cameraSpeed = 0.05f;
    if(key == GLFW_KEY_W)
        cameraPos += cameraSpeed * cameraFront;
    if(key == GLFW_KEY_S)
        cameraPos -= cameraSpeed * cameraFront;
    if(key == GLFW_KEY_D)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if(key == GLFW_KEY_A)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    
    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos; // Reversed since y-coordinates go from bottom to left
    lastX = xpos;
    lastY = ypos;
    
    GLfloat sensitivity = 0.05;	// Change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    
    yaw   += xoffset;
    pitch += yoffset;
    
    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;
    
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}


int main(int argc, char **argv)
{
    
    glfwInit();
    
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    glfwMakeContextCurrent(window);
    
    
    glfwSetKeyCallback(window, key_callback);
    //  glfwSetCursorPosCallback(window, mouse_callback);
    
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    
    Shader shader("basic.vert", "basic.frag");
    

    while (!glfwWindowShouldClose(window))
    {
        
        
        
        
        glfwPollEvents();
        
        //        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //                sphere_init();
        
        glEnable(GL_DEPTH_TEST);
        shader.Use();
        
        draw_trangle_init();

        
        GLint projectMat = glGetUniformLocation(shader.Program,"projection_matrix");
        GLint viewMat = glGetUniformLocation(shader.Program,"view_matrix");
        GLint modelMat = glGetUniformLocation(shader.Program,"model_matrix");
        
        
        GLuint MatrixID = glGetUniformLocation(shader.Program, "MVP");
        
        GLfloat radius = 10.0f;
        GLfloat camX = sin(glfwGetTime()) * radius;
        GLfloat camZ = cos(glfwGetTime()) * radius;
        
        // view matrix
        glm::mat4 view;

        glm :: mat4 view_matrix = glm::lookAt(glm::vec3(15.0f, 15.0f, 10.0f),
                                              glm::vec3(0.0f, 0.0f, 0.0f),
                                              glm::vec3(0.0f, 1.0f, 0.0f));
        
        //        glm::mat4 view_matrix  = view;
        
        // projection matrix
        float aspect=float(4.0f)/float(3.0f);
        glm::mat4 projection_matrix = glm::perspective(60.0f/aspect,aspect,0.1f,100.0f);

        glm::mat4 model_matrix = glm::mat4(1.0f);// identity
        glm::mat4 model;
        
        model_matrix= glm::rotate(model_matrix, (GLfloat)glfwGetTime() * .4f, glm::vec3(0.5f, 1.0f, 0.0f));
        //
        model = model_matrix;
        
        //ModelViewProjection
        glm::mat4 model_view_projection = projection_matrix * view_matrix * model_matrix;
        
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &model_view_projection[0][0]);
        glUniformMatrix4fv(projectMat, 1, GL_FALSE, glm::value_ptr(projection_matrix));
        glUniformMatrix4fv(viewMat, 1, GL_FALSE, glm::value_ptr(view_matrix));
        glUniformMatrix4fv(modelMat, 1, GL_FALSE, glm::value_ptr(model));
        

        
        draw_trangle();
        
        
        
    
        //        glFlush();
        glfwSwapBuffers(window);
    }
    
    exit_trangle();
    glfwTerminate();
    return 0;
}

