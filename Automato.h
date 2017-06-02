#ifndef AUTOMATO_H
#define AUTOMATO_H
#include"vector"
#include"string"
#include"string.h"
#include <QString>
#include<QStringList>
#include<iostream>
#include<map>
#include<cassert>
#include"stdlib.h"
#include"stdio.h"
#include<Celula.h>
#include<tr1/unordered_map>


using namespace std;

class Automato{

   public:
    map<QString, map<QString,Celula> > turing;
    QString *estado;
    QString estadoInicial;
    QString estadoFinal;
    QString estadoRejeite;
    QString *alfa;
    QString *cadeia;
    QString tabela[1000];
    QString seq[1000];
    QString vetor;



    Automato();

    void lerEstado(QString est);
    void lerInicial(QString i);
    void lerFinal(QString f);
    void lerRejeite(QString r);
    void lerAlfabeto(QString a);
    void lerCadeia(QString c, QString a);
    void lerAutomato(QString sequencia);
    QString validarCadeia(QString vet);
    QString getAutomato();
};

#endif // AUTOMATO_H
