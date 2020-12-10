#pragma once
#include <iostream>
#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QGridLayout>
#include "MainMenu.hpp"
#include "Affichage.hpp"
#include <QtGui/QScrollArea>
#include <QtGui/QMessageBox>
#include <QtGui/QLineEdit>



  
  

class MainWindow : public QWidget 
{	Q_OBJECT
	
	private : 
	 
	 MainMenu* wMenu; 
	 
	 QGridLayout* layout;
	 
	 Affichage* affiche;
	 
	 QScrollArea* zoneArbre;
	 
	 QMessageBox* message;
	 
	 QLineEdit* saisie;
		
	
	public : 
		MainWindow();
		
		
	
};
