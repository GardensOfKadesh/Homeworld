#ifndef ___GLINC_H
#define ___GLINC_H

#ifdef HW_ENABLE_GLES

//#include <GLES/egl.h>
//#include <GLES/glext.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>
#include <stdio.h>

#define GL_QUADS                0x0007
#define GL_POLYGON              0x0009

#define GL_VERTEX_ARRAY         0x8074
#define GL_NORMAL_ARRAY         0x8075
#define GL_COLOR_ARRAY          0x8076
//#define GL_INDEX_ARRAY	        0x8077
#define GL_TEXTURE_COORD_ARRAY  0x8078


// these need to be emulated!
#define GL_ALPHA_TEST           0x0BC0
#define GL_FLAT                 0x1D00
#define GL_SMOOTH               0x1D01
#define GL_MODULATE             0x2100
#define GL_LINE_SMOOTH          0x0B20



#define GL_MODELVIEW                    0x1700
#define GL_PROJECTION                   0x1701
#define GL_TEXTURE                      0x1702

typedef struct GLMatrix {
    float m0, m4, m8, m12;
    float m1, m5, m9, m13;
    float m2, m6, m10, m14;
    float m3, m7, m11, m15;
} GLMatrix;


static unsigned int gles_immediate = 0;
static GLenum gles_mode;
static GLfloat gles_vertex[16384];
static GLfloat gles_texcoord[16384];
static GLfloat gles_colors[16384];
static GLfloat gles_normals[16384];
static unsigned int gles_vertex_count = 0;
static unsigned int gles_texcoord_count = 0;
static unsigned int gles_color_count = 0;
static unsigned int gles_normal_count = 0;
static unsigned char gles_vertex_dimensions = 2;
static GLushort gles_quad_indices[4] = { 1, 2, 0, 3 };

static GLuint buffer_object_vertex;
static GLuint buffer_object_normal;
static GLuint buffer_object_color;
static GLuint buffer_object_texcoord;
static int gl_state_p = 0;
static GLuint gl_state_programs[3];

static int gl_state_matrix_current_mode;
static GLMatrix *gl_state_matrix_current;
static GLMatrix gl_state_matrix_modelview;
static GLMatrix gl_state_matrix_projection;
static GLMatrix gl_state_matrix_transform;
static int gl_state_matrix_transform_required = 0;
static GLMatrix gl_state_matrix_stack[64];
static int gl_state_matrix_stack_counter = 0;


GLMatrix MatrixMultiply(GLMatrix left, GLMatrix right)
{
    GLMatrix result = { 0 };

    result.m0 = left.m0*right.m0 + left.m1*right.m4 + left.m2*right.m8 + left.m3*right.m12;
    result.m1 = left.m0*right.m1 + left.m1*right.m5 + left.m2*right.m9 + left.m3*right.m13;
    result.m2 = left.m0*right.m2 + left.m1*right.m6 + left.m2*right.m10 + left.m3*right.m14;
    result.m3 = left.m0*right.m3 + left.m1*right.m7 + left.m2*right.m11 + left.m3*right.m15;
    result.m4 = left.m4*right.m0 + left.m5*right.m4 + left.m6*right.m8 + left.m7*right.m12;
    result.m5 = left.m4*right.m1 + left.m5*right.m5 + left.m6*right.m9 + left.m7*right.m13;
    result.m6 = left.m4*right.m2 + left.m5*right.m6 + left.m6*right.m10 + left.m7*right.m14;
    result.m7 = left.m4*right.m3 + left.m5*right.m7 + left.m6*right.m11 + left.m7*right.m15;
    result.m8 = left.m8*right.m0 + left.m9*right.m4 + left.m10*right.m8 + left.m11*right.m12;
    result.m9 = left.m8*right.m1 + left.m9*right.m5 + left.m10*right.m9 + left.m11*right.m13;
    result.m10 = left.m8*right.m2 + left.m9*right.m6 + left.m10*right.m10 + left.m11*right.m14;
    result.m11 = left.m8*right.m3 + left.m9*right.m7 + left.m10*right.m11 + left.m11*right.m15;
    result.m12 = left.m12*right.m0 + left.m13*right.m4 + left.m14*right.m8 + left.m15*right.m12;
    result.m13 = left.m12*right.m1 + left.m13*right.m5 + left.m14*right.m9 + left.m15*right.m13;
    result.m14 = left.m12*right.m2 + left.m13*right.m6 + left.m14*right.m10 + left.m15*right.m14;
    result.m15 = left.m12*right.m3 + left.m13*right.m7 + left.m14*right.m11 + left.m15*right.m15;

    return result;
}

