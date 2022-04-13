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

// -- Glx Hook Functions --
// -- glXDestroyContext
void (*_glXDestroyContext)() = NULL;
            
void glXDestroyContext( Display *dpy, GLXContext ctx )
{
    if (_glXDestroyContext == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXDestroyContext = dlsym(handle, "glXDestroyContext");
            dlclose(handle);
        }
    }
    
    _glXDestroyContext(*dpy, ctx);
}

// -- glXSwapBuffers
void (*_glXSwapBuffers)() = NULL;
            
void glXSwapBuffers( Display *dpy, GLXDrawable drawable )
{
    if (_glXSwapBuffers == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXSwapBuffers = dlsym(handle, "glXSwapBuffers");
            dlclose(handle);
        }
    }
    
    _glXSwapBuffers(*dpy, drawable);
}

// -- glXDestroyGLXPixmap
void (*_glXDestroyGLXPixmap)() = NULL;
            
void glXDestroyGLXPixmap( Display *dpy, GLXPixmap pixmap )
{
    if (_glXDestroyGLXPixmap == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXDestroyGLXPixmap = dlsym(handle, "glXDestroyGLXPixmap");
            dlclose(handle);
        }
    }
    
    _glXDestroyGLXPixmap(*dpy, pixmap);
}

// -- glXQueryExtension
Bool (*_glXQueryExtension)() = NULL;
        
Bool glXQueryExtension( Display *dpy, int *errorb, int *event )
{
    if (_glXQueryExtension == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXQueryExtension = dlsym(handle, "glXQueryExtension");
            dlclose(handle);
        }
    }

    return _glXQueryExtension(*dpy, *errorb, *event);
}

// -- glXQueryVersion
Bool (*_glXQueryVersion)() = NULL;
        
Bool glXQueryVersion( Display *dpy, int *maj, int *min )
{
    if (_glXQueryVersion == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXQueryVersion = dlsym(handle, "glXQueryVersion");
            dlclose(handle);
        }
    }

    return _glXQueryVersion(*dpy, *maj, *min);
}

// -- glXIsDirect
Bool (*_glXIsDirect)() = NULL;
        
Bool glXIsDirect( Display *dpy, GLXContext ctx )
{
    if (_glXIsDirect == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXIsDirect = dlsym(handle, "glXIsDirect");
            dlclose(handle);
        }
    }

    return _glXIsDirect(*dpy, ctx);
}

// -- glXGetCurrentContext
GLXContext (*_glXGetCurrentContext)() = NULL;
        
GLXContext glXGetCurrentContext()
{
    if (_glXGetCurrentContext == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXGetCurrentContext = dlsym(handle, "glXGetCurrentContext");
            dlclose(handle);
        }
    }

    return _glXGetCurrentContext();
}

// -- glXGetCurrentDrawable
GLXDrawable (*_glXGetCurrentDrawable)() = NULL;
        
GLXDrawable glXGetCurrentDrawable()
{
    if (_glXGetCurrentDrawable == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXGetCurrentDrawable = dlsym(handle, "glXGetCurrentDrawable");
            dlclose(handle);
        }
    }

    return _glXGetCurrentDrawable();
}

// -- glXWaitGL
void (*_glXWaitGL)() = NULL;
            
void glXWaitGL()
{
    if (_glXWaitGL == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXWaitGL = dlsym(handle, "glXWaitGL");
            dlclose(handle);
        }
    }
    
    _glXWaitGL();
}

// -- glXWaitX
void (*_glXWaitX)() = NULL;
            
void glXWaitX()
{
    if (_glXWaitX == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXWaitX = dlsym(handle, "glXWaitX");
            dlclose(handle);
        }
    }
    
    _glXWaitX();
}

// -- glXUseXFont
void (*_glXUseXFont)() = NULL;
            
void glXUseXFont( Font font, int first, int count, int list )
{
    if (_glXUseXFont == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXUseXFont = dlsym(handle, "glXUseXFont");
            dlclose(handle);
        }
    }
    
    _glXUseXFont(font, first, count, list);
}

// -- char *glXQueryExtensionsString
const (*_char *glXQueryExtensionsString)() = NULL;
        
const char *glXQueryExtensionsString( Display *dpy, int screen )
{
    if (_char *glXQueryExtensionsString == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _char *glXQueryExtensionsString = dlsym(handle, "char *glXQueryExtensionsString");
            dlclose(handle);
        }
    }

    return _char *glXQueryExtensionsString(*dpy, screen);
}

