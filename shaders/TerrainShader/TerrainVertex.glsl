
#version 410
layout(location=0)  in vec3 position;
layout(location =1) in vec3 normal;
layout(location=2)  in vec2 textcoord;

//TODO output the required attribs for Bling-phong shading
//out VS_OUTPUT{
//
//}OUT;
      uniform mat4 model;
      uniform mat4 view;




    void main()
        {



            //set potision and normals
            gl_Position = view*model*vec4(position,1.0);
//            OUT.normals= vec3(transpose(inverse(model))*vec4(normal,0.0));

        }