//A simple Booking Flight App
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

class Reservation {  
public:
    char fName[70];//first name
    char lName[70];//last name
    int ref;
    int ticket;
    void getInfo() { // for passengers info
       
        std::cout << "\n Passenger Information";
        std::cout << "\n Please Enter First Name: " << std::endl;
        std::cin >> fName;
        std::cout << "\n Please Enter Last Name: " << std::endl;
        std::cin >> lName;
        std::cout << std::endl << std::endl;
        system("cls");
    }
};

class Book :public Reservation {
public:
    int b;//for booking
    int flightOption;
    int travelOption;
    int classOption;
    std::string destination;
    std::string travel;
    std::string classType;

public:
 
    void InternationalFlight() { //Leaving from SEA
        

        std::cout << "\n Please Select Your Travel Destination from SEA: "<< std::endl;

        std::cout << "1. Narita (Japan) by Japan Airlines " << std::endl;
        std::cout << "2. Haneda (Japan) by Delta " << std::endl;
        std::cout << "3. Seoul (S.Korea) by Korean Air " << std::endl;
        std::cout << "4. Vancouver (Canada) by Air Canada " << std::endl;
        std::cout << "5. Heathrow (UK) by British Airways " << std::endl;
        std::cout << "6. Berlin (Germany) by Lufthansa " << std::endl;
        std::cout << "\n 0. Go back to menu" << std::endl;
        std::cout << "****************" << std::endl;
        std::cout << "\n Enter your option: " << std::endl;
        std::cin >> flightOption;

        switch (flightOption) {
        case 1:
            destination = "Narita";
            break;
        case 2:
            destination = "Haneda";
            break;
        case 3:
            destination = "Seoul";
            break;
        case 4:
            destination = "Vancouver";
            break;
        case 5:
            destination = "Heathrow";
            break;
        case 6:
            destination = "Berlin";
            break;
        case 0:
            system("cls");

            break;
        default:
            std::cout << "Invalid Option. Please try again.";
            system("cls");
            exit(0);
        }
        bookTravelOption();
    };

    void bookTravelOption() {
        std::cout << "\nOne-way Trip or Round Trip" << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << "1. One-way Trip" << std::endl;
        std::cout << "2. Round Trip" << std::endl;
        std::cout << "\n 0. Go back to menu" << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << "\nEnter your option: " << std::endl;
        std::cin >> travelOption;
        switch (travelOption)
        {
        case 1:
            travel = "One Way";
            break;
        case 2:
            travel = "Round Trip";
            break;
        case 0:
            system("cls");
            break;

        default:
            std::cout << "Invalid Option. Please try again.";
            system("cls");
            exit(0);
        }
        bookClassOption();
    };
    void bookClassOption() {
        std::cout << "\nPlease choose a boarding group." << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << "1. Business Class" << std::endl;
        std::cout << "2. Premium Class" << std::endl;
        std::cout << "3. Economy Class" << std::endl;
        std::cout << "\n 0. Go back to menu" << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << "\nEnter your option: " << std::endl;
        std::cin >> classOption;

        switch (classOption)
        {
        case 1:
            classType = "Business Class";
            break;
        case 2:
            classType = "Premium Class";
            break;
        case 3:
            classType = "Economy Class";
            break;
        case 0:
            system("cls");
            break;
        default:
            break;
        }
        showStatus();
    };

    void showStatus() {
        int ref = 1;
        int ticket = 1;

        std::cout << "\t\t\t******************************************" << std::endl;
        std::cout<< "\t\t\t***** Your Reserved Flight Information*****" << std::endl;
        std::cout<< "\t\t\tReference #: "<<ref<< "\t Flight Ticket #:  "<< ticket << std::endl;
        std::cout << "\t\t\t-----Passenger's Information-----" << std::endl;
        std::cout << "\t\t\tName: " << fName <<lName<< std::endl;
        std::cout << "\t\t\t-----Passenger's Flight Information-----" << std::endl;
        std::cout << "\t\t\t Flight Destination: " << destination << std::endl;
        std::cout << "\t\t\tTravel Option: " << travel << std::endl;
        std::cout << "\t\t\tClass Group: " << classType << std::endl;
        std::cout << std::endl;
        std::cout << "\n\t\tCompany Contact Number: 1-000-123-4567" << std::endl;
        std::cout << "\n\t\tCompany Contact Email: abcdef@000.com" << std::endl;
        std::cout << "\n\t\tThank You" << std::endl;
    };
    
}b;


int main()
{
    std::ofstream file;
    int menuOption;
    while (menuOption = 4) {

        std::cout << "\t\t\t-----------------------------------" << std::endl;
        std::cout << "\t\t\t| Booking Flight Management System |" << std::endl;
        std::cout << "\t\t\t-----------------------------------" << std::endl;
        std::cout << "\t\t\t 1. Booking Flight" << std::endl;
        std::cout << "\t\t\t 2. Ticket Information" << std::endl;
        std::cout << "\t\t\t 3. Cancel Flight" << std::endl;
        std::cout << "\t\t\t 4. Exit" << std::endl;

        std::cout << "\t\t\t-----------------------------" << std::endl;
        std::cout << "\t\t\tChoose Option:[1/2/3/4]" << std::endl;
        std::cout << "\t\t\t-----------------------------" << std::endl;
        std::cout << "Enter your option: ";
        std::cin >> menuOption;

        file.open("booking_info.txt", std::ios::app);
        file << b.fName << b.lName << b.destination << b.travel << b.classType <<'\n';
        file.close();
        system("cls");
 
        switch (menuOption) { //from class Book = b;

        case 1:
            b.getInfo();
            b.InternationalFlight();
            system("cls");
            b.showStatus(); //this will end up showing the complete screen for the flight as a confirmation.
            break;
        case 2:
            b.showStatus();
            break;
        case 3: // Delete the all information
            file.open("booking_info.txt", std::ios::in);
            file << b.fName << b.lName << b.destination << b.travel << b.classType << '\n';
            remove("booking_info.txt");
            rename("Temp.txt", "booking_info.txt");          
            system("cls");
            b.showStatus();
            std::cout << "\n\t\t\t***********************************************************" << std::endl;
            std::cout << "\n\t\t\t***********DELETED THE RESERVATION INFORMATION*************" << std::endl;
            std::cout << "\n\t\t\t***********************************************************" << std::endl;
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }

    system("pause>0");
}