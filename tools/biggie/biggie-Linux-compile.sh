#!/bin/sh
cc -o biggie -Wall -O2 -D_LINUX_FIX_ME -I../../src/ThirdParty/CRC \
        -I../../src/SDL \
	-I../../src/ThirdParty/LZSS `sdl2-config --cflags` \
	main.c options.c ../../src/Game/BigFile.c \
	../../Linux/src/ThirdParty/CRC/libhw_CRC.a \
	../../Linux/src/ThirdParty/LZSS/libhw_LZSS.a `sdl2-config --libs`
