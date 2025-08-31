# GoK Documentation

This is the main hub for all the documentation of the project.
From software architecture and design, to project governance, through build tools, coding conventions, contribution guidelines, etc.

There MUST be at least one path from this page to any piece of documentation pertaining to this project, and that path SHOULD be as straightforward as possible (though it does not have to be short).

## Index

- [Project's landing page (top-level README)](/README.md)
  - [Project's History](/README.md#history)
- [How to contribute](/CONTRIBUTING.md)
  - [Project Governance](/CONTRIBUTING.md#governance)
- [Documentation folder](/documentation/)
  - Documentation meta page ([you are here](./README.md))
    - [How to contribute to the project's documentation](#helping-with-documentation)
  - [Community](/documentation/community/README.md)
    - How to [open an issue]
- [Old Documentation][archive]

## Helping with Documentation

A good documentation is crucial to:

1. Make it as easy as possible for anyone to contribute
1. Make it as easy as possible for anyone to play

The more contributors, the more they can help with 2.

Any change to this documentation that goes in those directions is welcome.

**One very simple way you can help improve this documentation is by taking notes while you follow it.**
What was unclear?
What piece of information did you have to look up elsewhere?
Etc.

Another way you can help is by digging up precious nuggets of information from [old documentation files][archive]

### Guidelines

When writing documentation for this project you should try to reach for the following goals, in the following order:

1. **Add new information.**
It sounds obvious that you wouldn't add something that is already documented, but it's important to place that goal above all else.
We are not in a position to be picky.
All contributions are welcome, and if it takes too much effort to reach the other goals listed below, then we will still accept your contribution if it meets this goal.
1. **Avoid duplication.**
Less duplication means less places to forget when some information needs to be updated.
The same piece of information should not be present in different places (even with different phrasing).
Try to re-organise and/or link between the different places.
It can be convenient for the reader to sum up something before linking to it, in case they already have the information, so they don't have to follow yet another link, but it should be limited to a single sentence or two.
1. **Have structure**.
Make it easy to skim, skip ahead, or jump back to other -- relevant -- parts of the documentation.
1. **Be clear.**
Sentences should use proper English, but also attempt to be as simple as possible. 
Use common words accessible to non-native speakers.
1. **Be concise.**
If you can express the same idea in less words, then do.
Take some time to read over what you wrote, and see if you can rephrase it.
1. **Be accessible**
Assume zero knowledge of or familiarity with the project, and explain everything from the ground up.
It never hurts, as long as it can easily be skipped.

If you find anything that can be improved to better meet these goals, then please consider [contributing](#how-to) or [reporting it][open an issue]!

### How-To

> [!caution]
> Please read the [license agreement](./contributors/license-agreement.md#read-this-before-contributing) before contributing anything

There are basically two ways you can change the documentation:
- With [Git] and a text editor.
This is the same as changing code, except you don't need as much tooling.
- [Directly from gitlab](#gitlabs-edit-feature)

All documentation should be written in Markdown, please read [the style conventions](#markdown-style-guide).

#### Gitlab's "Edit" Feature

If you are viewing this page on Gitlab, there should be a blue "Edit" button at the top right corner of this page.

Clicking it should open a drop-down menu, where you can select "Edit single file".

(There is also an "Open in Web IDE" option.
It might save you time if you are already familiar with VS Code, but if you are not a developper, we do not recommend this option)

E.g. for this page, you be redirected to a page with a URL that looks like: https://gitlab.com/gardens-of-kadesh/gardens-of-kadesh/-/edit/master/documentation/README.md

You can use `Shift`+Scrollwheel to scroll horizontally if a sentence extends beyond the text area.

#### Markdown Style Guide

[Markdown] is a "markup language".
I.e. a conventional way to write plain text such that it can be formatted into prettier documents like what you see here.

This documentation assumes it will be rendered on Gitlab, so you can make use of Gitlab flavored markdown (especially [alerts][glfm alerts]).

We do not make use of a formatter, but here are the few rules that you should observe to maintain consistency within the markdown source of this documentation:

- Titles with `#`s not `---` or `===`.
`#`s allow deeper levels of nested titles.
- Leave a single blank line above and below titles, code blocks (` ``` `), and lists.
- One sentence = one line.
Basically open a new line after every `.`, when converting to HTML, they will be concatenated and will simply wrap dynamically based on the browser window.
It makes it easier to re-order sentences and makes diffs between different versions easier to read.
(Although, admittedly, it is a bit annoying in editors that do not feature soft wrap.)
- Prefer reference links, especially if used in multiple places and/or long.
Keep them at the bottom of each section (before the next title), by order of apparition within the page.


[Markdown]: https://learnmarkdown.com/
[glfm alerts]: https://docs.gitlab.com/user/markdown/#alerts

[archive]: /zarchive/README.md
[open an issue]: /documentation/community/README.md#opening-an-issue
