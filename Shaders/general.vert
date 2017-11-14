#version 410 core

layout(location = 0) in	vec4 vertexPosition_modelspace;
out vec4				color;
uniform mat4 VP;
void main(){
	color = vec4(1.0,1.0,1.0,1.0);
	gl_Position = VP * vertexPosition_modelspace;
}
