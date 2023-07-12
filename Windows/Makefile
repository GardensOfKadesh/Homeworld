GIT_VERSION = `git config --get remote.origin.url | sed -r 's/.*(\@|\/\/)(.*)(\:|\/)([^:\/]*)\/([^\/\.]*)\.git/https:\/\/\2\/\4\/\5/'` `git describe --always --dirty`

JPG_MODULES = interfce.c \
              jaricom.c jcapimin.c jcapistd.c jcarith.c jccoefct.c jccolor.c \
              jcdctmgr.c jchuff.c jcinit.c jcmainct.c jcmarker.c jcmaster.c \
              jcomapi.c jcparam.c jcprepct.c jcsample.c jctrans.c jdapimin.c \
              jdapistd.c jdarith.c jdatadst.c jdatasrc.c jdcoefct.c jdcolor.c \
              jddctmgr.c jdhuff.c jdinput.c jdmainct.c jdmarker.c jdmaster.c \
              jdmerge.c jdpostct.c jdsample.c jdtrans.c jerror.c jfdctflt.c \
              jfdctfst.c jfdctint.c jidctflt.c jidctfst.c jidctint.c jquant1.c \
              jquant2.c jutils.c jmemmgr.c jmemansi.c

SRCDIR = ../src
MODULES = $(wildcard $(SRCDIR)/SDL/*.c) \
          $(wildcard $(SRCDIR)/Game/*.c) \
          $(wildcard $(SRCDIR)/Ships/*.c) \
          $(wildcard $(SRCDIR)/../Linux/src/Missions/Generated/*.c) \
          $(JPG_MODULES:%=$(SRCDIR)/ThirdParty/JPG/%) \
          $(SRCDIR)/ThirdParty/CRC/CRC32.c \
          $(wildcard $(SRCDIR)/ThirdParty/LZSS/*.c) \


BUILDDIR = build
BINDIR = bin


# -DHW_GAME_HOMEWORLD
# -DHW_GAME_DEMO
# -DHW_BUILD_FOR_DISTRIBUTION
# -DHW_BUILD_FOR_DEBUGGING
# -D_WIN32_FIXME \

# _WIN32_FIXME;HW_GAME_HOMEWORLD;HW_BUILD_FOR_DEBUGGING;_WIN32;WIN32;_DEBUG;_WINDOWS

COMMONFLAGS = -MMD \
              -MP \
              -DHAVE_BOOLEAN \
              -DHW_GAME_HOMEWORLD \
              -DHW_BUILD_FOR_DISTRIBUTION \
              -DGENERIC_ETGCALLFUNCTION \
              -D_WIN32 \
              -D_LINUX_FIX_ME \
              -D_X86_64 \
              -D_X86_64_FIX_ME \
              -DWIN32 \
              -DWINDOWS \
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

EMXX = gcc
EMXXFLAGS = $(COMMONFLAGS) -O0 -ggdb3 `sdl2-config --cflags` -mconsole
EMXXLINK = -O0 -ggdb3 -lSDL2main -lSDL2 `sdl2-config --libs` -lopengl32 -lglew32 -mconsole


all: $(BINDIR)

$(BINDIR): $(BINDIR)/hw.exe $(BINDIR)/hw.pdb

$(BINDIR)/hw.exe: $(MODULES:%=$(BUILDDIR)/%.o) Makefile
	$(EMXX) $(filter %.o,$^) -o $@ $(EMXXLINK)

$(BUILDDIR)/%.o: % Makefile
	@mkdir -p $(dir $@)
	@echo $(EMXX) -c $< -o $@
	@$(EMXX) $(EMXXFLAGS) -c $< -o $@

$(BINDIR)/hw.pdb: $(BINDIR)/hw.exe
	.\cv2pdb\cv2pdb.exe bin\hw.exe

clean:
	rm -rf $(BUILDDIR)/* $(BINDIR)/*
