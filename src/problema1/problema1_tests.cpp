#include "gtest/gtest.h"
#include "problema1.h"

using namespace std;

TEST(problema1, CostoMinimo) {
	int cantTareas = 3;
	vector<vector<int> > tablaCostos;
	/*
	1
	2 4
	3 5 6
	*/
	tablaCostos[0].push_back(1);
	tablaCostos[1].push_back(2);
	tablaCostos[1].push_back(4);
	tablaCostos[2].push_back(3);
	tablaCostos[2].push_back(5);
	tablaCostos[2].push_back(6);
	
	pair<int, vector<int> > res = problema1(cantTareas, tablaCostos);

	EXPECT_EQ(8, get<0>(res));
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
