#ifndef _COMMAND_LINE_OPTIONS_H_
#define _COMMAND_LINE_OPTIONS_H_

namespace meteor
{
    struct CommandLineOptions
    {
        inline static bool                  shouldGenerateData = false;
        inline static string                dataFile = "";
    };
}

#endif // !_COMMAND_LINE_OPTIONS_H_
