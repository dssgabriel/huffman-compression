#include "MainWindow.hpp"



MainWindow::MainWindow()

{
 
layout = new QGridLayout();
			setLayout(layout);
			
			
			wMenu = new MainMenu();
			wMenu->show();
			layout->addWidget(wMenu,0,0);
			
			
			affiche = new Affichage();
			affiche->show();
		 
			
			zoneArbre = new QScrollArea();
			zoneArbre->setWidget(affiche);
			zoneArbre->show();
			layout->addWidget(zoneArbre,1,0);
			
			saisie = new QLineEdit();
			saisie->show();
			layout->addWidget(saisie);
			
			 
			
			//QMessageBox::critical(saisie, tr("Message"), tr("Erreur de Saisie !"));
			
			
			connect(saisie, SIGNAL(returnPressed()), this, SLOT(QMessageBox()));

	
			
			
			
}
			
		
