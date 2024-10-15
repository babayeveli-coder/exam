#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

const int MAX_QUESTIONS = 100;
const int MAX_OPTIONS = 4;
string quizTitles[MAX_QUESTIONS];
string quizQuestions[MAX_QUESTIONS][MAX_QUESTIONS];
string quizOptions[MAX_QUESTIONS][MAX_QUESTIONS][MAX_OPTIONS];
int quizAnswers[MAX_QUESTIONS][MAX_QUESTIONS];
int numQuizzes = 0;
int numQuestions[MAX_QUESTIONS] = { 0 };

// Function to create a new quiz 
void createQuiz() {
    
    string quizTitle;

    cout << "Enter quiz title (single word): ";
    cin >> quizTitle;
    quizTitles[numQuizzes] = quizTitle;

    

    cout << "How many questions in this quiz? ";
    int qCount;
    cin >> qCount;
    numQuestions[numQuizzes] = qCount;

    for (int i = 0; i < qCount; ++i) {
        
        cout << "Enter question " << i + 1 << ": ";
        cin >> quizQuestions[numQuizzes][i];
        for (int j = 0; j < MAX_OPTIONS; ++j) {
            
            cout << "Enter option " << j + 1 << ": ";
            cin >> quizOptions[numQuizzes][i][j];
        }
        
        cout << "Enter correct answer (1-4): ";

        cin >> quizAnswers[numQuizzes][i];
    }


    numQuizzes++;
    cout << "Quiz created successfully!\n";
}

// Function to display quizzes with navigation
int displayQuizzes() {
    
    if (numQuizzes == 0) {
        cout << "No quizzes available.\n";
        return -1; // No quizzes to select
    }

    int quizOption = 0; // Starting at the first quiz
    const int numOptions = numQuizzes; // Number of available quizzes

    while (true) {
        cout << "Available quizzes:\n";
        for (int i = 0; i < numOptions; ++i) {
            if (i == quizOption) {
                cout << "> " << quizTitles[i] << " <" << endl; // Highlight current option
            }
            else {
                cout << "  " << quizTitles[i] << endl;
            }
        }

        char choice = _getch();

        // Use switch statement to handle user input
        switch (choice) {
        case 'W':
        case 'w':
            quizOption = (quizOption - 1 + numOptions) % numOptions; // Move up
            break;
        case 'S':
        case 's':
            quizOption = (quizOption + 1) % numOptions; // Move down
            break;
        case 'E':
        case 'e':
            return quizOption; // Return the selected quiz option index
        case 'B':
        case 'b':
            return -1; // Go back to the previous menu
        default:
            break; // Ignore other inputs
        }
    }
}



int main() {

}