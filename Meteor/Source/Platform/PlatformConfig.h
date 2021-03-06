#ifndef _PLATFORM_CONFIG_H_
#define _PLATFORM_CONFIG_H_

#ifdef PLATFORM_WINDOWS
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif // !WIN32_LEAN_AND_MEAN

#ifndef USE_PIX
#define USE_PIX
#endif // !USE_PIX

#ifndef NOMINMAX
#define NOMINMAX
#endif // !NOMINMAX
#endif // PLATFORM_WINDOWS

#ifdef PLATFORM_WINDOWS
#define WINDOWS_ONLY(x) x
#else
#define WINDOWS_ONLY(x) 
#endif // PLATFORM_WINDOWS

#ifdef PLATFORM_LINUX
#define LINUX_ONLY(x) x
#else
#define LINUX_ONLY(x) 
#endif //PLATFORM_LINUX

#define meteor_NAMESPACE_BEGIN namespace meteor {
#define meteor_NAMESPACE_END }

#endif // !_PLATFORM_CONFIG_H_
