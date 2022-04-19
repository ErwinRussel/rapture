//#include <GL/gl.h>
//#include <GL/glx.h>
#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

// -- OpenGL Hook Functions --
// -- glClearIndex            
void glClearIndex( GLfloat c )
{
    printf("gl stub called: glClearIndex");
}

// -- glClearColor            
void glClearColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha )
{
    printf("gl stub called: glClearColor");
}

// -- glClear            
void glClear( GLbitfield mask )
{
    printf("gl stub called: glClear");
}

// -- glIndexMask            
void glIndexMask( GLuint mask )
{
    printf("gl stub called: glIndexMask");
}

// -- glColorMask            
void glColorMask( GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha )
{
    printf("gl stub called: glColorMask");
}

// -- glAlphaFunc            
void glAlphaFunc( GLenum func, GLclampf ref )
{
    printf("gl stub called: glAlphaFunc");
}

// -- glBlendFunc            
void glBlendFunc( GLenum sfactor, GLenum dfactor )
{
    printf("gl stub called: glBlendFunc");
}

// -- glLogicOp            
void glLogicOp( GLenum opcode )
{
    printf("gl stub called: glLogicOp");
}

// -- glCullFace            
void glCullFace( GLenum mode )
{
    printf("gl stub called: glCullFace");
}

// -- glFrontFace            
void glFrontFace( GLenum mode )
{
    printf("gl stub called: glFrontFace");
}

// -- glPointSize            
void glPointSize( GLfloat size )
{
    printf("gl stub called: glPointSize");
}

// -- glLineWidth            
void glLineWidth( GLfloat width )
{
    printf("gl stub called: glLineWidth");
}

// -- glLineStipple            
void glLineStipple( GLint factor, GLushort pattern )
{
    printf("gl stub called: glLineStipple");
}

// -- glPolygonMode            
void glPolygonMode( GLenum face, GLenum mode )
{
    printf("gl stub called: glPolygonMode");
}

// -- glPolygonOffset            
void glPolygonOffset( GLfloat factor, GLfloat units )
{
    printf("gl stub called: glPolygonOffset");
}

// -- glPolygonStipple            
void glPolygonStipple( const GLubyte *mask )
{
    printf("gl stub called: glPolygonStipple");
}

// -- glGetPolygonStipple            
void glGetPolygonStipple( GLubyte *mask )
{
    printf("gl stub called: glGetPolygonStipple");
}

// -- glEdgeFlag            
void glEdgeFlag( GLboolean flag )
{
    printf("gl stub called: glEdgeFlag");
}

// -- glEdgeFlagv            
void glEdgeFlagv( const GLboolean *flag )
{
    printf("gl stub called: glEdgeFlagv");
}

// -- glScissor            
void glScissor( GLint x, GLint y, GLsizei width, GLsizei height)
{
    printf("gl stub called: glScissor");
}

// -- glClipPlane            
void glClipPlane( GLenum plane, const GLdouble *equation )
{
    printf("gl stub called: glClipPlane");
}

// -- glGetClipPlane            
void glGetClipPlane( GLenum plane, GLdouble *equation )
{
    printf("gl stub called: glGetClipPlane");
}

// -- glDrawBuffer            
void glDrawBuffer( GLenum mode )
{
    printf("gl stub called: glDrawBuffer");
}

// -- glReadBuffer            
void glReadBuffer( GLenum mode )
{
    printf("gl stub called: glReadBuffer");
}

// -- glEnable            
void glEnable( GLenum cap )
{
    printf("gl stub called: glEnable");
}

// -- glDisable            
void glDisable( GLenum cap )
{
    printf("gl stub called: glDisable");
}

// -- glIsEnabled        
GLboolean glIsEnabled( GLenum cap )
{
    printf("Glx stub called: glIsEnabled");
}

// -- glEnableClientState            
void glEnableClientState( GLenum cap )
{
    printf("gl stub called: glEnableClientState");
}

// -- glDisableClientState            
void glDisableClientState( GLenum cap )
{
    printf("gl stub called: glDisableClientState");
}

// -- glGetBooleanv            
void glGetBooleanv( GLenum pname, GLboolean *params )
{
    printf("gl stub called: glGetBooleanv");
}

// -- glGetDoublev            
void glGetDoublev( GLenum pname, GLdouble *params )
{
    printf("gl stub called: glGetDoublev");
}

// -- glGetFloatv            
void glGetFloatv( GLenum pname, GLfloat *params )
{
    printf("gl stub called: glGetFloatv");
}

// -- glGetIntegerv            
void glGetIntegerv( GLenum pname, GLint *params )
{
    printf("gl stub called: glGetIntegerv");
}

// -- glPushAttrib            
void glPushAttrib( GLbitfield mask )
{
    printf("gl stub called: glPushAttrib");
}

// -- glPopAttrib            
void glPopAttrib()
{
    printf("gl stub called: glPopAttrib");
}

// -- glPushClientAttrib            
void glPushClientAttrib( GLbitfield mask )
{
    printf("gl stub called: glPushClientAttrib");
}

// -- glPopClientAttrib            
void glPopClientAttrib()
{
    printf("gl stub called: glPopClientAttrib");
}

// -- glRenderMode        
GLint glRenderMode( GLenum mode )
{
    printf("Glx stub called: glRenderMode");
}

// -- glGetError        
GLdisplayenum glGetError()
{
    printf("Glx stub called: glGetError");
}

// -- * GLAPIENTRY glGetString        
const * GLAPIENTRY glGetString( GLenum name )
{
    printf("Glx stub called: * GLAPIENTRY glGetString");
}

// -- glFinish            
void glFinish()
{
    printf("gl stub called: glFinish");
}

// -- glFlush            
void glFlush()
{
    printf("gl stub called: glFlush");
}

// -- glHint            
void glHint( GLenum target, GLenum mode )
{
    printf("gl stub called: glHint");
}

// -- glClearDepth            
void glClearDepth( GLclampd depth )
{
    printf("gl stub called: glClearDepth");
}

// -- glDepthFunc            
void glDepthFunc( GLenum func )
{
    printf("gl stub called: glDepthFunc");
}

// -- glDepthMask            
void glDepthMask( GLboolean flag )
{
    printf("gl stub called: glDepthMask");
}

// -- glDepthRange            
void glDepthRange( GLclampd near_val, GLclampd far_val )
{
    printf("gl stub called: glDepthRange");
}

// -- glClearAccum            
void glClearAccum( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha )
{
    printf("gl stub called: glClearAccum");
}

// -- glAccum            
void glAccum( GLenum op, GLfloat value )
{
    printf("gl stub called: glAccum");
}

// -- glMatrixMode            
void glMatrixMode( GLenum mode )
{
    printf("gl stub called: glMatrixMode");
}

// -- glOrtho            
void glOrtho( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val )
{
    printf("gl stub called: glOrtho");
}

// -- glFrustum            
void glFrustum( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val )
{
    printf("gl stub called: glFrustum");
}

// -- glViewport            
void glViewport( GLint x, GLint y, GLsizei width, GLsizei height )
{
    printf("gl stub called: glViewport");
}

// -- glPushMatrix            
void glPushMatrix()
{
    printf("gl stub called: glPushMatrix");
}

// -- glPopMatrix            
void glPopMatrix()
{
    printf("gl stub called: glPopMatrix");
}

// -- glLoadIdentity            
void glLoadIdentity()
{
    printf("gl stub called: glLoadIdentity");
}

// -- glLoadMatrixd            
void glLoadMatrixd( const GLdouble *m )
{
    printf("gl stub called: glLoadMatrixd");
}

// -- glLoadMatrixf            
void glLoadMatrixf( const GLfloat *m )
{
    printf("gl stub called: glLoadMatrixf");
}

// -- glMultMatrixd            
void glMultMatrixd( const GLdouble *m )
{
    printf("gl stub called: glMultMatrixd");
}

// -- glMultMatrixf            
void glMultMatrixf( const GLfloat *m )
{
    printf("gl stub called: glMultMatrixf");
}

// -- glRotated            
void glRotated( GLdouble angle, GLdouble x, GLdouble y, GLdouble z )
{
    printf("gl stub called: glRotated");
}

// -- glRotatef            
void glRotatef( GLfloat angle, GLfloat x, GLfloat y, GLfloat z )
{
    printf("gl stub called: glRotatef");
}

// -- glScaled            
void glScaled( GLdouble x, GLdouble y, GLdouble z )
{
    printf("gl stub called: glScaled");
}

// -- glScalef            
void glScalef( GLfloat x, GLfloat y, GLfloat z )
{
    printf("gl stub called: glScalef");
}

