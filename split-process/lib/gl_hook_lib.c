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
void (*_glClearIndex)() = NULL;
            
void glClearIndex( GLfloat c )
{
    if (_glClearIndex == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glClearIndex = dlsym(handle, "glClearIndex");
            dlclose(handle);
        }
    }
    
    _glClearIndex(c);
}

// -- glClearColor
void (*_glClearColor)() = NULL;
            
void glClearColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha )
{
    if (_glClearColor == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glClearColor = dlsym(handle, "glClearColor");
            dlclose(handle);
        }
    }
    
    _glClearColor(red, green, blue, alpha);
}

// -- glClear
void (*_glClear)() = NULL;
            
void glClear( GLbitfield mask )
{
    if (_glClear == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glClear = dlsym(handle, "glClear");
            dlclose(handle);
        }
    }
    
    _glClear(mask);
}

// -- glIndexMask
void (*_glIndexMask)() = NULL;
            
void glIndexMask( GLuint mask )
{
    if (_glIndexMask == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexMask = dlsym(handle, "glIndexMask");
            dlclose(handle);
        }
    }
    
    _glIndexMask(mask);
}

// -- glColorMask
void (*_glColorMask)() = NULL;
            
void glColorMask( GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha )
{
    if (_glColorMask == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColorMask = dlsym(handle, "glColorMask");
            dlclose(handle);
        }
    }
    
    _glColorMask(red, green, blue, alpha);
}

// -- glAlphaFunc
void (*_glAlphaFunc)() = NULL;
            
void glAlphaFunc( GLenum func, GLclampf ref )
{
    if (_glAlphaFunc == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glAlphaFunc = dlsym(handle, "glAlphaFunc");
            dlclose(handle);
        }
    }
    
    _glAlphaFunc(func, ref);
}

// -- glBlendFunc
void (*_glBlendFunc)() = NULL;
            
void glBlendFunc( GLenum sfactor, GLenum dfactor )
{
    if (_glBlendFunc == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glBlendFunc = dlsym(handle, "glBlendFunc");
            dlclose(handle);
        }
    }
    
    _glBlendFunc(sfactor, dfactor);
}

// -- glLogicOp
void (*_glLogicOp)() = NULL;
            
void glLogicOp( GLenum opcode )
{
    if (_glLogicOp == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLogicOp = dlsym(handle, "glLogicOp");
            dlclose(handle);
        }
    }
    
    _glLogicOp(opcode);
}

// -- glCullFace
void (*_glCullFace)() = NULL;
            
void glCullFace( GLenum mode )
{
    if (_glCullFace == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCullFace = dlsym(handle, "glCullFace");
            dlclose(handle);
        }
    }
    
    _glCullFace(mode);
}

// -- glFrontFace
void (*_glFrontFace)() = NULL;
            
void glFrontFace( GLenum mode )
{
    if (_glFrontFace == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glFrontFace = dlsym(handle, "glFrontFace");
            dlclose(handle);
        }
    }
    
    _glFrontFace(mode);
}

// -- glPointSize
void (*_glPointSize)() = NULL;
            
void glPointSize( GLfloat size )
{
    if (_glPointSize == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPointSize = dlsym(handle, "glPointSize");
            dlclose(handle);
        }
    }
    
    _glPointSize(size);
}

// -- glLineWidth
void (*_glLineWidth)() = NULL;
            
void glLineWidth( GLfloat width )
{
    if (_glLineWidth == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLineWidth = dlsym(handle, "glLineWidth");
            dlclose(handle);
        }
    }
    
    _glLineWidth(width);
}

// -- glLineStipple
void (*_glLineStipple)() = NULL;
            
void glLineStipple( GLint factor, GLushort pattern )
{
    if (_glLineStipple == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLineStipple = dlsym(handle, "glLineStipple");
            dlclose(handle);
        }
    }
    
    _glLineStipple(factor, pattern);
}

// -- glPolygonMode
void (*_glPolygonMode)() = NULL;
            
void glPolygonMode( GLenum face, GLenum mode )
{
    if (_glPolygonMode == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPolygonMode = dlsym(handle, "glPolygonMode");
            dlclose(handle);
        }
    }
    
    _glPolygonMode(face, mode);
}

// -- glPolygonOffset
void (*_glPolygonOffset)() = NULL;
            
void glPolygonOffset( GLfloat factor, GLfloat units )
{
    if (_glPolygonOffset == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPolygonOffset = dlsym(handle, "glPolygonOffset");
            dlclose(handle);
        }
    }
    
    _glPolygonOffset(factor, units);
}

// -- glPolygonStipple
void (*_glPolygonStipple)() = NULL;
            
void glPolygonStipple( const GLubyte *mask )
{
    if (_glPolygonStipple == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPolygonStipple = dlsym(handle, "glPolygonStipple");
            dlclose(handle);
        }
    }
    
    _glPolygonStipple(*mask);
}

// -- glGetPolygonStipple
void (*_glGetPolygonStipple)() = NULL;
            
void glGetPolygonStipple( GLubyte *mask )
{
    if (_glGetPolygonStipple == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetPolygonStipple = dlsym(handle, "glGetPolygonStipple");
            dlclose(handle);
        }
    }
    
    _glGetPolygonStipple(*mask);
}

// -- glEdgeFlag
void (*_glEdgeFlag)() = NULL;
            
void glEdgeFlag( GLboolean flag )
{
    if (_glEdgeFlag == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEdgeFlag = dlsym(handle, "glEdgeFlag");
            dlclose(handle);
        }
    }
    
    _glEdgeFlag(flag);
}

// -- glEdgeFlagv
void (*_glEdgeFlagv)() = NULL;
            
void glEdgeFlagv( const GLboolean *flag )
{
    if (_glEdgeFlagv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEdgeFlagv = dlsym(handle, "glEdgeFlagv");
            dlclose(handle);
        }
    }
    
    _glEdgeFlagv(*flag);
}

// -- glScissor
void (*_glScissor)() = NULL;
            
void glScissor( GLint x, GLint y, GLsizei width, GLsizei height)
{
    if (_glScissor == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glScissor = dlsym(handle, "glScissor");
            dlclose(handle);
        }
    }
    
    _glScissor(x, y, width, height);
}

// -- glClipPlane
void (*_glClipPlane)() = NULL;
            
void glClipPlane( GLenum plane, const GLdouble *equation )
{
    if (_glClipPlane == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glClipPlane = dlsym(handle, "glClipPlane");
            dlclose(handle);
        }
    }
    
    _glClipPlane(plane, *equation);
}

// -- glGetClipPlane
void (*_glGetClipPlane)() = NULL;
            
void glGetClipPlane( GLenum plane, GLdouble *equation )
{
    if (_glGetClipPlane == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetClipPlane = dlsym(handle, "glGetClipPlane");
            dlclose(handle);
        }
    }
    
    _glGetClipPlane(plane, *equation);
}

// -- glDrawBuffer
void (*_glDrawBuffer)() = NULL;
            
void glDrawBuffer( GLenum mode )
{
    if (_glDrawBuffer == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDrawBuffer = dlsym(handle, "glDrawBuffer");
            dlclose(handle);
        }
    }
    
    _glDrawBuffer(mode);
}

// -- glReadBuffer
void (*_glReadBuffer)() = NULL;
            
void glReadBuffer( GLenum mode )
{
    if (_glReadBuffer == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glReadBuffer = dlsym(handle, "glReadBuffer");
            dlclose(handle);
        }
    }
    
    _glReadBuffer(mode);
}

// -- glEnable
void (*_glEnable)() = NULL;
            
void glEnable( GLenum cap )
{
    if (_glEnable == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEnable = dlsym(handle, "glEnable");
            dlclose(handle);
        }
    }
    
    _glEnable(cap);
}

// -- glDisable
void (*_glDisable)() = NULL;
            
void glDisable( GLenum cap )
{
    if (_glDisable == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDisable = dlsym(handle, "glDisable");
            dlclose(handle);
        }
    }
    
    _glDisable(cap);
}

// -- glIsEnabled
GLboolean (*_glIsEnabled)() = NULL;
        
GLboolean glIsEnabled( GLenum cap )
{
    if (_glIsEnabled == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIsEnabled = dlsym(handle, "glIsEnabled");
            dlclose(handle);
        }
    }

    return _glIsEnabled(cap);
}

// -- glEnableClientState
void (*_glEnableClientState)() = NULL;
            
void glEnableClientState( GLenum cap )
{
    if (_glEnableClientState == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEnableClientState = dlsym(handle, "glEnableClientState");
            dlclose(handle);
        }
    }
    
    _glEnableClientState(cap);
}

// -- glDisableClientState
void (*_glDisableClientState)() = NULL;
            
void glDisableClientState( GLenum cap )
{
    if (_glDisableClientState == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDisableClientState = dlsym(handle, "glDisableClientState");
            dlclose(handle);
        }
    }
    
    _glDisableClientState(cap);
}

// -- glGetBooleanv
void (*_glGetBooleanv)() = NULL;
            
void glGetBooleanv( GLenum pname, GLboolean *params )
{
    if (_glGetBooleanv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetBooleanv = dlsym(handle, "glGetBooleanv");
            dlclose(handle);
        }
    }
    
    _glGetBooleanv(pname, *params);
}

// -- glGetDoublev
void (*_glGetDoublev)() = NULL;
            
void glGetDoublev( GLenum pname, GLdouble *params )
{
    if (_glGetDoublev == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetDoublev = dlsym(handle, "glGetDoublev");
            dlclose(handle);
        }
    }
    
    _glGetDoublev(pname, *params);
}

// -- glGetFloatv
void (*_glGetFloatv)() = NULL;
            
void glGetFloatv( GLenum pname, GLfloat *params )
{
    if (_glGetFloatv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetFloatv = dlsym(handle, "glGetFloatv");
            dlclose(handle);
        }
    }
    
    _glGetFloatv(pname, *params);
}

// -- glGetIntegerv
void (*_glGetIntegerv)() = NULL;
            
void glGetIntegerv( GLenum pname, GLint *params )
{
    if (_glGetIntegerv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetIntegerv = dlsym(handle, "glGetIntegerv");
            dlclose(handle);
        }
    }
    
    _glGetIntegerv(pname, *params);
}

// -- glPushAttrib
void (*_glPushAttrib)() = NULL;
            
void glPushAttrib( GLbitfield mask )
{
    if (_glPushAttrib == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPushAttrib = dlsym(handle, "glPushAttrib");
            dlclose(handle);
        }
    }
    
    _glPushAttrib(mask);
}

// -- glPopAttrib
void (*_glPopAttrib)() = NULL;
            
void glPopAttrib()
{
    if (_glPopAttrib == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPopAttrib = dlsym(handle, "glPopAttrib");
            dlclose(handle);
        }
    }
    
    _glPopAttrib();
}

// -- glPushClientAttrib
void (*_glPushClientAttrib)() = NULL;
            
void glPushClientAttrib( GLbitfield mask )
{
    if (_glPushClientAttrib == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPushClientAttrib = dlsym(handle, "glPushClientAttrib");
            dlclose(handle);
        }
    }
    
    _glPushClientAttrib(mask);
}

// -- glPopClientAttrib
void (*_glPopClientAttrib)() = NULL;
            
void glPopClientAttrib()
{
    if (_glPopClientAttrib == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPopClientAttrib = dlsym(handle, "glPopClientAttrib");
            dlclose(handle);
        }
    }
    
    _glPopClientAttrib();
}

// -- glRenderMode
GLint (*_glRenderMode)() = NULL;
        
GLint glRenderMode( GLenum mode )
{
    if (_glRenderMode == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRenderMode = dlsym(handle, "glRenderMode");
            dlclose(handle);
        }
    }

    return _glRenderMode(mode);
}

// -- glGetError
GLdisplayenum (*_glGetError)() = NULL;
        
GLdisplayenum glGetError()
{
    if (_glGetError == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetError = dlsym(handle, "glGetError");
            dlclose(handle);
        }
    }

    return _glGetError();
}

// -- * GLAPIENTRY glGetString
const (*_* GLAPIENTRY glGetString)() = NULL;
        
const * GLAPIENTRY glGetString( GLenum name )
{
    if (_* GLAPIENTRY glGetString == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _* GLAPIENTRY glGetString = dlsym(handle, "* GLAPIENTRY glGetString");
            dlclose(handle);
        }
    }

    return _* GLAPIENTRY glGetString(name);
}

// -- glFinish
void (*_glFinish)() = NULL;
            
void glFinish()
{
    if (_glFinish == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glFinish = dlsym(handle, "glFinish");
            dlclose(handle);
        }
    }
    
    _glFinish();
}

// -- glFlush
void (*_glFlush)() = NULL;
            
void glFlush()
{
    if (_glFlush == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glFlush = dlsym(handle, "glFlush");
            dlclose(handle);
        }
    }
    
    _glFlush();
}

// -- glHint
void (*_glHint)() = NULL;
            
void glHint( GLenum target, GLenum mode )
{
    if (_glHint == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glHint = dlsym(handle, "glHint");
            dlclose(handle);
        }
    }
    
    _glHint(target, mode);
}

// -- glClearDepth
void (*_glClearDepth)() = NULL;
            
void glClearDepth( GLclampd depth )
{
    if (_glClearDepth == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glClearDepth = dlsym(handle, "glClearDepth");
            dlclose(handle);
        }
    }
    
    _glClearDepth(depth);
}

// -- glDepthFunc
void (*_glDepthFunc)() = NULL;
            
void glDepthFunc( GLenum func )
{
    if (_glDepthFunc == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDepthFunc = dlsym(handle, "glDepthFunc");
            dlclose(handle);
        }
    }
    
    _glDepthFunc(func);
}

// -- glDepthMask
void (*_glDepthMask)() = NULL;
            
void glDepthMask( GLboolean flag )
{
    if (_glDepthMask == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDepthMask = dlsym(handle, "glDepthMask");
            dlclose(handle);
        }
    }
    
    _glDepthMask(flag);
}

// -- glDepthRange
void (*_glDepthRange)() = NULL;
            
void glDepthRange( GLclampd near_val, GLclampd far_val )
{
    if (_glDepthRange == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDepthRange = dlsym(handle, "glDepthRange");
            dlclose(handle);
        }
    }
    
    _glDepthRange(near_val, far_val);
}

// -- glClearAccum
void (*_glClearAccum)() = NULL;
            
void glClearAccum( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha )
{
    if (_glClearAccum == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glClearAccum = dlsym(handle, "glClearAccum");
            dlclose(handle);
        }
    }
    
    _glClearAccum(red, green, blue, alpha);
}

// -- glAccum
void (*_glAccum)() = NULL;
            
void glAccum( GLenum op, GLfloat value )
{
    if (_glAccum == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glAccum = dlsym(handle, "glAccum");
            dlclose(handle);
        }
    }
    
    _glAccum(op, value);
}

// -- glMatrixMode
void (*_glMatrixMode)() = NULL;
            
void glMatrixMode( GLenum mode )
{
    if (_glMatrixMode == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMatrixMode = dlsym(handle, "glMatrixMode");
            dlclose(handle);
        }
    }
    
    _glMatrixMode(mode);
}

// -- glOrtho
void (*_glOrtho)() = NULL;
            
void glOrtho( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val )
{
    if (_glOrtho == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glOrtho = dlsym(handle, "glOrtho");
            dlclose(handle);
        }
    }
    
    _glOrtho(left, right, bottom, top, near_val, far_val);
}

// -- glFrustum
void (*_glFrustum)() = NULL;
            
void glFrustum( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val )
{
    if (_glFrustum == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glFrustum = dlsym(handle, "glFrustum");
            dlclose(handle);
        }
    }
    
    _glFrustum(left, right, bottom, top, near_val, far_val);
}

// -- glViewport
void (*_glViewport)() = NULL;
            
void glViewport( GLint x, GLint y, GLsizei width, GLsizei height )
{
    if (_glViewport == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glViewport = dlsym(handle, "glViewport");
            dlclose(handle);
        }
    }
    
    _glViewport(x, y, width, height);
}

// -- glPushMatrix
void (*_glPushMatrix)() = NULL;
            
void glPushMatrix()
{
    if (_glPushMatrix == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPushMatrix = dlsym(handle, "glPushMatrix");
            dlclose(handle);
        }
    }
    
    _glPushMatrix();
}

// -- glPopMatrix
void (*_glPopMatrix)() = NULL;
            
void glPopMatrix()
{
    if (_glPopMatrix == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPopMatrix = dlsym(handle, "glPopMatrix");
            dlclose(handle);
        }
    }
    
    _glPopMatrix();
}

// -- glLoadIdentity
void (*_glLoadIdentity)() = NULL;
            
void glLoadIdentity()
{
    if (_glLoadIdentity == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLoadIdentity = dlsym(handle, "glLoadIdentity");
            dlclose(handle);
        }
    }
    
    _glLoadIdentity();
}

// -- glLoadMatrixd
void (*_glLoadMatrixd)() = NULL;
            
void glLoadMatrixd( const GLdouble *m )
{
    if (_glLoadMatrixd == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLoadMatrixd = dlsym(handle, "glLoadMatrixd");
            dlclose(handle);
        }
    }
    
    _glLoadMatrixd(*m);
}

// -- glLoadMatrixf
void (*_glLoadMatrixf)() = NULL;
            
void glLoadMatrixf( const GLfloat *m )
{
    if (_glLoadMatrixf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLoadMatrixf = dlsym(handle, "glLoadMatrixf");
            dlclose(handle);
        }
    }
    
    _glLoadMatrixf(*m);
}

// -- glMultMatrixd
void (*_glMultMatrixd)() = NULL;
            
void glMultMatrixd( const GLdouble *m )
{
    if (_glMultMatrixd == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultMatrixd = dlsym(handle, "glMultMatrixd");
            dlclose(handle);
        }
    }
    
    _glMultMatrixd(*m);
}

// -- glMultMatrixf
void (*_glMultMatrixf)() = NULL;
            
void glMultMatrixf( const GLfloat *m )
{
    if (_glMultMatrixf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultMatrixf = dlsym(handle, "glMultMatrixf");
            dlclose(handle);
        }
    }
    
    _glMultMatrixf(*m);
}

// -- glRotated
void (*_glRotated)() = NULL;
            
