#include "tomo_ui/main_gui.hpp"

#include <QPushButton>
#include <QBoxLayout>

#include <QtCharts/QChartView>

MainGUI::MainGUI(const std::shared_ptr<Ros2Node>& ros2_node, QWidget* parent)
    : QMainWindow(parent)
    , ros2_node(ros2_node)
{
    main_widget = new QWidget(this);
    main_widget->setStyleSheet("background-color: #1F3347;");

    QHBoxLayout* main_layout = new QHBoxLayout;
    main_layout->setSpacing(20);
    main_layout->setMargin(20);

    lineedit = new LineEdit;
    publish_button = new QPushButton("Publish");
    connect(publish_button, &QPushButton::clicked, this, &MainGUI::publish_button_clicked);

    chart = new Chart;
    chart->setTitle("Dynamic spline chart");
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    main_layout->addWidget(chartView);

    main_layout->addWidget(lineedit);
    main_layout->addWidget(publish_button);
   

    main_widget->setLayout(main_layout);

    setCentralWidget(main_widget);
}

MainGUI::~MainGUI()
{
}

void MainGUI::publish_button_clicked()
{
    if (!lineedit->text().isEmpty()){
      // Make sure to convert from QString to std::string
      ros2_node->publish_message(lineedit->text().toUtf8().constData());
    }
}