// -- glTranslated            
void glTranslated( GLdouble x, GLdouble y, GLdouble z )
{
    printf("gl stub called: glTranslated");
}

// -- glTranslatef            
void glTranslatef( GLfloat x, GLfloat y, GLfloat z )
{
    printf("gl stub called: glTranslatef");
}

// -- glIsList        
GLboolean glIsList( GLuint list )
{
    printf("Glx stub called: glIsList");
}

// -- glDeleteLists            
void glDeleteLists( GLuint list, GLsizei range )
{
    printf("gl stub called: glDeleteLists");
}

// -- glGenLists        
GLuint glGenLists( GLsizei range )
{
    printf("Glx stub called: glGenLists");
}

// -- glNewList            
void glNewList( GLuint list, GLenum mode )
{
    printf("gl stub called: glNewList");
}

// -- glEndList            
void glEndList()
{
    printf("gl stub called: glEndList");
}

// -- glCallList            
void glCallList( GLuint list )
{
    printf("gl stub called: glCallList");
}

// -- glCallLists            
void glCallLists( GLsizei n, GLenum type, const GLvoid *lists )
{
    printf("gl stub called: glCallLists");
}

// -- glListBase            
void glListBase( GLuint base )
{
    printf("gl stub called: glListBase");
}

// -- glBegin            
void glBegin( GLenum mode )
{
    printf("gl stub called: glBegin");
}

// -- glEnd            
void glEnd()
{
    printf("gl stub called: glEnd");
}

// -- glVertex2d            
void glVertex2d( GLdouble x, GLdouble y )
{
    printf("gl stub called: glVertex2d");
}

// -- glVertex2f            
void glVertex2f( GLfloat x, GLfloat y )
{
    printf("gl stub called: glVertex2f");
}

// -- glVertex2i            
void glVertex2i( GLint x, GLint y )
{
    printf("gl stub called: glVertex2i");
}

// -- glVertex2s            
void glVertex2s( GLshort x, GLshort y )
{
    printf("gl stub called: glVertex2s");
}

// -- glVertex3d            
void glVertex3d( GLdouble x, GLdouble y, GLdouble z )
{
    printf("gl stub called: glVertex3d");
}

// -- glVertex3f            
void glVertex3f( GLfloat x, GLfloat y, GLfloat z )
{
    printf("gl stub called: glVertex3f");
}

// -- glVertex3i            
void glVertex3i( GLint x, GLint y, GLint z )
{
    printf("gl stub called: glVertex3i");
}

// -- glVertex3s            
void glVertex3s( GLshort x, GLshort y, GLshort z )
{
    printf("gl stub called: glVertex3s");
}

// -- glVertex4d            
void glVertex4d( GLdouble x, GLdouble y, GLdouble z, GLdouble w )
{
    printf("gl stub called: glVertex4d");
}

// -- glVertex4f            
void glVertex4f( GLfloat x, GLfloat y, GLfloat z, GLfloat w )
{
    printf("gl stub called: glVertex4f");
}

// -- glVertex4i            
void glVertex4i( GLint x, GLint y, GLint z, GLint w )
{
    printf("gl stub called: glVertex4i");
}

// -- glVertex4s            
void glVertex4s( GLshort x, GLshort y, GLshort z, GLshort w )
{
    printf("gl stub called: glVertex4s");
}

// -- glVertex2dv            
void glVertex2dv( const GLdouble *v )
{
    printf("gl stub called: glVertex2dv");
}

// -- glVertex2fv            
void glVertex2fv( const GLfloat *v )
{
    printf("gl stub called: glVertex2fv");
}

// -- glVertex2iv            
void glVertex2iv( const GLint *v )
{
    printf("gl stub called: glVertex2iv");
}

// -- glVertex2sv            
void glVertex2sv( const GLshort *v )
{
    printf("gl stub called: glVertex2sv");
}

// -- glVertex3dv            
void glVertex3dv( const GLdouble *v )
{
    printf("gl stub called: glVertex3dv");
}

// -- glVertex3fv            
void glVertex3fv( const GLfloat *v )
{
    printf("gl stub called: glVertex3fv");
}

// -- glVertex3iv            
void glVertex3iv( const GLint *v )
{
    printf("gl stub called: glVertex3iv");
}

// -- glVertex3sv            
void glVertex3sv( const GLshort *v )
{
    printf("gl stub called: glVertex3sv");
}

// -- glVertex4dv            
void glVertex4dv( const GLdouble *v )
{
    printf("gl stub called: glVertex4dv");
}

// -- glVertex4fv            
void glVertex4fv( const GLfloat *v )
{
    printf("gl stub called: glVertex4fv");
}

// -- glVertex4iv            
void glVertex4iv( const GLint *v )
{
    printf("gl stub called: glVertex4iv");
}

// -- glVertex4sv            
void glVertex4sv( const GLshort *v )
{
    printf("gl stub called: glVertex4sv");
}

// -- glNormal3b            
void glNormal3b( GLbyte nx, GLbyte ny, GLbyte nz )
{
    printf("gl stub called: glNormal3b");
}

// -- glNormal3d            
void glNormal3d( GLdouble nx, GLdouble ny, GLdouble nz )
{
    printf("gl stub called: glNormal3d");
}

// -- glNormal3f            
void glNormal3f( GLfloat nx, GLfloat ny, GLfloat nz )
{
    printf("gl stub called: glNormal3f");
}

// -- glNormal3i            
void glNormal3i( GLint nx, GLint ny, GLint nz )
{
    printf("gl stub called: glNormal3i");
}

// -- glNormal3s            
void glNormal3s( GLshort nx, GLshort ny, GLshort nz )
{
    printf("gl stub called: glNormal3s");
}

// -- glNormal3bv            
void glNormal3bv( const GLbyte *v )
{
    printf("gl stub called: glNormal3bv");
}

// -- glNormal3dv            
void glNormal3dv( const GLdouble *v )
{
    printf("gl stub called: glNormal3dv");
}

// -- glNormal3fv            
void glNormal3fv( const GLfloat *v )
{
    printf("gl stub called: glNormal3fv");
}

// -- glNormal3iv            
void glNormal3iv( const GLint *v )
{
    printf("gl stub called: glNormal3iv");
}

// -- glNormal3sv            
void glNormal3sv( const GLshort *v )
{
    printf("gl stub called: glNormal3sv");
}

// -- glIndexd            
void glIndexd( GLdouble c )
{
    printf("gl stub called: glIndexd");
}

// -- glIndexf            
void glIndexf( GLfloat c )
{
    printf("gl stub called: glIndexf");
}

// -- glIndexi            
void glIndexi( GLint c )
{
    printf("gl stub called: glIndexi");
}

// -- glIndexs            
void glIndexs( GLshort c )
{
    printf("gl stub called: glIndexs");
}

// -- glIndexub            
void glIndexub( GLubyte c )
{
    printf("gl stub called: glIndexub");
}

// -- glIndexdv            
void glIndexdv( const GLdouble *c )
{
    printf("gl stub called: glIndexdv");
}

// -- glIndexfv            
void glIndexfv( const GLfloat *c )
{
    printf("gl stub called: glIndexfv");
}

// -- glIndexiv            
void glIndexiv( const GLint *c )
{
    printf("gl stub called: glIndexiv");
}

// -- glIndexsv            
void glIndexsv( const GLshort *c )
{
    printf("gl stub called: glIndexsv");
}

// -- glIndexubv            
void glIndexubv( const GLubyte *c )
{
    printf("gl stub called: glIndexubv");
}

// -- glColor3b            
void glColor3b( GLbyte red, GLbyte green, GLbyte blue )
{
    printf("gl stub called: glColor3b");
}

// -- glColor3d            
void glColor3d( GLdouble red, GLdouble green, GLdouble blue )
{
    printf("gl stub called: glColor3d");
}

// -- glColor3f            
void glColor3f( GLfloat red, GLfloat green, GLfloat blue )
{
    printf("gl stub called: glColor3f");
}

// -- glColor3i            
void glColor3i( GLint red, GLint green, GLint blue )
{
    printf("gl stub called: glColor3i");
}

// -- glColor3s            
void glColor3s( GLshort red, GLshort green, GLshort blue )
{
    printf("gl stub called: glColor3s");
}

// -- glColor3ub            
void glColor3ub( GLubyte red, GLubyte green, GLubyte blue )
{
    printf("gl stub called: glColor3ub");
}

// -- glColor3ui            
void glColor3ui( GLuint red, GLuint green, GLuint blue )
{
    printf("gl stub called: glColor3ui");
}

