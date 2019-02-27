#include<cstring>
#include<map>
#include<sstream>
#include<string>
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

typedef enum {plus,minus,multiple,divide,eos,lparen,rparen,modulus,operand}Operator;
int isp[8]={12,12,13,13,0,19,0,13};
int icp[8]={12,12,13,13,0,19,20,13};

void Convert(string);
Operator Precedence(char);
void push(Operator);
string printtoken(Operator);
Operator pop();

vector<string>Stringtemp;
Operator Stack[100];
int Stack_Index=0;
int main (){
	string expression,temp1,temp2;
	vector<string>Result;
	getline(cin,expression);
	Convert(expression);
	int Length=Stringtemp.size();
	Length--;
	push(eos);
	Operator token;
	while(Length>=0){
		token=Precedence(Stringtemp.at(Length).at(0));
		if(token==operand){
			Result.push_back(Stringtemp.at(Length));
		}
		else if(token==lparen){
			while(Stack[Stack_Index-1]!=rparen){
				Result.push_back(printtoken(pop()));}
			pop();}
		else {
			while(icp[token]<isp[Stack[Stack_Index-1]]){
				Result.push_back(printtoken(pop()));}
			push(token);}
		Length--;
	}
	for (int i=Stack_Index-1;i>0;i--){
		Result.push_back(printtoken(pop()));
	}
	for ( int i=Result.size()-1;i>=0;i--){
		cout<<Result.at(i);
	}
	cout<<endl;
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
		case'(':
			return lparen;
		case ')':
			return rparen;
		case '%':
			return Operator::modulus;
		default:
			return operand;
}
}

void push(Operator x){
	Stack[Stack_Index++]=x;
}

Operator pop(){
	return Stack[--Stack_Index];}

string printtoken(Operator o){
	switch (o){
		case 0:
			return "+";
			break;
		case 1:
			return "-";
			break;
		case 2:
			return "*";
			break;
		case 3:
			return "/";
			break;
		case 4:
			return "eos ";
			break;
		case 7:
			return "%";
			break;
	}
}
