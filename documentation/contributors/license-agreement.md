# Contributor License Agreement
## This Project is not Open-Source

At least not by [the definition of the OSI][open-source definition].
Keep reading for more information.

[open-source definition]: https://opensource.org/osd

## Sign this before contributing

As of writing (2026-09-25), the original source code to Homeworld remains bound by [a very restrictive license][the REULA].

Brian Burleson [posted in 2013][gbx forums thread hw source now] (before the release of the Remastered Collection) that [Gearbox] would be open to an "opensource release" of both the new code of the Classic version included in the remaster, and the old, original, code.
However this was never discussed again (to the best of our knowledge).

We have an [ongoing plea][open letter] to Gearbox for a relicensing to a [Free Software license].
In the meantime, **we ask of you -- dear new contributor -- that you provide your code under [the MIT License](../../COPYING.MIT)**.

It is a very unrestrictive license, that is well-known and well understood.
(It has been [vetted by companies like Google] for inclusion in their propietary projects.)
For our purposes, it is a formal way for you to say:
"I agree to my code being distributed under any license you like, as long as you say somewhere that it is my code."

(So, *for example:* If tomorrow Gearbox publishes the original code under GPLv3, then this whole project, including your code, could be distributed as GPLv3 as well.)

Here is how you can do that:
**Just add the name(s) under which you commit(ed) code, and all associated e-mail addresses to the list in [COPYING.MIT](../../COPYING.MIT)**.
(The year does not matter much.
The convention is to put most recent contributions at the top.)

This should definitely smooth any process of re-licensing.
And as a bonus, that means you can fearlessly re-use code contributed here in other projects of yours!

**All commits after 0e40bdd0 are licensed under MIT.**  
(Update this ☝️ if you are a historic contributor!)

[vetted by companies like Google]: https://opensource.google/documentation/reference/thirdparty/licenses#notice

### Note on reformatting and refactoring

**Please refrain from reformatting code that you haven't touched, and from refactoring code that is not part of the fix or feature you're working on.**

Code coming from the very [first commit of this repo](ad1bb82c) is -- and always will be -- protected by [the REULA].
(Until a re-license, or until it falls into the public domain in ~90 years.)
Which makes it relatively practical to track what code is free and what isn't with tools like `git blame`.

I (Thibault Lemaire) am **not** a lawyer, but I would argue that a simple reformat does not constitute "original work" -- legally speaking -- and so cannot be distributed as MIT.
It is still the same code.

So if you were to reformat a file, the blame would show *your* commit instead of the first commit.
Making it harder to identify its licensing.

Refactoring is a much grayer area than reformatting (which can be automated), but I think it could be similarly argued that you are *only* changing the shape of the existing code.
If, however, you are fixing a bug or adding a feature, then you are definitely bringing something new, and I would say it's safe to call that your own work, and take that opportunity to refactor whatever stands in your way.

Leaving old code untouched as much as possible also has another advantage: It makes it easier to integrate work from other forks.
(People keep starting their own projects from whatever code they can grab on the internet.
Given the many forks already out there, we can't know the state of the code they're starting off of.)

## Short explainer of [the REULA]


> [!WARNING] We are not lawyers
> All the information provided in this documentation is based on our (possibly wrong) understanding of [the REULA].
> It is provided as a summary and quick reference only.
> In court, only the text of [the REULA] will hold any value, so please read it in full before making a decision (and tell us if you spot any mistakes!).
>
> You have been warned.

Here are a few key takeaways of [the REULA]:

1. **You cannot use this project to make money** (i.e. non-commercial use only)
3. **You cannot read the source code.** Yes, this one is a bit insane.
Let us explain: 
The REULA states that modifications of the source code can only be shared between members of the [RDN] (who *must* agree to the REULA).
The RDN went dark in July 2007, which was [already a problem for the Homeworld SDL project][old homeworld source code license thread].
*They* decided to only focus on the "have agreed to the license" part and chose to restrict access to their source code as well.  
**We, at the GoK project, have chosen to disregard that close almost entirely¹.**
We consider that any person contributing to the project (or simply forking it to modify it) implicitly agrees to the license.
(Which is why it is so important that you, a future contributor, have read these few lines.)
3. All the contributions you make become the property of the current IP holder.
(The license names "RELIC" specifically, but it is our understanding that the rights are effectively transferred along with the IP.)
This is basically the same as being their employee, except they don't pay you.
But if you also make your code available under the MIT as described [above](#sign-this-before-contributing), then it can benefit everyone!
Not just the IP holder.

¹: We host our modified source code publicly to prevent it from being lost again.
From the following observations, the other alternative was basically to let the project die:
   1. The Homeworld SDL project went extinct without a legacy
   2. We were only able to pick up the project because someone had dumped the source code on GitHub
   3. Even with that source code, we were mostly unable to contact the ex-members of Homeworld SDL to get developments that might have been made since the dump
   4. There is only so few of us  


[the REULA]: ../../COPYING.REULA
[open letter]: https://gardens-of-kadesh.gitlab.io/#request_for_an_unambiguous_license
[gearbox]: https://www.gearboxsoftware.com/
[free software license]: https://en.wikipedia.org/wiki/Free_software#Licensing
[rdn]: https://web.archive.org/web/20070626061405/http://www.relic.com:80/rdn/
[old homeworld source code license thread]: https://web.archive.org/web/20160303221756/http://homesource.nekomimicon.net/sourceforum/viewtopic.php?f=9&t=377
[gbx forums thread hw source now]: https://archive.ph/20150308155452/http://oldforums.gearboxsoftware.com/showpost.php?p=4553392&postcount=6
