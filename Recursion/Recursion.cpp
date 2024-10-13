#include <iostream>
#include <string>
#include <stack>

using namespace std;

string verification_rules(char bracket, stack<char>& stack_sentence) {
	char opposite_bracket = (bracket == '(') ? ')' : (bracket == '[') ? ']' : (bracket == '{') ? '}' : ')';
	short parentheses = 0, curly_brackets = 0, square_brackets = 0;
	short closing_parentheses = 0, closing_curly_brackets = 0, closing_square_brackets = 0;

	while (!stack_sentence.empty()) {
		if (stack_sentence.top() == '(') {
			parentheses++;
		}
		else if (stack_sentence.top() == '[') {
			square_brackets++;
		}
		else if (stack_sentence.top() == '{') {
			curly_brackets++;
		}
		if (stack_sentence.top() == ')') {
			closing_parentheses++;
		}
		else if (stack_sentence.top() == ']') {
			closing_square_brackets++;
		}
		else if (stack_sentence.top() == '}') {
			closing_curly_brackets++;
		}
		stack_sentence.pop();
	}
	if (parentheses == closing_parentheses && square_brackets == closing_square_brackets && curly_brackets == closing_curly_brackets) {
		return "Row adhere the rules! \n\033[32mIt's correct sentence!\033[0m";
	}
	else {
		return "Row doesn't adhere the rulse! \n\033[31mIt's not correct sentence!\033[0m";
	}


	//char opposite_bracket = (bracket == '(') ? ')' : (bracket == '[') ? ']' : (bracket == '{') ? '}' : ')';

	//while (!stack_sentence.empty()) {
	//	if ((stack_sentence.top() == '(' || stack_sentence.top() == '[' || stack_sentence.top() == '{') && stack_sentence.top() != bracket) {

	//		char new_bracket = stack_sentence.top();
	//		stack_sentence.pop();
	//		verification_rules(new_bracket, stack_sentence);
	//	}
	//	else if (stack_sentence.top() == opposite_bracket) {
	//		stack_sentence.pop();
	//	}
	// /* If come up with condition a bit better ir recursia will be work.  
	// I just don't come up with how to check is correct the sentence or isn't correct*/
	//	else if (stack_sentence.top() == bracket) { <------ this condition
	//		return "Row doesn't adhere the rules";
	//	}
	//	else {
	//		stack_sentence.pop();
	//	}
	//}
	
}


template<class T1, class T2>
T2 dissassembly(T1 sentence) {
	stack<char> stack_buffer, result_stack;
	char first_bracket;
	bool first_bracket_are = false;

	for (auto sym : sentence) {

		stack_buffer.push(sym);

		if (sym == '(' || sym == '[' || sym == '{' && first_bracket_are == false) {

			first_bracket = sym;
			first_bracket_are = true;
		}
	}
	while (!stack_buffer.empty()) {
		result_stack.push(stack_buffer.top());
		stack_buffer.pop();
	}
	

	return verification_rules(first_bracket, result_stack);
}

template<>
string dissassembly(char* sentence) {
	stack<char> stack_sentence;
	char first_bracket;
	bool first_bracket_are = false;

	for (int i = 0; *(sentence + i) != '\0'; i++) {

		char sym = sentence[i];
		stack_sentence.push(sym);

		if (sym == '(' || sym == '[' || sym == '{' && first_bracket_are == false) {

			first_bracket = sym;
			first_bracket_are = true;
		}
	}
	
	return verification_rules(first_bracket, stack_sentence);
}



int main(){
	string sentence;

	cout << "Write the sentence with brackets: \n";
	getline(cin, sentence);

	string result = dissassembly<string, string>(sentence);

	cout << result;
	return 0;

}
