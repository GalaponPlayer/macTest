#include "graph.h"

#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>

//changed?
using namespace std;

Graph::Graph(const string& file_name)
{
	ifstream ifs(file_name);
	cout << "nandeya" << endl

	if (!ifs)
	{
		cerr << "Open file faild" <<endl;
	}

/*	istringstream ss;

	string num_city, buff;
	getline(ifs, num_city);
	ss = istringstream(num_cit);
	ss >> num_of_city;

	for (int i = 0; i < num_of_city; ++i)
	{
		getline(ifs, buff);

	}
*/
	istream_iterator<double> it(ifs);
	istream_iterator<double> end;

	auto n = *it;
	num_of_city = (int)n;
	++it;



	for (int i = 0; i < num_of_city; ++i)
	{
		verts.push_back(pair<double,double>());
		verts[i].first = *it;
		++it;
		verts[i].second = *it;
		++it;
	}

	for (int i = 0; i < num_of_city; ++i)
	{
		graph.push_back(std::vector<double>());
		for (int j = 0; j < num_of_city; ++j)
		{
			double dt = (verts[i].first - verts[j].first)*(verts[i].first - verts[j].first) + (verts[i].second - verts[j].second)*(verts[i].second - verts[j].second);
			graph[i].push_back(dt);
		}
	}
}

double Graph::dist(int x, int y)
{
	if ((x < 0) || (x >= graph.size()))
	{
		throw out_of_range("x is invalid number");
	}

	if ((y < 0) || (y >= graph.size()))
	{
		throw out_of_range("y is invalid number");
	}

	double distance = graph[x][y];
	return distance;
}


double Graph::path_dist(const std::vector<int> path)
{
	int size = path.size();
	double path_distance = 0.0;

	try
	{
		for (int i = 0; i < (size - 1); ++i)
		{
			path_distance += dist(path[i], path[i + 1]);
		}

		path_distance += dist(path[size - 1], path[0]);

	}

	catch(exception& e)
	{
		cerr <<"Exception throwed in Graph::path_dist()" << endl;
		exit(0);
	}

	return path_distance;
}

int Graph::num_of_v()
{
	return num_of_city;
}

void Graph::show_verts(int n)
{
	cout << n << ": " << verts[n].first << "," << verts[n].second << endl;
}