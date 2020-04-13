# iracingOverlay

An openGL C++ based lightweight overlay for IRacing.

# What can it do
* Display a scrolling transparent graph of the throttle and brake traces

![GitHub Logo](Other/throttleBrakeTrace.png)


# Dependencies
##  Automated Install
A few scripts have been created to automate the installation process. In the event these fail, you may have to compile the dependencies manually.

### Linux (Ubuntu)
On Ubuntu these dependencies can be installed by running
```
sudo chmod +x installDependicies.sh
./installDependiciesUbuntu.txt
```
### Windows
On Windows, this is a two step process.
```
installDependiciesWindows-part1.bat
```
Install the required packages as the installers popup.
Add the environment variables specified at the end of the process.
Then in a new commnd prompt,
```
installDependiciesWindows-part2.bat
```
## Manual Install
### Linux (Ubuntu)
* Building dependicies
	* cmake
	```
	sudo apt-get install cmake
	```
* GLFW (multi-platform library for OpenGL)
	* Download from http://www.glfw.org/download.html and extract.
	* Install dependencies
	```
	sudo apt-get install xorg-dev libglu1-mesa-dev
	```
	* Navigate to the glfw root directory and use cmake
	```
	cmake -G "Unix Makefiles"
	make -j4
	sudo make install
	```

* GLM (The OpenGL Mathematics Library)
	* Download a release from Github and extract, https://github.com/g-truc/glm/tags
	* Copy the glm folder inside the glm release into the include directory
	```
	cd <glm_root_dir>
	sudo cp -r glm /usr/local/include/
	```

* FreeType - Font Rendering Library
	* Download and extract from https://www.freetype.org/index.html
	* Naigate to the root directory and run
	* Copy include files to /usr/local/include
	```
	sudo cp -r include/* /usr/local/include 
	```
	Please DO NOT run ./configure on a system running the Unity window manager, as this will most likely break Unity.


# Compiling
A CMakeLists.txt file is included for compiling with Cmake. This should work for systems running Ubuntu. Navigate to the build directory and remove any old CMakeFiles
```
cd build
rm -r *
```
Run cmake to generate a makefile.
```
cmake ../                           # Linux
cmake -G "MinGW Makefiles" ../      # Windows
```
Compile the program.
```
make -j4
```

## Debugging
To enable debugging, when running cmake, enable the debugging flag.
```
cmake -DCMAKE_BUILD_TYPE=Debug
```

# Compiling an Eclipse Project
To generate an Eclipse project, from the root directory,
```
cd build
rm -r CMakeFiles/
cmake -G "Eclipse CDT4 - Unix Makefiles" ../src
```
Then import the project into Eclipse using File >> Import >> General >> Existing Projects into Workspace. Click next and set the root directory to <workspace>/openGLMap/build. Click Finish. The project can now be built with Eclipse using the 'all' Build Target. The source files will be inside the "[Source Directory]" and are linked to their actual counterpats.
