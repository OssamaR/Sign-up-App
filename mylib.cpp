#include "mylib.hpp"
/* ************************************************* */

std::vector<record> Records;
int count_of_Records =0; // keeps track of number of elements in the records vector

/* ************************************************* */

void Menu()
{
    std::cout << "------------------------\n\n";
    std::cout << "Please select an option\n\n";
    std::cout << "1. Add Record\n";
    std::cout << "2. Fetch Record\n";
    std::cout << "3. Show Records\n";
    std::cout << "4. Exit Records\n\n";
    std::cout << "------------------------\n\n";
};

/* ************************************************* */

void Add_Record()
{
    std::string name ;
    int age = ZERO;
    record temp;
    
    std::cout << "\nPlease enter the record's name\n";
    std::cin.ignore();  // to clear the buffer so std::getline can work correctly
    std::getline(std::cin, name);
    temp.name=name;
    std::cout << "\nPlease enter the record's age\n";
    std::cin >> age;
    temp.age=age;
    temp.ID= count_of_Records;
    Records.push_back(temp);
    std::cout << "\n";
    std::cout << "Record of " << Records[count_of_Records].name << " is created\n";
    std::cout << "\n";
    count_of_Records++ ;
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1)); // Delay for a second
};

/* ************************************************* */

void Fetch_Record()
{
    int size = Records.size();
    int ID_input;
    if (size <= count_of_Records) // checks if there are records written to the vector or not
    {
        std::cout << "\nPlease enter the record's ID : ";
        std::cin  >> ID_input ;
        if ( ID_input <= count_of_Records) // checks that ID_input is within the range of IDs
        {            
            std::cout << Records[ID_input].name << "\n";
            std::cout << Records[ID_input].age << "\n";
        }
        else
        {
        std::cout << "\nNo Records with this ID\n\n" ;
        }
    }
    else 
    {
        std::cout << "\nNo Records add to be fetched\n\n" ;
    }

};

/* ************************************************* */

void Show_Records()
{
    std::cout << "\nShowing all Records ...\n" ;
    for (record rec : Records) {
        std::cout << rec.name << "\n";
        std::cout << rec.age << "\n";
    }

};

/* ************************************************* */

void Opt( Options option )
{
    switch (option)
    {
    case Options::ADD :
        Add_Record();
        break;

case Options::FETCH :
        Fetch_Record();
        break;

    case Options::SHOW :
        Show_Records();
        break;

    case Options::EXIT :
        std::exit(0);
        break;
    
    default:
        break;
    }
}

/* ************************************************* */

std::istream& operator>> ( std::istream & input_stream , Options & result)
{
    int int_option ;
    input_stream >> int_option ;

    result = static_cast<Options>(int_option);

    return input_stream ;
}
