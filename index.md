# Activate OpenGL and GLSL on Xcode

In this page, I will demonstrate how to activate OpenGL and GLSL on Xcode. <br /> 
I use Intel Iris pro graphics and OpenGL 4.1 [check your OpenGL version](https://support.apple.com/en-us/HT202823) on Xcode (version 7.2). <br />   
Type this commend in Mac terminal to know your version of Xcode.<br />   
```c
/usr/bin/xcodebuild -version
```
<!--- AAAAA  -->
### Step 1: Download framworks and library for OpenGL

- [Cmake](https://cmake.org/): It is a cross-platform for managing a build process of software. Here we need it to build GLFW and glm.  
- [GLEW](http://glew.sourceforge.net/): It is OpenGL Extension Wrangler Library  
- [GLFW](http://www.glfw.org/): It is a library that creates a window with OpenGL context. basically, another library `GLUT` also can create a window with OpenGL context. It depends on which one you perfer to do...  
- [glm](https://github.com/g-truc/glm): It is a mathematics library for OpenGL and GLSL. I really like it a lot. It helps me handel with vertex buffer object and vertex array object. If you don't know what vertex buffer object or vertex array object is. Don't worry. This is a [website](https://learnopengl.com/#!Getting-started/Hello-Triangle), a very useful website that shows you how to use GLSL.<br />   
<br />  

* [Download Cmake](https://cmake.org/download/): Choose `Mac OSX 10.6 or later           cmake-3.8.0-rc4-Darwin-x86_64.dmg  OR  cmake-3.8.0-rc4-Darwin-x86_64.tar.gz` 
* [Download GLEW](http://glew.sourceforge.net/): Download it via github or zip. 
* [Download GLFW](http://www.glfw.org/): Choose `Download GLFW 3.2.1`.
* [Download Glm](https://github.com/g-truc/glm/releases/tag/0.9.8.4): Choose `glm-0.9.8.4.zip`.

 ------
 
### [Build `GLFW` with Cmake](http://www.glfw.org/docs/latest/compile_guide.html#compile_generate).<br />
   After we download `GLFW`,we use `Cmake` to generate project files or makefiles and compile it by makefiles to get the `GLFW`   library.<br />  
   
 - First, let's start to create a new folder on your desktop, and unzip the `GLFW` file. `Cmake` will generate files into thie new  folder. For example, I create a new folder called `glfw_build`.<br />
  
 - Second, go to the directory of `GLFW` and get the working directory of `GLFW` by `pwd`. <br />
   For example, after upzip the`GLFW` file, I get `glfw-3.2.1` on my desktop.<br />  
    ```c
     cd glfw-3.2.1
     pwd
     ```   
   `/Users/Chiaoysbaby/desktop/glfw-3.2.1` is the working directory of `GLFW`. <br /> 
    
    <img width="512" alt="screen shot 2017-04-05 at 1 20 58 am" src="https://cloud.githubusercontent.com/assets/16565587/24696413/3f21b594-199e-11e7-9882-ad9373a4413d.png">


 - Third, go(cd) to your new folder and type this in your terminal.<br />  
    ```c
     cmake /~the working directory of glfw~/ -DBUILD_SHARED_LIBS=ON
    ``` 
    It shows this in my terminal.<br />  
    <img width="1024" alt="screen shot 2017-04-05 at 1 29 40 am" src="https://cloud.githubusercontent.com/assets/16565587/24696759/6ec534fa-199f-11e7-9d75-f1cb59f612d9.png">

 - Fourth, check files: <br />
    Because Cmake generate projects file or makefiles in my glfw_build. After Cmake the file, we have a new file called `Makefile`: <br />   
    <img width="780" alt="screen shot 2017-04-05 at 1 30 56 am" src="https://cloud.githubusercontent.com/assets/16565587/24696871/ebaa05ae-199f-11e7-849d-be5165b93dee.png">

 - Fifth, build `GLFW` framworks by makefile and go to the directory where you camke `GLFW` and type `sudo make install` in your terminal. <br />

   ```c
    sudo make install
   ```
    <!--- After typing `sudo make install`, it shows this information in your terminal.<br />   -->
       
###  Build `GLEW` libraries. <br />  
   Unlike `GLFW`, we just need to `make install ` it. Go to the directoy of `glew-2.0.0` and type `sudo make install` in your mac   terminal. Because I extracted glew-2.0.0.zip on my desktop, I go to the glew-2.0.0  by `cd ~/desktop/glew-2.0.0 `. <br />

   ```c
   cd ~/desktop/glew-2.0.0 
   sudo make install
   ```
   After installing `GLEW`, it shows this information in terminal. We have the header files of `GLEW` which are in the `/usr/local/include/GL`and the libraries of `GLFW` which are in the `/usr/local/lib/ `<br />

   <img width="631" alt="screen shot 2017-04-05 at 4 11 01 am" src="https://cloud.githubusercontent.com/assets/16565587/24702964/fbdb94f4-19b5-11e7-873f-06a26136d051.png">

### Build `Glm` libraries.<br />  
   Because `Glm` doesn't have makefile, we need to generate its makefile by `Cmake` `<br /> 
  - Create a new folder on your desktop amd unzip the `Glm` zip file.
    For example, I create a new folder called `glm_build`.
  - Go to the directory of `GLEW` and get the working directory of `Glm` by `pwd`Linux command. 
  - Go(cd) to your new folder and type this in your mac terminal.

     ```c
     cmake /~the working directory of glfw~/ -DBUILD_SHARED_LIBS=ON
     ``` 
      After camke the folder, it shows this information in your terminal: <br />

     <img width="1122" alt="screen shot 2017-04-05 at 4 23 47 am" src="https://cloud.githubusercontent.com/assets/16565587/24703664/0216412c-19b9-11e7-892e-de116f6864af.png">

  - The Next step is to build libraries of `Glm` by a makefile. 
    Go to the directory where you camke `Glm` and type `sudo make install` in your terminal. <br />

    ```c
    sudo make install
    ```
    After installing the `Glm`, we have many header files of `Glm` in `/usr/local/include/glm`. <br />  


### Step 2: Check head files and libraries whether are in your environment or not. 

-  Let's check head files: <br /> 
   After installing `GLFW`,`GLFW` and `glm`, they build heads file into `/usr/local/include`. There are many methods to go to the  directory. Here I use `Shift`+ `command`+ `G` keys to show `Go to the folder`. Open any folder, and press `Shift`+ `command`+ `G` keys together, it will show:  <br />  
   
   <img width="581" alt="screen shot 2017-04-05 at 3 58 59 pm" src="https://cloud.githubusercontent.com/assets/16565587/24730497/d0ccb0c8-1a18-11e7-9e11-4f147c6d3542.png">
  
   Tpye `/usr/local/include` in Go to the folder, we will go to the directory where has heead files. <br />     
   If anything is correct, it has three folders in this directory, includes `GL`, `GLFW` and `glm`. <br /> 
   
    <img width="567" alt="screen shot 2017-04-05 at 4 02 00 pm" src="https://cloud.githubusercontent.com/assets/16565587/24730585/44f61494-1a19-11e7-89ee-dd88333de0d5.png">
   
-  Check libraries: <br /> 
   After we successfully install `GLFW` and `GLEW` they have several libraries in `/usr/local/lib` .<br />  
   Here I also use the same method to go to the folder, and check these several files in `/usr/local/lib` .<br /> 
   For `GLFW`, it builds `libglfw.3.2.dylib`, `libglfw.3.gylib` and `libglfw.dylib`. <br />  
   For `GLEW`, it buildes `libGLEW.2.0.dylib` and  `libGLEW.dylib`. <br />
 
 
### Step 3: Open a new Porject on Xcode.
 In this step, we start to open a new OpenGL project and GLSL on Xcode. Xcode is an integrated development environment(IDE) for macOS. We    will use Cocoa application on OSX to activate GLSL. <br /> 
 <br /> 
 - open a new project on Xcode, and choose Cocoa Application. 
 
   <img width="719" alt="screen shot 2017-04-05 at 6 45 21 pm" src="https://cloud.githubusercontent.com/assets/16565587/24734024/17b13d08-1a30-11e7-8d85-5f7e756c964f.png">

- Type your product name. In the example, test1 is my prproductoject name. Although we don't use Objective-C as programming language, we still kepp it and click `Next` button.  

   <img width="721" alt="screen shot 2017-04-05 at 6 47 32 pm" src="https://cloud.githubusercontent.com/assets/16565587/24734185/de0e7a56-1a30-11e7-810a-b9a40f83c768.png">

- Choose a directory that you want to create thie project. In the example, I store my project on desktop. <br />  
- After setting the directory, we will see: <br /> 

   <img width="389" alt="screen shot 2017-04-05 at 6 56 08 pm" src="https://cloud.githubusercontent.com/assets/16565587/24734378/e5f397dc-1a31-11e7-8653-0e6050240063.png">

- Here we need to delete several files, includes `AppDelegate.h`(uder test1) , `AppDelegate.m`(uder test1) and `main.m`(under Supporting   Files). In addition, we need to add new file called `main.cpp` as our main file in test1. <br /> 
  <br /> 
  After I made change,it looks like this:<br /> 
 
  <img width="264" alt="screen shot 2017-04-05 at 7 05 26 pm" src="https://cloud.githubusercontent.com/assets/16565587/24734534/e7b54132-1a32-11e7-816d-cab8eef39ca8.png">

- Chick test1, it shows this: <br />  

   <img width="1151" alt="screen shot 2017-04-05 at 7 08 06 pm" src="https://cloud.githubusercontent.com/assets/16565587/24734631/4dc15d94-1a33-11e7-93bc-3ca7857dd81e.png">

- Chick `build pheses` and insert libraries in `Link Binary With Libraries`. <br /> 
- Click the `+` button to add 'OpenGL.framework' and 'GLUT.framework'. <br /> 

   <img width="391" alt="screen shot 2017-04-05 at 7 15 47 pm" src="https://cloud.githubusercontent.com/assets/16565587/24735785/75be515c-1a39-11e7-931f-8c95d95cadb9.png">
  
   <img width="397" alt="screen shot 2017-04-05 at 7 15 38 pm" src="https://cloud.githubusercontent.com/assets/16565587/24735800/7d6c2c08-1a39-11e7-8469-b270ff5a4c6a.png">

- Click `Add another..` button, and use `Go to the folder` this method to the directory `/usr/local/lib`.<br /> 
  Find `libglfw.3.2.dylib` and `libGLEW.2.0.0.dylib` in this directory, and add them.<br />  
  <br /> 
  **Note**: Id you don't find `libGLEW.2.0.0.dylib`, try to find `libGLEW.2.0.dylib` and add this instead of `libGLEW.2.0.0.dylib` . `libGLEW.2.0.dylib` is the symbolic link to  `libGLEW.2.0.0.dylib` . <br />   

  <img width="306" alt="screen shot 2017-04-05 at 8 49 47 pm" src="https://cloud.githubusercontent.com/assets/16565587/24737151/72067028-1a41-11e7-8396-56486ac1ba1e.png">

  Finally, we added two frameworks and two libraries in `Link Binary With Libraries`. <br /> 
 
   <img width="832" alt="screen shot 2017-04-05 at 8 45 37 pm" src="https://cloud.githubusercontent.com/assets/16565587/24737094/0392b890-1a41-11e7-9a59-da957fe5ada3.png">

 - Next, we also need to add path of head files. Look for `Search paths` which is under `Build Settings`.<br />
   Add two paths `/usr/local/include` and `/opt/local/include` in  Header Search Paths.<br />
 
   <img width="873" alt="screen shot 2017-04-05 at 9 29 50 pm" src="https://cloud.githubusercontent.com/assets/16565587/24738016/aa7cc794-1a47-11e7-9679-d1beb5609820.png">

 - After adding path for header files, we also need to add path for libries. Let out system know where the head files and libries are.<br />
  Add two paths `/usr/local/lib` and `/opt/local/lib` in  Library Search Paths.<br />
  
   <img width="805" alt="screen shot 2017-04-05 at 9 45 22 pm" src="https://cloud.githubusercontent.com/assets/16565587/24738285/87c9fc1a-1a49-11e7-82be-a4a23344143f.png">


### Step 4: Edit your main.cpp on Xcode.
- In main.cpp, add libraries here. <br />
  **Note:** the `shader.h` is from this [website](https://learnopengl.com/code_viewer.php?type=header&code=shader). <br />
  We put our `shader.h`, `vertex shader`, and `fragment shader` in Supporting files. <br />
  Just right click button mouse to add new Empty file, and nameed the file as `shader.h` or `vertex shader`, or `fragment shader`. <br />   **Note:** name you vertex shader as `XXX.vert` and name your fragment shader as `XXX.frag`.<br />
  
  ```cpp
  #include <GL/glew.h>
  #include "sphere.h"

  #include <glut/glut.h>
  #include <iostream>

  #include "Shader.h"
  #include <vector>

  #include <GLFW/glfw3.h>

  #include "glm/glm.hpp"
  #include <glm/gtc/matrix_transform.hpp>
  #include <glm/gtc/type_ptr.hpp>
  ```

  <img width="1047" alt="screen shot 2017-04-05 at 10 12 07 pm" src="https://cloud.githubusercontent.com/assets/16565587/24738794/0053bad8-1a4d-11e7-9be6-591b21612c92.png">


- Finally, I have these several files in my project. The `objects.h` file is written for draw triangle. <br /> 

  <img width="255" alt="screen shot 2017-04-05 at 10 18 02 pm" src="https://cloud.githubusercontent.com/assets/16565587/24738948/0d394fbe-1a4e-11e7-8a21-3fcbf8bcd604.png">

- In main.cpp file., `Shader shader("basic.vert", "basic.frag")` to generate vertex shader and fragment shader.<br />
  
  ```cpp
   Shader shader("basic.vert", "basic.frag");
   shader.Use();
  
  ```
  
  `shader.Use()` is a function call in shader.h It means Installing a program object as part of current rendering state.
  
  ```cpp
  // Uses the current shader
    void Use()
    {
        glUseProgram(this->Program);
    }
  ```
 
- In vertex and fragment shader, we have to declare our version of OepnGL by adding `#version 410 core` in the beginning of file. Here I    use OpenGL 4.1, I type `#version 410 core`. Check your version in this [Link](https://en.wikipedia.org/wiki/OpenGL_Shading_Language).<br />  
  This is my fragment shader. In new version of OpenGL, `gl_fragcolor` is deprecated. We output the `color` instead of `gl_fragcolor`.<br />  
  
  ```glsl
  #version 410 core

  out vec4 color;
  in vec4 vertexColor; // from vertex shader 

  void main()
  {
     color = vertexColor;

  }
   
  ```
- In vertex shader, `gl_modelviewprojectionmatrix` and `gl_vertex` are also deprecated. Here I use `projection_matrix * view_matrix *  model_matrix * vec4(vertexPosition_modelspace,1.0f)` instead of `gl_modelviewprojectionmatrix * gl_vertex`. <br />    

  ```glsl
  #version 410 core
  layout(location = 0) in vec3 vertexPosition_modelspace;
  layout(location = 1) in vec3 colorful;
  out vec4 vertexColor;
  uniform mat4 MVP;

  uniform mat4 projection_matrix;
  uniform mat4 view_matrix;
  uniform mat4 model_matrix;
  void main()
  {
     gl_Position = projection_matrix * view_matrix * model_matrix * vec4(vertexPosition_modelspace,1.0f);
     //    gl_Position =vec4(vertexPosition_modelspace,1.0f);
     vertexColor = vec4(1, 0, 0, 1.0);
     //  vertexColor = vec4(colorful,1.0f);
  }

  ```
### Step 5: Performance.

![triangles](https://cloud.githubusercontent.com/assets/16565587/24740587/bff0e006-1a56-11e7-8247-99e90a8ca8c3.gif)

If you have nay questions, please let me know. I am glad to help you! :blush:
