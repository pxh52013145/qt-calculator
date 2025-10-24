# Development Changelog

## Iteration History

### Iteration 1: Project Initialization
- Created Qt project structure
- Set up main.cpp, mainwindow.h, mainwindow.cpp
- Configured lab1.pro

### Iteration 2: UI Design
- Designed interface with Qt Designer
- Created display container with 2 QLabels
- Created 4x6 button grid layout
- Added 24 buttons (digits, operators, functions)

### Iteration 3: Basic Input Functions
- Implemented digit input handling
- Added decimal point support with duplicate checking
- Implemented backspace functionality
- Connected signals and slots

### Iteration 4: Arithmetic Operations
- Implemented operator handling
- Created expression evaluation with operator precedence
- Added real-time preview calculation
- Implemented equals button functionality

### Iteration 5: Unary Operators
- Added square operation (x²)
- Added square root (√x)
- Added reciprocal (1/x)
- Added negate (+/-)
- Error handling for invalid operations

### Iteration 6: UI Styling
- Applied QSS stylesheets
- Set color scheme (white, gray, blue)
- Added hover effects
- Added pressed effects
- Rounded corners design

### Iteration 7: Keyboard Support
- Overrode keyPressEvent()
- Mapped number keys 0-9
- Mapped operator keys +, -, *, /
- Mapped function keys (Enter, Backspace, Esc)

### Iteration 8: Optimizations
- Fixed operator precedence (1×2+3×2 = 8 not 10)
- Reduced spacing between expression and preview
- Removed "=" from preview display
- Removed unnecessary files

