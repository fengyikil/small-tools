#ifndef LOG_H
#define LOG_H
#include "stdio.h"

enum
{
    LogTime = 0x00000001,
    LogFile = 0x00000002,
    LogLine = 0x00000004,
    LogFunc = 0x00000008,
    LogALLON =  0xffffffff,
    LogALLOFF = 0x00000000
};
typedef void(*LogCallback)(const char* buf);

extern void logBind(const char* file,int line,const char* func,const char *format, ...);
extern void logsetCallback(LogCallback lck);
extern void logEnableflags(int flags);
extern void logDisableflags(int flags);




#ifdef WIN32
#define TrimFilePath(x) strrchr(x,'\\')?strrchr(x,'\\')+1:x
#else //*nix
#define TrimFilePath(x) strrchr(x,'/')?strrchr(x,'/')+1:x
#endif
#define LogPt(fmt, ...) \
    logBind(TrimFilePath(__FILE__),__LINE__,__FUNCTION__,fmt,##__VA_ARGS__)

#endif // LOG_H
