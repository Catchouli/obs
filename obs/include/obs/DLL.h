#pragma once

/*
*   This file is included in files which wish to export or import to or from a DLL.
*   To use it, simply #include the file and include OBS_API in your prototypes.
*   When compiling a dll, _WINDLL should be defined
*/
#if defined(_MSC_VER)
#   if defined(_WINDLL)
#       define OBS_API __declspec(dllexport)
#   else
#       define OBS_API __declspec(dllimport)
#   endif
#else
#   define OBS_API
#endif