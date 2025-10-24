# Git 使用指南 - 计算器项目

## 初始化 Git 仓库

### 1. 本地初始化

```bash
# 进入项目目录
cd lab1

# 初始化 Git 仓库
git init

# 查看状态
git status
```

### 2. 添加 .gitignore 文件

创建 `.gitignore` 文件，忽略不需要版本控制的文件：

```
# Qt 编译文件
build/
*.o
*.obj
*.exe
*.dll
*.so
*.dylib
moc_*.cpp
ui_*.h
qrc_*.cpp
Makefile
Makefile.*

# Qt Creator 文件
*.pro.user
*.pro.user.*

# IDE 文件
.vscode/
.idea/
*.swp
*~

# 临时文件
*.tmp
*.temp
*.log
```

## 代码迭代流程

### 步骤 1：UI 界面设计

```bash
# 添加 UI 文件
git add mainwindow.ui

# 提交
git commit -m "步骤1: 完成UI界面设计

- 创建 4x6 按钮网格布局
- 添加显示屏 QLineEdit
- 设置窗口大小为 380x580
- 添加所有按钮：数字、运算符、功能按钮"

# 查看提交历史
git log --oneline
```

### 步骤 2：按键事件处理

```bash
# 添加修改的文件
git add mainwindow.h mainwindow.cpp

# 提交
git commit -m "步骤2: 实现按键事件处理

- 实现数字按钮点击处理
- 添加小数点输入和重复检查
- 实现退格功能
- 添加 waitingForOperand 状态管理"
```

### 步骤 3：双操作符处理

```bash
git add mainwindow.cpp

git commit -m "步骤3: 实现双操作符处理

- 实现四则运算逻辑
- 添加 calculate() 计算函数
- 实现连续运算功能
- 添加除零错误处理"
```

### 步骤 4：单操作符处理

```bash
git add mainwindow.cpp

git commit -m "步骤4: 实现单操作符处理

- 添加平方运算 (x²)
- 添加平方根运算 (√x)
- 添加倒数运算 (1/x)
- 添加正负号切换 (+/-)
- 实现错误处理（负数开方、除零）"
```

### 步骤 5：样式表美化

```bash
git add mainwindow.cpp

git commit -m "步骤5: 使用样式表改善界面

- 添加 applyStyles() 函数
- 设置显示屏白色背景和圆角
- 设置数字按钮白色样式
- 设置功能按钮浅灰色样式
- 设置等号按钮蓝色高亮
- 添加 hover 和 pressed 效果"
```

### 步骤 6：键盘事件处理

```bash
git add mainwindow.h mainwindow.cpp

git commit -m "步骤6: 实现键盘事件处理

- 重写 keyPressEvent() 函数
- 映射数字键 0-9
- 映射运算符键 +, -, *, /
- 映射功能键 Enter, Backspace, Esc, Delete
- 实现键盘和鼠标操作统一处理"
```

### 步骤 7：添加文档

```bash
git add README.md 实验报告.md GIT使用指南.md

git commit -m "步骤7: 添加项目文档

- 添加 README.md 项目说明
- 添加实验报告模板
- 添加 Git 使用指南"
```

## 创建 GitHub 远程仓库

### 1. 在 GitHub 上创建仓库

1. 登录 GitHub
2. 点击右上角 "+" → "New repository"
3. 填写仓库名称：`qt-calculator`
4. 选择 Public 或 Private
5. 不要勾选 "Initialize this repository with a README"
6. 点击 "Create repository"

### 2. 连接远程仓库

```bash
# 添加远程仓库
git remote add origin https://github.com/你的用户名/qt-calculator.git

# 查看远程仓库
git remote -v

# 推送到远程仓库
git push -u origin main
```

如果默认分支是 `master`，可以重命名为 `main`：

```bash
git branch -M main
git push -u origin main
```

## 常用 Git 命令

### 查看状态和历史

```bash
# 查看当前状态
git status

# 查看提交历史
git log

# 查看简洁历史
git log --oneline

# 查看图形化历史
git log --graph --oneline --all

# 查看某次提交的详细信息
git show <commit-hash>
```

### 添加和提交

```bash
# 添加单个文件
git add mainwindow.cpp

# 添加多个文件
git add mainwindow.h mainwindow.cpp

# 添加所有修改
git add .

# 提交
git commit -m "提交信息"

# 修改最后一次提交
git commit --amend
```

### 分支管理

