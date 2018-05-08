// RTKBASE is a GUI interface for RTKLIB made for the Raspberry pî and a touchscreen
//   Copyright (C) 2016
//   David ENSG PPMD-2016 (first rtkbase release)
//   Francklin N'guyen van <francklin2@wanadoo.fr>
//   Sylvain Poulain <sylvain.poulain@giscan.com>
//   Vladimir ENSG PPMD-2017 (editable configuration)
//   Saif Aati ENSG PPMD-2018 (post processing)
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.


#include"mymessagehandler.h"



void myMsgHandler(QtMsgType type, const char *msg)
{
    /*-----------------------------------------------------------------------------/
        - qInstallMessageHandler :Function that prints out debug messages,
        warnings, critical and fatal error messages
        - create a logfille in the work directory
    /-----------------------------------------------------------------------------*/

    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
    break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
    break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
    break;
    }
    QFile outFile("../work/Log_file.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt << endl;
}
