#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include "../Output/MQControls.Main.h"

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::MQControlsTest::implementation {
    MainWindow::MainWindow() {
        InitializeComponent();
    }

    void MainWindow::OnClick(IInspectable const& sender, RoutedEventArgs const&) {
        IB().Orientation(IB().Orientation() == Controls::Orientation::Horizontal ?
            Controls::Orientation::Vertical : Controls::Orientation::Horizontal);
    }

    void MainWindow::OnClick1(IInspectable const& sender, RoutedEventArgs const&) {
        IB().IsEnabled(!IB().IsEnabled());
    }

    void MainWindow::OnClick2(IInspectable const& sender, RoutedEventArgs const&) {
        SBox().IsEnabled(!SBox().IsEnabled());
    }

    void MainWindow::OnClick3(IInspectable const& sender, RoutedEventArgs const&) {
        GBox().IsEnabled(!GBox().IsEnabled());
    }

    void MainWindow::OnClick4(IInspectable const& sender, RoutedEventArgs const&) {
        RTB().IsEnabled(!RTB().IsEnabled());
    }

    void MainWindow::OnClick5(IInspectable const& sender, RoutedEventArgs const&) {
        SSC().IsEnabled(!SSC().IsEnabled());
    }

    void MainWindow::OnClick6(IInspectable const& sender, RoutedEventArgs const&) {
        SSE().IsEnabled(!SSE().IsEnabled());
    }
}