void glRotated( GLdouble angle, GLdouble x, GLdouble y, GLdouble z )
{
    if (_glRotated == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRotated = dlsym(handle, "glRotated");
            dlclose(handle);
        }
    }
    
    _glRotated(angle, x, y, z);
}

// -- glRotatef
void (*_glRotatef)() = NULL;
            
void glRotatef( GLfloat angle, GLfloat x, GLfloat y, GLfloat z )
{
    if (_glRotatef == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRotatef = dlsym(handle, "glRotatef");
            dlclose(handle);
        }
    }
    
    _glRotatef(angle, x, y, z);
}

// -- glScaled
void (*_glScaled)() = NULL;
            
void glScaled( GLdouble x, GLdouble y, GLdouble z )
{
    if (_glScaled == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glScaled = dlsym(handle, "glScaled");
            dlclose(handle);
        }
    }
    
    _glScaled(x, y, z);
}

// -- glScalef
void (*_glScalef)() = NULL;
            
void glScalef( GLfloat x, GLfloat y, GLfloat z )
{
    if (_glScalef == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glScalef = dlsym(handle, "glScalef");
            dlclose(handle);
        }
    }
    
    _glScalef(x, y, z);
}

// -- glTranslated
void (*_glTranslated)() = NULL;
            
void glTranslated( GLdouble x, GLdouble y, GLdouble z )
{
    if (_glTranslated == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTranslated = dlsym(handle, "glTranslated");
            dlclose(handle);
        }
    }
    
    _glTranslated(x, y, z);
}

// -- glTranslatef
void (*_glTranslatef)() = NULL;
            
void glTranslatef( GLfloat x, GLfloat y, GLfloat z )
{
    if (_glTranslatef == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTranslatef = dlsym(handle, "glTranslatef");
            dlclose(handle);
        }
    }
    
    _glTranslatef(x, y, z);
}

// -- glIsList
GLboolean (*_glIsList)() = NULL;
        
GLboolean glIsList( GLuint list )
{
    if (_glIsList == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIsList = dlsym(handle, "glIsList");
            dlclose(handle);
        }
    }

    return _glIsList(list);
}

// -- glDeleteLists
void (*_glDeleteLists)() = NULL;
            
void glDeleteLists( GLuint list, GLsizei range )
{
    if (_glDeleteLists == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDeleteLists = dlsym(handle, "glDeleteLists");
            dlclose(handle);
        }
    }
    
    _glDeleteLists(list, range);
}

// -- glGenLists
GLuint (*_glGenLists)() = NULL;
        
GLuint glGenLists( GLsizei range )
{
    if (_glGenLists == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGenLists = dlsym(handle, "glGenLists");
            dlclose(handle);
        }
    }

    return _glGenLists(range);
}

// -- glNewList
void (*_glNewList)() = NULL;
            
void glNewList( GLuint list, GLenum mode )
{
    if (_glNewList == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNewList = dlsym(handle, "glNewList");
            dlclose(handle);
        }
    }
    
    _glNewList(list, mode);
}

// -- glEndList
void (*_glEndList)() = NULL;
            
void glEndList()
{
    if (_glEndList == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEndList = dlsym(handle, "glEndList");
            dlclose(handle);
        }
    }
    
    _glEndList();
}

// -- glCallList
void (*_glCallList)() = NULL;
            
void glCallList( GLuint list )
{
    if (_glCallList == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCallList = dlsym(handle, "glCallList");
            dlclose(handle);
        }
    }
    
    _glCallList(list);
}

// -- glCallLists
void (*_glCallLists)() = NULL;
            
void glCallLists( GLsizei n, GLenum type, const GLvoid *lists )
{
    if (_glCallLists == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCallLists = dlsym(handle, "glCallLists");
            dlclose(handle);
        }
    }
    
    _glCallLists(n, type, *lists);
}

// -- glListBase
void (*_glListBase)() = NULL;
            
void glListBase( GLuint base )
{
    if (_glListBase == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glListBase = dlsym(handle, "glListBase");
            dlclose(handle);
        }
    }
    
    _glListBase(base);
}

// -- glBegin
void (*_glBegin)() = NULL;
            
void glBegin( GLenum mode )
{
    if (_glBegin == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glBegin = dlsym(handle, "glBegin");
            dlclose(handle);
        }
    }
    
    _glBegin(mode);
}

// -- glEnd
void (*_glEnd)() = NULL;
            
void glEnd()
{
    if (_glEnd == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEnd = dlsym(handle, "glEnd");
            dlclose(handle);
        }
    }
    
    _glEnd();
}

// -- glVertex2d
void (*_glVertex2d)() = NULL;
            
void glVertex2d( GLdouble x, GLdouble y )
{
    if (_glVertex2d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex2d = dlsym(handle, "glVertex2d");
            dlclose(handle);
        }
    }
    
    _glVertex2d(x, y);
}

// -- glVertex2f
void (*_glVertex2f)() = NULL;
            
void glVertex2f( GLfloat x, GLfloat y )
{
    if (_glVertex2f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex2f = dlsym(handle, "glVertex2f");
            dlclose(handle);
        }
    }
    
    _glVertex2f(x, y);
}

// -- glVertex2i
void (*_glVertex2i)() = NULL;
            
void glVertex2i( GLint x, GLint y )
{
    if (_glVertex2i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex2i = dlsym(handle, "glVertex2i");
            dlclose(handle);
        }
    }
    
    _glVertex2i(x, y);
}

// -- glVertex2s
void (*_glVertex2s)() = NULL;
            
void glVertex2s( GLshort x, GLshort y )
{
    if (_glVertex2s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex2s = dlsym(handle, "glVertex2s");
            dlclose(handle);
        }
    }
    
    _glVertex2s(x, y);
}

// -- glVertex3d
void (*_glVertex3d)() = NULL;
            
void glVertex3d( GLdouble x, GLdouble y, GLdouble z )
{
    if (_glVertex3d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex3d = dlsym(handle, "glVertex3d");
            dlclose(handle);
        }
    }
    
    _glVertex3d(x, y, z);
}

// -- glVertex3f
void (*_glVertex3f)() = NULL;
            
void glVertex3f( GLfloat x, GLfloat y, GLfloat z )
{
    if (_glVertex3f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex3f = dlsym(handle, "glVertex3f");
            dlclose(handle);
        }
    }
    
    _glVertex3f(x, y, z);
}

// -- glVertex3i
void (*_glVertex3i)() = NULL;
            
void glVertex3i( GLint x, GLint y, GLint z )
{
    if (_glVertex3i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex3i = dlsym(handle, "glVertex3i");
            dlclose(handle);
        }
    }
    
    _glVertex3i(x, y, z);
}

// -- glVertex3s
void (*_glVertex3s)() = NULL;
            
void glVertex3s( GLshort x, GLshort y, GLshort z )
{
    if (_glVertex3s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex3s = dlsym(handle, "glVertex3s");
            dlclose(handle);
        }
    }
    
    _glVertex3s(x, y, z);
}

// -- glVertex4d
void (*_glVertex4d)() = NULL;
            
void glVertex4d( GLdouble x, GLdouble y, GLdouble z, GLdouble w )
{
    if (_glVertex4d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex4d = dlsym(handle, "glVertex4d");
            dlclose(handle);
        }
    }
    
    _glVertex4d(x, y, z, w);
}

// -- glVertex4f
void (*_glVertex4f)() = NULL;
            
void glVertex4f( GLfloat x, GLfloat y, GLfloat z, GLfloat w )
{
    if (_glVertex4f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex4f = dlsym(handle, "glVertex4f");
            dlclose(handle);
        }
    }
    
    _glVertex4f(x, y, z, w);
}

// -- glVertex4i
void (*_glVertex4i)() = NULL;
            
void glVertex4i( GLint x, GLint y, GLint z, GLint w )
{
    if (_glVertex4i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex4i = dlsym(handle, "glVertex4i");
            dlclose(handle);
        }
    }
    
    _glVertex4i(x, y, z, w);
}

// -- glVertex4s
void (*_glVertex4s)() = NULL;
            
void glVertex4s( GLshort x, GLshort y, GLshort z, GLshort w )
{
    if (_glVertex4s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex4s = dlsym(handle, "glVertex4s");
            dlclose(handle);
        }
    }
    
    _glVertex4s(x, y, z, w);
}

// -- glVertex2dv
void (*_glVertex2dv)() = NULL;
            
void glVertex2dv( const GLdouble *v )
{
    if (_glVertex2dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex2dv = dlsym(handle, "glVertex2dv");
            dlclose(handle);
        }
    }
    
    _glVertex2dv(*v);
}

// -- glVertex2fv
void (*_glVertex2fv)() = NULL;
            
void glVertex2fv( const GLfloat *v )
{
    if (_glVertex2fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex2fv = dlsym(handle, "glVertex2fv");
            dlclose(handle);
        }
    }
    
    _glVertex2fv(*v);
}

// -- glVertex2iv
void (*_glVertex2iv)() = NULL;
            
void glVertex2iv( const GLint *v )
{
    if (_glVertex2iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex2iv = dlsym(handle, "glVertex2iv");
            dlclose(handle);
        }
    }
    
    _glVertex2iv(*v);
}

// -- glVertex2sv
void (*_glVertex2sv)() = NULL;
            
void glVertex2sv( const GLshort *v )
{
    if (_glVertex2sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex2sv = dlsym(handle, "glVertex2sv");
            dlclose(handle);
        }
    }
    
    _glVertex2sv(*v);
}

// -- glVertex3dv
void (*_glVertex3dv)() = NULL;
            
void glVertex3dv( const GLdouble *v )
{
    if (_glVertex3dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex3dv = dlsym(handle, "glVertex3dv");
            dlclose(handle);
        }
    }
    
    _glVertex3dv(*v);
}

// -- glVertex3fv
void (*_glVertex3fv)() = NULL;
            
void glVertex3fv( const GLfloat *v )
{
    if (_glVertex3fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex3fv = dlsym(handle, "glVertex3fv");
            dlclose(handle);
        }
    }
    
    _glVertex3fv(*v);
}

// -- glVertex3iv
void (*_glVertex3iv)() = NULL;
            
void glVertex3iv( const GLint *v )
{
    if (_glVertex3iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex3iv = dlsym(handle, "glVertex3iv");
            dlclose(handle);
        }
    }
    
    _glVertex3iv(*v);
}

// -- glVertex3sv
void (*_glVertex3sv)() = NULL;
            
void glVertex3sv( const GLshort *v )
{
    if (_glVertex3sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex3sv = dlsym(handle, "glVertex3sv");
            dlclose(handle);
        }
    }
    
    _glVertex3sv(*v);
}

// -- glVertex4dv
void (*_glVertex4dv)() = NULL;
            
void glVertex4dv( const GLdouble *v )
{
    if (_glVertex4dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex4dv = dlsym(handle, "glVertex4dv");
            dlclose(handle);
        }
    }
    
    _glVertex4dv(*v);
}

// -- glVertex4fv
void (*_glVertex4fv)() = NULL;
            
void glVertex4fv( const GLfloat *v )
{
    if (_glVertex4fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex4fv = dlsym(handle, "glVertex4fv");
            dlclose(handle);
        }
    }
    
    _glVertex4fv(*v);
}

// -- glVertex4iv
void (*_glVertex4iv)() = NULL;
            
void glVertex4iv( const GLint *v )
{
    if (_glVertex4iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex4iv = dlsym(handle, "glVertex4iv");
            dlclose(handle);
        }
    }
    
    _glVertex4iv(*v);
}

// -- glVertex4sv
void (*_glVertex4sv)() = NULL;
            
void glVertex4sv( const GLshort *v )
{
    if (_glVertex4sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertex4sv = dlsym(handle, "glVertex4sv");
            dlclose(handle);
        }
    }
    
    _glVertex4sv(*v);
}

// -- glNormal3b
void (*_glNormal3b)() = NULL;
            
void glNormal3b( GLbyte nx, GLbyte ny, GLbyte nz )
{
    if (_glNormal3b == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNormal3b = dlsym(handle, "glNormal3b");
            dlclose(handle);
        }
    }
    
    _glNormal3b(nx, ny, nz);
}

// -- glNormal3d
void (*_glNormal3d)() = NULL;
            
void glNormal3d( GLdouble nx, GLdouble ny, GLdouble nz )
{
    if (_glNormal3d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNormal3d = dlsym(handle, "glNormal3d");
            dlclose(handle);
        }
    }
    
    _glNormal3d(nx, ny, nz);
}

// -- glNormal3f
void (*_glNormal3f)() = NULL;
            
void glNormal3f( GLfloat nx, GLfloat ny, GLfloat nz )
{
    if (_glNormal3f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNormal3f = dlsym(handle, "glNormal3f");
            dlclose(handle);
        }
    }
    
    _glNormal3f(nx, ny, nz);
}

// -- glNormal3i
void (*_glNormal3i)() = NULL;
            
void glNormal3i( GLint nx, GLint ny, GLint nz )
{
    if (_glNormal3i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNormal3i = dlsym(handle, "glNormal3i");
            dlclose(handle);
        }
    }
    
    _glNormal3i(nx, ny, nz);
}

// -- glNormal3s
void (*_glNormal3s)() = NULL;
            
void glNormal3s( GLshort nx, GLshort ny, GLshort nz )
{
    if (_glNormal3s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNormal3s = dlsym(handle, "glNormal3s");
            dlclose(handle);
        }
    }
    
    _glNormal3s(nx, ny, nz);
}

// -- glNormal3bv
void (*_glNormal3bv)() = NULL;
            
void glNormal3bv( const GLbyte *v )
{
    if (_glNormal3bv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNormal3bv = dlsym(handle, "glNormal3bv");
            dlclose(handle);
        }
    }
    
    _glNormal3bv(*v);
}

// -- glNormal3dv
void (*_glNormal3dv)() = NULL;
            
void glNormal3dv( const GLdouble *v )
{
    if (_glNormal3dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNormal3dv = dlsym(handle, "glNormal3dv");
            dlclose(handle);
        }
    }
    
    _glNormal3dv(*v);
}

// -- glNormal3fv
void (*_glNormal3fv)() = NULL;
            
void glNormal3fv( const GLfloat *v )
{
    if (_glNormal3fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNormal3fv = dlsym(handle, "glNormal3fv");
            dlclose(handle);
        }
    }
    
    _glNormal3fv(*v);
}

// -- glNormal3iv
void (*_glNormal3iv)() = NULL;
            
void glNormal3iv( const GLint *v )
{
    if (_glNormal3iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNormal3iv = dlsym(handle, "glNormal3iv");
            dlclose(handle);
        }
    }
    
    _glNormal3iv(*v);
}

// -- glNormal3sv
void (*_glNormal3sv)() = NULL;
            
void glNormal3sv( const GLshort *v )
{
    if (_glNormal3sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNormal3sv = dlsym(handle, "glNormal3sv");
            dlclose(handle);
        }
    }
    
    _glNormal3sv(*v);
}

// -- glIndexd
void (*_glIndexd)() = NULL;
            
void glIndexd( GLdouble c )
{
    if (_glIndexd == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexd = dlsym(handle, "glIndexd");
            dlclose(handle);
        }
    }
    
    _glIndexd(c);
}

// -- glIndexf
void (*_glIndexf)() = NULL;
            
void glIndexf( GLfloat c )
{
    if (_glIndexf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexf = dlsym(handle, "glIndexf");
            dlclose(handle);
        }
    }
    
    _glIndexf(c);
}

// -- glIndexi
void (*_glIndexi)() = NULL;
            
void glIndexi( GLint c )
{
    if (_glIndexi == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexi = dlsym(handle, "glIndexi");
            dlclose(handle);
        }
    }
    
    _glIndexi(c);
}

// -- glIndexs
void (*_glIndexs)() = NULL;
            
void glIndexs( GLshort c )
{
    if (_glIndexs == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexs = dlsym(handle, "glIndexs");
            dlclose(handle);
        }
    }
    
    _glIndexs(c);
}

// -- glIndexub
void (*_glIndexub)() = NULL;
            
void glIndexub( GLubyte c )
{
    if (_glIndexub == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexub = dlsym(handle, "glIndexub");
            dlclose(handle);
        }
    }
    
    _glIndexub(c);
}

// -- glIndexdv
void (*_glIndexdv)() = NULL;
            
void glIndexdv( const GLdouble *c )
{
    if (_glIndexdv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexdv = dlsym(handle, "glIndexdv");
            dlclose(handle);
        }
    }
    
    _glIndexdv(*c);
}

// -- glIndexfv
void (*_glIndexfv)() = NULL;
            
void glIndexfv( const GLfloat *c )
{
    if (_glIndexfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexfv = dlsym(handle, "glIndexfv");
            dlclose(handle);
        }
    }
    
    _glIndexfv(*c);
}

// -- glIndexiv
void (*_glIndexiv)() = NULL;
            
void glIndexiv( const GLint *c )
{
    if (_glIndexiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexiv = dlsym(handle, "glIndexiv");
            dlclose(handle);
        }
    }
    
    _glIndexiv(*c);
}

// -- glIndexsv
void (*_glIndexsv)() = NULL;
            
void glIndexsv( const GLshort *c )
{
    if (_glIndexsv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexsv = dlsym(handle, "glIndexsv");
            dlclose(handle);
        }
    }
    
    _glIndexsv(*c);
}

// -- glIndexubv
void (*_glIndexubv)() = NULL;
            
void glIndexubv( const GLubyte *c )
{
    if (_glIndexubv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexubv = dlsym(handle, "glIndexubv");
            dlclose(handle);
        }
    }
    
    _glIndexubv(*c);
}

// -- glColor3b
void (*_glColor3b)() = NULL;
            
void glColor3b( GLbyte red, GLbyte green, GLbyte blue )
{
    if (_glColor3b == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3b = dlsym(handle, "glColor3b");
            dlclose(handle);
        }
    }
    
    _glColor3b(red, green, blue);
}

// -- glColor3d
void (*_glColor3d)() = NULL;
            
void glColor3d( GLdouble red, GLdouble green, GLdouble blue )
{
    if (_glColor3d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3d = dlsym(handle, "glColor3d");
            dlclose(handle);
        }
    }
    
    _glColor3d(red, green, blue);
}

// -- glColor3f
void (*_glColor3f)() = NULL;
            
void glColor3f( GLfloat red, GLfloat green, GLfloat blue )
{
    if (_glColor3f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3f = dlsym(handle, "glColor3f");
            dlclose(handle);
        }
    }
    
    _glColor3f(red, green, blue);
}

