#!/usr/bin/env bash

# 9 月 15 日开发环境只读验收脚本。
# 它不会安装、更新、删除或修改任何软件。

set -u

PASS_COUNT=0
FAIL_COUNT=0

pass() {
  printf '[通过] %s\n' "$1"
  PASS_COUNT=$((PASS_COUNT + 1))
}

fail() {
  printf '[缺失] %s\n' "$1"
  FAIL_COUNT=$((FAIL_COUNT + 1))
}

check_command() {
  local command_name="$1"
  local label="$2"
  shift 2

  if command -v "$command_name" >/dev/null 2>&1; then
    pass "$label：$($@ 2>&1 | head -n 1)"
  else
    fail "$label（找不到命令：$command_name）"
  fi
}

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

printf '%s\n' '=== Robotics Foundation：环境验收 ==='
printf '项目路径：%s\n' "$PROJECT_ROOT"
printf '检查时间：%s\n\n' "$(date '+%Y-%m-%d %H:%M:%S %Z')"

if grep -qi microsoft /proc/version 2>/dev/null; then
  pass "WSL 环境：$(uname -r)"
else
  fail '当前系统看起来不是 WSL；请在 Ubuntu/WSL 终端运行本脚本'
fi

if [ -r /etc/os-release ]; then
  # shellcheck disable=SC1091
  . /etc/os-release
  pass "Linux 发行版：${PRETTY_NAME:-未知}"
else
  fail '无法读取 /etc/os-release'
fi

check_command gcc 'GCC' gcc --version
check_command g++ 'G++' g++ --version
check_command cmake 'CMake' cmake --version
check_command git 'Git' git --version
check_command python3 'Python' python3 --version

if python3 -m pip --version >/dev/null 2>&1; then
  pass "pip：$(python3 -m pip --version)"
else
  fail 'Python pip'
fi

if python3 -m venv --help >/dev/null 2>&1; then
  pass 'Python venv：可用'
else
  fail 'Python venv'
fi

if [ -f /usr/include/eigen3/Eigen/Core ]; then
  if dpkg-query -W -f='${Version}' libeigen3-dev >/dev/null 2>&1; then
    pass "Eigen：$(dpkg-query -W -f='${Version}' libeigen3-dev)"
  else
    pass 'Eigen：头文件存在'
  fi
else
  fail 'Eigen 3（找不到 /usr/include/eigen3/Eigen/Core）'
fi

if git -C "$PROJECT_ROOT" rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  BRANCH="$(git -C "$PROJECT_ROOT" branch --show-current)"
  pass "Git 仓库：当前分支 ${BRANCH:-未知}"

  if REMOTE_URL="$(git -C "$PROJECT_ROOT" remote get-url origin 2>/dev/null)"; then
    pass "GitHub 远程地址：$REMOTE_URL"
  else
    fail 'GitHub 远程地址 origin'
  fi
else
  fail '当前项目不是 Git 仓库'
fi

printf '\n通过：%d，缺失：%d\n' "$PASS_COUNT" "$FAIL_COUNT"

if [ "$FAIL_COUNT" -eq 0 ]; then
  printf '%s\n' '验收结果：通过'
  exit 0
fi

printf '%s\n' '验收结果：未通过，请根据“缺失”项目排查'
exit 1
