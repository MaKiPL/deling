/****************************************************************************
 ** Deling Final Fantasy VIII Field Editor
 ** Copyright (C) 2009-2012 Arzel J�r�me <myst6re@gmail.com>
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
#ifndef DEF_BGPREVIEW
#define DEF_BGPREVIEW

#include <QtGui>
#include "BGPreview2.h"

class BGPreview : public QScrollArea
{
	Q_OBJECT
public:
	BGPreview(QWidget *parent=0);

	void clear();
public slots:
	void fill(const QPixmap &background);
signals:
	void triggered();
private:
	QLabel *label;
protected:
	void mouseReleaseEvent(QMouseEvent *);
};

#endif
