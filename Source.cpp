// Name: Xaiver
// Date: 05/18/2022


#include <iostream>

using namespace std;

class Project1
{
private:
    int hours24; // Private data can only be accessed by the methods in the class.
    int minutes; // This is the data, the purpose of the class.
    int seconds; // The class encapsulates the data and the methods to access
    int numberOfYears; // the data in a single unit.
    bool am_pm;


    int CalcHour12(bool & am_pm)  // This is a control for the 12hr clock
    {
        if (hours24 <= 12)
        {
            am_pm = 0;
            return hours24;
        }
        else
        {
            am_pm = 1;
            return hours24 - 12;
        }
    };

    void AddHour(void) // this adds another hour to both Clocks
    {
        hours24++;

        if (hours24 == 23)
        {
            hours24 = 0;
        }
    };

    void AddMinute(void) // this adds min to both clocks
    {
        minutes++;

        if (minutes == 59)
        {
            minutes = 0;
            AddHour();
        }
    };

    void AddSecond(void) // this adds sec to both clocks
    {
        seconds++;

        if (seconds == 59)
        {
            seconds = 0;
            AddMinute();
        }
    };

    void DisplayTime(void) // Displays the time
    {
       
        for (int i = 0; i < 27; i++)  //asterisks
        {
            cout << "*";
        }

        
        cout << "    "; //spacing


        for (int i = 0; i < 27; i++) //asterisks
        {
            cout << "*";
        }

        
        cout << endl; //spacing

        //Clock headers
        cout << "*      12-Hour Clock      *    *      24-Hour Clock      *" << endl;

        
        cout << "*       "; // 12hr display

        //print hours
        if (CalcHour12(am_pm) < 10)
        {
            cout << "0" << CalcHour12(am_pm) << ":";
        }
        else
        {
            cout << CalcHour12(am_pm) << ":";
        }

        //print minutes
        if (minutes < 10)
        {
            cout << "0" << minutes << ":";
        }
        else
        {
            cout << minutes << ":";
        }

        //print seconds
        if (seconds < 10)
        {
            cout << "0" << seconds << "          *" << endl;
        }
        else
        {
            cout << seconds;
        }

        //print am/pm
        if (am_pm == 0)
        {
            cout << " AM" << "       *";
        }
        else
        {
            cout << " PM" << "       *";
        }

        //spacing
        cout << "    ";

        
        cout << "*        "; // 24hr display

        //print hours
        if (hours24 < 10)
        {
            cout << "0" << hours24 << ":";
        }
        else
        {
            cout << hours24 << ":";
        }

        //print minutes
        if (minutes < 10)
        {
            cout << "0" << minutes << ":";
        }
        else
        {
            cout << minutes << ":";
        }

        //print seconds
        if (seconds < 10)
        {
            cout << "0" << seconds << "          *" << endl;
        }
        else
        {
            cout << seconds << "         *" << endl;
        }

        //asterisks
        for (int i = 0; i < 27; i++)
        {
            cout << "*";
        }

        //spacing
        cout << "    ";

        //asterisks
        for (int i = 0; i < 27; i++)
        {
            cout << "*";
        }
    };

    void DisplayMenu(void) // This contains the chain of commands.
    {
        //asterisks
        for (int i = 0; i < 27; i++)
        {
            cout << "*";
        }

        cout << endl;

        //option 1
        cout << "* 1 - Add One Hour        *" << endl;

        //option 2
        cout << "* 2 - Add One Minute      *" << endl;

        //option 3
        cout << "* 3 - Add One Second      *" << endl;

        //option 4
        cout << "* 4 - Exit Program        *" << endl;

        //stars
        for (int i = 0; i < 27; i++)
        {
            cout << "*";
        }
    };

public:
    void ClearScreen(void) // Clears the screen
    {
        system("CLS");
    };

    void Display(void) // Displays time
    {
        DisplayTime();
        cout << endl;
        DisplayMenu();
    };

    bool ReadUserInput(void) // Reads useer input
    {
        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            AddHour();
            return false;
            break;
        case 2:
            AddMinute();
            return false;
            break;
        case 3:
            AddSecond();
            return false;
            break;
        case 4:
            return true;
            break;
        }
    };

    void Init(int hour, int minute, int second)
    {
        hours24 = hour;
        minutes = minute;
        seconds = second;
    };
};

int main(void)
{
    Project1 project1; 

    project1.Init(8, 3, 15); // Access the function 
    

    while (1)
    {
        project1.ClearScreen(); // Call the functions in the object
        project1.Display();
        cout << endl;
        if (project1.ReadUserInput())
            break;         // Exit main()
    }
}