// -- glColor3i
void (*_glColor3i)() = NULL;
            
void glColor3i( GLint red, GLint green, GLint blue )
{
    if (_glColor3i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3i = dlsym(handle, "glColor3i");
            dlclose(handle);
        }
    }
    
    _glColor3i(red, green, blue);
}

// -- glColor3s
void (*_glColor3s)() = NULL;
            
void glColor3s( GLshort red, GLshort green, GLshort blue )
{
    if (_glColor3s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3s = dlsym(handle, "glColor3s");
            dlclose(handle);
        }
    }
    
    _glColor3s(red, green, blue);
}

// -- glColor3ub
void (*_glColor3ub)() = NULL;
            
void glColor3ub( GLubyte red, GLubyte green, GLubyte blue )
{
    if (_glColor3ub == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3ub = dlsym(handle, "glColor3ub");
            dlclose(handle);
        }
    }
    
    _glColor3ub(red, green, blue);
}

// -- glColor3ui
void (*_glColor3ui)() = NULL;
            
void glColor3ui( GLuint red, GLuint green, GLuint blue )
{
    if (_glColor3ui == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3ui = dlsym(handle, "glColor3ui");
            dlclose(handle);
        }
    }
    
    _glColor3ui(red, green, blue);
}

// -- glColor3us
void (*_glColor3us)() = NULL;
            
void glColor3us( GLushort red, GLushort green, GLushort blue )
{
    if (_glColor3us == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3us = dlsym(handle, "glColor3us");
            dlclose(handle);
        }
    }
    
    _glColor3us(red, green, blue);
}

// -- glColor4b
void (*_glColor4b)() = NULL;
            
void glColor4b( GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha )
{
    if (_glColor4b == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4b = dlsym(handle, "glColor4b");
            dlclose(handle);
        }
    }
    
    _glColor4b(red, green, blue, alpha);
}

// -- glColor4d
void (*_glColor4d)() = NULL;
            
void glColor4d( GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha )
{
    if (_glColor4d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4d = dlsym(handle, "glColor4d");
            dlclose(handle);
        }
    }
    
    _glColor4d(red, green, blue, alpha);
}

// -- glColor4f
void (*_glColor4f)() = NULL;
            
void glColor4f( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha )
{
    if (_glColor4f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4f = dlsym(handle, "glColor4f");
            dlclose(handle);
        }
    }
    
    _glColor4f(red, green, blue, alpha);
}

// -- glColor4i
void (*_glColor4i)() = NULL;
            
void glColor4i( GLint red, GLint green, GLint blue, GLint alpha )
{
    if (_glColor4i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4i = dlsym(handle, "glColor4i");
            dlclose(handle);
        }
    }
    
    _glColor4i(red, green, blue, alpha);
}

// -- glColor4s
void (*_glColor4s)() = NULL;
            
void glColor4s( GLshort red, GLshort green, GLshort blue, GLshort alpha )
{
    if (_glColor4s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4s = dlsym(handle, "glColor4s");
            dlclose(handle);
        }
    }
    
    _glColor4s(red, green, blue, alpha);
}

// -- glColor4ub
void (*_glColor4ub)() = NULL;
            
void glColor4ub( GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha )
{
    if (_glColor4ub == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4ub = dlsym(handle, "glColor4ub");
            dlclose(handle);
        }
    }
    
    _glColor4ub(red, green, blue, alpha);
}

// -- glColor4ui
void (*_glColor4ui)() = NULL;
            
void glColor4ui( GLuint red, GLuint green, GLuint blue, GLuint alpha )
{
    if (_glColor4ui == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4ui = dlsym(handle, "glColor4ui");
            dlclose(handle);
        }
    }
    
    _glColor4ui(red, green, blue, alpha);
}

// -- glColor4us
void (*_glColor4us)() = NULL;
            
void glColor4us( GLushort red, GLushort green, GLushort blue, GLushort alpha )
{
    if (_glColor4us == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4us = dlsym(handle, "glColor4us");
            dlclose(handle);
        }
    }
    
    _glColor4us(red, green, blue, alpha);
}

// -- glColor3bv
void (*_glColor3bv)() = NULL;
            
void glColor3bv( const GLbyte *v )
{
    if (_glColor3bv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3bv = dlsym(handle, "glColor3bv");
            dlclose(handle);
        }
    }
    
    _glColor3bv(*v);
}

// -- glColor3dv
void (*_glColor3dv)() = NULL;
            
void glColor3dv( const GLdouble *v )
{
    if (_glColor3dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3dv = dlsym(handle, "glColor3dv");
            dlclose(handle);
        }
    }
    
    _glColor3dv(*v);
}

// -- glColor3fv
void (*_glColor3fv)() = NULL;
            
void glColor3fv( const GLfloat *v )
{
    if (_glColor3fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3fv = dlsym(handle, "glColor3fv");
            dlclose(handle);
        }
    }
    
    _glColor3fv(*v);
}

// -- glColor3iv
void (*_glColor3iv)() = NULL;
            
void glColor3iv( const GLint *v )
{
    if (_glColor3iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3iv = dlsym(handle, "glColor3iv");
            dlclose(handle);
        }
    }
    
    _glColor3iv(*v);
}

// -- glColor3sv
void (*_glColor3sv)() = NULL;
            
void glColor3sv( const GLshort *v )
{
    if (_glColor3sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3sv = dlsym(handle, "glColor3sv");
            dlclose(handle);
        }
    }
    
    _glColor3sv(*v);
}

// -- glColor3ubv
void (*_glColor3ubv)() = NULL;
            
void glColor3ubv( const GLubyte *v )
{
    if (_glColor3ubv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3ubv = dlsym(handle, "glColor3ubv");
            dlclose(handle);
        }
    }
    
    _glColor3ubv(*v);
}

// -- glColor3uiv
void (*_glColor3uiv)() = NULL;
            
void glColor3uiv( const GLuint *v )
{
    if (_glColor3uiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3uiv = dlsym(handle, "glColor3uiv");
            dlclose(handle);
        }
    }
    
    _glColor3uiv(*v);
}

// -- glColor3usv
void (*_glColor3usv)() = NULL;
            
void glColor3usv( const GLushort *v )
{
    if (_glColor3usv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor3usv = dlsym(handle, "glColor3usv");
            dlclose(handle);
        }
    }
    
    _glColor3usv(*v);
}

// -- glColor4bv
void (*_glColor4bv)() = NULL;
            
void glColor4bv( const GLbyte *v )
{
    if (_glColor4bv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4bv = dlsym(handle, "glColor4bv");
            dlclose(handle);
        }
    }
    
    _glColor4bv(*v);
}

// -- glColor4dv
void (*_glColor4dv)() = NULL;
            
void glColor4dv( const GLdouble *v )
{
    if (_glColor4dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4dv = dlsym(handle, "glColor4dv");
            dlclose(handle);
        }
    }
    
    _glColor4dv(*v);
}

// -- glColor4fv
void (*_glColor4fv)() = NULL;
            
void glColor4fv( const GLfloat *v )
{
    if (_glColor4fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4fv = dlsym(handle, "glColor4fv");
            dlclose(handle);
        }
    }
    
    _glColor4fv(*v);
}

// -- glColor4iv
void (*_glColor4iv)() = NULL;
            
void glColor4iv( const GLint *v )
{
    if (_glColor4iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4iv = dlsym(handle, "glColor4iv");
            dlclose(handle);
        }
    }
    
    _glColor4iv(*v);
}

// -- glColor4sv
void (*_glColor4sv)() = NULL;
            
void glColor4sv( const GLshort *v )
{
    if (_glColor4sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4sv = dlsym(handle, "glColor4sv");
            dlclose(handle);
        }
    }
    
    _glColor4sv(*v);
}

// -- glColor4ubv
void (*_glColor4ubv)() = NULL;
            
void glColor4ubv( const GLubyte *v )
{
    if (_glColor4ubv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4ubv = dlsym(handle, "glColor4ubv");
            dlclose(handle);
        }
    }
    
    _glColor4ubv(*v);
}

// -- glColor4uiv
void (*_glColor4uiv)() = NULL;
            
void glColor4uiv( const GLuint *v )
{
    if (_glColor4uiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4uiv = dlsym(handle, "glColor4uiv");
            dlclose(handle);
        }
    }
    
    _glColor4uiv(*v);
}

// -- glColor4usv
void (*_glColor4usv)() = NULL;
            
void glColor4usv( const GLushort *v )
{
    if (_glColor4usv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColor4usv = dlsym(handle, "glColor4usv");
            dlclose(handle);
        }
    }
    
    _glColor4usv(*v);
}

// -- glTexCoord1d
void (*_glTexCoord1d)() = NULL;
            
void glTexCoord1d( GLdouble s )
{
    if (_glTexCoord1d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord1d = dlsym(handle, "glTexCoord1d");
            dlclose(handle);
        }
    }
    
    _glTexCoord1d(s);
}

// -- glTexCoord1f
void (*_glTexCoord1f)() = NULL;
            
void glTexCoord1f( GLfloat s )
{
    if (_glTexCoord1f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord1f = dlsym(handle, "glTexCoord1f");
            dlclose(handle);
        }
    }
    
    _glTexCoord1f(s);
}

// -- glTexCoord1i
void (*_glTexCoord1i)() = NULL;
            
void glTexCoord1i( GLint s )
{
    if (_glTexCoord1i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord1i = dlsym(handle, "glTexCoord1i");
            dlclose(handle);
        }
    }
    
    _glTexCoord1i(s);
}

// -- glTexCoord1s
void (*_glTexCoord1s)() = NULL;
            
void glTexCoord1s( GLshort s )
{
    if (_glTexCoord1s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord1s = dlsym(handle, "glTexCoord1s");
            dlclose(handle);
        }
    }
    
    _glTexCoord1s(s);
}

// -- glTexCoord2d
void (*_glTexCoord2d)() = NULL;
            
void glTexCoord2d( GLdouble s, GLdouble t )
{
    if (_glTexCoord2d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord2d = dlsym(handle, "glTexCoord2d");
            dlclose(handle);
        }
    }
    
    _glTexCoord2d(s, t);
}

// -- glTexCoord2f
void (*_glTexCoord2f)() = NULL;
            
void glTexCoord2f( GLfloat s, GLfloat t )
{
    if (_glTexCoord2f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord2f = dlsym(handle, "glTexCoord2f");
            dlclose(handle);
        }
    }
    
    _glTexCoord2f(s, t);
}

// -- glTexCoord2i
void (*_glTexCoord2i)() = NULL;
            
void glTexCoord2i( GLint s, GLint t )
{
    if (_glTexCoord2i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord2i = dlsym(handle, "glTexCoord2i");
            dlclose(handle);
        }
    }
    
    _glTexCoord2i(s, t);
}

// -- glTexCoord2s
void (*_glTexCoord2s)() = NULL;
            
void glTexCoord2s( GLshort s, GLshort t )
{
    if (_glTexCoord2s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord2s = dlsym(handle, "glTexCoord2s");
            dlclose(handle);
        }
    }
    
    _glTexCoord2s(s, t);
}

// -- glTexCoord3d
void (*_glTexCoord3d)() = NULL;
            
void glTexCoord3d( GLdouble s, GLdouble t, GLdouble r )
{
    if (_glTexCoord3d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord3d = dlsym(handle, "glTexCoord3d");
            dlclose(handle);
        }
    }
    
    _glTexCoord3d(s, t, r);
}

// -- glTexCoord3f
void (*_glTexCoord3f)() = NULL;
            
void glTexCoord3f( GLfloat s, GLfloat t, GLfloat r )
{
    if (_glTexCoord3f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord3f = dlsym(handle, "glTexCoord3f");
            dlclose(handle);
        }
    }
    
    _glTexCoord3f(s, t, r);
}

// -- glTexCoord3i
void (*_glTexCoord3i)() = NULL;
            
void glTexCoord3i( GLint s, GLint t, GLint r )
{
    if (_glTexCoord3i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord3i = dlsym(handle, "glTexCoord3i");
            dlclose(handle);
        }
    }
    
    _glTexCoord3i(s, t, r);
}

// -- glTexCoord3s
void (*_glTexCoord3s)() = NULL;
            
void glTexCoord3s( GLshort s, GLshort t, GLshort r )
{
    if (_glTexCoord3s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord3s = dlsym(handle, "glTexCoord3s");
            dlclose(handle);
        }
    }
    
    _glTexCoord3s(s, t, r);
}

// -- glTexCoord4d
void (*_glTexCoord4d)() = NULL;
            
void glTexCoord4d( GLdouble s, GLdouble t, GLdouble r, GLdouble q )
{
    if (_glTexCoord4d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord4d = dlsym(handle, "glTexCoord4d");
            dlclose(handle);
        }
    }
    
    _glTexCoord4d(s, t, r, q);
}

// -- glTexCoord4f
void (*_glTexCoord4f)() = NULL;
            
void glTexCoord4f( GLfloat s, GLfloat t, GLfloat r, GLfloat q )
{
    if (_glTexCoord4f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord4f = dlsym(handle, "glTexCoord4f");
            dlclose(handle);
        }
    }
    
    _glTexCoord4f(s, t, r, q);
}

// -- glTexCoord4i
void (*_glTexCoord4i)() = NULL;
            
void glTexCoord4i( GLint s, GLint t, GLint r, GLint q )
{
    if (_glTexCoord4i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord4i = dlsym(handle, "glTexCoord4i");
            dlclose(handle);
        }
    }
    
    _glTexCoord4i(s, t, r, q);
}

// -- glTexCoord4s
void (*_glTexCoord4s)() = NULL;
            
void glTexCoord4s( GLshort s, GLshort t, GLshort r, GLshort q )
{
    if (_glTexCoord4s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord4s = dlsym(handle, "glTexCoord4s");
            dlclose(handle);
        }
    }
    
    _glTexCoord4s(s, t, r, q);
}

// -- glTexCoord1dv
void (*_glTexCoord1dv)() = NULL;
            
void glTexCoord1dv( const GLdouble *v )
{
    if (_glTexCoord1dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord1dv = dlsym(handle, "glTexCoord1dv");
            dlclose(handle);
        }
    }
    
    _glTexCoord1dv(*v);
}

// -- glTexCoord1fv
void (*_glTexCoord1fv)() = NULL;
            
void glTexCoord1fv( const GLfloat *v )
{
    if (_glTexCoord1fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord1fv = dlsym(handle, "glTexCoord1fv");
            dlclose(handle);
        }
    }
    
    _glTexCoord1fv(*v);
}

// -- glTexCoord1iv
void (*_glTexCoord1iv)() = NULL;
            
void glTexCoord1iv( const GLint *v )
{
    if (_glTexCoord1iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord1iv = dlsym(handle, "glTexCoord1iv");
            dlclose(handle);
        }
    }
    
    _glTexCoord1iv(*v);
}

// -- glTexCoord1sv
void (*_glTexCoord1sv)() = NULL;
            
void glTexCoord1sv( const GLshort *v )
{
    if (_glTexCoord1sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord1sv = dlsym(handle, "glTexCoord1sv");
            dlclose(handle);
        }
    }
    
    _glTexCoord1sv(*v);
}

// -- glTexCoord2dv
void (*_glTexCoord2dv)() = NULL;
            
void glTexCoord2dv( const GLdouble *v )
{
    if (_glTexCoord2dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord2dv = dlsym(handle, "glTexCoord2dv");
            dlclose(handle);
        }
    }
    
    _glTexCoord2dv(*v);
}

// -- glTexCoord2fv
void (*_glTexCoord2fv)() = NULL;
            
void glTexCoord2fv( const GLfloat *v )
{
    if (_glTexCoord2fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord2fv = dlsym(handle, "glTexCoord2fv");
            dlclose(handle);
        }
    }
    
    _glTexCoord2fv(*v);
}

// -- glTexCoord2iv
void (*_glTexCoord2iv)() = NULL;
            
void glTexCoord2iv( const GLint *v )
{
    if (_glTexCoord2iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord2iv = dlsym(handle, "glTexCoord2iv");
            dlclose(handle);
        }
    }
    
    _glTexCoord2iv(*v);
}

// -- glTexCoord2sv
void (*_glTexCoord2sv)() = NULL;
            
void glTexCoord2sv( const GLshort *v )
{
    if (_glTexCoord2sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord2sv = dlsym(handle, "glTexCoord2sv");
            dlclose(handle);
        }
    }
    
    _glTexCoord2sv(*v);
}

// -- glTexCoord3dv
void (*_glTexCoord3dv)() = NULL;
            
void glTexCoord3dv( const GLdouble *v )
{
    if (_glTexCoord3dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord3dv = dlsym(handle, "glTexCoord3dv");
            dlclose(handle);
        }
    }
    
    _glTexCoord3dv(*v);
}

// -- glTexCoord3fv
void (*_glTexCoord3fv)() = NULL;
            
void glTexCoord3fv( const GLfloat *v )
{
    if (_glTexCoord3fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord3fv = dlsym(handle, "glTexCoord3fv");
            dlclose(handle);
        }
    }
    
    _glTexCoord3fv(*v);
}

// -- glTexCoord3iv
void (*_glTexCoord3iv)() = NULL;
            
void glTexCoord3iv( const GLint *v )
{
    if (_glTexCoord3iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord3iv = dlsym(handle, "glTexCoord3iv");
            dlclose(handle);
        }
    }
    
    _glTexCoord3iv(*v);
}

// -- glTexCoord3sv
void (*_glTexCoord3sv)() = NULL;
            
void glTexCoord3sv( const GLshort *v )
{
    if (_glTexCoord3sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord3sv = dlsym(handle, "glTexCoord3sv");
            dlclose(handle);
        }
    }
    
    _glTexCoord3sv(*v);
}

// -- glTexCoord4dv
void (*_glTexCoord4dv)() = NULL;
            
void glTexCoord4dv( const GLdouble *v )
{
    if (_glTexCoord4dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord4dv = dlsym(handle, "glTexCoord4dv");
            dlclose(handle);
        }
    }
    
    _glTexCoord4dv(*v);
}

// -- glTexCoord4fv
void (*_glTexCoord4fv)() = NULL;
            
void glTexCoord4fv( const GLfloat *v )
{
    if (_glTexCoord4fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord4fv = dlsym(handle, "glTexCoord4fv");
            dlclose(handle);
        }
    }
    
    _glTexCoord4fv(*v);
}

// -- glTexCoord4iv
void (*_glTexCoord4iv)() = NULL;
            
