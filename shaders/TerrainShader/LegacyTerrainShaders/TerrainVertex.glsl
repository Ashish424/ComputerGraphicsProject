
#version 410
layout(location=0)  in vec3 position;
layout(location =1) in vec3 normal;
layout(location=2)  in vec2 textcoord;

//TODO output the required attribs for Bling-phong shading
out VS_OUTPUT{
vec3 normals;
vec2 TexCoord;
vec3 worldSpacePos;
}OUT;
uniform mat4 model;
uniform mat4 view;




void main(){


//pass on vars
    OUT.worldSpacePos = vec3(model*vec4(position,1.0));
    OUT.normals= vec3(transpose(inverse(model))*vec4(normal,0.0));
    OUT.TexCoord = vec2(textcoord.x, textcoord.y);



//calulate in view space
    gl_Position = view*vec4(OUT.worldSpacePos,1.0);






}