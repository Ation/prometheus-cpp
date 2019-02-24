#pragma once

#include <memory>
#include <vector>


#include "CivetServer.h"
#include "prometheus/registry.h"

namespace prometheus {
namespace detail {
class MetricsHandler : public CivetHandler {
 public:
  MetricsHandler(const std::vector<std::weak_ptr<Collectable>>& collectables,
                 Registry& registry);

  bool handleGet(CivetServer* server, struct mg_connection* conn) override;

 private:
  std::vector<MetricFamily> CollectMetrics() const;

  const std::vector<std::weak_ptr<Collectable>>& collectables_;
  Family<Counter>& bytes_transferred_family_;
  std::shared_ptr<Counter> bytes_transferred_;
  Family<Counter>& num_scrapes_family_;
  std::shared_ptr<Counter> num_scrapes_;
  Family<Summary>& request_latencies_family_;
  std::shared_ptr<Summary> request_latencies_;
};
}
}
