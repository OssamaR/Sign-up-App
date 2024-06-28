#ifndef MYLIB_H
#define MYLIB_H

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <array>
    #include <vector>
    #include <sstream>
    #include <chrono> //for delay
    #include <thread> //for delay
    #include <cstdlib>  // for exit()

    #define ZERO 0
    #define MAX_Numberof_Records 100
    
    class record
    {
        public:
            int age;
            int ID;
            std::string name;
    };

    extern std::vector<record> Records;


    enum class Options
    { ADD=1, FETCH=2, SHOW=3, EXIT=4 };
     

    /* FUNCTION PROTOTYPES */

    void Menu();
    void Add_Record();
    void Fetch_Record();
    void Show_Records();

    void Opt( Options option );
    std::istream& operator>> ( std::istream & input_stream , Options & result) ;




#endif 
