@echo off
echo ====================================
echo Qt 计算器项目 - Git 初始化脚本
echo ====================================
echo.

echo [1] 初始化 Git 仓库...
git init
echo.

echo [2] 添加文件到暂存区...
git add .gitignore
git add lab1.pro main.cpp mainwindow.h mainwindow.cpp mainwindow.ui
git add README.md 实验报告.md GIT使用指南.md
echo.

echo [3] 创建初始提交...
git commit -m "初始提交: Qt计算器项目完整实现

包含功能:
- UI界面设计
- 数字输入和小数点处理
- 四则运算逻辑
- 单操作符功能（平方、开方、倒数）
- 样式表美化
- 键盘事件处理
- 完整文档"
echo.

echo [4] 查看提交历史...
git log --oneline
echo.

echo ====================================
echo Git 仓库初始化完成！
echo ====================================
echo.
echo 下一步操作:
echo 1. 在 GitHub 上创建远程仓库
echo 2. 运行以下命令连接远程仓库:
echo    git remote add origin https://github.com/你的用户名/qt-calculator.git
echo    git branch -M main
echo    git push -u origin main
echo.
pause

