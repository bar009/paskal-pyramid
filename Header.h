#pragma once
#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Pyramiad
{
public:
	void makeRows();
	void startPyramid();
	void makeNumbers();
	void print();

private:
	vector<vector<int> > _rows;
};