// -- char *glXQueryServerString
const (*_char *glXQueryServerString)() = NULL;
        
const char *glXQueryServerString( Display *dpy, int screen, int name )
{
    if (_char *glXQueryServerString == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _char *glXQueryServerString = dlsym(handle, "char *glXQueryServerString");
            dlclose(handle);
        }
    }

    return _char *glXQueryServerString(*dpy, screen, name);
}

// -- char *glXGetClientString
const (*_char *glXGetClientString)() = NULL;
        
const char *glXGetClientString( Display *dpy, int name )
{
    if (_char *glXGetClientString == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _char *glXGetClientString = dlsym(handle, "char *glXGetClientString");
            dlclose(handle);
        }
    }

    return _char *glXGetClientString(*dpy, name);
}

// -- *glXGetCurrentDisplay
Display (*_*glXGetCurrentDisplay)() = NULL;
        
Display *glXGetCurrentDisplay()
{
    if (_*glXGetCurrentDisplay == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _*glXGetCurrentDisplay = dlsym(handle, "*glXGetCurrentDisplay");
            dlclose(handle);
        }
    }

    return _*glXGetCurrentDisplay();
}

// -- glXDestroyWindow
void (*_glXDestroyWindow)() = NULL;
            
void glXDestroyWindow( Display *dpy, GLXWindow window )
{
    if (_glXDestroyWindow == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXDestroyWindow = dlsym(handle, "glXDestroyWindow");
            dlclose(handle);
        }
    }
    
    _glXDestroyWindow(*dpy, window);
}

// -- glXDestroyPixmap
void (*_glXDestroyPixmap)() = NULL;
            
void glXDestroyPixmap( Display *dpy, GLXPixmap pixmap )
{
    if (_glXDestroyPixmap == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXDestroyPixmap = dlsym(handle, "glXDestroyPixmap");
            dlclose(handle);
        }
    }
    
    _glXDestroyPixmap(*dpy, pixmap);
}

// -- glXDestroyPbuffer
void (*_glXDestroyPbuffer)() = NULL;
            
void glXDestroyPbuffer( Display *dpy, GLXPbuffer pbuf )
{
    if (_glXDestroyPbuffer == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXDestroyPbuffer = dlsym(handle, "glXDestroyPbuffer");
            dlclose(handle);
        }
    }
    
    _glXDestroyPbuffer(*dpy, pbuf);
}

// -- glXGetCurrentReadDrawable
GLXDrawable (*_glXGetCurrentReadDrawable)() = NULL;
        
GLXDrawable glXGetCurrentReadDrawable()
{
    if (_glXGetCurrentReadDrawable == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXGetCurrentReadDrawable = dlsym(handle, "glXGetCurrentReadDrawable");
            dlclose(handle);
        }
    }

    return _glXGetCurrentReadDrawable();
}

// -- glXGetProcAddressARB 
__GLXextFuncPtr (*_glXGetProcAddressARB )() = NULL;
        
__GLXextFuncPtr glXGetProcAddressARB (const GLubyte *)
{
    if (_glXGetProcAddressARB  == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXGetProcAddressARB  = dlsym(handle, "glXGetProcAddressARB ");
            dlclose(handle);
        }
    }

    return _glXGetProcAddressARB ();
}

// -- 
void (*_)() = NULL;
            
void (*glXGetProcAddress(const GLubyte *procname)
{
    if (_ == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _ = dlsym(handle, "");
            dlclose(handle);
        }
    }
    
    _(GLubyte);
}

// -- *glXAllocateMemoryNV
void (*_*glXAllocateMemoryNV)() = NULL;
            
void *glXAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority)
{
    if (_*glXAllocateMemoryNV == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _*glXAllocateMemoryNV = dlsym(handle, "*glXAllocateMemoryNV");
            dlclose(handle);
        }
    }
    
    _*glXAllocateMemoryNV(size, readfreq, writefreq, priority);
}

// -- glXFreeMemoryNV
void (*_glXFreeMemoryNV)() = NULL;
            
void glXFreeMemoryNV(GLvoid *pointer)
{
    if (_glXFreeMemoryNV == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXFreeMemoryNV = dlsym(handle, "glXFreeMemoryNV");
            dlclose(handle);
        }
    }
    
    _glXFreeMemoryNV(*pointer);
}