void glTexCoord4iv( const GLint *v )
{
    if (_glTexCoord4iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord4iv = dlsym(handle, "glTexCoord4iv");
            dlclose(handle);
        }
    }
    
    _glTexCoord4iv(*v);
}

// -- glTexCoord4sv
void (*_glTexCoord4sv)() = NULL;
            
void glTexCoord4sv( const GLshort *v )
{
    if (_glTexCoord4sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoord4sv = dlsym(handle, "glTexCoord4sv");
            dlclose(handle);
        }
    }
    
    _glTexCoord4sv(*v);
}

// -- glRasterPos2d
void (*_glRasterPos2d)() = NULL;
            
void glRasterPos2d( GLdouble x, GLdouble y )
{
    if (_glRasterPos2d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos2d = dlsym(handle, "glRasterPos2d");
            dlclose(handle);
        }
    }
    
    _glRasterPos2d(x, y);
}

// -- glRasterPos2f
void (*_glRasterPos2f)() = NULL;
            
void glRasterPos2f( GLfloat x, GLfloat y )
{
    if (_glRasterPos2f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos2f = dlsym(handle, "glRasterPos2f");
            dlclose(handle);
        }
    }
    
    _glRasterPos2f(x, y);
}

// -- glRasterPos2i
void (*_glRasterPos2i)() = NULL;
            
void glRasterPos2i( GLint x, GLint y )
{
    if (_glRasterPos2i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos2i = dlsym(handle, "glRasterPos2i");
            dlclose(handle);
        }
    }
    
    _glRasterPos2i(x, y);
}

// -- glRasterPos2s
void (*_glRasterPos2s)() = NULL;
            
void glRasterPos2s( GLshort x, GLshort y )
{
    if (_glRasterPos2s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos2s = dlsym(handle, "glRasterPos2s");
            dlclose(handle);
        }
    }
    
    _glRasterPos2s(x, y);
}

// -- glRasterPos3d
void (*_glRasterPos3d)() = NULL;
            
void glRasterPos3d( GLdouble x, GLdouble y, GLdouble z )
{
    if (_glRasterPos3d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos3d = dlsym(handle, "glRasterPos3d");
            dlclose(handle);
        }
    }
    
    _glRasterPos3d(x, y, z);
}

// -- glRasterPos3f
void (*_glRasterPos3f)() = NULL;
            
void glRasterPos3f( GLfloat x, GLfloat y, GLfloat z )
{
    if (_glRasterPos3f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos3f = dlsym(handle, "glRasterPos3f");
            dlclose(handle);
        }
    }
    
    _glRasterPos3f(x, y, z);
}

// -- glRasterPos3i
void (*_glRasterPos3i)() = NULL;
            
void glRasterPos3i( GLint x, GLint y, GLint z )
{
    if (_glRasterPos3i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos3i = dlsym(handle, "glRasterPos3i");
            dlclose(handle);
        }
    }
    
    _glRasterPos3i(x, y, z);
}

// -- glRasterPos3s
void (*_glRasterPos3s)() = NULL;
            
void glRasterPos3s( GLshort x, GLshort y, GLshort z )
{
    if (_glRasterPos3s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos3s = dlsym(handle, "glRasterPos3s");
            dlclose(handle);
        }
    }
    
    _glRasterPos3s(x, y, z);
}

// -- glRasterPos4d
void (*_glRasterPos4d)() = NULL;
            
void glRasterPos4d( GLdouble x, GLdouble y, GLdouble z, GLdouble w )
{
    if (_glRasterPos4d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos4d = dlsym(handle, "glRasterPos4d");
            dlclose(handle);
        }
    }
    
    _glRasterPos4d(x, y, z, w);
}

// -- glRasterPos4f
void (*_glRasterPos4f)() = NULL;
            
void glRasterPos4f( GLfloat x, GLfloat y, GLfloat z, GLfloat w )
{
    if (_glRasterPos4f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos4f = dlsym(handle, "glRasterPos4f");
            dlclose(handle);
        }
    }
    
    _glRasterPos4f(x, y, z, w);
}

// -- glRasterPos4i
void (*_glRasterPos4i)() = NULL;
            
void glRasterPos4i( GLint x, GLint y, GLint z, GLint w )
{
    if (_glRasterPos4i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos4i = dlsym(handle, "glRasterPos4i");
            dlclose(handle);
        }
    }
    
    _glRasterPos4i(x, y, z, w);
}

// -- glRasterPos4s
void (*_glRasterPos4s)() = NULL;
            
void glRasterPos4s( GLshort x, GLshort y, GLshort z, GLshort w )
{
    if (_glRasterPos4s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos4s = dlsym(handle, "glRasterPos4s");
            dlclose(handle);
        }
    }
    
    _glRasterPos4s(x, y, z, w);
}

// -- glRasterPos2dv
void (*_glRasterPos2dv)() = NULL;
            
void glRasterPos2dv( const GLdouble *v )
{
    if (_glRasterPos2dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos2dv = dlsym(handle, "glRasterPos2dv");
            dlclose(handle);
        }
    }
    
    _glRasterPos2dv(*v);
}

// -- glRasterPos2fv
void (*_glRasterPos2fv)() = NULL;
            
void glRasterPos2fv( const GLfloat *v )
{
    if (_glRasterPos2fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos2fv = dlsym(handle, "glRasterPos2fv");
            dlclose(handle);
        }
    }
    
    _glRasterPos2fv(*v);
}

// -- glRasterPos2iv
void (*_glRasterPos2iv)() = NULL;
            
void glRasterPos2iv( const GLint *v )
{
    if (_glRasterPos2iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos2iv = dlsym(handle, "glRasterPos2iv");
            dlclose(handle);
        }
    }
    
    _glRasterPos2iv(*v);
}

// -- glRasterPos2sv
void (*_glRasterPos2sv)() = NULL;
            
void glRasterPos2sv( const GLshort *v )
{
    if (_glRasterPos2sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos2sv = dlsym(handle, "glRasterPos2sv");
            dlclose(handle);
        }
    }
    
    _glRasterPos2sv(*v);
}

// -- glRasterPos3dv
void (*_glRasterPos3dv)() = NULL;
            
void glRasterPos3dv( const GLdouble *v )
{
    if (_glRasterPos3dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos3dv = dlsym(handle, "glRasterPos3dv");
            dlclose(handle);
        }
    }
    
    _glRasterPos3dv(*v);
}

// -- glRasterPos3fv
void (*_glRasterPos3fv)() = NULL;
            
void glRasterPos3fv( const GLfloat *v )
{
    if (_glRasterPos3fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos3fv = dlsym(handle, "glRasterPos3fv");
            dlclose(handle);
        }
    }
    
    _glRasterPos3fv(*v);
}

// -- glRasterPos3iv
void (*_glRasterPos3iv)() = NULL;
            
void glRasterPos3iv( const GLint *v )
{
    if (_glRasterPos3iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos3iv = dlsym(handle, "glRasterPos3iv");
            dlclose(handle);
        }
    }
    
    _glRasterPos3iv(*v);
}

// -- glRasterPos3sv
void (*_glRasterPos3sv)() = NULL;
            
void glRasterPos3sv( const GLshort *v )
{
    if (_glRasterPos3sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos3sv = dlsym(handle, "glRasterPos3sv");
            dlclose(handle);
        }
    }
    
    _glRasterPos3sv(*v);
}

// -- glRasterPos4dv
void (*_glRasterPos4dv)() = NULL;
            
void glRasterPos4dv( const GLdouble *v )
{
    if (_glRasterPos4dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos4dv = dlsym(handle, "glRasterPos4dv");
            dlclose(handle);
        }
    }
    
    _glRasterPos4dv(*v);
}

// -- glRasterPos4fv
void (*_glRasterPos4fv)() = NULL;
            
void glRasterPos4fv( const GLfloat *v )
{
    if (_glRasterPos4fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos4fv = dlsym(handle, "glRasterPos4fv");
            dlclose(handle);
        }
    }
    
    _glRasterPos4fv(*v);
}

// -- glRasterPos4iv
void (*_glRasterPos4iv)() = NULL;
            
void glRasterPos4iv( const GLint *v )
{
    if (_glRasterPos4iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos4iv = dlsym(handle, "glRasterPos4iv");
            dlclose(handle);
        }
    }
    
    _glRasterPos4iv(*v);
}

// -- glRasterPos4sv
void (*_glRasterPos4sv)() = NULL;
            
void glRasterPos4sv( const GLshort *v )
{
    if (_glRasterPos4sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRasterPos4sv = dlsym(handle, "glRasterPos4sv");
            dlclose(handle);
        }
    }
    
    _glRasterPos4sv(*v);
}

// -- glRectd
void (*_glRectd)() = NULL;
            
void glRectd( GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2 )
{
    if (_glRectd == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRectd = dlsym(handle, "glRectd");
            dlclose(handle);
        }
    }
    
    _glRectd(x1, y1, x2, y2);
}

// -- glRectf
void (*_glRectf)() = NULL;
            
void glRectf( GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2 )
{
    if (_glRectf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRectf = dlsym(handle, "glRectf");
            dlclose(handle);
        }
    }
    
    _glRectf(x1, y1, x2, y2);
}

// -- glRecti
void (*_glRecti)() = NULL;
            
void glRecti( GLint x1, GLint y1, GLint x2, GLint y2 )
{
    if (_glRecti == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRecti = dlsym(handle, "glRecti");
            dlclose(handle);
        }
    }
    
    _glRecti(x1, y1, x2, y2);
}

// -- glRects
void (*_glRects)() = NULL;
            
void glRects( GLshort x1, GLshort y1, GLshort x2, GLshort y2 )
{
    if (_glRects == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRects = dlsym(handle, "glRects");
            dlclose(handle);
        }
    }
    
    _glRects(x1, y1, x2, y2);
}

// -- glRectdv
void (*_glRectdv)() = NULL;
            
void glRectdv( const GLdouble *v1, const GLdouble *v2 )
{
    if (_glRectdv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRectdv = dlsym(handle, "glRectdv");
            dlclose(handle);
        }
    }
    
    _glRectdv(*v1, *v2);
}

// -- glRectfv
void (*_glRectfv)() = NULL;
            
void glRectfv( const GLfloat *v1, const GLfloat *v2 )
{
    if (_glRectfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRectfv = dlsym(handle, "glRectfv");
            dlclose(handle);
        }
    }
    
    _glRectfv(*v1, *v2);
}

// -- glRectiv
void (*_glRectiv)() = NULL;
            
void glRectiv( const GLint *v1, const GLint *v2 )
{
    if (_glRectiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRectiv = dlsym(handle, "glRectiv");
            dlclose(handle);
        }
    }
    
    _glRectiv(*v1, *v2);
}

// -- glRectsv
void (*_glRectsv)() = NULL;
            
void glRectsv( const GLshort *v1, const GLshort *v2 )
{
    if (_glRectsv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glRectsv = dlsym(handle, "glRectsv");
            dlclose(handle);
        }
    }
    
    _glRectsv(*v1, *v2);
}

// -- glVertexPointer
void (*_glVertexPointer)() = NULL;
            
void glVertexPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )
{
    if (_glVertexPointer == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glVertexPointer = dlsym(handle, "glVertexPointer");
            dlclose(handle);
        }
    }
    
    _glVertexPointer(size, type, stride, *ptr);
}

// -- glNormalPointer
void (*_glNormalPointer)() = NULL;
            
void glNormalPointer( GLenum type, GLsizei stride, const GLvoid *ptr )
{
    if (_glNormalPointer == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glNormalPointer = dlsym(handle, "glNormalPointer");
            dlclose(handle);
        }
    }
    
    _glNormalPointer(type, stride, *ptr);
}

// -- glColorPointer
void (*_glColorPointer)() = NULL;
            
void glColorPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )
{
    if (_glColorPointer == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColorPointer = dlsym(handle, "glColorPointer");
            dlclose(handle);
        }
    }
    
    _glColorPointer(size, type, stride, *ptr);
}

// -- glIndexPointer
void (*_glIndexPointer)() = NULL;
            
void glIndexPointer( GLenum type, GLsizei stride, const GLvoid *ptr )
{
    if (_glIndexPointer == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIndexPointer = dlsym(handle, "glIndexPointer");
            dlclose(handle);
        }
    }
    
    _glIndexPointer(type, stride, *ptr);
}

// -- glTexCoordPointer
void (*_glTexCoordPointer)() = NULL;
            
void glTexCoordPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )
{
    if (_glTexCoordPointer == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexCoordPointer = dlsym(handle, "glTexCoordPointer");
            dlclose(handle);
        }
    }
    
    _glTexCoordPointer(size, type, stride, *ptr);
}

// -- glEdgeFlagPointer
void (*_glEdgeFlagPointer)() = NULL;
            
void glEdgeFlagPointer( GLsizei stride, const GLvoid *ptr )
{
    if (_glEdgeFlagPointer == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEdgeFlagPointer = dlsym(handle, "glEdgeFlagPointer");
            dlclose(handle);
        }
    }
    
    _glEdgeFlagPointer(stride, *ptr);
}

// -- glGetPointerv
void (*_glGetPointerv)() = NULL;
            
void glGetPointerv( GLenum pname, GLvoid **params )
{
    if (_glGetPointerv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetPointerv = dlsym(handle, "glGetPointerv");
            dlclose(handle);
        }
    }
    
    _glGetPointerv(pname, **params);
}

// -- glArrayElement
void (*_glArrayElement)() = NULL;
            
void glArrayElement( GLint i )
{
    if (_glArrayElement == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glArrayElement = dlsym(handle, "glArrayElement");
            dlclose(handle);
        }
    }
    
    _glArrayElement(i);
}

// -- glDrawArrays
void (*_glDrawArrays)() = NULL;
            
void glDrawArrays( GLenum mode, GLint first, GLsizei count )
{
    if (_glDrawArrays == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDrawArrays = dlsym(handle, "glDrawArrays");
            dlclose(handle);
        }
    }
    
    _glDrawArrays(mode, first, count);
}

// -- glDrawElements
void (*_glDrawElements)() = NULL;
            
void glDrawElements( GLenum mode, GLsizei count, GLenum type, const GLvoid *indices )
{
    if (_glDrawElements == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDrawElements = dlsym(handle, "glDrawElements");
            dlclose(handle);
        }
    }
    
    _glDrawElements(mode, count, type, *indices);
}

// -- glInterleavedArrays
void (*_glInterleavedArrays)() = NULL;
            
void glInterleavedArrays( GLenum format, GLsizei stride, const GLvoid *pointer )
{
    if (_glInterleavedArrays == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glInterleavedArrays = dlsym(handle, "glInterleavedArrays");
            dlclose(handle);
        }
    }
    
    _glInterleavedArrays(format, stride, *pointer);
}

// -- glShadeModel
void (*_glShadeModel)() = NULL;
            
void glShadeModel( GLenum mode )
{
    if (_glShadeModel == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glShadeModel = dlsym(handle, "glShadeModel");
            dlclose(handle);
        }
    }
    
    _glShadeModel(mode);
}

// -- glLightf
void (*_glLightf)() = NULL;
            
void glLightf( GLenum light, GLenum pname, GLfloat param )
{
    if (_glLightf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLightf = dlsym(handle, "glLightf");
            dlclose(handle);
        }
    }
    
    _glLightf(light, pname, param);
}

// -- glLighti
void (*_glLighti)() = NULL;
            
void glLighti( GLenum light, GLenum pname, GLint param )
{
    if (_glLighti == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLighti = dlsym(handle, "glLighti");
            dlclose(handle);
        }
    }
    
    _glLighti(light, pname, param);
}

// -- glLightfv
void (*_glLightfv)() = NULL;
            
void glLightfv( GLenum light, GLenum pname, const GLfloat *params )
{
    if (_glLightfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLightfv = dlsym(handle, "glLightfv");
            dlclose(handle);
        }
    }
    
    _glLightfv(light, pname, *params);
}

// -- glLightiv
void (*_glLightiv)() = NULL;
            
void glLightiv( GLenum light, GLenum pname, const GLint *params )
{
    if (_glLightiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLightiv = dlsym(handle, "glLightiv");
            dlclose(handle);
        }
    }
    
    _glLightiv(light, pname, *params);
}

// -- glGetLightfv
void (*_glGetLightfv)() = NULL;
            
void glGetLightfv( GLenum light, GLenum pname, GLfloat *params )
{
    if (_glGetLightfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetLightfv = dlsym(handle, "glGetLightfv");
            dlclose(handle);
        }
    }
    
    _glGetLightfv(light, pname, *params);
}

// -- glGetLightiv
void (*_glGetLightiv)() = NULL;
            
void glGetLightiv( GLenum light, GLenum pname, GLint *params )
{
    if (_glGetLightiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetLightiv = dlsym(handle, "glGetLightiv");
            dlclose(handle);
        }
    }
    
    _glGetLightiv(light, pname, *params);
}

// -- glLightModelf
void (*_glLightModelf)() = NULL;
            
void glLightModelf( GLenum pname, GLfloat param )
{
    if (_glLightModelf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLightModelf = dlsym(handle, "glLightModelf");
            dlclose(handle);
        }
    }
    
    _glLightModelf(pname, param);
}

// -- glLightModeli
void (*_glLightModeli)() = NULL;
            
void glLightModeli( GLenum pname, GLint param )
{
    if (_glLightModeli == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLightModeli = dlsym(handle, "glLightModeli");
            dlclose(handle);
        }
    }
    
    _glLightModeli(pname, param);
}

// -- glLightModelfv
void (*_glLightModelfv)() = NULL;
            
void glLightModelfv( GLenum pname, const GLfloat *params )
{
    if (_glLightModelfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLightModelfv = dlsym(handle, "glLightModelfv");
            dlclose(handle);
        }
    }
    
    _glLightModelfv(pname, *params);
}

// -- glLightModeliv
void (*_glLightModeliv)() = NULL;
            
void glLightModeliv( GLenum pname, const GLint *params )
{
    if (_glLightModeliv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLightModeliv = dlsym(handle, "glLightModeliv");
            dlclose(handle);
        }
    }
    
    _glLightModeliv(pname, *params);
}

// -- glMaterialf
void (*_glMaterialf)() = NULL;
            
void glMaterialf( GLenum face, GLenum pname, GLfloat param )
{
    if (_glMaterialf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMaterialf = dlsym(handle, "glMaterialf");
            dlclose(handle);
        }
    }
    
    _glMaterialf(face, pname, param);
}

