<img src="https://user-images.githubusercontent.com/45521946/129032696-a2832d53-f9a3-4744-8e6b-c2b55686ba5c.png" width="550">

## A WIP level editor/game engine for the Nintendo 64

<img src="https://i.imgur.com/TSwNWNs.png" width="600">

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/f246a65f5b4f480f922a5ed886eb37e8)](https://www.codacy.com/gh/deadcast2/UltraEd/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=deadcast2/UltraEd&amp;utm_campaign=Badge_Grade)

### Important Update

Life has changed for me in this last part of the year (a good change!) and I don't have as much motivation and time as I used to have so I won't be working on this project much anymore. A major issue I'm having is the lack of good debugging tools while developing software for the N64. A debugger is paramount when you start stepping beyond constructing a non-trivial application. I feel like I'm approaching that barrier which will make future development very difficult on the N64. I've grown as a developer working on this project but didn't do too much upfront planning to know this obstacle would be inevitable. Perhaps circumstances will change in the future with the advent of a good way to debug and step through code as it’s executed on the console. Maybe one exists now and can be recommended to me for inspection. I’m not calling it totally quits on this project but need better tooling and more time. Thanks for checking out the project and I'll be around. :)

### Setup

Due to the project using Git LFS the zipped version from GitHub won't contain all necessary files. Clone the project using Git and then run `git lfs pull` to hydrate all of the pointer files. After that make sure that the Windows 10 SDK is installed and then open the editor solution file in Visual Studio 2022. Set the solution to build as a x64 application and then all should build fine. Make sure to also install OpenAL so you can test your rom out in the cen64 emulator included. I've included it in Editor/Vendor. Also if you so happen to have the excellent 64drive you can test on that too.

### Notes

UltraEd isn't finished and is not a fully polished tool yet. It has enough functionality to throw a few models in a scene, texture them, script them and have some fun. I have many ideas and things I'm excited to implement in the future. I have a full-time job and other life commitments so I work on this tool in my free time. I love the N64! :0)

### Quick Start

UltraEd is now project based so a new project must be created before creating a scene with assets. Click File > New Project. Enter a name and select where the project should live on your drive. After your project folder has been created you can add assets to your project by dropping them in the newly created folder. Everything placed in the folder is accessible from the editor and is tracked. So when a model or texture is changed the scene will auto-update with the changes.

### Programming API

The feature set is currently very small but it will expand over time. Here is the current set of methods available:

1. **Actor \*FindActorByName(const char \*name)**
Pass the name of an actor and the first matching one will be returned.

2. **void SetActiveCamera(Actor \*camera)**
Pass a camera actor to become the new focused camera.

3. **Actor \*Clone(Actor \*actor)**
Allows "copying" of an actor.

4. **void Destroy(Actor \*actor)**
Marks the actors to be removed along with any children at the end of the current frame.

Each actor includes a default script that contains empty function implementations. Here's the template:

```
void $Start(Actor *self)
{
    // Called upon startup
}

void $Update(Actor *self)
{
    // Called once every frame
}

void $Input(Actor *self, NUContData gamepads[4])
{
    // Called when any input from the controller is detected
}

void $Collide(Actor *self, Actor *other)
{
    // Called when a collision is detected only if both actors have a collider added.
}

void $Destroy(Actor *self)
{
    // Called when actor is being destroyed.
}
```

The dollar signs are necessary to allow correct namespacing of all defined functions.

### Dependencies

The included Assimp library was compiled from source using version 5.0.1 and was built as a static library with the option BUILD_SHARED_LIBS set to false.
<a href="https://github.com/assimp/assimp/releases/tag/v5.0.1">https://github.com/assimp/assimp/releases/tag/v5.0.1</a>

### Donations

If you would like... you can donate to UltraEd's development! ^_^

<img src="https://i.imgur.com/vzHSER7.png" width="32" /> bc1qxev0tlhhxuug6f4qhe0xh0u5u7su6hqdjsp30y

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=R25G2EARP89AL)

### License

UltraEd is MIT licensed and was previously GPL v3. The decision to change was due to no longer using Qt for the GUI. ImGui was chosen instead due to its immediate-mode style rendering and more flexible license.
