#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);  //sets up the UI for the MainWindow

    setWindowTitle("Disorders of Sexual Development Database"); //sets the title of the window bar

    //create all of the widgets needed to handle layouts
    masterWidget = new QWidget;
    top = new QWidget;
    bottom = new QWidget;
    karyotype = new QWidget;
    sexPhenotype = new QWidget;
    diagnosis = new QWidget;
    gene = new QWidget;
    chromosome = new QWidget;
    position = new QWidget;
    button = new QWidget;

    //create the master layout and add all of the widgets, that will contain their own layouts, to it.
    allWidgets = new QVBoxLayout(masterWidget); //adds master layout to the master widget.  this is the top of the hierarchy
    topLayout = new QVBoxLayout(top);           //creates a layout to put all of the top widgets into
    bottomLayout = new QVBoxLayout(bottom);     //creates a layout to put all of the bottom widgets into
    allWidgets->addWidget(top);     //adds all of the top widgets contained in the "top" widget to the master layout & master widget
    allWidgets->addWidget(bottom);  //adds all of the bottom widgets contained in the "bottom" widget to the master layout & master widget
    masterWidget->setFixedSize(750,600);        //sets fixed size of the screen
    allWidgets->insertSpacing(1,50);            //insert spacer between the mandatory and optional inputs
    allWidgets->insertSpacing(3,10);           //insert a spacer below the optional input
    allWidgets->addWidget(button);
    allWidgets->insertSpacing(5,40);           //insert a spacer below the buttons


    //add all of the widgets to the top or bottom layout
    topLayout->addWidget(karyotype);    //top layout adding the widget that contains its own layout
    topLayout->addWidget(sexPhenotype); //top layout adding the widget that contains its own layout
    topLayout->addWidget(diagnosis);    //bottom layout adding the widget that contains its own layout


    //make karyotype section
    karyotypeLayout = new QHBoxLayout(karyotype);   //adds karyotype layout to its widget
    karyotypeLabel = new QLabel;
    karyotypeLabel->setText("Karyotype:<font color = red>*</font>");
    karyotypeComboBox = new QComboBox;
    karyotypeComboBox->addItem("XX");   //index 1
    karyotypeComboBox->addItem("XY");   //index 2
    karyotypeComboBox->addItem("XXY");   //index 3
    karyotypeComboBox->addItem("XYY");   //index 3
    karyotypeComboBox->addItem("X");   //index 3
    karyotypeComboBox->setCurrentIndex(0);  //sets default to 0 (XX)
    karyotypeLayout->addWidget(karyotypeLabel);     //adds the label to the layout
    karyotypeLayout->addWidget(karyotypeComboBox);  //adds the selection box to the layout
    karyotypeLayout->insertSpacing(3,400);

    //make sex phenotype section
    sexPhenotypeLayout = new QHBoxLayout(sexPhenotype); //adds the layout to its widget
    sexPhenotypeLabel = new QLabel;                     //creates the label
    sexPhenotypeLabel->setText("Sex Phenotype:<font color = red>*</font>");        //sets label text
    sexPhenotypeComboBox = new QComboBox;               //creates combo box
    sexPhenotypeComboBox->addItem("Male");              //index 1
    sexPhenotypeComboBox->addItem("Female");            //index 2
    sexPhenotypeComboBox->addItem("Unspecified");       //index 3
    karyotypeComboBox->setCurrentIndex(0);              //sets default to 0 (male)
    sexPhenotypeLayout->addWidget(sexPhenotypeLabel);   //adds the label to the layout
    sexPhenotypeLayout->addWidget(sexPhenotypeComboBox);//adds the selection box to the layout
    sexPhenotypeLayout->insertSpacing(3,400);


    //make the diagnosis section
    diagnosisLayout = new QHBoxLayout(diagnosis);   //creates layout and adds it to its widget
    diagnosisLabel = new QLabel;                    //creates the diagnosis label
    diagnosisLabel->setText("Diagnosis:<font color = red>*</font>");           //sets text of diagnosis label
    diagnosisLineEdit = new QLineEdit;      //creates the input dialogue
    diagnosisLineEdit->setPlaceholderText("Enter diagnosis separated by ' , '");
    diagnosisLayout->addWidget(diagnosisLabel);     //adds the label to the layout
    diagnosisLayout->insertSpacing(1, 20);
    diagnosisLayout->addWidget(diagnosisLineEdit); //adds the dialogue input box to the layout

    //add the mandatory asterisk part
    mandatoryAsterisk = new QLabel; //for the text that explains that anything with a red star is mandatoy input
    mandatoryAsterisk->setText("<font color = red>*</font>Indicates input that is mandatory.");
    mandatoryAsterisk->setAlignment(Qt::AlignCenter);
    topLayout->addWidget(mandatoryAsterisk);


    //add the optional input information label
    explainOptional = new QLabel;
    explainOptional->setText("The following information is optional:");
    explainOptional->setAlignment(Qt::AlignCenter);
    bottomLayout->addWidget(explainOptional, 0);
    bottomLayout->addWidget(gene);      //bottom
    bottomLayout->addWidget(chromosome);//bottom
    bottomLayout->addWidget(position);  //bottom

    //make the gene input area
    geneLayout = new QHBoxLayout(gene); //creates gene layout and adds it to the widget
    geneLabel = new QLabel;             //creates the label for the gene input
    geneLabel->setText("Gene:");        //sets text to gene
    geneLineEdit = new QLineEdit;       //creates the line edit object
    geneLineEdit->setPlaceholderText("Enter gene name");    //sets default text
    geneLayout->addWidget(geneLabel);       //adds the label to the layout
    geneLayout->insertSpacing(1, 53);
    geneLayout->addWidget(geneLineEdit);    //adds the line edit object to the layout

    //make the chromosome input area
    chromosomeLayout = new QHBoxLayout(chromosome); //creates the chromosome layout and adds it to the chromosome widget
    chromosomeLabel = new QLabel;                   //creates the chromosome text label
    chromosomeLabel->setText("Chromosome:");        //sets text of the label
    chromosomeLineEdit = new QLineEdit;             //creates the line edit object
    chromosomeLineEdit->setPlaceholderText("Enter the chromosome number here"); //sets default text of the lineedit object
    chromosomeLayout->addWidget(chromosomeLabel);       //adds the label to the layout
    chromosomeLayout->addWidget(chromosomeLineEdit);    //adds the text input object to the layout
    //chromosomeLayout->insertSpacing(1, 20);


    //make the gene locus input area
    positionLayout = new QHBoxLayout(position);     //creates the position layout and adds it to the widget
    positionLabel = new QLabel;                     //creates the position label
    positionLabel->setText("Position:");            //sets the position label
    positionLineEdit = new QLineEdit;               //creates new line edit object
    positionLineEdit->setPlaceholderText("Enter the position of the gene on the chromosome");   //sets default text
    positionLayout->addWidget(positionLabel);       //adds the label to the layout
    positionLayout->addWidget(positionLineEdit);    //adds the position line edit object to the object
    positionLayout->insertSpacing(1, 31);           //adds spacer to improve alignment

    //make the push buttons
    buttonLayout = new QHBoxLayout(button);         //creates the button layout and adds it to the button widget which is already in the main one
    quitButton = new QPushButton;
    quitButton->setText("Quit");
    searchButton = new QPushButton;
    searchButton->setText("Search");
    buttonLayout->insertSpacing(0, 50);
    buttonLayout->addWidget(quitButton);
    buttonLayout->insertSpacing(2, 100);
    buttonLayout->addWidget(searchButton);
    buttonLayout->insertSpacing(4, 50);


    //code that does things when the something is clicked or text is entered
    //the CONNECT functions
    updateKaryotype();  //so the default is actually input
    updateSex();        //so the default is actually input

    connect(karyotypeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateKaryotype()));    //updates karyotypeName
    connect(sexPhenotypeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSex()));       //updates sexPhenotypeName
    connect(diagnosisLineEdit, SIGNAL(textChanged(QString)), this, SLOT(updateDiagnosis()));        //updates diagnosisInput std::string
    connect(geneLineEdit, SIGNAL(textChanged(QString)), this, SLOT(updateGene()));                  //updates geneInput std::string
    connect(chromosomeLineEdit, SIGNAL(textChanged(QString)), this, SLOT(updateChromosome()));      //updates the chromosomeInput
    connect(positionLineEdit, SIGNAL(textChanged(QString)), this, SLOT(updatePosition()));          //updates the positionInput string
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));                                    //quits the program
    connect(searchButton, SIGNAL(clicked()), this, SLOT(startSearch()));                             //calls startSearch slot/function
    setCentralWidget(masterWidget);



}

