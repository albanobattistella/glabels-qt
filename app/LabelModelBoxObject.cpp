/*  LabelModelBoxObject.cpp
 *
 *  Copyright (C) 2013  Jim Evins <evins@snaught.com>
 *
 *  This file is part of gLabels-qt.
 *
 *  gLabels-qt is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gLabels-qt is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with gLabels-qt.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "LabelModelBoxObject.h"

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>


namespace glabels
{

	LabelModelBoxObject::LabelModelBoxObject( QObject* parent ) : LabelModelObject(parent)
	{
		/* TODO: initialize default line and fill poperties.  */
	}


	LabelModelBoxObject::~LabelModelBoxObject()
	{
	}


	double LabelModelBoxObject::lineWidth( void ) const
	{
		return mLineWidth;
	}


	void LabelModelBoxObject::setLineWidth( double value )
	{
		if ( mLineWidth != value )
		{
			mLineWidth = value;
			emit changed();
		}
	}


	ColorNode LabelModelBoxObject::lineColorNode( void ) const
	{
		return mLineColorNode;
	}


	void LabelModelBoxObject::setLineColorNode( const ColorNode& value )
	{
		if ( mLineColorNode != value )
		{
			mLineColorNode = value;
			emit changed();
		}
	}
		

	ColorNode LabelModelBoxObject::fillColorNode( void ) const
	{
		return mFillColorNode;
	}


	void LabelModelBoxObject::setFillColorNode( const ColorNode& value )
	{
		if ( mFillColorNode != value )
		{
			mFillColorNode = value;
			emit changed();
		}
	}
		

	bool LabelModelBoxObject::canFill()
	{
		return true;
	}


	bool LabelModelBoxObject::canLineColor()
	{
		return true;
	}


	bool LabelModelBoxObject::canLineWidth()
	{
		return true;
	}


	// Create QGraphicsItem suitable for representing this object
	QGraphicsItem* LabelModelBoxObject::createGraphicsItem()
	{
		QGraphicsRectItem *rectItem = new QGraphicsRectItem( x0(), y0(), w(), h() );

		QBrush brush( fillColorNode().color() );
		rectItem->setBrush( brush );

		QPen pen( lineColorNode().color() );
		pen.setJoinStyle( Qt::MiterJoin );
		pen.setWidthF( lineWidth() );
		rectItem->setPen( pen );

		updateGraphicsItemMatrix( rectItem );
		updateGraphicsItemShadow( rectItem );

		return rectItem;
	}


	// Update a QGraphicsItem to keep it in sync with this object
	void LabelModelBoxObject::updateGraphicsItem( QGraphicsItem* graphicsItem )
	{
		QGraphicsRectItem *rectItem = dynamic_cast<QGraphicsRectItem*>(graphicsItem);
		if ( rectItem )
		{
			rectItem->setRect( x0(), y0(), w(), h() );

			QBrush brush( fillColorNode().color() );
			rectItem->setBrush( brush );

			QPen pen( lineColorNode().color() );
			pen.setJoinStyle( Qt::MiterJoin );
			pen.setWidthF( lineWidth() );
			rectItem->setPen( pen );

			updateGraphicsItemMatrix( rectItem );
			updateGraphicsItemShadow( rectItem );
		}
	}

}
