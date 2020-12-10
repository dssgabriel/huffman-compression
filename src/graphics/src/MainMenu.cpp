#include "MainMenu.hpp"


MainMenu::MainMenu()
{
			layout = new QHBoxLayout();
			setLayout(layout);
	
			
			afficher = new QPushButton("Arbre", this);
			afficher->show();
			layout->addWidget(afficher);
			
			
			prefixe = new QPushButton("Prefixe", this);
			prefixe->show();
			layout->addWidget(prefixe);
			
			
			
			infixe = new  QPushButton("Infixe", this);
			infixe->show();
			layout->addWidget(infixe);
			
			
			postfixe = new  QPushButton("Postfixe", this);
			postfixe->show();
			layout->addWidget(postfixe); 
			
			bQuitter = new QPushButton("Quitter", this);
			bQuitter->show();
			layout->addWidget(bQuitter);
			
			connect(bQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
			
			

			
			setFrameShape(Panel);
			
			setFrameShadow(Raised);
			
		};


