#include "pch.h"
#include "Property.h"
#include "Property.g.cpp"

#include <winrt/Microsoft.UI.Xaml.Hosting.h>

namespace winrt::MQControls::implementation {
    void Property::ShortCutKeyPropertyChanged(DependencyObject const& d, DependencyPropertyChangedEventArgs const& args) {
        if (auto elem{ d.try_as<UIElement>() }) {
            auto items{ elem.KeyboardAccelerators() };
            items.Clear();
            if (auto key{ args.NewValue().as<Input::KeyboardAccelerator>() }) {
                items.Append(key);
            }
        }
    }

    void Property::ClipToBoundsPropertyChanged(DependencyObject const& d, DependencyPropertyChangedEventArgs const& args) {
        if (auto elem{ d.try_as<UIElement>() }) {
            auto visual{ Hosting::ElementCompositionPreview::GetElementVisual(elem) };
            visual.Clip(args.NewValue().as<bool>() ? visual.Compositor().CreateInsetClip() : nullptr);
        }
    }
}