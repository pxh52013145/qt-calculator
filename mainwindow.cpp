#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QtMath>
#include <QDebug>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , inputExpression("0")
{
    ui->setupUi(this);
    
    // 连接信号和槽
    connectSignals();
    
    // 应用样式表
    applyStyles();
    
    // 窗口标题在 UI 文件中设置，这里不需要重复设置
    // setWindowTitle("计算器");
    
    // 初始显示
    updateDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 连接所有按钮的信号和槽
void MainWindow::connectSignals()
{
    // 数字按钮 0-9
    connect(ui->btn0, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->btn1, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->btn2, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->btn3, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->btn4, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->btn5, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->btn6, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->btn7, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->btn8, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->btn9, &QPushButton::clicked, this, &MainWindow::digitClicked);
    
    // 运算符按钮
    connect(ui->btnPlus, &QPushButton::clicked, this, &MainWindow::operatorClicked);
    connect(ui->btnMinus, &QPushButton::clicked, this, &MainWindow::operatorClicked);
    connect(ui->btnMultiply, &QPushButton::clicked, this, &MainWindow::operatorClicked);
    connect(ui->btnDivide, &QPushButton::clicked, this, &MainWindow::operatorClicked);
    connect(ui->btnPercent, &QPushButton::clicked, this, &MainWindow::operatorClicked);
    
    // 等号按钮
    connect(ui->btnEquals, &QPushButton::clicked, this, &MainWindow::equalsClicked);
    
    // 清除按钮
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::clearClicked);
    connect(ui->btnCE, &QPushButton::clicked, this, &MainWindow::clearEntryClicked);
    
    // 退格按钮
    connect(ui->btnBackspace, &QPushButton::clicked, this, &MainWindow::backspaceClicked);
    
    // 小数点按钮
    connect(ui->btnDecimal, &QPushButton::clicked, this, &MainWindow::decimalClicked);
    
    // 单操作符按钮
    connect(ui->btnReciprocal, &QPushButton::clicked, this, &MainWindow::unaryOperatorClicked);
    connect(ui->btnSquare, &QPushButton::clicked, this, &MainWindow::unaryOperatorClicked);
    connect(ui->btnSqrt, &QPushButton::clicked, this, &MainWindow::unaryOperatorClicked);
    
    // 正负号按钮
    connect(ui->btnNegate, &QPushButton::clicked, this, &MainWindow::negateClicked);
}

// 计算表达式的值（支持运算符优先级）
double MainWindow::evaluateExpression(const QString &expr)
{
    QString expression = expr;
    
    // 第一步：找最后一个加法或减法（优先级最低）
    int lastAddSubIndex = -1;
    QString addSubOp;
    for (int i = expression.length() - 1; i > 0; i--) {
        QString ch = expression.mid(i, 1);
        if (ch == "+" || ch == "−") {
            lastAddSubIndex = i;
            addSubOp = ch;
            break;
        }
    }
    
    // 如果找到加减运算符，先递归计算左右两边
    if (lastAddSubIndex > 0) {
        QString leftStr = expression.left(lastAddSubIndex);
        QString rightStr = expression.mid(lastAddSubIndex + 1);
        
        if (!rightStr.isEmpty()) {
            double left = evaluateExpression(leftStr);   // 递归计算左边
            double right = evaluateExpression(rightStr); // 递归计算右边
            
            if (addSubOp == "+") {
                return left + right;
            } else if (addSubOp == "−") {
                return left - right;
            }
        }
    }
    
    // 第二步：没有加减，找乘除百分比
    int lastMulDivIndex = -1;
    QString mulDivOp;
    for (int i = expression.length() - 1; i > 0; i--) {
        QString ch = expression.mid(i, 1);
        if (ch == "×" || ch == "÷" || ch == "%") {
            lastMulDivIndex = i;
            mulDivOp = ch;
            break;
        }
    }
    
    if (lastMulDivIndex > 0) {
        QString leftStr = expression.left(lastMulDivIndex);
        QString rightStr = expression.mid(lastMulDivIndex + 1);
        
        if (!rightStr.isEmpty()) {
            double left = evaluateExpression(leftStr);   // 递归计算左边
            double right = rightStr.toDouble();          // 右边直接转数字
            
            if (mulDivOp == "×") {
                return left * right;
            } else if (mulDivOp == "÷") {
                if (right != 0.0) {
                    return left / right;
                } else {
                    return 0.0;
                }
            } else if (mulDivOp == "%") {
                if (right != 0.0) {
                    return fmod(left, right);  // 取余操作
                } else {
                    return 0.0;
                }
            }
        }
    }
    
    // 第三步：没有运算符，直接返回数值
    return expression.toDouble();
}

