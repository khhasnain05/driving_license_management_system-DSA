
//This is where main function resides and the code execution starts here

#include <iostream>
#include <string>
#include <cstdlib>   // for system()
#include <windows.h> // Required for Unicode support
#include <unordered_set>  // Needed for hash-based storage
#include <random> // Modern C++ random system
#include <shellapi.h> // for displaying medical forms
#include <fstream>
#include <sstream>
#include<chrono>
#include<conio.h>

using namespace std;

// Global hash set for userIDS
unordered_set<int> usedIDs;

// Global hash set for CNICs
unordered_set<string> usedCNICs;

//----------------------------------------ASCII ART-------------------------------------------

void display_welcome_logo() {
    cout << R"(  __                                                 
 \ \        / / | |                           | |        |__   __|       / _|/ _(_)      |  __ \    | (_)         
  \ \  /\  / /__| | ___ ___  _ __ ___   ___   | |_ ___      | |_ __ __ _| |_| |_ _  ___  | |__) |__ | |_  ___ ___ 
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \  | __/ _ \     | | '__/ _` |  _|  _| |/ __| |  ___/ _ \| | |/ __/ _ \
    \  /\  /  __/ | (_| (_) | | | | | |  __/  | || (_) |    | | | | (_| | | | | | | (__  | |  | (_) | | | (_|  __/
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|   \__\___/ __  |_|_|__\__,_|_| |_| |_|\___| |_|   \___/|_|_|\___\___|
                                   |  __ \| |    |_   _|  \/  |/ ____|                                            
                                   | |  | | |      | | | \  / | (___                                              
                                   | |  | | |      | | | |\/| |\___ \                                             
                                   | |__| | |____ _| |_| |  | |____) |                                            
                                   |_____/|______|_____|_|  |_|_____/  
    )";
}

void display_login_page() {
    cout << R"( 
                              | |    / __ \ / ____|_   _| \ | |  |  __ \ /\   / ____|  ____|
                              | |   | |  | | |  __  | | |  \| |  | |__) /  \ | |  __| |__   
                              | |   | |  | | | |_ | | | | . ` |  |  ___/ /\ \| | |_ |  __|  
                              | |___| |__| | |__| |_| |_| |\  |  | |  / ____ \ |__| | |____ 
                              |______\____/ \_____|_____|_| \_|  |_| /_/    \_\_____|______|
                                                               
    )";
}

void display_TRAFFIC_LIGHTS ()
{
     cout << R"(

                                                                    _[]_
                                                                   [____]
                                                               .----'  '----.
                                                           .== = | . == . |= == .
                                                           \   |   /####\   |   /
                                                           /   |   \####/   |   \
                                                           '===|     ""     |==='
                                                          . == = | . == . |= == .
                                                           \   |   /::::\   |   /
                                                           /   |   \::::/   |   \
                                                           '===|     ""     |==='
                                                          . == = | . == . |= == .
                                                            \  |  / && &&\  |   /
                                                            /  |  \ && &&/  |   \
                                                           '===|     ""     |==='
                                                               '--.______.--'

    )";
}

void display_TESTER_OFFICER()
{
    cout << R"(
                                          
                                                              __  _.-"` `'-.
                                                             /||\'._ __{}_(
                                                             ||||  |'--.__\
                                                             |  L.(   ^_\^
                                                             \ .-' |   _ |
                                                             | |   )\___/
                                                             |  \-'`:._]
                                                             \__/;      '-.

    )";
}

void display_INCHARGE_OFFICER()
{
    cout << R"(
                                                                   _.---._
                                                                .-' ((O)) '-.
                                                                 \ _.\_/._ /
                                                                  /..___..\
                                                                  ;-.___.-;
                                                                 (| e ) e |)     .;.
                                                                  \  /_   /      ||||
                                                                  _\__-__/_    (\|'-|
                                                                /` / \V/ \ `\   \ )/
                                                               /   \  Y  /   \  /=/
                                                              /  |  \ | / {}  \/ /
                                                             /  /|   `|'   |\   /
                                                             \  \|    |.   | \_/
   
    )";
}

void display_REGISTER()
{
    cout << R"(
                                              


                                                     ⠀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀
⠀                             ⠀⠀                 ⣀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⡀⠀⠀
⠀                                              ⢀⣴⣿⣿⣿⠀⣧⠘⡇⢠⢤⣼⠉⣤⣌⣿⠀⣿⠑⠦⣹⣤⠀⣠⣼⠀⡦⢼⡇⢰⡄⢹⣿⣿⣿⣄⠀
                                              ⠀⣼⣿⣿⣿⣿⠀⡄⠺⡇⠰⠶⢿⠀⠷⠄⢸⠀⣟⠓⠦⢈⣿⡁⢾⣿⠀⠶⠾⡇⢰⠀⢿⣿⣿⣿⣿⡆
                                              ⠐⣿⣿⣿⣿⣿⣶⣿⣶⣷⣶⣶⣾⣷⣶⣶⣿⣶⣿⣷⣶⣾⣿⣶⣿⣿⣶⣶⣾⣷⣾⣷⣾⣿⣿⣿⣿⡇
                                              ⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠉⠀⠉⠀⠉⠀⠁⠉⠀⠁⠉⠈⠀⠉⠈⠁⠉⠉⠉⠹⢿⣿⣿⣿⡇
⠀                                              ⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⡀⠀⠂⢀⠰⡚⢢⡖⢳⡰⢊⡑⢲⠓⡖⠒⡶⢙⠀⠀⠈⠻⣿⡇
⠀                                              ⠀⠈⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠄⠈⠀⢸⠁⣄⠃⢸⠀⢎⡄⢈⡆⠃⡄⠀⢸⠀⠀⠁⡀⢘⡇
⠀                             ⠀                 ⠀⠀⠀⠈⠉⠛⠛⠛⠛⠛⠛⠛⠲⡈⠀⡐⠈⠦⠍⠦⠸⠑⠌⠠⠌⠣⠤⠛⠤⠇⠀⠠⠀⠄⠈⢧
⠀⠀⠀⠀                             ⠀⠀⠀⠀⠀                 ⠀⠀⠀⠀⠀⠀⠈⠑⠦⠤⠤⠤⠤⠤⠴⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⡾


    )";
}

void display_USER_DASHBOARD_LOGO()
{
    cout << R"(⠀                                   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                                                 ⠀⢣⠌⢃⣤⣇⣤⣇⣠⠇⣧⢾⡲⡇⠤⡀⠀⢀⣴⡶⣾⢿⣿⣿⣦⣄⣀⣀⠀⠀
⠀                                                 ⣼⣟⣛⣿⣿⣛⣛⣛⣛⣇⣼⢛⣤⣀⣃⠀⢸⣿⣿⣟⡿⣼⢧⡿⣼⣿⣿⣿⠀
⠀⠀                                                ⠀⠀⠙⠋⠀⠀⠀⠀⠀⠀⠘⠛⠀⠀⠀⠀⠙⠿⠋⠉⠉⠉⠉⠉⠻⠟⠁⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                                   ⣸⠻⠠⡀⠀⠀⠀
⠀                                                 ⣲⣦⣦⢰⣶⡆⣶⡆⢁⣿⣆⠀⠀⠀⠀⠀⠀⠙⠷⣦⣔⢿⣧⣶⣶⡾⣷⠀⠀
                                                 ⢰⠛⢻⠃⠛⠛⠙⠛⠛⠛⢻⠛⡟⠒⠃⠀⠀⢠⡞⢲⣶⣮⣶⣿⢫⣿⣾⡟⣧⠀
                                                 ⠘⠓⠚⣟⡷⠒⠒⠒⠒⠛⠒⠓⣟⡷⠒⠀⠀⠸⡜⢗⣨⠽⠿⠿⠿⠿⣇⣛⠸⠀
    )";
}

void display_TRAFFIC_OFFICER_DASHBOARD_LOGO(){
    cout << R"(
              ___________              __  .__                 ________   _____  _____.__                    
              \__    ___/___   _______/  |_|__| ____    ____   \_____  \_/ ____\/ ____\__| ____  ___________ 
                |    |_/ __ \ /  ___/\   __\  |/    \  / ___\   /   |   \   __\\   __\|  |/ ___\/ __ \_  __ \
                |    |\  ___/ \___ \  |  | |  |   |  \/ /_/  > /    |    \  |   |  |  |  \  \__\  ___/|  | \/
                |____| \___  >____  > |__| |__|___|  /\___  /  \_______  /__|   |__|  |__|\___  >___  >__|   
                           \/     \/               \//_____/           \/                     \/    \/       
                           ________                .__   ___.                          .___                  
                           \______ \ _____    _____|  |__\_ |__   _________ _______  __| _/                  
                            |    |  \\__  \  /  ___/  |  \| __ \ /  _ \__  \\_  __ \/ __ |                   
                            |    `   \/ __ \_\___ \|   Y  \ \_\ (  <_> ) __ \|  | \/ /_/ |                   
                           /_______  (____  /____  >___|  /___  /\____(____  /__|  \____ |                   
                                   \/     \/     \/     \/    \/           \/           \/                   
    )";
}

