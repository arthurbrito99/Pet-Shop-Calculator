#include "calculos.h"

bool verificaDiaUtil(int dia, int mes, int ano){

    // Congruência de Zeller
    if (mes == 1) {
        mes = 13;
        ano--;
    }
    if (mes == 2) {
        mes = 14;
        ano--;
    }

    int q = dia;
    int m = mes;
    int k = ano % 100;
    int j = ano / 100;

    int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;

    if(h == 0 || h == 1)
        return false;
    else
        return true;

}

// Calculos de valores para cada canil dado se é dia util e a quantidade de caes pequenos e grandes

float calculaMCC(bool diaUtil, int caesPequenos, int caesGrandes){

    float valor = ((caesPequenos * 20.00) + (caesGrandes * 40.00));

    if(!diaUtil)
        valor = valor * 1.2;

    return valor;

}

float calculaVR(bool diaUtil, int caesPequenos, int caesGrandes){

    if(diaUtil){
        return ((caesPequenos * 15.00) + (caesGrandes * 50.00));
    }
    else{
        return ((caesPequenos * 20.00) + (caesGrandes * 55.00));
    }

}

float calculaCC(bool diaUtil, int caesPequenos, int caesGrandes){

    return ((caesPequenos * 30.00) + (caesGrandes * 45.00));

}