// -- glColor3us            
void glColor3us( GLushort red, GLushort green, GLushort blue )
{
    printf("gl stub called: glColor3us");
}

// -- glColor4b            
void glColor4b( GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha )
{
    printf("gl stub called: glColor4b");
}

// -- glColor4d            
void glColor4d( GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha )
{
    printf("gl stub called: glColor4d");
}

// -- glColor4f            
void glColor4f( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha )
{
    printf("gl stub called: glColor4f");
}

// -- glColor4i            
void glColor4i( GLint red, GLint green, GLint blue, GLint alpha )
{
    printf("gl stub called: glColor4i");
}

// -- glColor4s            
void glColor4s( GLshort red, GLshort green, GLshort blue, GLshort alpha )
{
    printf("gl stub called: glColor4s");
}

// -- glColor4ub            
void glColor4ub( GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha )
{
    printf("gl stub called: glColor4ub");
}

// -- glColor4ui            
void glColor4ui( GLuint red, GLuint green, GLuint blue, GLuint alpha )
{
    printf("gl stub called: glColor4ui");
}

// -- glColor4us            
void glColor4us( GLushort red, GLushort green, GLushort blue, GLushort alpha )
{
    printf("gl stub called: glColor4us");
}

// -- glColor3bv            
void glColor3bv( const GLbyte *v )
{
    printf("gl stub called: glColor3bv");
}

// -- glColor3dv            
void glColor3dv( const GLdouble *v )
{
    printf("gl stub called: glColor3dv");
}

// -- glColor3fv            
void glColor3fv( const GLfloat *v )
{
    printf("gl stub called: glColor3fv");
}

// -- glColor3iv            
void glColor3iv( const GLint *v )
{
    printf("gl stub called: glColor3iv");
}

// -- glColor3sv            
void glColor3sv( const GLshort *v )
{
    printf("gl stub called: glColor3sv");
}

// -- glColor3ubv            
void glColor3ubv( const GLubyte *v )
{
    printf("gl stub called: glColor3ubv");
}

// -- glColor3uiv            
void glColor3uiv( const GLuint *v )
{
    printf("gl stub called: glColor3uiv");
}

// -- glColor3usv            
void glColor3usv( const GLushort *v )
{
    printf("gl stub called: glColor3usv");
}

// -- glColor4bv            
void glColor4bv( const GLbyte *v )
{
    printf("gl stub called: glColor4bv");
}

// -- glColor4dv            
void glColor4dv( const GLdouble *v )
{
    printf("gl stub called: glColor4dv");
}

// -- glColor4fv            
void glColor4fv( const GLfloat *v )
{
    printf("gl stub called: glColor4fv");
}

// -- glColor4iv            
void glColor4iv( const GLint *v )
{
    printf("gl stub called: glColor4iv");
}

// -- glColor4sv            
void glColor4sv( const GLshort *v )
{
    printf("gl stub called: glColor4sv");
}

// -- glColor4ubv            
void glColor4ubv( const GLubyte *v )
{
    printf("gl stub called: glColor4ubv");
}

// -- glColor4uiv            
void glColor4uiv( const GLuint *v )
{
    printf("gl stub called: glColor4uiv");
}

// -- glColor4usv            
void glColor4usv( const GLushort *v )
{
    printf("gl stub called: glColor4usv");
}

// -- glTexCoord1d            
void glTexCoord1d( GLdouble s )
{
    printf("gl stub called: glTexCoord1d");
}

// -- glTexCoord1f            
void glTexCoord1f( GLfloat s )
{
    printf("gl stub called: glTexCoord1f");
}

// -- glTexCoord1i            
void glTexCoord1i( GLint s )
{
    printf("gl stub called: glTexCoord1i");
}

// -- glTexCoord1s            
void glTexCoord1s( GLshort s )
{
    printf("gl stub called: glTexCoord1s");
}

// -- glTexCoord2d            
void glTexCoord2d( GLdouble s, GLdouble t )
{
    printf("gl stub called: glTexCoord2d");
}

// -- glTexCoord2f            
void glTexCoord2f( GLfloat s, GLfloat t )
{
    printf("gl stub called: glTexCoord2f");
}

// -- glTexCoord2i            
void glTexCoord2i( GLint s, GLint t )
{
    printf("gl stub called: glTexCoord2i");
}

// -- glTexCoord2s            
void glTexCoord2s( GLshort s, GLshort t )
{
    printf("gl stub called: glTexCoord2s");
}

// -- glTexCoord3d            
void glTexCoord3d( GLdouble s, GLdouble t, GLdouble r )
{
    printf("gl stub called: glTexCoord3d");
}

// -- glTexCoord3f            
void glTexCoord3f( GLfloat s, GLfloat t, GLfloat r )
{
    printf("gl stub called: glTexCoord3f");
}

// -- glTexCoord3i            
void glTexCoord3i( GLint s, GLint t, GLint r )
{
    printf("gl stub called: glTexCoord3i");
}

// -- glTexCoord3s            
void glTexCoord3s( GLshort s, GLshort t, GLshort r )
{
    printf("gl stub called: glTexCoord3s");
}

// -- glTexCoord4d            
void glTexCoord4d( GLdouble s, GLdouble t, GLdouble r, GLdouble q )
{
    printf("gl stub called: glTexCoord4d");
}

// -- glTexCoord4f            
void glTexCoord4f( GLfloat s, GLfloat t, GLfloat r, GLfloat q )
{
    printf("gl stub called: glTexCoord4f");
}

// -- glTexCoord4i            
void glTexCoord4i( GLint s, GLint t, GLint r, GLint q )
{
    printf("gl stub called: glTexCoord4i");
}

// -- glTexCoord4s            
void glTexCoord4s( GLshort s, GLshort t, GLshort r, GLshort q )
{
    printf("gl stub called: glTexCoord4s");
}

// -- glTexCoord1dv            
void glTexCoord1dv( const GLdouble *v )
{
    printf("gl stub called: glTexCoord1dv");
}

// -- glTexCoord1fv            
void glTexCoord1fv( const GLfloat *v )
{
    printf("gl stub called: glTexCoord1fv");
}

// -- glTexCoord1iv            
void glTexCoord1iv( const GLint *v )
{
    printf("gl stub called: glTexCoord1iv");
}

// -- glTexCoord1sv            
void glTexCoord1sv( const GLshort *v )
{
    printf("gl stub called: glTexCoord1sv");
}

// -- glTexCoord2dv            
void glTexCoord2dv( const GLdouble *v )
{
    printf("gl stub called: glTexCoord2dv");
}

// -- glTexCoord2fv            
void glTexCoord2fv( const GLfloat *v )
{
    printf("gl stub called: glTexCoord2fv");
}

// -- glTexCoord2iv            
void glTexCoord2iv( const GLint *v )
{
    printf("gl stub called: glTexCoord2iv");
}

// -- glTexCoord2sv            
void glTexCoord2sv( const GLshort *v )
{
    printf("gl stub called: glTexCoord2sv");
}

// -- glTexCoord3dv            
void glTexCoord3dv( const GLdouble *v )
{
    printf("gl stub called: glTexCoord3dv");
}

// -- glTexCoord3fv            
void glTexCoord3fv( const GLfloat *v )
{
    printf("gl stub called: glTexCoord3fv");
}

// -- glTexCoord3iv            
void glTexCoord3iv( const GLint *v )
{
    printf("gl stub called: glTexCoord3iv");
}

// -- glTexCoord3sv            
void glTexCoord3sv( const GLshort *v )
{
    printf("gl stub called: glTexCoord3sv");
}

// -- glTexCoord4dv            
void glTexCoord4dv( const GLdouble *v )
{
    printf("gl stub called: glTexCoord4dv");
}

// -- glTexCoord4fv            
void glTexCoord4fv( const GLfloat *v )
{
    printf("gl stub called: glTexCoord4fv");
}

// -- glTexCoord4iv            
void glTexCoord4iv( const GLint *v )
{
    printf("gl stub called: glTexCoord4iv");
}

// -- glTexCoord4sv            
void glTexCoord4sv( const GLshort *v )
{
    printf("gl stub called: glTexCoord4sv");
}

// -- glRasterPos2d            
void glRasterPos2d( GLdouble x, GLdouble y )
{
    printf("gl stub called: glRasterPos2d");
}

// -- glRasterPos2f            
void glRasterPos2f( GLfloat x, GLfloat y )
{
    printf("gl stub called: glRasterPos2f");
}

// -- glRasterPos2i            
void glRasterPos2i( GLint x, GLint y )
{
    printf("gl stub called: glRasterPos2i");
}

