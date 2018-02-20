#include <iostream>
#include <cstring>

int FindFunctionDefn(const char* strFunctionName, const char* strSourceCode) {
	
	int l = strlen(strFunctionName);
	
	int i, j;

	for (i = 0, j = 0; strFunctionName[j] != '\0' && strSourceCode[i] != '\0'; i++) {
	
		if(strFunctionName[j] == strSourceCode[i]) {
			j++;
		}
		else {
			j = 0;
		}
	}

	int indx = 0;

	if(j == l) {
		
		indx = i - j + 1;
	}
		
	int line = 0;
	
	

	if(indx > 0) {
		
		char temp[] = "\\n";

		int l2 = strlen(temp);

		int k, m;
		
		for(k = 0, m = 0; k <= indx; k++) {
			
			if(strSourceCode[k] == temp[m] && temp[m] != '\0') {
				
				m++;
					
			}
			else {
				if(temp[m] == '\0'){
				line++;
				m = 0;	
				}

			}

		}		
	
	}	

	if(line != 0) line++;

	return line;

}

int main() {
	
	char strFunctionName[] = "func2";

	char strSourceCode[] = "int func1(){ return \\n 0; \\n }\\n int func2(){ return 1; }\\n int main(int argc, char*argv[]){ return func2(); }\\n"; 
	

	int val = FindFunctionDefn(strFunctionName, strSourceCode);

	std::cout << val << std::endl;
	
	return 0;
}
