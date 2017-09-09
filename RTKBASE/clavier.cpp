#include "clavier.h"
#include "ui_clavier.h"
#include <iostream>

Clavier::Clavier(QString ancientexte, QString nomchamp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clavier)
{
    ui->setupUi(this);

    ui->ZonetextLine->setText(ancientexte);
    ui->NomchampLabel->setText(nomchamp);

    QObject::connect(ui->AButton,SIGNAL(clicked()),this,SLOT(A()));
    QObject::connect(ui->ZButton,SIGNAL(clicked()),this,SLOT(Z()));
    QObject::connect(ui->EButton,SIGNAL(clicked()),this,SLOT(E()));
    QObject::connect(ui->RButton,SIGNAL(clicked()),this,SLOT(R()));
    QObject::connect(ui->TButton,SIGNAL(clicked()),this,SLOT(T()));
    QObject::connect(ui->YButton,SIGNAL(clicked()),this,SLOT(Y()));
    QObject::connect(ui->UButton,SIGNAL(clicked()),this,SLOT(U()));
    QObject::connect(ui->IButton,SIGNAL(clicked()),this,SLOT(I()));
    QObject::connect(ui->OButton,SIGNAL(clicked()),this,SLOT(O()));
    QObject::connect(ui->PButton,SIGNAL(clicked()),this,SLOT(P()));
    QObject::connect(ui->QButton,SIGNAL(clicked()),this,SLOT(Q()));
    QObject::connect(ui->SButton,SIGNAL(clicked()),this,SLOT(S()));
    QObject::connect(ui->DButton,SIGNAL(clicked()),this,SLOT(D()));
    QObject::connect(ui->FButton,SIGNAL(clicked()),this,SLOT(F()));
    QObject::connect(ui->GButton,SIGNAL(clicked()),this,SLOT(G()));
    QObject::connect(ui->HButton,SIGNAL(clicked()),this,SLOT(H()));
    QObject::connect(ui->JButton,SIGNAL(clicked()),this,SLOT(J()));
    QObject::connect(ui->KButton,SIGNAL(clicked()),this,SLOT(K()));
    QObject::connect(ui->LButton,SIGNAL(clicked()),this,SLOT(L()));
    QObject::connect(ui->MButton,SIGNAL(clicked()),this,SLOT(M()));
    QObject::connect(ui->WButton,SIGNAL(clicked()),this,SLOT(W()));
    QObject::connect(ui->XButton,SIGNAL(clicked()),this,SLOT(X()));
    QObject::connect(ui->CButton,SIGNAL(clicked()),this,SLOT(C()));
    QObject::connect(ui->VButton,SIGNAL(clicked()),this,SLOT(V()));
    QObject::connect(ui->BButton,SIGNAL(clicked()),this,SLOT(B()));
    QObject::connect(ui->NButton,SIGNAL(clicked()),this,SLOT(N()));
    QObject::connect(ui->SpaceButton,SIGNAL(clicked()),this,SLOT(Space()));
    QObject::connect(ui->BackButton,SIGNAL(clicked()),this,SLOT(Back()));
    QObject::connect(ui->MajButton,SIGNAL(clicked()),this,SLOT(Maj()));
    QObject::connect(ui->GaucheButton,SIGNAL(clicked()),this,SLOT(Gauche()));
    QObject::connect(ui->DroiteButton,SIGNAL(clicked()),this,SLOT(Droite()));
    QObject::connect(ui->VirgButton,SIGNAL(clicked()),this,SLOT(Virg()));
    QObject::connect(ui->PvirgButton,SIGNAL(clicked()),this,SLOT(PVirg()));
    QObject::connect(ui->P2Button,SIGNAL(clicked()),this,SLOT(P2()));
    QObject::connect(ui->PexclButton,SIGNAL(clicked()),this,SLOT(PExcl()));
    QObject::connect(ui->UnderButton,SIGNAL(clicked()),this,SLOT(Under()));
    QObject::connect(ui->ChevgButton,SIGNAL(clicked()),this,SLOT(ChevG()));
    QObject::connect(ui->ChevdButton,SIGNAL(clicked()),this,SLOT(ChevD()));
    QObject::connect(ui->PintButton,SIGNAL(clicked()),this,SLOT(PInt()));
    QObject::connect(ui->PointButton,SIGNAL(clicked()),this,SLOT(Point()));
    QObject::connect(ui->SlashButton,SIGNAL(clicked()),this,SLOT(Slash()));
    QObject::connect(ui->AslashButton,SIGNAL(clicked()),this,SLOT(ASlash()));
    QObject::connect(ui->_9Button,SIGNAL(clicked()),this,SLOT(_9()));
    QObject::connect(ui->_8Button,SIGNAL(clicked()),this,SLOT(_8()));
    QObject::connect(ui->_7Button,SIGNAL(clicked()),this,SLOT(_7()));
    QObject::connect(ui->_6Button,SIGNAL(clicked()),this,SLOT(_6()));
    QObject::connect(ui->_5Button,SIGNAL(clicked()),this,SLOT(_5()));
    QObject::connect(ui->_4Button,SIGNAL(clicked()),this,SLOT(_4()));
    QObject::connect(ui->_3Button,SIGNAL(clicked()),this,SLOT(_3()));
    QObject::connect(ui->_2Button,SIGNAL(clicked()),this,SLOT(_2()));
    QObject::connect(ui->_1Button,SIGNAL(clicked()),this,SLOT(_1()));
    QObject::connect(ui->_0Button,SIGNAL(clicked()),this,SLOT(_0()));
    QObject::connect(ui->MoinsButton,SIGNAL(clicked()),this,SLOT(Moins()));
    QObject::connect(ui->PlusButton,SIGNAL(clicked()),this,SLOT(Plus()));
    QObject::connect(ui->DivButton,SIGNAL(clicked()),this,SLOT(Div()));
    QObject::connect(ui->AstButton,SIGNAL(clicked()),this,SLOT(Ast()));

    QObject::connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(Cancel()));
    QObject::connect(ui->OKButton,SIGNAL(clicked()),this,SLOT(OK()));
}