// -- glMateriali
void (*_glMateriali)() = NULL;
            
void glMateriali( GLenum face, GLenum pname, GLint param )
{
    if (_glMateriali == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMateriali = dlsym(handle, "glMateriali");
            dlclose(handle);
        }
    }
    
    _glMateriali(face, pname, param);
}

// -- glMaterialfv
void (*_glMaterialfv)() = NULL;
            
void glMaterialfv( GLenum face, GLenum pname, const GLfloat *params )
{
    if (_glMaterialfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMaterialfv = dlsym(handle, "glMaterialfv");
            dlclose(handle);
        }
    }
    
    _glMaterialfv(face, pname, *params);
}

// -- glMaterialiv
void (*_glMaterialiv)() = NULL;
            
void glMaterialiv( GLenum face, GLenum pname, const GLint *params )
{
    if (_glMaterialiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMaterialiv = dlsym(handle, "glMaterialiv");
            dlclose(handle);
        }
    }
    
    _glMaterialiv(face, pname, *params);
}

// -- glGetMaterialfv
void (*_glGetMaterialfv)() = NULL;
            
void glGetMaterialfv( GLenum face, GLenum pname, GLfloat *params )
{
    if (_glGetMaterialfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetMaterialfv = dlsym(handle, "glGetMaterialfv");
            dlclose(handle);
        }
    }
    
    _glGetMaterialfv(face, pname, *params);
}

// -- glGetMaterialiv
void (*_glGetMaterialiv)() = NULL;
            
void glGetMaterialiv( GLenum face, GLenum pname, GLint *params )
{
    if (_glGetMaterialiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetMaterialiv = dlsym(handle, "glGetMaterialiv");
            dlclose(handle);
        }
    }
    
    _glGetMaterialiv(face, pname, *params);
}

// -- glColorMaterial
void (*_glColorMaterial)() = NULL;
            
void glColorMaterial( GLenum face, GLenum mode )
{
    if (_glColorMaterial == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColorMaterial = dlsym(handle, "glColorMaterial");
            dlclose(handle);
        }
    }
    
    _glColorMaterial(face, mode);
}

// -- glPixelZoom
void (*_glPixelZoom)() = NULL;
            
void glPixelZoom( GLfloat xfactor, GLfloat yfactor )
{
    if (_glPixelZoom == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPixelZoom = dlsym(handle, "glPixelZoom");
            dlclose(handle);
        }
    }
    
    _glPixelZoom(xfactor, yfactor);
}

// -- glPixelStoref
void (*_glPixelStoref)() = NULL;
            
void glPixelStoref( GLenum pname, GLfloat param )
{
    if (_glPixelStoref == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPixelStoref = dlsym(handle, "glPixelStoref");
            dlclose(handle);
        }
    }
    
    _glPixelStoref(pname, param);
}

// -- glPixelStorei
void (*_glPixelStorei)() = NULL;
            
void glPixelStorei( GLenum pname, GLint param )
{
    if (_glPixelStorei == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPixelStorei = dlsym(handle, "glPixelStorei");
            dlclose(handle);
        }
    }
    
    _glPixelStorei(pname, param);
}

// -- glPixelTransferf
void (*_glPixelTransferf)() = NULL;
            
void glPixelTransferf( GLenum pname, GLfloat param )
{
    if (_glPixelTransferf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPixelTransferf = dlsym(handle, "glPixelTransferf");
            dlclose(handle);
        }
    }
    
    _glPixelTransferf(pname, param);
}

// -- glPixelTransferi
void (*_glPixelTransferi)() = NULL;
            
void glPixelTransferi( GLenum pname, GLint param )
{
    if (_glPixelTransferi == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPixelTransferi = dlsym(handle, "glPixelTransferi");
            dlclose(handle);
        }
    }
    
    _glPixelTransferi(pname, param);
}

// -- glPixelMapfv
void (*_glPixelMapfv)() = NULL;
            
void glPixelMapfv( GLenum map, GLsizei mapsize, const GLfloat *values )
{
    if (_glPixelMapfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPixelMapfv = dlsym(handle, "glPixelMapfv");
            dlclose(handle);
        }
    }
    
    _glPixelMapfv(map, mapsize, *values);
}

// -- glPixelMapuiv
void (*_glPixelMapuiv)() = NULL;
            
void glPixelMapuiv( GLenum map, GLsizei mapsize, const GLuint *values )
{
    if (_glPixelMapuiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPixelMapuiv = dlsym(handle, "glPixelMapuiv");
            dlclose(handle);
        }
    }
    
    _glPixelMapuiv(map, mapsize, *values);
}

// -- glPixelMapusv
void (*_glPixelMapusv)() = NULL;
            
void glPixelMapusv( GLenum map, GLsizei mapsize, const GLushort *values )
{
    if (_glPixelMapusv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPixelMapusv = dlsym(handle, "glPixelMapusv");
            dlclose(handle);
        }
    }
    
    _glPixelMapusv(map, mapsize, *values);
}

// -- glGetPixelMapfv
void (*_glGetPixelMapfv)() = NULL;
            
void glGetPixelMapfv( GLenum map, GLfloat *values )
{
    if (_glGetPixelMapfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetPixelMapfv = dlsym(handle, "glGetPixelMapfv");
            dlclose(handle);
        }
    }
    
    _glGetPixelMapfv(map, *values);
}

// -- glGetPixelMapuiv
void (*_glGetPixelMapuiv)() = NULL;
            
void glGetPixelMapuiv( GLenum map, GLuint *values )
{
    if (_glGetPixelMapuiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetPixelMapuiv = dlsym(handle, "glGetPixelMapuiv");
            dlclose(handle);
        }
    }
    
    _glGetPixelMapuiv(map, *values);
}

// -- glGetPixelMapusv
void (*_glGetPixelMapusv)() = NULL;
            
void glGetPixelMapusv( GLenum map, GLushort *values )
{
    if (_glGetPixelMapusv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetPixelMapusv = dlsym(handle, "glGetPixelMapusv");
            dlclose(handle);
        }
    }
    
    _glGetPixelMapusv(map, *values);
}

// -- glBitmap
void (*_glBitmap)() = NULL;
            
void glBitmap( GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap )
{
    if (_glBitmap == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glBitmap = dlsym(handle, "glBitmap");
            dlclose(handle);
        }
    }
    
    _glBitmap(width, height, xorig, yorig, xmove, ymove, *bitmap);
}

// -- glReadPixels
void (*_glReadPixels)() = NULL;
            
void glReadPixels( GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels )
{
    if (_glReadPixels == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glReadPixels = dlsym(handle, "glReadPixels");
            dlclose(handle);
        }
    }
    
    _glReadPixels(x, y, width, height, format, type, *pixels);
}

// -- glDrawPixels
void (*_glDrawPixels)() = NULL;
            
void glDrawPixels( GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels )
{
    if (_glDrawPixels == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDrawPixels = dlsym(handle, "glDrawPixels");
            dlclose(handle);
        }
    }
    
    _glDrawPixels(width, height, format, type, *pixels);
}

// -- glCopyPixels
void (*_glCopyPixels)() = NULL;
            
void glCopyPixels( GLint x, GLint y, GLsizei width, GLsizei height, GLenum type )
{
    if (_glCopyPixels == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCopyPixels = dlsym(handle, "glCopyPixels");
            dlclose(handle);
        }
    }
    
    _glCopyPixels(x, y, width, height, type);
}

// -- glStencilFunc
void (*_glStencilFunc)() = NULL;
            
void glStencilFunc( GLenum func, GLint ref, GLuint mask )
{
    if (_glStencilFunc == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glStencilFunc = dlsym(handle, "glStencilFunc");
            dlclose(handle);
        }
    }
    
    _glStencilFunc(func, ref, mask);
}

// -- glStencilMask
void (*_glStencilMask)() = NULL;
            
void glStencilMask( GLuint mask )
{
    if (_glStencilMask == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glStencilMask = dlsym(handle, "glStencilMask");
            dlclose(handle);
        }
    }
    
    _glStencilMask(mask);
}

// -- glStencilOp
void (*_glStencilOp)() = NULL;
            
void glStencilOp( GLenum fail, GLenum zfail, GLenum zpass )
{
    if (_glStencilOp == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glStencilOp = dlsym(handle, "glStencilOp");
            dlclose(handle);
        }
    }
    
    _glStencilOp(fail, zfail, zpass);
}

// -- glClearStencil
void (*_glClearStencil)() = NULL;
            
void glClearStencil( GLint s )
{
    if (_glClearStencil == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glClearStencil = dlsym(handle, "glClearStencil");
            dlclose(handle);
        }
    }
    
    _glClearStencil(s);
}

// -- glTexGend
void (*_glTexGend)() = NULL;
            
void glTexGend( GLenum coord, GLenum pname, GLdouble param )
{
    if (_glTexGend == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexGend = dlsym(handle, "glTexGend");
            dlclose(handle);
        }
    }
    
    _glTexGend(coord, pname, param);
}

// -- glTexGenf
void (*_glTexGenf)() = NULL;
            
void glTexGenf( GLenum coord, GLenum pname, GLfloat param )
{
    if (_glTexGenf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexGenf = dlsym(handle, "glTexGenf");
            dlclose(handle);
        }
    }
    
    _glTexGenf(coord, pname, param);
}

// -- glTexGeni
void (*_glTexGeni)() = NULL;
            
void glTexGeni( GLenum coord, GLenum pname, GLint param )
{
    if (_glTexGeni == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexGeni = dlsym(handle, "glTexGeni");
            dlclose(handle);
        }
    }
    
    _glTexGeni(coord, pname, param);
}

// -- glTexGendv
void (*_glTexGendv)() = NULL;
            
void glTexGendv( GLenum coord, GLenum pname, const GLdouble *params )
{
    if (_glTexGendv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexGendv = dlsym(handle, "glTexGendv");
            dlclose(handle);
        }
    }
    
    _glTexGendv(coord, pname, *params);
}

// -- glTexGenfv
void (*_glTexGenfv)() = NULL;
            
void glTexGenfv( GLenum coord, GLenum pname, const GLfloat *params )
{
    if (_glTexGenfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexGenfv = dlsym(handle, "glTexGenfv");
            dlclose(handle);
        }
    }
    
    _glTexGenfv(coord, pname, *params);
}

// -- glTexGeniv
void (*_glTexGeniv)() = NULL;
            
void glTexGeniv( GLenum coord, GLenum pname, const GLint *params )
{
    if (_glTexGeniv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexGeniv = dlsym(handle, "glTexGeniv");
            dlclose(handle);
        }
    }
    
    _glTexGeniv(coord, pname, *params);
}

// -- glGetTexGendv
void (*_glGetTexGendv)() = NULL;
            
void glGetTexGendv( GLenum coord, GLenum pname, GLdouble *params )
{
    if (_glGetTexGendv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetTexGendv = dlsym(handle, "glGetTexGendv");
            dlclose(handle);
        }
    }
    
    _glGetTexGendv(coord, pname, *params);
}

// -- glGetTexGenfv
void (*_glGetTexGenfv)() = NULL;
            
void glGetTexGenfv( GLenum coord, GLenum pname, GLfloat *params )
{
    if (_glGetTexGenfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetTexGenfv = dlsym(handle, "glGetTexGenfv");
            dlclose(handle);
        }
    }
    
    _glGetTexGenfv(coord, pname, *params);
}

// -- glGetTexGeniv
void (*_glGetTexGeniv)() = NULL;
            
void glGetTexGeniv( GLenum coord, GLenum pname, GLint *params )
{
    if (_glGetTexGeniv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetTexGeniv = dlsym(handle, "glGetTexGeniv");
            dlclose(handle);
        }
    }
    
    _glGetTexGeniv(coord, pname, *params);
}

// -- glTexEnvf
void (*_glTexEnvf)() = NULL;
            
void glTexEnvf( GLenum target, GLenum pname, GLfloat param )
{
    if (_glTexEnvf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexEnvf = dlsym(handle, "glTexEnvf");
            dlclose(handle);
        }
    }
    
    _glTexEnvf(target, pname, param);
}

// -- glTexEnvi
void (*_glTexEnvi)() = NULL;
            
void glTexEnvi( GLenum target, GLenum pname, GLint param )
{
    if (_glTexEnvi == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexEnvi = dlsym(handle, "glTexEnvi");
            dlclose(handle);
        }
    }
    
    _glTexEnvi(target, pname, param);
}

// -- glTexEnvfv
void (*_glTexEnvfv)() = NULL;
            
void glTexEnvfv( GLenum target, GLenum pname, const GLfloat *params )
{
    if (_glTexEnvfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexEnvfv = dlsym(handle, "glTexEnvfv");
            dlclose(handle);
        }
    }
    
    _glTexEnvfv(target, pname, *params);
}

// -- glTexEnviv
void (*_glTexEnviv)() = NULL;
            
void glTexEnviv( GLenum target, GLenum pname, const GLint *params )
{
    if (_glTexEnviv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexEnviv = dlsym(handle, "glTexEnviv");
            dlclose(handle);
        }
    }
    
    _glTexEnviv(target, pname, *params);
}

// -- glGetTexEnvfv
void (*_glGetTexEnvfv)() = NULL;
            
void glGetTexEnvfv( GLenum target, GLenum pname, GLfloat *params )
{
    if (_glGetTexEnvfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetTexEnvfv = dlsym(handle, "glGetTexEnvfv");
            dlclose(handle);
        }
    }
    
    _glGetTexEnvfv(target, pname, *params);
}

// -- glGetTexEnviv
void (*_glGetTexEnviv)() = NULL;
            
void glGetTexEnviv( GLenum target, GLenum pname, GLint *params )
{
    if (_glGetTexEnviv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetTexEnviv = dlsym(handle, "glGetTexEnviv");
            dlclose(handle);
        }
    }
    
    _glGetTexEnviv(target, pname, *params);
}

// -- glTexParameterf
void (*_glTexParameterf)() = NULL;
            
void glTexParameterf( GLenum target, GLenum pname, GLfloat param )
{
    if (_glTexParameterf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexParameterf = dlsym(handle, "glTexParameterf");
            dlclose(handle);
        }
    }
    
    _glTexParameterf(target, pname, param);
}

// -- glTexParameteri
void (*_glTexParameteri)() = NULL;
            
void glTexParameteri( GLenum target, GLenum pname, GLint param )
{
    if (_glTexParameteri == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexParameteri = dlsym(handle, "glTexParameteri");
            dlclose(handle);
        }
    }
    
    _glTexParameteri(target, pname, param);
}

// -- glTexParameterfv
void (*_glTexParameterfv)() = NULL;
            
void glTexParameterfv( GLenum target, GLenum pname, const GLfloat *params )
{
    if (_glTexParameterfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexParameterfv = dlsym(handle, "glTexParameterfv");
            dlclose(handle);
        }
    }
    
    _glTexParameterfv(target, pname, *params);
}

// -- glTexParameteriv
void (*_glTexParameteriv)() = NULL;
            
void glTexParameteriv( GLenum target, GLenum pname, const GLint *params )
{
    if (_glTexParameteriv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexParameteriv = dlsym(handle, "glTexParameteriv");
            dlclose(handle);
        }
    }
    
    _glTexParameteriv(target, pname, *params);
}

// -- glGetTexParameterfv
void (*_glGetTexParameterfv)() = NULL;
            
void glGetTexParameterfv( GLenum target, GLenum pname, GLfloat *params)
{
    if (_glGetTexParameterfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetTexParameterfv = dlsym(handle, "glGetTexParameterfv");
            dlclose(handle);
        }
    }
    
    _glGetTexParameterfv(target, pname, *params);
}

// -- glGetTexParameteriv
void (*_glGetTexParameteriv)() = NULL;
            
void glGetTexParameteriv( GLenum target, GLenum pname, GLint *params )
{
    if (_glGetTexParameteriv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetTexParameteriv = dlsym(handle, "glGetTexParameteriv");
            dlclose(handle);
        }
    }
    
    _glGetTexParameteriv(target, pname, *params);
}

// -- glGetTexLevelParameterfv
void (*_glGetTexLevelParameterfv)() = NULL;
            
void glGetTexLevelParameterfv( GLenum target, GLint level, GLenum pname, GLfloat *params )
{
    if (_glGetTexLevelParameterfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetTexLevelParameterfv = dlsym(handle, "glGetTexLevelParameterfv");
            dlclose(handle);
        }
    }
    
    _glGetTexLevelParameterfv(target, level, pname, *params);
}

// -- glGetTexLevelParameteriv
void (*_glGetTexLevelParameteriv)() = NULL;
            
void glGetTexLevelParameteriv( GLenum target, GLint level, GLenum pname, GLint *params )
{
    if (_glGetTexLevelParameteriv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetTexLevelParameteriv = dlsym(handle, "glGetTexLevelParameteriv");
            dlclose(handle);
        }
    }
    
    _glGetTexLevelParameteriv(target, level, pname, *params);
}

// -- glTexImage1D
void (*_glTexImage1D)() = NULL;
            
void glTexImage1D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels )
{
    if (_glTexImage1D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexImage1D = dlsym(handle, "glTexImage1D");
            dlclose(handle);
        }
    }
    
    _glTexImage1D(target, level, internalFormat, width, border, format, type, *pixels);
}

// -- glTexImage2D
void (*_glTexImage2D)() = NULL;
            
void glTexImage2D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels )
{
    if (_glTexImage2D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexImage2D = dlsym(handle, "glTexImage2D");
            dlclose(handle);
        }
    }
    
    _glTexImage2D(target, level, internalFormat, width, height, border, format, type, *pixels);
}

// -- glGetTexImage
void (*_glGetTexImage)() = NULL;
            
void glGetTexImage( GLenum target, GLint level,  GLenum format, GLenum type,  GLvoid *pixels )
{
    if (_glGetTexImage == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetTexImage = dlsym(handle, "glGetTexImage");
            dlclose(handle);
        }
    }
    
    _glGetTexImage(target, level, format, type, *pixels);
}

// -- glGenTextures
void (*_glGenTextures)() = NULL;
            
void glGenTextures( GLsizei n, GLuint *textures )
{
    if (_glGenTextures == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGenTextures = dlsym(handle, "glGenTextures");
            dlclose(handle);
        }
    }
    
    _glGenTextures(n, *textures);
}

// -- glDeleteTextures
void (*_glDeleteTextures)() = NULL;
            
