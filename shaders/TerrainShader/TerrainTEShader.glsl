#version 410





layout( quads,fractional_odd_spacing ) in;



uniform sampler2D heightMapDisplacer;
uniform float heightMapdepth;
in TCS_OUT
{
    vec2 heightMapCoords;
} tes_in[];

out TCS_OUT
{
    vec2 texCoords;
} tes_out;







uniform mat4 model;
uniform mat4 view;




void main() {


//just bilinear interpolation
//for heightmap coords
   vec2 tc1 = mix(tes_in[0].heightMapCoords, tes_in[1].heightMapCoords, gl_TessCoord.x);
   vec2 tc2 = mix(tes_in[2].heightMapCoords, tes_in[3].heightMapCoords, gl_TessCoord.x);
   vec2 tc = mix(tc2, tc1, gl_TessCoord.y);


//for position
   vec4 p1 = mix(gl_in[0].gl_Position, gl_in[1].gl_Position, gl_TessCoord.x);
   vec4 p2 = mix(gl_in[2].gl_Position, gl_in[3].gl_Position, gl_TessCoord.x);
   vec4 p = mix(p2, p1, gl_TessCoord.y);



   p.y += texture(heightMapDisplacer, tc).r * heightMapdepth;




   //multiply matrices
   gl_Position = view*model *p;


    tes_out.texCoords = tc;










}
