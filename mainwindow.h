#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//for C++ code
#include<iostream>
#include<string>
#include<vector>

//for the MYSQL
#include <QCoreApplication>
#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDebug>

//for Qt code
#include <QMainWindow>
#include<QWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>   //for regular push buttons
#include<QRadioButton>  //for radio buttons
#include<QComboBox>     //for drop down menu
#include<QInputDialog>
#include<QLineEdit>
#include<QString>
#include<QMessageBox>

/**
    @class MainWindow
    @brief This is what the user sees when they first open the program
*/
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool okToStart();   //determines whether all things have been input
    //std::ostream& operator<<(std::ostream& out, QString words); //operator overload that will be used to convert Qstring to std::string

public slots:
    void updateKaryotype(); //updates karyotypeName
    void updateSex();       //updates sexPhenotypeName
    void updateDiagnosis(); //updated diagnosisInput
    void updateGene();      //updates geneInput
    void updateChromosome();//updates chromosomeInput
    void updatePosition();  //updates positionInput
    void startSearch();     //starts the search process
    void prepareVariables();

private:
    Ui::MainWindow *ui;
    //widgets
    QWidget *masterWidget;  //for all of the widgets to display
    QWidget *top;           //for karyotype, pheno, diagnosis options
    QWidget *bottom;        //for gene or chr + position
    QWidget *karyotype;     //for karyotype selection: XX, XY, XO,
    QWidget *sexPhenotype;  //male, female
    QWidget *diagnosis;     //user input here, separated by spaces
    QWidget *gene;          //takes in name of a gene
    QWidget *chromosome;           //takes in a number that gets added to position
    QWidget *position;      //takes in the number of a gene locus
    QWidget *button;

    //layouts that contain the widgets for input and labels
    QVBoxLayout *allWidgets;
    QVBoxLayout *topLayout;
    QVBoxLayout *bottomLayout;
    QHBoxLayout *karyotypeLayout;       //layout for karyotype selection
    QHBoxLayout *sexPhenotypeLayout;    //layout for sex phenotype
    QHBoxLayout *diagnosisLayout;       //layout for diangosis input
    QHBoxLayout *geneLayout;            //layout for gene input
    QHBoxLayout *chromosomeLayout;             //layout for chr
    QHBoxLayout *positionLayout;        //layout for position on gene input
    QHBoxLayout *buttonLayout;                   //for the run and quit buttons

    //labels that explain what the user input is
    QLabel *karyotypeLabel;             //label for karyotype text
    QLabel *sexPhenotypeLabel;          //label for sex phenotype text
    QLabel *diagnosisLabel;             //label for the diagnosis text
    QLabel *geneLabel;                  //label for the gene text
    QLabel *chromosomeLabel;            //label for the chr label
    QLabel *positionLabel;              //label for the position
    QLabel *mandatoryAsterisk;          //label to explain what the red asterisk means
    QLabel *explainOptional;            //label used to explain that the lower part is option

    //user input interfaces
    QComboBox *karyotypeComboBox;           //takes in the patients karyotype
    QComboBox *sexPhenotypeComboBox;        //takes in the phenotype
    QLineEdit *diagnosisLineEdit;   //takes in the diagnosis
    QLineEdit *geneLineEdit;        //takes in the gene
    QLineEdit *chromosomeLineEdit;  //takes in the chromosome
    QLineEdit *positionLineEdit;    //takes in the position on the chromosome.

    //buttons required
    QPushButton *quitButton;        //button that will quit the program
    QPushButton *searchButton;      //button that will search

    //string objects that contain the information about what needs to be searched.
    std::string karyotypeName;      //stores which karyotype is selected: XX = 0, XY = 1, XXY = 2, XYY = 3, X = 4
    std::string sexPhentypeName;    //stores which sex was entered, male = 0, female = 1, unspecified = 2
    std::string diagnosisInput;     //stotes the diagnosis options
    std::string geneInput;          //stores the gene
    std::string chromosomeInput;    //stores the chromosome input
    std::string positionInput;      //stores the position input
    std::vector<std::string> diagnosisOptions;

    //these boolean values are used to determine which fields have been filled out and determines whether the search can be completed.
    bool karyotypeComplete;
    bool sexPhenotypeComplete;
    bool diagnosisComplete;
    bool geneComplete;
    bool chromosomeComplete;
    bool positionComplete;  //must be true if chromosomeComplete == true



};

#endif // MAINWINDOW_H
