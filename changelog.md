This document describes changes between tagged Gardens of Kadesh versions.

Not all changes are tracked here but it's recommended to add important changes
as part of pull requests. To get a full picture of all changes between
versions, you can browse git to display all changes between tags.


## Current Trunk


## r6
#### Bugfix
- half the strength of the non-linear inverse perspective scaling (N-LIPS) now also for engine trails


## r5
#### Improvements
- update readme.md for Gardens of Kadesh
- add changelog.md for tracking changes between versions
- add "this may take a while" to download status text and enable showing it
- additional screenshots added to media
- add resolution change support to plugscreens


## r4
#### Bugfixes
- fix skirmish resource injection timer
- increase task timer prevision to get correct universe update timing


## r3
#### Bugfixes
- make favicon work


## r2
#### Improvements
- change SDL window title
- add favicon


## r1
#### Improvements
- increased universe update rate for smoother movement
- dithering for vertex backgrounds to prevent color banding
- enable anisotropic texture filtering for reduced flickering
- severe reduction of opengl draw calls for improved performance
- various opengl improvements for better compatibility and performance
- extended the plugscreen system to display static text, load jpg buttons and have functional links
- force LOD system to highest level
- half the strength of the non-linear inverse perspective scaling (N-LIPS)

#### Unfortunate side effects
- force single threading for webassembly compatibility (prob. breaking multiplayer)

#### Bugfixes
- various fixes and improvements to the generic ETG function system
- various fixes to enable correct rendering with emscripten legacy opengl emulation
- various fixes to improve compiler and cross platform compatibility
- fixed right click menu artifact appearing on high resolutions
- fixed out of bounds error when compiling HW demo target
- fixed mission 3 state machine issue


## pre r1
- please see previous HomeworldSDL commits/releases