// 更新显示和预演算
void MainWindow::updateDisplay()
{
    // 上方显示输入的表达式
    ui->display->setText(inputExpression);
    
    // 检查是否有运算符且右操作数不为空
    bool hasOperator = false;
    int lastOpIndex = -1;
    
    for (int i = inputExpression.length() - 1; i > 0; i--) {
        QString ch = inputExpression.mid(i, 1);
        if (ch == "+" || ch == "−" || ch == "×" || ch == "÷" || ch == "%") {
            lastOpIndex = i;
            hasOperator = true;
            break;
        }
    }
    
    // 如果有运算符且右边有数字，显示预演算
    if (hasOperator && lastOpIndex < inputExpression.length() - 1) {
        QString rightPart = inputExpression.mid(lastOpIndex + 1);
        if (!rightPart.isEmpty() && rightPart != "0") {
            double result = evaluateExpression(inputExpression);
            ui->previewDisplay->setText(QString::number(result, 'g', 15));
        } else {
            ui->previewDisplay->setText("");
        }
    } else {
        ui->previewDisplay->setText("");
    }
}

// 数字按钮点击处理
void MainWindow::digitClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    
    QString digit = button->text();
    
    if (inputExpression == "0") {
        inputExpression = digit;
    } else {
        inputExpression += digit;
    }
    
    updateDisplay();
}

// 小数点按钮点击处理
void MainWindow::decimalClicked()
{
    // 检查当前数字是否已包含小数点
    int lastOpIndex = -1;
    for (int i = inputExpression.length() - 1; i >= 0; i--) {
        QString ch = inputExpression.mid(i, 1);
        if (ch == "+" || ch == "−" || ch == "×" || ch == "÷" || ch == "%") {
            lastOpIndex = i;
            break;
        }
    }
    
    QString currentNumber;
    if (lastOpIndex >= 0) {
        currentNumber = inputExpression.mid(lastOpIndex + 1);
    } else {
        currentNumber = inputExpression;
    }
    
    if (!currentNumber.contains('.')) {
        if (currentNumber.isEmpty()) {
            inputExpression += "0.";
        } else {
            inputExpression += ".";
        }
        updateDisplay();
    }
}

// 运算符按钮点击处理
void MainWindow::operatorClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    
    QString op;
    if (button == ui->btnPlus) op = "+";
    else if (button == ui->btnMinus) op = "−";
    else if (button == ui->btnMultiply) op = "×";
    else if (button == ui->btnDivide) op = "÷";
    else if (button == ui->btnPercent) op = "%";
    
    // 检查最后一个字符是否已经是运算符
    if (!inputExpression.isEmpty()) {
        QString lastChar = inputExpression.right(1);
        if (lastChar == "+" || lastChar == "−" || lastChar == "×" || 
            lastChar == "÷" || lastChar == "%") {
            // 替换最后一个运算符
            inputExpression.chop(1);
        }
    }
    
    inputExpression += op;
    updateDisplay();
}

// 等号按钮点击处理
void MainWindow::equalsClicked()
{
    // 计算结果
    double result = evaluateExpression(inputExpression);
    
    // 显示结果在上方，清空预演算
    inputExpression = QString::number(result, 'g', 15);
    ui->display->setText(inputExpression);
    ui->previewDisplay->setText("");
}

