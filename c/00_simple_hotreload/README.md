# Dev workflow

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