// -- glRasterPos2s            
void glRasterPos2s( GLshort x, GLshort y )
{
    printf("gl stub called: glRasterPos2s");
}

// -- glRasterPos3d            
void glRasterPos3d( GLdouble x, GLdouble y, GLdouble z )
{
    printf("gl stub called: glRasterPos3d");
}

// -- glRasterPos3f            
void glRasterPos3f( GLfloat x, GLfloat y, GLfloat z )
{
    printf("gl stub called: glRasterPos3f");
}

// -- glRasterPos3i            
void glRasterPos3i( GLint x, GLint y, GLint z )
{
    printf("gl stub called: glRasterPos3i");
}

// -- glRasterPos3s            
void glRasterPos3s( GLshort x, GLshort y, GLshort z )
{
    printf("gl stub called: glRasterPos3s");
}

// -- glRasterPos4d            
void glRasterPos4d( GLdouble x, GLdouble y, GLdouble z, GLdouble w )
{
    printf("gl stub called: glRasterPos4d");
}

// -- glRasterPos4f            
void glRasterPos4f( GLfloat x, GLfloat y, GLfloat z, GLfloat w )
{
    printf("gl stub called: glRasterPos4f");
}

// -- glRasterPos4i            
void glRasterPos4i( GLint x, GLint y, GLint z, GLint w )
{
    printf("gl stub called: glRasterPos4i");
}

// -- glRasterPos4s            
void glRasterPos4s( GLshort x, GLshort y, GLshort z, GLshort w )
{
    printf("gl stub called: glRasterPos4s");
}

// -- glRasterPos2dv            
void glRasterPos2dv( const GLdouble *v )
{
    printf("gl stub called: glRasterPos2dv");
}

// -- glRasterPos2fv            
void glRasterPos2fv( const GLfloat *v )
{
    printf("gl stub called: glRasterPos2fv");
}

// -- glRasterPos2iv            
void glRasterPos2iv( const GLint *v )
{
    printf("gl stub called: glRasterPos2iv");
}

// -- glRasterPos2sv            
void glRasterPos2sv( const GLshort *v )
{
    printf("gl stub called: glRasterPos2sv");
}

// -- glRasterPos3dv            
void glRasterPos3dv( const GLdouble *v )
{
    printf("gl stub called: glRasterPos3dv");
}

// -- glRasterPos3fv            
void glRasterPos3fv( const GLfloat *v )
{
    printf("gl stub called: glRasterPos3fv");
}

// -- glRasterPos3iv            
void glRasterPos3iv( const GLint *v )
{
    printf("gl stub called: glRasterPos3iv");
}

// -- glRasterPos3sv            
void glRasterPos3sv( const GLshort *v )
{
    printf("gl stub called: glRasterPos3sv");
}

// -- glRasterPos4dv            
void glRasterPos4dv( const GLdouble *v )
{
    printf("gl stub called: glRasterPos4dv");
}

// -- glRasterPos4fv            
void glRasterPos4fv( const GLfloat *v )
{
    printf("gl stub called: glRasterPos4fv");
}

// -- glRasterPos4iv            
void glRasterPos4iv( const GLint *v )
{
    printf("gl stub called: glRasterPos4iv");
}

// -- glRasterPos4sv            
void glRasterPos4sv( const GLshort *v )
{
    printf("gl stub called: glRasterPos4sv");
}

// -- glRectd            
void glRectd( GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2 )
{
    printf("gl stub called: glRectd");
}

// -- glRectf            
void glRectf( GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2 )
{
    printf("gl stub called: glRectf");
}

// -- glRecti            
void glRecti( GLint x1, GLint y1, GLint x2, GLint y2 )
{
    printf("gl stub called: glRecti");
}

// -- glRects            
void glRects( GLshort x1, GLshort y1, GLshort x2, GLshort y2 )
{
    printf("gl stub called: glRects");
}

// -- glRectdv            
void glRectdv( const GLdouble *v1, const GLdouble *v2 )
{
    printf("gl stub called: glRectdv");
}

// -- glRectfv            
void glRectfv( const GLfloat *v1, const GLfloat *v2 )
{
    printf("gl stub called: glRectfv");
}

// -- glRectiv            
void glRectiv( const GLint *v1, const GLint *v2 )
{
    printf("gl stub called: glRectiv");
}

// -- glRectsv            
void glRectsv( const GLshort *v1, const GLshort *v2 )
{
    printf("gl stub called: glRectsv");
}

// -- glVertexPointer            
void glVertexPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )
{
    printf("gl stub called: glVertexPointer");
}

// -- glNormalPointer            
void glNormalPointer( GLenum type, GLsizei stride, const GLvoid *ptr )
{
    printf("gl stub called: glNormalPointer");
}

// -- glColorPointer            
void glColorPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )
{
    printf("gl stub called: glColorPointer");
}

// -- glIndexPointer            
void glIndexPointer( GLenum type, GLsizei stride, const GLvoid *ptr )
{
    printf("gl stub called: glIndexPointer");
}

// -- glTexCoordPointer            
void glTexCoordPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )
{
    printf("gl stub called: glTexCoordPointer");
}

// -- glEdgeFlagPointer            
void glEdgeFlagPointer( GLsizei stride, const GLvoid *ptr )
{
    printf("gl stub called: glEdgeFlagPointer");
}

// -- glGetPointerv            
void glGetPointerv( GLenum pname, GLvoid **params )
{
    printf("gl stub called: glGetPointerv");
}

// -- glArrayElement            
void glArrayElement( GLint i )
{
    printf("gl stub called: glArrayElement");
}

// -- glDrawArrays            
void glDrawArrays( GLenum mode, GLint first, GLsizei count )
{
    printf("gl stub called: glDrawArrays");
}

// -- glDrawElements            
void glDrawElements( GLenum mode, GLsizei count, GLenum type, const GLvoid *indices )
{
    printf("gl stub called: glDrawElements");
}

// -- glInterleavedArrays            
void glInterleavedArrays( GLenum format, GLsizei stride, const GLvoid *pointer )
{
    printf("gl stub called: glInterleavedArrays");
}

// -- glShadeModel            
void glShadeModel( GLenum mode )
{
    printf("gl stub called: glShadeModel");
}

// -- glLightf            
void glLightf( GLenum light, GLenum pname, GLfloat param )
{
    printf("gl stub called: glLightf");
}

// -- glLighti            
void glLighti( GLenum light, GLenum pname, GLint param )
{
    printf("gl stub called: glLighti");
}

// -- glLightfv            
void glLightfv( GLenum light, GLenum pname, const GLfloat *params )
{
    printf("gl stub called: glLightfv");
}

// -- glLightiv            
void glLightiv( GLenum light, GLenum pname, const GLint *params )
{
    printf("gl stub called: glLightiv");
}

// -- glGetLightfv            
void glGetLightfv( GLenum light, GLenum pname, GLfloat *params )
{
    printf("gl stub called: glGetLightfv");
}

// -- glGetLightiv            
void glGetLightiv( GLenum light, GLenum pname, GLint *params )
{
    printf("gl stub called: glGetLightiv");
}

// -- glLightModelf            
void glLightModelf( GLenum pname, GLfloat param )
{
    printf("gl stub called: glLightModelf");
}

// -- glLightModeli            
void glLightModeli( GLenum pname, GLint param )
{
    printf("gl stub called: glLightModeli");
}

// -- glLightModelfv            
void glLightModelfv( GLenum pname, const GLfloat *params )
{
    printf("gl stub called: glLightModelfv");
}

// -- glLightModeliv            
void glLightModeliv( GLenum pname, const GLint *params )
{
    printf("gl stub called: glLightModeliv");
}

// -- glMaterialf            
void glMaterialf( GLenum face, GLenum pname, GLfloat param )
{
    printf("gl stub called: glMaterialf");
}

// -- glMateriali            
void glMateriali( GLenum face, GLenum pname, GLint param )
{
    printf("gl stub called: glMateriali");
}

// -- glMaterialfv            
void glMaterialfv( GLenum face, GLenum pname, const GLfloat *params )
{
    printf("gl stub called: glMaterialfv");
}

// -- glMaterialiv            
void glMaterialiv( GLenum face, GLenum pname, const GLint *params )
{
    printf("gl stub called: glMaterialiv");
}

// -- glGetMaterialfv            
void glGetMaterialfv( GLenum face, GLenum pname, GLfloat *params )
{
    printf("gl stub called: glGetMaterialfv");
}

// -- glGetMaterialiv            
void glGetMaterialiv( GLenum face, GLenum pname, GLint *params )
{
    printf("gl stub called: glGetMaterialiv");
}