/**
    @brief this is the MainWindow destructor and handles all memory for the objects that it inherets
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/**
    @brief this function updates the string value of the karyotype
            assignments: XX = 0, XY = 1, XXY = 2, XYY = 3, X = 4

*/
void MainWindow::updateKaryotype(){
    // XX = 0, XY = 1, XXY = 2, XYY = 3, X = 4
    int currentIndex = karyotypeComboBox->currentIndex(); //sets the value of the karyotype to the current index
    if (currentIndex == 0){
        karyotypeName = "XX";
    }
    else if(currentIndex == 1){
        karyotypeName = "XY";
    }
    else if(currentIndex == 2){
        karyotypeName = "XXY";
    }
    else if(currentIndex == 3){
        karyotypeName = "XYY";
    }
    else if(currentIndex == 4){
        karyotypeName = "X";
    }
    else{ //this might be bad
        karyotypeName = " ";
    }
    karyotypeComplete = true;
    std::cout << "Karyotype Updated: "<< karyotypeName << std::endl;

    return;
}

/**
    @brief this function updates the value of the phenotypical sex, which can be either male, female, or unspecified.
            male = 0, female = 1, unspecified = 2
*/
void MainWindow::updateSex(){
    int currentIndex = sexPhenotypeComboBox->currentIndex();    //gets the current index of the combo box
    if(currentIndex == 0){
        sexPhentypeName = "male";
    }
    else if(currentIndex == 1){
        sexPhentypeName = "female";
    }
    else if(currentIndex == 2){
        sexPhentypeName = "unspecified";
    }
    else{   //this might be bad
        sexPhentypeName = " ";
    }
    sexPhenotypeComplete = true;
    std::cout << "Sex updated: " << sexPhentypeName << std::endl;
    return;
}

