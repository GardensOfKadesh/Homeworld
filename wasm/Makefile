GIT_VERSION = `git config --get remote.origin.url | sed -r 's/.*(\@|\/\/)(.*)(\:|\/)([^:\/]*)\/([^\/\.]*)\.git/https:\/\/\2\/\4\/\5/'` `git describe --always --dirty`

JPG_MODULES = interfce.c \
              jaricom.c jcapimin.c jcapistd.c jcarith.c jccoefct.c jccolor.c \
              jcdctmgr.c jchuff.c jcinit.c jcmainct.c jcmarker.c jcmaster.c \
              jcomapi.c jcparam.c jcprepct.c jcsample.c jctrans.c jdapimin.c \
              jdapistd.c jdarith.c jdatadst.c jdatasrc.c jdcoefct.c jdcolor.c \
              jddctmgr.c jdhuff.c jdinput.c jdmainct.c jdmarker.c jdmaster.c \
              jdmerge.c jdpostct.c jdsample.c jdtrans.c jerror.c jfdctflt.c \
              jfdctfst.c jfdctint.c jidctflt.c jidctfst.c jidctint.c jquant1.c \
              jquant2.c jutils.c jmemmgr.c jmemnobs.c

SRCDIR = ../src
MODULES = $(wildcard $(SRCDIR)/SDL/*.c) \
          $(wildcard $(SRCDIR)/Game/*.c) \
          $(wildcard $(SRCDIR)/Ships/*.c) \
          $(wildcard $(SRCDIR)/../Linux/src/Missions/Generated/*.c) \
          $(JPG_MODULES:%=$(SRCDIR)/ThirdParty/JPG/%) \
          $(SRCDIR)/ThirdParty/CRC/CRC32.c \
          $(wildcard $(SRCDIR)/ThirdParty/LZSS/*.c) \


# prepare buttons for plugscreen
# convert Discord-Logo-White.png -resize 32x32\! -background black -flatten -brightness-contrast 0x0 button-discord-on.jpg
# convert Discord-Logo-White.png -resize 32x32\! -background black -flatten -brightness-contrast -50x0 button-discord-off.jpg

#ASSETS = HW_Music.wxd HW_Comp.vce Homeworld.big Update.big HomeworldSDL.big

# for Homeworld Demo
ASSETS = DL_Music.wxd DL_demo.vce HomeworldDL.big Update.big HomeworldSDL.big Plugscreens/
# for Homeworld Release, plug.tga missing from remastered homeworld.big
#ASSETS = Update.big HomeworldSDL.big Plugscreens/ plug.tga

UNAME = $(shell uname -s)
BUILDDIR = build
BINDIR = bin
WWWDIR = www
_MKDIRS := $(shell mkdir -p $(BINDIR) $(WWWDIR) $(BUILDDIR))


# -DHW_GAME_HOMEWORLD
# -DHW_GAME_DEMO
# -DHW_BUILD_FOR_DISTRIBUTION
# -DHW_BUILD_FOR_DEBUGGING

COMMONFLAGS = -MMD \
              -MP \
              -DHW_GAME_DEMO \
              -DHW_BUILD_FOR_DISTRIBUTION \
              -DGENERIC_ETGCALLFUNCTION \
              -D_LINUX_FIX_ME \
              -Dlinux \
              -DSTDC_HEADERS \
              -DGIT_VERSION="\"$(GIT_VERSION)\"" \
              -I ../Linux/src/Missions/ \
              -I ../src/Game/ \
              -I ../src/Ships/ \
              -I ../src/Game/ \
              -I ../src/SDL/ \
              -I ../src/ThirdParty/CRC/ \
              -I ../src/ThirdParty/LZSS/ \
              -I ../src/ThirdParty/Titan/ \
              -I ../src/ThirdParty/JPG/

EMXX = emcc

# -msimd128 for enabling WASM SIMD extension and llvm autovectorization, measure performance?!
# add -flto to EMXXFLAGS for link time optimization, for dev work it takes quite long
# CRASH ON CAPTURE WITH SALVAGE CORVETTE
#EMXXFLAGS = $(COMMONFLAGS) -O3 -flto -s USE_SDL=2 -s USE_SDL_IMAGE=2 -Wno-invalid-source-encoding
#EMXXLINK = -O3 --use-preload-plugins -s TOTAL_MEMORY=50331648 -s ALLOW_MEMORY_GROWTH=1 -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s LEGACY_GL_EMULATION=1 -lidbfs.js
# for dev/debugging
EMXXFLAGS = $(COMMONFLAGS) -O2 -g --profiling  -s USE_SDL=2 -s USE_SDL_IMAGE=2 -Wno-invalid-source-encoding
EMXXLINK = -O2 -g --profiling --use-preload-plugins -s TOTAL_MEMORY=50331648 -s ALLOW_MEMORY_GROWTH=1 -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s LEGACY_GL_EMULATION=1 -lidbfs.js





all: $(WWWDIR)

$(WWWDIR): $(WWWDIR)/hw.html $(WWWDIR)/index.html $(WWWDIR)/favicon.png

$(WWWDIR)/index.html: hwfs.html
	cp hwfs.html $(dir $@)index.html

$(WWWDIR)/favicon.png: 1.png
	cp 1.png $(dir $@)favicon.png


$(WWWDIR)/hw.html: $(MODULES:%=$(BUILDDIR)/%.em.o) $(ASSETS) Makefile
	$(EMXX) $(EMXXLINK) $(filter %.o,$^) $(ASSETS:%=--preload-file %) -o $@

$(BUILDDIR)/%.em.o: % Makefile
	@mkdir -p $(dir $@)
	@echo $(EMXX) -c $< -o $@
	@$(EMXX) $(EMXXFLAGS) -c $< -o $@ #--emrun

clean:
	rm -rf $(BUILDDIR)/* $(BINDIR)/* $(WWWDIR)/* Linux/* src/*
