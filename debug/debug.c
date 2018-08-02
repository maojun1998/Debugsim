#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <time.h>


static FILE *Debug;

void dprintf(const char *fmt, ...)
{
    va_list args;
    const char *pString;
    time_t times;
    struct tm *localTimes;
    
    int d;
    void *p;
    char *s;
    char ccc;
    
    va_start(args, fmt);
    time(&times);
    localTimes = localtime (&times);
    
    fprintf(Debug, "* %d/%d/%d %d:%d:%d    : " ,localTimes->tm_year+1900, 
            localTimes->tm_mon +1, localTimes->tm_mday, localTimes->tm_hour, 
            localTimes->tm_min, localTimes->tm_sec);

    pString = fmt;
    
    while (pString[0]) {
        if (pString[0] == '%') {
            if (pString[1] == 'd') {
                d = va_arg(args, int);
                fprintf(Debug, "%d", d);
                pString += 2;
            } else if (pString[1] == 'p') {
                p = va_arg(args, void *);
                
                fprintf(Debug, "%p", p);
                pString += 2;
            } else if (pString[1] == 's') {
                s = va_arg(args, char *);
                fprintf(Debug, "%s", s);
                pString += 2;
            } else if (pString[1] == 'x') {
                d = va_arg(args, int);
                fprintf(Debug, "%x", d);
                pString += 2;
            }else if (pString[1] == 'c') {
                ccc = va_arg(args, char);
                fprintf(Debug, "%c", ccc);
                pString += 2;
            }
            else {
                fputc(pString[0], Debug);
                pString++;
            }
        } else {
                fputc(pString[0], Debug);
                pString++;
        }
    }
    
    va_end(fmt);
    
    fflush(Debug);
}

void Init_Debug(void) 
{

    Debug = fopen("Debug.log", "w");
    
    if (!Debug) {
        fprintf(stderr, "Init debug System False.\n");
        exit(-1);
    }
    dprintf("Init Debug system.\n");
}

void Release_Debug(void)
{
    dprintf("Release Debug System.\n");
    fclose(Debug);
}