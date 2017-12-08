#version 410 core

in vec2  UV;
out vec4 frag_color;
uniform sampler2D myTexture;

void main () {

	frag_color = texture( myTexture, UV);
	//frag_color = vec4(1.0f,0.0f,1.0f,1.0f);
}