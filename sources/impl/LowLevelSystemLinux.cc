//---------------------------------------------------------------------------
// LowLevelSystemLinux.cc
//---------------------------------------------------------------------------

#include <cstdio>
#include <cstdarg>
#include "impl/LowLevelSystemLinux.h"

using namespace std;

extern int ccMain();

//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  return ccMain();
}

namespace CC
{
  static LogWriter logWriter("cc.log");

  //-------------------------------------------------------------------------
  LogWriter::LogWriter(const string& logFileName) :
    m_logFileName(logFileName)
  {
  }

  //-------------------------------------------------------------------------
  LogWriter::~LogWriter()
  {
    if(m_logFile)
    {
      fclose(m_logFile);
    }
  }

  //-------------------------------------------------------------------------
  void LogWriter::Write(const string& message)
  {
    if(!m_logFile)
    {
      ReopenFile();
    }
    fprintf(m_logFile, message.c_str());
    fflush(m_logFile);
  }

  //-------------------------------------------------------------------------
  void LogWriter::ReopenFile()
  {
    if (m_logFile)
    {
      fclose(m_logFile);
    }
    m_logFile = fopen(m_logFileName.c_str(), "w");
  }

  //-------------------------------------------------------------------------
  void Log(const char* format, ...)
  {
    char text[2048];
    va_list args;
    if (format == NULL)
      return;
    va_start(args, format);
    vsprintf(text, format, args);
    va_end(args);

    string message = "";
    message += text;
    logWriter.Write(message);
  }
}
