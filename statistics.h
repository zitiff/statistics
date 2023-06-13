#include <iostream>
#include <limits>

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

	Max::Max() : m_max{ std::numeric_limits<double>::min() } {
	}

	void update(double next) override;

	double eval() const override;

	const char* name() const override;

private:

	double m_max;
};