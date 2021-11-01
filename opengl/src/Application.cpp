#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <GL/glut.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(void)
{
    GLFWwindow* window;

    // Initialize GLFW library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a window
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "5 SIDE SHAPED POLYGON", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity(); // same as above comment

    GLfloat polygonVertices[] =
    {
        100, 100, 0,//A
        100, 300, 0,//B
        40, 300, 0,//C
        40, 320, 0,//D
        500, 320, 0,//E
        500, 300, 0,//F
        440, 300, 0,//G
        440, 100, 0,//H
    };

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // polygon drawing mode (GL_POINT, GL_LINE, GL_FILL)


    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // render OpenGL here
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, polygonVertices);
        glDrawArrays(GL_POLYGON, 0, 8);
        glDisableClientState(GL_VERTEX_ARRAY);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}