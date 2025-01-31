// MIT License
//
// Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "output_file.hpp"
#include "config.hpp"
#include "lib/common/logging.hpp"

#include <fmt/core.h>
#include <fmt/format.h>

namespace rocprofiler
{
namespace tool
{
namespace fs = common::filesystem;

std::string
get_output_filename(std::string_view fname, std::string_view ext)
{
    auto cfg_output_path = tool::format(tool::get_config().output_path);

    // add a period to provided file extension if necessary
    constexpr auto period   = std::string_view{"."};
    constexpr auto noperiod = std::string_view{};
    const auto     _ext =
        fmt::format("{}{}", (!ext.empty() && ext.find('.') != 0) ? period : noperiod, ext);

    auto output_path   = fs::path{cfg_output_path};
    auto output_prefix = tool::format(tool::get_config().output_file);

    if(fs::exists(output_path) && !fs::is_directory(fs::status(output_path)))
        throw std::runtime_error{
            fmt::format("ROCPROFILER_OUTPUT_PATH ({}) already exists and is not a directory",
                        output_path.string())};
    if(!fs::exists(output_path)) fs::create_directories(output_path);

    return tool::format(output_path / fmt::format("{}_{}{}", output_prefix, fname, _ext));
}
std::pair<std::ostream*, output_stream_dtor_t>
get_output_stream(std::string_view fname, std::string_view ext)
{
    auto cfg_output_path = tool::format(tool::get_config().output_path);

    if(cfg_output_path == "stdout" || cfg_output_path == "STDOUT")
        return {&std::cout, [](auto*&) {}};
    else if(cfg_output_path == "stderr" || cfg_output_path == "STDERR")
        return {&std::cout, [](auto*&) {}};
    else if(cfg_output_path.empty())
        return {&std::clog, [](auto*&) {}};

    auto  output_file = get_output_filename(fname, ext);
    auto* _ofs        = new std::ofstream{output_file};

    LOG_IF(FATAL, !_ofs && !*_ofs) << fmt::format("Failed to open {} for output", output_file);
    ROCP_ERROR << "Opened result file: " << output_file;

    return {_ofs, [](std::ostream*& v) {
                if(v) dynamic_cast<std::ofstream*>(v)->close();
                delete v;
                v = nullptr;
            }};
}

output_file::~output_file()
{
    if(m_stream)
        ROCP_INFO << "Closing result file: " << m_name;
    else
        ROCP_WARNING << "output_file::~output_file does not have a output stream instance!";

    m_dtor(m_stream);
}
}  // namespace tool
}  // namespace rocprofiler