void glDeleteTextures( GLsizei n, const GLuint *textures)
{
    if (_glDeleteTextures == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDeleteTextures = dlsym(handle, "glDeleteTextures");
            dlclose(handle);
        }
    }
    
    _glDeleteTextures(n, *textures);
}

// -- glBindTexture
void (*_glBindTexture)() = NULL;
            
void glBindTexture( GLenum target, GLuint texture )
{
    if (_glBindTexture == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glBindTexture = dlsym(handle, "glBindTexture");
            dlclose(handle);
        }
    }
    
    _glBindTexture(target, texture);
}

// -- glPrioritizeTextures
void (*_glPrioritizeTextures)() = NULL;
            
void glPrioritizeTextures( GLsizei n, const GLuint *textures, const GLclampf *priorities )
{
    if (_glPrioritizeTextures == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPrioritizeTextures = dlsym(handle, "glPrioritizeTextures");
            dlclose(handle);
        }
    }
    
    _glPrioritizeTextures(n, *textures, *priorities);
}

// -- glAreTexturesResident
GLboolean (*_glAreTexturesResident)() = NULL;
        
GLboolean glAreTexturesResident( GLsizei n, const GLuint *textures, GLboolean *residences )
{
    if (_glAreTexturesResident == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glAreTexturesResident = dlsym(handle, "glAreTexturesResident");
            dlclose(handle);
        }
    }

    return _glAreTexturesResident(n, *textures, *residences);
}

// -- glIsTexture
GLboolean (*_glIsTexture)() = NULL;
        
GLboolean glIsTexture( GLuint texture )
{
    if (_glIsTexture == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glIsTexture = dlsym(handle, "glIsTexture");
            dlclose(handle);
        }
    }

    return _glIsTexture(texture);
}

// -- glTexSubImage1D
void (*_glTexSubImage1D)() = NULL;
            
void glTexSubImage1D( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels )
{
    if (_glTexSubImage1D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexSubImage1D = dlsym(handle, "glTexSubImage1D");
            dlclose(handle);
        }
    }
    
    _glTexSubImage1D(target, level, xoffset, width, format, type, *pixels);
}

// -- glTexSubImage2D
void (*_glTexSubImage2D)() = NULL;
            
void glTexSubImage2D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels )
{
    if (_glTexSubImage2D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexSubImage2D = dlsym(handle, "glTexSubImage2D");
            dlclose(handle);
        }
    }
    
    _glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, *pixels);
}

// -- glCopyTexImage1D
void (*_glCopyTexImage1D)() = NULL;
            
void glCopyTexImage1D( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border )
{
    if (_glCopyTexImage1D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCopyTexImage1D = dlsym(handle, "glCopyTexImage1D");
            dlclose(handle);
        }
    }
    
    _glCopyTexImage1D(target, level, internalformat, x, y, width, border);
}

// -- glCopyTexImage2D
void (*_glCopyTexImage2D)() = NULL;
            
void glCopyTexImage2D( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border )
{
    if (_glCopyTexImage2D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCopyTexImage2D = dlsym(handle, "glCopyTexImage2D");
            dlclose(handle);
        }
    }
    
    _glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}

// -- glCopyTexSubImage1D
void (*_glCopyTexSubImage1D)() = NULL;
            
void glCopyTexSubImage1D( GLenum target, GLint level,GLint xoffset, GLint x, GLint y,GLsizei width )
{
    if (_glCopyTexSubImage1D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCopyTexSubImage1D = dlsym(handle, "glCopyTexSubImage1D");
            dlclose(handle);
        }
    }
    
    _glCopyTexSubImage1D(target, level,GLint GLint GLint width);
}

// -- glCopyTexSubImage2D
void (*_glCopyTexSubImage2D)() = NULL;
            
void glCopyTexSubImage2D( GLenum target, GLint level,GLint xoffset, GLint yoffset,GLint x, GLint y, GLsizei width, GLsizei height )
{
    if (_glCopyTexSubImage2D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCopyTexSubImage2D = dlsym(handle, "glCopyTexSubImage2D");
            dlclose(handle);
        }
    }
    
    _glCopyTexSubImage2D(target, level,GLint GLint x, y, width, height);
}

// -- glMap1d
void (*_glMap1d)() = NULL;
            
void glMap1d( GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points )
{
    if (_glMap1d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMap1d = dlsym(handle, "glMap1d");
            dlclose(handle);
        }
    }
    
    _glMap1d(target, u1, u2, stride, order, *points);
}

// -- glMap1f
void (*_glMap1f)() = NULL;
            
void glMap1f( GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points )
{
    if (_glMap1f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMap1f = dlsym(handle, "glMap1f");
            dlclose(handle);
        }
    }
    
    _glMap1f(target, u1, u2, stride, order, *points);
}

// -- glMap2d
void (*_glMap2d)() = NULL;
            
void glMap2d( GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points )
{
    if (_glMap2d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMap2d = dlsym(handle, "glMap2d");
            dlclose(handle);
        }
    }
    
    _glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, *points);
}

// -- glMap2f
void (*_glMap2f)() = NULL;
            
void glMap2f( GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points )
{
    if (_glMap2f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMap2f = dlsym(handle, "glMap2f");
            dlclose(handle);
        }
    }
    
    _glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, *points);
}

// -- glGetMapdv
void (*_glGetMapdv)() = NULL;
            
void glGetMapdv( GLenum target, GLenum query, GLdouble *v )
{
    if (_glGetMapdv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetMapdv = dlsym(handle, "glGetMapdv");
            dlclose(handle);
        }
    }
    
    _glGetMapdv(target, query, *v);
}

// -- glGetMapfv
void (*_glGetMapfv)() = NULL;
            
void glGetMapfv( GLenum target, GLenum query, GLfloat *v )
{
    if (_glGetMapfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetMapfv = dlsym(handle, "glGetMapfv");
            dlclose(handle);
        }
    }
    
    _glGetMapfv(target, query, *v);
}

// -- glGetMapiv
void (*_glGetMapiv)() = NULL;
            
void glGetMapiv( GLenum target, GLenum query, GLint *v )
{
    if (_glGetMapiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetMapiv = dlsym(handle, "glGetMapiv");
            dlclose(handle);
        }
    }
    
    _glGetMapiv(target, query, *v);
}

// -- glEvalCoord1d
void (*_glEvalCoord1d)() = NULL;
            
void glEvalCoord1d( GLdouble u )
{
    if (_glEvalCoord1d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalCoord1d = dlsym(handle, "glEvalCoord1d");
            dlclose(handle);
        }
    }
    
    _glEvalCoord1d(u);
}

// -- glEvalCoord1f
void (*_glEvalCoord1f)() = NULL;
            
void glEvalCoord1f( GLfloat u )
{
    if (_glEvalCoord1f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalCoord1f = dlsym(handle, "glEvalCoord1f");
            dlclose(handle);
        }
    }
    
    _glEvalCoord1f(u);
}

// -- glEvalCoord1dv
void (*_glEvalCoord1dv)() = NULL;
            
void glEvalCoord1dv( const GLdouble *u )
{
    if (_glEvalCoord1dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalCoord1dv = dlsym(handle, "glEvalCoord1dv");
            dlclose(handle);
        }
    }
    
    _glEvalCoord1dv(*u);
}

// -- glEvalCoord1fv
void (*_glEvalCoord1fv)() = NULL;
            
void glEvalCoord1fv( const GLfloat *u )
{
    if (_glEvalCoord1fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalCoord1fv = dlsym(handle, "glEvalCoord1fv");
            dlclose(handle);
        }
    }
    
    _glEvalCoord1fv(*u);
}

// -- glEvalCoord2d
void (*_glEvalCoord2d)() = NULL;
            
void glEvalCoord2d( GLdouble u, GLdouble v )
{
    if (_glEvalCoord2d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalCoord2d = dlsym(handle, "glEvalCoord2d");
            dlclose(handle);
        }
    }
    
    _glEvalCoord2d(u, v);
}

// -- glEvalCoord2f
void (*_glEvalCoord2f)() = NULL;
            
void glEvalCoord2f( GLfloat u, GLfloat v )
{
    if (_glEvalCoord2f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalCoord2f = dlsym(handle, "glEvalCoord2f");
            dlclose(handle);
        }
    }
    
    _glEvalCoord2f(u, v);
}

// -- glEvalCoord2dv
void (*_glEvalCoord2dv)() = NULL;
            
void glEvalCoord2dv( const GLdouble *u )
{
    if (_glEvalCoord2dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalCoord2dv = dlsym(handle, "glEvalCoord2dv");
            dlclose(handle);
        }
    }
    
    _glEvalCoord2dv(*u);
}

// -- glEvalCoord2fv
void (*_glEvalCoord2fv)() = NULL;
            
void glEvalCoord2fv( const GLfloat *u )
{
    if (_glEvalCoord2fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalCoord2fv = dlsym(handle, "glEvalCoord2fv");
            dlclose(handle);
        }
    }
    
    _glEvalCoord2fv(*u);
}

// -- glMapGrid1d
void (*_glMapGrid1d)() = NULL;
            
void glMapGrid1d( GLint un, GLdouble u1, GLdouble u2 )
{
    if (_glMapGrid1d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMapGrid1d = dlsym(handle, "glMapGrid1d");
            dlclose(handle);
        }
    }
    
    _glMapGrid1d(un, u1, u2);
}

// -- glMapGrid1f
void (*_glMapGrid1f)() = NULL;
            
void glMapGrid1f( GLint un, GLfloat u1, GLfloat u2 )
{
    if (_glMapGrid1f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMapGrid1f = dlsym(handle, "glMapGrid1f");
            dlclose(handle);
        }
    }
    
    _glMapGrid1f(un, u1, u2);
}

// -- glMapGrid2d
void (*_glMapGrid2d)() = NULL;
            
void glMapGrid2d( GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2 )
{
    if (_glMapGrid2d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMapGrid2d = dlsym(handle, "glMapGrid2d");
            dlclose(handle);
        }
    }
    
    _glMapGrid2d(un, u1, u2, vn, v1, v2);
}

// -- glMapGrid2f
void (*_glMapGrid2f)() = NULL;
            
void glMapGrid2f( GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2 )
{
    if (_glMapGrid2f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMapGrid2f = dlsym(handle, "glMapGrid2f");
            dlclose(handle);
        }
    }
    
    _glMapGrid2f(un, u1, u2, vn, v1, v2);
}

// -- glEvalPoint1
void (*_glEvalPoint1)() = NULL;
            
void glEvalPoint1( GLint i )
{
    if (_glEvalPoint1 == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalPoint1 = dlsym(handle, "glEvalPoint1");
            dlclose(handle);
        }
    }
    
    _glEvalPoint1(i);
}

// -- glEvalPoint2
void (*_glEvalPoint2)() = NULL;
            
void glEvalPoint2( GLint i, GLint j )
{
    if (_glEvalPoint2 == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalPoint2 = dlsym(handle, "glEvalPoint2");
            dlclose(handle);
        }
    }
    
    _glEvalPoint2(i, j);
}

// -- glEvalMesh1
void (*_glEvalMesh1)() = NULL;
            
void glEvalMesh1( GLenum mode, GLint i1, GLint i2 )
{
    if (_glEvalMesh1 == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalMesh1 = dlsym(handle, "glEvalMesh1");
            dlclose(handle);
        }
    }
    
    _glEvalMesh1(mode, i1, i2);
}

// -- glEvalMesh2
void (*_glEvalMesh2)() = NULL;
            
void glEvalMesh2( GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2 )
{
    if (_glEvalMesh2 == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glEvalMesh2 = dlsym(handle, "glEvalMesh2");
            dlclose(handle);
        }
    }
    
    _glEvalMesh2(mode, i1, i2, j1, j2);
}

// -- glFogf
void (*_glFogf)() = NULL;
            
void glFogf( GLenum pname, GLfloat param )
{
    if (_glFogf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glFogf = dlsym(handle, "glFogf");
            dlclose(handle);
        }
    }
    
    _glFogf(pname, param);
}

// -- glFogi
void (*_glFogi)() = NULL;
            
void glFogi( GLenum pname, GLint param )
{
    if (_glFogi == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glFogi = dlsym(handle, "glFogi");
            dlclose(handle);
        }
    }
    
    _glFogi(pname, param);
}

// -- glFogfv
void (*_glFogfv)() = NULL;
            
void glFogfv( GLenum pname, const GLfloat *params )
{
    if (_glFogfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glFogfv = dlsym(handle, "glFogfv");
            dlclose(handle);
        }
    }
    
    _glFogfv(pname, *params);
}

// -- glFogiv
void (*_glFogiv)() = NULL;
            
void glFogiv( GLenum pname, const GLint *params )
{
    if (_glFogiv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glFogiv = dlsym(handle, "glFogiv");
            dlclose(handle);
        }
    }
    
    _glFogiv(pname, *params);
}

// -- glFeedbackBuffer
void (*_glFeedbackBuffer)() = NULL;
            
void glFeedbackBuffer( GLsizei size, GLenum type, GLfloat *buffer )
{
    if (_glFeedbackBuffer == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glFeedbackBuffer = dlsym(handle, "glFeedbackBuffer");
            dlclose(handle);
        }
    }
    
    _glFeedbackBuffer(size, type, *buffer);
}

// -- glPassThrough
void (*_glPassThrough)() = NULL;
            
void glPassThrough( GLfloat token )
{
    if (_glPassThrough == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPassThrough = dlsym(handle, "glPassThrough");
            dlclose(handle);
        }
    }
    
    _glPassThrough(token);
}

// -- glSelectBuffer
void (*_glSelectBuffer)() = NULL;
            
void glSelectBuffer( GLsizei size, GLuint *buffer )
{
    if (_glSelectBuffer == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glSelectBuffer = dlsym(handle, "glSelectBuffer");
            dlclose(handle);
        }
    }
    
    _glSelectBuffer(size, *buffer);
}

// -- glInitNames
void (*_glInitNames)() = NULL;
            
void glInitNames()
{
    if (_glInitNames == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glInitNames = dlsym(handle, "glInitNames");
            dlclose(handle);
        }
    }
    
    _glInitNames();
}

// -- glLoadName
void (*_glLoadName)() = NULL;
            
void glLoadName( GLuint name )
{
    if (_glLoadName == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLoadName = dlsym(handle, "glLoadName");
            dlclose(handle);
        }
    }
    
    _glLoadName(name);
}

// -- glPushName
void (*_glPushName)() = NULL;
            
void glPushName( GLuint name )
{
    if (_glPushName == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPushName = dlsym(handle, "glPushName");
            dlclose(handle);
        }
    }
    
    _glPushName(name);
}

// -- glPopName
void (*_glPopName)() = NULL;
            
void glPopName()
{
    if (_glPopName == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glPopName = dlsym(handle, "glPopName");
            dlclose(handle);
        }
    }
    
    _glPopName();
}

// -- glDrawRangeElements
void (*_glDrawRangeElements)() = NULL;
            
void glDrawRangeElements( GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices )
{
    if (_glDrawRangeElements == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glDrawRangeElements = dlsym(handle, "glDrawRangeElements");
            dlclose(handle);
        }
    }
    
    _glDrawRangeElements(mode, start, end, count, type, *indices);
}

// -- glTexImage3D
void (*_glTexImage3D)() = NULL;
            
void glTexImage3D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels )
{
    if (_glTexImage3D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexImage3D = dlsym(handle, "glTexImage3D");
            dlclose(handle);
        }
    }
    
    _glTexImage3D(target, level, internalFormat, width, height, depth, border, format, type, *pixels);
}

// -- glTexSubImage3D
void (*_glTexSubImage3D)() = NULL;
            
void glTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
{
    if (_glTexSubImage3D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glTexSubImage3D = dlsym(handle, "glTexSubImage3D");
            dlclose(handle);
        }
    }
    
    _glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, *pixels);
}

// -- glCopyTexSubImage3D
void (*_glCopyTexSubImage3D)() = NULL;
            
void glCopyTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height )
{
    if (_glCopyTexSubImage3D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCopyTexSubImage3D = dlsym(handle, "glCopyTexSubImage3D");
            dlclose(handle);
        }
    }
    
    _glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

// -- glColorTable
void (*_glColorTable)() = NULL;
            
void glColorTable( GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table )
{
    if (_glColorTable == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColorTable = dlsym(handle, "glColorTable");
            dlclose(handle);
        }
    }
    
    _glColorTable(target, internalformat, width, format, type, *table);
}

// -- glColorSubTable
void (*_glColorSubTable)() = NULL;
            
void glColorSubTable( GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data )
{
    if (_glColorSubTable == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColorSubTable = dlsym(handle, "glColorSubTable");
            dlclose(handle);
        }
    }
    
    _glColorSubTable(target, start, count, format, type, *data);
}

// -- glColorTableParameteriv
void (*_glColorTableParameteriv)() = NULL;
            
void glColorTableParameteriv(GLenum target, GLenum pname, const GLint *params)
{
    if (_glColorTableParameteriv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColorTableParameteriv = dlsym(handle, "glColorTableParameteriv");
            dlclose(handle);
        }
    }
    
    _glColorTableParameteriv(target, pname, *params);
}

// -- glColorTableParameterfv
void (*_glColorTableParameterfv)() = NULL;
            
void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
    if (_glColorTableParameterfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glColorTableParameterfv = dlsym(handle, "glColorTableParameterfv");
            dlclose(handle);
        }
    }
    
    _glColorTableParameterfv(target, pname, *params);
}

// -- glCopyColorSubTable
void (*_glCopyColorSubTable)() = NULL;
            
void glCopyColorSubTable( GLenum target, GLsizei start,GLint x, GLint y, GLsizei width )
{
    if (_glCopyColorSubTable == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCopyColorSubTable = dlsym(handle, "glCopyColorSubTable");
            dlclose(handle);
        }
    }
    
    _glCopyColorSubTable(target, start,GLint GLint GLsizei);
}

// -- glCopyColorTable
void (*_glCopyColorTable)() = NULL;
            
void glCopyColorTable( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width )
{
    if (_glCopyColorTable == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCopyColorTable = dlsym(handle, "glCopyColorTable");
            dlclose(handle);
        }
    }
    
    _glCopyColorTable(target, internalformat, x, y, width);
}

// -- glGetColorTable
void (*_glGetColorTable)() = NULL;
            
void glGetColorTable( GLenum target, GLenum format, GLenum type, GLvoid *table )
{
    if (_glGetColorTable == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetColorTable = dlsym(handle, "glGetColorTable");
            dlclose(handle);
        }
    }
    
    _glGetColorTable(target, format, type, *table);
}

