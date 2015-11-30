#version 410
out VS_OUT
{
    vec2 heightMapCoords;
} vs_out;



uniform float dimension;
void main(void)
{
    const vec4 vertices[] = vec4[](vec4(-0.5, 0.0, -0.5, 1.0),
                                   vec4( 0.5, 0.0, -0.5, 1.0),
                                   vec4(-0.5, 0.0,  0.5, 1.0),
                                   vec4( 0.5, 0.0,  0.5, 1.0));


    int dim = int(dimension);
    //mod by dim
    float temp = mod(gl_InstanceID,dim);
    int x = int(temp);

    //divide by dim
    int y = gl_InstanceID / dim;
    vec2 offs = vec2(x, y);





    gl_Position = vertices[gl_VertexID] + vec4(float(x - dim/2), 0.0,float(y - dim/2), 0.0);

    //write output data to output interface blocks
    vs_out.heightMapCoords = (vertices[gl_VertexID].xz + offs + vec2(0.5))/dim;

}