// -- glColorMaterial            
void glColorMaterial( GLenum face, GLenum mode )
{
    printf("gl stub called: glColorMaterial");
}

// -- glPixelZoom            
void glPixelZoom( GLfloat xfactor, GLfloat yfactor )
{
    printf("gl stub called: glPixelZoom");
}

// -- glPixelStoref            
void glPixelStoref( GLenum pname, GLfloat param )
{
    printf("gl stub called: glPixelStoref");
}

// -- glPixelStorei            
void glPixelStorei( GLenum pname, GLint param )
{
    printf("gl stub called: glPixelStorei");
}

// -- glPixelTransferf            
void glPixelTransferf( GLenum pname, GLfloat param )
{
    printf("gl stub called: glPixelTransferf");
}

// -- glPixelTransferi            
void glPixelTransferi( GLenum pname, GLint param )
{
    printf("gl stub called: glPixelTransferi");
}

// -- glPixelMapfv            
void glPixelMapfv( GLenum map, GLsizei mapsize, const GLfloat *values )
{
    printf("gl stub called: glPixelMapfv");
}

// -- glPixelMapuiv            
void glPixelMapuiv( GLenum map, GLsizei mapsize, const GLuint *values )
{
    printf("gl stub called: glPixelMapuiv");
}

// -- glPixelMapusv            
void glPixelMapusv( GLenum map, GLsizei mapsize, const GLushort *values )
{
    printf("gl stub called: glPixelMapusv");
}

// -- glGetPixelMapfv            
void glGetPixelMapfv( GLenum map, GLfloat *values )
{
    printf("gl stub called: glGetPixelMapfv");
}

// -- glGetPixelMapuiv            
void glGetPixelMapuiv( GLenum map, GLuint *values )
{
    printf("gl stub called: glGetPixelMapuiv");
}

// -- glGetPixelMapusv            
void glGetPixelMapusv( GLenum map, GLushort *values )
{
    printf("gl stub called: glGetPixelMapusv");
}

// -- glBitmap            
void glBitmap( GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap )
{
    printf("gl stub called: glBitmap");
}

// -- glReadPixels            
void glReadPixels( GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels )
{
    printf("gl stub called: glReadPixels");
}

// -- glDrawPixels            
void glDrawPixels( GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels )
{
    printf("gl stub called: glDrawPixels");
}

// -- glCopyPixels            
void glCopyPixels( GLint x, GLint y, GLsizei width, GLsizei height, GLenum type )
{
    printf("gl stub called: glCopyPixels");
}

// -- glStencilFunc            
void glStencilFunc( GLenum func, GLint ref, GLuint mask )
{
    printf("gl stub called: glStencilFunc");
}

// -- glStencilMask            
void glStencilMask( GLuint mask )
{
    printf("gl stub called: glStencilMask");
}

// -- glStencilOp            
void glStencilOp( GLenum fail, GLenum zfail, GLenum zpass )
{
    printf("gl stub called: glStencilOp");
}

// -- glClearStencil            
void glClearStencil( GLint s )
{
    printf("gl stub called: glClearStencil");
}

// -- glTexGend            
void glTexGend( GLenum coord, GLenum pname, GLdouble param )
{
    printf("gl stub called: glTexGend");
}

// -- glTexGenf            
void glTexGenf( GLenum coord, GLenum pname, GLfloat param )
{
    printf("gl stub called: glTexGenf");
}

// -- glTexGeni            
void glTexGeni( GLenum coord, GLenum pname, GLint param )
{
    printf("gl stub called: glTexGeni");
}

// -- glTexGendv            
void glTexGendv( GLenum coord, GLenum pname, const GLdouble *params )
{
    printf("gl stub called: glTexGendv");
}

// -- glTexGenfv            
void glTexGenfv( GLenum coord, GLenum pname, const GLfloat *params )
{
    printf("gl stub called: glTexGenfv");
}

// -- glTexGeniv            
void glTexGeniv( GLenum coord, GLenum pname, const GLint *params )
{
    printf("gl stub called: glTexGeniv");
}

// -- glGetTexGendv            
void glGetTexGendv( GLenum coord, GLenum pname, GLdouble *params )
{
    printf("gl stub called: glGetTexGendv");
}

// -- glGetTexGenfv            
void glGetTexGenfv( GLenum coord, GLenum pname, GLfloat *params )
{
    printf("gl stub called: glGetTexGenfv");
}

// -- glGetTexGeniv            
void glGetTexGeniv( GLenum coord, GLenum pname, GLint *params )
{
    printf("gl stub called: glGetTexGeniv");
}

// -- glTexEnvf            
void glTexEnvf( GLenum target, GLenum pname, GLfloat param )
{
    printf("gl stub called: glTexEnvf");
}

// -- glTexEnvi            
void glTexEnvi( GLenum target, GLenum pname, GLint param )
{
    printf("gl stub called: glTexEnvi");
}

// -- glTexEnvfv            
void glTexEnvfv( GLenum target, GLenum pname, const GLfloat *params )
{
    printf("gl stub called: glTexEnvfv");
}

// -- glTexEnviv            
void glTexEnviv( GLenum target, GLenum pname, const GLint *params )
{
    printf("gl stub called: glTexEnviv");
}

// -- glGetTexEnvfv            
void glGetTexEnvfv( GLenum target, GLenum pname, GLfloat *params )
{
    printf("gl stub called: glGetTexEnvfv");
}

// -- glGetTexEnviv            
void glGetTexEnviv( GLenum target, GLenum pname, GLint *params )
{
    printf("gl stub called: glGetTexEnviv");
}

// -- glTexParameterf            
void glTexParameterf( GLenum target, GLenum pname, GLfloat param )
{
    printf("gl stub called: glTexParameterf");
}

// -- glTexParameteri            
void glTexParameteri( GLenum target, GLenum pname, GLint param )
{
    printf("gl stub called: glTexParameteri");
}

// -- glTexParameterfv            
void glTexParameterfv( GLenum target, GLenum pname, const GLfloat *params )
{
    printf("gl stub called: glTexParameterfv");
}

// -- glTexParameteriv            
void glTexParameteriv( GLenum target, GLenum pname, const GLint *params )
{
    printf("gl stub called: glTexParameteriv");
}

// -- glGetTexParameterfv            
void glGetTexParameterfv( GLenum target, GLenum pname, GLfloat *params)
{
    printf("gl stub called: glGetTexParameterfv");
}

// -- glGetTexParameteriv            
void glGetTexParameteriv( GLenum target, GLenum pname, GLint *params )
{
    printf("gl stub called: glGetTexParameteriv");
}

// -- glGetTexLevelParameterfv            
void glGetTexLevelParameterfv( GLenum target, GLint level, GLenum pname, GLfloat *params )
{
    printf("gl stub called: glGetTexLevelParameterfv");
}

// -- glGetTexLevelParameteriv            
void glGetTexLevelParameteriv( GLenum target, GLint level, GLenum pname, GLint *params )
{
    printf("gl stub called: glGetTexLevelParameteriv");
}

// -- glTexImage1D            
void glTexImage1D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels )
{
    printf("gl stub called: glTexImage1D");
}

// -- glTexImage2D            
void glTexImage2D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels )
{
    printf("gl stub called: glTexImage2D");
}

// -- glGetTexImage            
void glGetTexImage( GLenum target, GLint level,  GLenum format, GLenum type,  GLvoid *pixels )
{
    printf("gl stub called: glGetTexImage");
}

// -- glGenTextures            
void glGenTextures( GLsizei n, GLuint *textures )
{
    printf("gl stub called: glGenTextures");
}

// -- glDeleteTextures            
void glDeleteTextures( GLsizei n, const GLuint *textures)
{
    printf("gl stub called: glDeleteTextures");
}

// -- glBindTexture            
void glBindTexture( GLenum target, GLuint texture )
{
    printf("gl stub called: glBindTexture");
}

// -- glPrioritizeTextures            
void glPrioritizeTextures( GLsizei n, const GLuint *textures, const GLclampf *priorities )
{
    printf("gl stub called: glPrioritizeTextures");
}

// -- glAreTexturesResident        
GLboolean glAreTexturesResident( GLsizei n, const GLuint *textures, GLboolean *residences )
{
    printf("Glx stub called: glAreTexturesResident");
}

// -- glIsTexture        
GLboolean glIsTexture( GLuint texture )
{
    printf("Glx stub called: glIsTexture");
}

// -- glTexSubImage1D            
void glTexSubImage1D( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels )
{
    printf("gl stub called: glTexSubImage1D");
}

