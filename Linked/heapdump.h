/*
 * Interface of the ADT heapdump
 */

#ifdef _DEBUG				// Active only in Debug Configuration
#define _CRTDBG_MAP_ALLOC	// Visual Studio Mem Leak detector activated
#include <crtdbg.h>
#endif

void heapdump(void);
void heapleak(void);