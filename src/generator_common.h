#ifndef GENERATOR_COMMON_H
#define GENERATOR_COMMON_H

#include <string>
#include <string_view>
#include <iterator>

struct ArrayView {
    const std::string_view* data = nullptr;
    size_t length = 0;
    constexpr size_t size() const { return length; }
    constexpr bool empty() const { return length == 0; }
    constexpr std::string_view operator[](size_t i) const { return data[i]; }
};

template<size_t N>
constexpr ArrayView make_view(const std::string_view (&arr)[N]) {
    return {arr, N};
}

constexpr ArrayView make_view(const ArrayView& v) {
    return v;
}

template<size_t N>
constexpr bool operator==(const ArrayView& lhs, const std::string_view (&rhs)[N]) {
    return lhs.data == rhs;
}

template<size_t N>
constexpr bool operator==(const std::string_view (&lhs)[N], const ArrayView& rhs) {
    return lhs == rhs.data;
}

constexpr bool operator==(const ArrayView& lhs, const ArrayView& rhs) {
    return lhs.data == rhs.data && lhs.length == rhs.length;
}

template<size_t N>
constexpr bool operator!=(const ArrayView& lhs, const std::string_view (&rhs)[N]) {
    return !(lhs == rhs);
}

template<size_t N>
constexpr bool operator!=(const std::string_view (&lhs)[N], const ArrayView& rhs) {
    return !(lhs == rhs);
}

constexpr bool operator!=(const ArrayView& lhs, const ArrayView& rhs) {
    return !(lhs == rhs);
}

namespace std {
    inline size_t size(const ArrayView& v) { return v.size(); }
}

inline std::string capitalize(std::string s) {
    if (!s.empty()) s[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])));
    return s;
}

inline std::string capitalize(std::string_view sv) {
    std::string s(sv);
    if (!s.empty()) s[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])));
    return s;
}

inline std::string to_lower(std::string_view sv) {
    std::string s(sv);
    for (char& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return s;
}

inline std::string to_lower(std::string s) {
    for (char& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return s;
}

inline std::string operator+(std::string_view a, std::string_view b) {
    std::string s;
    s.reserve(a.size() + b.size());
    s.append(a);
    s.append(b);
    return s;
}

inline std::string operator+(std::string_view a, const std::string& b) {
    std::string s;
    s.reserve(a.size() + b.size());
    s.append(a);
    s.append(b);
    return s;
}

inline std::string operator+(const std::string& a, std::string_view b) {
    std::string s;
    s.reserve(a.size() + b.size());
    s.append(a);
    s.append(b);
    return s;
}

inline std::string operator+(std::string&& a, std::string_view b) {
    a.append(b);
    return std::move(a);
}

inline std::string operator+(std::string_view a, const char* b) {
    std::string_view sv(b);
    std::string s;
    s.reserve(a.size() + sv.size());
    s.append(a);
    s.append(sv);
    return s;
}

inline std::string operator+(const char* a, std::string_view b) {
    std::string_view sv(a);
    std::string s;
    s.reserve(sv.size() + b.size());
    s.append(sv);
    s.append(b);
    return s;
}

inline std::string operator+(const std::string& a, size_t b) {
    return a + std::to_string(b);
}
inline std::string operator+(std::string&& a, size_t b) {
    a += std::to_string(b);
    return std::move(a);
}
inline std::string operator+(std::string_view a, size_t b) {
    return std::string(a) + std::to_string(b);
}
inline std::string operator+(size_t a, const std::string& b) {
    return std::to_string(a) + b;
}
inline std::string operator+(size_t a, std::string_view b) {
    return std::to_string(a) + std::string(b);
}

inline std::string operator+(const std::string& a, double b) {
    std::string s = std::to_string(b);
    while (s.size() > 1 && s.back() == '0') s.pop_back();
    if (!s.empty() && s.back() == '.') s.pop_back();
    return a + s;
}
inline std::string operator+(double a, const std::string& b) {
    std::string s = std::to_string(a);
    while (s.size() > 1 && s.back() == '0') s.pop_back();
    if (!s.empty() && s.back() == '.') s.pop_back();
    return s + b;
}
inline std::string operator+(std::string_view a, double b) {
    return std::string(a) + std::to_string(b);
}
inline std::string operator+(double a, std::string_view b) {
    return std::to_string(a) + std::string(b);
}

inline std::string operator+(const std::string& a, int b) {
    return a + std::to_string(b);
}
inline std::string operator+(int a, const std::string& b) {
    return std::to_string(a) + b;
}
inline std::string operator+(std::string_view a, int b) {
    return std::string(a) + std::to_string(b);
}
inline std::string operator+(int a, std::string_view b) {
    return std::to_string(a) + std::string(b);
}


inline constexpr bool operator==(std::string_view, int) { return false; }
inline constexpr bool operator==(int, std::string_view) { return false; }
inline constexpr bool operator!=(std::string_view a, int b) { return !(a == b); }
inline constexpr bool operator!=(int a, std::string_view b) { return !(a == b); }

inline bool operator==(const std::string&, int) { return false; }
inline bool operator==(int, const std::string&) { return false; }
inline bool operator!=(const std::string& a, int b) { return !(a == b); }
inline bool operator!=(int a, const std::string& b) { return !(a == b); }

#endif // GENERATOR_COMMON_H
