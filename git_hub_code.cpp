// SoftwareTesting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This program creates a Database allowing the user to load student information and changes
//The program reads from a file into a vector and writes to the vector at the end


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string string_choice;
ofstream op;


struct student {
    string name;
    string id;
    string email;
    string presentation_grade;
    string essay_grade;
    string project_grade;
    
};
int choice;
int edit_choice;




void print_student(student my_student) {

    cout << "Student name: " << my_student.name << endl;
    cout << "Student email:  " << my_student.email << endl;
    cout << "Student ID : " << my_student.id << endl;
    cout << "Presentation Grade : " << my_student.presentation_grade << endl;
    cout << "Essay Grade : " << my_student.essay_grade << endl;
    cout << "Project Grade : " << my_student.project_grade << endl;
    cout << endl;

}

void print_database(vector<student> current_db) {

    //loops through and prints all elements

    for (student my_student : current_db) {

        cout << "Student name: " << my_student.name << endl;
        cout << "Student email:  " << my_student.email << endl;
        cout << "Student ID : " << my_student.id << endl;
        cout << "Presentation Grade : " << my_student.presentation_grade << endl;
        cout << "Essay Grade : " << my_student.essay_grade << endl;
        cout << "Project Grade : " << my_student.project_grade << endl;
        cout << "----------------------------\n";

     }

}

//all search functions return true if student is found
bool search_database_by_name(vector<student> current_db,string member) {

    for (student my_student : current_db) {

        if (my_student.name == member) {

            cout << endl;
            cout << "*******************************\n";
            cout << endl;
            cout << "Found student!\n";
            cout << "Here is their information...\n";
            cout << endl;
            cout << "*******************************\n";
            
            print_student(my_student);

            
            return true;
        }
        
    }
    cout << "Could not find student, check spelling and try again.\n";
    return false;

}

bool search_database_by_email(vector<student> current_db, string member) {

    for (student my_student : current_db) {

        if (my_student.email == member) {
            cout << endl;
            cout << "*******************************\n";
            cout << endl;
            cout << "Found student!\n";
            cout << "Here is their information...\n";
            cout << endl;
            cout << "*******************************\n";

            print_student(my_student);
            
            return true;
        }

    }

    cout << "Could not find student with that email, check spelling and try again.\n";
    return false;
}

bool search_database_by_ID(vector<student> current_db, string member) {

    for (student my_student : current_db) {

        if (my_student.id == member) {
            cout << endl;
            cout << "*******************************\n";
            cout << endl;
            cout << "Found student!\n";
            cout << "Here is their information...\n";
            cout << endl;
            cout << "*******************************\n";

            print_student(my_student);
            
            return true;
        }

    }

    cout << "Could not find student with that ID, check the ID and try again.\n";
    return false;
}

//this function is on hold, not sure what i'm going to do with grades being strings instead of ints
char grade_conversion(int score) {

    switch (score) {

    case 0:
        return 'F';
        break;
    case 1: 
        return 'D';
        break;
    case 2:
        return 'C';
        break;
    case 3:
        return 'B';
        break;
    case 4:
        return 'A';
        break;
    default:
        return 'I';
    }

}

student add_new_student() {

    student temp_student;


    cout << "Type student's name(first and last): ";
    getline(cin, temp_student.name);
    cout << "Type student's email: ";
    getline(cin, temp_student.email);
    cout << "Type student's ID: ";
    getline(cin, temp_student.id);
    cout << "Enter Presentation Grade(0-4): ";
    getline(cin, temp_student.presentation_grade);
    cout << "Enter Essay Grade(0-4): ";
    getline(cin, temp_student.essay_grade);
    cout << "Enter Project Grade(0-4): ";
    getline(cin, temp_student.project_grade);
    cout << endl;

    return temp_student;


}


