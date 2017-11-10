#version 410 core

layout(location = 0) in	vec3 vertexPosition_modelspace;
layout(location = 1) in	vec4 vColor;
uniform mat4			VP;
out vec4				color;

void main(){
	color = vColor;
	gl_Position = VP * vec4(vertexPosition_modelspace,1);
}
