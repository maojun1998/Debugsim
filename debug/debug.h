#ifndef __DEBUG__   // DEBUG.H
#define __DEBUG__

//
//  just for debug. dprintf for dprintf
//
#if DBG
void dprintf(const char *fmt, ...);
#else 
#define dprintf()   \
    do {            \
                    \
    } while (0)
#endif //dbg

//
//  Init the deubg System, just open the file debug.log.
//
#if DBG
void Init_Debug(void);
#else 
#define dprintf()   \
    do {            \
                    \
    } while (0)
#endif //dbg

//
//  Release the debug System, just close the file debug.log.
//
#if DBG
void Release_Debug(void);
#else 
#define dprintf()   \
    do {            \
                    \
    } while (0)
#endif //dbg

#endif // DEBUG.H