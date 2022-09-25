#include <bits/stdc++.h>
using namespace std;
const int M=1010;
typedef long long ll;
typedef pair<ll,ll> pii;

int a[M];

random_device rd;
mt19937 rng(rd());
int rand_range(int l, int r){
	uniform_int_distribution<int> dis(l, r);
	return dis(rng);
}
int rand_range(ll l, ll r){
	uniform_int_distribution<ll> dis(l, r);
	return dis(rng);
}

//n_range is range for n, and x_range is range for a[i]
vector<ll> rand_arr(pii n_range, pii x_range){
	ll n= rand_range(n_range.first, n_range.second);
	vector<ll> v(n);
	for(int i=0;i<n;i++)
		v[i]= rand_range(x_range.first, x_range.second);
	
	return v;
}

vector<ll> rand_permutation(pii n_range){
	ll n= rand_range(n_range.first, n_range.second);
	vector<ll> v(n);
	iota(v.begin(), v.end(), 1);
	shuffle(v.begin(), v.end(), rng);
	return v;
}

//random 2d-array
vector<vector<ll>> rand_mat(pii n_range, pii m_range, pii x){
	ll n= rand_range(n_range.first, n_range.second);
	ll m= rand_range(m_range.first, m_range.second);

	vector<vector<ll>> v(m);
	for(int i=0;i<n;i++){
		v[i]= vector<ll>(n);
		for(int j=0;j<m;j++)
			v[i][j]= rand_range(x.first, x.second);
	}
	
	return v;
}

//test for sample problem: sorting an array
void generate_test(ofstream &fin, ofstream &fout){
	int n= rand_range(1,1000);
	for(int i=0;i<n;i++)
		a[i]= rand_range(1,5000);
	
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
