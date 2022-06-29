#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

#include "calculos.h"

int main() {

    string strData;
    int qtdCaesPequenos, qtdCaesGrandes;
    cin >> strData >> qtdCaesPequenos >> qtdCaesGrandes;

    istringstream buf(strData);
    int dia, mes, ano;
    char b1, b2;

    // Verifica se a data é válida e converte para inteiros
    if (!(buf >> dia >> b1 >> mes >> b2 >> ano && b1 == '/' && b2 == '/')) {
        cout << "Data invalida\n";
        return 0;
    }
    
    bool diaUtil = verificaDiaUtil(dia, mes, ano);

    float valorMCC = calculaMCC(diaUtil, qtdCaesPequenos, qtdCaesGrandes);
    float valorVR = calculaVR(diaUtil, qtdCaesPequenos, qtdCaesGrandes);
    float valorCC = calculaCC(diaUtil, qtdCaesPequenos, qtdCaesGrandes);

    // Canis em ordem decrescente de distância e os valores respectivos
    string canis[] = {"Meu Canino Feliz", "Vai Rex", "ChowChawgas"};
    float valores[] = {valorMCC, valorVR, valorCC};

    string canil = canis[0];
    float valorFinal = valores[0];

    for(int i = 1; i < 3; i++){
        if(valores[i] <= valorFinal){
            canil = canis[i];
            valorFinal = valores[i];
        }
    }

    cout << "Canil escolhido: " << canil << '\n';
    cout << "Valor total: " << valorFinal << '\n';

    return 0;

}