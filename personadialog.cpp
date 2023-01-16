#include "personadialog.h"
#include "ui_personadialog.h"

PersonaDialog::PersonaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonaDialog)
{
    ui->setupUi(this);
}

PersonaDialog::~PersonaDialog()
{
    delete ui;
}

void PersonaDialog::on_buttonBox_accepted()
{

    QString nombre = ui->inNombre->text();
    QString apellido = ui->inApellido->text();
    QString telefono = ui->inTelefono->text();
    QString email = ui->inEmail->text();

    if( !v_telf(telefono) || !v_email(email)||!v_nomap(nombre)||!v_nomap(apellido)){
        QMessageBox::information(this, "Error", "Los Datos son Erróneos o estan incompletos..!");
        return;
    }

    this->m_persona = new Persona(nombre, apellido, telefono, email);
    accept();
}

void PersonaDialog::on_buttonBox_rejected()
{
    reject();
}

bool PersonaDialog::v_telf(QString telefono)
{
    if(telefono.isEmpty()){
        return false;
    }
    QRegExp tef ("\(09|9)?[ -]*([0-9])[ -]*([0-9][ -]*){7}");
    return tef.exactMatch(telefono);

}

bool PersonaDialog::v_nomap(QString nomap)
{
    if(nomap.isEmpty()){
        return false;
    }
    QRegExp na ("^[A-Za-z]+$");
    return na.exactMatch(nomap);
}

bool PersonaDialog::v_email(QString email)
{
    if(email.isEmpty()){
        return false;
    }

      QRegExp eml ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
      return eml.exactMatch(email);
}


Persona *PersonaDialog::persona() const
{
    return m_persona;
}
