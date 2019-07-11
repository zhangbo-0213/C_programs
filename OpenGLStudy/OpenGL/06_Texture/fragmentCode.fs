#version 330 core
in vec3 outColor;
in vec2 texCoord;

out vec4 FragColor;
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixValue;

void main(){
    //FragColor=texture(texture1,texCoord)*vec4(outColor,1.0f);
    FragColor=mix(texture(texture1,texCoord),texture(texture2,vec2(texCoord.x,texCoord.y)*3.0f-1.0f),mixValue);
}


