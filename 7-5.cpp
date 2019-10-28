
#include <iostream> 
#include <iomanip>

using namespace std;

const double MARRIED_DEDUCTION = 7000.00;
const double SINGLE_DEDUCTION = 4000.00;
const double PERSONAL_EXECPTION = 1500.00;

void getData(char& mStatus, int& nOfChildren, double& salary,
            double& pContribPension);
double taxAmount(char mStatus, int nOfChildren, double salary,
                double pContribPension);

int main()
{
    char maritalStatus; 
    int numberOfChildren; 
    double grossSalary;
    double pContributedToPension;

    cout << fixed << showpoint;
    cout << setprecision(2);

    getData(maritalStatus, numberOfChildren, 
            grossSalary, pContributedToPension);

    cout << endl;
    cout << "Your tax for the year is: "
         << taxAmount(maritalStatus, numberOfChildren, 
                      grossSalary, pContributedToPension)
         << endl;

    return 0;
}

void getData(char& mStatus, int& nOfChildren, double& salary,
             double& pContribPension)
{
    cout << "Enter marital status: m or M (married), s or S (single): ";
    cin >> mStatus;
    cout << endl;

    if (mStatus == 'm' || mStatus == 'M')
    {
        cout << "Enter number of children under the age of 14: ";
        cin >> nOfChildren;
        cout << endl;
    }

    cout << "Enter gross salary for the year: ";
    cin >> salary;
    cout << endl;

    cout << "Enter percentage of salary contributed to pension (0-6 percent): ";
    cin >> pContribPension;
    cout << endl;
}

double taxAmount(char mStatus, int nOfChildren, double salary,
                 double pContribPension)
{
    double taxableAmount;
    double sDeduction;
    double tax;

    int numberOfDeduction;

    if (mStatus == 'm' || mStatus == 'M')
    {
        numberOfDeduction = 2 + nOfChildren;
        sDeduction = MARRIED_DEDUCTION;
    }
    else
    {
        numberOfDeduction = 1;
        sDeduction = SINGLE_DEDUCTION;
    }

    taxableAmount = salary - sDeduction - 
                    PERSONAL_EXECPTION * numberOfDeduction - 
                    salary * pContribPension / 100;

    if (taxableAmount < 0)
        taxableAmount = 0;

    if (0 <= taxableAmount && taxableAmount <= 15000)
        tax = taxableAmount * .15;
    else if (15001 <= taxableAmount && taxableAmount <= 40000)
        tax = 2250 + (taxableAmount - 15000) * .25;
    else
        tax = 8460 + (taxableAmount - 40000) * .35;

	return tax;
}