```bash
# 查看分支
git branch

# 创建分支
git branch feature-new

# 切换分支
git checkout feature-new

# 创建并切换分支
git checkout -b feature-new

# 合并分支
git checkout main
git merge feature-new

# 删除分支
git branch -d feature-new
```

### 撤销和回退

```bash
# 撤销工作区的修改
git checkout -- mainwindow.cpp

# 撤销暂存区的文件
git reset HEAD mainwindow.cpp

# 回退到上一个版本
git reset --soft HEAD^

# 回退到指定版本
git reset --hard <commit-hash>
```

### 同步远程仓库

```bash
# 拉取远程更新
git pull origin main

# 推送到远程
git push origin main

# 查看远程仓库信息
git remote show origin
```

## 提交信息规范

### 格式

```
<类型>: <简短描述>

<详细描述>

<相关问题>
```

### 类型

- `feat`：新功能
- `fix`：修复 bug
- `docs`：文档更新
- `style`：代码格式调整（不影响功能）
- `refactor`：代码重构
- `test`：测试相关
- `chore`：构建过程或辅助工具的变动

### 示例

```bash
git commit -m "feat: 添加平方根计算功能

实现了平方根按钮的功能，包括：
- 添加 √x 按钮
- 实现 unaryOperatorClicked() 处理
- 添加负数检查和错误提示

相关: #12"
```

## 实验要求的提交

为了满足实验要求"有体现代码迭代过程"，建议按照以下步骤提交：

```bash
# 1. 初始提交
git add lab1.pro main.cpp mainwindow.h mainwindow.cpp
git commit -m "初始化项目：创建Qt计算器基本框架"

# 2. UI设计
git add mainwindow.ui
git commit -m "步骤1: 完成UI界面布局设计"

# 3. 基本功能
git add mainwindow.h mainwindow.cpp
git commit -m "步骤2: 实现数字输入和基本按键处理"

# 4. 运算逻辑
git add mainwindow.cpp
git commit -m "步骤3: 实现四则运算逻辑和连续计算"

# 5. 高级功能
git add mainwindow.cpp
git commit -m "步骤4: 添加单操作符功能（平方、开方、倒数）"

# 6. 界面美化
git add mainwindow.cpp
git commit -m "步骤5: 使用QSS样式表美化界面"

# 7. 键盘支持
git add mainwindow.h mainwindow.cpp
git commit -m "步骤6: 实现键盘事件处理和快捷键"

# 8. 文档
git add README.md 实验报告.md
git commit -m "步骤7: 添加项目文档和实验报告"
```

## 查看提交历史（用于实验报告）

```bash
# 查看所有提交
git log

# 查看简洁版本
git log --oneline --graph

# 导出提交历史
git log --pretty=format:"%h - %an, %ar : %s" > git_history.txt

# 查看某个文件的修改历史
git log --follow mainwindow.cpp

# 查看代码统计
git log --stat
```

## 生成提交统计（用于实验报告）

```bash
# 查看贡献统计
git shortlog -sn

# 查看代码行数统计
git log --author="你的名字" --pretty=tformat: --numstat | \
  awk '{ add += $1; subs += $2; loc += $1 - $2 } END \
  { printf "added lines: %s removed lines: %s total lines: %s\n", add, subs, loc }'

# 生成可视化图表（需要安装 git-stats）
git-stats
```

## 故障排除

### 问题 1：push 被拒绝

```bash
# 原因：远程仓库有更新
# 解决：先拉取再推送
git pull origin main --rebase
git push origin main
```

### 问题 2：合并冲突

```bash
# 1. 查看冲突文件
git status

# 2. 手动编辑冲突文件，解决冲突标记
# <<<<<<< HEAD
# =======
# >>>>>>> branch-name

# 3. 添加已解决的文件
git add <conflict-file>

# 4. 完成合并
git commit
```

### 问题 3：误提交大文件

```bash
# 从历史中删除大文件
git filter-branch --force --index-filter \
  "git rm --cached --ignore-unmatch <大文件路径>" \
  --prune-empty --tag-name-filter cat -- --all

# 强制推送
git push origin --force --all
```

## 总结

使用 Git 进行版本控制的好处：

1. **追踪变更**：可以看到代码的每一次修改
2. **回退版本**：出问题时可以轻松回到之前的状态
3. **协作开发**：多人可以同时开发不同功能
4. **代码备份**：代码安全存储在云端
5. **学习记录**：完整的开发过程可用于学习和复习

按照本指南操作，你将拥有一个清晰的代码迭代历史，满足实验要求。
