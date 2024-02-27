#include "pch.h"
#include "MarqueeText.h"
#include "MarqueeText.g.cpp"

namespace winrt::MQControls::implementation {
    void MarqueeText::UpdateAnimation(bool keepProgress) {
        auto isLooping{ IsLooping() };
        auto old_progress{ mTransform.X() };
        auto container_width{ mContainer.ActualWidth() };
        auto text_width{ mText1.ActualWidth() };
        auto interval_space{ Interval() };
        if (isLooping) {
            if (auto padding{ container_width - text_width }; padding > 0.0 && interval_space < padding) {
                interval_space = padding;
            }
            mIntervalSpace.Width(interval_space);
            mText2.Visibility(Visibility::Visible);
            mIntervalSpace.Visibility(Visibility::Visible);
        }
        else {
            mText2.Visibility(Visibility::Collapsed);
            mIntervalSpace.Visibility(Visibility::Collapsed);
        }
        auto start{ isLooping ? interval_space : container_width };
        auto end{ -text_width };
        auto distance{ start - end };
        auto speed{ Speed() };
        if (speed == 0.0) speed = 0.01;
        auto duration{ static_cast<int64_t>(distance * 1000.0 / speed) };
        mAnimation.From(start);
        mAnimation.To(end);
        mAnimation.Duration({ std::chrono::milliseconds{ duration }, DurationType::TimeSpan });
        std::chrono::milliseconds new_progress{ };
        if (keepProgress) {
            duration = static_cast<int64_t>(duration * std::fabs(start - old_progress) / distance);
            new_progress = std::chrono::milliseconds{ duration };
        }
        mStoryboard.Seek(new_progress);
    }

    void MarqueeText::SpeedPropertyChanged(DependencyObject const& d, DependencyPropertyChangedEventArgs const&) {
        if (auto control{ get_self<MarqueeText>(d.as<MQControl>()) }; control->isInitialize) {
            control->UpdateAnimation(true);
        }
    }

    void MarqueeText::IntervalPropertyChanged(DependencyObject const& d, DependencyPropertyChangedEventArgs const&) {
        if (auto control{ get_self<MarqueeText>(d.as<MQControl>()) }; control->isInitialize) {
            if (control->IsLooping()) {
                control->UpdateAnimation(true);
            }
        }
    }

    void MarqueeText::IsLoopingPropertyChanged(DependencyObject const& d, DependencyPropertyChangedEventArgs const&) {
        if (auto control{ get_self<MarqueeText>(d.as<MQControl>()) }; control->isInitialize) {
            control->UpdateAnimation(false);
        }
    }

    void MarqueeText::IsOnPropertyChanged(DependencyObject const& d, DependencyPropertyChangedEventArgs const& args) {
        if (auto control{ get_self<MarqueeText>(d.as<MQControl>()) }; control->isInitialize) {
            if (unbox_value<bool>(args.NewValue())) {
                control->mStoryboard.Resume();
            }
            else {
                control->mStoryboard.Pause();
            }
        }
    }

    void MarqueeText::OnApplyTemplate() {
        base_type::OnApplyTemplate();

        mContainer = GetTemplateChild(L"mContainer").as<decltype(mContainer)>();
        mText1 = GetTemplateChild(L"mText1").as<decltype(mText1)>();
        mIntervalSpace = GetTemplateChild(L"mIntervalSpace").as<decltype(mIntervalSpace)>();
        mText2 = GetTemplateChild(L"mText2").as<decltype(mText2)>();
        mTransform = GetTemplateChild(L"mTransform").as<decltype(mTransform)>();
        mStoryboard = GetTemplateChild(L"mStoryboard").as<decltype(mStoryboard)>();
        mAnimation = GetTemplateChild(L"mAnimation").as<decltype(mAnimation)>();

        if (mText1SizeChangedToken) mText1.SizeChanged(mText1SizeChangedToken);
        mText1SizeChangedToken = mText1.SizeChanged([this] (auto...) {
            UpdateAnimation(std::exchange(isUpdateFirstly, true));
        });

        isInitialize = true;

        mStoryboard.Begin();
        if (!IsOn()) mStoryboard.Pause();
    }
}