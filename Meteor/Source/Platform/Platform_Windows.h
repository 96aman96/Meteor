#ifndef _PLATFORM_WINDOWS_H_
#define _PLATFORM_WINDOWS_H_

// Including SDKDDKVer.h defines the highest available Windows platform.
// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.
#include <SDKDDKVer.h>

#include <windows.h>
#include <cstdlib> // for calloc and free
#include <vector>
#include <cassert>
#include <boost/algorithm/string.hpp> // for split

#include "Platform/Types/Types.h"
#include "Platform/Assertion.h"
#include "Framework/AppContext.h"

extern meteor::int32 meteorMain(meteor::int32 argc, const meteor::string argv); // cannot link even after the actual definition is right above in MainEngine.cpp

// Entry Point For Windows
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, meteor::int32 nShowCmd)
{
    using namespace meteor;

    const string argv(lpCmdLine);
    string sourceDirPath;
    string dataDirPath;
    auto setDirPaths = [&sourceDirPath, &dataDirPath]()
    {
        const auto hModule = GetModuleHandle(NULL); // Get handle to current module
        const DWORD pathLength = 180;

        char* outStr = static_cast<char*>(std::calloc(pathLength, sizeof(char)));

        if (::GetModuleFileNameA(hModule, outStr, pathLength))
        {
            string outputString(outStr);
            std::free(outStr);

            const string parentDirName(PROJECT_PARENT_DIR_NAME);
            const string sourceDir("\\meteor\\Source\\");
            const string dataDir("\\meteor\\Data\\");

            const size_t pos = outputString.find(parentDirName);
            outputString = outputString.substr(0, pos + parentDirName.length());

            sourceDirPath = outputString + sourceDir;
            sourceDirPath.shrink_to_fit();

            dataDirPath = outputString + dataDir;
            dataDirPath.shrink_to_fit();
        }
        return string("");
    }();

    Assert(!sourceDirPath.empty(), "Cannot find Source directory.");
    Assert(!dataDirPath.empty(), "Cannot find Data directory.");
    AppContext::SetSourceDirPath(sourceDirPath);
    AppContext::SetDataDirPath(dataDirPath);

    const int32 argc = [](const string& argv)
    {
        std::vector<string> splitUpString = {};
        boost::split(splitUpString, argv, [](char ch) { return ch == '-'; });
        return static_cast<int32>(splitUpString.size() - 1);
    }(argv);


    // set the source dir path in app context
    MainParams params{ hInstance, hPrevInstance, argc, argv, nShowCmd };
    AppContext::SetMainParams(params);

    // call meteorMain()
    meteorMain(argc, argv);
}

#endif // !_PLATFORM_WINDOWS_H_