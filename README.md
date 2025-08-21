# shell
A simple C shell/command line interpreter.
---

### **Simple Shell Project Roadmap**

#### **PHASE 0 – Project Setup** ✅

| Step | Task                                                              |
| ---- | ----------------------------------------------------------------- |
| 0.1  | Create project folder & initialize Git repository ✅              |
| 0.2  | Set up basic C project structure (`src/`, `include/`, `Makefile`) ✅|
| 0.3  | Write a minimal `main.c` that prints a welcome message ✅           |
| 0.4  | Add `.gitignore` (e.g., `*.o`, `*.out`, `*.exe`) ✅               |

---

#### **PHASE 1 – Core Shell Loop**

| Step | Task                                          |
| ---- | --------------------------------------------- |
| 1.1  | Implement a prompt (`myshell> `)              |
| 1.2  | Read user input with `getline()` or `fgets()` |
| 1.3  | Echo the input back (basic REPL loop)         |
| 1.4  | Implement `exit` command to quit              |

---

#### **PHASE 2 – Command Execution**

| Step | Task                                               |
| ---- | -------------------------------------------------- |
| 2.1  | Parse user input into command + arguments          |
| 2.2  | Use `fork()` + `execvp()` to run external commands |
| 2.3  | Use `wait()` to handle child processes             |
| 2.4  | Handle basic errors (e.g., command not found)      |

---

#### **PHASE 3 – Built-in Commands**

| Step | Task                                |
| ---- | ----------------------------------- |
| 3.1  | Add `cd` (change directory)         |
| 3.2  | Add `pwd` (print working directory) |
| 3.3  | Add `help` (list built-in commands) |

---

#### **PHASE 4 – Advanced Features**

| Step | Task                                        |             |
| ---- | ------------------------------------------- | ----------- |
| 4.1  | Support input/output redirection (`>`, `<`) |             |
| 4.2  | Implement command piping (\`ls              | grep txt\`) |
| 4.3  | Handle background processes (`&`)           |             |

---

#### **PHASE 5 – Polish & Documentation**

| Step | Task                                    |
| ---- | --------------------------------------- |
| 5.1  | Add comments and function documentation |
| 5.2  | Write a usage guide in `README.md`      |
| 5.3  | Create example commands section         |
| 5.4  | Final code cleanup and testing          |

---