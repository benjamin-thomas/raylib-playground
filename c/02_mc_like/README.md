# Dev workflow

Used version: raylib v5.5

## Step 0: install raylib

Just copy the files to:

- /usr/local/lib
- /usr/local/include

Then update the cache with:

- ldconfig

This make the compilation flags simpler, and works well with editors which make
control-click link to the headers.

## Step 1: build everything and launch the app

```bash
mkdir ./build/
./manage/build_all && ./build/main
```

`-fPIC` seems to be required to create shared libs `ldl` makes the main
"linkable" to the shared lib.

## Step 2: recompile (which reloads) the shared lib on file change

```bash
rg --files -t c | entr -c ./manage/build_lib
```

## Step 3: change the code, and observe the hot-reload functionality

For instance, change the color in `lib.c`.

---

## Textures

I grabbed the textures from this MineCraft clone:

https://github.com/fogleman/Craft
