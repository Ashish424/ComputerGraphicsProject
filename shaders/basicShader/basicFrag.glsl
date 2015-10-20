#version 410

out vec4 frag_color;
in VS_OUTPUT{
   vec4 color;


   }IN;
void main() {


frag_color = IN.color;





}
