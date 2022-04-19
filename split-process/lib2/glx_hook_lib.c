#include <GL/gl.h>
#include <GL/glx.h>
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
void glXDestroyContext( Display *dpy, GLXContext ctx )
{
    printf("gl stub called: glXDestroyContext");
}

// -- glXSwapBuffers            
void glXSwapBuffers( Display *dpy, GLXDrawable drawable )
{
    printf("gl stub called: glXSwapBuffers");
}

// -- glXDestroyGLXPixmap            
void glXDestroyGLXPixmap( Display *dpy, GLXPixmap pixmap )
{
    printf("gl stub called: glXDestroyGLXPixmap");
}

// -- glXQueryExtension        
Bool glXQueryExtension( Display *dpy, int *errorb, int *event )
{
    printf("Glx stub called: glXQueryExtension");
}

// -- glXQueryVersion        
Bool glXQueryVersion( Display *dpy, int *maj, int *min )
{
    printf("Glx stub called: glXQueryVersion");
}

// -- glXIsDirect        
Bool glXIsDirect( Display *dpy, GLXContext ctx )
{
    printf("Glx stub called: glXIsDirect");
}

// -- glXGetCurrentContext        
GLXContext glXGetCurrentContext()
{
    printf("Glx stub called: glXGetCurrentContext");
}

// -- glXGetCurrentDrawable        
GLXDrawable glXGetCurrentDrawable()
{
    printf("Glx stub called: glXGetCurrentDrawable");
}

// -- glXWaitGL            
void glXWaitGL()
{
    printf("gl stub called: glXWaitGL");
}

// -- glXWaitX            
void glXWaitX()
{
    printf("gl stub called: glXWaitX");
}

// -- glXUseXFont            
void glXUseXFont( Font font, int first, int count, int list )
{
    printf("gl stub called: glXUseXFont");
}

// -- char *glXQueryExtensionsString        
const char *glXQueryExtensionsString( Display *dpy, int screen )
{
    printf("Glx stub called: char *glXQueryExtensionsString");
}

// -- char *glXQueryServerString        
const char *glXQueryServerString( Display *dpy, int screen, int name )
{
    printf("Glx stub called: char *glXQueryServerString");
}

// -- char *glXGetClientString        
const char *glXGetClientString( Display *dpy, int name )
{
    printf("Glx stub called: char *glXGetClientString");
}

// -- *glXGetCurrentDisplay        
Display *glXGetCurrentDisplay()
{
    printf("Glx stub called: *glXGetCurrentDisplay");
}

// -- glXDestroyWindow            
void glXDestroyWindow( Display *dpy, GLXWindow window )
{
    printf("gl stub called: glXDestroyWindow");
}

// -- glXDestroyPixmap            
void glXDestroyPixmap( Display *dpy, GLXPixmap pixmap )
{
    printf("gl stub called: glXDestroyPixmap");
}

// -- glXDestroyPbuffer            
void glXDestroyPbuffer( Display *dpy, GLXPbuffer pbuf )
{
    printf("gl stub called: glXDestroyPbuffer");
}

// -- glXGetCurrentReadDrawable        
GLXDrawable glXGetCurrentReadDrawable()
{
    printf("Glx stub called: glXGetCurrentReadDrawable");
}

// -- glXGetProcAddressARB         
__GLXextFuncPtr glXGetProcAddressARB (const GLubyte *)
{
    printf("Glx stub called: glXGetProcAddressARB ");
}

// --             
void (*glXGetProcAddress(const GLubyte *procname)
{
    printf("gl stub called: ");
}

// -- *glXAllocateMemoryNV            
void *glXAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority)
{
    printf("gl stub called: *glXAllocateMemoryNV");
}

// -- glXFreeMemoryNV            
void glXFreeMemoryNV(GLvoid *pointer)
{
    printf("gl stub called: glXFreeMemoryNV");
}

// -- glXBindTexImageARB        
Bool glXBindTexImageARB(Display *dpy, GLXPbuffer pbuffer, int buffer)
{
    printf("Glx stub called: glXBindTexImageARB");
}

// -- glXReleaseTexImageARB        
Bool glXReleaseTexImageARB(Display *dpy, GLXPbuffer pbuffer, int buffer)
{
    printf("Glx stub called: glXReleaseTexImageARB");
}

// -- glXDrawableAttribARB        
Bool glXDrawableAttribARB(Display *dpy, GLXDrawable draw, const int *attribList)
{
    printf("Glx stub called: glXDrawableAttribARB");
}

// -- glXGetFrameUsageMESA        
int glXGetFrameUsageMESA(Display *dpy, GLXDrawable drawable, float *usage)
{
    printf("Glx stub called: glXGetFrameUsageMESA");
}

// -- glXBeginFrameTrackingMESA        
int glXBeginFrameTrackingMESA(Display *dpy, GLXDrawable drawable)
{
    printf("Glx stub called: glXBeginFrameTrackingMESA");
}

// -- glXEndFrameTrackingMESA        
int glXEndFrameTrackingMESA(Display *dpy, GLXDrawable drawable)
{
    printf("Glx stub called: glXEndFrameTrackingMESA");
}

// -- glXQueryFrameTrackingMESA        
int glXQueryFrameTrackingMESA(Display *dpy, GLXDrawable drawable, int64_t *swapCount, int64_t *missedFrames, float *lastMissedUsage)
{
    printf("Glx stub called: glXQueryFrameTrackingMESA");
}

// -- glXSwapIntervalMESA        
int glXSwapIntervalMESA(unsigned int interval)
{
    printf("Glx stub called: glXSwapIntervalMESA");
}

// -- glXGetSwapIntervalMESA        
int glXGetSwapIntervalMESA()
{
    printf("Glx stub called: glXGetSwapIntervalMESA");
}

