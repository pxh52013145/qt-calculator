@echo off
chcp 65001 >nul
echo ====================================
echo Qt 计算器项目 - 分步提交脚本
echo ====================================
echo.
echo 本脚本将按实验步骤分别提交代码，展示迭代过程
echo.
pause

echo.
echo [步骤1] 初始化项目框架...
git init
git add lab1.pro main.cpp
git add mainwindow.h mainwindow.cpp
echo 文件已添加到暂存区
git commit -m "步骤1: 初始化项目 - 创建Qt计算器基本框架

- 创建 main.cpp 程序入口
- 创建 MainWindow 类框架
- 配置 lab1.pro 项目文件"
echo 提交完成！
pause

echo.
echo [步骤2] UI界面设计...
git add mainwindow.ui
git commit -m "步骤2: UI界面布局与设计

- 使用 QLineEdit 创建显示屏
- 使用 QGridLayout 创建 4x6 按钮网格
- 添加数字按钮 0-9
- 添加运算符按钮 +, -, ×, ÷
- 添加功能按钮 C, CE, ⌫, =
- 添加高级功能按钮 x², √x, 1/x, %
- 设置窗口大小 380x580"
echo 提交完成！
pause

echo.
echo [步骤3] 按键事件处理...
git add mainwindow.h mainwindow.cpp
git commit -m "步骤3: 实现按键事件处理 - 数字输入、小数点、退格

- 实现 digitClicked() 处理数字输入
- 实现 decimalClicked() 处理小数点输入
- 添加重复小数点检查
- 实现 backspaceClicked() 退格功能
- 添加 waitingForOperand 状态管理
- 连接信号和槽"
echo 提交完成！
pause

echo.
echo [步骤4] 双操作符处理...
git add mainwindow.cpp
git commit -m "步骤4: 实现双操作符处理 - 完成四则运算逻辑

- 实现 operatorClicked() 处理运算符
- 实现 calculate() 计算函数
- 支持加法、减法、乘法、除法
- 实现 equalsClicked() 等号功能
- 支持连续运算（如 2+3+4）
- 添加除零错误处理
- 实现百分比运算"
echo 提交完成！
pause

echo.
echo [步骤5] 单操作符处理...
git add mainwindow.cpp
git commit -m "步骤5: 实现单操作符处理 - 平方、开方、倒数

- 实现 unaryOperatorClicked() 单操作符处理
- 添加平方运算 (x²)
- 添加平方根运算 (√x)
- 添加倒数运算 (1/x)
- 实现 negateClicked() 正负号切换
- 添加负数开方错误处理
- 添加除零错误处理"
echo 提交完成！
pause

echo.
echo [步骤6] 样式表美化...
git add mainwindow.cpp
git commit -m "步骤6: 使用样式表改善界面

- 实现 applyStyles() 函数
- 设置主窗口浅灰色背景
- 设置显示屏白色背景和圆角边框
- 设置数字按钮纯白色样式
- 设置功能按钮浅灰色样式
- 设置运算符按钮样式
- 设置等号按钮蓝色高亮
- 添加 hover 悬停效果
- 添加 pressed 按下效果"
echo 提交完成！
pause

echo.
echo [步骤7] 键盘事件处理...
git add mainwindow.h mainwindow.cpp
git commit -m "步骤7: 实现键盘事件处理

- 重写 keyPressEvent() 函数
- 映射数字键 0-9
- 映射运算符键 +, -, *, /
- 映射等号键 Enter, =
- 映射小数点键 ., ,
- 映射退格键 Backspace
- 映射清除键 Esc, Delete
- 实现键盘和鼠标统一处理"
echo 提交完成！
pause

echo.
echo [步骤8] 添加项目文档...
git add README.md 实验报告.md GIT使用指南.md .gitignore
git commit -m "步骤8: 添加项目文档和说明

- 添加 README.md 项目说明
- 添加实验报告模板
- 添加 Git 使用指南
- 添加 .gitignore 文件"
echo 提交完成！
pause

echo.
echo ====================================
echo 所有步骤提交完成！
echo ====================================
echo.
echo 查看提交历史:
git log --oneline --graph --all
echo.
echo.
echo 下一步: 推送到 GitHub
echo 1. 在 GitHub 创建仓库: qt-calculator
echo 2. 运行命令:
echo    git remote add origin https://github.com/你的用户名/qt-calculator.git
echo    git branch -M main
echo    git push -u origin main
echo.
pause

