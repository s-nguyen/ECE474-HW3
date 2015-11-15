#include <iostream>
#include <vector>
#include <string>
#include "FileIO.h"
#include "Variable.h"
#include "Operation.h"
#include "Schedule.h"


using namespace std;

int main(int argc, char* argv[])
{
	vector<Variable*> v;
	vector<Operation*> o;
	vector<vector<Operation*>> o_list;
	vector<Schedule*> schedules;
	string s = argv[2];
	if (argc == 4) {
		int latency = stoi(s); //converts the latency to int
		int read = readfile(argv[1], v, o);
		read = checkVar(v, o);
		Operation::seperateOperator(o_list, o);

		if (read == 0) { // No errors
			int check; // = schedules[i]->listR(latency);

			if (check == -1) {
				cout << "Invalid Latency constraint. Try a bigger latency" << endl;
				return -1;
			}	
			
		}
		else if (read == -1) {
			cout << "Could not open file" << endl;
			return -1;
		}
		else if (read == -2) {
			cout << "invalid operator" << endl;
			return -1;
		}
		else if (read == -3) {
			cout << "Unknown operation must be a typo" << endl;
			return -1;
		}
		else if (read == -9) {
			cout << "Missing declariation of variable" << endl;
			return -1;
		}

	}
	else {
		cout << "Usage: ./hlsyn cFile latency verilogFile" << endl;
	}

	return 0;
}