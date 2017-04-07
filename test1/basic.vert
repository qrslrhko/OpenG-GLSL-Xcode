#version 410 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 colorful;
out vec4 vertexColor;
uniform mat4 MVP;

uniform mat4 projection_matrix;
uniform mat4 view_matrix;
uniform mat4 model_matrix;
void main()
{
    gl_Position = projection_matrix * view_matrix * model_matrix * vec4(vertexPosition_modelspace,1.0f);
    //    gl_Position =vec4(vertexPosition_modelspace,1.0f);
    vertexColor = vec4(1, 0, 0, 1.0);
    //  vertexColor = vec4(colorful,1.0f);
}