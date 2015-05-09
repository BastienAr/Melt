// ABLETON
#include "src/ableton/alsmiditrack.h"
#include "src/ableton/alsdevicechain.h"

// IO
#include "src/io/alsfilestreambase.h"

M_NAMESPACE_ABLETON_BEGIN


AlsMidiTrack::AlsMidiTrack()
: Id(0)
, DeviceChain(QSharedPointer<AlsDeviceChain>())
{
  QHash<QString, QPair<CreateVarLambda, SetVarLambda>> manipulatorConcat =  decltype(_classManipulator){
       { "Id", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsMidiTrack::setId)) },
       { "DeviceChain", qMakePair(static_cast<CreateVarLambda>(&AlsMidiTrack::createDeviceChain), nullptr) }
};

  _classManipulator.unite(manipulatorConcat);

  _tagName = "MidiTrack";
}

void AlsMidiTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, {{"Id", QString::number(Id)}},r_indentLvl_);
  ++r_indentLvl_;
  AlsTrack::write(p_fos_, r_indentLvl_);
  DeviceChain->write(p_fos_, r_indentLvl_);
  p_fos_->write(this->_garbage);
  --r_indentLvl_;
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

void AlsMidiTrack::setId(const QString &r_value_)
{
  Id = r_value_.toInt();
}

QSharedPointer<QObject> AlsMidiTrack::createDeviceChain()
{
  DeviceChain = QSharedPointer<AlsDeviceChain>(new AlsDeviceChain());
  return DeviceChain.staticCast<QObject>();
}

AlsMidiTrack::~AlsMidiTrack()
{
  DeviceChain.clear();
}


M_NAMESPACE_ABLETON_END