Clavier::~Clavier()
{
    delete ui;
}

void Clavier::A()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("a"));
    else ui->ZonetextLine->insert(QString("A"));
}

void Clavier::Z()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("z"));
    else ui->ZonetextLine->insert(QString("Z"));
}

void Clavier::E()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("e"));
    else ui->ZonetextLine->insert(QString("E"));
}

void Clavier::R()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("r"));
    else ui->ZonetextLine->insert(QString("R"));
}

void Clavier::T()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("t"));
    else ui->ZonetextLine->insert(QString("T"));
}

void Clavier::Y()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("y"));
    else ui->ZonetextLine->insert(QString("Y"));
}

void Clavier::U()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("u"));
    else ui->ZonetextLine->insert(QString("U"));
}

void Clavier::I()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("i"));
    else ui->ZonetextLine->insert(QString("I"));
}

void Clavier::O()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("o"));
    else ui->ZonetextLine->insert(QString("O"));
}

void Clavier::P()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("p"));
    else ui->ZonetextLine->insert(QString("P"));
}

void Clavier::Q()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("q"));
    else ui->ZonetextLine->insert(QString("Q"));
}

void Clavier::S()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("s"));
    else ui->ZonetextLine->insert(QString("S"));
}

void Clavier::D()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("d"));
    else ui->ZonetextLine->insert(QString("D"));
}

void Clavier::F()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("f"));
    else ui->ZonetextLine->insert(QString("F"));
}

void Clavier::G()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("g"));
    else ui->ZonetextLine->insert(QString("G"));
}

void Clavier::H()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("h"));
    else ui->ZonetextLine->insert(QString("H"));
}

void Clavier::J()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("j"));
    else ui->ZonetextLine->insert(QString("J"));
}

void Clavier::K()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("k"));
    else ui->ZonetextLine->insert(QString("K"));
}

void Clavier::L()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("l"));
    else ui->ZonetextLine->insert(QString("L"));
}

void Clavier::M()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("m"));
    else ui->ZonetextLine->insert(QString("M"));
}

void Clavier::W()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("w"));
    else ui->ZonetextLine->insert(QString("W"));
}

void Clavier::X()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("x"));
    else ui->ZonetextLine->insert(QString("X"));
}

void Clavier::C()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("c"));
    else ui->ZonetextLine->insert(QString("C"));
}

void Clavier::V()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("v"));
    else ui->ZonetextLine->insert(QString("V"));
}

void Clavier::B()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("b"));
    else ui->ZonetextLine->insert(QString("B"));
}

void Clavier::N()
{
    if (!MAJ) ui->ZonetextLine->insert(QString("n"));
    else ui->ZonetextLine->insert(QString("N"));
}

void Clavier::Space()
{
    ui->ZonetextLine->insert(QString(" "));
}

void Clavier::Virg()
{
    ui->ZonetextLine->insert(QString(","));
}

void Clavier::PVirg()
{
    ui->ZonetextLine->insert(QString(";"));
}

void Clavier::P2()
{
    ui->ZonetextLine->insert(QString(":"));
}

void Clavier::PExcl()
{
    ui->ZonetextLine->insert(QString("!"));
}

void Clavier::Under()
{
    ui->ZonetextLine->insert(QString("_"));
}

void Clavier::ChevG()
{
    ui->ZonetextLine->insert(QString("<"));
}

void Clavier::ChevD()
{
    ui->ZonetextLine->insert(QString(">"));
}