/**
    @brief this function updates the string containing all of the possible diagnosis that are input, separated by a ',' with spaces*/
void MainWindow::updateDiagnosis(){
    QString word = diagnosisLineEdit->text();   //create a QString object (temporary) that is equal to everything in the input line
    diagnosisInput = word.toStdString();        //set the std::string equal to the QString by converting the QString type
    std::cout<<"Diagnosis is: " << diagnosisInput << std::endl; //out to console, to be deleted

    if(diagnosisInput != std::string("")){  //meaning the string is not empty
        diagnosisComplete = true; //if they wrote something
    }
    else{
        diagnosisComplete = false;  //if they wrote something and then erased it
    }
    //when the program search is called, the vector containing the different strings that are being searched needs to be called
}

/**
    @brief this function updates string that contains information about which gene is going to be searched*/
void MainWindow::updateGene(){
    QString word = geneLineEdit->text();   //create a QString object (temporary) that is equal to everything in the input line
    geneInput = word.toStdString();        //set the std::string equal to the QString by converting the QString type
    std::cout<<"Gene is: " << geneInput << std::endl; //out to console, to be deleted
    if(geneInput != std::string("")){
        geneComplete = true;
    }
    else{
        geneComplete = false;
    }
    //when the program search is called, the vector containing the different strings that are being searched needs to be called
}

/**
    @brief this function updates the string that contains information about which chromosome the mutation is on*/
void MainWindow::updateChromosome(){
    QString word = chromosomeLineEdit->text();   //create a QString object (temporary) that is equal to everything in the input line
    chromosomeInput = word.toStdString();        //set the std::string equal to the QString by converting the QString type
    if(chromosomeInput != std::string("")){
        chromosomeInput += "_"; //if there is input, then add the underscore
        chromosomeComplete = true;//it's been entered
    }
    else{
        chromosomeComplete = false;
    }
    std::cout<<"Chromosome is: " << chromosomeInput << std::endl; //out to console, to be deleted
    //when the program search is called, the vector containing the different strings that are being searched needs to be called
}

/**
    @brief this function updates the string that contains information about what the position on the respective chromosome is.*/
void MainWindow::updatePosition(){
    QString word = positionLineEdit->text();   //create a QString object (temporary) that is equal to everything in the input line
    positionInput = word.toStdString();        //set the std::string equal to the QString by converting the QString type
    if(positionInput != std::string("")){
        positionComplete = true;
    }
    else{
        positionComplete = false;
    }
    std::cout<<"Position is: " << positionInput << std::endl; //out to console, to be deleted
    //when the program search is called, the vector containing the different strings that are being searched needs to be called
}

/**
    @brief this function will start the search and does other things: creates the vector that contains all of the diagnoses that will be searched, combines the chromosome and position into
            one string.*/
void MainWindow::startSearch(){
    if(!okToStart()) return;  //meaning there are things not complete
    prepareVariables();         //combines the chromosome and position if it's been inputed


}

/**
    @brief this function updates the chromosome string object to be the complete input for the database in the form X_YYYY by combining chromosomeINput and positionInput*/
void MainWindow::prepareVariables(){
    if(chromosomeComplete && positionComplete){
        chromosomeInput += positionInput;   //combines the chromosome and position
        std::cout<<"Updated Chromosome is: " << chromosomeInput << std::endl;
        return;
    }
    else return;
}

/**
    @brief makes sure all mandatory fields are filled in, makes sure that if chromosome is filled in, so is
            the position on the chromosome
    @return boolean true if everything has been filled in appropriately
    @return boolean false if not everything has been completely properly.*/
bool MainWindow::okToStart(){
    if(karyotypeComplete == false || sexPhenotypeComplete == false || diagnosisComplete == false){
        if(karyotypeComplete == false){
            QMessageBox notComplete;
            notComplete.setText("You must select a karyotype.");
            notComplete.exec();
        }
        else if(sexPhenotypeComplete == false){
            QMessageBox notComplete;
            notComplete.setText("You must select a sex.");
            notComplete.exec();
        }
        else if(diagnosisComplete == false){
            QMessageBox notComplete;
            notComplete.setText("You must enter at least one diagnosis.");
            notComplete.exec();
        }
        return false; //so that they have to fill it out
    }

    if((chromosomeComplete != positionComplete)){   //if they aren't both true or both false
        QMessageBox notComplete;
        notComplete.setText("You must enter the chromosome and the chromosome position.");
        notComplete.exec();
        return false;
    }

    return true;    //meaning that all criteria have been met
}


