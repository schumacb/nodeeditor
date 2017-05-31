#pragma once

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

#include "NodeDataModel.hpp"
namespace QtNodes {

/// Simplified version of a NodeDataModel where setInData and outData are not
/// used. Eg. in a headless mode.
class NODE_EDITOR_PUBLIC NodeModel : public NodeDataModel {
  Q_OBJECT
public:
  NodeModel();
  virtual ~NodeModel() = default;

  /// setInData should not be used
  void setInData(std::shared_ptr<NodeData> nodeData, PortIndex port);
  /// outData should not be used
  std::shared_ptr<NodeData> outData(PortIndex port);
};

/// Further simplified version of a NodaModel wher no caption is used.
class NODE_EDITOR_PUBLIC SimpleNodeModel : public NodeModel {
  Q_OBJECT
public:
  SimpleNodeModel();
  virtual ~SimpleNodeModel() = default;

  /// returns an empty string as caption
  QString caption() const;

  /// caption is invisible by default
  bool captionVisible() const;
};

/// Nodes, that don't need a name
class NODE_EDITOR_PUBLIC AnonymousNodeModel : public SimpleNodeModel {
  Q_OBJECT
public:
  AnonymousNodeModel();
  virtual ~AnonymousNodeModel() = default;

  /// returns an empty string as name
  QString name() const;
};
}
