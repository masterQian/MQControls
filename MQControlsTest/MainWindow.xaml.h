#pragma once

#include "MainWindow.g.h"

namespace winrt::MQControlsTest::implementation {
    struct MainWindow : MainWindowT<MainWindow> {
        MainWindow();

        void OnClick(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
        void OnClick1(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
        void OnClick2(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
        void OnClick3(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
        void OnClick4(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
        void OnClick5(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
        void OnClick6(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
    };
}

namespace winrt::MQControlsTest::factory_implementation {
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow> { };
}
