#pragma once

#ifdef DE_DEBUG
#define DE_ENABLE_ASSERT
#endif

#ifdef  DE_ENABLE_ASSERT
#define DE_ASSERT(x, ...) { if(!(x)) { __debugbreak(); } }
#define DE_CORE_ASSERT(x, ...) { if(!(x)) { __debugbreak(); } }
#else
#define DE_ASSERT(X, ...)
#define DE_CORE_ASSERT(x, ...)
#endif