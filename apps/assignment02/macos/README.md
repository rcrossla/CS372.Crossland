BUILD INSTRUCTIONS FOR Apple MacOS
==================================
You need to do two things to get started building an application using `cmake` on
macOS:
- Make certain you are in the `macos` folder.
- Run `cmake ..` to rebuild the buildsystem.
- Then run `cmake --build .` to build the application

* Pre-requisites
There are some things that you need to have installed for this to work
correctly. 
- You will need the Homebrew package manager. This can be installed from
  [https://brew.sh](https://brew.sh) using the command:
  
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

- Once you Homebrew installed, use it to install `cmake` 

```bash
brew install cmake
```


