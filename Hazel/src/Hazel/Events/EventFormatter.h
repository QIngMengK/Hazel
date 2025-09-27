#pragma once

#include "spdlog/fmt/bundled/format.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"

//
// Application Events
//
template <>
struct fmt::formatter<Hazel::WindowResizeEvent> : fmt::formatter<std::string> {
    template <typename FormatContext>
    auto format(const Hazel::WindowResizeEvent& e, FormatContext& ctx) const {
        return fmt::formatter<std::string>::format(
            fmt::format("WindowResizeEvent: {}x{}", e.GetWidth(), e.GetHeight()), ctx);
    }
};

template <>
struct fmt::formatter<Hazel::WindowCloseEvent> : fmt::formatter<std::string> {
    template <typename FormatContext>
    auto format(const Hazel::WindowCloseEvent&, FormatContext& ctx) const {
        return fmt::formatter<std::string>::format("WindowCloseEvent", ctx);
    }
};

//
// Keyboard Events
//
template <>
struct fmt::formatter<Hazel::KeyPressedEvent> : fmt::formatter<std::string> {
    template <typename FormatContext>
    auto format(const Hazel::KeyPressedEvent& e, FormatContext& ctx) const {
        return fmt::formatter<std::string>::format(
            fmt::format("KeyPressedEvent: key={} (repeat={})", e.GetKeyCode(), e.GetRepeatCount()), ctx);
    }
};

template <>
struct fmt::formatter<Hazel::KeyReleasedEvent> : fmt::formatter<std::string> {
    template <typename FormatContext>
    auto format(const Hazel::KeyReleasedEvent& e, FormatContext& ctx) const {
        return fmt::formatter<std::string>::format(
            fmt::format("KeyReleasedEvent: key={}", e.GetKeyCode()), ctx);
    }
};

//
// Mouse Events
//
template <>
struct fmt::formatter<Hazel::MouseMovedEvent> : fmt::formatter<std::string> {
    template <typename FormatContext>
    auto format(const Hazel::MouseMovedEvent& e, FormatContext& ctx) const {
        return fmt::formatter<std::string>::format(
            fmt::format("MouseMovedEvent: {} , {}", e.GetX(), e.GetY()), ctx);
    }
};

template <>
struct fmt::formatter<Hazel::MouseScrolledEvent> : fmt::formatter<std::string> {
    template <typename FormatContext>
    auto format(const Hazel::MouseScrolledEvent& e, FormatContext& ctx) const {
        return fmt::formatter<std::string>::format(
            fmt::format("MouseScrolledEvent: {} , {}", e.GetXOffset(), e.GetYOffset()), ctx);
    }
};

template <>
struct fmt::formatter<Hazel::MouseButtonPressedEvent> : fmt::formatter<std::string> {
    template <typename FormatContext>
    auto format(const Hazel::MouseButtonPressedEvent& e, FormatContext& ctx) const {
        return fmt::formatter<std::string>::format(
            fmt::format("MouseButtonPressedEvent: button={}", e.GetMouseButton()), ctx);
    }
};

template <>
struct fmt::formatter<Hazel::MouseButtonReleasedEvent> : fmt::formatter<std::string> {
    template <typename FormatContext>
    auto format(const Hazel::MouseButtonReleasedEvent& e, FormatContext& ctx) const {
        return fmt::formatter<std::string>::format(
            fmt::format("MouseButtonReleasedEvent: button={}", e.GetMouseButton()), ctx);
    }
};
