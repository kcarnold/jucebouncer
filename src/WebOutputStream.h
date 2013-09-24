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

#include "../streams/juce_OutputStream.h"


//==============================================================================
/**
    An output stream that writes into a local file.

    @see OutputStream, FileInputStream, File::createOutputStream
*/
class JUCE_API  WebOutputStream  : public OutputStream
{
public:
    //==============================================================================
    /** Creates a WebOutputStream.

        If the file doesn't exist, it will first be created. If the file can't be
        created or opened, the failedToOpen() method will return
        true.

        If the file already exists when opened, the stream's write-postion will
        be set to the end of the file. To overwrite an existing file,
        use File::deleteFile() before opening the stream, or use setPosition(0)
        after it's opened (although this won't truncate the file).

        @see TemporaryFile
    */
    WebOutputStream (struct mg_connection *conn,
                      int bufferSizeToUse = 16384);

    /** Destructor. */
    ~WebOutputStream();

    bool write (const void* data, size_t numBytes);
    void writeRepeatedByte (uint8 byte, size_t numTimesToRepeat);


private:
    //==============================================================================
    struct mg_connection *conn;
    size_t bufferSize, bytesInBuffer;
    HeapBlock <char> buffer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WebOutputStream)
};

#endif   // __JUCE_WebOUTPUTSTREAM_JUCEHEADER__
