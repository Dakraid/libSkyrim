# Dakraid/libSkyrim
This is a fork of Himika's libSkyrim, a project that aims to make developing plugins for Skyrim LE easier and more convenient.

As my work on BestInClassPP requires changes and updates to libSkyrim and SKSE, I have decided to create a fork to keep track of these and make any new discoveries available to the public.

## Requirements
Currently the library is build using Visual Studio 15, Target Platform Version (and SDK) 8.1, and Platform Toolset v140.

Building the project under VS17 and above requires the flag "/Zc:offsetof" to be set, as otherwise the static_asserts seem to fail.
