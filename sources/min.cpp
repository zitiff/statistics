#include "../headers/min.h"
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
