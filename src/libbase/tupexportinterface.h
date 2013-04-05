/***************************************************************************
 *   Project TUPI: Magia 2D                                                *
 *   Project Contact: info@maefloresta.com                                 *
 *   Project Website: http://www.maefloresta.com                           *
 *   Project Leader: Gustav Gonzalez <info@maefloresta.com>                *
 *                                                                         *
 *   Developers:                                                           *
 *   2010:                                                                 *
 *    Gustavo Gonzalez / xtingray                                          *
 *                                                                         *
 *   KTooN's versions:                                                     * 
 *                                                                         *
 *   2006:                                                                 *
 *    David Cuadrado                                                       *
 *    Jorge Cuadrado                                                       *
 *   2003:                                                                 *
 *    Fernado Roldan                                                       *
 *    Simena Dinas                                                         *
 *                                                                         *
 *   Copyright (C) 2010 Gustav Gonzalez - http://www.maefloresta.com       *
 *   License:                                                              *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#ifndef TupEXPORTINTERFACE_H
#define TupEXPORTINTERFACE_H

#include "tupscene.h"
#include "qplugin.h" // Q_EXPORT_PLUGIN

#include <QStringList>
#include <QDir>
#include <QColor>

/**
 * @author David Cuadrado
*/

class TUPI_EXPORT TupExportInterface
{
    public:
        enum Format 
             {
               NONE = 0,
               WEBM = 1 << 0,
               OGV  = 1 << 1,
               SWF  = 1 << 2,
               MPEG = 1 << 3,
               AVI  = 1 << 4,
               RM   = 1 << 5,
               ASF  = 1 << 6,
               MOV  = 1 << 7,
               GIF  = 1 << 8,
               PNG  = 1 << 9,
               JPEG = 1 << 10,
               XPM  = 1 << 11,
               SMIL = 1 << 12
             };

        Q_DECLARE_FLAGS(Formats, Format);

        virtual ~TupExportInterface() {};
        virtual QString key() const = 0;
        virtual Formats availableFormats() = 0;
        virtual bool exportToFormat(const QColor color, const QString &filePath, const QList<TupScene *> &scenes, Format format, const QSize &size, int fps) = 0;
        virtual bool exportFrame(int frameIndex, const QColor color, const QString &filePath, TupScene *scene, const QSize &size) = 0;
        virtual const char* getExceptionMsg() = 0;
};

        Q_DECLARE_OPERATORS_FOR_FLAGS(TupExportInterface::Formats);
        Q_DECLARE_INTERFACE(TupExportInterface, "com.maefloresta.tupi.ExportInterface/0.1");

#endif
