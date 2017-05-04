# Lopoly Sonic

How could have Sonic looked like in the Saturn era? Sure, we got Sonic R, the
special stages in Sonic 3D and the small sandbox in Sonic Jam, but I'm not
happy with how Sonic's model looked in those at all. But the Saturn hardware
is quite weak (and the whole 5th generation for that matter), so this is not
an easy task. This is an attempt to see how Sonic could have looked like
with those limitations in mind.

Not a 100% exact recreation of the limits (I just wanted something quick to
experiment with), but should be good enough to get an idea.

*To-do: upload some pics here*

## Download

There are a few prebuilt binaries here if you don't want to build it yourself:

* `bin-linux` for the Linux version (64-bit)
   * Needs SDL2 installed
* `bin-windows` for the Windows version (32-bit)
   * `SDL2.dll` taken straight from the [SDL site](http://libsdl.org/download-2.0.php)

Note that the Windows port is experimental, and by that I mean it'll crash
as soon as you quit the program (・～・) Trying to see how to fix it (I guess
that building against a patched SDL 2.0.4-9174 but using the SDL 2.0.5 DLL
isn't helping matters, I need to get up to date)

## F.A.Q.

### How do you build this?

Build all C files together and link against SDL2 and OpenGL.

* For Linux, this means linking against `-lSDL2 -lGL`
* For Windows, this means linking against `-lSDL2 -lopengl32`
   * and you may need `-static-libgcc -static-libstdc++`

You could also use the Code::Blocks projects (`losonic.cbp` for Linux,
`losonic_win.cbp` for Windows), but beware that they've been set up for my
environment and changing the toolchain they use can be a horrible mess.

(note: all the above assumes MinGW-w64 for Windows)

### Won't Sega sue you?

Sega is well known to not mind about non-commercial Sonic fangames (and when
they really do, they'll just send a warning first). They are *not* Nintendo.

Note that if you intend to use this code in commercial stuff, you'll have to
remove anything related to Sonic.

### What are you planning to do with this?

Dunno, this is a sandbox of sorts. I was annoyed at how awful were the Sonic
models during the Saturn era (especially the quills) and decided to take my
shot at it to see how good it could look in about the same amount of polygons.

### Why Z and C for jumping?

Because I want to use X for spindash (the position of the keys would gimmick
A/B/C on a Saturn controller).

### So when will you add the spindash?

When I stop being lazy :P

### Why did you use OpenGL 1.1? Didn't you know you should be using Vulkan?

I just wanted something quick, OK? Not like this needs much performance...

(on that note: we need a new easy API, Vulkan is so goddamn low level and
verbose we may as well just bitbang the GPU registers and it'd be easier,
and no "just use Unity" isn't a good answer for me)

### Why did you hardcode the models?

I'm not good with modelling programs (・ω・`)

Though yeah, some day we should go and convert the code into actual models.
We could make wrapper code that has the same names as OpenGL's functions and
just collects the polygons into an array, though this will only give us
triangles (we're still going to need to replace triangle pairs with quads
manually as needed).

### Why didn't you use lighting?

The idea was that if I were to make this on the Saturn, I'd just ditch
lighting altogether for the sake performance (and just ensure the model is
shaded nicely). This means not having to transform normals nor having to do
lighting calculations, which should speed up things significantly.

### There are glitches in the textures

Because they're bleeding into other parts of the texture. On the Saturn each
polygon would be its own sprite and this issue wouldn't happen, and since
this is a "what if this was on the Saturn" thing, I won't bother fixing it.
