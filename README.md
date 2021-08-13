# Gardens of Kadesh
Gardens of Kadesh is a [WebAssembly] port of [HomeworldSDL]. [HomeworldSDL] is an [SDL] port of the [Homeworld] source code that was [released in 2003] by [Relic Entertainment].

![gameplay gif](media/screenshot_01.jpg)

### How to play
[To play direcly in your browser click here](https://gardensofkadesh.github.io/)


### About
Our goals are to continue modernizing the Homeworld engine with gentle touches while preserving the original gameplay and feel. To make the Homeworld 1 experience widely accessible on modern devices and to new generations of players.

![gameplay gif](media/gameplay_01.gif)

In addition we hope to achieve awareness for the source code situation of Homeworld 1. The Homeworld source code was released under an unfavorable Relic Developer Network License.
The disappearance of the Relic Developer Network and the Homeworld IP having changed hands leaves the license state of the Homeworld source code in a dubious state that hinders development.
We aim to achieve a consideration for a re-releasing of the original Homeworld source code under GPL2/3 or re-licensing the current GardenOfKadesh/Homeworld code under GPL2/3.

If you can help us in any way, or get back to us in support, please get in touch.
Follow our project here on [github](https://github.com/GardensOfKadesh) and/or joins us on our [discord](https://discord.gg/tpBKaHVV).

### Changelog
To see changes between versions take a look at the [changelog](changelog.md).

## Building
### Homeworld demo assets
This repository contains only the source code for Homeworld's engine (metaphorically, the skeleton). In order to have a playable game, you will need the original assets (artwork, textures, sounds, meshes, ... Metaphorically again, the flesh).

The following asset files are required to build Gardens of Kadesh based on the Homeworld demo:
- HomeworldDL.big (from the [Homeworld demo])
- DL_demo.vce (from the [Homeworld demo])
- DL_Music.wxd (from the [Homeworld demo])
- Update.big (from the [Homeworld 1.05 Patch])
- HomeworldSDL.big (see [HomeworldSDL] how to build this manually)

All the above demo assets can also be downloaded here (TODO). Alternatively wine can be used to extract them from the windows installers. See [HomeworldSDL] on how to do that.


### Build requirements
To build Gardens of Kadesh based on the Homeworld demo under linux the following preparations are required:

- copy all the above listed asset files into the wasm/ folder of the repository
- install [emscripten] with a version >= 2.0.25 (Older versions don't include the necessary improvements to the legacy OpenGL emulation layer)

### Building process
To setup [emscripten] switch to your [emscripten] installation folder and run:
``` sh
source emsdk_env.sh
```

To run the Gardens of Kadesh build process switch to the wasm/ folder of its repository and run:
``` sh
make clean
make
```

To increase build speed add "-jX" to enable parallel building. Replace the X with the number of threads your processor has.

Make sure to issue a "make clean" after changes to the code since the Makefile is currently not properly setup to track all changes automatically.

### Running locally
The finished build can be tested locally in a browser by running:
``` sh
emrun www/index.html
```

## Media

![gameplay gif](media/screenshot_02.jpg)







[Discord]: https://discord.gg/tpBKaHVV
[Homeworld]: https://en.wikipedia.org/wiki/Homeworld
[HomeworldSDL]: https://github.com/HomeworldSDL/HomeworldSDL
[SDL]: https://en.wikipedia.org/wiki/Simple_DirectMedia_Layer
[WebAssembly]: https://webassembly.org/
[emscripten]: https://emscripten.org

[released in 2003]: http://www.insidemacgames.com/news/story.php?ArticleID=8516
[Relic Entertainment]: https://www.relic.com/

[Homeworld demo]: https://www.moddb.com/games/homeworld/downloads/homeworld-demo
[Homeworld 1.05 Patch]: http://www.homeworldaccess.net/downloads/hw1patch/si_homeworld_update_105.exe
