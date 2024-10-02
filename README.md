#  Minishell

Minishell is a simple shell written in C, replicating basic functionality of Unix shells like Bash.

---

## 📋 Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Installation](#installation)
- [Bonus Features](#bonus-features)

---

## 🔰 Introduction

Minishell allows users to execute commands, handle pipes, redirections, and manage environment variables. It's a great way to learn more about processes, system calls, and file descriptors.

---

## ⚙️ Features

- Command prompt and history.
- Execute commands using absolute, relative paths, or `$PATH`.
- Pipes (`|`) and redirections (`>`, `>>`, `<`, `<<`).
- Signal handling (`ctrl-C`, `ctrl-D`, `ctrl-\`).
- Built-in commands support.

---

## 🚀 Usage

Run the shell:

```bash
./minishell
```
Example command:

```bash
$ ls | grep minishell > result.txt
```
🛠️ Built-in Commands

    echo [-n] [text]
    cd [directory]
    pwd
    export [VAR=value]
    unset [VAR]
    env
    exit [status]

📦 Installation

Clone the repository:

``` bash
git clone https://github.com/bennamrouche/minishell.git
``` 
## Compile the project:

```bash
make
#Run the shell:
./minishell
``` 
✨ Bonus Features

    Logical operators && and ||.
    Wildcards (*) for file matching.