#version 410 core

//layout(location = 0) in	vec4 vertexPosition_modelspace;
layout(location = 0) in	vec3 vertexPosition_modelspace;
out vec4				color;
uniform mat4 VP;
void main(){
	color = vec4(1.0,1.0,1.0,1.0);
	//gl_Position = VP * vertexPosition_modelspace;
	gl_Position = VP * vec4(vertexPosition_modelspace,1.0f);
}
