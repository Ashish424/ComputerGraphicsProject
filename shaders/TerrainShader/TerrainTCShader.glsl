#version 410




layout (vertices = 4) out;

in VS_OUT
{
    vec2 heightMapCoords;
} tcs_in[];

out TCS_OUT
{
    vec2 heightMapCoords;
} tcs_out[];



//model matrix for world space coords
uniform mat4 model;



//used for adaptive tesselation
uniform vec3 cameraPos;
uniform float doCameraTessel;

uniform float minTessLevel;
uniform float maxTessLevel;



//used for static tesselation
uniform float fixedTessLevel;




//TODO remove this and put  max camera distance here
#define MAXLENGTH 40

void main() {

 if (gl_InvocationID == 0)
    {


         if(doCameraTessel > 0.5f)
         {
             vec4 pos = model*(gl_in[gl_InvocationID].gl_Position);
             float val  = length(vec3(pos)-cameraPos);
             val/=MAXLENGTH;
             float depth = clamp(val,0.0,1.0);

             //interpolate in reverse!
             float tessLevel = mix(maxTessLevel, minTessLevel,depth);



            gl_TessLevelInner[0] = tessLevel;
            gl_TessLevelInner[1] = tessLevel;

            gl_TessLevelOuter[0] = tessLevel;
            gl_TessLevelOuter[1] = tessLevel;
            gl_TessLevelOuter[2] = tessLevel;
            gl_TessLevelOuter[3] = tessLevel;

         }
         //fixed tess levels
         else
         {

            gl_TessLevelInner[0] = fixedTessLevel;
            gl_TessLevelInner[1] = fixedTessLevel;

            gl_TessLevelOuter[0] = fixedTessLevel;
            gl_TessLevelOuter[1] = fixedTessLevel;
            gl_TessLevelOuter[2] = fixedTessLevel;
            gl_TessLevelOuter[3] = fixedTessLevel;


         }
    }



    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
    tcs_out[gl_InvocationID].heightMapCoords = tcs_in[gl_InvocationID].heightMapCoords;










}
