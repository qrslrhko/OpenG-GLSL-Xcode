#define _USE_MATH_DEFINES
#include <GL/glew.h>
//#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glut/glut.h>
#include <iostream>

const int na=36;        // vertex grid size
const int nb=18;
const int na3=na*3;     // line in grid size
const int nn=nb*na3;    // whole grid size
GLfloat sphere_pos[nn]; // vertex
GLfloat sphere_nor[nn]; // normal
//GLfloat sphere_col[nn];   // color
GLfloat  sphere_ix [na*(nb-1)*6];    // indices
//GLuint sphere_vbo[4]={-1,-1,-1,-1};
//GLuint sphere_vao[4]={-1,-1,-1,-1};
//GLuint sphere_vbo[4]={1,1,1,1};
//GLuint sphere_vao[4]={1,1,1,1};
GLuint sphere_vbo[4] ={ 0,1,2,3};
//GLuint sphere_vao[4]={0,1,2,3};
GLuint sphere_vao;

GLuint VBO,VBO_color, VAO;
GLuint index_vbo;    // Index buffer object
GLuint color_vbo;
//GLuint indices[] = {
//    2, 1, 4,
//    1, 3, 4,
//    0, 3, 1,
//    3, 5, 4
//};
//GLuint indices[] = {  // Note that we start from 0!
//    0, 1, 3,  // First Triangle
//    1, 2, 3   // Second Triangle
//};
GLuint indices[] = {
    //    0, 1, 2,
    //    2, 1, 3,
    
    0, 1, 4,
    4, 1, 3,
    4, 3, 2,
    4, 2, 0
    
};

void draw_trangle_init(){
    
    //    GLfloat vertices[] = {
    //        -0.5f, -0.5f, 0.0f, // Left
    //        0.5f, -0.5f, 0.0f, // Right
    //        0.0f,  0.5f, 0.0f  // Top
    //    };
    //
    //    GLfloat vertices[] = {-0.5f, -0.5f, 0.0f,
    //        0.0f, -0.5f, 0.0f,
    //        -0.25f,  0.0f, 0.0f,
    //        -0.25f,  0.0f, 0.0f,
    //        0.25f,  0.0f, 0.0f,
    //        0.0f,   0.5f, 0.0f,
    //        0.0f,  -0.5f, 0.0f,
    //        0.5f,  -0.5f, 0.0f,
    //        0.25f,  0.0f, 0.0f
    //    };
    //    GLfloat vertices[] = {
    //        0.5f,  0.5f, 0.0f,  // Top Right
    //        0.5f, -0.5f, 0.0f,  // Bottom Right
    //        -0.5f, -0.5f, 0.0f,  // Bottom Left
    //        -0.5f,  0.5f, 0.0f   // Top Left
    //    };
    GLfloat vertices[] = {
        0.0f, 0.0f, 0.0f,
        4.0f, 0.0f, 0.0f,
        0.0f, 4.0f, 0.0f,
        4.0f, 4.0f, 0.0f,
        2.0f, 2.0f, 4.0f
    };
    
    GLfloat color_box[]{
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };
    
    // for color buffer
    glGenBuffers(1, &VBO_color);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_color);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color_box), color_box, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    
    
    //    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    
    
    // for indices
    glGenBuffers(1, &index_vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_vbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    //    glDisableVertexAttribArray(0);
    
}

void draw_trangle(){
    //    glEnable(GL_CULL_FACE);
    //    glFrontFace(GL_CCW);
    //    glEnable(GL_LIGHTING);
    //    glEnable(GL_LIGHT0);
    //
    //    glBindVertexArray(VAO);
    //    glDrawArrays(GL_TRIANGLES, 0, 3);
    //    glBindVertexArray(0);
    //
    
    glBindVertexArray(VAO);
    //    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_vbo);
    
    glDrawElements( GL_TRIANGLES, 30 , GL_UNSIGNED_INT, 0 );
    //    glBindVertexArray(0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    //    glDisable(GL_CULL_FACE);
    //    glDisable(GL_LIGHTING);
    //    glDisable(GL_DEPTH_TEST);
    
    
}

void exit_trangle(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &index_vbo);
}


