#include "Mesh.hpp"


Mesh::Mesh() {
	//
}
Mesh::Mesh(GLuint indices[], const std::string& vert_shader, const std::string& frag_shader) {
	//
}

void Mesh::addIndices(std::vector<GLuint>& indices) {
	ibo.createIndexBuffer(indices.data(), indices.size());
}
void Mesh::addIndices(GLuint indices[], int size) {
	ibo.createIndexBuffer(indices, size);
}
void Mesh::addFloatBuffer(GLfloat bufferData[]) {

}
void Mesh::addUIntBuffer(GLuint bufferData[]) {
	
}
void Mesh::addShader(const std::string& vert_shader, const std::string& frag_shader) {

}

