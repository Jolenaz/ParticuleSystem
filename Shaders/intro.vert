#version 410 core

layout(location = 0) in vec3 vertex_pos;
//layout(location = 1) in vec2 vertex_text;

//out vec2 UV;

void main () {
//	UV = vertex_text;
	gl_Position = vec4(vertex_pos, 1.0f);
}