void glMatrixMode(int mode) {
    if (mode == GL_PROJECTION) gl_state_matrix_current = &gl_state_matrix_projection;
    else if (mode == GL_MODELVIEW) gl_state_matrix_current = &gl_state_matrix_modelview;
    //else if (mode == GL_TEXTURE) // Not supported

    gl_state_matrix_current_mode = mode;
}

void glPushMatrix() {
    if (gl_state_matrix_current_mode == GL_MODELVIEW) {
        gl_state_matrix_transform_required = 1;
        gl_state_matrix_current = &gl_state_matrix_transform;
    }

    gl_state_matrix_stack[gl_state_matrix_stack_counter] = *gl_state_matrix_current;
    gl_state_matrix_stack_counter++;
}


void glPopMatrix() {
    if (gl_state_matrix_stack_counter > 0) {
        GLMatrix mat = gl_state_matrix_stack[gl_state_matrix_stack_counter - 1];
        *gl_state_matrix_current = mat;
        gl_state_matrix_stack_counter--;
    }

    if ((gl_state_matrix_stack_counter == 0) && (gl_state_matrix_current_mode == GL_MODELVIEW)) {
        gl_state_matrix_current = &gl_state_matrix_modelview;
        gl_state_matrix_transform_required = 0;
    }
}

void glMultMatrixf(float *matf) {
    GLMatrix mat = { matf[0], matf[4], matf[8], matf[12],
                   matf[1], matf[5], matf[9], matf[13],
                   matf[2], matf[6], matf[10], matf[14],
                   matf[3], matf[7], matf[11], matf[15] };

    *gl_state_matrix_current = MatrixMultiply(*gl_state_matrix_current, mat);
}

void glLoadIdentity(void) {
    GLMatrix identity = { 1.0f, 0.0f, 0.0f, 0.0f,
                          0.0f, 1.0f, 0.0f, 0.0f,
                          0.0f, 0.0f, 1.0f, 0.0f,
                          0.0f, 0.0f, 0.0f, 1.0f };
    *gl_state_matrix_current = identity;
}

void glPointSize(GLfloat size) {
    // not implemented right now
}



static inline void gles_vertex_data(void) {
    if (!gles_normal_count) gles_normal_count = 3;
    while (gles_normal_count / 3 < gles_vertex_count / gles_vertex_dimensions) {
        gles_normals[gles_normal_count] = gles_normals[gles_normal_count - 3];
        gles_normal_count++;
        gles_normals[gles_normal_count] = gles_normals[gles_normal_count - 3];
        gles_normal_count++;
        gles_normals[gles_normal_count] = gles_normals[gles_normal_count - 3];
        gles_normal_count++;
    }
    if (!gles_color_count) gles_color_count = 4;
    while (gles_color_count / 4 < gles_vertex_count / gles_vertex_dimensions) {
        gles_colors[gles_color_count] = gles_colors[gles_color_count - 4];
        gles_color_count++;
        gles_colors[gles_color_count] = gles_colors[gles_color_count - 4];
        gles_color_count++;
        gles_colors[gles_color_count] = gles_colors[gles_color_count - 4];
        gles_color_count++;
        gles_colors[gles_color_count] = gles_colors[gles_color_count - 4];
        gles_color_count++;
    }
}


void glVertexPointer(unsigned char size, unsigned int type, unsigned int stride, GLfloat *pointer) {
    glBindBuffer(GL_ARRAY_BUFFER, buffer_object_vertex);
    glBufferSubData(GL_ARRAY_BUFFER, 0, 4 * gles_vertex_count, pointer);
    glVertexAttribPointer(0, size, type, 0, stride, 0);

    switch (size) {
        case 2:
            gl_state_p = 2;
            break;
        case 3:
            gl_state_p = 1;
            break;
        case 4:
            gl_state_p = 0;
            break;
    }

    glUseProgram(gl_state_programs[gl_state_p]);
}

void glNormalPointer(unsigned int type, unsigned int stride, GLfloat *pointer) {
    glBindBuffer(GL_ARRAY_BUFFER, buffer_object_normal);
    glBufferSubData(GL_ARRAY_BUFFER, 0, 4 * gles_normal_count, pointer);
    glVertexAttribPointer(1, 3, type, 0, stride, 0);

    glUseProgram(gl_state_programs[gl_state_p]);
}

void glColorPointer(unsigned char size, unsigned int type, unsigned int stride, GLfloat *pointer) {
    glBindBuffer(GL_ARRAY_BUFFER, buffer_object_color);
    glBufferSubData(GL_ARRAY_BUFFER, 0, 4 * gles_color_count, pointer);
    glVertexAttribPointer(2, size, type, 0, stride, 0);

    glUseProgram(gl_state_programs[gl_state_p]);
}