void display_LICENSE_ISSUED_LOGO(){
    cout << R"(
                       __    __  ___  ____  __ _  ____  ____    __  ____  ____  _  _  ____  ____       
                      (  )  (  )/ __)(  __)(  ( \/ ___)(  __)  (  )/ ___)/ ___)/ )( \(  __)(    \      
                      / (_/\ )(( (__  ) _) /    /\___ \ ) _)    )( \___ \\___ \) \/ ( ) _)  ) D (      
                      \____/(__)\___)(____)\_)__)(____/(____)  (__)(____/(____/\____/(____)(____/      
                         ____  _  _   ___  ___  ____  ____  ____  ____  _  _  __    __    _  _           
                        / ___)/ )( \ / __)/ __)(  __)/ ___)/ ___)(  __)/ )( \(  )  (  )  ( \/ )          
                        \___ \) \/ (( (__( (__  ) _) \___ \\___ \ ) _) ) \/ (/ (_/\/ (_/\ )  /           
                        (____/\____/ \___)\___)(____)(____/(____/(__)  \____/\____/\____/(__/            
    )";
}

void display_INCHARGE_DASHBOARD()
{
    cout << "\n\n";
    cout << "    ╔═══════════════════════════════════════════════════════════╗\n";
    cout << "    ║                                                           ║\n";
    cout << "    ║      LICENSE INCHARGE ADMINISTRATIVE CONTROL PANEL        ║\n";
    cout << "    ║                                                           ║\n";
    cout << "    ║                      INCHARGE                             ║\n";
    cout << "    ║                                                           ║\n";
    cout << "    ╚═══════════════════════════════════════════════════════════╝\n";
}

void display_ALL_USERS_LOGO()
{
    cout << R"(
    
    ═══════════════════════════════════════════════════════════════
    ║                                                             ║
    ║     _   _  ___  ___  ____  ___                              ║
    ║    | | | |/ __|/ _ \| __ \/ __|                             ║
    ║    | |_| |\__ \  __/|    /\__ \                             ║
    ║     \___/ |___/\___||_|\_\|___/                             ║
    ║                                                             ║
    ║           REGISTERED USERS DATABASE                         ║
    ║                                                             ║
    ═══════════════════════════════════════════════════════════════
    
    )";
}

void display_SEARCH_LOGO()
{
    cout << R"(
    
         _____                     _     
        / ____|                   | |    
       | (___   ___  __ _ _ __ ___| |__  
        \___ \ / _ \/ _` | '__/ __| '_ \ 
        ____) |  __/ (_| | | | (__| | | |
       |_____/ \___|\__,_|_|  \___|_| |_|
                                          
            FIND USER BY CNIC
    
    )";
}

void display_LEARNERS_LOGO()
{
    cout << R"(
    
    ╔═══════════════════════════════════════════════════════════╗
    ║                                                           ║
    ║    _                                                      ║
    ║   | |     ___  __ _ _ __ _ __   ___ _ __ ___              ║
    ║   | |    / _ \/ _` | '__| '_ \ / _ \ '__/ __|             ║
    ║   | |___|  __/ (_| | |  | | | |  __/ |  \__ \             ║
    ║   |_____|\___|\__,_|_|  |_| |_|\___|_|  |___/             ║
    ║                                                           ║
    ║            SYSTEM-WIDE LEARNER RECORDS                    ║
    ║                                                           ║
    ╚═══════════════════════════════════════════════════════════╝
    
    )";
}

void display_LICENSES_LOGO()
{
    cout << R"(
    
    ╔═══════════════════════════════════════════════════════════╗
    ║                                                           ║
    ║    _     _                                                ║
    ║   | |   (_) ___ ___ _ __  ___  ___  ___                   ║
    ║   | |   | |/ __/ _ \ '_ \/ __|/ _ \/ __|                  ║
    ║   | |___| | (_|  __/ | | \__ \  __/\__ \                  ║
    ║   |_____|_|\___\___|_| |_|___/\___||___/                  ║ 
    ║                                                           ║
    ║            SYSTEM-WIDE LICENSE RECORDS                    ║
    ║                                                           ║
    ╚═══════════════════════════════════════════════════════════╝
    
    )";
}

void display_STATISTICS_LOGO()
{
    cout << R"(
    
    ╔══════════════════════════════════════════════════════════════╗
    ║                                                              ║
    ║     ____  _        _   _     _   _                           ║
    ║    / ___|| |_ __ _| |_(_)___| |_(_) ___ ___                  ║
    ║    \___ \| __/ _` | __| / __| __| |/ __/ __|                 ║
    ║     ___) | || (_| | |_| \__ \ |_| | (__\__ \                 ║
    ║    |____/ \__\__,_|\__|_|___/\__|_|\___|___/                 ║
    ║                                                              ║
    ║              SYSTEM PERFORMANCE METRICS                      ║
    ║                                                              ║
    ╚══════════════════════════════════════════════════════════════╝
    
    )";
}


// -----------------------------enumerations------------------------------

enum userState
{
    REGISTERERD,
    LEARNER,
    SIGN_TEST_PASS,
    LICENSED
};

enum vehicleType
{
    MOTORCYCLE,
    CAR,
    LTV,
    HTV,
    PSV

};

enum learnerState {
    ACTIVE_LEARNER,
    EXPIRED_LEARNER,
    COMPLETE
};

enum licenseState 
{
    ACTIVE_LICENSE,
    EXPIRED_LICENSE
};

enum CNICResult {
    CNIC_OK,
    CNIC_EXISTS_GO_LOGIN,
    CNIC_RETRY
};

enum testState {
    NOT_TESTED,
    COMPUTER_PASSED,
    PRACTICAL_FAILED,
    BOTH_PASSED
};

// -------------------------------Structures---------------------------------

struct Date {
    int day, month, year;
};

struct Learner {
    int learnerID;
    vehicleType learnerType;
    learnerState learnerStatus;
    string fatherName;
    int age;
    string address;
    Date takeTestAfter;
    Date validTill;
    testState currentTestState;
    int computerTestScore; 
};

struct License
{
    int licenseID;
    vehicleType licenseType;
    licenseState licenseStatus;
    Date issueDate;
    Date expirydate;
};

struct User {
    int userID;
    string name;
    string CNIC;
    userState userStatus;
    string Password;
    int learnerUb;
    int licenseUb;
    User* left;
    User* right;
    Learner learnerRecord[5];
    License licenseRecord[5];
};

struct Question {
    string questionText;
    string asciiArt;
    string options[4];
    int correctAnswer; // 0-3
};

struct TestResult {
    int userID;
    int learnerID;
    vehicleType testType;
    int computerTestScore;
    int practicalTestScore;
    Date testDate;
    bool computerPassed;
    bool practicalPassed;
};

User* root = NULL;

Question trafficSignQuestions[10];

// -------------------------FUNCTIONS START HERE-----------------------------------------------

void showLearnerTypeMenu()
{
    cout << "\nSelect Learner Type:\n";
    cout << "0. Motorcycle\n";
    cout << "1. Car\n";
    cout << "2. LTV\n";
    cout << "3. HTV\n";
    cout << "4. PSV\n";
}

void insertUserIntoBST(User* newUser)
{
    newUser->left = NULL;
    newUser->right = NULL;

    if (root == NULL)
    {
        root = newUser;
        return;
    }

    User* current = root;
    User* parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (newUser->userID < current->userID)
            current = current->left;
        else
            current = current->right;
    }

    if (newUser->userID < parent->userID)
        parent->left = newUser;
    else
        parent->right = newUser;
}

void saveUsersToFile(User* root, ofstream& out)
{
    if (!root) return;

    out << root->userID << "|"
        << root->name << "|"
        << root->CNIC << "|"
        << root->userStatus << "|"
        << root->Password << "\n";

    saveUsersToFile(root->left, out);
    saveUsersToFile(root->right, out);
}

void saveAll()
{
    ofstream out("users.txt");
    saveUsersToFile(root, out);
    out.close();
}

void loadUsersFromFile()
{
    ifstream in("users.txt");
    if (!in) return;  // file not found is fine

    string line;
    while (getline(in, line))
    {
        if (line.empty()) continue; // skip empty lines

        stringstream ss(line);
        string token;

        User* u = new User();
        u->left = u->right = nullptr;
        u->learnerUb = u->licenseUb = -1;

        try {
            // Read and convert userID
            if (!getline(ss, token, '|') || token.empty())
                throw runtime_error("Missing userID");
            u->userID = stoi(token);

            // Read name
            if (!getline(ss, u->name, '|'))
                throw runtime_error("Missing name");

            // Read CNIC
            if (!getline(ss, u->CNIC, '|'))
                throw runtime_error("Missing CNIC");

            // Read userStatus
            if (!getline(ss, token, '|') || token.empty())
                throw runtime_error("Missing userStatus");
            u->userStatus = static_cast<userState>(stoi(token));

            // Read Password
            if (!getline(ss, u->Password, '|'))
                throw runtime_error("Missing Password");
        }
        catch (const exception& e) {
           /* cerr << "Skipping invalid line: \"" << line << "\" (" << e.what() << ")\n";*/
            delete u; // avoid memory leak
            continue; // skip this user
        }

        // Everything is valid, insert into BST
        insertUserIntoBST(u);

        // Update hash sets
        usedCNICs.insert(u->CNIC);
        usedIDs.insert(u->userID);
    }

    in.close();
}

string dateToString(const Date& d);

User* searchUserByID(User* root, int userID);

void saveLearnersOfUser(const User* user, ofstream& out)
{
    for (int i = 0; i <= user->learnerUb; i++)
    {
        const Learner& L = user->learnerRecord[i];

        out << user->userID << "|"
            << L.learnerID << "|"
            << L.learnerType << "|"
            << L.learnerStatus << "|"
            << L.age << "|"
            << L.fatherName << "|"
            << L.address << "|"
            << dateToString(L.takeTestAfter) << "|"
            << dateToString(L.validTill) << "|"
            << L.currentTestState << "|"     
            << L.computerTestScore << "\n";     
    }
}

Date stringToDate(const std::string& str) {
    Date d;
    sscanf_s(str.c_str(), "%d-%d-%d", &d.day, &d.month, &d.year);
    return d;
}

void saveAllLearners(User* root, ofstream& out)
{
    if (!root) return;

    saveLearnersOfUser(root, out);
    saveAllLearners(root->left, out);
    saveAllLearners(root->right, out);
}

void saveLearners()
{
    ofstream out("learners.txt");
    saveAllLearners(root, out);
    out.close();
}

void loadLearnersFromFile()
{
    ifstream in("learners.txt");
    if (!in) return;

    string line;
    while (getline(in, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        int userID;
        getline(ss, token, '|');
        userID = stoi(token);

        User* user = searchUserByID(root, userID);
        if (!user) continue; // orphan record safety

        Learner L;

        getline(ss, token, '|'); L.learnerID = stoi(token);
        getline(ss, token, '|'); L.learnerType = static_cast<vehicleType>(stoi(token));
        getline(ss, token, '|'); L.learnerStatus = static_cast<learnerState>(stoi(token));
        getline(ss, token, '|'); L.age = stoi(token);
        getline(ss, L.fatherName, '|');
        getline(ss, L.address, '|');

        getline(ss, token, '|'); L.takeTestAfter = stringToDate(token);
        getline(ss, token, '|'); L.validTill = stringToDate(token);

        if (getline(ss, token, '|')) {
            L.currentTestState = static_cast<testState>(stoi(token));
        } else {
            L.currentTestState = NOT_TESTED;
        }
        
        if (getline(ss, token, '|')) {
            L.computerTestScore = stoi(token);
        } else {
            L.computerTestScore = 0;
        }

        // Insert learner
        user->learnerUb++;
        user->learnerRecord[user->learnerUb] = L;
        user->userStatus = LEARNER;
    }

    in.close();
}

void saveLicensesOfUser(const User* user, ofstream& out)
{
    for (int i = 0; i <= user->licenseUb; i++)
    {
        const License& L = user->licenseRecord[i];

        out << user->userID << "|"
            << L.licenseID << "|"
            << L.licenseType << "|"
            << L.licenseStatus << "|"
            << dateToString(L.issueDate) << "|"
            << dateToString(L.expirydate) << "\n";
    }
}

void saveAllLicenses(User* root, ofstream& out)
{
    if (!root) return;

    saveLicensesOfUser(root, out);
    saveAllLicenses(root->left, out);
    saveAllLicenses(root->right, out);
}

void saveLicenses()
{
    ofstream out("licenses.txt");
    saveAllLicenses(root, out);
    out.close();
}

void loadLicensesFromFile()
{
    ifstream in("licenses.txt");
    if (!in) return;

    string line;
    while (getline(in, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        int userID;
        getline(ss, token, '|');
        userID = stoi(token);

        User* user = searchUserByID(root, userID);
        if (!user) continue;

        License L;
        getline(ss, token, '|'); L.licenseID = stoi(token);
        getline(ss, token, '|'); L.licenseType = static_cast<vehicleType>(stoi(token));
        getline(ss, token, '|'); L.licenseStatus = static_cast<licenseState>(stoi(token));
        getline(ss, token, '|'); L.issueDate = stringToDate(token);
        getline(ss, token, '|'); L.expirydate = stringToDate(token);

        user->licenseUb++;
        user->licenseRecord[user->licenseUb] = L;
        user->userStatus = LICENSED;
    }

    in.close();
}

int getValidAge()
{
    int age;
    while (true)
    {
        cout << "Enter your age: ";
        if (!(cin >> age))  // input failed (not an int)
        {
            cout << "Invalid choice. Please enter a number.\n";

            cin.clear();                // clear fail state
            cin.ignore(10000, '\n');    // discard invalid input
            continue;
        }


        if (age <= 0 || age > 125)
        {
            cout << "Age is not valid.\n";
            continue;
        }
        return age;
    }
}

// -------------------------------- functions to handle dates ------------------------------------ 

Date getCurrentDate()
{
    Date d;
    time_t t = time(nullptr);
    tm now;
    localtime_s(&now, &t);

    d.day = now.tm_mday;
    d.month = now.tm_mon + 1;
    d.year = now.tm_year + 1900;

    return d;
}

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && isLeap(year)) return 29;
    return days[month - 1];
}

//---------------------------------add days---------------------------------------------

void addDays(Date& d, int daysToAdd) {
    while (daysToAdd--) {
        d.day++;
        if (d.day > daysInMonth(d.month, d.year)) {
            d.day = 1;
            d.month++;
            if (d.month > 12) {
                d.month = 1;
                d.year++;
            }
        }
    }
}

// ------------------------------convert date to string----------------------------- 

string dateToString(const Date& d) {
    return to_string(d.day) + "-" +
        to_string(d.month) + "-" +
        to_string(d.year);
}

// -------------------------clear screen------------------------------------------------

void clearScreen()
{
    system("CLS");
}

// -----------------------------------random and unique id generator-------------------------

int generateUniqueID()
{
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dist(10000, 99999);

    int id;
    do {
        id = dist(gen);
    } while (usedIDs.count(id));

    usedIDs.insert(id);
    return id;
}

// -------------------------------is aphabet----------------------------------------

bool isAlphabetic(const string& s)
{
    if (s.empty()) return false;

    for (char c : s)
    {
        if (!(
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == ' '                  
            ))
        {
            return false;
        }
    }
    return true;
}

// ---------------------------------is numeric-----------------------------------

bool isNumeric(const string& s)
{
    if (s.empty()) return false;
    for (char c : s)
        if (!isdigit(c))
            return false;
    return true;
}

// ----------------------------valid name-------------------------------------------

string getValidName()
{
    string name;

    while (true)
    {
        cout << "Enter Name: ";
        getline(cin, name);

        if (isAlphabetic(name))
            return name;

        cout << " Invalid name. Use alphabets only.\n";
    }
}

// -----------------------------valid cnic------------------------------

bool isUniqueCNIC(const string& cnic)
{
    return  usedCNICs.count(cnic) == 0;
}

bool isValidCNIC(const string& cnic) {
    if (cnic.length() != 13) return false;
    for (char c : cnic) {
        if (!isdigit(c)) return false;
    }
    return true;
}

CNICResult getValidCNIC(string& cnic)
{
    string input;

    while (true)
    {
        cout << "\nEnter CNIC (13 digits, no dashes): ";
        getline(cin, cnic);

        if (!isValidCNIC(cnic))
        {
            cout << "\nInvalid CNIC. Try again.\n";
            continue;
        }

        if (!isUniqueCNIC(cnic))
        {
            while (true)
            {
                cout << "\nCNIC already exists!\n\n";
                cout << "1. Go to Login\n";
                cout << "2. Enter CNIC Again\n\n";
                cout << "Choice: ";

                getline(cin, input);

                if (!isNumeric(input)) {
                    cout << "\nNumbers only!\n";
                    continue;
                }

                int choice = stoi(input);

                if (choice == 1)
                    return CNIC_EXISTS_GO_LOGIN;
                else if (choice == 2)
                    break;   // re-enter CNIC
                else
                    cout << "\nInvalid choice!\n";
            }
        }
        else
        {
            usedCNICs.insert(cnic);
            return CNIC_OK;
            
        }
    }
}

bool learnerExists(const User* user, int learnerUb, vehicleType type)
{
    for (int i = 0; i <= learnerUb; i++)
    {
        if (user->learnerRecord[i].learnerType == type)
            return true;
    }
    return false;
}

bool licenseExists(const User* user, int licenseUb, vehicleType type)
{
    for (int i = 0; i <= licenseUb; i++)
    {
        if (user->licenseRecord[i].licenseType == type)
            return true;
    }
    return false;
}

bool isEligibleForLearner(User* user, vehicleType type, int age)
{
    switch (type)
    {
    case MOTORCYCLE:
    case CAR:
        return age >= 18;

    case LTV:
        return age >= 21 && licenseExists(user, user->licenseUb, CAR);

    case HTV:
        return age >= 25 && licenseExists(user, user->licenseUb, LTV);

    case PSV:
        return age >= 25 && licenseExists(user, user->licenseUb, HTV);

    default:
        return false;
    }
}

string vehicleTypeToString(vehicleType type)
{
    switch (type)
    {
    case MOTORCYCLE: return "Motorcycle";
    case CAR:        return "Car";
    case LTV:        return "LTV";
    case HTV:        return "HTV";
    case PSV:        return "PSV";
    default:         return "Unknown";
    }
}

void viewLearners(const User* user)
{
    if (user->userStatus != LEARNER)
    {
        cout << "\nYou don't have any active learner at the moment.\n";
        return;
    }

    bool found = false;

    cout << "\n----- Your Active Learners -----\n";

    for (int i = 0; i <= user->learnerUb; i++)
    {
        const Learner& L = user->learnerRecord[i];

        if (L.learnerStatus == ACTIVE_LEARNER)
        {
            found = true;
            cout << "\nLearnerID   : " << L.learnerID;
            cout << "\nLearner Type   : " << vehicleTypeToString(L.learnerType);
            cout << "\nFather Name   : " << L.fatherName;
            cout << "\nAge           : " << L.age;
            cout << "\nAddress       : " << L.address;
            cout << "\nTest After    : " << dateToString(L.takeTestAfter);
            cout << "\nValid Till    : " << dateToString(L.validTill);
            cout << "\n--------------------------------\n";
        }
    }

    if (!found)
    {
        cout << "\nNo active learner found.\n";
    }
}

void viewLicenses(const User* user)
{
    if (user->userStatus != LICENSED)
    {
        cout << "\nYou don't have any valid license at the moment.\n";
        return;
    }

    bool found = false;

    cout << "\n----- Your Active Licenses -----\n";

    for (int i = 0; i <= user->licenseUb; i++)
    {
        const License& L = user->licenseRecord[i];

        if (L.licenseStatus == ACTIVE_LICENSE)
        {
            found = true;

            cout << "\nLicense Type   : " << vehicleTypeToString(L.licenseType);
            cout << "\nLicense ID     : " << L.licenseID;
            cout << "\nIssued On      : " << dateToString(L.issueDate);
            cout << "\nValid Till     : " << dateToString(L.expirydate);
            cout << "\n--------------------------------\n";
        }
    }

    if (!found)
    {
        cout << "\nNo active license found.\n";
    }
}

void viewMedicalForm(const User* user,const string& filePath)
{
    if (user->userStatus != LEARNER)
    {
        cout << "\nYou should have a valid learner to view medical forms.\n";
        return;
    }

    // --- Check if file exists ---
    ifstream file(filePath);
    if (!file.good())
    {
        cout << "\nMedical form not found at the given location.\n";
        return;
    }
    file.close();

    // --- Open PDF ---
    HINSTANCE result = ShellExecuteA(
        NULL,
        "open",
        filePath.c_str(),
        NULL,
        NULL,
        SW_SHOWNORMAL
    );

    // --- Error handling ---
    if ((INT_PTR)result <= 32)
    {
        cout << "\nFailed to open medical form.\n";
        cout << "Make sure a PDF viewer is installed.\n";
        return;
    }

    cout << "\nMedical form opened successfully.\n";
}

void showSuccessAndHold(const string& msg);

void createLearner(User* user)
{
    int age = getValidAge();

    if (age < 18)
    {
        cout << "\nYou are too young for driving.\n";
        
        return;
    }

    vehicleType type;
    int choice;

    while (true)
    {
        showLearnerTypeMenu();
        cout << "\nEnter choice (-1 to go back): ";

        if (!(cin >> choice))  // input failed (not an int)
        {
            cout << "\nInvalid choice. Please enter a number.\n";

            cin.clear();                // clear fail state
            cin.ignore(10000, '\n');    // discard invalid input
            continue;
        }

        if (choice == -1) {
            clearScreen();
            return;
        };

        if (choice < 0 || choice > 4)
        {
            cout << "\nInvalid learner type.\n";
            continue;
        }

        type = static_cast<vehicleType>(choice);

        if (!isEligibleForLearner(user, type, age))
        {
            cout << "\nYou are not eligible for this learner type.\n";
     
            continue;
        }

        if (learnerExists(user, user->learnerUb, type))
        {
            cout << "\nYou already have this learner.\n";
        
            return;
        }

        break;
    }
    
    user->learnerUb++;            // NOW increment
    // --- Insert learner at UB index ---
    Learner& L = user->learnerRecord[user->learnerUb];

    cin.ignore();
    cout << "\nEnter Father's Name: ";
    getline(cin, L.fatherName);

    cout << "Enter Address: ";
    getline(cin, L.address);

    L.age = age;
    L.learnerType = type;
    L.learnerStatus = ACTIVE_LEARNER;
    L.learnerID = generateUniqueID();
    L.currentTestState = NOT_TESTED; 
    L.computerTestScore = 0;
    // --- Dates ---
    Date today = getCurrentDate();

    L.takeTestAfter = today;
    addDays(L.takeTestAfter, 41);

    L.validTill = today;
    addDays(L.validTill, 180); //  6 months

    user->userStatus = LEARNER;
    showSuccessAndHold("\n\nLearner has been created successfully! Pay the fee!!!");
    cout << "\nNow you have an ACTIVE LEARNER.\n";
    cout << "Test after: " << dateToString(L.takeTestAfter) << "\n";
    cout << "Valid till: " << dateToString(L.validTill) << "\n";
    showSuccessAndHold("");
    clearScreen();
}

User* searchUserByID(User* root, int userID)
{
    if (!root) return nullptr;

    if (root->userID == userID)
        return root;
    else if (userID < root->userID)
        return searchUserByID(root->left, userID);
    else
        return searchUserByID(root->right, userID);
}

bool isValidUserID(int id)
{
    return id >= 10000 && id <= 99999;
}

void userDashboard(User* user);

void userLogsIn()
{
    int userID;
    string password;

    while (true)
    {
        cout << "\n--- User Login ---\n";
        cout << "\nEnter 5-digit User ID (0 to go back): ";
        if (!(cin >> userID))  // input failed (not an int)
        {
            cout << "\nInvalid choice. Please enter a number.\n";

            cin.clear();                // clear fail state
            cin.ignore(10000, '\n');    // discard invalid input
            continue;
        }
        if (userID == 0)
            return; // back to main menu

        if (!isValidUserID(userID))
        {
            cout << "\nInvalid User ID. Must be 5 digits.\n";
            continue;
        }

        User* user = searchUserByID(root, userID);

        if (!user)
        {
            cout << "User not found. Try again.\n";
            continue;
        }

        cout << "Enter Password: ";
        cin >> password;

        if (user->Password != password)
        {
            cout << "Incorrect password. Try again.\n";
            continue;
        }

        // SUCCESS
        
        clearScreen();
        userDashboard(user);
        return; // after logout → back to main menu
    }
}

void userDashboard(User* user)
{
    int choice;
    display_USER_DASHBOARD_LOGO();
    do
    {
        cout << "\n--- User Dashboard ---\n";
        cout << "\nWelcome " << user->name << " \n";
        cout << "1. Apply for Learner\n";
        cout << "2. View Learners\n";
        cout << "3. View Licenses\n";
        cout << "4. View Medical Forms\n";
        cout << "5. log out\n\n";
        cout << "Enter choice: ";
        if (!(cin >> choice))  // input failed (not an int)
        {
            cout << "\nInvalid choice. Please enter a number.\n";

            cin.clear();                // clear fail state
            cin.ignore(10000, '\n');    // discard invalid input
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            createLearner(user);
            break;
        }
        case 2:
        {
            viewLearners(user);
            break;
        }

        case 3:
        {
            viewLicenses(user);
            break;
        }
        case 4:
        {
            viewMedicalForm(user,R"(Medical Form.pdf)");
            break;
        }
        case 5:
        {
            cout << "Logging out...\n";
            break;
        }
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);
}

//------------------------------------- Function to validate password: 5-15 characters---------------

bool isValidPassword(const string& password) {
    return password.length() >= 5 && password.length() <= 40;
}

string getValidPassword()
{
    string pass;

    while (true)
    {
        cout << "Enter Password(between 5 and 40 characters): ";
        getline(cin, pass);

        if (isValidPassword(pass))
            return pass;

        cout << "\nPassword Invalid.\n";
    }
}

//-----------------------------success message function-------------------------------------

void showSuccessAndHold(const string& msg)
{
    cout << "\n" << msg << "\n";
    cout << "\nPress Enter to continue...";
    cin.get();
}

//function declaration to avoid errors
void licenseInchargeDashboard();
bool login();
void registration();

void initializeTestQuestions() {
    // Question 1
    trafficSignQuestions[0].questionText = "What does this sign mean?";
    trafficSignQuestions[0].asciiArt = R"(
       ________
      /        \
     |    \/    |
     |    /\    |
      \________/
    )";
    trafficSignQuestions[0].options[0] = "1. Slow down";
    trafficSignQuestions[0].options[1] = "2. Road Closed";
    trafficSignQuestions[0].options[2] = "3. Yield to traffic";
    trafficSignQuestions[0].options[3] = "4. One Way";
    trafficSignQuestions[0].correctAnswer = 1;

    // Question 2
    trafficSignQuestions[1].questionText = "What does this sign indicate?";
    trafficSignQuestions[1].asciiArt = R"(
          /\
         /  \
        / 40 \
       /______\
    )";
    trafficSignQuestions[1].options[0] = "1. Minimum speed 40";
    trafficSignQuestions[1].options[1] = "2. Distance 40 km";
    trafficSignQuestions[1].options[2] = "3. Maximum speed 40";
    trafficSignQuestions[1].options[3] = "4. Route number 40";
    trafficSignQuestions[1].correctAnswer = 2;

    // Question 3
    trafficSignQuestions[2].questionText = "What does this sign mean?";
    trafficSignQuestions[2].asciiArt = R"(
       ___________
      /           \
     |      NO     |
     |    ENTRY    |
      \___________/
    )";
    trafficSignQuestions[2].options[0] = "1. One way street";
    trafficSignQuestions[2].options[1] = "2. No entry for vehicles";
    trafficSignQuestions[2].options[2] = "3. Parking prohibited";
    trafficSignQuestions[2].options[3] = "4. Road closed";
    trafficSignQuestions[2].correctAnswer = 1;

    // Question 4
    trafficSignQuestions[3].questionText = "What does this sign indicate?";
    trafficSignQuestions[3].asciiArt = R"(
          /\
         /||\
        / || \
       /  ||  \
      /__||||__\
    )";
    trafficSignQuestions[3].options[0] = "1. Merge ahead";
    trafficSignQuestions[3].options[1] = "2. Two-way traffic";
    trafficSignQuestions[3].options[2] = "3. Divided highway";
    trafficSignQuestions[3].options[3] = "4. Road narrows ahead";
    trafficSignQuestions[3].correctAnswer = 3;

    // Question 5
    trafficSignQuestions[4].questionText = "What does this sign mean?";
    trafficSignQuestions[4].asciiArt = R"(
       ___________
      |           |
      |     P     |
      |___________|
    )";
    trafficSignQuestions[4].options[0] = "1. Private property";
    trafficSignQuestions[4].options[1] = "2. Police station ahead";
    trafficSignQuestions[4].options[2] = "3. Parking allowed";
    trafficSignQuestions[4].options[3] = "4. Pedestrian crossing";
    trafficSignQuestions[4].correctAnswer = 2;

    // Question 6
    trafficSignQuestions[5].questionText = "What does this sign indicate?";
    trafficSignQuestions[5].asciiArt = R"(
          /\
         /  \
        / !! \
       /______\
    )";
    trafficSignQuestions[5].options[0] = "1. Danger ahead";
    trafficSignQuestions[5].options[1] = "2. Stop ahead";
    trafficSignQuestions[5].options[2] = "3. Hospital ahead";
    trafficSignQuestions[5].options[3] = "4. School zone";
    trafficSignQuestions[5].correctAnswer = 0;

    // Question 7
    trafficSignQuestions[6].questionText = "What does this sign mean?";
    trafficSignQuestions[6].asciiArt = R"(
       ___________
      |           |
      |    <--    |
      |___________|
    )";
    trafficSignQuestions[6].options[0] = "1. Turn right only";
    trafficSignQuestions[6].options[1] = "2. U-turn allowed";
    trafficSignQuestions[6].options[2] = "3. Turn left only";
    trafficSignQuestions[6].options[3] = "4. Straight ahead";
    trafficSignQuestions[6].correctAnswer = 2;

    // Question 8
    trafficSignQuestions[7].questionText = "What does this sign indicate?";
    trafficSignQuestions[7].asciiArt = R"(
          /\
         /  \
        /~~~~\
       /______\
    )";
    trafficSignQuestions[7].options[0] = "1. Flooded area";
    trafficSignQuestions[7].options[1] = "2. Slippery road";
    trafficSignQuestions[7].options[2] = "3. Bridge ahead";
    trafficSignQuestions[7].options[3] = "4. Rough road";
    trafficSignQuestions[7].correctAnswer = 1;

    // Question 9
    trafficSignQuestions[8].questionText = "What does this sign mean?";
    trafficSignQuestions[8].asciiArt = R"(
       ______________
      |              |
      |    SCHOOL    |
      |______________|
    )";
    trafficSignQuestions[8].options[0] = "1. Library ahead";
    trafficSignQuestions[8].options[1] = "2. School zone - reduce speed";
    trafficSignQuestions[8].options[2] = "3. Children playing area";
    trafficSignQuestions[8].options[3] = "4. Educational district";
    trafficSignQuestions[8].correctAnswer = 1;

    // Question 10
    trafficSignQuestions[9].questionText = "What does this sign indicate?";
    trafficSignQuestions[9].asciiArt = R"(
       _____________
      /             \
     |     YIELD     |
      \_____________/
    )";
    trafficSignQuestions[9].options[0] = "1. Stop completely";
    trafficSignQuestions[9].options[1] = "2. No passing";
    trafficSignQuestions[9].options[2] = "3. Speed up";
    trafficSignQuestions[9].options[3] = "4. Give way to other traffic";
    trafficSignQuestions[9].correctAnswer = 3;
}

int conductComputerTest() {
    int score = 0;
    cout << "\n\n========================================\n";
    cout << "     COMPUTER-BASED SIGN TEST\n";
    cout << "========================================\n\n";
    cout << "Total Questions: 10\n";
    cout << "Time per Question: 60 seconds\n";
    cout << "Passing Score: 5/10\n\n";
    cout << "========================================\n\n";
    
    system("pause");
    clearScreen();

    for (int i = 0; i < 10; i++) {
        cout << "\n\n";
        cout << "Question " << (i + 1) << "/10\n";
        cout << "========================================\n\n";
        cout << trafficSignQuestions[i].questionText << "\n\n";
        cout << trafficSignQuestions[i].asciiArt << "\n\n";

        for (int j = 0; j < 4; j++) {
            cout << trafficSignQuestions[i].options[j] << "\n";
        }

        cout << "========================================\n";
        
        int userAnswer = -1;
        auto startTime = chrono::steady_clock::now();
        bool answered = false;
        
        // Timer countdown loop
        while (!answered) {
            auto currentTime = chrono::steady_clock::now();
            auto elapsed = chrono::duration_cast<chrono::seconds>(currentTime - startTime).count();
            int timeLeft = 60 - elapsed;

            if (timeLeft <= 0) {
                cout << "\n\n*** TIME'S UP! Moving to next question ***\n";
                Sleep(1500);
                break;
            }

            // Display countdown timer
            cout << "\rTime remaining: " << timeLeft << " seconds  ";
            cout << "Enter your answer (1-4): ";
            cout.flush();

            // Check if input is available (non-blocking check simulation)
            if (_kbhit()) {
                cin >> userAnswer;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nInvalid input! Enter 1, 2, 3 or 4.\n";
                    Sleep(1000);
                    continue;
                }

                if (userAnswer < 1 || userAnswer > 4) {
                    cout << "\nInvalid choice! Enter 1, 2, 3 or 4.\n";
                    Sleep(1000);
                    continue;
                }

                answered = true;
                
                if ((userAnswer-1) == trafficSignQuestions[i].correctAnswer) {
                    score++;
                    cout << "\n✓ Correct!\n";
                } else {
                    cout << "\n✗ Incorrect! Correct answer was: " 
                         << trafficSignQuestions[i].options[trafficSignQuestions[i].correctAnswer] << "\n";
                }
            }

            Sleep(100); // Small delay to prevent CPU overuse
        }

        if (answered) {
            cout << "\nCurrent Score: " << score << "/10\n";
        } else {
            cout << "\nNo answer given. Current Score: " << score << "/10\n";
        }
        
        if (i < 9) {
            cout << "\nPress Enter for next question...";
            cin.ignore();
            cin.get();
            clearScreen();
        }

        if ( i == 9){
            cout << endl << endl;
            system("pause");
            clearScreen();
        }
    }

    return score;
}

int conductPracticalTest() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dist(30, 100);
    
    return dist(gen);
}

void issueLicense(User* user, vehicleType type) {
    user->licenseUb++;
    License& newLicense = user->licenseRecord[user->licenseUb];

    newLicense.licenseID = generateUniqueID();
    newLicense.licenseType = type;
    newLicense.licenseStatus = ACTIVE_LICENSE;
    newLicense.issueDate = getCurrentDate();
    newLicense.expirydate = getCurrentDate();
    addDays(newLicense.expirydate, 1825); // 5 years

    user->userStatus = LICENSED;

    display_LICENSE_ISSUED_LOGO();
    cout << "\n\nLicense ID: " << newLicense.licenseID << "\n";
    cout << "Type: " << vehicleTypeToString(type) << "\n";
    cout << "Issue Date: " << dateToString(newLicense.issueDate) << "\n";
    cout << "Valid Till: " << dateToString(newLicense.expirydate) << "\n";
}

void testingOfficerDashboard() {
    string username, password;
    int attempts = 0;
    bool authenticated = false;

    while (attempts < 3) {
        display_TESTER_OFFICER();
        cout << endl << endl<< "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "admin" && password == "root12345") {
            authenticated = true;
            break; 
        } 
        else if (username == "admin" && password != "root12345") {
            cout << "\n[!] Password incorrect. Please enter correct password.\n\n";
        } 
        else {
            cout << "\n[!] Username and Password incorrect. Please enter again.\n\n";
        }

        attempts++;
        if (attempts < 3) {
            system("pause");
            clearScreen();
        }
    }

    if (!authenticated) {
        cout << "\n[!!!] Maximum login attempts exceeded. Access Restricted.\n";
        system("pause");
        clearScreen();
        return;
    }

    clearScreen();

    while (true) {
        int userID;
        display_TRAFFIC_OFFICER_DASHBOARD_LOGO();
        cout << endl << endl << "Enter User ID to test (0 to logout): ";
        
        if (!(cin >> userID)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input. Enter again!!!\n\n";
            system("pause");
            clearScreen();
            continue;
        }

        if (userID == 0) {
            cout << "\nLogging out...\n";
            clearScreen();
            return;
        }

        User* user = searchUserByID(root, userID);
        
        if (!user) {
            cout << "\nUser not found!\n\n";
            system("pause");
            clearScreen();
            continue;
        }

        if (user->userStatus != LEARNER) {
            cout << "\nYou don't have an active learner permit!\n\n";
            system("pause");
            clearScreen();
            continue;
        }

        // Find active learner
        int activeLearnerIndex = -1;
        for (int i = 0; i <= user->learnerUb; i++) {
            if (user->learnerRecord[i].learnerStatus == ACTIVE_LEARNER) {
                activeLearnerIndex = i;
                break;
            }
        }

        if (activeLearnerIndex == -1) {
            cout << "\nNo active learner found!\n";
            system("pause");
            clearScreen();
            continue;
        }

        Learner& learner = user->learnerRecord[activeLearnerIndex];

        clearScreen();
        cout << "\n========================================\n";
        cout << "     APPLICANT INFORMATION\n";
        cout << "========================================\n\n";
        cout << "Name: " << user->name << "\n";
        cout << "User ID: " << user->userID << "\n";
        cout << "Learner ID: " << learner.learnerID << "\n";
        cout << "Learner Type: " << vehicleTypeToString(learner.learnerType) << "\n";
        cout << "Father Name: " << learner.fatherName << "\n";
        cout << "Age: " << learner.age << "\n";
        cout << "Address: " << learner.address << "\n\n";
        cout << "========================================\n\n\n";
        system("pause");
        clearScreen();

        // Check test state and proceed accordingly
        if (learner.currentTestState == NOT_TESTED) {
            // First time testing
            cout << "\n\nChecking medical form...\n";
            Sleep(2500);
            cout << "\nMedical form is CORRECT!\n\n";
            system("pause");

            // Computer test
            clearScreen();
            cout << "\n\nStarting Computer-Based Sign Test...\n\n\n";
            system("pause");
            clearScreen();

            int computerScore = conductComputerTest();
            learner.computerTestScore = computerScore;  // Save score
            clearScreen();

            cout << "\n\n========================================\n\n";
            cout << "     COMPUTER TEST RESULTS\n\n";
            cout << "========================================\n\n";
            cout << "Score: " << computerScore << "/10\n\n";

            bool computerPassed = (computerScore >= 5);
            
            if (computerPassed) {
                user -> userStatus = SIGN_TEST_PASS;
                cout << "Status: PASSED\n\n";
                cout << "========================================\n\n\n";
                learner.currentTestState = COMPUTER_PASSED;  // Update state
                saveLearners();
            } else {
                cout << "Status: FAILED\n";
                cout << "Required: 5/10 minimum\n\n";
                cout << "========================================\n\n";
                
                cout << "Better luck next time!\n\n";
                system("pause");
                clearScreen();
                continue;
            }

            system("pause");
        } 
        else if (learner.currentTestState == COMPUTER_PASSED) {
            // Already passed computer test
            cout << "\n\nMedical form: ALREADY VERIFIED";
            cout << "\nComputer Test: ALREADY PASSED (" << learner.computerTestScore << "/10)\n\n";
            cout << "Proceeding directly to Practical Driving Test...\n\n";
            system("pause");
        }
        else if (learner.currentTestState == PRACTICAL_FAILED) {
            // Failed practical test before
            cout << "\n\nMedical form: ALREADY VERIFIED\n";
            cout << "Computer Test: ALREADY PASSED (" << learner.computerTestScore << "/10)\n";
            cout << "Previous Practical Driving Test: FAILED\n\n";
            cout << "Retaking Practical Driving Test...\n\n";
            system("pause");
        }

        // Practical test
        clearScreen();
        cout << "\n========================================\n\n";
        cout << "     PRACTICAL DRIVING TEST\n\n";
        cout << "========================================\n\n";
        cout << "Conducting practical test...\n\n";
        Sleep(2500);
        cout << "1. Testing vehicle control...\n\n";
        Sleep(2500);
        cout << "2. Testing traffic rules application...\n\n";
        Sleep(2500);
        cout << "3. Testing parking skills...";
        Sleep(2500);

        int practicalScore = conductPracticalTest();
        cout << endl << endl << endl;
        system("pause");
        clearScreen();

        cout << "\n========================================\n\n";
        cout << "     PRACTICAL TEST RESULT\n\n";
        cout << "========================================\n\n";
        cout << "Score: " << practicalScore << "/100\n";
        
        bool practicalPassed = (practicalScore >= 70);
        
        if (practicalPassed) {
            cout << "Status: PASSED\n\n";
            cout << "========================================\n\n\n\n";
            
            // Update learner status
            learner.learnerStatus = COMPLETE;
            learner.currentTestState = BOTH_PASSED;
            saveLearners();

            // Issue license
            system("pause");
            clearScreen();
            issueLicense(user, learner.learnerType);

            cout << "\n\nCongratulations! License has been issued.\n\n\n";
            system("pause");
            clearScreen();
        } else {
            cout << "Status: FAILED\n";
            cout << "Required: 70/100 minimum\n\n";
            cout << "========================================\n\n";
            
            learner.currentTestState = PRACTICAL_FAILED;  // Update state
            saveLearners();
            
            cout << "\nYou need to retake the practical test.\n";
            cout << "Computer test score is saved. You won't need to retake it.\n\n";
            system("pause");
            clearScreen();
        }
    }
}

bool login()
{
    int choice;

    while (true) {

        display_welcome_logo();
        // Login Options
        cout << "\n\nLogin as:\n";
        cout << "1. Applicant\n";
        cout << "2. Testing Officer\n";
        cout << "3. Incharge Licensing Branch\n";
        cout << "4. Don't Have an Account?? Register\n";
        cout << "5. Exit\n";

        string input;
        cout << "\nEnter your choice: ";
        getline(cin, input);
        if (isNumeric(input))
        {
            choice = stoi(input);
            break;
        }
        else
        {
            cout << " Numbers only!\n";
            clearScreen();
        }
    }
    // Clear screen after choice
        clearScreen();
        
    switch (choice)
    {
    case 1:
    { 
        display_login_page();
        display_TRAFFIC_LIGHTS();
        userLogsIn();
        return true;
    }
    case 2:
    {
        clearScreen();
        testingOfficerDashboard();
        return true;
    }
    case 3:
    {
     clearScreen();
    licenseInchargeDashboard();
    return true;
    }
    case 4:
    {
        registration();
        return true;
        return true;
    }
    case 5:
    {
        return false;
        break;
    }
    default:
    {

        showSuccessAndHold("Invalid Choice");
        clearScreen();
        return true;
    }
    }
}

// ----------------------------------Register function------------------------------------

void registration()
{

    display_REGISTER();
    string cnic;
    CNICResult result = getValidCNIC(cnic);

    if (result == CNIC_EXISTS_GO_LOGIN)
    {
        clearScreen();
        login();
    }
    else if (result == CNIC_OK)
    {

        //creation of node
        User* applicant = new User();

        //filling of data
        applicant->CNIC = cnic;
        applicant->name = getValidName();
        applicant->Password = getValidPassword();
        applicant->userStatus = REGISTERERD;
        applicant->userID = generateUniqueID();
        applicant->learnerUb = -1;
        applicant->licenseUb = -1;

        insertUserIntoBST(applicant);

        cout << "\nYour Unique UserID is :"<<applicant->userID<<endl;
        showSuccessAndHold("Your Registration is Successful");
        
        clearScreen();
    }
}
//-------------------------Displaying Users in Incharge Module(In-order DFS)--------------------
void displayAllUsers(User* root) {
    if (!root) return;
    
    // Create a stack 
    User* stack[1000];  // Array-based stack
    int top = -1;       // Stack pointer
    User* current = root;
    
    // In-order traversal
    while (current != nullptr || top != -1) {
        // Go to leftmost node, pushing all nodes to stack
        while (current != nullptr) {
            stack[++top] = current;  // Push to stack
            current = current->left;
        }
        
        // Pop from stack and process
        current = stack[top--];  // Pop from stack
        
        // Process current node (display user)
        cout << "\n========================================\n";
        cout << "User ID: " << current->userID << "\n";
        cout << "Name: " << current->name << "\n";
        cout << "CNIC: " << current->CNIC << "\n";
        cout << "Status: ";
        
        switch(current->userStatus) {
            case REGISTERERD: 
                cout << "Registered (No Learner)"; 
                break;
            case LEARNER: 
                cout << "Has Active Learner"; 
                break;
            case SIGN_TEST_PASS: 
                cout << "Computer Test Passed"; 
                break;
            case LICENSED: 
                cout << "Has Valid License"; 
                break;
        }
        
        cout << "\n========================================\n";
        
        // Move to right subtree
        current = current->right;
    }
}

// -----------------Display learners in Incharge Module (Level-order-BFS) ---------------------------------------------

void displayAllLearnersInSystem(User* root) {
    if (!root) return;
    
    // Create a queue for level-order traversal (BFS)
    User* queue[1000];  // Array-based queue
    int front = 0;
    int rear = 0;
    
    // Enqueue root
    queue[rear++] = root;
    
    // Level-order traversal
    while (front < rear) {
        // Dequeue
        User* current = queue[front++];
        
        // Process current node
        if (current->learnerUb >= 0) {
            cout << "\n========================================\n";
            cout << "User: " << current->name << " (CNIC: " << current->CNIC << ")\n";
            cout << "========================================\n";
            
            // Loop through learner array
            for (int i = 0; i <= current->learnerUb; i++) {
                const Learner& L = current->learnerRecord[i];
                
                cout << "\nLearner ID: " << L.learnerID << "\n";
                cout << "Type: " << vehicleTypeToString(L.learnerType) << "\n";
                cout << "Status: ";
                
                switch(L.learnerStatus) {
                    case ACTIVE_LEARNER: 
                        cout << "Active"; 
                        break;
                    case EXPIRED_LEARNER: 
                        cout << "Expired"; 
                        break;
                    case COMPLETE: 
                        cout << "Completed (Licensed)"; 
                        break;
                }
                
                cout << "\nFather Name: " << L.fatherName << "\n";
                cout << "Age: " << L.age << "\n";
                cout << "Test After: " << dateToString(L.takeTestAfter) << "\n";
                cout << "Valid Till: " << dateToString(L.validTill) << "\n";
                
                cout << "Test Status: ";
                switch(L.currentTestState) {
                    case NOT_TESTED: 
                        cout << "Not Tested Yet"; 
                        break;
                    case COMPUTER_PASSED: 
                        cout << "Computer Test Passed (" << L.computerTestScore << "/10)"; 
                        break;
                    case PRACTICAL_FAILED: 
                        cout << "Practical Test Failed (Computer: " << L.computerTestScore << "/10)"; 
                        break;
                    case BOTH_PASSED: 
                        cout << "Both Tests Passed"; 
                        break;
                }
                
                cout << "\n" << string(40, '-') << "\n";
            }
        }
        
        // Enqueue left child
        if (current->left != nullptr) {
            queue[rear++] = current->left;
        }
        
        // Enqueue right child
        if (current->right != nullptr) {
            queue[rear++] = current->right;
        }
    }
}

// ----------------Displaying Licenses in Incharge Module(Level-order-BFS-----------------------

void displayAllLicensesInSystem(User* root) {
    if (!root) return;
    
    // Create a queue for level-order traversal
    User* queue[1000];
    int front = 0;
    int rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        User* current = queue[front++];
        
        if (current->licenseUb >= 0) {
            cout << "\n========================================\n";
            cout << "User: " << current->name << " (CNIC: " << current->CNIC << ")\n";
            cout << "========================================\n";
            
            for (int i = 0; i <= current->licenseUb; i++) {
                const License& L = current->licenseRecord[i];
                
                cout << "\nLicense ID: " << L.licenseID << "\n";
                cout << "Type: " << vehicleTypeToString(L.licenseType) << "\n";
                cout << "Status: ";
                
                switch(L.licenseStatus) {
                    case ACTIVE_LICENSE: 
                        cout << "Active"; 
                        break;
                    case EXPIRED_LICENSE: 
                        cout << "Expired"; 
                        break;
                }
                
                cout << "\nIssued On: " << dateToString(L.issueDate) << "\n";
                cout << "Valid Till: " << dateToString(L.expirydate) << "\n";
                cout << string(40, '-') << "\n";
            }
        }
        
        if (current->left != nullptr) {
            queue[rear++] = current->left;
        }
        
        if (current->right != nullptr) {
            queue[rear++] = current->right;
        }
    }
}

// -----------------------Queue based Traversal for Counting------------------------------

int countNodes(User* root) {
    if (!root) return 0;
    
    int count = 0;
    User* queue[1000];
    int front = 0;
    int rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        User* current = queue[front++];
        count++;  // Count this node
        
        if (current->left != nullptr) {
            queue[rear++] = current->left;
        }
        
        if (current->right != nullptr) {
            queue[rear++] = current->right;
        }
    }
    
    return count;
}

int countLearners(User* root) {
    if (!root) return 0;
    
    int count = 0;
    User* queue[1000];
    int front = 0;
    int rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        User* current = queue[front++];
        count += (current->learnerUb + 1);  // Add learner count
        
        if (current->left != nullptr) {
            queue[rear++] = current->left;
        }
        
        if (current->right != nullptr) {
            queue[rear++] = current->right;
        }
    }
    
    return count;
}

int countLicenses(User* root) {
    if (!root) return 0;
    
    int count = 0;
    User* queue[1000];
    int front = 0;
    int rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        User* current = queue[front++];
        count += (current->licenseUb + 1);  // Add license count
        
        if (current->left != nullptr) {
            queue[rear++] = current->left;
        }
        
        if (current->right != nullptr) {
            queue[rear++] = current->right;
        }
    }
    
    return count;
}

void displayStatistics(User* root) {
    cout << "\n========================================\n";
    cout << "       SYSTEM STATISTICS\n";
    cout << "========================================\n\n";
    
    cout << "Total Registered Users: " << countNodes(root) << "\n";
    cout << "Total Learners Issued: " << countLearners(root) << "\n";
    cout << "Total Licenses Issued: " << countLicenses(root) << "\n";
    
    cout << "\n========================================\n\n";
}

// -----------------------------Level-Order Search using CNIC------------------------------------

User* searchUserByCNIC(User* root, const string& cnic) {
    if (!root) return nullptr;
    
    // Use queue for level-order search
    User* queue[1000];
    int front = 0;
    int rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        User* current = queue[front++];
        
        // Check if this is the user we're looking for
        if (current->CNIC == cnic) {
            return current;  // Found!
        }
        
        // Add children to queue
        if (current->left != nullptr) {
            queue[rear++] = current->left;
        }
        
        if (current->right != nullptr) {
            queue[rear++] = current->right;
        }
    }
    
    return nullptr;  // Not found
}

void searchAndDisplayUser() {
    display_SEARCH_LOGO();
    
    string cnic;
    cout << "\nEnter CNIC (13 digits, no dashes): ";
    cin.ignore();
    getline(cin, cnic);
    
    // Validate CNIC format
    if (cnic.length() != 13) {
        cout << "\n[!] Invalid CNIC format! Must be 13 digits.\n";
        return;
    }
    
    for (char c : cnic) {
        if (!isdigit(c)) {
            cout << "\n[!] Invalid CNIC! Only digits allowed.\n";
            return;
        }
    }
    
    // Search for user
    User* user = searchUserByCNIC(root, cnic);
    
    if (!user) {
        cout << "\n[!] User not found!\n";
        return;
    }
    
    // Display user details
    cout << "\n========================================\n";
    cout << "       USER DETAILS\n";
    cout << "========================================\n\n";
    cout << "User ID: " << user->userID << "\n";
    cout << "Name: " << user->name << "\n";
    cout << "CNIC: " << user->CNIC << "\n";
    cout << "Status: ";
    
    switch(user->userStatus) {
        case REGISTERERD: cout << "Registered"; break;
        case LEARNER: cout << "Has Learner"; break;
        case SIGN_TEST_PASS: cout << "Sign Test Passed"; break;
        case LICENSED: cout << "Licensed"; break;
    }
    
    cout << "\n\n";
    
    // Display learners if any
    if (user->learnerUb >= 0) {
        cout << "--- LEARNERS ---\n";
        for (int i = 0; i <= user->learnerUb; i++) {
            const Learner& L = user->learnerRecord[i];
            cout << "\n  Learner " << (i + 1) << ":\n";
            cout << "  Learner ID: " << L.learnerID << "\n";
            cout << "  Type: " << vehicleTypeToString(L.learnerType) << "\n";
            cout << "  Status: ";
            switch(L.learnerStatus) {
                case ACTIVE_LEARNER: cout << "Active"; break;
                case EXPIRED_LEARNER: cout << "Expired"; break;
                case COMPLETE: cout << "Completed"; break;
            }
            cout << "\n  Valid Till: " << dateToString(L.validTill) << "\n";
            cout << "  Test Status: ";
            switch(L.currentTestState) {
                case NOT_TESTED: cout << "Not Tested"; break;
                case COMPUTER_PASSED: cout << "Computer Passed (" << L.computerTestScore << "/10)"; break;
                case PRACTICAL_FAILED: cout << "Practical Failed"; break;
                case BOTH_PASSED: cout << "All Tests Passed"; break;
            }
            cout << "\n";
        }
        cout << "\n";
    }
    
    // Display licenses if any
    if (user->licenseUb >= 0) {
        cout << "--- LICENSES ---\n";
        for (int i = 0; i <= user->licenseUb; i++) {
            const License& L = user->licenseRecord[i];
            cout << "\n  License " << (i + 1) << ":\n";
            cout << "  License ID: " << L.licenseID << "\n";
            cout << "  Type: " << vehicleTypeToString(L.licenseType) << "\n";
            cout << "  Status: ";
            switch(L.licenseStatus) {
                case ACTIVE_LICENSE: cout << "Active"; break;
                case EXPIRED_LICENSE: cout << "Expired"; break;
            }
            cout << "\n  Issued: " << dateToString(L.issueDate) << "\n";
            cout << "  Valid Till: " << dateToString(L.expirydate) << "\n";
        }
    }
    
    cout << "\n========================================\n";
}

// ----------------------------License Incharge Dashboard-----------------------------------------

void licenseInchargeDashboard() {
    string username, password;
    int attempts = 0;
    bool authenticated = false;

    while (attempts < 3) {
        display_INCHARGE_OFFICER();
        cout << endl << endl << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "incharge" && password == "incharge123") {
            authenticated = true;
            break;
        }
        else if (username == "incharge" && password != "incharge123") {
            cout << "\n[!] Password incorrect. Please try again.\n\n";
        }
        else {
            cout << "\n[!] Invalid username and password.\n\n";
        }

        attempts++;
        if (attempts < 3) {
            system("pause");
            clearScreen();
        }
    }

    if (!authenticated) {
        cout << "\n[!!!] Maximum login attempts exceeded. Access Restricted.\n";
        system("pause");
        clearScreen();
        return;
    }

    clearScreen();

    while (true) {
        display_INCHARGE_DASHBOARD();
        
        cout << "\n1. View All Registered Users\n";
        cout << "2. Search User by CNIC\n";
        cout << "3. View All Learners in System\n";
        cout << "4. View All Licenses in System\n";
        cout << "5. View System Statistics\n";
        cout << "6. Logout\n\n";
        cout << "Enter choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input! Enter a number.\n\n";
            system("pause");
            clearScreen();
            continue;
        }

        clearScreen();

        switch (choice) {
            case 1:
                display_ALL_USERS_LOGO();
                if (root == NULL) {
                    cout << "\nNo users registered yet!\n";
                } else {
                    displayAllUsers(root);
                }
                cout << "\n";
                system("pause");
                clearScreen();
                break;

            case 2:
                searchAndDisplayUser();
                cout << "\n";
                system("pause");
                clearScreen();
                break;

            case 3:
                display_LEARNERS_LOGO();
                if (root == NULL) {
                    cout << "\nNo learners in system yet!\n";
                } else {
                    displayAllLearnersInSystem(root);
                }
                cout << "\n";
                system("pause");
                clearScreen();
                break;

            case 4:
                display_LICENSES_LOGO();
                if (root == NULL) {
                    cout << "\nNo licenses in system yet!\n";
                } else {
                    displayAllLicensesInSystem(root);
                }
                cout << "\n";
                system("pause");
                clearScreen();
                break;

            case 5:
                display_STATISTICS_LOGO();
                displayStatistics(root);
                system("pause");
                clearScreen();
                break;

            case 6:
                cout << "\nLogging out...\n";
                clearScreen();
                return;

            default:
                cout << "\n[!] Invalid choice! Enter 1-6.\n\n";
                system("pause");
                clearScreen();
        }
    }
}

// ----------------------------------main function------------------------------------

int main()
{
    // 1. Set the console output to UTF-8
    SetConsoleOutputCP(65001);

    loadUsersFromFile();   //  restore memory
    loadLearnersFromFile();
    loadLicensesFromFile();
    initializeTestQuestions();

    bool programRunning = true;
    while (programRunning)
    {
        programRunning = login();
    }

    saveAll();     //  save memory
    saveLearners();
    saveLicenses();
    return 0;
}