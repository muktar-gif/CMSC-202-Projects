/*****************************************
** File:    Scheduler.cpp
** Project: CMSC 202 Project 5, Fall 2019
** Author:  Muhammed Muktar
** Date:    12/5/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Scheduler Class.
**
***********************************************/
#include "Scheduler.h"

const string MENU_OPTIONS[] = {"Display All Courses", "Display a Specific Course",
                             "Search for Specific Student", "Sort Roster", "Quit"}; //menu options

const int DISP_COUR = 1, DISP_SPECIFIC_COUR = 2, SEARCH = 3, SORT = 4, QUIT = 5;    //menu indexes

//Name: Scheduler
//Desc: Default Constructor
//Precondition: None
//Postcondition: Creates Scheduler object
Scheduler::Scheduler()
{

  m_name = "";
  m_fileName = "";
}

//Name: Scheduler
//Desc: Overloaded Constructor
//Precondition: Valid fileName
//Postcondition: Creates Scheduler object
Scheduler::Scheduler(string fileName)
{

  m_fileName = fileName;
}
//Name: ~Scheduler
//Desc: Destructor
//Precondition: None
//Postcondition: Deallocates everything dynamically allocated in Scheduler
Scheduler::~Scheduler()
{

  //loops and deletes ptrs in m_classes
  for (int i = 0; i < int(m_classes.size()); i++)
  {

    delete m_classes[i];
  }
}

//Name: LoadFile
//Desc: Loads a roster file
//Precondition: Valid roster file
//Postcondition: Populates roster
void Scheduler::LoadFile()
{

  ifstream loadFile;
  string validFile;

  loadFile.open(m_fileName);

  //if the file does not exist
  while (!loadFile)
  {

    //asks for another file
    cout << "Please reenter file" << endl;
    cin >> validFile;

    m_fileName = validFile;

    cout << "\nLoading file: " << m_fileName << "\n"
         << endl;

    loadFile.open(m_fileName);
  }

  string fName = "", lName = "", id = "", className = "";

  //while there is something to read
  //gets first and last name, id and class name
  while (getline(loadFile, fName, ','))
  {

    getline(loadFile, lName, ',');
    getline(loadFile, id, ',');
    getline(loadFile, className, '\n');

    if (loadFile.eof())
      break;

    //adds student to potential class
    Student *newStudent = new Student(fName, lName, stoi(id));
    AddStudent(newStudent, className);
  }

  loadFile.close();
}

//Name: MainMenu
//Desc: Displays the main menu of the program
//      Has options for 1. Display All Courses, 2. Display Specific Course
//      3. Search for Specific Student, 4. Sort Roster, and 5. Quit
//Precondition: Has roster loaded
//Postcondition: Keeps running until user chooses 5 (quit)
void Scheduler::MainMenu()
{

  int askOption;
  bool keepPlaying = true;

  //while the player does not want to quit
  while (keepPlaying)
  {

    //prints menu
    for (int i = 0; i < QUIT; i++)
      cout << i + 1 << ". " << MENU_OPTIONS[i] << endl;

    cin >> askOption;

    //validates option
    while (askOption < DISP_COUR || askOption > QUIT)
      cin >> askOption;

    switch (askOption)
    {

    case DISP_COUR:

      //displays courses
      DisplayCourses();
      break;

    case DISP_SPECIFIC_COUR:

      //displays specific course
      DisplaySpecific();
      break;

    case SEARCH:

      //search for a specific student
      SearchStudent();
      break;

    case SORT:

      //sorts queue
      SortRoster();
      break;

    case QUIT:

      //stops playing
      keepPlaying = false;
      break;
    }
  }
}
//Name: DisplayCourses()
//Desc: Displays each course in the m_classes (Just name and section)
//Precondition: Classes loaded into m_classes
//Postcondition: Displays Class info
void Scheduler::DisplayCourses()
{

  //displays courses
  for (int i = 0; i < int(m_classes.size()); i++)
    cout << *m_classes[i];
}

