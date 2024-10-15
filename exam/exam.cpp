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