vector<student> delete_student_from_db(vector<student> &current_db, string member) {
    
    int count = 0;

    //finding location of student and deleting, and returning
    for (student my_student : current_db) {

        if (my_student.name == member) {

            current_db.erase(current_db.begin() + count);
            return current_db;
        }
        count++;
    }
    return current_db;
}

vector<student> new_edit_student_information(vector<student> &current_db, string member, int field_choice) {

    for (student& my_student : current_db) {

        if (my_student.name == member) {

            switch (field_choice) {

            case 1:
                cout << "Enter the new Name: \n";
                getline(cin, string_choice);
                my_student.name = string_choice;
                cout << "Updated information!\n";
                return current_db;
                break;
            
            case 2:
                    
                 cout << "Enter the new email: \n";
                 getline(cin, string_choice);
                 my_student.email = string_choice;
                 cout << "Updated information!\n";
                 return current_db;
                 break;
            case 3:
                cout << "Enter the new ID: \n";
                getline(cin, string_choice);

                cout << "Updated information!\n";
                my_student.id = string_choice;
                return current_db;
                break;

            case 4:

                cout << "Enter the new presentation grade: \n";
                getline(cin, string_choice);
                my_student.presentation_grade = string_choice;
                cout << "Updated information!\n";
                return current_db;
                break;

            case 5:

                cout << "Enter the new essay grade: \n";
                getline(cin, string_choice);
                my_student.essay_grade = string_choice;
                cout << "Updated information!\n";
                return current_db;
                break;

            case 6:

                cout << "Enter the new Project Grade: \n";
                getline(cin, string_choice);
                my_student.project_grade = string_choice;
                cout << "Updated information!\n";
                return current_db;
                break;
            
            default:
                cout << "You did not pick a valid option, back to main menu...\n";
                return current_db;


            }


        }

    }
    cout << "That was invalid choice....sending back to main menu now...but i'll make this cleaner later...\n";
    return current_db;
}



