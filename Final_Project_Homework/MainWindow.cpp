#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("전북대 캠퍼스 순환버스 최단경로 안내 시스템");
    
    // 보고서 한 페이지 캡처에 가장 이상적인 창 크기 설정
    resize(740, 820);
    
    setupUI();
}

void MainWindow::setupUI() {
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    // 💡 컴포넌트 간 여백과 마진을 최소화하여 컴팩트하게 배치
    mainLayout->setSpacing(8);
    mainLayout->setContentsMargins(15, 10, 15, 10);

    // 1. 타이틀 라벨 상단 배치
    QLabel* titleLabel = new QLabel("<h3 style='color:#1a365d; font-weight:bold; margin:0;'>"
                                     "🚌 전북대학교 캠퍼스 버스 노선도 검색기</h3>");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // 2. 노선도 이미지 로드 및 배치 영역 (크기 축소 조정)
    QPixmap mapPixmap("campus_map.png"); 
    mapImageLabel = new QLabel(this);
    
    if (mapPixmap.isNull()) {
        mapImageLabel->setText("<h4 style='color:red;'>⚠️ campus_map.png 로드 실패<br>"
                               "파일이 소스코드 폴더 또는 실행파일(.exe) 폴더에 있는지 확인하세요.</h4>");
    } else {
        // 💡 기존 650x400에서 600x320 비율로 압축하여 세로 공간을 80픽셀 이상 확보
        mapImageLabel->setPixmap(mapPixmap.scaled(600, 320, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    mapImageLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(mapImageLabel);

    // 3. 입력 패널 그룹화 (출발지 및 도착지)
    QHBoxLayout* inputLayout = new QHBoxLayout();
    inputLayout->setContentsMargins(10, 2, 10, 2);
    
    QLabel* startLabel = new QLabel("<b>출발 정류장:</b>");
    startCombo = new QComboBox();
    
    QLabel* destLabel = new QLabel("<b>도착 정류장:</b>");
    destCombo = new QComboBox();

    std::vector<std::string> stations = graph.getStationList();
    for (const auto& name : stations) {
        QString qName = QString::fromStdString(name);
        startCombo->addItem(qName);
        destCombo->addItem(qName);
    }
    // 기본 세팅 (예술대학본관 -> 사회과학대학)
    destCombo->setCurrentIndex(7);

    inputLayout->addWidget(startLabel);
    inputLayout->addWidget(startCombo, 1);
    inputLayout->addSpacing(15);
    inputLayout->addWidget(destLabel);
    inputLayout->addWidget(destCombo, 1);
    
    mainLayout->addLayout(inputLayout);

    // 4. 경로 검색 실행 버튼
    searchBtn = new QPushButton("🚀 최적 경로 및 시간 조회");
    searchBtn->setStyleSheet("QPushButton { background-color: #2b6cb0; color: white; font-size: 12pt; "
                             "font-weight: bold; border-radius: 5px; padding: 8px; }"
                             "QPushButton:hover { background-color: #2c5282; }");
    mainLayout->addWidget(searchBtn);

    // 5. 결과 출력 레이블 및 디스플레이 영역
    QLabel* outputLabel = new QLabel("<b>📋 운행 경로 탐색 결과 및 환승 안내</b>");
    mainLayout->addWidget(outputLabel);

    resultDisplay = new QTextEdit();
    resultDisplay->setReadOnly(true);
    resultDisplay->setFontPointSize(10.5);
    // 💡 결과창 내부 여백(padding)을 조절하여 스크롤 없이 글씨가 다 보이도록 설정
    resultDisplay->setStyleSheet("QTextEdit { background-color: #f7fafc; border: 1px solid #cbd5e0; "
                                 "border-radius: 4px; padding: 8px; }");
    mainLayout->addWidget(resultDisplay);

    connect(searchBtn, &QPushButton::clicked, this, &MainWindow::onSearchRouteClicked);
}

void MainWindow::onSearchRouteClicked() {
    std::string startStation = startCombo->currentText().toStdString();
    std::string destStation = destCombo->currentText().toStdString();

    resultDisplay->clear();

    if (startStation == destStation) {
        resultDisplay->setHtml("<b style='color:red;'>출발 정류장과 도착 정류장이 동일합니다. 걸어가세요!</b>");
        return;
    }

    RouteResult res = graph.findShortestPath(startStation, destStation);

    if (res.totalTime == -1) {
        resultDisplay->setText("죄송합니다. 현재 노선망으로는 도달할 수 없는 경로입니다.");
        return;
    }

    // 💡 HTML 문장 간의 간격(margin, line-height)을 좁혀서 데이터 밀집도 향상
    QString htmlOutput = QString("<div style='line-height:130%; margin:0; padding:0;'>"
                                 "<span style='font-size:11pt; color:#2d3748;'>"
                                 "📍 <b>%1</b> 에서 <b>%2</b> 까지의 최적 소요 경로입니다.</span><br>")
                         .arg(QString::fromStdString(startStation), QString::fromStdString(destStation));

    htmlOutput += QString("<span style='font-size:13pt; color:#e53e3e;'>⏱️ <b>총 소요 시간: %1분</b></span><br>")
                  .arg(res.totalTime);

    htmlOutput += "<div style='margin-top:5px;'><b>[상세 이동 경로 안내]</b></div>"
                  "<hr style='border: 0.5px solid #cbd5e0; margin: 3px 0;'>";
    htmlOutput += "<ol style='margin:0; padding-left:20px;'>";

    for (size_t i = 0; i < res.lines.size(); ++i) {
        QString currentSt = QString::fromStdString(res.path[i]);
        QString nextSt = QString::fromStdString(res.path[i+1]);
        QString line = QString::fromStdString(res.lines[i]);
        
        QString colorStr = "#2b6cb0"; 
        if (line.contains("레드")) colorStr = "#e53e3e";
        else if (line.contains("그린")) colorStr = "#38a169";

        htmlOutput += QString("<li style='margin-bottom:2px;'><b>%1</b> 정류장에서 <span style='color:%2;'><b>[%3]</b></span> 탑승 "
                              "➡️ <b>%4</b> 이동</li>")
                      .arg(currentSt, colorStr, line, nextSt);
    }
    htmlOutput += "</ol></div>";

    resultDisplay->setHtml(htmlOutput);
}