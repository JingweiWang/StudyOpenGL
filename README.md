# StudyOpenGL

这是我在学习OpenGL时写的demo.

## 如何编译? 

### *macOS* 

在 *终端* 中执行如下命令即可

```bash
$ gcc -framework GLUT -framework OpenGL *.c -o ../bin/*

$ ./*
```

### *Windows* 

请确保在 *32位* 系统下.

1. 下载 [glut-3.7.6-bin.zip](./glut-3.7.6-bin.zip) 并解压缩, 如有兴趣请使用源码编译 [glut-3.7.6-src.zip](./glut-3.7.6-src.zip) . 
2. 将里面的 *glut.h* 复制到 `C:\Program Files\Microsoft Visual Studio\VC98\Include\GL` 下; 
3. 将 *glut32.dll* 复制到 `C:\Program Files\Microsoft Visual Studio\VC98\Lib` 下; 
4. 将 *glut32.lib* 复制到 `C:\Windows\System32` 下即可使用 *Visual C++ 6.0* 进行编译运行.

## *macOS* 与 *Windows* 头文件区别

下面举例两个系统的头文件不同, 对应修改即可. 

*macOS* 下的头文件: 

```c
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
```

*Windows* 下的头文件: 

```c
#include <gl.h>
#include <glu.h>
#include <glut.h>
```