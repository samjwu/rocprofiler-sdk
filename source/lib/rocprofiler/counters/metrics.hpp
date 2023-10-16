#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include <hsa/hsa_ven_amd_aqlprofile.h>

#include "fmt/core.h"
#include "fmt/ranges.h"

namespace rocprofiler
{
namespace counters
{
// Base metrics (w/o instance information) defined in gfx_metrics/derrived.xml
class Metric
{
public:
    Metric() = default;
    Metric(std::string name,
           std::string block,
           std::string event,
           std::string dsc,
           std::string expr,
           std::string special,
           uint64_t    id)
    : name_(std::move(name))
    , block_(std::move(block))
    , event_(std::move(event))
    , description_(std::move(dsc))
    , expression_(std::move(expr))
    , special_(std::move(special))
    , id_(id)
    {}

    const std::string& name() const { return name_; }
    const std::string& block() const { return block_; }
    const std::string& event() const { return event_; }
    const std::string& description() const { return description_; }
    const std::string& expression() const { return expression_; }
    const std::string& special() const { return special_; }
    uint64_t           id() const { return id_; }
    bool               empty() const { return empty_; }

    friend bool operator<(Metric const& lhs, Metric const& rhs);

private:
    std::string name_        = {};
    std::string block_       = {};
    std::string event_       = {};
    std::string description_ = {};
    std::string expression_  = {};
    std::string special_     = {};
    int64_t     id_          = -1;
    bool        empty_       = false;
};

using MetricMap   = std::unordered_map<std::string, std::vector<Metric>>;
using MetricIdMap = std::unordered_map<uint64_t, Metric>;

/**
 * Get base hardware counters for all GFXs Map<GFX Name, Counters>
 */
MetricMap
getBaseHardwareMetrics();

/**
 * Get derived hardware metrics for all GFXs  Map<GFX Name, Counters>
 */
MetricMap
getDerivedHardwareMetrics();

/**
 * Combined map containing both base and derived counters
 */
const MetricMap&
getMetricMap();

/**
 * Get the metrics that apply to a specific agent. Supplied parameter
 * is the GFXIP of the agent.
 */
const std::vector<Metric>&
getMetricsForAgent(const std::string&);

/**
 * Get a map of metric::id() -> metric
 */
const MetricIdMap&
getMetricIdMap();
}  // namespace counters
}  // namespace rocprofiler

namespace fmt
{
// fmt::format support for metric
template <>
struct formatter<rocprofiler::counters::Metric>
{
    template <typename ParseContext>
    constexpr auto parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template <typename Ctx>
    auto format(rocprofiler::counters::Metric const& metric, Ctx& ctx) const
    {
        return fmt::format_to(
            ctx.out(),
            "Metric: {} [Block: {}, Event: {}, Expression: {}, Description: {}, id: {}]",
            metric.name(),
            metric.block(),
            metric.event(),
            metric.expression().empty() ? "<None>" : metric.expression(),
            metric.description(),
            metric.id());
    }
};

// fmt::format support for MetricMap
template <>
struct formatter<rocprofiler::counters::MetricMap>
{
    template <typename ParseContext>
    constexpr auto parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template <typename Ctx>
    auto format(rocprofiler::counters::MetricMap const& map, Ctx& ctx) const
    {
        std::string out;
        for(const auto& [gfxName, counters] : map)
        {
            out += fmt::format("Counters for {}\n\t{}\n", gfxName, fmt::join(counters, "\n\t"));
        }
        return fmt::format_to(ctx.out(), "{}", out);
    }
};
}  // namespace fmt
