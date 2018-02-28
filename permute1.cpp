#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <thread>

using namespace std;
using std::string;
using std::vector;

int param;
ofstream ofs;
const string firstHalf[] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","/","-","$","%","&"};
const int len1 = 66;

vector<int> lastInds;
vector<int> backInds;

void makePerm(string &lastPerm, bool &finished){
	int numChars = param;
	if(lastPerm == ""){
		for(int i = 0; i<numChars; i++){
			lastPerm+=firstHalf[0];
		}
		return;
	}
	bool maybeDone = true;
	for(int i = numChars-1; i>0; i--){
		if(lastPerm[i] != '&'){
			maybeDone = false;
			break;
		}
	}
	if(maybeDone && lastPerm[0] == 'w'){
		finished = true;
		return;
	}
	for(int i = 0; i<numChars; i++){
		if(lastPerm[i] != '&'){
			lastPerm[i] = firstHalf[lastInds[i]][0];
			lastInds[i]++;
			break;
		}
		else{
			lastPerm[i] = '0';
			lastInds[i] = 0;
		}
	}
	
}

void makeBack(string &lastPerm, bool &finished){
	int numChars=param;
	if(lastPerm == ""){
		for(int i = 0; i<numChars; i++){
			lastPerm+=firstHalf[65];
		}
		return;
	}
	bool maybeDone = true;
	for(int i = 0; i<numChars; i++){
		if(lastPerm[i] != 'x'){
			maybeDone = false;
			break;
		}
	}
	if(maybeDone){
		finished = true;
		return;
	}
	for(int i = 0; i<numChars; i++){
		if(lastPerm[i] != '0'){
			lastPerm[i] = firstHalf[backInds[i]][0];
			backInds[i]--;
			break;
		}
		else{
			lastPerm[i] = '&';
			backInds[i] = 65;
		}
	}
	
}

void runIt(bool first){
	string perm = "";
	bool fin = false;
	if(first){
		while(!fin){
			makePerm(perm, fin);
			ofs<<perm<<endl;
		}
	}
	else{
		while(!fin){
			makeBack(perm, fin);
			ofs<<perm<<endl;
		}
	}
}

int main(int argc, char** argv){
	ofs.open("perms1.txt", ofstream::out);
	param = atoi(argv[1]);
	lastInds.resize(param, 0);
	backInds.resize(param, 65);
	
	clock_t t = clock();
	clock_t n;

	thread t1(runIt, true);
	thread t2(runIt, false);
	t1.join();
	t2.join();
	ofs.close();
	n=clock();
	cout<<(float)(n-t)/CLOCKS_PER_SEC<<endl;
	return 0;
}