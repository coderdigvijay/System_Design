#include<bits/stdc++.h>
using namespace std;

class Ilogger{
    public:
    virtual void log()=0;
};

class loggerFactory{
    public:
    virtual Ilogger* createLogger()=0;
};

class errorLogger:public Ilogger{
    public:
    void log(){
        cout<<"ERROR LOGGER"<<endl;
    }
};

class errorLoggerFactory:public loggerFactory{
    public:
    Ilogger* createLogger(){
        return new errorLogger();
    }
};


class infoLogger:public Ilogger{
    public:
    void log(){
        cout<<"INFO LOGGER"<<endl;
    }
};

class infoLoggerFactory:public loggerFactory{
    public:
    Ilogger* createLogger(){
        return new infoLogger();
    }
};

int main()
{
    loggerFactory* factory1=new errorLoggerFactory();
    Ilogger* logger1=factory1->createLogger();
    logger1->log();
    loggerFactory* factory2=new infoLoggerFactory();
    Ilogger* logger2=factory2->createLogger();
    logger2->log();
    return 0;
}