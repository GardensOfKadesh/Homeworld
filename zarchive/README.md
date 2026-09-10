# Ze Archive (a.k.a the Graveyard of Documentation)

This folder ([`zarchive`](.)) should be used to gather all the pieces of documentation/information that have become partially obsolete but not completely useless.
(The `z` is only there to make the folder sort last)

Yes, I know we have version control. But if you don't know something existed, how will you think to look for it?


Rules:
1. The tree hierarchy in this folder MUST match that of the top-level repository directory (e.g. `./Linux/BUGS` -> `./zarchive/Linux/BUGS`).
This is important to preserve context, please follow this rule when archiving files.
2. All the information contained in this folder SHOULD eventually either be deleted (if no longer relevant), or be incorporated into more recent documentation.

The strategy is to incrementally build a more structured, beginner-friendly documentation framework, by first moving the existing work out of the way, to more easily pick back what's important.

## Source Material Release Snapshot

[The `original-release-snapshot` folder](./original-release-snapshot/) stores everything that was released by Relic back in 2003 but which has not (yet) been integrated into the GoK project.

**It is intended as a read-only archive, you can move stuff out of it, but it is forbidden to modify anything inside it.  
Deleting stuff is also OK, but if you do, add a line here explaining what you deleted and why (in the same commit that deletes it).**

There was a time (when this project was still called HomeworldSDL) when people could freely and easily access the original release and all those tools.
With the death of the RDN, this is no longer the case.
Yet it is still important (maybe more than ever) for contributors (and the wider community) to have access to these resources.
If only as reference to understand what the workflow looked like back then.

So thank you to [Alex Headly](https://github.com/aheadley) for saving that source material and boldly putting it up on GitHub for all to access.
I (Thibault Lemaire) have rebased the entire commit history on top of [his snapshot](ad1bb82c) to make it easier to know exactly what HwSDL/GoK changed, and how.
If you want to see how it all looked like back then, that's where you should go.
(It should be the very first commit of this repository.)
I believe this will be useful for licensing, but also to restore features (like multiplayer, or RGL), and compatibility.

The people of the HwSDL project had started to import the tools archived here.
The process was tracked [there](../tools/README.txt).
