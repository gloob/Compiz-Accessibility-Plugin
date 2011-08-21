/*
 * Compiz Accessibility PLugin
 *
 * Copyright (c) 2011 F123 Consulting & Mais Diferenças
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Author: Alejandro Leiva <aleiva@emergya.com>
 *
 */

#ifndef _ACCESSIBILITY_H
#define _ACCESSIBILITY_H

typedef boost::function<int (const char *)> AtspiEventCallback;

typedef int AtspiEventHandler;

/* Struct of a handler and list of handlers */
struct AtspiHandler {
    const char *        event_type;
    AtspiEventCallback  cb;
    AtspiEventHandler   id;
};

typedef std::list<AtspiHandler *> AtspiHandlerList;


class Accessibility
{
    public:

        AtspiHandlerList list;

    public:

        Accessibility ();
        ~Accessibility ();

        AtspiEventHandler
        registerEventHandler (const char * event_type, AtspiEventCallback cb);
        
        void
        unregisterEventHandler (AtspiEventHandler handler);

        bool
        unregisterByType (const char * event_type);

};      

#endif // _ACCESSIBILITY_H