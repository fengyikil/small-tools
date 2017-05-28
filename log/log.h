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
inline static void defualt_log(const char* buf)
{
    puts(buf);
}
class Log
{
public:
	Log(LogCallback cb=defualt_log);
    void bind(const char* file,int line,const char* func,const char *format, ...);
//	void print(const char *format, ...);
    void setCallback(LogCallback lck);
    void flagsEnable(int flags);
    void flagsDisable(int flags);
private:
    LogCallback callback;
    int flag;

};
#ifdef WIN32
#define TrimFilePath(x) strrchr(x,'\\')?strrchr(x,'\\')+1:x
#else //*nix
#define TrimFilePath(x) strrchr(x,'/')?strrchr(x,'/')+1:x
#endif
//#define LogPrint(log,fmt, ...) \
//    log->print("[%s-(%d)-%s] : " fmt"\n",TrimFilePath(__FILE__),__LINE__,__FUNCTION__,##__VA_ARGS__)

#define LogPt(log,fmt, ...) \
    log->bind(TrimFilePath(__FILE__),__LINE__,__FUNCTION__,fmt,##__VA_ARGS__)


#endif // LOG_H
