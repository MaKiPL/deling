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
#include "TimFile.h"

TimFile::TimFile() :
	_currentColorTable(0)
{
}

TimFile::TimFile(const QByteArray &data)
{
	TimFile::TimFile();
	open(data);
}

bool TimFile::open(const QByteArray &data)
{
//	QTime t;t.start();

	quint32 palSize=0, imgSize=0, color=0;
	quint16 w, h;
	const char *constData = data.constData();
	bool hasPal;
	int dataSize = data.size();
	QVector<QRgb> currentPal;

	if(!data.startsWith(QByteArray("\x10\x00\x00\x00", 4)) || dataSize < 8)		return false;

//	quint8 tag = (quint8)data.at(0);
//	quint8 version = (quint8)data.at(1);
	bpp = (quint8)data.at(4) & 3;
	hasPal = ((quint8)data.at(4) >> 3) & 1;

//	qDebug() << QString("=== Apercu TIM ===");
//	qDebug() << QString("Tag = %1, version = %2, reste = %3").arg(tag).arg(version).arg(QString(data.mid(2,2).toHex()));
//	qDebug() << QString("bpp = %1, hasPal = %2, flag = %3, reste = %4").arg(bpp).arg(hasPal).arg((quint8)data.at(4),0,2).arg(QString(data.mid(5,3).toHex()));

	if(hasPal && bpp > 1)
		return false;

	_colorTables.clear();

	if(hasPal)
	{
		if(dataSize < 20)
			return false;

		memcpy(&palSize, &constData[8], 4);
		memcpy(&palW, &constData[16], 2);
		memcpy(&palH, &constData[18], 2);
		if((quint32)dataSize < 8+palSize/* || palSize != (quint32)palW*palH*2+12*/)
			return false;

		quint16 onePalSize = (bpp==0 ? 16 : 256);
		int nbPal = (palSize-12)/(onePalSize*2);
		if((palSize-12)%(onePalSize*2) != 0)
		{
			nbPal *= 2;
		}
		if(nbPal > 0)
		{
			int pos=0;
			for(int i=0 ; i<nbPal ; ++i)
			{
				QVector<QRgb> pal;

				for(quint16 j=0 ; j<onePalSize ; ++j) {
					memcpy(&color, &constData[20+pos*2+j*2], 2);
					pal.append(qRgb((color & 31)*COEFF_COLOR, (color>>5 & 31)*COEFF_COLOR, (color>>10 & 31)*COEFF_COLOR));
				}

				_colorTables.append(pal);

				pos += pos % palW == 0 ? onePalSize : palW - onePalSize;
			}
		}
		else
		{
			return false;
		}

		currentPal = _colorTables.first();
		_currentColorTable = 0;

//		qDebug() << QString("-Palette-");
//		qDebug() << QString("Size = %1, w = %2, h = %3").arg(palSize).arg(palW).arg(palH);
//		qDebug() << QString("NbPal = %1 (valid : %2)").arg(nbPal).arg((palSize-12)%(onePalSize*2));
	}

	if((quint32)dataSize < 20+palSize)
		return false;

	memcpy(&imgSize, &constData[8+palSize], 4);
	memcpy(&w, &constData[16+palSize], 2);
	memcpy(&h, &constData[18+palSize], 2);
	if(bpp==0)		w*=4;
	else if(bpp==1)	w*=2;

//	qDebug() << QString("-Image-");
//	qDebug() << QString("Size = %1, w = %2, h = %3").arg(imgSize).arg(w).arg(h);
//	qDebug() << QString("TIM Size = %1").arg(8+palSize+imgSize);

	_image = QImage(w, h, QImage::Format_RGB32);
	QRgb *pixels = (QRgb *)_image.bits();

	int size, i=0;
	quint32 x=0, y=0;

	if(bpp!=0) {
		size = qMin((quint32)w*h*bpp, dataSize - 8 - palSize);
	} else {
		size = qMin((quint32)w/2*h, dataSize - 8 - palSize);
	}

	if(8 + palSize + size > (quint32)dataSize)
		return false;

	if(bpp==0)//mag176, icon
	{
		while(i<size)
		{
			if(!_image.valid(x, y))	break;

			pixels[x + y*w] = currentPal.at((quint8)data.at(20+palSize+i) & 0xF);
			++x;
			if(x==w)
			{
				x = 0;
				++y;
			}
			if(!_image.valid(x, y))	break;

			pixels[x + y*w] = currentPal.at((quint8)data.at(20+palSize+i) >> 4);
			++x;
			if(x==w)
			{
				x = 0;
				++y;
			}
			++i;
		}
	}
	else if(bpp==1)
	{
		while(i<size)
		{
			if(!_image.valid(x, y))	break;

			pixels[x + y*w] = currentPal.at((quint8)data.at(20+palSize+i));

			++x;
			if(x==w)
			{
				x = 0;
				++y;
			}
			++i;
		}
	}
	else if(bpp==2)
	{
		while(i<size)
		{
			if(!_image.valid(x, y))	break;

			memcpy(&color, &constData[20+palSize+i], 2);
			pixels[x + y*w] = qRgb((color & 31)*COEFF_COLOR, (color>>5 & 31)*COEFF_COLOR, (color>>10 & 31)*COEFF_COLOR);

			++x;
			if(x==w)
			{
				x = 0;
				++y;
			}
			i+=2;
		}
	}
	else if(bpp==3)
	{
		while(i<size)
		{
			if(!_image.valid(x, y))	break;

			memcpy(&color, &constData[20+palSize+i], 3);
			pixels[x + y*w] = qRgb(color >> 16, (color >> 8) & 0xFF, color & 0xFF);

			++x;
			if(x==w)
			{
				x = 0;
				++y;
			}
			i+=3;
		}
	}

//	qDebug() << t.elapsed();
	return true;
}

bool TimFile::save(QByteArray &data)
{
	bool hasPal = bpp <= 1;
	quint32 flag = (hasPal << 3) | (bpp & 3);

	// Header
	data.append("\x10\x00\x00\x00", 4);
	data.append((char *)&flag, 4);

	if(hasPal) {
		// TODO
	}

	return false;
}

const QImage &TimFile::image() const
{
	return _image;
}

int TimFile::currentColorTable() const
{
	return _currentColorTable;
}

QVector<QRgb> TimFile::colorTable(int id) const
{
	return _colorTables.value(id);
}

void TimFile::setCurrentColorTable(int id)
{
	if(id < _colorTables.size() && _currentColorTable != id) {
		_image.setColorTable(_colorTables.at(_currentColorTable = id));
	}
}

void TimFile::setColorTable(int id, const QVector<QRgb> &colorTable)
{
	if(id < _colorTables.size()) {
		_colorTables.replace(id, colorTable);
	}
}