// -- glXBindTexImageARB
Bool (*_glXBindTexImageARB)() = NULL;
        
Bool glXBindTexImageARB(Display *dpy, GLXPbuffer pbuffer, int buffer)
{
    if (_glXBindTexImageARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXBindTexImageARB = dlsym(handle, "glXBindTexImageARB");
            dlclose(handle);
        }
    }

    return _glXBindTexImageARB(*dpy, pbuffer, buffer);
}

// -- glXReleaseTexImageARB
Bool (*_glXReleaseTexImageARB)() = NULL;
        
Bool glXReleaseTexImageARB(Display *dpy, GLXPbuffer pbuffer, int buffer)
{
    if (_glXReleaseTexImageARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXReleaseTexImageARB = dlsym(handle, "glXReleaseTexImageARB");
            dlclose(handle);
        }
    }

    return _glXReleaseTexImageARB(*dpy, pbuffer, buffer);
}

// -- glXDrawableAttribARB
Bool (*_glXDrawableAttribARB)() = NULL;
        
Bool glXDrawableAttribARB(Display *dpy, GLXDrawable draw, const int *attribList)
{
    if (_glXDrawableAttribARB == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXDrawableAttribARB = dlsym(handle, "glXDrawableAttribARB");
            dlclose(handle);
        }
    }

    return _glXDrawableAttribARB(*dpy, draw, *attribList);
}

// -- glXGetFrameUsageMESA
int (*_glXGetFrameUsageMESA)() = NULL;
        
int glXGetFrameUsageMESA(Display *dpy, GLXDrawable drawable, float *usage)
{
    if (_glXGetFrameUsageMESA == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXGetFrameUsageMESA = dlsym(handle, "glXGetFrameUsageMESA");
            dlclose(handle);
        }
    }

    return _glXGetFrameUsageMESA(*dpy, drawable, *usage);
}

// -- glXBeginFrameTrackingMESA
int (*_glXBeginFrameTrackingMESA)() = NULL;
        
int glXBeginFrameTrackingMESA(Display *dpy, GLXDrawable drawable)
{
    if (_glXBeginFrameTrackingMESA == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXBeginFrameTrackingMESA = dlsym(handle, "glXBeginFrameTrackingMESA");
            dlclose(handle);
        }
    }

    return _glXBeginFrameTrackingMESA(*dpy, drawable);
}

// -- glXEndFrameTrackingMESA
int (*_glXEndFrameTrackingMESA)() = NULL;
        
int glXEndFrameTrackingMESA(Display *dpy, GLXDrawable drawable)
{
    if (_glXEndFrameTrackingMESA == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXEndFrameTrackingMESA = dlsym(handle, "glXEndFrameTrackingMESA");
            dlclose(handle);
        }
    }

    return _glXEndFrameTrackingMESA(*dpy, drawable);
}

// -- glXQueryFrameTrackingMESA
int (*_glXQueryFrameTrackingMESA)() = NULL;
        
int glXQueryFrameTrackingMESA(Display *dpy, GLXDrawable drawable, int64_t *swapCount, int64_t *missedFrames, float *lastMissedUsage)
{
    if (_glXQueryFrameTrackingMESA == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXQueryFrameTrackingMESA = dlsym(handle, "glXQueryFrameTrackingMESA");
            dlclose(handle);
        }
    }

    return _glXQueryFrameTrackingMESA(*dpy, drawable, *swapCount, *missedFrames, *lastMissedUsage);
}

// -- glXSwapIntervalMESA
int (*_glXSwapIntervalMESA)() = NULL;
        
int glXSwapIntervalMESA(unsigned int interval)
{
    if (_glXSwapIntervalMESA == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXSwapIntervalMESA = dlsym(handle, "glXSwapIntervalMESA");
            dlclose(handle);
        }
    }

    return _glXSwapIntervalMESA(int);
}

// -- glXGetSwapIntervalMESA
int (*_glXGetSwapIntervalMESA)() = NULL;
        
int glXGetSwapIntervalMESA()
{
    if (_glXGetSwapIntervalMESA == NULL) {
    void *handle = dlopen("libGL.so", RTLD_LAZY);
        if (handle) {
            _glXGetSwapIntervalMESA = dlsym(handle, "glXGetSwapIntervalMESA");
            dlclose(handle);
        }
    }

    return _glXGetSwapIntervalMESA();
}