// -- glTexSubImage2D            
void glTexSubImage2D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels )
{
    printf("gl stub called: glTexSubImage2D");
}

// -- glCopyTexImage1D            
void glCopyTexImage1D( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border )
{
    printf("gl stub called: glCopyTexImage1D");
}

// -- glCopyTexImage2D            
void glCopyTexImage2D( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border )
{
    printf("gl stub called: glCopyTexImage2D");
}

// -- glCopyTexSubImage1D            
void glCopyTexSubImage1D( GLenum target, GLint level,GLint xoffset, GLint x, GLint y,GLsizei width )
{
    printf("gl stub called: glCopyTexSubImage1D");
}

// -- glCopyTexSubImage2D            
void glCopyTexSubImage2D( GLenum target, GLint level,GLint xoffset, GLint yoffset,GLint x, GLint y, GLsizei width, GLsizei height )
{
    printf("gl stub called: glCopyTexSubImage2D");
}

// -- glMap1d            
void glMap1d( GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points )
{
    printf("gl stub called: glMap1d");
}

// -- glMap1f            
void glMap1f( GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points )
{
    printf("gl stub called: glMap1f");
}

// -- glMap2d            
void glMap2d( GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points )
{
    printf("gl stub called: glMap2d");
}

// -- glMap2f            
void glMap2f( GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points )
{
    printf("gl stub called: glMap2f");
}

// -- glGetMapdv            
void glGetMapdv( GLenum target, GLenum query, GLdouble *v )
{
    printf("gl stub called: glGetMapdv");
}

// -- glGetMapfv            
void glGetMapfv( GLenum target, GLenum query, GLfloat *v )
{
    printf("gl stub called: glGetMapfv");
}

// -- glGetMapiv            
void glGetMapiv( GLenum target, GLenum query, GLint *v )
{
    printf("gl stub called: glGetMapiv");
}

// -- glEvalCoord1d            
void glEvalCoord1d( GLdouble u )
{
    printf("gl stub called: glEvalCoord1d");
}

// -- glEvalCoord1f            
void glEvalCoord1f( GLfloat u )
{
    printf("gl stub called: glEvalCoord1f");
}

// -- glEvalCoord1dv            
void glEvalCoord1dv( const GLdouble *u )
{
    printf("gl stub called: glEvalCoord1dv");
}

// -- glEvalCoord1fv            
void glEvalCoord1fv( const GLfloat *u )
{
    printf("gl stub called: glEvalCoord1fv");
}

// -- glEvalCoord2d            
void glEvalCoord2d( GLdouble u, GLdouble v )
{
    printf("gl stub called: glEvalCoord2d");
}

// -- glEvalCoord2f            
void glEvalCoord2f( GLfloat u, GLfloat v )
{
    printf("gl stub called: glEvalCoord2f");
}

// -- glEvalCoord2dv            
void glEvalCoord2dv( const GLdouble *u )
{
    printf("gl stub called: glEvalCoord2dv");
}

// -- glEvalCoord2fv            
void glEvalCoord2fv( const GLfloat *u )
{
    printf("gl stub called: glEvalCoord2fv");
}

// -- glMapGrid1d            
void glMapGrid1d( GLint un, GLdouble u1, GLdouble u2 )
{
    printf("gl stub called: glMapGrid1d");
}

// -- glMapGrid1f            
void glMapGrid1f( GLint un, GLfloat u1, GLfloat u2 )
{
    printf("gl stub called: glMapGrid1f");
}

// -- glMapGrid2d            
void glMapGrid2d( GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2 )
{
    printf("gl stub called: glMapGrid2d");
}

// -- glMapGrid2f            
void glMapGrid2f( GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2 )
{
    printf("gl stub called: glMapGrid2f");
}

// -- glEvalPoint1            
void glEvalPoint1( GLint i )
{
    printf("gl stub called: glEvalPoint1");
}

// -- glEvalPoint2            
void glEvalPoint2( GLint i, GLint j )
{
    printf("gl stub called: glEvalPoint2");
}

// -- glEvalMesh1            
void glEvalMesh1( GLenum mode, GLint i1, GLint i2 )
{
    printf("gl stub called: glEvalMesh1");
}

// -- glEvalMesh2            
void glEvalMesh2( GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2 )
{
    printf("gl stub called: glEvalMesh2");
}

// -- glFogf            
void glFogf( GLenum pname, GLfloat param )
{
    printf("gl stub called: glFogf");
}

// -- glFogi            
void glFogi( GLenum pname, GLint param )
{
    printf("gl stub called: glFogi");
}

// -- glFogfv            
void glFogfv( GLenum pname, const GLfloat *params )
{
    printf("gl stub called: glFogfv");
}

// -- glFogiv            
void glFogiv( GLenum pname, const GLint *params )
{
    printf("gl stub called: glFogiv");
}

// -- glFeedbackBuffer            
void glFeedbackBuffer( GLsizei size, GLenum type, GLfloat *buffer )
{
    printf("gl stub called: glFeedbackBuffer");
}

// -- glPassThrough            
void glPassThrough( GLfloat token )
{
    printf("gl stub called: glPassThrough");
}

// -- glSelectBuffer            
void glSelectBuffer( GLsizei size, GLuint *buffer )
{
    printf("gl stub called: glSelectBuffer");
}

// -- glInitNames            
void glInitNames()
{
    printf("gl stub called: glInitNames");
}

// -- glLoadName            
void glLoadName( GLuint name )
{
    printf("gl stub called: glLoadName");
}

// -- glPushName            
void glPushName( GLuint name )
{
    printf("gl stub called: glPushName");
}

// -- glPopName            
void glPopName()
{
    printf("gl stub called: glPopName");
}

// -- glDrawRangeElements            
void glDrawRangeElements( GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices )
{
    printf("gl stub called: glDrawRangeElements");
}

// -- glTexImage3D            
void glTexImage3D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels )
{
    printf("gl stub called: glTexImage3D");
}

// -- glTexSubImage3D            
void glTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
{
    printf("gl stub called: glTexSubImage3D");
}

// -- glCopyTexSubImage3D            
void glCopyTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height )
{
    printf("gl stub called: glCopyTexSubImage3D");
}

// -- glColorTable            
void glColorTable( GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table )
{
    printf("gl stub called: glColorTable");
}

// -- glColorSubTable            
void glColorSubTable( GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data )
{
    printf("gl stub called: glColorSubTable");
}

// -- glColorTableParameteriv            
void glColorTableParameteriv(GLenum target, GLenum pname, const GLint *params)
{
    printf("gl stub called: glColorTableParameteriv");
}

// -- glColorTableParameterfv            
void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
    printf("gl stub called: glColorTableParameterfv");
}

// -- glCopyColorSubTable            
void glCopyColorSubTable( GLenum target, GLsizei start,GLint x, GLint y, GLsizei width )
{
    printf("gl stub called: glCopyColorSubTable");
}

// -- glCopyColorTable            
void glCopyColorTable( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width )
{
    printf("gl stub called: glCopyColorTable");
}

// -- glGetColorTable            
void glGetColorTable( GLenum target, GLenum format, GLenum type, GLvoid *table )
{
    printf("gl stub called: glGetColorTable");
}

// -- glGetColorTableParameterfv            
void glGetColorTableParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    printf("gl stub called: glGetColorTableParameterfv");
}

// -- glGetColorTableParameteriv            
void glGetColorTableParameteriv( GLenum target, GLenum pname, GLint *params )
{
    printf("gl stub called: glGetColorTableParameteriv");
}

// -- glBlendEquation            
void glBlendEquation( GLenum mode )
{
    printf("gl stub called: glBlendEquation");
}

// -- glBlendColor            
void glBlendColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha )
{
    printf("gl stub called: glBlendColor");
}

// -- glHistogram            
void glHistogram( GLenum target, GLsizei width, GLenum internalformat, GLboolean sink )
{
    printf("gl stub called: glHistogram");
}

// -- glResetHistogram            
void glResetHistogram( GLenum target )
{
    printf("gl stub called: glResetHistogram");
}

// -- glGetHistogram            
void glGetHistogram( GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values )
{
    printf("gl stub called: glGetHistogram");
}

// -- glGetHistogramParameterfv            
void glGetHistogramParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    printf("gl stub called: glGetHistogramParameterfv");
}

// -- glGetHistogramParameteriv            
void glGetHistogramParameteriv( GLenum target, GLenum pname, GLint *params )
{
    printf("gl stub called: glGetHistogramParameteriv");
}

// -- glMinmax            
void glMinmax( GLenum target, GLenum internalformat, GLboolean sink )
{
    printf("gl stub called: glMinmax");
}

