// Lab 3a, SalesPerson.h
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks
#ifndef SalesPerson_h
#define SalesPerson_h

class SalesPerson
{
  public:
    static const int monthsPerYear = 12;
    SalesPerson();
    void getSalesFromUser();
    void setSales(int, double);
    void printAnnualSales();
  private:
    double totalAnnualSales();
    double sales[monthsPerYear];
};

#endif
