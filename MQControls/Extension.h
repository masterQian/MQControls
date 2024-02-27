#pragma once
#include "FontIconExtension.g.h"
#include "ShortCutKeyExtension.g.h"

#include <winrt/Microsoft.UI.Text.h>
#include <winrt/Microsoft.UI.Xaml.Input.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::MQControls::implementation {
    struct FontIconExtension : FontIconExtensionT<FontIconExtension> {
        double mFontSize;
        hstring mGlyph;
        Windows::UI::Text::FontWeight mFontWeight;
        Media::Brush mForeground;

        FontIconExtension() : mFontSize{ }, mFontWeight{ Microsoft::UI::Text::FontWeights::Normal() },
            mForeground{ Media::SolidColorBrush{ Windows::UI::Colors::Black() } } { }

        double FontSize() const { return mFontSize; }
        void FontSize(double value) { mFontSize = value; }

        hstring Glyph() const { return mGlyph; }
        void Glyph(hstring const& value) { mGlyph = value; }

        Windows::UI::Text::FontWeight FontWeight() const { return mFontWeight; }
        void FontWeight(Windows::UI::Text::FontWeight const& value) { mFontWeight = value; }

        Media::Brush Foreground() const { return mForeground; }
        void Foreground(Media::Brush const& value) { mForeground = value; }

        IInspectable ProvideValue() const {
            Controls::FontIcon icon;
            icon.Glyph(mGlyph);
            if (mFontSize > 0.0) {
                icon.FontSize(mFontSize);
            }
            icon.FontWeight(mFontWeight);
            icon.Foreground(mForeground);
            return icon;
        }

        IInspectable ProvideValue(IXamlServiceProvider provider) const { return ProvideValue(); }
    };

    struct ShortCutKeyExtension : ShortCutKeyExtensionT<ShortCutKeyExtension> {
        Windows::System::VirtualKey mKey;
        Windows::System::VirtualKeyModifiers mModifiers;

        ShortCutKeyExtension() : mKey{ Windows::System::VirtualKey::None },
            mModifiers{ Windows::System::VirtualKeyModifiers::None } { }

        Windows::System::VirtualKey Key() const { return mKey; }
        void Key(Windows::System::VirtualKey const& value) { mKey = value; }

        Windows::System::VirtualKeyModifiers Modifiers() const { return mModifiers; }
        void Modifiers(Windows::System::VirtualKeyModifiers const& value) { mModifiers = value; }

        IInspectable ProvideValue() const {
            Input::KeyboardAccelerator key;
            key.Key(mKey);
            key.Modifiers(mModifiers);
            return key;
        }

        IInspectable ProvideValue(IXamlServiceProvider provider) const { return ProvideValue(); }
    };
}

namespace winrt::MQControls::factory_implementation {
    struct FontIconExtension : FontIconExtensionT<FontIconExtension, implementation::FontIconExtension> { };
    struct ShortCutKeyExtension : ShortCutKeyExtensionT<ShortCutKeyExtension, implementation::ShortCutKeyExtension> { };
}
