#include "prometheus/histogram_builder.h"

#include "prometheus/registry.h"

namespace prometheus {

detail::HistogramBuilder BuildHistogram() { return {}; }

namespace detail {

HistogramBuilder& HistogramBuilder::Labels(
    const std::map<std::string, std::string>& labels) {
  labels_ = labels;
  return *this;
}

HistogramBuilder& HistogramBuilder::Name(const std::string& name) {
  name_ = name;
  return *this;
}

HistogramBuilder& HistogramBuilder::Help(const std::string& help) {
  help_ = help;
  return *this;
}

std::shared_ptr<Family<Histogram>> HistogramBuilder::Register(Registry& registry) {
  return registry.Add<Histogram>(name_, help_, labels_);
}
}  // namespace detail
}  // namespace prometheus
