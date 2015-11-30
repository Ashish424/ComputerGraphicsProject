#version 410




in TCS_OUT
{
    vec2 texCoords;
}fcs_in;




uniform sampler2D tester;
//uniform sampler2D textureSamplers[5];
out vec4 color;
void main() {

    color = texture(tester,fcs_in.texCoords);



}
