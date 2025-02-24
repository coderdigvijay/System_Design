#include<bits/stdc++.h>
using namespace std;


enum class logType{
    ERROR,
    INFO,
    CONSOLE
};

class Ilogger{
    public:
    virtual void log(string msg)=0;
};

class errorLogger:public Ilogger{
    public:
    void log(string msg){
        cout<<"ERROR LOGGER";
    }
};

class infoLogger:public Ilogger{
    public:
    void log(string msg){
        cout<<"INFO LOGGER";
        }
};

class consoleLogger:public Ilogger{
    public:
    void log(string msg){
        cout<<"CONSOLE LOGGER";
    }
};

class LoggerFactory{
    public:
    static Ilogger* createLogger(logType type){
        switch(type){
            case logType::ERROR:
                return new errorLogger();
            case logType::INFO:
                return new infoLogger();
            case logType::CONSOLE:
                return new consoleLogger();
        }
    }
};

int main(){
    Ilogger* logger=LoggerFactory::createLogger(logType::ERROR);
    logger->log("Hello");
}