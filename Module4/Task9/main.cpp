#include <iostream>

int main() {
    int firstStepTaxPayment = 1300;
    int secondStepTaxPayment = 8000;
    int annualIncome, fullTaxPayment;

    std::cout << "Введите ваш доход: ";
    std::cin >> annualIncome;
    std::cout << "----Раcсчитываем налоги----\n";
    if (annualIncome < 0) {
        annualIncome *= -1;
    }

    if (annualIncome >= 50000) {
        fullTaxPayment = (annualIncome - 50000) * 0.3 + secondStepTaxPayment + firstStepTaxPayment;
    }
    else if (annualIncome < 10000) {
            fullTaxPayment = annualIncome * 0.13;
        }
        else {
            fullTaxPayment = (annualIncome - 10000) * 0.2 + firstStepTaxPayment;
            }

    std::cout << "К оплате налогов на сумму: " << fullTaxPayment << "\n";

  return 0;
}