// -- glResetMinmax            
void glResetMinmax( GLenum target )
{
    printf("gl stub called: glResetMinmax");
}

// -- glGetMinmax            
void glGetMinmax( GLenum target, GLboolean reset, GLenum format, GLenum types, GLvoid *values )
{
    printf("gl stub called: glGetMinmax");
}

// -- glGetMinmaxParameterfv            
void glGetMinmaxParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    printf("gl stub called: glGetMinmaxParameterfv");
}

// -- glGetMinmaxParameteriv            
void glGetMinmaxParameteriv( GLenum target, GLenum pname, GLint *params )
{
    printf("gl stub called: glGetMinmaxParameteriv");
}

// -- glConvolutionFilter1D            
void glConvolutionFilter1D( GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image )
{
    printf("gl stub called: glConvolutionFilter1D");
}

// -- glConvolutionFilter2D            
void glConvolutionFilter2D( GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image )
{
    printf("gl stub called: glConvolutionFilter2D");
}

// -- glConvolutionParameterf            
void glConvolutionParameterf( GLenum target, GLenum pname, GLfloat params )
{
    printf("gl stub called: glConvolutionParameterf");
}

// -- glConvolutionParameterfv            
void glConvolutionParameterfv( GLenum target, GLenum pname, const GLfloat *params )
{
    printf("gl stub called: glConvolutionParameterfv");
}

// -- glConvolutionParameteri            
void glConvolutionParameteri( GLenum target, GLenum pname, GLint params )
{
    printf("gl stub called: glConvolutionParameteri");
}

// -- glConvolutionParameteriv            
void glConvolutionParameteriv( GLenum target, GLenum pname, const GLint *params )
{
    printf("gl stub called: glConvolutionParameteriv");
}

// -- glCopyConvolutionFilter1D            
void glCopyConvolutionFilter1D( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width )
{
    printf("gl stub called: glCopyConvolutionFilter1D");
}

// -- glCopyConvolutionFilter2D            
void glCopyConvolutionFilter2D( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height)
{
    printf("gl stub called: glCopyConvolutionFilter2D");
}

// -- glGetConvolutionFilter            
void glGetConvolutionFilter( GLenum target, GLenum format, GLenum type, GLvoid *image )
{
    printf("gl stub called: glGetConvolutionFilter");
}

// -- glGetConvolutionParameterfv            
void glGetConvolutionParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    printf("gl stub called: glGetConvolutionParameterfv");
}

// -- glGetConvolutionParameteriv            
void glGetConvolutionParameteriv( GLenum target, GLenum pname, GLint *params )
{
    printf("gl stub called: glGetConvolutionParameteriv");
}

// -- glSeparableFilter2D            
void glSeparableFilter2D( GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column )
{
    printf("gl stub called: glSeparableFilter2D");
}

// -- glGetSeparableFilter            
void glGetSeparableFilter( GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span )
{
    printf("gl stub called: glGetSeparableFilter");
}

// -- glActiveTexture            
void glActiveTexture( GLenum texture )
{
    printf("gl stub called: glActiveTexture");
}

// -- glClientActiveTexture            
void glClientActiveTexture( GLenum texture )
{
    printf("gl stub called: glClientActiveTexture");
}

// -- glCompressedTexImage1D            
void glCompressedTexImage1D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data )
{
    printf("gl stub called: glCompressedTexImage1D");
}

// -- glCompressedTexImage2D            
void glCompressedTexImage2D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data )
{
    printf("gl stub called: glCompressedTexImage2D");
}

// -- glCompressedTexImage3D            
void glCompressedTexImage3D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data )
{
    printf("gl stub called: glCompressedTexImage3D");
}

// -- glCompressedTexSubImage1D            
void glCompressedTexSubImage1D( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data )
{
    printf("gl stub called: glCompressedTexSubImage1D");
}

// -- glCompressedTexSubImage2D            
void glCompressedTexSubImage2D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data )
{
    printf("gl stub called: glCompressedTexSubImage2D");
}

// -- glCompressedTexSubImage3D            
void glCompressedTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data )
{
    printf("gl stub called: glCompressedTexSubImage3D");
}

// -- glGetCompressedTexImage            
void glGetCompressedTexImage( GLenum target, GLint lod, GLvoid *img )
{
    printf("gl stub called: glGetCompressedTexImage");
}

// -- glMultiTexCoord1d            
void glMultiTexCoord1d( GLenum target, GLdouble s )
{
    printf("gl stub called: glMultiTexCoord1d");
}

// -- glMultiTexCoord1dv            
void glMultiTexCoord1dv( GLenum target, const GLdouble *v )
{
    printf("gl stub called: glMultiTexCoord1dv");
}

// -- glMultiTexCoord1f            
void glMultiTexCoord1f( GLenum target, GLfloat s )
{
    printf("gl stub called: glMultiTexCoord1f");
}

// -- glMultiTexCoord1fv            
void glMultiTexCoord1fv( GLenum target, const GLfloat *v )
{
    printf("gl stub called: glMultiTexCoord1fv");
}

// -- glMultiTexCoord1i            
void glMultiTexCoord1i( GLenum target, GLint s )
{
    printf("gl stub called: glMultiTexCoord1i");
}

// -- glMultiTexCoord1iv            
void glMultiTexCoord1iv( GLenum target, const GLint *v )
{
    printf("gl stub called: glMultiTexCoord1iv");
}

// -- glMultiTexCoord1s            
void glMultiTexCoord1s( GLenum target, GLshort s )
{
    printf("gl stub called: glMultiTexCoord1s");
}

// -- glMultiTexCoord1sv            
void glMultiTexCoord1sv( GLenum target, const GLshort *v )
{
    printf("gl stub called: glMultiTexCoord1sv");
}

// -- glMultiTexCoord2d            
void glMultiTexCoord2d( GLenum target, GLdouble s, GLdouble t )
{
    printf("gl stub called: glMultiTexCoord2d");
}

// -- glMultiTexCoord2dv            
void glMultiTexCoord2dv( GLenum target, const GLdouble *v )
{
    printf("gl stub called: glMultiTexCoord2dv");
}

// -- glMultiTexCoord2f            
void glMultiTexCoord2f( GLenum target, GLfloat s, GLfloat t )
{
    printf("gl stub called: glMultiTexCoord2f");
}

// -- glMultiTexCoord2fv            
void glMultiTexCoord2fv( GLenum target, const GLfloat *v )
{
    printf("gl stub called: glMultiTexCoord2fv");
}

// -- glMultiTexCoord2i            
void glMultiTexCoord2i( GLenum target, GLint s, GLint t )
{
    printf("gl stub called: glMultiTexCoord2i");
}

// -- glMultiTexCoord2iv            
void glMultiTexCoord2iv( GLenum target, const GLint *v )
{
    printf("gl stub called: glMultiTexCoord2iv");
}

// -- glMultiTexCoord2s            
void glMultiTexCoord2s( GLenum target, GLshort s, GLshort t )
{
    printf("gl stub called: glMultiTexCoord2s");
}

// -- glMultiTexCoord2sv            
void glMultiTexCoord2sv( GLenum target, const GLshort *v )
{
    printf("gl stub called: glMultiTexCoord2sv");
}

// -- glMultiTexCoord3d            
void glMultiTexCoord3d( GLenum target, GLdouble s, GLdouble t, GLdouble r )
{
    printf("gl stub called: glMultiTexCoord3d");
}

// -- glMultiTexCoord3dv            
void glMultiTexCoord3dv( GLenum target, const GLdouble *v )
{
    printf("gl stub called: glMultiTexCoord3dv");
}

// -- glMultiTexCoord3f            
void glMultiTexCoord3f( GLenum target, GLfloat s, GLfloat t, GLfloat r )
{
    printf("gl stub called: glMultiTexCoord3f");
}

// -- glMultiTexCoord3fv            
void glMultiTexCoord3fv( GLenum target, const GLfloat *v )
{
    printf("gl stub called: glMultiTexCoord3fv");
}

// -- glMultiTexCoord3i            
void glMultiTexCoord3i( GLenum target, GLint s, GLint t, GLint r )
{
    printf("gl stub called: glMultiTexCoord3i");
}

// -- glMultiTexCoord3iv            
void glMultiTexCoord3iv( GLenum target, const GLint *v )
{
    printf("gl stub called: glMultiTexCoord3iv");
}

// -- glMultiTexCoord3s            
void glMultiTexCoord3s( GLenum target, GLshort s, GLshort t, GLshort r )
{
    printf("gl stub called: glMultiTexCoord3s");
}

