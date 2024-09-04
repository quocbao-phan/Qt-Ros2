#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

#include "tomo_ui/ros2node.hpp"
#include "tomo_ui/custom_widgets/lineedit.hpp"
#include "tomo_ui/custom_widgets/chart.hpp"

class MainGUI : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainGUI(const std::shared_ptr<Ros2Node>&  ros2_node, QWidget* parent = nullptr);
	~MainGUI() override;
private:
	void publish_button_clicked();

	const std::shared_ptr<Ros2Node> ros2_node;

	QWidget* main_widget;
	LineEdit* lineedit;
	QPushButton* publish_button;

	Chart *chart;
};