#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;
using std::string;
using std::vector;

string allChars[] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","/","-","$","%","&"};
int lenChars = 66;

vector<int> lastInds;
void makePerm(string &lastPerm, int numChars, bool &finished){
	if(lastPerm == ""){
		for(int i = 0; i<numChars; i++){
			lastPerm+=allChars[0];
		}
		return;
	}
	for(int i = 0; i<numChars; i++){
		if(lastPerm[i] != '&'){
			lastPerm[i] = allChars[lastInds[i]][0];
			lastInds[i]++;
			break;
		}
		else{
			lastPerm[i] = '0';
			lastInds[i] = 0;
		}
		if(i == numChars-1){
			finished = true;
			return;
		}
	}
	
}
int main(int argc, char** argv){
/*	ofstream ofs;
	ofs.open("perms.txt", ofstream::out);*/
	string perm = "";
	bool finished = false;
	int param = atoi(argv[1]);
	lastInds.resize(param, 0);
	clock_t t = clock();
	clock_t n;
	while(!finished){
		n = clock();
		makePerm(perm, param, finished);
	}
	cout<<(float)(n-t)/CLOCKS_PER_SEC<<endl;
//	ofs.close();
	return 0;
}