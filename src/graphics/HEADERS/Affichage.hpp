#pragma once 
#include <QtGui/QApplication>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QPainter>
#include <QGraphicsItem>





class Affichage : public QFrame
{
	
	private : 
	QLabel* Arbre;  
	
	
	
	public : 
	
	Affichage() 
	{
		setFixedSize(500,500);
	
	}
	
	void paintEvent(QPaintEvent* e)
	{	
		QWidget::paintEvent(e);
	    
		QPainter paint(this);
		
	
		
		
		
		
		
		
	}
     
};
