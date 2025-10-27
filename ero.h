#include <stdio.h>

GLenum errorCheck(void)
{
    GLenum code;
    const GLubyte *string;

    code = glGetError();

    if (code != GL_NO_ERROR) {
        string = gluErrorString(code);
        if (string)
            fprintf(stderr, "OPENGL ERROR: %s\n", string);
        else
            fprintf(stderr, "OPENGL ERROR: Unknown error code 0x%X\n", code);
    }

    return code;
}

