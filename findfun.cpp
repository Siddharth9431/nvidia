#include <iostream>
#include <cstring>

int FindFunctionDefn(const char* strFunctionName, const char* strSourceCode) {
	
	char* pntl;
	const char* pnts = strSourceCode;
	
	const char nl[] = "\\n";

	pnts = std::strstr(strSourceCode, strFunctionName);
	
	int line = 0;

	if(pnts != NULL) {

		int len = pnts - strSourceCode;

		std::strncpy(pntl, strSourceCode, len);
		
		const char* pntx = pntl;

		while((pntx = std::strstr(pntx, nl)) != NULL) {
			line++;
			if(*pntx != '\0') ++pntx; 
		}	
	}

	return line + 1;
}


int main() {
	
	char strFunctionName[] = "func2";

	char strSourceCode[] = "int func1(){ return \\n 0; \\n }\\n int func2(){ return 1; }\\n int main(int argc, char*argv[]){ return func2(); }\\n"; 

	int val = FindFunctionDefn(strFunctionName, strSourceCode);

	std::cout << val << std::endl;

}
