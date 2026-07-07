// File: glm_hello.cpp
#include <iostream>
#include <fstream>
#include <string>

// GLM (header-only)
#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>  // translate, rotate, scale, perspective, lookAt
#include <glm/gtc/quaternion.hpp>        // quat, angleAxis
#include <glm/gtx/quaternion.hpp>        // toMat4
#include <glm/gtx/string_cast.hpp>       // glm::to_string

using namespace std;

// Bac-style files. Change to "bac.in"/"bac.out" if needed.
ifstream  fin ("input.in");
ofstream  fout("output.out");

int main(int argc, char** argv)
{
    cout << "GLM Hello World (math only)" << '\n';

    if (!fin.is_open())  cerr << "[Warn] input.in not found. Reading from keyboard.\n";
    if (!fout.is_open()) cerr << "[Warn] output.out cannot be opened. File output disabled.\n";

    // Read a point p = (x,y,z).
    float x = 1.f, y = 2.f, z = 3.f;
    if (!(fin >> x >> y >> z)) {
        cout << "Enter x y z: ";
        if (!(cin >> x >> y >> z)) {
            cerr << "No input. Exiting.\n";
            return 0;
        }
    }
    glm::vec3 p(x, y, z);

    // Basis vectors.
    glm::vec3 ex(1,0,0), ey(0,1,0), ez(0,0,1);

    // Scalar, vector ops.
    float dot_xy = glm::dot(ex, ey);        // = 0
    glm::vec3  cr = glm::cross(ex, ey);     // = ez
    float normp = glm::length(p);           // ||p||
    glm::vec3  u  = glm::normalize(p);      // p / ||p||

    // Model = T * R * S.
    glm::mat4 I(1.0f);
    glm::mat4 T = glm::translate(I, glm::vec3(1.0f, 2.0f, 3.0f));
    glm::quat  q = glm::angleAxis(glm::radians(45.0f), glm::vec3(0,1,0));
    glm::mat4 R  = glm::toMat4(q);
    glm::mat4 S  = glm::scale(I, glm::vec3(2.0f, 0.5f, 1.0f));
    glm::mat4 M  = T * R * S;

    // Homogeneous point.
    glm::vec4 ph(p, 1.0f);
    glm::vec4 p_world = M * ph;

    // View and Projection.
    glm::mat4 V = glm::lookAt(
        glm::vec3(0,0,5),   // eye
        glm::vec3(0,0,0),   // center
        glm::vec3(0,1,0));  // up
    glm::mat4 P = glm::perspective(glm::radians(60.0f), 16.0f/9.0f, 0.1f, 100.0f);

    glm::vec4 p_clip = P * V * p_world;

    auto dump = [&](ostream& os){
        os << "p = "              << glm::to_string(p)       << '\n';
        os << "<ex,ey> = "        << dot_xy                  << '\n';
        os << "ex x ey = "        << glm::to_string(cr)      << '\n';
        os << "||p|| = "          << normp                   << '\n';
        os << "normalize(p) = "   << glm::to_string(u)       << '\n';
        os << "M = T*R*S = "      << glm::to_string(M)       << '\n';
        os << "p_world = "        << glm::to_string(p_world) << '\n';
        os << "V = lookAt(...) = "<< glm::to_string(V)       << '\n';
        os << "P = perspective = "<< glm::to_string(P)       << '\n';
        os << "p_clip = P*V*M*p = "<< glm::to_string(p_clip) << '\n';
    };

    dump(cout);
    if (fout.is_open()) dump(fout);

    cout << "Done.\n";
    return 0;
}
