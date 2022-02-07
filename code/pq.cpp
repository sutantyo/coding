#include<bits/stdc++.h>
using namespace std;

struct job{
	string id;
	int q_time;
	int p_time;

	bool operator< (const job& b) const{
		return p_time > b.p_time;
	}

	job(string id, int q, int p) : id(id), q_time(q), p_time(p) {};
};

int main(int argc, char* argv[]){

	vector<job> input;
	input.push_back(job("id0",3,10));
	input.push_back(job("id1",3,2));
	input.push_back(job("id2",5,3));
	input.push_back(job("id3",5,8));
	input.push_back(job("id4",5,1));
	input.push_back(job("id5",100,7));
	input.push_back(job("id6",100,3));

	sort(input.begin(),input.end(),[](job a, job b){
		return a.q_time < b.q_time;
	});

	/*
	auto comp = [](job a, job b){return a.p_time > b.p_time;};
	priority_queue<job,vector<job>,decltype(comp)> pq(comp);
	*/
	priority_queue<job> pq;

	int index = 0;
	int time = 0;
	
	do {
		if (pq.empty() && index < input.size()){
			time = input[index].q_time;
		}
		while(index < input.size() && input[index].q_time <= time){
			pq.push(input[index]);
			index++;
		}
		if (!pq.empty()){
			time = time + pq.top().p_time;
			pq.pop();
		}
	} while(!pq.empty() || (index < input.size()));

}


