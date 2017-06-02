#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

    void on_Guardar_clicked();

    void on_Verificar_clicked();

    void on_Visivel_clicked();

    void on_SAIR_clicked();

    void on_carregar_clicked();

    void on_LerArquivos_clicked();

    void on_InserirDados_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
