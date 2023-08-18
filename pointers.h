//
//  pointers.h
//  cpp-test
//
//  Created by John Pape on 7/13/23.
//

#ifndef pointers_h
#define pointers_h

void pointerStuff(){
    int gettysburg { 1863 };
    printf("gettysburg: %d\n", gettysburg);
    int *gettysburg_address = &gettysburg;
    printf("&gettysburg: %p\n", gettysburg_address);
}

#endif /* pointers_h */
