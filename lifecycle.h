//
//  lifecycle.h
//  cpp-test
//
//  Created by John Pape on 7/13/23.
//

#ifndef lifecycle_h
#define lifecycle_h

struct Tracer {
    Tracer(const char* name): name{ name } {
        printf("%s constructed\n", name);
    }
    
    ~Tracer(){
        printf("%s destructed\n", name);
    }
    
private:
    const char* name;
};

#endif /* lifecycle_h */