void Clavier::PInt()
{
    ui->ZonetextLine->insert(QString("?"));
}

void Clavier::Point()
{
    ui->ZonetextLine->insert(QString("."));
}

void Clavier::Slash()
{
    ui->ZonetextLine->insert(QString("/"));
}

void Clavier::ASlash()
{
    ui->ZonetextLine->insert(QString("\\"));
}

void Clavier::_0()
{
    ui->ZonetextLine->insert(QString("0"));
}

void Clavier::_1()
{
    ui->ZonetextLine->insert(QString("1"));
}

void Clavier::_2()
{
    ui->ZonetextLine->insert(QString("2"));
}

void Clavier::_3()
{
    ui->ZonetextLine->insert(QString("3"));
}

void Clavier::_4()
{
    ui->ZonetextLine->insert(QString("4"));
}

void Clavier::_5()
{
    ui->ZonetextLine->insert(QString("5"));
}

void Clavier::_6()
{
    ui->ZonetextLine->insert(QString("6"));
}

void Clavier::_7()
{
    ui->ZonetextLine->insert(QString("7"));
}

void Clavier::_8()
{
    ui->ZonetextLine->insert(QString("8"));
}

void Clavier::_9()
{
    ui->ZonetextLine->insert(QString("9"));
}

void Clavier::Moins()
{
    ui->ZonetextLine->insert(QString("-"));
}

void Clavier::Plus()
{
    ui->ZonetextLine->insert(QString("+"));
}

void Clavier::Div()
{
    ui->ZonetextLine->insert(QString("/"));
}

void Clavier::Ast()
{
    ui->ZonetextLine->insert(QString("*"));
}


void Clavier::Maj()
{
    if (ui->MajButton->isChecked()==true)
    {
        MAJ = true;
        ui->AButton->setText(QString("A"));
        ui->ZButton->setText(QString("Z"));
        ui->EButton->setText(QString("E"));
        ui->RButton->setText(QString("R"));
        ui->TButton->setText(QString("T"));
        ui->YButton->setText(QString("Y"));
        ui->UButton->setText(QString("U"));
        ui->IButton->setText(QString("I"));
        ui->OButton->setText(QString("O"));
        ui->PButton->setText(QString("P"));
        ui->QButton->setText(QString("Q"));
        ui->SButton->setText(QString("S"));
        ui->DButton->setText(QString("D"));
        ui->FButton->setText(QString("F"));
        ui->GButton->setText(QString("G"));
        ui->HButton->setText(QString("H"));
        ui->JButton->setText(QString("J"));
        ui->KButton->setText(QString("K"));
        ui->LButton->setText(QString("L"));
        ui->MButton->setText(QString("M"));
        ui->WButton->setText(QString("W"));
        ui->XButton->setText(QString("X"));
        ui->CButton->setText(QString("C"));
        ui->VButton->setText(QString("V"));
        ui->BButton->setText(QString("B"));
        ui->NButton->setText(QString("N"));
    }
    else
    {
        MAJ = false;
        ui->AButton->setText(QString("a"));
        ui->ZButton->setText(QString("z"));
        ui->EButton->setText(QString("e"));
        ui->RButton->setText(QString("r"));
        ui->TButton->setText(QString("t"));
        ui->YButton->setText(QString("y"));
        ui->UButton->setText(QString("u"));
        ui->IButton->setText(QString("i"));
        ui->OButton->setText(QString("o"));
        ui->PButton->setText(QString("p"));
        ui->QButton->setText(QString("q"));
        ui->SButton->setText(QString("s"));
        ui->DButton->setText(QString("d"));
        ui->FButton->setText(QString("f"));
        ui->GButton->setText(QString("g"));
        ui->HButton->setText(QString("h"));
        ui->JButton->setText(QString("j"));
        ui->KButton->setText(QString("k"));
        ui->LButton->setText(QString("l"));
        ui->MButton->setText(QString("m"));
        ui->WButton->setText(QString("w"));
        ui->XButton->setText(QString("x"));
        ui->CButton->setText(QString("c"));
        ui->VButton->setText(QString("v"));
        ui->BButton->setText(QString("b"));
        ui->NButton->setText(QString("n"));
    }
}

void Clavier::Back()
{
    ui->ZonetextLine->backspace();
}

void Clavier::Gauche()
{
    ui->ZonetextLine->setCursorPosition(ui->ZonetextLine->cursorPosition()-1);
}

void Clavier::Droite()
{
    ui->ZonetextLine->setCursorPosition(ui->ZonetextLine->cursorPosition()+1);
}


void Clavier::Cancel()
{
    this->close();
}

void Clavier::OK()
{
    this->close();
    emit Texte(ui->ZonetextLine->text());
    std::cout<<"Nouveau Texte : "<<ui->ZonetextLine->text().toStdString()<<std::endl;
}
