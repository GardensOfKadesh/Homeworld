# Design and Architecture

> [!IMPORTANT] TODO
> 
> Explain how the the code is structured, the different systems, KAS scripts, `.shp` files, etc.

## `Warp.script`

`Warp.script` is a single-player debug helper used to start the campaign directly at a later mission with a generated player fleet.
You trigger it simply by clicking `SINGLE PLAYER` > `START!`.
The game will look for a file named exactly `Warp.script` (case insensitive) at the root of the game data search path.
You can rename it to disable it.
The implementation is in `src/Game/SinglePlayer.c`.

The first line must be `WarpTo N`, where `N` is the mission number to start.
Mission numbers are the original Homeworld mission enum values, so `WarpTo 7` starts Mission 7, "The Gardens of Kadesh".
`WarpTo 1` is ignored because the warp path is only enabled for missions after Mission 1.
The first line is parsed by a small custom check before the normal script parser runs, so write it without `=`.

```text
WarpTo 7
WarpStartRU 2000
WarpFleet LightCorvette 6
WarpFleet ResourceCollector 4
WarpFleet ResearchShip 1
```

After the first line, the file is read by the normal script parser.
The supported entries are:

- `WarpStartRU`: sets the player's starting resource units.
- `WarpFleet`: adds ships to the player's generated fleet.

`WarpFleet` takes a ship type followed by a count.
Commas in that value are treated as spaces, so `WarpFleet LightCorvette, 6` is equivalent to `WarpFleet LightCorvette 6`.
For race-specific standard ship types, the code maps the type to the current player race.
Invalid ship names stop the game with a fatal script error.
Ship type names are case-insensitive.

The standard R1/R2 ship type names are:

| Ship type | Notes |
| --- | --- |
| `AdvanceSupportFrigate` | Support frigate. |
| `AttackBomber` | |
| `Carrier` | |
| `CloakedFighter` | R1-only; maps to `DefenseFighter` for R2. |
| `CloakGenerator` | |
| `DDDFrigate` | R1-only; maps to `DFGFrigate` for R2. |
| `DefenseFighter` | R2-only; maps to `CloakedFighter` for R1. |
| `DFGFrigate` | R2-only; maps to `DDDFrigate` for R1. |
| `GravWellGenerator` | |
| `HeavyCorvette` | |
| `HeavyCruiser` | |
| `HeavyDefender` | |
| `HeavyInterceptor` | |
| `IonCannonFrigate` | |
| `LightCorvette` | |
| `LightDefender` | |
| `LightInterceptor` | |
| `MinelayerCorvette` | |
| `MissileDestroyer` | |
| `Mothership` | The warp path already creates one automatically. |
| `MultiGunCorvette` | |
| `Probe` | |
| `ProximitySensor` | |
| `RepairCorvette` | |
| `ResearchShip` | Activates a free lab when added. |
| `ResourceCollector` | |
| `ResourceController` | |
| `SalCapCorvette` | |
| `SensorArray` | |
| `StandardDestroyer` | |
| `StandardFrigate` | |
| `Drone` | R1-only. |
| `TargetDrone` | |
| `HeadShotAsteroid` | Mission/special object. |
| `CryoTray` | Mission/special object. |

The non-standard ship type names recognized by `WarpFleet` are:

| Race | Ship types |
| --- | --- |
| P1 | `P1Fighter`, `P1IonArrayFrigate`, `P1MissileCorvette`, `P1Mothership`, `P1StandardCorvette` |
| P2 | `P2AdvanceSwarmer`, `P2FuelPod`, `P2Mothership`, `P2MultiBeamFrigate`, `P2Swarmer` |
| P3 | `P3Destroyer`, `P3Frigate`, `P3Megaship` |
| Traders | `FloatingCity`, `CargoBarge`, `MiningBase`, `ResearchStation`, `JunkYardDawg`, `JunkYardHQ` |

`StrToShipType` also recognizes `Ghostship`, `Junk_LGun`, `Junk_SGun`, `ResearchStationBridge`, and `ResearchStationTower`,
but `RacesAllowedForGivenShip` does not assign a valid race to those entries, so avoid using them in `WarpFleet`.

The warp startup path creates the player's Mothership automatically at the mission start point, then adds the `WarpFleet` ships in parade formation around it.
Do not add a Mothership through `WarpFleet` unless you deliberately want an extra one.
The code also applies the research unlocks that the player would normally have gained by reaching the target mission.

The same file is read more than once during startup.
Before the mission is loaded, `WarpFleet` entries are used to mark the required ship data for preload.
During mission start, the entries are read again to create the fleet and set starting resource units.

`src/Game/HorseRace.c` does not parse `Warp.script` directly.
It uses the already selected single-player mission to choose the loading screen, so `WarpTo 7` should show `SinglePlayer/mission07/loading.jpg` while the target mission loads.

## 1.05 vs 1.06

The "Classic" version of Homeworld 1 provided in the [HWRM bundle](https://www.homeworldremastered.com/) (hereafter abdridged to HW1C) is labeled "1.06" and has a few differences with the freely available [1.05 patch].

According to [reddit user SuperSajuuk](https://www.reddit.com/user/SuperSajuuk/) in [a post from 2023-08-21][sajuuk's post]:
> [HW1C] is built with a patch that was never released back in the day (1.06).
> In essence, it's an incomplete and untested build [...]


He later went on to explain [on Discord](https://discord.com/channels/794197267091292160/874750343928500224/1429173663994744872)
> [HW1C] is built from a version of the source code that included the 1.06 patch that Relic had developed but which was neither completed, released or tested.
> It is full of bugs and breaks [...] randomly throughout the game (Mission 10 in particular [frequently never completes])
>
> [...]
>
> Regarding the source of this statement, it is unfortunately something that was posted to [the Homeworld Universe discord server][hw universe discord] in a channel that was [later deleted]. Consequently, you'll just have to trust me that this is the case [...].
> However, there are plenty of testimonials of users who had all sorts of crashing issues in the HW1 Classic 1.06 build and had no such problems from the original CD (or the ISO copy on archive.org, which is perfectly safe btw) patched to 1.05.
> Make of that what you will. 😉

This story of an unfinished 1.06 patch, if true, would explain the differences we have observed between the assets in the `Homeworld.big` file distributed with HW1C and those found in `Homeworld.big` + `Update.big` in a HW1 install patched to 1.05.

It is simply the state the HW1 sources were in when [Gearbox] acquired the IP from THQ.

We had considered distributing those changes in a `GoK.big` file for people playing GoK with the assets from an original CD, but in light of this, and not to mention the licensing issues this would add, we have decided against it.

[sajuuk's post]: https://www.reddit.com/r/homeworld/comments/15x1n4l/homeworld_1_classic_on_modern_hardware/
[1.05 patch]: https://www.homeworldaccess.net/infusions/downloads/downloads.php?file_id=35
[hw universe discord]: https://discord.gg/homeworld
[gearbox]: https://www.gearboxsoftware.com/
