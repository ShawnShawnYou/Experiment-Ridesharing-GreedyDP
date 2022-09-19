/**
	\author: Trasier
	\date:	 2019/11/18
*/
#include <bits/stdc++.h>
using namespace std;

#include "util.h"

void pruneGDP() {
	while (pos < n) {
#ifdef WATCH_MEM
		if (pos % 20000 == 0) {
			watchSolutionOnce(getpid(), usedMemory);
		}
#endif  
		if (pos % 2000 == 0) {
			t3 = clock();
			if (t3-t2 > clockLimit) {
				dumpResult("pruneGDP");			
				return ;
			}
		}
		
		for (int i = 0; i < m; ++ i) {
			updateDriver(i, R[pos].tim);
		}

		tsd = clock();
		vector<int> car;
		if (R[pos].len < INF_WEIGHT) {
			car = single_search(R[pos].s, R[pos].ddl - R[pos].tim);
		}
		
		double fit;

		////pre processing
		vector <pair <double, int> > valued_car;
		for (int i = 0; i < car.size(); ++ i) {
			fit = INF;
			try_insertion_euclid(W[car[i]], pos, fit);
			if (fit < INF)
				valued_car.push_back(make_pair(fit, car[i]));
		}
		sort(valued_car.begin(), valued_car.end());
		
		////assign the request to some taxi
		assignTaxi(valued_car);
	}
	
	for (int i = 0; i < m; ++ i) {
		finishTaxi(i);
	}
	t3 = clock();
	dumpResult("pruneGDP");
}

int main(int argc, char **args) {
    string directory = "E:/workspace/A-Experiment-dataset/pruneGDP_data";
    string root = directory + "/data/chengdu/chengdu";
    vertexFile = root + ".node";
    edgeFile = root + ".edge";
    pathLabelFile = root + ".label";
    orderFile = root + ".order";
    dataFile = root + "_taxi.txt";
    requestFile = root + "_order.txt";
    //	desFile = root + "_res.txt";
    //	freopen(desFile.c_str(), "w", stdout);


	readInput();
	
	t1 = clock();
	initGrid();
	t2 = clock();
	
	pruneGDP();
	freeMemory();
	fflush(stdout);

	return 0;
}
