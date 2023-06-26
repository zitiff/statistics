#include <iostream>
#include <limits>
#include <vector>

class IStatistics {
public:
	virtual ~IStatistics() {}
	
	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {

public:

	Min::Min() : m_min{ std::numeric_limits<double>::max() } {
	}

	void update(double next) override;

	double eval() const override;

	const char* name() const override;

private:

	double m_min;
};


class Max : public IStatistics {

public:

	Max() : m_max{ std::numeric_limits<double>::lowest() } {
	}

	void update(double next) override;

	double eval() const override;

	const char* name() const override;

private:

	double m_max;
};

class Mean : public IStatistics {

public:

	Mean() : m_mean{ std::numeric_limits<double>::lowest() } {
	}

	void update(double next) override;

	double eval() const override;

	const char* name() const override;

private:

	double m_mean;

	double sum = 0;

	int count = 0;
};


class Std : public IStatistics {

public:

	Std() : m_std{ std::numeric_limits<double>::lowest() } {
	}

	void update(double next) override;

	double eval() const override;

	const char* name() const override;

private:

	std::vector<double> nums;

	double m_mean;

	double m_std;

	double sum = 0;

	double sum_dif = 0;

	int count = 0;
};

class  Pct90 : public IStatistics {

public:

	void update(double next) override;

	double eval() const override;

	const char* name() const override;

private:
	std::vector<double> data;
};

class  Pct95 : public IStatistics {

public:

	void update(double next) override;

	double eval() const override;

	const char* name() const override;

private:

	std::vector<double> data;
};
