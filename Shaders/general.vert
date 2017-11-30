#version 410 core

layout(location = 0) in	vec4 vertexPosition_modelspace;
out vec4				color;
uniform mat4 VP;
uniform vec4 center;
uniform vec4 inColor;
void main(){
	float dist = distance(vertexPosition_modelspace, center) / 20.0f;
	dist = dist > 1.0f ? 1.0f : dist;
<<<<<<< HEAD
	vec4 minColor = inColor * 0.5f;
=======
	vec4 minColor = inColor * 0.1f;
>>>>>>> e550056d2ba6df8edf0763efcd7953380a0a5a0f
	color = minColor + dist * (inColor - minColor);
	gl_Position = VP * vertexPosition_modelspace;
}
