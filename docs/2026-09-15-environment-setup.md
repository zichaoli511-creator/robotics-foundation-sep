# 2026-09-15：从零搭建机器人开发环境

## 1. 今天完成了什么

今天的目标不是开始写复杂程序，而是准备一个稳定、可重复检查的 Linux 开发环境，并完成第一次 GitHub 上传。

最终结构如下：

```text
Windows 11
└── WSL 2
    └── Ubuntu 22.04 LTS
        ├── GCC / G++
        ├── CMake
        ├── Git
        ├── Python / pip / venv
        ├── Eigen 3
        └── robotics-foundation-sep
```

可以这样理解：

- Windows 是电脑的主操作系统。
- WSL 2 让 Windows 内部能够运行真正的 Linux 环境。
- Ubuntu 是安装在 WSL 中的 Linux 发行版。
- VS Code 是编辑器；通过 WSL 扩展，它可以直接编辑 Ubuntu 中的文件。
- Git 负责记录本地修改；GitHub 负责保存和展示上传后的远程仓库。

## 2. 安装 WSL 2 与 Ubuntu

在 Windows PowerShell 中执行过：

```powershell
wsl --install --web-download -d Ubuntu-22.04
```

安装完成后按系统提示重启。第一次启动 Ubuntu 时，需要创建 Linux 用户名和密码。本机创建的用户名是：

```text
robot
```

输入 Linux 密码时，终端不会显示圆点或星号，这是正常的安全设计；输入完成后按 Enter 即可。

看到类似下面的提示符，说明已经进入 Ubuntu：

```text
robot@lzc:~$
```

提示符各部分的含义：

- `robot`：当前用户
- `lzc`：计算机名
- `~`：当前位于用户主目录 `/home/robot`
- `$`：普通用户命令提示符

## 3. 更新软件包索引

在 Ubuntu 终端执行：

```bash
sudo apt update
```

`sudo` 表示临时使用管理员权限；系统会要求输入刚才创建的 Linux 密码。`apt update` 只更新“可安装软件清单”，不会自动升级全部软件。

出现下面的文字表示软件包索引更新成功：

```text
Reading package lists... Done
```

如果看到“有若干软件包可以升级”，并不代表安装失败，也不影响当天的环境搭建验收。

## 4. 安装开发工具

使用的软件包如下：

```bash
sudo apt install -y build-essential cmake git python3 python3-pip python3-venv libeigen3-dev
```

各软件包的作用：

| 软件包 | 作用 |
| --- | --- |
| `build-essential` | 安装 GCC、G++、Make 等基础 C/C++ 编译工具 |
| `cmake` | 生成和管理 C/C++ 项目的构建过程 |
| `git` | 记录代码历史，与 GitHub 同步 |
| `python3` | Python 解释器 |
| `python3-pip` | 安装 Python 第三方库 |
| `python3-venv` | 创建相互隔离的 Python 虚拟环境 |
| `libeigen3-dev` | 常用于机器人计算的 C++ 矩阵库 |

重复执行这条安装命令通常不会造成问题。APT 会识别已经安装的软件，只补充缺少的软件或处理可用更新。

## 5. 验证工具版本

当天逐项执行了：

```bash
gcc --version
g++ --version
cmake --version
git --version
python3 --version
```

验收结果：

```text
gcc 11.4.0
g++ 11.4.0
cmake 3.22.1
git 2.34.1
Python 3.10.12
```

现在也可以在仓库中一次完成复查：

```bash
bash scripts/check_environment.sh
```

## 6. 创建本地 Git 仓库

在 Ubuntu 终端执行过：

```bash
mkdir -p ~/robotics-foundation-sep
cd ~/robotics-foundation-sep
git init -b main
```

命令解释：

- `mkdir -p`：创建目录；目录已经存在时也不会报错。
- `cd`：进入目录。
- `~`：当前 Linux 用户的主目录，即 `/home/robot`。
- `git init`：让当前目录成为 Git 仓库。
- `-b main`：将初始分支命名为 `main`。

使用以下命令可以确认位置和隐藏文件：

```bash
pwd
ls -la
```

其中 `.git` 是 Git 保存版本历史和仓库配置的隐藏目录，不要手动修改里面的内容。

## 7. 使用 VS Code 连接 WSL

在仓库目录中执行：

```bash
code .
```

末尾的点号 `.` 表示“用 VS Code 打开当前目录”。

连接正确时，VS Code 左下角会显示类似：

```text
WSL: Ubuntu-22.04
```

VS Code 内置终端的提示符也应类似：

```text
robot@lzc:~/robotics-foundation-sep$
```

如果终端开头显示 `PS Microsoft.PowerShell...`，说明那是 PowerShell，而不是 Ubuntu 的 Bash。可以关闭该终端，再从 WSL 窗口中新建 Bash 终端。

## 8. 理解本地仓库与 GitHub

执行 `git init` 只会创建本地仓库，不会自动在 GitHub 网站生成项目。两者的关系是：

```text
本地文件 → Git 提交 → GitHub 远程仓库
```

第一次提交使用的核心命令：

```bash
git add README.md
git commit -m "docs: add project README"
git status
git log --oneline
```

命令解释：

- `git add`：选择要放进下一次提交的修改。
- `git commit`：把已选择的修改保存为一个本地历史节点。
- `git status`：查看当前分支和未提交修改。
- `git log --oneline`：用简短形式查看提交历史。

连接 GitHub 后，远程仓库地址为：

```text
https://github.com/zichaoli511-creator/robotics-foundation-sep.git
```

查看远程地址：

```bash
git remote -v
```

上传本地提交：

```bash
git push -u origin main
```

其中：

- `origin` 是远程仓库的常用别名。
- `main` 是要上传的本地分支。
- `-u` 建立本地 `main` 与远程 `origin/main` 的跟踪关系；以后通常直接执行 `git push` 即可。

## 9. 当天验收清单

- [x] Ubuntu 能正常启动
- [x] 可以使用用户 `robot` 登录
- [x] 软件包索引更新成功
- [x] GCC 和 G++ 可用
- [x] CMake 可用
- [x] Git 可用
- [x] Python 3 可用
- [x] pip 和 venv 已安装
- [x] Eigen 3 已安装
- [x] 本地仓库使用 `main` 分支
- [x] VS Code 已进入 WSL 环境
- [x] README 已提交
- [x] 本地仓库已连接 GitHub
- [x] 首个提交已推送到 GitHub

结论：**2026 年 9 月 15 日学习任务验收通过。**
