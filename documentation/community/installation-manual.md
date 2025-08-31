# Gardens of Kadesh's Installation Manual

To play the full *Homeworld* game using this project, **you must have bought a copy of the game** to [get the original assets](#setting-up-the-assets-folder) (models, textures, sounds, movies etc.). 

You can then either [find a pre-compiled binary/executable for your platform](#downloads) (if available), or [compile one yourself](#compiling-from-source) from the source code and the instructions available in this repository.
(We try to make that as easy as we can)

When you have both, please read [the post-install instructions](#running-the-game-for-the-first-time).

## Getting the Assets

There are basically two ways you can obtain them:

- The original Homeworld game from 1999 (you'll have to find it second hand).
  In that case, you should also download [the official 1.05 patch].

- [The Homeworld Remastered Collection](https://www.homeworldremastered.com/) which includes a version of the original game (named "Classic") updated to run on Windows 10.

Either will work perfectly fine with this project.

### Asset Checklist

This section is intended as a quick checklist to make sure you have everything needed for the game to run. If you don't know where to find one of these files, see the appropriate section below. (Most of them can be found in the game's installation folder.)

#### Original (1999)

- [ ] `Homeworld.big`  
    > sha256: af9dcc06e3f99404334a0a8ec17e399876080e85feb5b47858382dc715136040
- [ ] `Update.big` Provided by the official 1.05 Patch  
    > sha256: c71b07758ee7696b3a19c1d75c946cbd68830e03b30cd3c2888f2f6d22b7c976
- [ ] `HW_Comp.vce`  
    > sha256: 15c4b988adb09b0969b0dc288b21ddc10ca9d42a2064d15b46b53dcf02fc2e44
- [ ] `HW_Music.wxd`  
    > sha256: b909c2cdbc8c8db67be168f6005bf8e8facaa9857263b16d186c824a0c4eed4f
- [ ] `Movies` (This folder is optional, you will simply not have the pencil-style cutscenes in the campaign)

#### Remaster (2015)

- [ ] `homeworld.big` (You might have to rename it to `Homeworld.big`, with a capital `H`)
    > sha256: e38c0528c1d4bd9d9195d26d5231ae29bef18f57d9bd1fe2eed33fb2b9b172a8
- [ ] `HW_Comp.vce`  
    > sha256: 15c4b988adb09b0969b0dc288b21ddc10ca9d42a2064d15b46b53dcf02fc2e44
- [ ] `HW_Music.wxd`  
    > sha256: 48f93c07bf718c56c20727aba12f06baf13d4d11d1c7185d2d2153543834e454
- [ ] `Movies` (This folder is optional, you will simply not have the pencil-style cutscenes in the campaign)

## Setting up the assets folder

This project needs all the [required files mentioned above](#asset-checklist) gathered in a single folder, which will be refered to as `$ASSETS_FOLDER` from here on out.
It can be anywhere you want (for example `~/Games/HomeworldSDL/` on Linux), and we suggest you copy (or move, or symlink) the assets from the game folder there.

### MacOS

To setup either the data from the original or remaster.  Please place the data assets into `Library/Application Support/Homeworld` or, if you are using Raider Retreat, place them in the same destination folder except to use `Raider Retreat` instead of `Homeworld`.

### Extracting the assets

#### Original (1999)

Install the game and [patch][the official 1.05 patch] (you can use [wine] 4.1 or above on Linux & MacOS)

``` sh
wine HWSetup.EXE
wine si_homeworld_update_105.exe
```

Open the game installation folder (usually `~/.wine/drive_c/Sierra/Homeworld` on Linux).
This is where you'll find the [required files](#asset-checklist).
Copy them to `$ASSETS_FOLDER`.

[wine]: https://www.winehq.org/

#### Remaster (2015)

##### Steam

After installing [the game][store_page], you should be able to find the [required assets](#asset-checklist) in `~/.local/share/Steam/steamapps/common/Homeworld/Homeworld1Classic/Data` (on Linux).
Copy them to `$ASSETS_FOLDER`.

[store_page]: https://store.steampowered.com/app/244160/Homeworld_Remastered_Collection/

## Downloads

Please see our [releases page] for the most up-to-date download links.

If there are no downloads for your platform, then the best we can offer is for you to [compile it yourself](#compiling-from-source).

[releases page]: https://gitlab.com/gardens-of-kadesh/gardens-of-kadesh/-/releases

### Windows

- [GoK 1.2.0 (x86_64)](https://github.com/GardensOfKadesh/Homeworld/releases/download/1.2.0/Homeworld-GardensOfKadesh-1.2.0-Windows.zip) 

## Compiling From Source

Please read the [compilation documentation](/documentation/contributors/compiling-from-source.md).

## Running the game for the first time

The first time you run the game, you will have to point it to [the directory containing the required assets](#setting-up-the-assets-folder). For example, if you have [compiled the game from source](#compiling-from-source) on Linux:

```sh
HW_Data=$ASSETS_FOLDER ./homeworld
```

where `./homeworld` is the path to your HomeworldSDL binary executable.

The game stores its configuration in `~/.homeworld` (on Linux), and will remember the asset directory and graphics configuration for later runs, which means you don't need to provide the `HW_Data` dir the next time you run the game, and you can safely move the executable around.

> ![TIP]
> The executable will, by default, look for its assets next to itself (in the same folder), if `HW_Data` is unset.


[the official 1.05 patch]: https://www.homeworldaccess.net/infusions/downloads/downloads.php?file_id=35
