// Simple Text Creator - EN/US - V 1.0.0 Stable Release.

#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main (void) {

    int User_Choice = 0;
    string File_Name = "Empty", Text = "Empty", UC_Before_Convert = "Empty";

    cout << "\nWelcome to the Simple Text Creator!";

    while (true) {

        User_Choice = 0, File_Name = "Empty", Text = "Empty", UC_Before_Convert = "Empty";

        cout << "\n\nPlease enter the name of the file to create/overwrite/delete/read:\n" << endl;

        getline (cin, File_Name);

        ifstream Read_File (File_Name);

        if (Read_File.is_open()) {

            cout << "This file already exists: What would you like to do?" << endl << endl << "1: Create a different file." << endl 
            << "2: Read." << endl << "3: Overwrite." << endl << "4: Delete." << endl << "5: Restart." << endl << "6: Close." << endl 
            << endl;

            getline (cin, UC_Before_Convert);
            User_Choice = stoi (UC_Before_Convert);

            if (User_Choice < 1 || User_Choice > 6) { cout << "\nERROR: Invalid option! Restarting..."; continue; }
        }

        (User_Choice != 2) ? Read_File.close() : void();

        switch (User_Choice) {

            case 0: { ofstream Create_File (File_Name);

                if (Create_File.is_open() == false) { cout << "\nERROR: I couldn't create the file for you. Restarting...";
                    continue; }

                cout << endl << "Enter the text to create the file (type 'END_TEXT' to finish):" << endl << endl;

                while (true) { getline (cin, Text);

                    if (Text == "END_TEXT") { Create_File.close(); break; }
                    Create_File << Text << endl;

                } break;
            }

            case 1: { cout << "\nRestarting..."; continue; break; }
            case 2: { cout << endl; while (getline (Read_File, Text)) { cout << Text << endl; } Read_File.close(); break; }

            case 3: { 

                if (remove (File_Name.c_str()) != 0) { cout << "\nERROR: I couldn't erase it for you. Restarting..."; continue; }

                ofstream Overwrite_File (File_Name);

                if (Overwrite_File.is_open() == false) { cout << "\nERROR: I couldn't create it for you. Restarting..."; continue; }

                cout << endl << "Enter the text to create the file (type 'END_TEXT' to finish):" << endl << endl;
                
                while (true) { getline (cin, Text);

                    if (Text == "END_TEXT") { Overwrite_File.close(); break; }
                    Overwrite_File << Text << endl;

                } break;
            }

            case 4: { remove (File_Name.c_str()); break; }
            case 5: { cout << "\nRestarting..."; continue; break; }
            case 6: { cout << "\nClosing...\n"; return 0; break; }
        }

        cout << endl << "Done! The file '" << File_Name << "' was created/overwritten/deleted/read successfully! ---- "
        << "Would you like to restart?" << endl << endl << "1: Restart." << endl << "2: Exit." << endl << endl;

        getline (cin, UC_Before_Convert);
        User_Choice = stoi (UC_Before_Convert);

        if (User_Choice == 1) { cout << "\nRestarting..."; continue; }
        else if (User_Choice == 2) { cout << "\nClosing...\n"; return 0; }
        else { cout << "\nERROR: Invalid option! Restarting..."; continue; }
    }

    return 0;
}

// End of the code.