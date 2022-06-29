#include <iostream>

using namespace std;

#include "calculos.h"

// Testes
bool testaDiaUtil(int d, int m, int a) {
    return verificaDiaUtil(d, m, a);
}
bool testaValorMCC(bool diaUtil) {
    float valor = calculaMCC(diaUtil, 1, 1);
    return (diaUtil ? valor == 60.00 : valor == 72.00);
}
bool testaValorVR(bool diaUtil) {
    float valor = calculaVR(diaUtil, 1, 1);
    return (diaUtil ? valor == 65.00 : valor == 75.00);
}
bool testaValorCC(bool diaUtil) {
    float valor = calculaCC(diaUtil, 1, 1);
    return (valor == 75.00);
}

// Falha se o teste em questão retornar false
#define IS_TRUE(x) { if (!(x)) cout << __FUNCTION__ << " falhou na linha " << __LINE__ << endl; else cout << __FUNCTION__ << " passou na linha " << __LINE__ << endl; }

void runTests(){
    IS_TRUE(!testaDiaUtil(29, 05, 2022));
    IS_TRUE(testaDiaUtil(30, 05, 2022));
    IS_TRUE(testaValorMCC(true));
    IS_TRUE(testaValorMCC(false));
    IS_TRUE(testaValorVR(true));
    IS_TRUE(testaValorVR(false));
    IS_TRUE(testaValorCC(true));
    IS_TRUE(testaValorCC(false));
}

int main(void) {
    runTests();
}