// -- glGetColorTableParameterfv
void (*_glGetColorTableParameterfv)() = NULL;
            
void glGetColorTableParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    if (_glGetColorTableParameterfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetColorTableParameterfv = dlsym(handle, "glGetColorTableParameterfv");
            dlclose(handle);
        }
    }
    
    _glGetColorTableParameterfv(target, pname, *params);
}

// -- glGetColorTableParameteriv
void (*_glGetColorTableParameteriv)() = NULL;
            
void glGetColorTableParameteriv( GLenum target, GLenum pname, GLint *params )
{
    if (_glGetColorTableParameteriv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetColorTableParameteriv = dlsym(handle, "glGetColorTableParameteriv");
            dlclose(handle);
        }
    }
    
    _glGetColorTableParameteriv(target, pname, *params);
}

// -- glBlendEquation
void (*_glBlendEquation)() = NULL;
            
void glBlendEquation( GLenum mode )
{
    if (_glBlendEquation == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glBlendEquation = dlsym(handle, "glBlendEquation");
            dlclose(handle);
        }
    }
    
    _glBlendEquation(mode);
}

// -- glBlendColor
void (*_glBlendColor)() = NULL;
            
void glBlendColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha )
{
    if (_glBlendColor == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glBlendColor = dlsym(handle, "glBlendColor");
            dlclose(handle);
        }
    }
    
    _glBlendColor(red, green, blue, alpha);
}

// -- glHistogram
void (*_glHistogram)() = NULL;
            
void glHistogram( GLenum target, GLsizei width, GLenum internalformat, GLboolean sink )
{
    if (_glHistogram == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glHistogram = dlsym(handle, "glHistogram");
            dlclose(handle);
        }
    }
    
    _glHistogram(target, width, internalformat, sink);
}

// -- glResetHistogram
void (*_glResetHistogram)() = NULL;
            
void glResetHistogram( GLenum target )
{
    if (_glResetHistogram == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glResetHistogram = dlsym(handle, "glResetHistogram");
            dlclose(handle);
        }
    }
    
    _glResetHistogram(target);
}

// -- glGetHistogram
void (*_glGetHistogram)() = NULL;
            
void glGetHistogram( GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values )
{
    if (_glGetHistogram == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetHistogram = dlsym(handle, "glGetHistogram");
            dlclose(handle);
        }
    }
    
    _glGetHistogram(target, reset, format, type, *values);
}

// -- glGetHistogramParameterfv
void (*_glGetHistogramParameterfv)() = NULL;
            
void glGetHistogramParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    if (_glGetHistogramParameterfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetHistogramParameterfv = dlsym(handle, "glGetHistogramParameterfv");
            dlclose(handle);
        }
    }
    
    _glGetHistogramParameterfv(target, pname, *params);
}

// -- glGetHistogramParameteriv
void (*_glGetHistogramParameteriv)() = NULL;
            
void glGetHistogramParameteriv( GLenum target, GLenum pname, GLint *params )
{
    if (_glGetHistogramParameteriv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetHistogramParameteriv = dlsym(handle, "glGetHistogramParameteriv");
            dlclose(handle);
        }
    }
    
    _glGetHistogramParameteriv(target, pname, *params);
}

// -- glMinmax
void (*_glMinmax)() = NULL;
            
void glMinmax( GLenum target, GLenum internalformat, GLboolean sink )
{
    if (_glMinmax == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMinmax = dlsym(handle, "glMinmax");
            dlclose(handle);
        }
    }
    
    _glMinmax(target, internalformat, sink);
}

// -- glResetMinmax
void (*_glResetMinmax)() = NULL;
            
void glResetMinmax( GLenum target )
{
    if (_glResetMinmax == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glResetMinmax = dlsym(handle, "glResetMinmax");
            dlclose(handle);
        }
    }
    
    _glResetMinmax(target);
}

// -- glGetMinmax
void (*_glGetMinmax)() = NULL;
            
void glGetMinmax( GLenum target, GLboolean reset, GLenum format, GLenum types, GLvoid *values )
{
    if (_glGetMinmax == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetMinmax = dlsym(handle, "glGetMinmax");
            dlclose(handle);
        }
    }
    
    _glGetMinmax(target, reset, format, types, *values);
}

// -- glGetMinmaxParameterfv
void (*_glGetMinmaxParameterfv)() = NULL;
            
void glGetMinmaxParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    if (_glGetMinmaxParameterfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetMinmaxParameterfv = dlsym(handle, "glGetMinmaxParameterfv");
            dlclose(handle);
        }
    }
    
    _glGetMinmaxParameterfv(target, pname, *params);
}

// -- glGetMinmaxParameteriv
void (*_glGetMinmaxParameteriv)() = NULL;
            
void glGetMinmaxParameteriv( GLenum target, GLenum pname, GLint *params )
{
    if (_glGetMinmaxParameteriv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetMinmaxParameteriv = dlsym(handle, "glGetMinmaxParameteriv");
            dlclose(handle);
        }
    }
    
    _glGetMinmaxParameteriv(target, pname, *params);
}

// -- glConvolutionFilter1D
void (*_glConvolutionFilter1D)() = NULL;
            
void glConvolutionFilter1D( GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image )
{
    if (_glConvolutionFilter1D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glConvolutionFilter1D = dlsym(handle, "glConvolutionFilter1D");
            dlclose(handle);
        }
    }
    
    _glConvolutionFilter1D(target, internalformat, width, format, type, *image);
}

// -- glConvolutionFilter2D
void (*_glConvolutionFilter2D)() = NULL;
            
void glConvolutionFilter2D( GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image )
{
    if (_glConvolutionFilter2D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glConvolutionFilter2D = dlsym(handle, "glConvolutionFilter2D");
            dlclose(handle);
        }
    }
    
    _glConvolutionFilter2D(target, internalformat, width, height, format, type, *image);
}

// -- glConvolutionParameterf
void (*_glConvolutionParameterf)() = NULL;
            
void glConvolutionParameterf( GLenum target, GLenum pname, GLfloat params )
{
    if (_glConvolutionParameterf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glConvolutionParameterf = dlsym(handle, "glConvolutionParameterf");
            dlclose(handle);
        }
    }
    
    _glConvolutionParameterf(target, pname, params);
}

// -- glConvolutionParameterfv
void (*_glConvolutionParameterfv)() = NULL;
            
void glConvolutionParameterfv( GLenum target, GLenum pname, const GLfloat *params )
{
    if (_glConvolutionParameterfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glConvolutionParameterfv = dlsym(handle, "glConvolutionParameterfv");
            dlclose(handle);
        }
    }
    
    _glConvolutionParameterfv(target, pname, *params);
}

// -- glConvolutionParameteri
void (*_glConvolutionParameteri)() = NULL;
            
void glConvolutionParameteri( GLenum target, GLenum pname, GLint params )
{
    if (_glConvolutionParameteri == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glConvolutionParameteri = dlsym(handle, "glConvolutionParameteri");
            dlclose(handle);
        }
    }
    
    _glConvolutionParameteri(target, pname, params);
}

// -- glConvolutionParameteriv
void (*_glConvolutionParameteriv)() = NULL;
            
void glConvolutionParameteriv( GLenum target, GLenum pname, const GLint *params )
{
    if (_glConvolutionParameteriv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glConvolutionParameteriv = dlsym(handle, "glConvolutionParameteriv");
            dlclose(handle);
        }
    }
    
    _glConvolutionParameteriv(target, pname, *params);
}

// -- glCopyConvolutionFilter1D
void (*_glCopyConvolutionFilter1D)() = NULL;
            
void glCopyConvolutionFilter1D( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width )
{
    if (_glCopyConvolutionFilter1D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCopyConvolutionFilter1D = dlsym(handle, "glCopyConvolutionFilter1D");
            dlclose(handle);
        }
    }
    
    _glCopyConvolutionFilter1D(target, internalformat, x, y, width);
}

// -- glCopyConvolutionFilter2D
void (*_glCopyConvolutionFilter2D)() = NULL;
            
void glCopyConvolutionFilter2D( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height)
{
    if (_glCopyConvolutionFilter2D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCopyConvolutionFilter2D = dlsym(handle, "glCopyConvolutionFilter2D");
            dlclose(handle);
        }
    }
    
    _glCopyConvolutionFilter2D(target, internalformat, x, y, width, height);
}

// -- glGetConvolutionFilter
void (*_glGetConvolutionFilter)() = NULL;
            
void glGetConvolutionFilter( GLenum target, GLenum format, GLenum type, GLvoid *image )
{
    if (_glGetConvolutionFilter == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetConvolutionFilter = dlsym(handle, "glGetConvolutionFilter");
            dlclose(handle);
        }
    }
    
    _glGetConvolutionFilter(target, format, type, *image);
}

// -- glGetConvolutionParameterfv
void (*_glGetConvolutionParameterfv)() = NULL;
            
void glGetConvolutionParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    if (_glGetConvolutionParameterfv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetConvolutionParameterfv = dlsym(handle, "glGetConvolutionParameterfv");
            dlclose(handle);
        }
    }
    
    _glGetConvolutionParameterfv(target, pname, *params);
}

// -- glGetConvolutionParameteriv
void (*_glGetConvolutionParameteriv)() = NULL;
            
void glGetConvolutionParameteriv( GLenum target, GLenum pname, GLint *params )
{
    if (_glGetConvolutionParameteriv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetConvolutionParameteriv = dlsym(handle, "glGetConvolutionParameteriv");
            dlclose(handle);
        }
    }
    
    _glGetConvolutionParameteriv(target, pname, *params);
}

// -- glSeparableFilter2D
void (*_glSeparableFilter2D)() = NULL;
            
void glSeparableFilter2D( GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column )
{
    if (_glSeparableFilter2D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glSeparableFilter2D = dlsym(handle, "glSeparableFilter2D");
            dlclose(handle);
        }
    }
    
    _glSeparableFilter2D(target, internalformat, width, height, format, type, *row, *column);
}

// -- glGetSeparableFilter
void (*_glGetSeparableFilter)() = NULL;
            
void glGetSeparableFilter( GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span )
{
    if (_glGetSeparableFilter == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetSeparableFilter = dlsym(handle, "glGetSeparableFilter");
            dlclose(handle);
        }
    }
    
    _glGetSeparableFilter(target, format, type, *row, *column, *span);
}

// -- glActiveTexture
void (*_glActiveTexture)() = NULL;
            
void glActiveTexture( GLenum texture )
{
    if (_glActiveTexture == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glActiveTexture = dlsym(handle, "glActiveTexture");
            dlclose(handle);
        }
    }
    
    _glActiveTexture(texture);
}

// -- glClientActiveTexture
void (*_glClientActiveTexture)() = NULL;
            
void glClientActiveTexture( GLenum texture )
{
    if (_glClientActiveTexture == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glClientActiveTexture = dlsym(handle, "glClientActiveTexture");
            dlclose(handle);
        }
    }
    
    _glClientActiveTexture(texture);
}

// -- glCompressedTexImage1D
void (*_glCompressedTexImage1D)() = NULL;
            
void glCompressedTexImage1D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data )
{
    if (_glCompressedTexImage1D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCompressedTexImage1D = dlsym(handle, "glCompressedTexImage1D");
            dlclose(handle);
        }
    }
    
    _glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, *data);
}

// -- glCompressedTexImage2D
void (*_glCompressedTexImage2D)() = NULL;
            
void glCompressedTexImage2D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data )
{
    if (_glCompressedTexImage2D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCompressedTexImage2D = dlsym(handle, "glCompressedTexImage2D");
            dlclose(handle);
        }
    }
    
    _glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, *data);
}

// -- glCompressedTexImage3D
void (*_glCompressedTexImage3D)() = NULL;
            
void glCompressedTexImage3D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data )
{
    if (_glCompressedTexImage3D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCompressedTexImage3D = dlsym(handle, "glCompressedTexImage3D");
            dlclose(handle);
        }
    }
    
    _glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, *data);
}

// -- glCompressedTexSubImage1D
void (*_glCompressedTexSubImage1D)() = NULL;
            
void glCompressedTexSubImage1D( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data )
{
    if (_glCompressedTexSubImage1D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCompressedTexSubImage1D = dlsym(handle, "glCompressedTexSubImage1D");
            dlclose(handle);
        }
    }
    
    _glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, *data);
}

// -- glCompressedTexSubImage2D
void (*_glCompressedTexSubImage2D)() = NULL;
            
void glCompressedTexSubImage2D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data )
{
    if (_glCompressedTexSubImage2D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCompressedTexSubImage2D = dlsym(handle, "glCompressedTexSubImage2D");
            dlclose(handle);
        }
    }
    
    _glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, *data);
}

// -- glCompressedTexSubImage3D
void (*_glCompressedTexSubImage3D)() = NULL;
            
void glCompressedTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data )
{
    if (_glCompressedTexSubImage3D == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glCompressedTexSubImage3D = dlsym(handle, "glCompressedTexSubImage3D");
            dlclose(handle);
        }
    }
    
    _glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, *data);
}

// -- glGetCompressedTexImage
void (*_glGetCompressedTexImage)() = NULL;
            
void glGetCompressedTexImage( GLenum target, GLint lod, GLvoid *img )
{
    if (_glGetCompressedTexImage == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glGetCompressedTexImage = dlsym(handle, "glGetCompressedTexImage");
            dlclose(handle);
        }
    }
    
    _glGetCompressedTexImage(target, lod, *img);
}

// -- glMultiTexCoord1d
void (*_glMultiTexCoord1d)() = NULL;
            
