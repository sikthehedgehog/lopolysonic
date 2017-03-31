# Lopoly Sonic

## F.A.Q.

### What are you planning to do with this?

Dunno, this is a sandbox of sorts. I was annoyed at how awful were the Sonic
models during the Saturn era (especially the quills) and decided to take my
shot at it to see how good it could look in about the same amount of polygons.

### Why Z and C for jumping?

Because I want to use X for spindash (the position of the keys would gimmick
A/B/C on a Saturn controller).

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
