#ifndef _PROJECT_CONFIG_H_
#define _PROJECT_CONFIG_H_

#ifdef AC_DEBUG
#define AC_DEBUGONLY(x) x
#else
#define AC_DEBUGONLY(x)
#endif // AC_DEBUG

#define meteor_MATH_ENABLE

#define PROJECT_PARENT_DIR_NAME "meteorengine"

#endif // !_PROJECT_CONFIG_H_
