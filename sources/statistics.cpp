#include "../statistics.h"
#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
#pragma once

void Min::update(double next) {
	if (next < m_min) {
		m_min = next;
	}
}

double Min::eval() const {
	return m_min;
}

const char* Min::name() const {
	return "min";
}

void Max::update(double next) {
	if (next > m_max) {
		m_max = next;
	}
}

double Max::eval() const {
	return m_max;
}

const char* Max::name() const {
	return "max";
}

void Mean::update(double next) {

	sum += next;
	count++;
	m_mean = sum/count;
}

double Mean::eval() const {
	return m_mean;
}

const char* Mean::name() const {
	return "mean";
}

void Std::update(double next) {

	sum += next;
	count++;
	m_mean = sum / count;
	sum_dif += pow((next - m_mean),2);
	m_std = sqrt(sum_dif / (count - 1));
}

double Std::eval() const {
	return m_std;
}

const char* Std::name() const {
	return "std";
}


void Pct90::update(double next) {
	data.push_back(next);
}

double Pct90::eval() const {
	std::vector<double> sortedData = data;
	std::sort(sortedData.begin(), sortedData.end());
	int index = ((sortedData.size() - 1) * 0.9);
	if (index == sortedData.size() - 1) {
		return sortedData.back();
	}
	else {
		double fraction = (sortedData.size() - 1) * 0.9 - index;
		return (1 - fraction) * sortedData[index] + fraction * sortedData[index + 1];
	}
}

const char* Pct90::name() const {
	return "pct90";
}

void Pct95::update(double next) {
	data.push_back(next);
}

double Pct95::eval() const {
	std::vector<double> sortedData = data;
	std::sort(sortedData.begin(), sortedData.end());
	size_t index = static_cast<size_t>((sortedData.size() - 1) * 0.95);
	if (index == sortedData.size() - 1) {
		return sortedData.back();
	}
	else {
		double fraction = (sortedData.size() - 1) * 0.95 - index;
		return (1 - fraction) * sortedData[index] + fraction * sortedData[index + 1];
	}
}

const char* Pct95::name() const {
	return "pct95";
}
