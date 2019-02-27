#include<iostream>
#include<cstring>
#include<map>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

typedef enum {plus,minus,multiple,divide,operand}Operator;

void Convert(string);
Operator Precedence(char);
void push(int);
int pop();
vector<string>Stringtemp;
int Stack[100],Stack_Index=0;
int main (){
	string expression;
	getline(cin,expression);
	Convert(expression);
	int Length=Stringtemp.size();
	Length--;
	Operator token;
	while(Length>=0){
		token=Precedence(Stringtemp.at(Length).at(0));
		if(token==operand){
			int x=stoi(Stringtemp.at(Length));
			push(x);}
		else {
			switch(token){
				case Operator::plus:{
					int op1=pop();
					int op2=pop();
					push(op1+op2);
					break;}
				case Operator::minus:{
					int op1=pop();
					int op2=pop();
					push(op1-op2);
					break;}
				case multiple:{
					int op1=pop();
					int op2=pop();
					push(op1*op2);
					break;}
				case divide:{
					int op1=pop();
					int op2=pop();
					push(op1/op2);
					break;}
			}}
		Length--;
	}
	cout<<"The Answer is "<<pop()<<endl;
}

void Convert(string expression){
	stringstream split(expression);
	string sss;
	const char token=' ';
	while(getline(split,sss,token)){
		Stringtemp.push_back(sss);//seperating string
			}
	}

Operator Precedence(char Result){
	switch(Result){
		case'+':
			return Operator::plus;
		case'-':
			return Operator::minus;
		case'*':
			return multiple;
		case'/':
			return divide;
		default:
			return operand;
}
}

void push(int x){
	Stack[Stack_Index++]=x;
}

int pop(){
	return Stack[--Stack_Index];}