int main()
{
    //random number to start loop
    choice = 7;
    
    //declaring databse and temp student for appending
    vector <student> student_db;
    student new_student;

    //file....newdata.csv is for testing, studentdata.csv is the real one....
    ifstream ip("studentdata.csv");
    //ifstream ip("newdata.csv");
    //if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    //excel parsing code, can be cleaned up later
    string firstname;
    string email;
    string ID;
    string pres_grade;
    string ess_grade;
    string proj_grade;

    //string string_choice;
    string temp_string;
    
    //ifstream ip("studentdata.csv");
    //the following code parses through the excel file and adds data to database (works properly)



    while (ip.peek() != EOF) {

        getline(ip, firstname, ',');
        getline(ip, email, ',');
        getline(ip, ID, ',');
        getline(ip, pres_grade, ',');
        getline(ip, ess_grade, ',');
        getline(ip, proj_grade, '\n');

        new_student.name = firstname;
        new_student.email = email;
        new_student.id = ID;
        new_student.presentation_grade = pres_grade;
        new_student.essay_grade = ess_grade;
        new_student.project_grade = proj_grade;

        student_db.push_back(new_student);

        
        
    }
    cout << "Welcome to the Software testing Database! \n";

    //run this loop until done with program (not done)
    while (choice != 6) {

        if (student_db.size() == 0) {

            student temp_student;
            cout << "*******************************\n";
            cout << "Database is empty, please add a student!\n";
            temp_student = add_new_student();
            student_db.push_back(temp_student);
            

        }


        cout << "*******************************\n";
        cout << "What would you like to do?\n";
        cout << "*******************************\n";
        cout << " 1 - View database\n";
        cout << " 2 - Add new student to database\n";
        cout << " 3 - Delete from list.\n";
        cout << " 4 - Search and view Student\n";
        cout << " 5 - Edit Student Information\n";
        cout << " 6 - Exit program and save changes\n";
        cout << "*******************************\n";
        cout << " Enter your choice and press return: \n";
        
        cin >> choice;
        cin.clear();
        cin.ignore();

        //leaving this commented out, code is kinda whack if it receives something other than int, will fix.....
        /*while (true)
        {
            cin >>choice;
            if (!cin)
            {
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin.clear();
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else break;
        }*/

        switch (choice)
        {
        case 1:
            
            cout << "Here is the current database...\n";
            cout << "----------------------------\n";
            print_database(student_db);
            
            break;
        case 2:
        {
            //creating student, adding to DB           
            student new_student = add_new_student();

            student_db.push_back(new_student);

            cout << "Successfully added " << new_student.name << " to database...\n";
            cout << endl;
            
        }
        break;
        case 3:
           
            //kind of redundant, basically searching list twice, may want to change
            cout << endl;
            cout << "Type the name of student you want to delte: \n";
            getline(cin, string_choice);
            if (search_database_by_name(student_db, string_choice)) {
                
                cout << endl;
                cout << "Deleting " << string_choice << "'s record from the database....\n";
                cout << endl;
                student_db = delete_student_from_db(student_db, string_choice);
                cout << "Successfully deleted!\n";
            }
            else
                cout << "Could not find student....sending back to main menu....\n";
            
            break;

        case 4:
            //also redundant, may want to combine search functions

            cout << "Would you like to search by name, email, or ID?\n";
            getline(cin, string_choice);

                if (string_choice == "name") {
                    cout << "Which student would you like to look for?\n";
                    getline(cin, string_choice);
                    search_database_by_name(student_db, string_choice);
                    break;
                }
                else if (string_choice == "ID") {

                    cout << "Which ID would you like to look for?\n";
                    getline(cin, string_choice);
                    search_database_by_ID(student_db, string_choice);
                    //cout << "need to code search_by_id function...sending back to menu for now\n" << endl;
                    break;
                }
                else if (string_choice == "email") {

                    cout << "Which email would you like to look for?\n";
                    getline(cin, string_choice);

                    search_database_by_email(student_db, string_choice);
                    //cout << "need to code search_by_email function...sending back to menu for now...\n" << endl;
                    break;
                }

                cout << "not a valid input, sending back to main menu...\n";
                
            break;
        
        case 5:

            cout << "Type the name of the student to edit their information: \n";
            getline(cin, string_choice);

            if (search_database_by_name(student_db, string_choice)) {

                //left in old function for now
                //student_db = edit_student_information(student_db, string_choice);

                cout << "1--Student name\n";
                cout << "2--Student email\n";
                cout << "3--Student ID\n";
                cout << "4--Presentation Grade\n";
                cout << "5--Essay Grade\n";
                cout << "6--Project Grade\n";
                cout << endl;
                cout << "Select the number of the field you would like to change(1-6): \n";
                cin >> edit_choice;
                cin.ignore();

                student_db = new_edit_student_information(student_db, string_choice, edit_choice);
                
            }
            break;
        
        case 6:

            cout << "Would you like to update the database file with your changes?\n";
            cout << "1--Yes\n";
            cout << "2--No\n";
            cout << "Enter your choice: ";
            cin >> edit_choice;
            cin.ignore();
            
            if (edit_choice == 1) {

                cout << "updating database file and exiting program\n";

                //output file, studentdata is real, newdata is for testing, make sure input/output are the same(input up top)...
                op.open("studentdata.csv");
                //op.open("newdata.csv");
                for (unsigned int i = 0; i < student_db.size(); i++) {

                    op << student_db[i].name << "," << student_db[i].email << "," << student_db[i].id << ","
                        << student_db[i].presentation_grade << "," << student_db[i].essay_grade << "," << student_db[i].project_grade
                        << endl;
                }

            }
            else if (edit_choice == 2) {

                cout << "Discarding changes and exiting program....";

            }

            else
                cout << "You didn't pick a valid option, just going to exit the program, peace....\n";
            
            return 0;

        default:
            cout << "Not a Valid Choice. \n";
            cout << "Choose again.\n";
            
            break;
        
        }

    }

}






