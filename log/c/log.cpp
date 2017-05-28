#include "log.h"
#include <stdarg.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

static int flag;
inline static void logDefualt(const char* buf)
{
    puts(buf);
}
static LogCallback callback = logDefualt;
void logBind(const char *file, int line, const char *func, const char *format,...)
{
    char tmp[512];
    memset(tmp,0,512);
    int pos=0;

    va_list args;
    va_start(args, format);
    if(flag&LogTime)
    {
        time_t t = time(0);
        strftime(&tmp[pos], sizeof(tmp), "%Y/%m/%d %H:%M:%S ", localtime(&t));
        pos = strlen(tmp);
    }
    if(flag&LogFile)
    {
        strcat(&tmp[pos], file);
        pos = strlen(tmp);
        strcat(&tmp[pos]," ");
        pos = strlen(tmp);
    }
    if(flag&LogLine)
    {
        itoa(line, &tmp[pos], 10);
        pos = strlen(tmp);
        strcat(&tmp[pos]," ");
        pos = strlen(tmp);
    }
    if(flag&LogFunc)
    {
        strcat(&tmp[pos],func);
        pos = strlen(tmp);
        strcat(&tmp[pos]," ");
        pos = strlen(tmp);
    }
    if(flag!=LogALLOFF)
    {
    strcat(&tmp[pos],":");
    pos = strlen(tmp);
    }
    vsprintf(&tmp[pos],format,args);
    va_end(args);
    if(callback!=NULL)
        (*callback)(tmp);
}

void logsetCallback(LogCallback lck)
{
    if(lck!=NULL)
        callback =lck;
    else
        callback = logDefualt;
}

void logEnableflags(int flags)
{
    flag = flag|flags;
}

void logDisableflags(int flags)
{
    flag = flag^flags;
}




