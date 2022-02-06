//
// Prefix header for all source files of the 'Homeworld' target in the 'Homeworld' project
//

#ifdef __OBJC__
	#import <Cocoa/Cocoa.h>
#endif

// __APPLE__     -         Mac-specific code (#define'd on gcc command line / target info in Xcode)
// __APPLE___86  -   Intel Mac-specific code
// __APPLE___PPC - PowerPC Mac-specific code

// FIX_ENDIAN  - use where data needs byte-swapping

// Code wrapped by the following #defines is defective and needs reimplementing
// at some point in order to fix it. Try and use a positive test where possible
// (e.g. #ifdef __APPLE___FIX_86) so that developers with skills in a particular
// area can more quickly target them.

// __APPLE___FIX_86    - use to mark problematic code on Intel Macs
// __APPLE___FIX_PPC   - use to mark problematic code on PowerPC Macs

// __APPLE___FIX_ANIM  - use to toggle animatic (movie) code
// __APPLE___FIX_GL    - use to toggle glcaps and other gl related code
// __APPLE___FIX_LAN   - use to toggle LAN related code
// __APPLE___FIX_MISC  - use to toggle control / memory / other issues
// __APPLE___FIX_SOUND - use to toggle sound code

#ifdef __APPLE__
#define GENERIC_ETGCALLFUNCTION
	#define __APPLE___FIX_ANIM 1
	//#define __APPLE___FIX_SOUND 1
	#define __APPLE___FIX_LAN 1
	//#define __APPLE___FIX_GL 1
	#define __APPLE___FIX_MISC 1
	//#ifndef __APPLE___FIX_ME
	//	#define __APPLE___FIX_ME 1
	//#endif
	#ifdef __ppc__
		#define __APPLE___PPC 1
        #define __APPLE___FIX_GL 1
		#define __APPLE___FIX_PPC 1
		#define __APPLE___FIX_SOUND 1
	#endif
	#ifdef __i386__
		#define __APPLE___86 1
		#define __APPLE___FIX_86 1
	#endif
#ifdef __x86_64__
  #define __APPLE___64 1
  #define __APPLE___FIX_64 1
  #define _X86_64 1
#endif
#endif
