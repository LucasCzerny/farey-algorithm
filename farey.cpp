#include <iostream>

// The algorithm uses the "Naive Fraction Sum", where you add the nominators and denominators of two fractions like this:
//  a     c       a + c 
// --- & --- --> -------
//  b     d       b + d

struct Fraction
{
    double Nominator, Denominator;

    Fraction(double nominator, double denominator)
        : Nominator(nominator), Denominator(denominator) {}

    double GetValue() const { return Nominator / Denominator; }

    Fraction operator&(const Fraction& other)
    {
        Fraction result(this->Nominator + other.Nominator, this->Denominator + other.Denominator);
        return result;
    }
};

Fraction FareyAlgorithm(double value)
{
    Fraction lowerBound(0.0, 1.0);
    Fraction upperBound(1.0, 1.0);

    static const unsigned int DEPTH = 100;
    for (unsigned int i = 0; i < DEPTH; i++)
    {
        Fraction median = lowerBound & upperBound;

        if (value < median.GetValue())
            upperBound = median;
        else
            lowerBound = median;
    }

    return lowerBound & upperBound;
}

int main()
{
    double valueToApproximate = 0.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912;

    Fraction approx = FareyAlgorithm(valueToApproximate);
    std::cout << approx.Nominator << " / " << approx.Denominator << "\n";
}
