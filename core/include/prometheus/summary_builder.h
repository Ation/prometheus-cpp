#pragma once

#include <map>
#include <memory>
#include <string>

namespace prometheus {

template <typename T>
class Family;
class Summary;
class Registry;

namespace detail {
class SummaryBuilder;
}

detail::SummaryBuilder BuildSummary();

namespace detail {
class SummaryBuilder {
 public:
  SummaryBuilder& Labels(const std::map<std::string, std::string>& labels);
  SummaryBuilder& Name(const std::string&);
  SummaryBuilder& Help(const std::string&);
  std::shared_ptr<Family<Summary>> Register(Registry&);

 private:
  std::map<std::string, std::string> labels_;
  std::string name_;
  std::string help_;
};
}  // namespace detail

}  // namespace prometheus