void glTexCoordPointer(unsigned char size, unsigned int type, unsigned int stride, GLfloat *pointer) {
    glBindBuffer(GL_ARRAY_BUFFER, buffer_object_texcoord);
    glBufferSubData(GL_ARRAY_BUFFER, 0, 4 * gles_texcoord_count, pointer);
    glVertexAttribPointer(3, size, type, 0, stride, 0);

    glUseProgram(gl_state_programs[gl_state_p]);
}

void glShadeModel(GLenum mode) {
    // needs to be emulated in shader!
}


void glEnableClientState(GLenum cap) {
    GLuint index;

    switch (cap) {
        case GL_VERTEX_ARRAY:
            index = 0;
            break;
        case GL_NORMAL_ARRAY:
            index = 1;
            break;
        case GL_COLOR_ARRAY:
            index = 2;
            break;
        case GL_TEXTURE_COORD_ARRAY:
            index = 3;
            break;
        default:
            index = -1;
    }

    glEnableVertexAttribArray(index);
}

void glDisableClientState(GLenum cap) {
    GLuint index;

    switch (cap) {
        case GL_VERTEX_ARRAY:
            index = 0;
            break;
        case GL_NORMAL_ARRAY:
            index = 1;
            break;
        case GL_COLOR_ARRAY:
            index = 2;
            break;
        case GL_TEXTURE_COORD_ARRAY:
            index = 3;
            break;
        default:
            index = -1;
    }

    glDisableVertexAttribArray(index);
}

void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    int i;
    for (i = 0; i < 3; i++) {
        glUseProgram(gl_state_programs[i]);
        GLint id = glGetUniformLocation(gl_state_programs[i], "const_color");
        glUniform4f(id, red, green, blue, alpha);
    }

    glUseProgram(gl_state_programs[gl_state_p]);
}


void glNormal3f(GLfloat x, GLfloat y, GLfloat z) {
    int i;
    for (i = 0; i < 3; i++) {
        glUseProgram(gl_state_programs[i]);
        GLint id = glGetUniformLocation(gl_state_programs[i], "const_normal");
        glUniform3f(id, x, y, z);
    }

    glUseProgram(gl_state_programs[gl_state_p]);
}


static inline void gles_render_current(void) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(gles_vertex_dimensions, GL_FLOAT, 0, gles_vertex);
    if (gles_texcoord_count && gles_mode >= GL_TRIANGLES) {
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(2, GL_FLOAT, 0, gles_texcoord);
    }
    if (gles_color_count) {
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(4, GL_FLOAT, 0, gles_colors);
    }
    if (gles_normal_count && gles_mode >= GL_TRIANGLES) {
        glEnableClientState(GL_NORMAL_ARRAY);
        glNormalPointer(GL_FLOAT, 0, gles_normals);
    }
    switch (gles_mode) {
        case GL_POINTS:
        case GL_LINES:
        case GL_LINE_LOOP:
        case GL_LINE_STRIP:
        case GL_TRIANGLES:
        case GL_TRIANGLE_STRIP:
        case GL_TRIANGLE_FAN:
            glDrawArrays(gles_mode, 0, gles_vertex_count / gles_vertex_dimensions);
            break;
        case GL_QUADS:
            glDrawElements(GL_TRIANGLE_STRIP, gles_vertex_count / gles_vertex_dimensions, GL_UNSIGNED_SHORT, gles_quad_indices);
            break;
        case GL_POLYGON: {
            unsigned int i;
            GLfloat center_x = 0.0f, center_y = 0.0f;
            gles_vertex[gles_vertex_count++] = gles_vertex[0];
            gles_vertex[gles_vertex_count++] = gles_vertex[1];
            GLushort poly_indices[(gles_vertex_count / gles_vertex_dimensions) + 1];
            poly_indices[0] = gles_vertex_count / gles_vertex_dimensions;
            for (i = 0; i < gles_vertex_count / gles_vertex_dimensions; i++) {
                poly_indices[i + 1] = i;
                center_x += gles_vertex[i * 2] / (gles_vertex_count / gles_vertex_dimensions);
                center_y += gles_vertex[(i * 2) + 1] / (gles_vertex_count / gles_vertex_dimensions);
            }
            gles_vertex[gles_vertex_count++] = center_x;
            gles_vertex[gles_vertex_count++] = center_y;
            gles_vertex_data();
            glDrawElements(GL_TRIANGLE_FAN, gles_vertex_count / gles_vertex_dimensions, GL_UNSIGNED_SHORT, poly_indices);
            break;
        }
        default:
            printf("gles_render_current: unsupported mode: 0x%x\n", gles_mode);
            break;
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    gles_vertex_count = 0;
    gles_texcoord_count = 0;
    if (gles_color_count) {
        gles_colors[0] = gles_colors[gles_color_count - 4];
        gles_colors[1] = gles_colors[gles_color_count - 3];
        gles_colors[2] = gles_colors[gles_color_count - 2];
        gles_colors[3] = gles_colors[gles_color_count - 1];
    }
    gles_color_count = 0;
    if (gles_normal_count) {
        gles_normals[0] = gles_normals[gles_normal_count - 3];
        gles_normals[1] = gles_normals[gles_normal_count - 2];
        gles_normals[2] = gles_normals[gles_normal_count - 1];
    }
    gles_normal_count = 0;
}

