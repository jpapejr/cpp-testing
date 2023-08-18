//
//  polymorphism.h
//  cpp-test
//
//  Created by John Pape on 8/17/23.
//

#ifndef polymorphism_h
#define polymorphism_h


struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[console] %ld -> %ld: %f\n", from , to, amount);
    }
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld -> %ld: %f\n", from, to, amount);
    }
};

struct Bank {
    Bank(Logger* new_logger) {
        logger = new_logger;
    }
    void set_logger(Logger* new_logger) {
        logger = new_logger;
    }
    void make_transfer(long from, long to, double amount) {
        logger->log_transfer(from, to, amount);
    }
    
private:
    Logger* logger;
};



#endif /* polymorphism_h */
