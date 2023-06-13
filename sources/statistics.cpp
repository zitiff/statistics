#include "../statistics.h"
#include <iostream>
#include <limits>
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