//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include<queue>
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

class Question{
public:
		char* Text;
		char* Answer1;
		char* Answer2;
		char* Answer3;
		int correctans;

		Question(){}   //defaultconstructor
		Question(char* text, char* ans1, char* ans2, char* ans3, int crtans){ //customconstructor
			Text = text;
			Answer1 = ans1;
			Answer2 = ans2;
			Answer3 = ans3;
			correctans = crtans;
		}

};

std :: queue<Question> LoadQuestion(){
	Question q1=Question("The day on which the Sun’s direct rays cross the celestial equator is called:", "the equinox","the ecliptic", "the solstice",1);
	Question q2=Question("Who invented the telescope?", "Galileo", "Johannes Kepler", "Hans Lippershey",3);
	Question q3=Question("What is the visible part of the Sun called?", "the photosphere", "the stratosphere", "the atmosphere", 1);
	Question q4=Question("What makes a planet a dwarf planet?", "size and shape", "distance from the Sun", "Mass", 1);
	Question q5=Question("Approximately how many miles (or kilometres) are there in a light-year?", "5.9 trillion (9.5 trillion km)", "5.9 million (9.5 million km)", "5.9 billion (9.5 billion km)",1);

	std::queue<Question> question;
	question.push(q1);
	question.push(q2);
	question.push(q3);
	question.push(q4);
	question.push(q5);
	return question;
}

std::queue<Question> question;
Question currentQuestion;
int selectedAnswer;
int points=0;


TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
    question=LoadQuestion();
	currentQuestion=question.front();

	QuestionLabel -> Text= currentQuestion.Text;
	Answer1RadioButton->Text= currentQuestion.Answer1;
	Answer2RadioButton->Text= currentQuestion.Answer2;
	Answer3RadioButton->Text= currentQuestion.Answer3;

	question.pop();
	PointsLabel->Text=points;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Answer1RadioButtonChange(TObject *Sender)
{
    selectedAnswer=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Answer2RadioButtonChange(TObject *Sender)
{
	selectedAnswer=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Answer3RadioButtonChange(TObject *Sender)
{
	selectedAnswer=3;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ConfirmButtonClick(TObject *Sender)
{
    if(selectedAnswer==currentQuestion.correctans){
		points++;
		PointsLabel->Text=points;
	}

	if(!question.empty()) {
		currentQuestion=question.front();

			QuestionLabel -> Text= currentQuestion.Text;
			Answer1RadioButton->Text= currentQuestion.Answer1;
			Answer2RadioButton->Text= currentQuestion.Answer2;
			Answer3RadioButton->Text= currentQuestion.Answer3;

			question.pop();
			Answer1RadioButton->IsChecked=false;
			Answer2RadioButton->IsChecked=false;
			Answer3RadioButton->IsChecked=false;
	}
	else{
		ConfirmButton->Enabled=false;
		ConfirmButton->Text="THE END!";
	}

}
//---------------------------------------------------------------------------
