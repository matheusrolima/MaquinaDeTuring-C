#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Automato.h"
#include"Celula.h"
#include"QFile"
#include"QStandardItem"
#include"QTextStream"
#include"QStringlist"
#include"QTextEdit"



Automato a1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->automato->setDisabled(true);
    ui->Guardar->setDisabled(true);

    ui->estados->setDisabled(true);
    ui->alfabeto->setDisabled(true);
    ui->inicial->setDisabled(true);
    ui->final_2->setDisabled(true);
    ui->Rejeite->setDisabled(true);
    ui->alfabetoDaFita->setDisabled(true);
    ui->carregar->setVisible(false);
    ui->pushButton->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_pushButton_clicked()
{
    a1.lerEstado(ui->estados->text());
    a1.lerAlfabeto(ui->alfabeto->text());
    a1.lerInicial(ui->inicial->text());
    a1.lerFinal(ui->final_2->text());
    a1.lerRejeite(ui->Rejeite->text());
    a1.lerAlfabeto(ui->alfabeto->text());
    a1.lerCadeia(ui->alfabeto->text(),ui->alfabetoDaFita->text());

    ui->estados->setDisabled(true);
    ui->alfabeto->setDisabled(true);
    ui->inicial->setDisabled(true);
    ui->final_2->setDisabled(true);
    ui->Rejeite->setDisabled(true);
    ui->alfabetoDaFita->setDisabled(true);

    ui->automato->setDisabled(false);
    ui->Guardar->setDisabled(false);

}

void MainWindow::on_Guardar_clicked()
{
    a1.lerAutomato(ui->automato->text());
    ui->automato->setDisabled(true);

}

void MainWindow::on_Verificar_clicked()
{
    //a1.validarCadeia(ui->Verificar->text());
    int i=1;


    a1.vetor = "_"+ui->vetor->text()+"_";
    ui->automato->setText(a1.vetor);
    QString disc[a1.vetor.length()];
    int k=0;
    for(;k<a1.vetor.length();k++)
    {
        disc[k]=a1.vetor[k];
    }

    map<QString, map<QString, Celula> > mapMain = a1.turing;
    map<QString,Celula> subMap;

    subMap = mapMain[a1.estadoInicial];
    Celula celula;
    celula = subMap[disc[i]];
    QString aux;
    QString interacoes[1000];
    int t =-1;

    while(true)
    {
        aux="";
        t++;
        if(celula.proximoEstado != "")
        {

            disc[i] = celula.simbolo;
            for(int j=0;j<k;j++)
            {
                aux=aux+disc[j];

            }
            interacoes[t]=aux;
            ui->saida2->setPlainText(interacoes[t]);


            //Implementar uma forma de mostrar o vetor atualizado.
            if(celula.proximoEstado==a1.estadoFinal)
            {
                ui->vetor->setText("Aceito");
                break;
            }
            else
            {
                if(celula.proximoEstado==a1.estadoRejeite)
                {
                    ui->vetor->setText("Rejeitado");
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
            ui->vetor->setText("Erro na fita!");
            break;
        }

    }



}



void MainWindow::on_Visivel_clicked()
{
    ui->estados->setDisabled(false);
    ui->alfabeto->setDisabled(false);
    ui->inicial->setDisabled(false);
    ui->final_2->setDisabled(false);
    ui->Rejeite->setDisabled(false);
    ui->alfabetoDaFita->setDisabled(false);
    ui->automato->setDisabled(false);
}

void MainWindow::on_SAIR_clicked()
{
    MainWindow::close();
}

void MainWindow::on_carregar_clicked()
{
    QFile file("Arquivo.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);

    int row =0;
    QString est = (row,0,(in.readLine()));
    QString alf = (row,1,(in.readLine()));
    QString alfF = (row,2,(in.readLine()));
    QString ini = (row,3,(in.readLine()));
    QString ac = (row,4,(in.readLine()));
    QString rej = (row,5,(in.readLine()));
    QString guarde=(row,6,(in.readLine()));


    a1.lerEstado(est);
    a1.lerAlfabeto(alf);
    a1.lerInicial(ini);
    a1.lerFinal(ac);
    a1.lerRejeite(rej);
    a1.lerCadeia(alf,alfF);
    a1.lerAutomato(guarde);

       ui->estados->setText(est);
       ui->alfabeto->setText(alf);
       ui->alfabetoDaFita->setText(alfF);
       ui->inicial->setText(ini);
       ui->final_2->setText(ac);
       ui->Rejeite->setText(rej);
       ui->automato->setText(guarde);
}

void MainWindow::on_LerArquivos_clicked()
{
    ui->carregar->setVisible(true);
    ui->pushButton->setVisible(false);

}

void MainWindow::on_InserirDados_clicked()
{
    ui->pushButton->setVisible(true);
    ui->carregar->setVisible(false);
    ui->estados->setDisabled(false);
    ui->alfabeto->setDisabled(false);
    ui->inicial->setDisabled(false);
    ui->final_2->setDisabled(false);
    ui->Rejeite->setDisabled(false);
    ui->alfabetoDaFita->setDisabled(false);
    ui->automato->setDisabled(false);

    ui->estados->setText("");
    ui->alfabeto->setText("");
    ui->alfabetoDaFita->setText("");
    ui->inicial->setText("");
    ui->final_2->setText("");
    ui->Rejeite->setText("");
    ui->automato->setText("");
}
