#include <bits/stdc++.h>
using namespace std;
const int M=1010;
int a[M];

//test for sample problem: sorting an array
void generate_test(ofstream &fin, ofstream &fout){
	int n= rand()%1000;
	for(int i=0;i<n;i++)
		a[i]= rand()%5000;
	
	fin<<n<<"\n";
	for(int i=0;i<n;i++){
		fin<<a[i]<<" \n"[i==(n-1)];
	}
	
	sort(a,a+n);
	for(int i=0;i<n;i++){
		fout<<a[i]<<" \n"[i==(n-1)];
	}
}

void write_test(int testnum){
	string num= to_string(testnum), in,out;
	
	in= "testcases/in/input"+num+".txt";
	out= "testcases/out/output"+num+".txt";
	ofstream fin(in);
	ofstream fout(out);
	
	generate_test(fin,fout);
	fin.close();
	fout.close();
}

int main(){
	srand(time(0));
	
	int testnum= 0;
	while(testnum<50){
		testnum++;
		write_test(testnum);
		cout<<"done generating test "<<testnum<<endl;
	}
}
