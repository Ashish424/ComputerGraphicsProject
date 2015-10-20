#version 410
    uniform sampler2D diffuse;
    out vec4 frag_colour;

    uniform vec4 ambient_color;
    uniform vec4 light_color;
    //camera position supplied here
    uniform vec3 camera_position;

    in VS_OUTPUT{
        vec3 World_position;
        vec3 FragColor;

        vec3 light_direction;
        vec3 normals;

    }IN;

      vec3 specular_color;

    void main(){
            specular_color = vec3(0.8,0.8,0.8);

            //save the texture color

            //using swizzling
            vec3 ambient  = IN.frag_colour.rgb*ambient_color.rgb;
            frag_colour.a = sampledColor.a;



            //normalize normal here imp
            vec3 normal = normalize(IN.normals);


            vec3 light_direction = normalize(IN.light_direction);
            float n_dot_1 = dot(light_direction,normal);



            vec3 diffuse = clamp(light_color.rgb*n_dot_1*sampledColor.rgb,0.0f,1.0f);
            vec3 viewDiff = normalize(camera_position-IN.World_position);
            vec3 reflectedDir = normalize(reflect(-light_direction,normal));



            float n_dot_2 =  pow(max(dot(reflectedDir,viewDiff), 0.0),256);
            vec3 specular = specular_color*n_dot_2;


            frag_colour.rgb = specular+ambient+diffuse+specular;
            frag_colour.a = IN.frag_colour.a;

        }
