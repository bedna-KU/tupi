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

#include "ktcomunicationparser.h"

struct KTComunicationParser::Private
{
    QString message;
    QString login;
};

KTComunicationParser::KTComunicationParser() : KTXmlParserBase(), k(new Private())
{
    
}

KTComunicationParser::~KTComunicationParser()
{
    
}

bool KTComunicationParser::startTag(const QString &tag, const QXmlAttributes &atts)
{
    if (root() == "communication_chat" || root() == "communication_notice" || root() == "communication_wall") {
        if (tag == "message") {
            k->message = atts.value("text");
            k->login = atts.value("from");
        }
    }
    
    return true;
}

bool KTComunicationParser::endTag(const QString &)
{
    return true;
}

void KTComunicationParser::text(const QString &)
{
}

QString KTComunicationParser::message() const
{
    return k->message;
}

QString KTComunicationParser::login() const
{
    return k->login;
}
