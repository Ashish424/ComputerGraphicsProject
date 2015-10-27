#version 410
out vec4 frag_colour;
in VS_OUTPUT{
vec3 normals;
vec2 TexCoord;
vec3 worldSpacePos;
}IN;




#define NR_POINT_LIGHTS 4
#define NR_DIRECTION_LIGHTS 4
#define NR_SPOT_LIGHTS 4

//struct delcaration
//material to store required components
//it is uniform so realtime effects possible
struct TerrainMaterial {
    //TODO add ambinet map later
    //TODO add normal map samling in different lights
    vec3 ambient;

    sampler2D diffuseSampler;
    sampler2D specularSampler;
    sampler2D normalSampler;
    //shininess is the specular coefffiecnt
    float shininess;

};


//Camera position in world coordinate System
uniform vec3 cameraPos;
//various light components
//sense of distance but no sense of direction
struct PointLight {
    vec3 position;
    //attenuation control
    float constant;float linear;float quadratic;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
//only direction no sense of distance
struct DirLight {
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight {
    vec3 position;
    float cutOffAngle;
    vec3 spotDirection;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

//fill in worldspace data of light here
uniform TerrainMaterial material;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform DirLight dirLights[NR_DIRECTION_LIGHTS];
uniform SpotLight spotLights[NR_SPOT_LIGHTS];

//methods to calulate lighting
vec3 calPointLight(TerrainMaterial m,PointLight p);
vec3 calDirLight(TerrainMaterial m,DirLight d);
//TODO add spotlight structure in function apramter
vec3 calSpotLight(TerrainMaterial m,SpotLight s);

void main(){




    frag_colour = texture(material.diffuseSampler,IN.TexCoord);


}




vec3 calPointLight(TerrainMaterial m,PointLight p){



    float distance  =  length(p.position-IN.worldSpacePos);
    float attenuation = 1.0f / (p.constant + p.linear * distance + p.quadratic * (distance * distance));
    vec3 ambient = material.ambient*p.ambient*attenuation;
    vec3 diffuse = vec3(texture(material.diffuseSampler,IN.TexCoord))*p.diffuse*attenuation;
    vec3 specular = vec3(texture(material.specularSampler,IN.TexCoord))*p.specular*attenuation;
    return ambient+specular+diffuse;



}
vec3 calDirLight(TerrainMaterial m,DirLight d){
//assuming .direction is normalized


//diffuse calculation
vec3 diffuse  =  vec3(texture(material.diffuseSampler,IN.TexCoord))*max(dot(IN.normals, -d.direction), 0.0)*d.diffuse;
//specular calculation
vec3 reflectedDirection  =  reflect(d.direction,normalize(IN.normals));
vec3 viewDirection = normalize(cameraPos- IN.worldSpacePos);
float spec = pow(max(dot(reflectedDirection,viewDirection),0.0),material.shininess);
vec3 specular =  vec3(texture(material.specularSampler,IN.TexCoord))*d.specular;
//TODO update this with ambient map
vec3 ambient = d.ambient * vec3(texture(material.diffuseSampler,IN.TexCoord));
return ambient+specular+diffuse;


}
vec3 calSpotLight(TerrainMaterial m,SpotLight s){


float spotVal = abs(dot(normalize(IN.worldSpacePos-s.position),s.spotDirection));
float cosComp = abs(cos(s.cutOffAngle));
//comparing cosines
if(spotVal < cosComp)spotVal = 0.0f;
//float spotVal = dot() ;
//diffuse calculation
vec3 diffuse  =  vec3(texture(material.diffuseSampler,IN.TexCoord))*max(dot(IN.normals, -s.spotDirection), 0.0)*s.diffuse;
return vec3(0.0,0.0,0.0);

}