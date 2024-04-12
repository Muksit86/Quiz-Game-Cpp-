#include<iostream>
#include<conio.h>
#include<windows.h>

struct Student{
    char name[20];
    int marks;
};

class Quiz
{
public:
    //GK
    std::string gkQuestions[20] = {"1) What is the capital city of France?",
                                "2) Which planet is known as the Red Planet?",
                                "3) Who painted the Mona Lisa?",
                                "4) What is the chemical symbol for water?",
                                "5) Which of the following is the largest ocean on Earth?"};
    std::string gkOptions[20] = {"a) London b) Paris c) Rome d) Berlin",
                                "a) Venus b) Mars c) Jupiter d) Saturn",
                                "a) Leonardo da Vinci b) Pablo Picasso c) Vincent van Gogh d) Michelangelo",
                                "a) NaCl b) H2O c) CO2 d) O2",
                                "a) Atlantic Ocean b) Indian Ocean c) Pacific Ocean d) Arctic Ocean"};
    char gkAnswers[20] = {'b', 'b', 'a', 'b', 'c'};

    //Coding
    std::string codeQuestions[20] = {"1) Which of the following is not a programming language?",
                                "2) What does HTML stand for?",
                                "3) Which symbol is used for single-line comments in many programming languages?",
                                "4) What does CSS stand for?",
                                "5) What is the output of 5 + \"3\" in JavaScript?"};
    std::string codeOptions[20] = {"a) Python b) HTML c) JAVA d) C++",
                                "a) Hyper Text Markup Language b) High-Level Text Management Language c) Hyperlink and Text Markup Language d) Home Tool Markup Language",
                                "a) /* b) // c) ! d) $",
                                "a) Computer Style Sheets b) Creative Style Sheets c) Cascading Style Sheets d) Colorful Style Sheets",
                                "a) 53 b) 8 c) 8 d) Error"};
    char codeAnswers[20] = {'b', 'b', 'a', 'b', 'c'};

    //Movie
    std::string movieQuestions[20] = {"1) Who directed Apocalypse Now?",
                                "2) When did the first Kill Bill release",
                                "3) Who played park owner John Hammond in Jurassic Park?",
                                "4) Who voiced Miss Mitune in Loki?",
                                "5) Who played Black Panther in Marvel?"};
    std::string movieOptions[20] = {"a) Francis Ford Coppola b) Joe Russo c) Martin Scorsese d) Quentin Tarantino",
                                "a) 12 October 2002 b) 10 October 2003 c) 10 November 2002 d) 10 September 2003",
                                "a) Richard Attenborough b) Robert downey Jr c) Javier Bardem d) Christopher Walken",
                                "a) Mark Hamill b) Billy West c) Grey DeLisle d) Tara Strong",
                                "a) Samuel L. Jackson b) Daniel Kaluuya c) Chadwick Boseman d) Michael B. Jordan"};                            
    char movieAnswers[20] = {'a', 'b', 'a', 'd', 'c'};

    void displayQuestionAndOption(std::string question[], std::string option[], int size, char Answer[], Student& s1){
    s1.marks = 0;
    int i;
    char userInput;
    for(i=0; i<size; i++){
            std::cout<<"\n"<<question[i];
            std::cout<<"\n"<<option[i];
            userInput = getch();

            if(Answer[i] == userInput){
                s1.marks++;
            }else{
                std::cout<<"The Answer: "<<Answer[i];
            }
        }
    }

    void resultDisplay(Student& s2){
        std::cout<< "Your result is "<<s2.marks<<" Out of 5";
    }

};

char options;

int main(){
    Student st;
    Quiz quiz;
    char choice;
    char difficultyLevel;
    st.marks = 0;
    do{
        char userSubjectChoice;
        std::cout<<"\n\t\t****QUIZ GAME****";
        std::cout<<"\n\t\t****FOR ALL****";
        std::cout<<"\nEnter your name: ";
        gets(st.name);
        system("CLS");
        std::cout<<"1) GK";
        std::cout<<"\n2) CODING";
        std::cout<<"\n3) MOVIE";
        std::cout<<"\nChoose your subject: ";
        userSubjectChoice = getch();
        switch (userSubjectChoice)
        {
        case '1':
            std::cout<<"GK...";
            quiz.displayQuestionAndOption(quiz.gkQuestions, quiz.gkOptions, 5, quiz.gkAnswers, st);
            break;
        case '2':
            std::cout<<"CODING...";
            quiz.displayQuestionAndOption(quiz.codeQuestions, quiz.codeOptions, 5, quiz.codeAnswers, st);
            break;
        case '3':
            std::cout<<"MOVIE...";
            quiz.displayQuestionAndOption(quiz.movieQuestions, quiz.movieOptions, 5, quiz.movieAnswers, st);
            break;
        default:
            std::cout<<"\nInvalid Input...";
            break;
        }

        quiz.resultDisplay(st);
        std::cout<< "\n"<< st.name <<" Do you want to continue (Y/N): ";
        choice = getch();
        system("CLS");
    }while(choice == 'Y' || choice == 'y');
}