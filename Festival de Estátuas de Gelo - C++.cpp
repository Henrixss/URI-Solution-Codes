#include<iostream>
#include<vector>
#include<climits>

#define lli long long int
#define INF INT_MAX

using namespace std;

lli num_blocos(lli M, lli N, vector<lli>& blocos) {
    lli solucoes[M+1];

    solucoes[0] = 0;

    for(lli i=1; i<=M; i++) {

        solucoes[i] = INF;

        for(lli j=0; j<N; j++) {
            if(i-blocos[j] >= 0) {
                solucoes[i] = min(solucoes[i], solucoes[ i-blocos[j] ]+1);
            }
        }
    }

    return solucoes[M];
}

int main(){
	
	lli T, N, M;
	vector<lli> vetor_a(26, 0);
	cin>>T;
	
	while(T--){
		cin>>N>>M;
		vetor_a.clear();
		for(lli i = 0; i<N; i++){
			cin>>vetor_a[i];
		}
		
		cout<<num_blocos(M, N, vetor_a)<<endl;
		
	}
	
	return 0;
}