// -- glMultiTexCoord3sv            
void glMultiTexCoord3sv( GLenum target, const GLshort *v )
{
    printf("gl stub called: glMultiTexCoord3sv");
}

// -- glMultiTexCoord4d            
void glMultiTexCoord4d( GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q )
{
    printf("gl stub called: glMultiTexCoord4d");
}

// -- glMultiTexCoord4dv            
void glMultiTexCoord4dv( GLenum target, const GLdouble *v )
{
    printf("gl stub called: glMultiTexCoord4dv");
}

// -- glMultiTexCoord4f            
void glMultiTexCoord4f( GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q )
{
    printf("gl stub called: glMultiTexCoord4f");
}

// -- glMultiTexCoord4fv            
void glMultiTexCoord4fv( GLenum target, const GLfloat *v )
{
    printf("gl stub called: glMultiTexCoord4fv");
}

// -- glMultiTexCoord4i            
void glMultiTexCoord4i( GLenum target, GLint s, GLint t, GLint r, GLint q )
{
    printf("gl stub called: glMultiTexCoord4i");
}

// -- glMultiTexCoord4iv            
void glMultiTexCoord4iv( GLenum target, const GLint *v )
{
    printf("gl stub called: glMultiTexCoord4iv");
}

// -- glMultiTexCoord4s            
void glMultiTexCoord4s( GLenum target, GLshort s, GLshort t, GLshort r, GLshort q )
{
    printf("gl stub called: glMultiTexCoord4s");
}

// -- glMultiTexCoord4sv            
void glMultiTexCoord4sv( GLenum target, const GLshort *v )
{
    printf("gl stub called: glMultiTexCoord4sv");
}

// -- glLoadTransposeMatrixd            
void glLoadTransposeMatrixd( const GLdouble m[16] )
{
    printf("gl stub called: glLoadTransposeMatrixd");
}

// -- glLoadTransposeMatrixf            
void glLoadTransposeMatrixf( const GLfloat m[16] )
{
    printf("gl stub called: glLoadTransposeMatrixf");
}

// -- glMultTransposeMatrixd            
void glMultTransposeMatrixd( const GLdouble m[16] )
{
    printf("gl stub called: glMultTransposeMatrixd");
}

// -- glMultTransposeMatrixf            
void glMultTransposeMatrixf( const GLfloat m[16] )
{
    printf("gl stub called: glMultTransposeMatrixf");
}

// -- glSampleCoverage            
void glSampleCoverage( GLclampf value, GLboolean invert )
{
    printf("gl stub called: glSampleCoverage");
}

// -- glActiveTextureARB            
void glActiveTextureARB(GLenum texture)
{
    printf("gl stub called: glActiveTextureARB");
}

// -- glClientActiveTextureARB            
void glClientActiveTextureARB(GLenum texture)
{
    printf("gl stub called: glClientActiveTextureARB");
}

// -- glMultiTexCoord1dARB            
void glMultiTexCoord1dARB(GLenum target, GLdouble s)
{
    printf("gl stub called: glMultiTexCoord1dARB");
}

// -- glMultiTexCoord1dvARB            
void glMultiTexCoord1dvARB(GLenum target, const GLdouble *v)
{
    printf("gl stub called: glMultiTexCoord1dvARB");
}

// -- glMultiTexCoord1fARB            
void glMultiTexCoord1fARB(GLenum target, GLfloat s)
{
    printf("gl stub called: glMultiTexCoord1fARB");
}

// -- glMultiTexCoord1fvARB            
void glMultiTexCoord1fvARB(GLenum target, const GLfloat *v)
{
    printf("gl stub called: glMultiTexCoord1fvARB");
}

// -- glMultiTexCoord1iARB            
void glMultiTexCoord1iARB(GLenum target, GLint s)
{
    printf("gl stub called: glMultiTexCoord1iARB");
}

// -- glMultiTexCoord1ivARB            
void glMultiTexCoord1ivARB(GLenum target, const GLint *v)
{
    printf("gl stub called: glMultiTexCoord1ivARB");
}

// -- glMultiTexCoord1sARB            
void glMultiTexCoord1sARB(GLenum target, GLshort s)
{
    printf("gl stub called: glMultiTexCoord1sARB");
}

// -- glMultiTexCoord1svARB            
void glMultiTexCoord1svARB(GLenum target, const GLshort *v)
{
    printf("gl stub called: glMultiTexCoord1svARB");
}

// -- glMultiTexCoord2dARB            
void glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t)
{
    printf("gl stub called: glMultiTexCoord2dARB");
}

// -- glMultiTexCoord2dvARB            
void glMultiTexCoord2dvARB(GLenum target, const GLdouble *v)
{
    printf("gl stub called: glMultiTexCoord2dvARB");
}

// -- glMultiTexCoord2fARB            
void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t)
{
    printf("gl stub called: glMultiTexCoord2fARB");
}

// -- glMultiTexCoord2fvARB            
void glMultiTexCoord2fvARB(GLenum target, const GLfloat *v)
{
    printf("gl stub called: glMultiTexCoord2fvARB");
}

// -- glMultiTexCoord2iARB            
void glMultiTexCoord2iARB(GLenum target, GLint s, GLint t)
{
    printf("gl stub called: glMultiTexCoord2iARB");
}

// -- glMultiTexCoord2ivARB            
void glMultiTexCoord2ivARB(GLenum target, const GLint *v)
{
    printf("gl stub called: glMultiTexCoord2ivARB");
}

// -- glMultiTexCoord2sARB            
void glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t)
{
    printf("gl stub called: glMultiTexCoord2sARB");
}

// -- glMultiTexCoord2svARB            
void glMultiTexCoord2svARB(GLenum target, const GLshort *v)
{
    printf("gl stub called: glMultiTexCoord2svARB");
}

// -- glMultiTexCoord3dARB            
void glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r)
{
    printf("gl stub called: glMultiTexCoord3dARB");
}

// -- glMultiTexCoord3dvARB            
void glMultiTexCoord3dvARB(GLenum target, const GLdouble *v)
{
    printf("gl stub called: glMultiTexCoord3dvARB");
}

// -- glMultiTexCoord3fARB            
void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r)
{
    printf("gl stub called: glMultiTexCoord3fARB");
}

// -- glMultiTexCoord3fvARB            
void glMultiTexCoord3fvARB(GLenum target, const GLfloat *v)
{
    printf("gl stub called: glMultiTexCoord3fvARB");
}

// -- glMultiTexCoord3iARB            
void glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r)
{
    printf("gl stub called: glMultiTexCoord3iARB");
}

// -- glMultiTexCoord3ivARB            
void glMultiTexCoord3ivARB(GLenum target, const GLint *v)
{
    printf("gl stub called: glMultiTexCoord3ivARB");
}

// -- glMultiTexCoord3sARB            
void glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r)
{
    printf("gl stub called: glMultiTexCoord3sARB");
}

// -- glMultiTexCoord3svARB            
void glMultiTexCoord3svARB(GLenum target, const GLshort *v)
{
    printf("gl stub called: glMultiTexCoord3svARB");
}

// -- glMultiTexCoord4dARB            
void glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
    printf("gl stub called: glMultiTexCoord4dARB");
}

// -- glMultiTexCoord4dvARB            
void glMultiTexCoord4dvARB(GLenum target, const GLdouble *v)
{
    printf("gl stub called: glMultiTexCoord4dvARB");
}

// -- glMultiTexCoord4fARB            
void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
    printf("gl stub called: glMultiTexCoord4fARB");
}

// -- glMultiTexCoord4fvARB            
void glMultiTexCoord4fvARB(GLenum target, const GLfloat *v)
{
    printf("gl stub called: glMultiTexCoord4fvARB");
}

// -- glMultiTexCoord4iARB            
void glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q)
{
    printf("gl stub called: glMultiTexCoord4iARB");
}

// -- glMultiTexCoord4ivARB            
void glMultiTexCoord4ivARB(GLenum target, const GLint *v)
{
    printf("gl stub called: glMultiTexCoord4ivARB");
}

// -- glMultiTexCoord4sARB            
void glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
{
    printf("gl stub called: glMultiTexCoord4sARB");
}

// -- glMultiTexCoord4svARB            
void glMultiTexCoord4svARB(GLenum target, const GLshort *v)
{
    printf("gl stub called: glMultiTexCoord4svARB");
}

// -- glBlendEquationSeparateATI            
void glBlendEquationSeparateATI( GLenum modeRGB, GLenum modeA )
{
    printf("gl stub called: glBlendEquationSeparateATI");
}

