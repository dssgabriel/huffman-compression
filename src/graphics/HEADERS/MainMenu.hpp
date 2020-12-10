#pragma once

#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QBoxLayout>
#include <QtGui/QFrame>  
#include <QtGui/QLineEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QMessageBox>



class MainMenu : public QFrame 
{	
	
	private : 
		QPushButton* bQuitter;
		QPushButton* prefixe;
		QPushButton* infixe;
		QPushButton* postfixe;
		QPushButton* afficher;
		
		QHBoxLayout* layout; 
		
		
		
		QGroupBox* groupbox;
		
		
		
	
	public : 
	
		MainMenu();
		
		
		
		
}	
;
