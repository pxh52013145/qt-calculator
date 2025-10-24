# GitHub 提交日志

## 项目仓库

- **GitHub 地址**：https://github.com/pxh52013145/qt-calculator
- **项目名称**：Qt Calculator
- **开发时间**：2025-10-24

---

## Git 提交历史（体现代码迭代过程）

### 提交记录列表

```
a7dd0f8 - Step 8: Add documentation and final optimization (2025-10-24)
96a923c - Step 7: Implement keyboard event handling (2025-10-24)
8ff4a35 - Step 6: Apply QSS stylesheets for modern UI design (2025-10-24)
32c7b01 - Step 5: Add unary operators (square, sqrt, reciprocal) (2025-10-24)
9b93648 - Step 4: Add arithmetic operations with operator precedence (2025-10-24)
3d086b3 - Step 3: Implement digit input and decimal point handling (2025-10-24)
a767777 - Step 2: Design UI layout with Qt Designer (2025-10-24)
f309c05 - Step 1: Initialize Qt Calculator Project (2025-10-24)
e6b034a - Add development changelog - showing iteration process (2025-10-24)
5a57600 - Remove unnecessary files (2025-10-24)
5171645 - 完成Qt计算器项目 (2025-10-24)
```

---

## 详细迭代过程

### Step 1: Initialize Qt Calculator Project (提交 f309c05)

**日期**：2025-10-24  
**内容**：

- 创建 Qt 项目基本框架
- 初始化 main.cpp 程序入口
- 创建 MainWindow 类结构
- 配置 lab1.pro 项目文件

---

### Step 2: Design UI layout with Qt Designer (提交 a767777)

**日期**：2025-10-24  
**内容**：

- 使用 Qt Designer 设计界面
- 创建显示容器（QWidget + VBoxLayout）
- 添加显示区域（两个 QLabel）
- 创建 4×6 按钮网格布局
- 添加 24 个按钮
- 设置组件属性和样式

---

### Step 3: Implement digit input and decimal point handling (提交 3d086b3)

**日期**：2025-10-24  
**内容**：

- 实现数字按钮点击处理
- 实现小数点输入功能
- 添加重复小数点检查
- 实现退格删除功能
- 连接信号和槽

**关键函数**：

- `digitClicked()` - 数字输入
- `decimalClicked()` - 小数点处理
- `backspaceClicked()` - 退格删除

---

### Step 4: Add arithmetic operations with operator precedence (提交 9b93648)

**日期**：2025-10-24  
**内容**：

- 实现运算符按钮处理
- **核心功能：递归表达式求值算法**
- **支持运算符优先级**（先乘除后加减）
- 实现实时预演算功能
- 实现等号计算功能
- 添加除零错误处理

**关键算法**：

- `evaluateExpression()` - 递归求值，支持优先级
- `operatorClicked()` - 运算符处理
- `equalsClicked()` - 等号计算
- `updateDisplay()` - 实时预演算

**技术亮点**：

- 1×2+3×2 = 8 ✓（正确处理优先级）
- 实时显示预演算结果
- 支持连续运算

---

### Step 5: Add unary operators (提交 32c7b01)

**日期**：2025-10-24  
**内容**：

- 实现平方运算 (x²)
- 实现平方根运算 (√x)
- 实现倒数运算 (1/x)
- 实现正负号切换 (+/-)
- 添加错误处理（负数开方、零的倒数）

**关键函数**：

- `unaryOperatorClicked()` - 单操作符处理
- `negateClicked()` - 正负号切换

---

### Step 6: Apply QSS stylesheets (提交 8ff4a35)

**日期**：2025-10-24  
**内容**：

- 实现 `applyStyles()` 函数
- 设置主窗口背景色
- 设置显示容器样式（白色背景，圆角）
- 设置数字按钮样式（白色）
- 设置功能按钮样式（浅灰）
- 设置等号按钮样式（蓝色高亮）
- 添加悬停效果（hover）
- 添加点击效果（pressed）

**配色方案**：

- 主窗口：#F3F3F3
- 数字按钮：#FFFFFF
- 功能按钮：#F8F8F8
- 等号按钮：#A0C8E8

---

### Step 7: Implement keyboard event handling (提交 96a923c)

**日期**：2025-10-24  
**内容**：

- 重写 `keyPressEvent()` 函数
- 映射数字键 0-9
- 映射运算符键 +, -, \*, /
- 映射功能键 Enter, Backspace, Esc, Delete
- 映射小数点键
- 实现键盘和鼠标统一操作

**支持的快捷键**：

- 数字键：0-9
- 运算符：+, -, \*, /
- 等号：Enter
- 退格：Backspace
- 清除：Esc

---

### Step 8: Add documentation and final optimization (提交 a7dd0f8)

**日期**：2025-10-24  
**内容**：

- 添加 README.md 项目说明
- 完善实验报告
- 添加 Git 使用指南
- 优化显示区域间距
- 去除预演算的"="符号
- 修复窗口标题设置问题

**优化内容**：

- 表达式和预演算紧密贴合
- 预演算只显示数字
- 完善文档

---

## 提交统计

- **总提交数**：11 次
- **代码迭代步骤**：8 步
- **开发周期**：1 天
- **主要功能**：20+ 个

---

## 命令行日志

### 查看提交历史

```bash
$ git log --oneline
a7dd0f8 Step 8: Add documentation and final optimization
96a923c Step 7: Implement keyboard event handling
8ff4a35 Step 6: Apply QSS stylesheets for modern UI design
32c7b01 Step 5: Add unary operators (square, sqrt, reciprocal)
9b93648 Step 4: Add arithmetic operations with operator precedence
3d086b3 Step 3: Implement digit input and decimal point handling
a767777 Step 2: Design UI layout with Qt Designer
f309c05 Step 1: Initialize Qt Calculator Project
e6b034a Add development changelog - showing iteration process
5a57600 Remove unnecessary files
5171645 完成Qt计算器项目
```

### 查看提交详情

```bash
$ git log --stat --oneline
a7dd0f8 Step 8: Add documentation and final optimization
96a923c Step 7: Implement keyboard event handling
8ff4a35 Step 6: Apply QSS stylesheets for modern UI design
32c7b01 Step 5: Add unary operators (square, sqrt, reciprocal)
9b93648 Step 4: Add arithmetic operations with operator precedence
3d086b3 Step 3: Implement digit input and decimal point handling
a767777 Step 2: Design UI layout with Qt Designer
f309c05 Step 1: Initialize Qt Calculator Project
```

---

## 推送到 GitHub

### 推送命令

```bash
# 推送到远程仓库
git push origin main -f

# 查看远程仓库
git remote -v
```

### GitHub 仓库地址

https://github.com/pxh52013145/qt-calculator

---

## 代码迭代说明

本项目采用**迭代开发**模式，分 8 个步骤逐步完成：

1. **Step 1-2**：搭建基础框架和 UI 设计
2. **Step 3-4**：实现核心计算功能
3. **Step 5**：扩展高级功能
4. **Step 6**：美化用户界面
5. **Step 7**：增强交互体验
6. **Step 8**：完善文档和优化

每一步都有明确的提交记录，完整体现了项目的开发过程。

---

**生成日期**：2025-10-24  
**提交总数**：11 次  
**状态**：✅ 完成
