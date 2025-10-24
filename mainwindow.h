#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // 键盘事件处理
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    // 数字按钮槽函数
    void digitClicked();
    // 运算符按钮槽函数
    void operatorClicked();
    // 等号按钮槽函数
    void equalsClicked();
    // 清除按钮槽函数
    void clearClicked();
    // CE按钮槽函数
    void clearEntryClicked();
    // 退格按钮槽函数
    void backspaceClicked();
    // 小数点按钮槽函数
    void decimalClicked();
    // 单操作符槽函数
    void unaryOperatorClicked();
    // 正负号槽函数
    void negateClicked();
    
private:
    Ui::MainWindow *ui;
    
    // 计算器状态变量
    QString inputExpression;     // 输入的完整表达式字符串（如 "845+996"）
    
    // 辅助函数
    void connectSignals();       // 连接信号和槽
    void updateDisplay();        // 更新显示和预演算
    double evaluateExpression(const QString &expr);  // 计算表达式的值
    void applyStyles();          // 应用样式表
};

#endif // MAINWINDOW_H
