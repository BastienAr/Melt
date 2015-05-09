// ABLETON
#include "src/ableton/alsaudiotrack.h"

// IO
#include "src/io/alsfilestreambase.h"


M_NAMESPACE_ABLETON_BEGIN


AlsAudioTrack::AlsAudioTrack()
: Id(0)
{
  QHash<QString, QPair<CreateVarLambda, SetVarLambda>> manipulatorConcat =  decltype(_classManipulator){
            { "Id", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsAudioTrack::setId)) }
};

  _classManipulator.unite(manipulatorConcat);

  _tagName = "AudioTrack";
}

void AlsAudioTrack::setId(const QString &r_value_)
{
  Id = r_value_.toInt();
}

void AlsAudioTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, {{"Id", QString::number(Id)}},r_indentLvl_);
  ++r_indentLvl_;
  AlsTrack::write(p_fos_, r_indentLvl_);
  p_fos_->write(this->_garbage);
  --r_indentLvl_;
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

AlsAudioTrack::~AlsAudioTrack()
{

}


M_NAMESPACE_ABLETON_END
