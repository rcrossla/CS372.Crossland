BUILD INSTRUCTIONS FOR Windows 10
==================================
You will need to build your app from the Windows Command Line.  Visual
Studio provides you with a special version of the Windows Command Line
tool that's configured so that everything is setup for you to compile
from the command line.  You will need to do the following in that tool
- Make certain you are in the `windows` folder 
- Run `cmake ..` to rebuild the buildsystem.
- Then run `cmake --build .` to build the application

Once you have completed those three steps, you can either build from the
command line using `cmake --build .`  or load the Visual Studio solution
file that Cmake created for you in the Windows folder.
