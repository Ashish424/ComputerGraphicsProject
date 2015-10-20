
#version 410
layout(location=0) in vec3 position;
layout(location=1) in vec2 textcoord;
layout(location =2) in vec3 color;
layout(location =3) in vec3 normal;


out VS_OUTPUT{
    vec3 World_position;
    vec3 FragColor;
    vec2 syncTextCoord;
    vec3 light_direction;
    vec3 normals;
}OUT;
    uniform mat4 transform;
    uniform mat4 view;
    uniform vec4 light_direction;

    void main()
        {


            //we want only the world coordinates
            OUT.World_position = (transform*vec4(position,1.0)).xyz;

             //set potision
            gl_Position = view*transform*vec4(position,1.0);
            OUT.normals= vec3(transpose(inverse(transform))*vec4(normal,0.0));


            OUT.light_direction.xyz = -light_direction.xyz;
            OUT.FragColor = color;
        }