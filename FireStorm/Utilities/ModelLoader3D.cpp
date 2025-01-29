// ModelLoader.cpp
#include "ModelLoader3D.h"
#include <iostream>
#include <vendor/tinyobjloader/tiny_obj_loader.h>



bool ModelLoader3D::loadModel(const std::string& filePath) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filePath.c_str())) {
        std::cerr << warn << err << std::endl;
        return false;
    }

    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            Vertex vertex;
            vertex.position = glm::vec3(attrib.vertices[3 * index.vertex_index + 0],
                                        attrib.vertices[3 * index.vertex_index + 1],
                                        attrib.vertices[3 * index.vertex_index + 2]);
            vertices.push_back(vertex);
            indices.push_back(indices.size());
        }
    }

    return true;
}

const std::vector<Vertex>& ModelLoader3D::getVertices() const {
    return vertices;
}

const std::vector<unsigned int>& ModelLoader3D::getIndices() const {
    return indices;
}