// 清除按钮点击处理
void MainWindow::clearClicked()
{
    inputExpression = "0";
    updateDisplay();
}

// CE按钮点击处理
void MainWindow::clearEntryClicked()
{
    inputExpression = "0";
    updateDisplay();
}

// 退格按钮点击处理
void MainWindow::backspaceClicked()
{
    if (inputExpression.length() > 1) {
        inputExpression.chop(1);  // 删除最后一个字符（数字或运算符）
    } else {
        inputExpression = "0";
    }
    updateDisplay();
}

// 单操作符按钮点击处理
void MainWindow::unaryOperatorClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    
    double operand = inputExpression.toDouble();
    double result = 0.0;
    
    if (button == ui->btnReciprocal) {
        // 倒数 1/x
        if (operand != 0.0) {
            result = 1.0 / operand;
        } else {
            ui->display->setText("错误");
            ui->previewDisplay->setText("");
            return;
        }
    } else if (button == ui->btnSquare) {
        // 平方 x²
        result = operand * operand;
    } else if (button == ui->btnSqrt) {
        // 平方根 √x
        if (operand >= 0.0) {
            result = qSqrt(operand);
        } else {
            ui->display->setText("错误");
            ui->previewDisplay->setText("");
            return;
        }
    }
    
    inputExpression = QString::number(result, 'g', 15);
    updateDisplay();
}

// 正负号按钮点击处理
void MainWindow::negateClicked()
{
    double value = inputExpression.toDouble();
    
    if (value != 0.0) {
        value = -value;
        inputExpression = QString::number(value, 'g', 15);
        updateDisplay();
    }
}

// 应用样式表
void MainWindow::applyStyles()
{
    // 主窗口样式
    this->setStyleSheet(
        "QMainWindow { background-color: #F3F3F3; }"
    );
    
    // 显示容器样式
    ui->displayContainer->setStyleSheet(
        "QWidget#displayContainer {"
        "   background-color: white;"
        "   border: 1px solid #E0E0E0;"
        "   border-radius: 5px;"
        "}"
    );
    
    // 主显示样式（大字，黑色）
    ui->display->setStyleSheet(
        "QLabel {"
        "   color: #333333;"
        "   background-color: transparent;"
        "}"
    );
    
    // 预演算显示样式（小字，灰色）
    ui->previewDisplay->setStyleSheet(
        "QLabel {"
        "   color: #999999;"
        "   background-color: transparent;"
        "}"
    );
    
    // 数字按钮样式（白色）- 悬停效果明显
    QString digitStyle = 
        "QPushButton {"
        "   background-color: white;"
        "   border: 1px solid #E0E0E0;"
        "   border-radius: 5px;"
        "   color: #333333;"
        "   font-size: 14pt;"
        "}"
        "QPushButton:hover {"
        "   background-color: #E5E5E5;"
        "   border: 1px solid #C0C0C0;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #D0D0D0;"
        "   border: 1px solid #B0B0B0;"
        "}";
    
    ui->btn0->setStyleSheet(digitStyle);
    ui->btn1->setStyleSheet(digitStyle);
    ui->btn2->setStyleSheet(digitStyle);
    ui->btn3->setStyleSheet(digitStyle);
    ui->btn4->setStyleSheet(digitStyle);
    ui->btn5->setStyleSheet(digitStyle);
    ui->btn6->setStyleSheet(digitStyle);
    ui->btn7->setStyleSheet(digitStyle);
    ui->btn8->setStyleSheet(digitStyle);
    ui->btn9->setStyleSheet(digitStyle);
    ui->btnDecimal->setStyleSheet(digitStyle);
    
    // 功能按钮样式（浅灰色）- 悬停效果明显
    QString functionStyle = 
        "QPushButton {"
        "   background-color: #F8F8F8;"
        "   border: 1px solid #E0E0E0;"
        "   border-radius: 5px;"
        "   color: #333333;"
        "   font-size: 12pt;"
        "}"
        "QPushButton:hover {"
        "   background-color: #E0E0E0;"
        "   border: 1px solid #C0C0C0;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #D0D0D0;"
        "   border: 1px solid #B0B0B0;"
        "}";
    
    ui->btnPercent->setStyleSheet(functionStyle);
    ui->btnCE->setStyleSheet(functionStyle);
    ui->btnClear->setStyleSheet(functionStyle);
    ui->btnBackspace->setStyleSheet(functionStyle);
    ui->btnReciprocal->setStyleSheet(functionStyle);
    ui->btnSquare->setStyleSheet(functionStyle);
    ui->btnSqrt->setStyleSheet(functionStyle);
    ui->btnNegate->setStyleSheet(functionStyle);
    
    // 运算符按钮样式（浅灰色）- 悬停效果明显
    QString operatorStyle = 
        "QPushButton {"
        "   background-color: #F8F8F8;"
        "   border: 1px solid #E0E0E0;"
        "   border-radius: 5px;"
        "   color: #333333;"
        "   font-size: 16pt;"
        "}"
        "QPushButton:hover {"
        "   background-color: #E0E0E0;"
        "   border: 1px solid #C0C0C0;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #D0D0D0;"
        "   border: 1px solid #B0B0B0;"
        "}";
    
    ui->btnPlus->setStyleSheet(operatorStyle);
    ui->btnMinus->setStyleSheet(operatorStyle);
    ui->btnMultiply->setStyleSheet(operatorStyle);
    ui->btnDivide->setStyleSheet(operatorStyle);
    
    // 等号按钮样式（蓝色高亮）- 悬停效果明显
    ui->btnEquals->setStyleSheet(
        "QPushButton {"
        "   background-color: #A0C8E8;"
        "   border: 1px solid #90B8D8;"
        "   border-radius: 5px;"
        "   color: #333333;"
        "   font-size: 16pt;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: #85B0D0;"
        "   border: 1px solid #7098B8;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #7098B8;"
        "   border: 1px solid #6088A8;"
        "}"
    );
}

