#include <GL/glew.h>
#define FREEGLUT_STATIC
#include <GL/freeglut.h>
#include <iostream>
#include <fstream>
#include <string>

// printShaderInfoLog
// From OpenGL Shading Language 3rd Edition, p215-216
// Display (hopefully) useful error messages if shader fails to compile
void printShaderInfoLog(GLint shader)
{
    int infoLogLen = 0;
    int charsWritten = 0;
    GLchar *infoLog;

    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLen);

// should additionally check for OpenGL errors here

    if (infoLogLen > 0)
    {
        infoLog = new GLchar[infoLogLen];
// error check for fail to allocate memory omitted
        glGetShaderInfoLog(shader,infoLogLen, &charsWritten, infoLog);
        std::cout << "InfoLog:" << std::endl << infoLog << std::endl;
        delete [] infoLog;
    }

// should additionally check for OpenGL errors here
}


// loadFile - loads text file into char* fname
// allocates memory - so need to delete after use
// size of file returned in fSize
char* loadFile(const char *fname, GLint &fSize)
{
    std::ifstream::pos_type size;
    char * memblock;
    std::string text;

// file read based on example in cplusplus.com tutorial
    std::ifstream file (fname, std::ios::in|std::ios::binary|std::ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        fSize = (GLuint) size;
        memblock = new char [size];
        file.seekg (0, std::ios::beg);
        file.read (memblock, size);
        file.close();
        std::cout << "file " << fname << " loaded" << std::endl;
        text.assign(memblock);
    }
    else
    {
        std::cout << "Unable to open file " << fname << std::endl;
        exit(1);
    }
    return memblock;
}

void initShaders(void)
{
    GLuint p, f, v;

    char *vs,*fs;

    v = glCreateShader(GL_VERTEX_SHADER);
    f = glCreateShader(GL_FRAGMENT_SHADER);

// load shaders & get length of each
    GLint vlen;
    GLint flen;
    vs = loadFile("minimal.vert",vlen);
    fs = loadFile("minimal.frag",flen);
    const char * vv = vs;
    const char * ff = fs;

    glShaderSource(v, 1, &vv,&vlen);
    glShaderSource(f, 1, &ff,&flen);
    GLint compiled;

    glCompileShader(v);
    glGetShaderiv(v, GL_COMPILE_STATUS, &compiled);
    if (!compiled)
    {
        std::cout << "Vertex shader NOT compiled." << std::endl;
        printShaderInfoLog(v);
    }
    else
    {
        std::cout << "Vertex shader compiled." << std::endl;
    }

    glCompileShader(f);
    glGetShaderiv(f, GL_COMPILE_STATUS, &compiled);
    if (!compiled)
    {
        std::cout << "Fragment shader NOT compiled." << std::endl;
        printShaderInfoLog(f);
    }
    else
    {
        std::cout << "Fragment shader compiled." << std::endl;
    }
    p = glCreateProgram();

    glBindAttribLocation(p,0, "in_Position");
    glBindAttribLocation(p,1, "in_Color");
    glAttachShader(p,v);
    glAttachShader(p,f);
    glLinkProgram(p);
    glUseProgram(p);

    delete [] vs; // dont forget to free allocated memory
    delete [] fs; // we allocated this in the loadFile function...
}
