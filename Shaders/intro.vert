#version 410 core

layout(location = 0) in vec2 vertex_pos;
layout(location = 1) in vec2 vertex_text;

out vec2 UV;

void main () {
	UV = vertex_text;
	gl_Position = vec4(vertex_pos.x, vertex_pos.y, 0.1f, 1.0f);
}