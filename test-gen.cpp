#include <bits/stdc++.h>
#include <dir.h>
using namespace std;
const int M=1010;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

int a[M];

random_device rd;
mt19937_64 rng(rd());
int rand_range(int l, int r){
	uniform_int_distribution<int> dis(l, r);
	return dis(rng);
}

ll rand_range(ll l, ll r){
	uniform_int_distribution<ll> dis(l, r);
	return dis(rng);
}

ld rand_range(ld l, ld r){
	uniform_real_distribution<ld> dis(l,r);
	return dis(rng);
}

string rand_str(pii size_range, string alphabet= ""){
	int size= rand_range(size_range.first, size_range.second);
	if(alphabet == ""){
		for(int i=0;i<26;i++)
			alphabet += (char)('a'+i);
		for(int i=0;i<26;i++)
			alphabet += (char)('A'+i);
		for(int i=0;i<10;i++)
			alphabet += (char)('0'+i);
	}

	string ret = "";
	for(int i=0;i<size;i++)
		ret += alphabet[rand_range(0, alphabet.size())];
	return ret;
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

struct Edge{
	int from, to;
	ll w;
};

struct Graph{
	int n;
	vector<Edge> edges;
	vector<ll> labels; //label for each vertex
	void print(ofstream &output, bool do_shuffle = true, bool weighted = false, bool print_labels = false){
		vector<Edge> ans(edges.begin(), edges.end());
		if(do_shuffle)
			shuffle(ans.begin(), ans.end(), rng);
		
		output<<n<<" "<<ans.size();
		if(print_labels){
			output<<"\n";
			for(ll u:labels)
				output<<u<<" ";
		}

		for(Edge u:ans){
			output<<"\n"<<u.from<<" "<<u.to;
			if(weighted)
				output<<" "<<u.w;
		}
		if(ans.size() == 0)
			output<<"\n";
	}

	bool add_edge(int v, int u, int w=0, bool bidirectional = false){
		if(v < 1 || v > n || u < 1 || u > n)
			return false;
		
		edges.push_back({v, u, w});
		if(bidirectional)
			edges.push_back({u, v, w});
		
		return true;
	}

	//TODO: add_edge if unique	
};

//random directed acyclic graph, each edge will be in the graph with probability of p
Graph rand_dag(int n, ld p){
	Graph g;
	g.n= n;
	auto topo = rand_permutation({n,n});

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(rand_range((ld)0.0, (ld)1.0) <= p)
				g.add_edge(topo[i]-1, topo[j]-1);
		}
	}
	return g;
}

//full binary tree with the specified height and labels
Graph create_full_binary_tree(int height, vector<ll> labels){
	Graph g;
	g.n= (1<<(height+1))-1;
	if(g.n != labels.size()){
		g.n=0;
		return g;
	}
	g.labels = labels;
	sort(labels.begin(), labels.end());

	for(int i=1;i<(1<<height);i++){
		g.add_edge(i,2*i);
		g.add_edge(i,2*i+1);
	}
	return g;
}

//random tree, parent of node i can be each of 1...(i-1) with equal probability
//it may have some properties based on creating random trees, for example, its height be less than expected
//TODO: shuffle vertices
Graph rand_tree(int n, bool swap_rand = false){
	Graph g;
	g.n = n;
	for(int i=2;i<=n;i++){
		int par = rand_range(1,i-1);
		if(!swap_rand)
			g.add_edge(par, i);
		else{
			if(rand_range(0,1)==0)
				g.add_edge(par, i);
			else
				g.add_edge(i,par);
		}
	}
	return g;
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

void create_dir(){
	mkdir("testcases");
	mkdir("testcases/in");
	mkdir("testcases/out");
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
	
	create_dir();
	int testnum= 0;
	while(testnum<50){
		testnum++;
		write_test(testnum);
		cout<<"done generating test "<<testnum<<endl;
	}
}
