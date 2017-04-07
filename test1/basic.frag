#version 410 core


out vec4 color;
in vec4 vertexColor;

void main()
{
    color = vertexColor;
    
    //color = vec4(1.0f,0.0f,2.0f,1.0f);
}