// 键盘事件处理
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        // 数字键
        case Qt::Key_0:
            ui->btn0->click();
            break;
        case Qt::Key_1:
            ui->btn1->click();
            break;
        case Qt::Key_2:
            ui->btn2->click();
            break;
        case Qt::Key_3:
            ui->btn3->click();
            break;
        case Qt::Key_4:
            ui->btn4->click();
            break;
        case Qt::Key_5:
            ui->btn5->click();
            break;
        case Qt::Key_6:
            ui->btn6->click();
            break;
        case Qt::Key_7:
            ui->btn7->click();
            break;
        case Qt::Key_8:
            ui->btn8->click();
            break;
        case Qt::Key_9:
            ui->btn9->click();
            break;
        
        // 运算符
        case Qt::Key_Plus:
            ui->btnPlus->click();
            break;
        case Qt::Key_Minus:
            ui->btnMinus->click();
            break;
        case Qt::Key_Asterisk:
            ui->btnMultiply->click();
            break;
        case Qt::Key_Slash:
            ui->btnDivide->click();
            break;
        case Qt::Key_Percent:
            ui->btnPercent->click();
            break;
        
        // 等号
        case Qt::Key_Return:
        case Qt::Key_Enter:
        case Qt::Key_Equal:
            ui->btnEquals->click();
            break;
        
        // 小数点
        case Qt::Key_Period:
        case Qt::Key_Comma:
            ui->btnDecimal->click();
            break;
        
        // 退格
        case Qt::Key_Backspace:
            ui->btnBackspace->click();
            break;
        
        // 清除
        case Qt::Key_Escape:
            ui->btnClear->click();
            break;
        case Qt::Key_Delete:
            ui->btnCE->click();
            break;
        
        default:
            QMainWindow::keyPressEvent(event);
    }
}
