#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include "BusGraph.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private slots:
    void onSearchRouteClicked(); // '경로 및 시간 조회' 버튼 클릭 핸들러

private:
    BusGraph graph; // 백엔드 그래프 로직 인스턴스
    
    QLabel* mapImageLabel;    // 노선도 이미지를 출력할 라벨 위젯
    QComboBox* startCombo;    // 출발 정류장 선택 드롭다운
    QComboBox* destCombo;     // 도착 정류장 선택 드롭다운
    QPushButton* searchBtn;   // 조회 수행 버튼
    QTextEdit* resultDisplay; // 결과를 깔끔한 텍스트 템플릿으로 띄울 위젯

    void setupUI();
};

#endif // MAINWINDOW_H