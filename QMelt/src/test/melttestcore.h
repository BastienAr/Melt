#pragma once
#include "common.h"

// QT
#include <QObject>


M_NAMESPACE_TEST_BEGIN


class MeltTestCore : public QObject
{
  Q_OBJECT
public:
  ~MeltTestCore() {}

  static void testParser();

  static void testStringComparator();

  static void testDepthFirstTraversal();

  static void testQObjectToString();

protected:
  explicit MeltTestCore(QObject *parent = 0) {}
};


M_NAMESPACE_TEST_END
