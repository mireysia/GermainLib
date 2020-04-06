# GERMAINLIB

## Introduction



## SOMMAIRE

1. File organisation
2. code specification
3. Git
4. Cmake Build system
   
### 1. File organisation

#### File tree structure

```
.
├── AUTHORS
├── CMakeLists.txt
├── apps
│   ├── CMakeLists.txt
│   └── main.c
├── cmake
│   └── add_FetchContent_MakeAvailable.cmake
├── docs
│   └── CMakeLists.txt
├── include
│   └── germainLib
│       ├── doubleLinkedList.h
│       ├── node_doublelink.h
│       ├── node_simplelink.h
│       ├── queue.h
│       ├── simpleLinkedList.h
│       └── stack.h
├── readme.md
├── src
│   ├── CMakeLists.txt
│   ├── doubleLinkedList.c
│   ├── node_doublelink.c
│   ├── node_simplelink.c
│   ├── queue.c
│   ├── simpleLinkedList.c
│   └── stack.c
└── test
    ├── CMakeLists.txt
    └── test.c

```

useful command to generate tree in terminal :

```
    sudo apt install tree
    tree
```

### 2. Documentation


### 3. Code specifiation

#### General specifiation

- **Every headers file must start with :**

```c
    #ifndef __HEADER_NAME_H__
    #define __HEADER_NAME_H__

    /* Place your code here */

    #endif /* HEADER_NAME_H */
```
- **You should use a code beautifier**

### 5. Git

- **Gitkraken is a good choice to avoid mistake**

- useful command :

check what's going on

```
    git status
```

list all commit on your branch

```
    git log
```

list branches

```
    git branch
```
new branch for current branch
```
    git branch your_branch_name
```
add all files to the versionning
```
    git add .
```
commit modifications and add all files
```
    git commit -m "your message" .
```
push the local modification to the server
```
    git push branch_name origin/remote_branch_name
```
configure your name and email
```
    git config --global user.name "your name"
    git config --global user.email "foo@bar.com"
```
initialize a new repo
```
    git init
```

- **never work on the same branch unless you do not edit the same file**
  

### Cmake Build system

### Build the project :

- install cmake :
```
    Linux : sudo apt install cmake
```
```
    Macos : brew install cmake
```

- configure build 
```
    cmake -S . -B build
```
- build main program :
```
    cmake --build build
```
- build tests : (debug only please)
```
    cmake --build build --target test
    cd test
    ./testlib
```
- build apps 
```
    cmake --build build
    ./main
``` 