void glMultiTexCoord1d( GLenum target, GLdouble s )
{
    if (_glMultiTexCoord1d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1d = dlsym(handle, "glMultiTexCoord1d");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1d(target, s);
}

// -- glMultiTexCoord1dv
void (*_glMultiTexCoord1dv)() = NULL;
            
void glMultiTexCoord1dv( GLenum target, const GLdouble *v )
{
    if (_glMultiTexCoord1dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1dv = dlsym(handle, "glMultiTexCoord1dv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1dv(target, *v);
}

// -- glMultiTexCoord1f
void (*_glMultiTexCoord1f)() = NULL;
            
void glMultiTexCoord1f( GLenum target, GLfloat s )
{
    if (_glMultiTexCoord1f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1f = dlsym(handle, "glMultiTexCoord1f");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1f(target, s);
}

// -- glMultiTexCoord1fv
void (*_glMultiTexCoord1fv)() = NULL;
            
void glMultiTexCoord1fv( GLenum target, const GLfloat *v )
{
    if (_glMultiTexCoord1fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1fv = dlsym(handle, "glMultiTexCoord1fv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1fv(target, *v);
}

// -- glMultiTexCoord1i
void (*_glMultiTexCoord1i)() = NULL;
            
void glMultiTexCoord1i( GLenum target, GLint s )
{
    if (_glMultiTexCoord1i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1i = dlsym(handle, "glMultiTexCoord1i");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1i(target, s);
}

// -- glMultiTexCoord1iv
void (*_glMultiTexCoord1iv)() = NULL;
            
void glMultiTexCoord1iv( GLenum target, const GLint *v )
{
    if (_glMultiTexCoord1iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1iv = dlsym(handle, "glMultiTexCoord1iv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1iv(target, *v);
}

// -- glMultiTexCoord1s
void (*_glMultiTexCoord1s)() = NULL;
            
void glMultiTexCoord1s( GLenum target, GLshort s )
{
    if (_glMultiTexCoord1s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1s = dlsym(handle, "glMultiTexCoord1s");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1s(target, s);
}

// -- glMultiTexCoord1sv
void (*_glMultiTexCoord1sv)() = NULL;
            
void glMultiTexCoord1sv( GLenum target, const GLshort *v )
{
    if (_glMultiTexCoord1sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1sv = dlsym(handle, "glMultiTexCoord1sv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1sv(target, *v);
}

// -- glMultiTexCoord2d
void (*_glMultiTexCoord2d)() = NULL;
            
void glMultiTexCoord2d( GLenum target, GLdouble s, GLdouble t )
{
    if (_glMultiTexCoord2d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2d = dlsym(handle, "glMultiTexCoord2d");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2d(target, s, t);
}

// -- glMultiTexCoord2dv
void (*_glMultiTexCoord2dv)() = NULL;
            
void glMultiTexCoord2dv( GLenum target, const GLdouble *v )
{
    if (_glMultiTexCoord2dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2dv = dlsym(handle, "glMultiTexCoord2dv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2dv(target, *v);
}

// -- glMultiTexCoord2f
void (*_glMultiTexCoord2f)() = NULL;
            
void glMultiTexCoord2f( GLenum target, GLfloat s, GLfloat t )
{
    if (_glMultiTexCoord2f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2f = dlsym(handle, "glMultiTexCoord2f");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2f(target, s, t);
}

// -- glMultiTexCoord2fv
void (*_glMultiTexCoord2fv)() = NULL;
            
void glMultiTexCoord2fv( GLenum target, const GLfloat *v )
{
    if (_glMultiTexCoord2fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2fv = dlsym(handle, "glMultiTexCoord2fv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2fv(target, *v);
}

// -- glMultiTexCoord2i
void (*_glMultiTexCoord2i)() = NULL;
            
void glMultiTexCoord2i( GLenum target, GLint s, GLint t )
{
    if (_glMultiTexCoord2i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2i = dlsym(handle, "glMultiTexCoord2i");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2i(target, s, t);
}

// -- glMultiTexCoord2iv
void (*_glMultiTexCoord2iv)() = NULL;
            
void glMultiTexCoord2iv( GLenum target, const GLint *v )
{
    if (_glMultiTexCoord2iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2iv = dlsym(handle, "glMultiTexCoord2iv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2iv(target, *v);
}

// -- glMultiTexCoord2s
void (*_glMultiTexCoord2s)() = NULL;
            
void glMultiTexCoord2s( GLenum target, GLshort s, GLshort t )
{
    if (_glMultiTexCoord2s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2s = dlsym(handle, "glMultiTexCoord2s");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2s(target, s, t);
}

// -- glMultiTexCoord2sv
void (*_glMultiTexCoord2sv)() = NULL;
            
void glMultiTexCoord2sv( GLenum target, const GLshort *v )
{
    if (_glMultiTexCoord2sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2sv = dlsym(handle, "glMultiTexCoord2sv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2sv(target, *v);
}

// -- glMultiTexCoord3d
void (*_glMultiTexCoord3d)() = NULL;
            
void glMultiTexCoord3d( GLenum target, GLdouble s, GLdouble t, GLdouble r )
{
    if (_glMultiTexCoord3d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3d = dlsym(handle, "glMultiTexCoord3d");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3d(target, s, t, r);
}

// -- glMultiTexCoord3dv
void (*_glMultiTexCoord3dv)() = NULL;
            
void glMultiTexCoord3dv( GLenum target, const GLdouble *v )
{
    if (_glMultiTexCoord3dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3dv = dlsym(handle, "glMultiTexCoord3dv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3dv(target, *v);
}

// -- glMultiTexCoord3f
void (*_glMultiTexCoord3f)() = NULL;
            
void glMultiTexCoord3f( GLenum target, GLfloat s, GLfloat t, GLfloat r )
{
    if (_glMultiTexCoord3f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3f = dlsym(handle, "glMultiTexCoord3f");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3f(target, s, t, r);
}

// -- glMultiTexCoord3fv
void (*_glMultiTexCoord3fv)() = NULL;
            
void glMultiTexCoord3fv( GLenum target, const GLfloat *v )
{
    if (_glMultiTexCoord3fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3fv = dlsym(handle, "glMultiTexCoord3fv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3fv(target, *v);
}

// -- glMultiTexCoord3i
void (*_glMultiTexCoord3i)() = NULL;
            
void glMultiTexCoord3i( GLenum target, GLint s, GLint t, GLint r )
{
    if (_glMultiTexCoord3i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3i = dlsym(handle, "glMultiTexCoord3i");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3i(target, s, t, r);
}

// -- glMultiTexCoord3iv
void (*_glMultiTexCoord3iv)() = NULL;
            
void glMultiTexCoord3iv( GLenum target, const GLint *v )
{
    if (_glMultiTexCoord3iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3iv = dlsym(handle, "glMultiTexCoord3iv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3iv(target, *v);
}

// -- glMultiTexCoord3s
void (*_glMultiTexCoord3s)() = NULL;
            
void glMultiTexCoord3s( GLenum target, GLshort s, GLshort t, GLshort r )
{
    if (_glMultiTexCoord3s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3s = dlsym(handle, "glMultiTexCoord3s");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3s(target, s, t, r);
}

// -- glMultiTexCoord3sv
void (*_glMultiTexCoord3sv)() = NULL;
            
void glMultiTexCoord3sv( GLenum target, const GLshort *v )
{
    if (_glMultiTexCoord3sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3sv = dlsym(handle, "glMultiTexCoord3sv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3sv(target, *v);
}

// -- glMultiTexCoord4d
void (*_glMultiTexCoord4d)() = NULL;
            
void glMultiTexCoord4d( GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q )
{
    if (_glMultiTexCoord4d == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4d = dlsym(handle, "glMultiTexCoord4d");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4d(target, s, t, r, q);
}

// -- glMultiTexCoord4dv
void (*_glMultiTexCoord4dv)() = NULL;
            
void glMultiTexCoord4dv( GLenum target, const GLdouble *v )
{
    if (_glMultiTexCoord4dv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4dv = dlsym(handle, "glMultiTexCoord4dv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4dv(target, *v);
}

// -- glMultiTexCoord4f
void (*_glMultiTexCoord4f)() = NULL;
            
void glMultiTexCoord4f( GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q )
{
    if (_glMultiTexCoord4f == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4f = dlsym(handle, "glMultiTexCoord4f");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4f(target, s, t, r, q);
}

// -- glMultiTexCoord4fv
void (*_glMultiTexCoord4fv)() = NULL;
            
void glMultiTexCoord4fv( GLenum target, const GLfloat *v )
{
    if (_glMultiTexCoord4fv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4fv = dlsym(handle, "glMultiTexCoord4fv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4fv(target, *v);
}

// -- glMultiTexCoord4i
void (*_glMultiTexCoord4i)() = NULL;
            
void glMultiTexCoord4i( GLenum target, GLint s, GLint t, GLint r, GLint q )
{
    if (_glMultiTexCoord4i == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4i = dlsym(handle, "glMultiTexCoord4i");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4i(target, s, t, r, q);
}

// -- glMultiTexCoord4iv
void (*_glMultiTexCoord4iv)() = NULL;
            
void glMultiTexCoord4iv( GLenum target, const GLint *v )
{
    if (_glMultiTexCoord4iv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4iv = dlsym(handle, "glMultiTexCoord4iv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4iv(target, *v);
}

// -- glMultiTexCoord4s
void (*_glMultiTexCoord4s)() = NULL;
            
void glMultiTexCoord4s( GLenum target, GLshort s, GLshort t, GLshort r, GLshort q )
{
    if (_glMultiTexCoord4s == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4s = dlsym(handle, "glMultiTexCoord4s");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4s(target, s, t, r, q);
}

// -- glMultiTexCoord4sv
void (*_glMultiTexCoord4sv)() = NULL;
            
void glMultiTexCoord4sv( GLenum target, const GLshort *v )
{
    if (_glMultiTexCoord4sv == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4sv = dlsym(handle, "glMultiTexCoord4sv");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4sv(target, *v);
}

// -- glLoadTransposeMatrixd
void (*_glLoadTransposeMatrixd)() = NULL;
            
void glLoadTransposeMatrixd( const GLdouble m[16] )
{
    if (_glLoadTransposeMatrixd == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLoadTransposeMatrixd = dlsym(handle, "glLoadTransposeMatrixd");
            dlclose(handle);
        }
    }
    
    _glLoadTransposeMatrixd(m[16]);
}

// -- glLoadTransposeMatrixf
void (*_glLoadTransposeMatrixf)() = NULL;
            
void glLoadTransposeMatrixf( const GLfloat m[16] )
{
    if (_glLoadTransposeMatrixf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glLoadTransposeMatrixf = dlsym(handle, "glLoadTransposeMatrixf");
            dlclose(handle);
        }
    }
    
    _glLoadTransposeMatrixf(m[16]);
}

// -- glMultTransposeMatrixd
void (*_glMultTransposeMatrixd)() = NULL;
            
void glMultTransposeMatrixd( const GLdouble m[16] )
{
    if (_glMultTransposeMatrixd == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultTransposeMatrixd = dlsym(handle, "glMultTransposeMatrixd");
            dlclose(handle);
        }
    }
    
    _glMultTransposeMatrixd(m[16]);
}

// -- glMultTransposeMatrixf
void (*_glMultTransposeMatrixf)() = NULL;
            
void glMultTransposeMatrixf( const GLfloat m[16] )
{
    if (_glMultTransposeMatrixf == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultTransposeMatrixf = dlsym(handle, "glMultTransposeMatrixf");
            dlclose(handle);
        }
    }
    
    _glMultTransposeMatrixf(m[16]);
}

// -- glSampleCoverage
void (*_glSampleCoverage)() = NULL;
            
void glSampleCoverage( GLclampf value, GLboolean invert )
{
    if (_glSampleCoverage == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glSampleCoverage = dlsym(handle, "glSampleCoverage");
            dlclose(handle);
        }
    }
    
    _glSampleCoverage(value, invert);
}

// -- glActiveTextureARB
void (*_glActiveTextureARB)() = NULL;
            
void glActiveTextureARB(GLenum texture)
{
    if (_glActiveTextureARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glActiveTextureARB = dlsym(handle, "glActiveTextureARB");
            dlclose(handle);
        }
    }
    
    _glActiveTextureARB(texture);
}

// -- glClientActiveTextureARB
void (*_glClientActiveTextureARB)() = NULL;
            
void glClientActiveTextureARB(GLenum texture)
{
    if (_glClientActiveTextureARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glClientActiveTextureARB = dlsym(handle, "glClientActiveTextureARB");
            dlclose(handle);
        }
    }
    
    _glClientActiveTextureARB(texture);
}

// -- glMultiTexCoord1dARB
void (*_glMultiTexCoord1dARB)() = NULL;
            
void glMultiTexCoord1dARB(GLenum target, GLdouble s)
{
    if (_glMultiTexCoord1dARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1dARB = dlsym(handle, "glMultiTexCoord1dARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1dARB(target, s);
}

// -- glMultiTexCoord1dvARB
void (*_glMultiTexCoord1dvARB)() = NULL;
            
void glMultiTexCoord1dvARB(GLenum target, const GLdouble *v)
{
    if (_glMultiTexCoord1dvARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1dvARB = dlsym(handle, "glMultiTexCoord1dvARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1dvARB(target, *v);
}

// -- glMultiTexCoord1fARB
void (*_glMultiTexCoord1fARB)() = NULL;
            
void glMultiTexCoord1fARB(GLenum target, GLfloat s)
{
    if (_glMultiTexCoord1fARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1fARB = dlsym(handle, "glMultiTexCoord1fARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1fARB(target, s);
}

// -- glMultiTexCoord1fvARB
void (*_glMultiTexCoord1fvARB)() = NULL;
            
void glMultiTexCoord1fvARB(GLenum target, const GLfloat *v)
{
    if (_glMultiTexCoord1fvARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1fvARB = dlsym(handle, "glMultiTexCoord1fvARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1fvARB(target, *v);
}

// -- glMultiTexCoord1iARB
void (*_glMultiTexCoord1iARB)() = NULL;
            
void glMultiTexCoord1iARB(GLenum target, GLint s)
{
    if (_glMultiTexCoord1iARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1iARB = dlsym(handle, "glMultiTexCoord1iARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1iARB(target, s);
}

// -- glMultiTexCoord1ivARB
void (*_glMultiTexCoord1ivARB)() = NULL;
            
void glMultiTexCoord1ivARB(GLenum target, const GLint *v)
{
    if (_glMultiTexCoord1ivARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1ivARB = dlsym(handle, "glMultiTexCoord1ivARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1ivARB(target, *v);
}

// -- glMultiTexCoord1sARB
void (*_glMultiTexCoord1sARB)() = NULL;
            
void glMultiTexCoord1sARB(GLenum target, GLshort s)
{
    if (_glMultiTexCoord1sARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1sARB = dlsym(handle, "glMultiTexCoord1sARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1sARB(target, s);
}

// -- glMultiTexCoord1svARB
void (*_glMultiTexCoord1svARB)() = NULL;
            
void glMultiTexCoord1svARB(GLenum target, const GLshort *v)
{
    if (_glMultiTexCoord1svARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord1svARB = dlsym(handle, "glMultiTexCoord1svARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord1svARB(target, *v);
}

// -- glMultiTexCoord2dARB
void (*_glMultiTexCoord2dARB)() = NULL;
            
void glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t)
{
    if (_glMultiTexCoord2dARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2dARB = dlsym(handle, "glMultiTexCoord2dARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2dARB(target, s, t);
}

// -- glMultiTexCoord2dvARB
void (*_glMultiTexCoord2dvARB)() = NULL;
            
void glMultiTexCoord2dvARB(GLenum target, const GLdouble *v)
{
    if (_glMultiTexCoord2dvARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2dvARB = dlsym(handle, "glMultiTexCoord2dvARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2dvARB(target, *v);
}

// -- glMultiTexCoord2fARB
void (*_glMultiTexCoord2fARB)() = NULL;
            
void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t)
{
    if (_glMultiTexCoord2fARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2fARB = dlsym(handle, "glMultiTexCoord2fARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2fARB(target, s, t);
}

// -- glMultiTexCoord2fvARB
void (*_glMultiTexCoord2fvARB)() = NULL;
            
void glMultiTexCoord2fvARB(GLenum target, const GLfloat *v)
{
    if (_glMultiTexCoord2fvARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2fvARB = dlsym(handle, "glMultiTexCoord2fvARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2fvARB(target, *v);
}

// -- glMultiTexCoord2iARB
void (*_glMultiTexCoord2iARB)() = NULL;
            
void glMultiTexCoord2iARB(GLenum target, GLint s, GLint t)
{
    if (_glMultiTexCoord2iARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2iARB = dlsym(handle, "glMultiTexCoord2iARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2iARB(target, s, t);
}

// -- glMultiTexCoord2ivARB
void (*_glMultiTexCoord2ivARB)() = NULL;
            
void glMultiTexCoord2ivARB(GLenum target, const GLint *v)
{
    if (_glMultiTexCoord2ivARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2ivARB = dlsym(handle, "glMultiTexCoord2ivARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2ivARB(target, *v);
}

// -- glMultiTexCoord2sARB
void (*_glMultiTexCoord2sARB)() = NULL;
            
void glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t)
{
    if (_glMultiTexCoord2sARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2sARB = dlsym(handle, "glMultiTexCoord2sARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2sARB(target, s, t);
}

// -- glMultiTexCoord2svARB
void (*_glMultiTexCoord2svARB)() = NULL;
            
void glMultiTexCoord2svARB(GLenum target, const GLshort *v)
{
    if (_glMultiTexCoord2svARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord2svARB = dlsym(handle, "glMultiTexCoord2svARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord2svARB(target, *v);
}

// -- glMultiTexCoord3dARB
void (*_glMultiTexCoord3dARB)() = NULL;
            
void glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r)
{
    if (_glMultiTexCoord3dARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3dARB = dlsym(handle, "glMultiTexCoord3dARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3dARB(target, s, t, r);
}

// -- glMultiTexCoord3dvARB
void (*_glMultiTexCoord3dvARB)() = NULL;
            
void glMultiTexCoord3dvARB(GLenum target, const GLdouble *v)
{
    if (_glMultiTexCoord3dvARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3dvARB = dlsym(handle, "glMultiTexCoord3dvARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3dvARB(target, *v);
}

// -- glMultiTexCoord3fARB
void (*_glMultiTexCoord3fARB)() = NULL;
            
void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r)
{
    if (_glMultiTexCoord3fARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3fARB = dlsym(handle, "glMultiTexCoord3fARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3fARB(target, s, t, r);
}

// -- glMultiTexCoord3fvARB
void (*_glMultiTexCoord3fvARB)() = NULL;
            
void glMultiTexCoord3fvARB(GLenum target, const GLfloat *v)
{
    if (_glMultiTexCoord3fvARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3fvARB = dlsym(handle, "glMultiTexCoord3fvARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3fvARB(target, *v);
}

// -- glMultiTexCoord3iARB
void (*_glMultiTexCoord3iARB)() = NULL;
            
void glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r)
{
    if (_glMultiTexCoord3iARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3iARB = dlsym(handle, "glMultiTexCoord3iARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3iARB(target, s, t, r);
}

// -- glMultiTexCoord3ivARB
void (*_glMultiTexCoord3ivARB)() = NULL;
            
void glMultiTexCoord3ivARB(GLenum target, const GLint *v)
{
    if (_glMultiTexCoord3ivARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3ivARB = dlsym(handle, "glMultiTexCoord3ivARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3ivARB(target, *v);
}

// -- glMultiTexCoord3sARB
void (*_glMultiTexCoord3sARB)() = NULL;
            
void glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r)
{
    if (_glMultiTexCoord3sARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3sARB = dlsym(handle, "glMultiTexCoord3sARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3sARB(target, s, t, r);
}

// -- glMultiTexCoord3svARB
void (*_glMultiTexCoord3svARB)() = NULL;
            
void glMultiTexCoord3svARB(GLenum target, const GLshort *v)
{
    if (_glMultiTexCoord3svARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord3svARB = dlsym(handle, "glMultiTexCoord3svARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord3svARB(target, *v);
}

// -- glMultiTexCoord4dARB
void (*_glMultiTexCoord4dARB)() = NULL;
            
void glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
    if (_glMultiTexCoord4dARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4dARB = dlsym(handle, "glMultiTexCoord4dARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4dARB(target, s, t, r, q);
}

// -- glMultiTexCoord4dvARB
void (*_glMultiTexCoord4dvARB)() = NULL;
            
void glMultiTexCoord4dvARB(GLenum target, const GLdouble *v)
{
    if (_glMultiTexCoord4dvARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4dvARB = dlsym(handle, "glMultiTexCoord4dvARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4dvARB(target, *v);
}

// -- glMultiTexCoord4fARB
void (*_glMultiTexCoord4fARB)() = NULL;
            
void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
    if (_glMultiTexCoord4fARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4fARB = dlsym(handle, "glMultiTexCoord4fARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4fARB(target, s, t, r, q);
}

// -- glMultiTexCoord4fvARB
void (*_glMultiTexCoord4fvARB)() = NULL;
            
void glMultiTexCoord4fvARB(GLenum target, const GLfloat *v)
{
    if (_glMultiTexCoord4fvARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4fvARB = dlsym(handle, "glMultiTexCoord4fvARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4fvARB(target, *v);
}

// -- glMultiTexCoord4iARB
void (*_glMultiTexCoord4iARB)() = NULL;
            
void glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q)
{
    if (_glMultiTexCoord4iARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4iARB = dlsym(handle, "glMultiTexCoord4iARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4iARB(target, s, t, r, q);
}

// -- glMultiTexCoord4ivARB
void (*_glMultiTexCoord4ivARB)() = NULL;
            
void glMultiTexCoord4ivARB(GLenum target, const GLint *v)
{
    if (_glMultiTexCoord4ivARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4ivARB = dlsym(handle, "glMultiTexCoord4ivARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4ivARB(target, *v);
}

// -- glMultiTexCoord4sARB
void (*_glMultiTexCoord4sARB)() = NULL;
            
void glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
{
    if (_glMultiTexCoord4sARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4sARB = dlsym(handle, "glMultiTexCoord4sARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4sARB(target, s, t, r, q);
}

// -- glMultiTexCoord4svARB
void (*_glMultiTexCoord4svARB)() = NULL;
            
void glMultiTexCoord4svARB(GLenum target, const GLshort *v)
{
    if (_glMultiTexCoord4svARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glMultiTexCoord4svARB = dlsym(handle, "glMultiTexCoord4svARB");
            dlclose(handle);
        }
    }
    
    _glMultiTexCoord4svARB(target, *v);
}

// -- glBlendEquationSeparateATI
void (*_glBlendEquationSeparateATI)() = NULL;
            
void glBlendEquationSeparateATI( GLenum modeRGB, GLenum modeA )
{
    if (_glBlendEquationSeparateATI == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glBlendEquationSeparateATI = dlsym(handle, "glBlendEquationSeparateATI");
            dlclose(handle);
        }
    }
    
    _glBlendEquationSeparateATI(modeRGB, modeA);
}

