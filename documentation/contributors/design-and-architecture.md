# Design and Architecture

> [!IMPORTANT] TODO
> 
> Explain how the the code is structured, the different systems, KAS scripts, `.shp` files, etc.

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
