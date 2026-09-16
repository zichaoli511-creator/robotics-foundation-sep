# 常见问题与排查方法

这里记录 2026 年 9 月 15 日环境搭建过程中实际遇到的问题。

## 1. 重启后搜索不到 Ubuntu 22.04

Windows 搜索结果有时不会立即显示刚安装的应用。可以直接在 PowerShell 中启动：

```powershell
wsl -d Ubuntu-22.04
```

也可以检查已经安装的发行版：

```powershell
wsl -l -v
```

第一次启动时出现 `Create a default Unix user account`，说明 Ubuntu 已经安装成功，正在进行初始化。

## 2. 下载很慢是否正常

WSL 或 Ubuntu 下载速度受网络、微软服务器和代理设置影响。只要百分比持续变化且没有错误，就可以继续等待。安装完成后会自动进入初始化流程。

不要在仍有进度时重复运行安装命令，以免同时启动多个安装过程。

## 3. 出现 localhost 代理警告

可能看到：

```text
wsl: 检测到 localhost 代理配置，但未镜像到 WSL。
NAT 模式下的 WSL 不支持 localhost 代理。
```

含义是 Windows 配置了只监听 `localhost` 的代理，而 WSL 2 的 NAT 网络不能直接把自己的 `localhost` 当作 Windows 的 `localhost`。

处理原则：

1. 先测试 Ubuntu 是否能正常访问软件源。
2. 如果 `sudo apt update` 能成功，可以暂时忽略警告。
3. 如果网络失败，再检查 Windows 代理工具是否允许局域网连接，或调整 WSL 网络模式。
4. 不要为了消除提示随意关闭公司、学校或个人所需的安全代理。

## 4. VS Code 扩展商店显示 `Failed to fetch`

这通常是 VS Code 无法访问扩展市场，常见原因是网络、代理或临时服务问题，并不代表 WSL 或项目损坏。

可以依次尝试：

1. 确认浏览器可以访问网络。
2. 等待片刻后刷新扩展页面。
3. 重新打开 VS Code。
4. 检查 Windows 与 VS Code 的代理设置是否一致。

如果从 Ubuntu 仓库目录执行 `code .` 后，左下角已经显示 `WSL: Ubuntu-22.04`，说明 WSL 连接已经建立成功。

## 5. VS Code 终端为什么是 PowerShell

即使打开了位于 WSL 的文件夹，已有终端也可能仍是 PowerShell。判断方法：

- PowerShell 提示符通常以 `PS` 开头。
- Ubuntu Bash 提示符通常类似 `robot@lzc:~$`。

可以关闭 PowerShell 终端，再点击终端面板中的加号，新建 WSL/Bash 终端。

## 6. 在 C、D、E 盘找不到项目

项目创建在 Ubuntu 的 Linux 文件系统中：

```text
/home/robot/robotics-foundation-sep
```

它不是普通的 `C:\...` 或 `D:\...` 文件夹。Windows 文件资源管理器可以通过下面的地址查看：

```text
\\wsl.localhost\Ubuntu-22.04\home\robot\robotics-foundation-sep
```

推荐使用 VS Code 的 WSL 模式或 Ubuntu 终端操作项目。不要寻找并直接修改 WSL 的 `.vhdx` 虚拟磁盘文件。

## 7. GitHub 上为什么没有本地项目

以下操作只影响本地：

```bash
git init -b main
git add README.md
git commit -m "docs: add project README"
```

只有创建或连接远程仓库并执行 `git push` 后，GitHub 网站才会出现对应内容。

检查远程连接：

```bash
git remote -v
```

检查本地与远程分支状态：

```bash
git status -sb
```

看到类似下面的内容表示本地 `main` 正在跟踪远程 `origin/main`：

```text
## main...origin/main
```

## 8. 重复安装已经存在的软件会怎样

使用 APT 重复安装同一个软件通常不会产生两个副本，也不会破坏环境。APT 会显示软件已经是最新版本，或者把它升级到软件源提供的版本。

仍然建议先阅读终端将要进行的操作，尤其不要随意加入删除参数或执行不理解的清理命令。

## 9. 快速收集排查信息

进入仓库运行：

```bash
bash scripts/check_environment.sh
git status -sb
git remote -v
```

把输出保留下来，就能快速判断是工具缺失、仓库状态问题，还是远程连接问题。
