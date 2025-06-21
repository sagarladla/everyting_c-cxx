/**
 * @author	: Sagarvarman Ladla
 * @program	: Batch Gradient Descent
 * @date	: Oct 20 2024
 * @ref		: https://github.com/sagarladla/mini-projects-archived/blob/main/Batch_Gradient_Descent/main.py
 * @writeup	: https://sagarladla.github.io/post/batch-gradient-descent/
 * */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <format>
#include <vector>

#define ld long double

// function prototypes
std::vector< std::pair<ld, ld> > get_dataset(std::string filename);
ld hypothesis(ld c, ld m, ld x);
ld cost(ld c, ld m, std::vector< std::pair<ld, ld> > dataset);
std::pair<ld, ld> gradient_descent(ld c, ld m, std::vector< std::pair<ld, ld> > dataset, ld alpha, size_t epochs);
void metrics(ld c, ld m, std::vector< std::pair<ld, ld> > dataset);
void predict(ld c, ld m);

// main function
int main(int argc, char const *argv[])
{
	ld c = 0;
	ld m = 0;
	ld alpha = 0.0008;
	size_t epochs = 1000;
	std::vector< std::pair<ld, ld> > dataset = get_dataset("data.csv");
	std::pair<ld, ld> model = gradient_descent(c, m, dataset, alpha, epochs);
	c = model.first;
	m = model.second;
	metrics(c, m, dataset);
	predict(c, m);
	return 0;
}

std::vector< std::pair<ld, ld> > get_dataset(std::string filename)
{
	std::string lines;
	std::string buffer;
	std::vector< std::pair<ld, ld> > dataset;
	std::ifstream inp(filename);
	while (getline(inp, lines))
	{
		std::stringstream line(lines);
		std::vector<ld> inpair;
		while (getline(line, buffer, ','))
		{
			inpair.push_back(std::atof(buffer.c_str()));
		}
		dataset.push_back(std::make_pair(inpair[0], inpair[1]));
	}
	inp.close();
	return dataset;
}

ld hypothesis(ld c, ld m, ld x)
{
	// Y = mx + c;
	return (c + (m * x));
}

ld cost(ld c, ld m, std::vector< std::pair<ld, ld> > dataset)
{
	ld total_error = 0;
	ld M = dataset.size();
	ld x;
	ld y;
	for (const std::pair<ld, ld> &point : dataset)
	{
		x = point.first;
		y = point.second;
		total_error += (1 / (2 * M)) * (pow((hypothesis(c, m, x) - y),2));
	}
	return total_error;
}

std::pair<ld, ld> gradient_descent(ld c, ld m, std::vector< std::pair<ld, ld> > dataset, ld alpha, size_t epochs)
{
	ld partial_c = 0;
	ld partial_m = 0;
	ld new_c = c;
	ld new_m = m;
	ld x;
	ld y;
	while (epochs--)
	{
		for (const std::pair<ld, ld> &point : dataset)
		{
			x = point.first;
			y = point.second;
			partial_c += (1 / (ld)(dataset.size())) * (hypothesis(new_c, new_m, x) - y);
			partial_m += (1 / (ld)(dataset.size())) * (hypothesis(new_c, new_m, x) - y) * x;
		}
		new_c = (c - (alpha * partial_c));
		new_m = (m - (alpha * partial_m));
	}
	std::pair<ld, ld> learned_model (new_c, new_m);
	return learned_model;
}

void predict(ld c, ld m)
{
	ld x;
	std::cout << "Enter X value to predict:...";
	std::cin >> x;
	std::cout << "Predicted Y value is:... " << hypothesis(c, m, x) << std::endl;
	return;
}

void metrics(ld c, ld m, std::vector< std::pair<ld, ld> > dataset)
{
	std::cout << std::format("Cost function's weights are: c: {}, m: {}", c, m) << std::endl; 
	std::cout << std::format("Total cost is : {} ", cost(c, m, dataset)) << std::endl;
	return;
}