//Name: DisplaySpecific
//Desc: Prompts user for a specific course (lists each class by name/section)
//      Displays each student enrolled in course
//Precondition: Classes loaded into m_classes and rosters populated
//Postcondition: Displays student info by class
void Scheduler::DisplaySpecific()
{

  int askDisplay;

  //asks which course to display
  cout << "Which course would you like to display?" << endl;

  for (int i = 0; i < int(m_classes.size()); i++)
    cout << i + 1 << ". " << *m_classes[i];

  cin >> askDisplay;

  //validates option
  while (askDisplay < 1 || askDisplay > int(m_classes.size()))
  {
    cin >> askDisplay;
  }

  //displays that course
  m_classes[askDisplay - 1]->DisplayStudents();
}

//Name: SearchStudent
//Desc: Prompts user for a specific string to search for (student name)
//      Returns each course that name appears
//Precondition: Classes loaded into m_classes and rosters populated
//Postcondition: Displays classes that student is in
void Scheduler::SearchStudent()
{

  string askName;

  //asks for name to search
  cout << "What name do you want to search for?" << endl;
  cin >> askName;

  //displays courses with that name
  cout << "Items with " << askName << " in them: " << endl;

  for (int i = 0; i < int(m_classes.size()); i++)
  {

    if (m_classes[i]->SearchClass(askName))
    {
      cout << *m_classes[i];
    }
  }

  cout << endl;
}

//Name: SortRoster
//Desc: For each Class, each m_roster and m_waitlist is sorted by last name
//Precondition: Classes loaded into m_classes and rosters populated
//Postcondition: Does not display anything but rosters are sorted
void Scheduler::SortRoster()
{

  //sorts queues
  for (int i = 0; i < int(m_classes.size()); i++)
    m_classes[i]->SortStudents();
}

//Name: Start
//Desc: Welcomes users, loadsfile and calls mainmenu
//Precondition: None
//Postcondition: m_classes is populated
void Scheduler::Start()
{

  //load file
  LoadFile();

  //start game
  cout << "Welcome to the UMBC Scheduler" << endl;
  MainMenu();
}

//Name: FindClass
//Desc: Helper function that searches for a class name in m_classes and
//      returns the index of where the Class exists to add the student
//      HINT: May want to implement to go backwards through m_classes
//Precondition: None
//Postcondition: Returns the index of the "current" section of a class
int Scheduler::FindClass(string className)
{

  //looks through class
  for (int i = int(m_classes.size()) - 1; i >= 0; i--)
  {

    //if name is found in that class
    if (m_classes[i]->GetName() == className)

      //returns index
      return i;
  }

  //class was not found
  return -1;
}

//Name: AddStudent
//Desc: Helper function from LoadFile that decides what to do with a new student
//      Scenario 1 - No classes in m_classes - Creates new class and adds student
//      Scenario 2 - Add Student to existing class where m_roster and m_waitlist
//      are not full
//      Scenario 3 - Add Student when existing class is full ->create new class and
//      move m_waitlist to new section
//Precondition: None
//Postcondition: Student added to a class
void Scheduler::AddStudent(Student *student, string className)
{

  //gets index of class name
  int indexClass = FindClass(className);
  int section = 1;
  bool addedStudent;

  //class is not found
  if (indexClass == -1)
  {

    //adds new class
    Class *newClass = new Class(className, section);
    m_classes.push_back(newClass);

    //adds student
    addedStudent = m_classes[int(m_classes.size()) - 1]->AddStudent(student);
  }
  else
  {

    //adds student to found class
    addedStudent = m_classes[indexClass]->AddStudent(student);

    //wait and roster is full
    if (!addedStudent)
    {

      //makes new section
      Class *newSection = new Class(className, m_classes[indexClass]->GetSection() + 1);
      m_classes.push_back(newSection);

      //trasfers waitlist to roster
      m_classes[indexClass]->TransferWaitToRoster(*newSection);

      //adds student
      m_classes[int(m_classes.size()) - 1]->AddStudent(student);
    }
  }
}
