# Compiling Homeworld SDL on Linux

## Installing dependencies

### Using [Nix]

If you have [Nix] installed, there is a [`flake.nix`](flake.nix) file listing the build depencies so you can just run the build in a `nix develop` environment without installing anything:

``` sh
nix develop ./Linux
```

You can then go on with the [Quick Start](#quick-start) in that virtual environment.

[Nix]: https://nixos.org/nix/

## Quick Start

> More information can be found in the documentation files next to this one.

### Meson

``` sh
meson setup build
cd build
meson compile
```

> You are free to replace `build` above with anything you like. It will be the name of the build directory

You can now [run the compiled executable for the first time](../README#running-the-game-for-the-first-time).

#### Game is slow/crashes

By default, the game is compiled with debugging tools which can slow down the game _and_ crash it when it is trying to fit round pegs into square holes.

__If you experience any crash, please, send us the log!__

But if the game is too slow or you encounter a crash that you cannot work around, you can compile an optimised version with:

```sh
meson setup --buildtype=release -Db_sanitize=none build.fast
```

### Autotools (Deprecated)

#### x86_64 (intel/amd 64-bit)

``` sh
cd Linux
./bootstrap
../configure
make -j4
```

> The `-j4` flag passed to `make` is just an example.
  `-j` controls the number of "jobs" used by `make` to compile the sources.
  If your machine is equipped with, e.g., 12 cores, then replace `-j4` by `-j12` for a faster build.

> The configuration step has a lot of flags, run `../configure --help` to see them. (Notably the `--disable-linux-fixme` flag)

#### x86 (intel/amd 32-bit)

This is if you want to cross-compile the game to 32bit even if your machine is 64bit.

The process is the same as for x86_64, except for the `../configure` step, as follows:

``` sh
cd Linux
./bootstrap
CFLAGS='-m32' ../configure --disable-x86_64  # here
make
```

> Note: this will output a binary without debug symbols. Building a 32b binary with debug symbols on a 64b machine is feasible (I have done it for debugging), but not supported by autoconf and therefore not very straightforward.

## Cross-compiling to wasm32-emscripten

You need to have emscripten installed and enable your installed emsdk tools in your current shell environment.
(If you're using the nix shell, you can skip this step)

```sh
source emsdk_env.sh
```

Now you can setup meson for cross-compiling to wasm32 using emscripten:

```sh
meson setup --cross-file ../wasm/wasm32-emscripten.meson-cross-build-definition.txt -Db_sanitize=none -Dmovies=false build.emscripten ..
```

Now switch to the created build.emscripten folder and compile:

```sh
cd build.emscripten
meson compile
```

To automatically open the compiled wasm32 binaries in the browser using the provided index.html one can use the mini webserver provided with emscripten:
```sh
emrun .
```

### Building the Docker image used in the CI

```sh
docker load < $(nix build --no-link --print-out-paths .#ci-docker-image)
```


