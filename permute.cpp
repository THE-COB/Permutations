#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;
using std::string;
using std::vector;

string allChars[] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","/","-","$","%","&"};
// lenChars = 66;

vector<int> lastInds;
void makePerm(string &lastPerm, int numChars, bool &finished){
	for(int i = 0; i<numChars; i++){
		if(lastInds[i] != 66){
			lastInds[i]++;
			lastPerm[i] = allChars[lastInds[i]][0];
			break;
		}
		else if(i != numChars-1){
			lastPerm[i] = '0';
			lastInds[i] = 0;
		}
		else{
			finished = true;
			return;
		}
	}
	
}
int main(int argc, char** argv){
	ofstream ofs;
	string perm = "";
	bool finished = false;
	int param = atoi(argv[1]);
	for(int i = 0; i<param; i++){
		perm+=allChars[0];
	}
	string fullStr = perm+"\n";
	lastInds.resize(param, 0);
	clock_t t = clock();
	clock_t n;
	while(!finished){
		n = clock();
		makePerm(perm, param, finished);
		fullStr+=perm+"\n";
	}
	string fName = "perms";
	fName+=argv[1];
	fName+=".txt";
	ofs.open(fName, ofstream::out);
	ofs<<fullStr;
	ofs.close();
	ofs.open("timelog.txt", ofstream::out);
	ofs<<(float)(n-t)/CLOCKS_PER_SEC<<" "<<argv[1]<<endl;
	ofs.close();
	return 0;
}