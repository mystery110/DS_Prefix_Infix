EVAL.CPP
--Enumeration is used for operator + - * and /. This allow the comparision for switch case become more easier . The enumeration is named as Operator .

--Convert is a function that 
  a)Splitting string entered by user using space
  b)After splitting , use a vector to store the result.
  A global vector<string>Stringtemp is declare to store the result.

--Precedence is a function that compare the character using switch case .
  Each case will return a different Operator .

--push and pop function is for stack 

--The expression entered by user is stored in variable expression(string).
  It is later passing to the function Convert .
  After this, the Stringtemp should have the result of the string sperated using space.

--Length(int) is declared and used to store the number of element within Stringtemp.
  It is later used as a condition for the while loop.

--Since we need to scan the expression from right to left , we start comparing from Stringtemp[Length],which is at the end of the vector.Each time when it finish comparing , Length-- . Therefore the condition for staying within the while loop is when Length >=0.

--For C/C++ , switch can only compare a character by not whole string , thefore , everytime Precedence is called , only the first character of the string in Stringtemp is passed as an argument .

--If it is an operand , it is converted into integer and pushto the  stack.

--If it is am operator , two number is pop from the stack to carry out the operation . The result is then push to the  stack

--After exiting the while loop , the final answer is the pop from the stack .

PREFIX.CPP
--Most of the variable declare has the same usage 

--printtoken function will return string of the operator .Example ,of the operator is + ,then "+" is returned . This allow me to used a vector<string> to stored them.

--isp and icp array is declare to recored the precedence for every operator .
  isp stand for in stack precedence while icp stand for in coming precedence.
  The reason for having isp and icp seperately is because left parenthesis and right parenthesis have different precedence when it is in stack or is an in coming operator .

--The function pop() will return an Operator instead of integer.

--Same procedure in the while loop .A vecotor<string>Result is declare to store the final answer .I still start comparing the expression at the end of the Stringtemp(scanning from right to left ).By doing this , left parenthesis will now become right parenthesis and vice versa.

--If the incoming token is an operand , it is pushback in to the vector directly 

--If it is a operator 
  a)If it is not a left parenthesie , the precedence of the in coming oeprator is compare to the precedence of the operator at the top of the stack .
    -)If both of them have the same precedence , the in coming operator is the push to the stack (because most of the operator has left to right associative,no popo is required).
	-)If the in coming operator has higher precedence , it is push to the stack .
	-)If the in coming operator has lower precedence , pop is called and the returned Operatoris passed to the fucntion printtoken.The string returned by printtoken is pushback to the Result .The comparison start again until the operator at the top of the stack has the same of lower precedence.

  b)If it is a left parenthesis (again, because i scan the expression from right to left , right parenthesis become left parenthesis)
  -)all the oeprator in the stack is pop until it meet the right parenthesis.

--After the while loop , what is remaining in the stack is pushback to Result

--The final answer is the reverse order of Result .




