# Contributing Code to the Project

> [!caution]
> Please read the [license agreement](./contributors/license-agreement.md#read-this-before-contributing) before contributing anything

## Overview

In broad strokes, if you want to contribute code to this project you will:

1. [`git clone`](#sharing-code)
1. Set up your [build environment][compile], [IDE] (like [VSCode]), and other development tools
1. [Hack](#hacking) at the bug/feature that you want to fix/implement
   1. Change the code
   1. [Compile]
   1. Run the game
   1. Doesn't work? Go to 1.
1. `git commit`
1. [Open a Merge Request on Gitlab][open an MR]

[compile]: ./compiling-from-source.md
[IDE]: https://en.wikipedia.org/wiki/Integrated_development_environment
[open an MR]: https://gitlab.com/gardens-of-kadesh/gardens-of-kadesh/-/merge_requests

## Sharing code

We use [Git] to version and share our code.

Coding is a bit like gaming: Sometimes you try something and it fails, so you load up another save.
Git is a save manager that lets you merge timelines and play together on the same code.

Git itself is peer-to-peer.
You can export save files (patches) to share with others.
But that's less convenient than having a centralized place where everyone can access the whole history of the project at any time.
That's what GitLab, GitHub, Gitea, Codeberg, GitBucket, etc are: Git servers.
People sometimes conflate Git and GitHub, but that's a bit like thinking Facebook is the Internet

[git]: https://git-scm.com/video/what-is-version-control.html

The rest of this documentation will assume you understand Git concepts.

## Hacking

So you want to dive into the code and start hacking, huh?
Here are a few pointers to help you with that:

### Clangd

[Clangd] is a _language server_ that can work with many editors (including [VSCode]) via a plugin.
It adds smart features to your editor: code completion, compile errors, go-to-definition and more.

To give proper hints, though, clangd needs to know the compile flags used (otherwise you'll get "header not found" errors).
To that end, it uses a `compile_commands.json` file describing how each file was compiled.

[Clangd]: https://clangd.llvm.org

#### With Meson

Meson automatically generates `compile_commands.json`, so if you named your build dir `build` as clangd expects, then you have nothing to do.
Enjoy your modern development environment!

### Sanitizers

[LLVM's Sanitizers] are a powerful suite of tools for memory debugging.
They can detect and help debug many kinds of invalid or dangerous memory handling patterns (like buffer overflows, use after free, or leaks).

[LLVM's Sanitizers]: https://clang.llvm.org/docs/AddressSanitizer.html

#### With Meson

The `address` and `undefined` sanitizers are enabled by default.
You can disable them by passing the `-Db_sanitize=none` option to `meson setup`.

[VSCode]: https://vscodium.com/
