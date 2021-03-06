#ifndef _ENUM_HELPERS_H_
#define _ENUM_HELPERS_H_

#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <cstdint>
#include <vector>

#include "Platform/Types/Types.h"

using namespace meteor;

#define ENUM_VAL_TO_STRING(r, data, elem) BOOST_PP_STRINGIZE(elem),

/*
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
String Enum Class : Generates a string vector with the stringified values of the 16bit unsigned integer type Enum
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

Usage: DECLARE_STRING_ENUM(Color, (Red)(Green)(Blue);

Code Generated:
enum class Color : uint16_t
{
    Red,
    Green,
    Blue,
};

std::vector<string> Color_Strings =
{
    "Red",
    "Green",
    "Blue",
};

string Color_GetName(Color enumVal) { return Color_Strings[static_cast<uint16_t>(enumVal)]; }

--------------------------------------------------------------------------------
Note: Use the Static Macro for Static String Vector
--------------------------------------------------------------------------------
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*/

#define DECLARE_STRING_ENUM(EnumName, EnumValues)\
    enum class EnumName : uint16\
    {\
        BOOST_PP_SEQ_ENUM(EnumValues)\
    };\
    std::vector<string> EnumName##_Strings = \
    {\
        BOOST_PP_SEQ_FOR_EACH(ENUM_VAL_TO_STRING, EnumName, EnumValues) \
    };\
    static string EnumName##_GetName(EnumName enumVal) { return EnumName##_Strings[static_cast<uint16>(enumVal)]; } \

#define DECLARE_STATIC_STRING_ENUM(EnumName, EnumValues)\
    enum class EnumName : uint16\
    {\
        BOOST_PP_SEQ_ENUM(EnumValues)\
    };\
    static std::vector<string> EnumName##_Strings = \
    {\
        BOOST_PP_SEQ_FOR_EACH(ENUM_VAL_TO_STRING, EnumName, EnumValues) \
    };\
    static string EnumName##_GetName(EnumName enumVal) { return EnumName##_Strings[static_cast<uint16>(enumVal)]; } \

#define DECLARE_STATIC_INLINE_STRING_ENUM(EnumName, EnumValues)\
    enum class EnumName : uint16\
    {\
        BOOST_PP_SEQ_ENUM(EnumValues)\
    };\
    inline static std::vector<string> EnumName##_Strings = \
    {\
        BOOST_PP_SEQ_FOR_EACH(ENUM_VAL_TO_STRING, EnumName, EnumValues) \
    };\
    inline static string EnumName##_GetName(EnumName enumVal) { return EnumName##_Strings[static_cast<uint16>(enumVal)]; } \

/*
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Explicit Typed String Enum Class : Generates a string vector with the stringified values of the explicity typed enum class
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

Usage: DECLARE_EXPLICIT_TYPE_STRING_ENUM(uint32_t, Color, (Red)(Green)(Blue);

Code Generated:
enum class Color : uint32_t
{
    Red,
    Green,
    Blue,
};

std::vector<string> Color_Strings =
{
    "Red",
    "Green",
    "Blue",
};

string Color_GetName(Color enumVal) { return Color_Strings[static_cast<uint32_t>(enumVal)]; }
--------------------------------------------------------------------------------
Note: Use the Static Macro for Static String Vector
--------------------------------------------------------------------------------
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*/

#define DECLARE_EXPLICIT_TYPE_STRING_ENUM(EnumType, EnumName, EnumValues)\
    enum class EnumName : EnumType\
    {\
        BOOST_PP_SEQ_ENUM(EnumValues)\
    };\
    std::vector<string> EnumName##_Strings = \
    {\
        BOOST_PP_SEQ_FOR_EACH(ENUM_VAL_TO_STRING, EnumName, EnumValues) \
    };\
    static string EnumName##_GetName(EnumName enumVal) { return EnumName##_Strings[static_cast<EnumType>(enumVal)]; } \

#define DECLARE_EXPLICIT_TYPE_STATIC_STRING_ENUM(EnumType, EnumName, EnumValues)\
    enum class EnumName : EnumType\
    {\
        BOOST_PP_SEQ_ENUM(EnumValues)\
    };\
    static std::vector<string> EnumName##_Strings = \
    {\
        BOOST_PP_SEQ_FOR_EACH(ENUM_VAL_TO_STRING, EnumName, EnumValues) \
    };\
    static string EnumName##_GetName(EnumName enumVal) { return EnumName##_Strings[static_cast<EnumType>(enumVal)]; } \

#define DECLARE_EXPLICIT_TYPE_STATIC_INLINE_STRING_ENUM(EnumType, EnumName, EnumValues)\
    enum class EnumName : EnumType\
    {\
        BOOST_PP_SEQ_ENUM(EnumValues)\
    };\
    inline static std::vector<string> EnumName##_Strings = \
    {\
        BOOST_PP_SEQ_FOR_EACH(ENUM_VAL_TO_STRING, EnumName, EnumValues) \
    };\
    inline static string EnumName##_GetName(EnumName enumVal) { return EnumName##_Strings[static_cast<EnumType>(enumVal)]; } \


#endif // _ENUM_HELPERS_H_
