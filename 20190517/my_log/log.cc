#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
using namespace log4cpp;

class Mylogger
{
public:
    static Mylogger *getInstance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance =new Mylogger();
        }
        return _pInstance;
    }

  //  void opret(const char * msg)
  //  {
  //      char *mmsg = new char[strlen(msg)+1]();
  //      strcpy(mmsg,msg);
  //      OstreamAppender *ostreamAppender =
  //          new OstreamAppender("ostreamAppender", &cout);
  //      ostreamAppender->setLayout(_patternLayout1);
  //      
  //      FileAppender *fileAppender =
  //          new FileAppender("fileAppender","my_log.log");
  //      fileAppender->setLayout(_patternLayout2);

  //      Category & myRecord =Category::getRoot().getInstance("mycategory");
  //      myRecord.setAppender(ostreamAppender);
  //      myRecord.addAppender(fileAppender);
  //      myRecord.setPriority(Priority::DEBUG);
  //      //myRecord.emerg(mmsg);
  //  }
    void warn(const char *msg)
    {
  //      opret(msg);
        _myRecord.warn(msg);
  //      destroy();
    }
    void error(const char * msg)
    {
   //     opret(msg);
        _myRecord.error(msg);
    //    destroy();
    }
    void debug(const char * msg)
    {
    //    opret(msg);
        _myRecord.debug(msg);
    //    destroy();
    }
    void info(const char * msg)
    {
     //   opret(msg);
        _myRecord.info(msg);
     //   destroy();
    }

    static void destroy()
    {
        if(_pInstance)
        {
            Category::shutdown();
        }
    }
private:
    Mylogger()
    //:ret(new char[strlen(ret)+1]())
    //:_myRecord ( Category::getRoot().getInstance("mycategory"))
    :_patternLayout1 ( new PatternLayout())
    ,_patternLayout2 ( new PatternLayout())
    ,_myRecord ( Category::getRoot().getInstance("mycategory"))
    {
     //   strcpy(_words,words);
        _patternLayout1->setConversionPattern("%d [%p] %m%n");
        _patternLayout2->setConversionPattern("%d [%p] %m%n");
        //_myRecord =Category::getRoot().getInstance("mycategory");
        //char *mmsg = new char[strlen(msg)+1]();
        //strcpy(mmsg,msg);
        OstreamAppender *ostreamAppender =
            new OstreamAppender("ostreamAppender", &cout);
        ostreamAppender->setLayout(_patternLayout1);
        
        FileAppender *fileAppender =
            new FileAppender("fileAppender","my_log.log");
        fileAppender->setLayout(_patternLayout2);

        Category & myRecord =Category::getRoot().getInstance("mycategory");
        myRecord.setAppender(ostreamAppender);
        myRecord.addAppender(fileAppender);
        myRecord.setPriority(Priority::DEBUG);
        //myRecord.emerg(mmsg);
    }
    ~Mylogger();
private:
    PatternLayout *_patternLayout1;
    PatternLayout *_patternLayout2;
    Category & _myRecord;
   // char *_words;
private:
    static Mylogger *_pInstance;
};

Mylogger *Mylogger::_pInstance = nullptr;

int main()
{
    Mylogger *mylog = Mylogger::getInstance();
    mylog->warn("this is a warn message");
    mylog->error("this is an error message");
    mylog->info("this is an info message");
    mylog->debug("this is a debug message");
    //mylog->destroy();
    return 0;
}

