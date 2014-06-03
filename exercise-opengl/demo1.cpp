// Put the stuff that is need but currently
// not of interest in other file
#include "shaderstuff.hpp"
// Library for simple interaction with graphics driver versions
#include <GL/glew.h>
// Library for simple platform independent window
#define FREEGLUT_STATIC
#include <GL/freeglut.h>
// Standard console output
#include <iostream>
// ID to adress vertex array object when drawing it
unsigned int vertexArrayObjID;
// Number of vertices in our example
const int numVerts = 3;

void createGeometry()
{
    // generate vertex array object name
    glGenVertexArrays( 1, &vertexArrayObjID );
    // bind ("make current") a vertex array object
    // which stores the state set below (e.g. vertices, color)
    glBindVertexArray( vertexArrayObjID );
    // Vertex buffer object for vertex data
    unsigned int vertexBufferObjID_0;
    // Generates name for the data of the vertex buffer
    glGenBuffers( 1, &vertexBufferObjID_0 );
    // Bind ("make current") the vertex buffer
    glBindBuffer( GL_ARRAY_BUFFER, vertexBufferObjID_0 );
    // The vertex coordinates
    GLfloat vertices[] = { -1.0f, 0.0f, 0.0f,
                            0.0f, 1.0f, 0.0f,
                            0.0f, 0.0f, 0.0f };
    // Components (floats) per vertex position
    const int numVertComps = 3;
    // Creates and initializes a buffer object's data store
    // vwith the vertex coordinates data
    glBufferData( GL_ARRAY_BUFFER, 
                  numVertComps*numVerts*sizeof(GLfloat),
                  vertices, GL_STATIC_DRAW );
    // Define the attribute which will be used to 
    // access the data on the GPU
    glVertexAttribPointer( (GLuint)0, numVertComps, GL_FLOAT, 
                           GL_FALSE, 0 /*stride*/,
                           0 /*initialOffsetPointer*/ );
    // Activate the attribute
    glEnableVertexAttribArray( 0 );
// Vertex buffer object for color data
    unsigned int vertexBufferObjID_1;
    // Generates name for the data of the buffer holding color values
    glGenBuffers(1, &vertexBufferObjID_1);
    // Bind ("make current") the buffer for the color
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjID_1);
    // The color values
    GLfloat colors[] = { 1.0f, 0.0f, 0.0f,
                         0.0f, 1.0f, 0.0f,
                         0.0f, 0.0f, 1.0f };
    // Components (floats) per color value
    const int numColComps = 3;
    // Creates and initializes the current buffer object's data store with the color data
    glBufferData(GL_ARRAY_BUFFER, numColComps*numVerts*sizeof(GLfloat), colors, GL_STATIC_DRAW);
    // Define the attribute which will be used to access the data on the GPU
    glVertexAttribPointer((GLuint)1, numColComps, GL_FLOAT, 
                          GL_FALSE, 0 /*stride*/, 0 /*initialOffsetPointer*/);
    // Activate the attribute
    glEnableVertexAttribArray(1);



    // break the existing vertex array object binding.
    glBindVertexArray(0);
} // end of createGeometry function


void display(void)
{
    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    // activate the vertex array object set above
    glBindVertexArray(vertexArrayObjID);
    // draw the vertex array from the activated vertex array object
    glDrawArrays(GL_TRIANGLES, 0, numVerts);
    // show the drawn geometry on the screen
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
}
int main (int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600,600);
    glutCreateWindow("Coburger OpenGL Beispiel 2014");
    glewInit();
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        // Problem: glewInit failed, something is seriously wrong.
        std::cout << "glewInit failed, aborting." << std::endl;
        exit (1);
    }
    std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
    std::cout << "OpenGL version " << glGetString(GL_VERSION) << " supported" << std::endl;

    createGeometry();
    initShaders();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
