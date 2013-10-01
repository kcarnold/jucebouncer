/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-11 by Raw Material Software Ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the GNU General
   Public License (Version 2), as published by the Free Software Foundation.
   A copy of the license is included in the JUCE distribution, or can be found
   online at www.gnu.org/licenses.

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

  ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.rawmaterialsoftware.com/juce for more information.

  ==============================================================================
*/

//==============================================================================
WebOutputStream::WebOutputStream (struct mg_connection *conn, const int bufferSize_)
    : conn(conn),
      bufferSize (bufferSize_),
      bytesInBuffer (0),
      buffer ((size_t) jmax (bufferSize_, 16))
{
}

WebOutputStream::~WebOutputStream()
{
    flushBuffer();
    mg_write(conn, "0\r\n\r\n", 5);
}


bool WebOutputStream::flushBuffer()
{
	return true;
}

void WebOutputStream::flush()
{
    flushBuffer();
}

bool WebOutputStream::write (const void* const src, const size_t numBytes)
{
    jassert (src != nullptr && ((ssize_t) numBytes) >= 0);
	return writeInternal(src, numBytes) > 0;
}

void WebOutputStream::writeRepeatedByte (uint8 byte, size_t numBytes)
{
    jassert (((ssize_t) numBytes) >= 0);
	OutputStream::writeRepeatedByte (byte, numBytes);
}

ssize_t WebOutputStream::writeInternal (const void* buf, size_t size) {
	mg_printf(conn, "%zX\r\n", size);
	mg_write(conn, buf, size);
	mg_printf(conn, "\r\n");
	return size;
}
