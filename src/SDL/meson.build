src_sdl = files(
    'NetworkInterface.c',
    'Queue.c',
    'TimeoutTimer.c',
    'Titan.c',
    'TitanInterfaceC.c',
    'avi.c',
    'font.c',
    'main.c',
    'mainrgn.c',
    'mixfft.c',
    'mouse.c',
    'prim2d.c',
    'prim3d.c',
    'render.c',
    'rglu.c',
    'rinit.c',
    'screenshot.c',
    'smixer.c',
    'soundlow.c',
    'sstream.c',
    'texreg.c',
    'utility.c',
)

src_sdl += files(
    'dct.c',
    'fqcodec.c',
    'fqeffect.c',
    'fquant.c',
)

lib_sdl = static_library(
    'hw_sdl',
    src_sdl,
    c_args: c_args + [f'-DHOMEWORLD_BUILD_VERSION="@build_version@"'],
    dependencies: base_deps,
    include_directories: ['../Game', '../Ships', '../ThirdParty/CRC', '../ThirdParty/stb'],
)

inc_src_sdl = include_directories('.')