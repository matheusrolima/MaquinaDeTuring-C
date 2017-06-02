#include"Automato.h"
#include"mainwindow.h"
#include"stdio.h"


Automato::Automato()
{

}

void Automato::lerEstado(QString est)
{

    QStringList nome = est.split(",");
    this->estado = new QString[nome.size()];
    int i=0;
    for(QStringList::iterator it=nome.begin();it !=nome.end();it++)
    {

        estado[i]=*it;
        map<QString, Celula> aux;
        this->turing[*it]= aux;
        i++;
    }

}
void Automato::lerInicial(QString i)
{
    this->estadoInicial = i;
}
void Automato::lerFinal(QString f)
{
    this->estadoFinal = f;
}
void Automato::lerRejeite(QString r)
{
    this->estadoRejeite = r;
}

void Automato::lerAlfabeto(QString a)
{
    QStringList nome = a.split(",");
    this->alfa = new QString[nome.size()];
    int i=0;
    for(QStringList::iterator it=nome.begin();it !=nome.end();it++)
    {
        alfa[i]=*it;

        i++;
    }
}
void Automato::lerCadeia(QString c,QString a)
{
    QStringList nome1=a.split(",");
    QStringList nome2=c.split(",");
    this->cadeia = new QString[nome1.size() + nome2.size()];
    int i=0;

    for(QStringList::iterator it=nome1.begin();it !=nome1.end();it++, i++)
    {
        cadeia[i]=*it;
    }
    for(QStringList::iterator it=nome2.begin();it !=nome2.end();it++, i++)
    {
        cadeia[i]=*it;

    }
}
void Automato::lerAutomato(QString sequencia)
{
    QStringList nome = sequencia.split(";");
    map<QString, Celula> subMap;


    int i=0;
    for(QStringList::iterator it=nome.begin();it !=nome.end();it++)
    {
        QString current = *it;
        tabela[i]=current;
        i++;
    }

    QStringList nome2;
    for(int i=0; i<nome.size();i++)
    {
        nome2=tabela[i].split(" ");
        subMap = this->turing[nome2[0]];
        Celula *celula = new Celula();
        celula->proximoEstado = nome2[2];
        celula->simbolo = nome2[3];
        celula->direcao = nome2[4];
        subMap[nome2[1]] = *celula;
        this->turing[nome2[0]] = subMap;
    }
   // QString oi = getAutomato();
    //QString falou = "matheus";
}
QString Automato::getAutomato(){
    map<QString, Celula> subMap;
    QString sCurrent = "";
    Celula celula;
    for(int i = 0; i < this->estado->length(); ++i){
        subMap = this->turing[this->estado[i]];
        sCurrent += this->estado[i] + " --->";
        for(int j = 0; j < this->alfa->length(); ++j){
            celula = subMap[this->alfa[j]];
            sCurrent+= " " + celula.proximoEstado + " " +
                    celula.simbolo + " " +
                    celula.direcao + "; ";
        }
        sCurrent += "....";
    }
    return sCurrent;
}

/*QString Automato::validarCadeia(QString vet)
{
    int i=1;
    vetor = "_0000_";
    QString disc[vetor.length()];
    for(int i=0;i<vetor.length();i++)
    {
        disc[i]=vetor[i];
    }

    map<QString, map<QString, Celula> > mapMain = this->turing;
    map<QString,Celula> subMap;

    subMap = mapMain[this->estadoInicial];
    Celula celula;
    celula = subMap[disc[i]];

    while(true)
    {
        if(celula.proximoEstado != "")
        {
            disc[i] = celula.simbolo;
            //Implementar uma forma de mostrar o vetor atualizado.
            if(celula.proximoEstado==this->estadoFinal)
            {
                //implementar impressão de mensagem : Aceite.
                break;
            }
            else
            {
                if(celula.proximoEstado==this->estadoRejeite)
                {
                    //implementar impressão de mensagem : Rejeite.
                    break;
                }
            }
            if(celula.direcao=="D" || celula.direcao=="d")
            {
                i++;
            }
            else
            {
                if(celula.direcao=="E"||celula.direcao=="e")
                {
                    i--;
                }
            }
            subMap = mapMain[celula.proximoEstado];
            celula = subMap[disc[i]];

        }
        else
        {
            //Implementar mensagem de erro na inserção da fita;
            break;
        }
    }
}
*/








