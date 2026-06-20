#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    // Qt 프레임워크 핵심 애플리케이션 핸들러 인스턴스 구동 [cite: 8]
    QApplication app(argc, argv);
    
    MainWindow window;
    window.show(); // GUI 주 윈도우 창 활성화 및 렌더링 [cite: 8]
    
    return app.exec(); // 사용자가 창을 닫을 때까지 대기하는 메시지 이벤트 루프 실행 [cite: 8]
}