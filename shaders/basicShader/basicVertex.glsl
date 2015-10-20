#version 410

layout(location=0) in vec3 position;
layout(location=1) in vec4 color;

uniform mat4 model;
uniform mat4 view;

out VS_OUTPUT{

       vec4 color;
       }OUT;

void main() {

     //TODO add tranfromations here

//view*model*
     gl_Position = view*model*vec4(position,1.0);
    OUT.color = color;


}
