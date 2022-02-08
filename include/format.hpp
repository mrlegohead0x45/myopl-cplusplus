#ifndef FORMAT_HPP_
#define FORMAT_HPP_

/*
    see https://fmt.dev/latest/api.html#udt
    i'll be honest, i don't really understand half of this
    but it works!
    i cannot however be bothered to extract the signatures
    and implement this in a format.cpp file
    and anyway it's only two lines actually doing anything
*/

#include "error.hpp"
#include "token.hpp"
#include <fmt/format.h>

template <> struct fmt::formatter<Token>: formatter<fmt::string_view> {
    template <typename FormatContext>
    auto format(const Token t, FormatContext &ctx) -> decltype(ctx.out()) {
        return fmt::formatter<fmt::string_view>::format(t.as_string(), ctx);
    }
};

template <> struct fmt::formatter<Error>: formatter<fmt::string_view> {
    template <typename FormatContext>
    auto format(const Error e, FormatContext &ctx) -> decltype(ctx.out()) {
        return fmt::formatter<fmt::string_view>::format(e.as_string(), ctx);
    }
};

#endif // FORMAT_HPP_