static inline void glBegin(GLenum mode) {
    gles_immediate = 1;
    gles_mode = mode;
}

static inline void glEnd(void) {
    if (gles_vertex_count) gles_render_current();
    gles_immediate = 0;
}

static inline void glesColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    if (gles_immediate) {
        if (gles_color_count / 4 <= gles_vertex_count / gles_vertex_dimensions) {
            gles_colors[gles_color_count++] = red;
            gles_colors[gles_color_count++] = green;
            gles_colors[gles_color_count++] = blue;
            gles_colors[gles_color_count++] = alpha;
        } else {
            gles_colors[gles_color_count - 4] = red;
            gles_colors[gles_color_count - 3] = green;
            gles_colors[gles_color_count - 2] = blue;
            gles_colors[gles_color_count - 1] = alpha;
        }
    } else {
        gles_colors[0] = red;
        gles_colors[1] = green;
        gles_colors[2] = blue;
        gles_colors[3] = alpha;
        glColor4f(red, green, blue, alpha);
    }
}

static inline void glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    glesColor4f(red, green, blue, 1.0f);
}

static inline void glesColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    glesColor4f((GLfloat)red / 255.0f, (GLfloat)green / 255.0f, (GLfloat)blue / 255.0f, (GLfloat)alpha / 255.0f);
}

static inline void glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    glesColor4ub(red, green, blue, 255);
}

static inline void glesNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    if (gles_immediate) {
        if (gles_normal_count / 3 <= gles_vertex_count / gles_vertex_dimensions) {
            gles_normals[gles_normal_count++] = nx;
            gles_normals[gles_normal_count++] = ny;
            gles_normals[gles_normal_count++] = nz;
        } else {
            gles_normals[gles_normal_count - 3] = nx;
            gles_normals[gles_normal_count - 2] = ny;
            gles_normals[gles_normal_count - 1] = nz;
        }
    } else {
        gles_normals[0] = nx;
        gles_normals[1] = ny;
        gles_normals[2] = nz;
        glNormal3f(nx, ny, nz);
    }
}

static inline void glNormal3fv(const GLfloat *v) {
    glesNormal3f(v[0], v[1], v[2]);
}

static inline void glTexCoord2f(GLfloat s, GLfloat t) {
    gles_texcoord[gles_texcoord_count++] = s;
    gles_texcoord[gles_texcoord_count++] = t;
}

static inline void glVertex2f(GLfloat x, GLfloat y) {
    if (gles_mode == GL_QUADS && gles_vertex_dimensions && gles_vertex_count / gles_vertex_dimensions == 4) gles_render_current();
    gles_vertex_dimensions = 2;
    gles_vertex[gles_vertex_count++] = x;
    gles_vertex[gles_vertex_count++] = y;
    gles_vertex_data();
}

static inline void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    if (gles_mode == GL_QUADS && gles_vertex_dimensions && gles_vertex_count / gles_vertex_dimensions == 4) gles_render_current();
    gles_vertex_dimensions = 3;
    gles_vertex[gles_vertex_count++] = x;
    gles_vertex[gles_vertex_count++] = y;
    gles_vertex[gles_vertex_count++] = z;
    gles_vertex_data();
}

static inline void glVertex3fv(const GLfloat *v) {
    glVertex3f(v[0], v[1], v[2]);
}

#define glColor4ub(R, G, B, A) glesColor4ub(R, G, B, A)
#define glColor4f(R, G, B, A) glesColor4f(R, G, B, A)
#define glNormal3f(X, Y, Z) glesNormal3f(X, Y, Z)

#else


#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

/*
extern PFNGLBINDBUFFERPROC glBindBuffer;
extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;
extern PFNGLGENBUFFERSPROC glGenBuffers;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLBUFFERSUBDATAPROC glBufferSubData;


typedef void (APIENTRYP PFNGLDRAWTEXIOESPROC) (GLint x, GLint y, GLint z, GLint width, GLint height);
*/

#endif

//extern PFNGLDRAWTEXIOESPROC glDrawTexiOES;

#ifndef GL_TEXTURE_CROP_RECT_OES
#define GL_TEXTURE_CROP_RECT_OES 0x8B9D
#endif

int glCheckExtension(const char *ext);

#endif
