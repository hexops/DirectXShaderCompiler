To regenerate:

1. Run `generate.bat` from the root of the repo in a command prompt, this will do a full build using the official build path. You will need the Windows SDK, Visual Studio, etc. outlined in the Microsoft README.
2. Run `stage.bat` to stage changes to commit. This commits generated sources only, e.g. `.h` and `.inc` header files.
