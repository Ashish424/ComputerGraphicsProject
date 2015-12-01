#version 410




in TCS_OUT
{
    vec2 texCoords;
    float myHeight;
}fcs_in;


uniform float heightMapdepth;
//switch color range
const float fRange1 = 0.15f;
const float fRange2 = 0.3f;
const float fRange3 = 0.65f;
const float fRange4 = 0.85f;

uniform sampler2D textureSamplers[3];
out vec4 color;
void main() {

//    color = texture(textureSamplers[0],fcs_in.texCoords);
    float scale =  (fcs_in.myHeight)/heightMapdepth;


    if(scale >= 0.0)color = texture(textureSamplers[0], fcs_in.texCoords);
    else if(scale <= fRange2)
    {
          scale -= fRange1;
          scale /= (fRange2-fRange1);

          float fScale2 = scale;
          scale = 1.0-scale;

          color += texture(textureSamplers[0], fcs_in.texCoords)*scale;
          color += texture(textureSamplers[1], fcs_in.texCoords)*fScale2;
    }
    else if(scale <= fRange3)color = texture(textureSamplers[1], fcs_in.texCoords);
    else if(scale <= fRange4)
    {
      scale -= fRange3;
      scale /= (fRange4-fRange3);

      float fScale2 = scale;
      scale = 1.0-scale;

      color += texture(textureSamplers[1], fcs_in.texCoords)*scale;
      color += texture(textureSamplers[2], fcs_in.texCoords)*fScale2;
   }
   else color = texture(textureSamplers[2], fcs_in.texCoords);




}
