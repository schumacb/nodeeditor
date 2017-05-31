#include "NodeModel.hpp"

using namespace QtNodes;

NodeModel::NodeModel() {}

void NodeModel::setInData(std::shared_ptr<QtNodes::NodeData> nodeData,
                          QtNodes::PortIndex port) {
  Q_UNUSED(nodeData)
  Q_UNUSED(port)
}

std::shared_ptr<NodeData> NodeModel::outData(PortIndex port) {
  Q_UNUSED(port)
  std::shared_ptr<NodeData> ptr;
  return ptr;
}

SimpleNodeModel::SimpleNodeModel() {}

QString SimpleNodeModel::caption() const { return QStringLiteral(""); }

bool SimpleNodeModel::captionVisible() const { return false; }
