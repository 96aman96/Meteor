#ifndef _PLATFORM_LINUX_H_
#define _PLATFORM_LINUX_H_

#include "Platform/Types/Types.h"

extern meteor::int32 meteorMain(meteor::int32 argc, const meteor::string argv); // cannot link even after the actual definition is right above in MainEngine.cpp

meteor::int32 main(meteor::int32 argc, char** argv)
{
    using namespace meteor;

    const string commandLine(*argv);
    // pass it to main params or whatever
    
    // TODO: Find the source dir somehow

    meteorMain(argc, commandLine);
}

#endif // !_PLATFORM_LINUX_H_
