/*  ColorNode.cpp
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

#include "ColorNode.h"


namespace glabels
{

	ColorNode::ColorNode()
		: mFieldFlag(false), mColor(QColor::fromRgba(0x00000000)), mKey("")
	{
	}


	ColorNode::ColorNode( bool fieldFlag, const QColor& color, const QString& key )
		: mFieldFlag(fieldFlag), mColor(color), mKey(key)
	{
	}


	ColorNode::ColorNode( const QColor& color )
		: mFieldFlag(false), mColor(color), mKey("")
	{
	}


	ColorNode::ColorNode( const QString& key )
		: mFieldFlag(true), mColor(QColor::fromRgba(0x00000000)), mKey(key)
	{
	}


	bool ColorNode::operator==( const ColorNode& cn )
	{
		return ( (mFieldFlag == cn.mFieldFlag) &&
			 (mColor     == cn.mColor)     &&
			 (mKey       == cn.mKey) );
	}


	bool ColorNode::operator!=( const ColorNode& cn )
	{
		return ( (mFieldFlag != cn.mFieldFlag) ||
			 (mColor     != cn.mColor)     ||
			 (mKey       != cn.mKey) );
	}


#if TODO
	QColor ColorNode::expand( MergeRecord? record )
	{
		if ( fieldFlag )
		{
			if ( record == null )
			{
				return QColor.fromRgba(0x00000000);
			}
			else
			{
				string? text = record.evalKey( key );
				if ( text != null )
				{
					Gdk.Color gdkColor = Gdk.Color();
					if ( Gdk.Color.parse( text, out gdkColor ) )
					{
						Color color = Color.from_gdkColor( gdkColor );
						return color;
					}
					else
					{
						return Color.fromRgba(0x00000000);
					}
				}
				else
				{
					return Color.fromRgba(0x00000000);
				}
			}
		}
		else
		{
			return color;
		}
	}
#endif


	bool ColorNode::fieldFlag( void ) const
	{
		return mFieldFlag;
	}
		

	const QColor& ColorNode::color( void ) const
	{
		return mColor;
	}
		

	const QString& ColorNode::key( void ) const
	{
		return mKey;
	}
		
}

