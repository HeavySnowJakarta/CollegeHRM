# CollegeHRM

College Human Resource Manager

> Note for ones who may concern: 这是我于 2024 年 6 月进行的课程设计作业，此项目 UI 部分使用 Qt Quick 框架开发。因涉及个人隐私信息，使用此开源代码编译产生的二进制文件与作为作业提交的二进制文件并不完全相同，区别在于 `.gitignore` 中的 `info.txt` 文件。本项目注释非常详细，您可参考随处可见的 README 文件。

## File Structure

```
.
├src                                Source codes.
│├lib                               C++ back-end.
├docs                               Some documents.
├scripts                            Scripts used for building, etc.
└xmake.lua                          Xmake configuration file.
```

## Requirements

+ Proper C/C++ toolchain (MSVC or GCC for example).
+ Qt (>=6.4) that fit the C/C++ toolchain with Qt Quick built-in.
+ Xmake >= 2.6.1
+ Lua >= 5.1

## Build&Run

ONLY TESTED ON WINDOWS.

```
xmake run
```

That's all (when the toolchain is set properly).

On current stage, the front-end development is just on progress, so you'll only see an example page after compliling (or compliling does not pass is also a normal case).