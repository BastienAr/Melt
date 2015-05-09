#include "src/ui/meltui.h"
#include "ui_meltui.h"
#include "src/app/meltcommandline.h"
#include "src/ableton/alsableton.h"
#include "src/ableton/alsliveset.h"
#include "src/ableton/alsname.h"
#include "src/ableton/alsmiditrack.h"
#include "src/ableton/alsdevicechain.h"
#include "src/ableton/alsclipslot.h"
#include "src/ableton/alsclipslotvalue.h"
#include "src/ableton/alsinnerclipslot.h"
#include "src/ableton/alsmidiclip.h"
#include "src/ableton/alsmainsequencer.h";

MeltUI::MeltUI(app::MeltApplication& app_, QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MeltUI)
, _app(app_)

{       
  ui->setupUi(this);
  this->setWindowTitle("Melt");
  this->setStyleSheet("background-color: rgb(127,127,127);");
  ui->tabWidget->tabBar()->setTabTextColor(0,Qt::white);
  ui->tabWidget->tabBar()->setTabTextColor(1,Qt::white);
  ui->tabWidget->tabBar()->setTabTextColor(2,Qt::white);

  if (_app.Arguments->isOk)
  {
    _remote = _app.getRemote();
    _local = _app.getLocal();
    _base= _app.getBase();
    _merge= _app.getMerge();

    ui->localCreatorValue->setText(_local->Creator);
    ui->localMinorValue->setText(_local->MinorVersion);
    ui->localMajorValue->setText(_local->MajorVersion);
    ui->localSchemaCCValue->setText(QString::number(_local->SchemaChangeCount));

    ui->remoteCreatorValue->setText(_remote->Creator);
    ui->remoteMinorValue->setText(_remote->MinorVersion);
    ui->remoteMajorValue->setText(_remote->MajorVersion);
    ui->remoteSchemaCCValue->setText(QString::number(_remote->SchemaChangeCount));

    QStandardItemModel *clipsModel = new QStandardItemModel(10,_local->LiveSet->Tracks.size());
    for (int i = 0; i < _local->LiveSet->Tracks.size(); ++i)
    {
      clipsModel->setHorizontalHeaderItem(i,new QStandardItem(_local->LiveSet->Tracks.at(i)->Name->EffectiveName));
      QSharedPointer<ableton::AlsMidiTrack> mt;
      if ((mt = _local->LiveSet->Tracks.at(i).dynamicCast<ableton::AlsMidiTrack>()) != nullptr) {
        for (int j = 0; j < mt->DeviceChain->MainSequencer->ClipSlotList.size(); ++j) {
          QSharedPointer<ableton::AlsClipSlotValue> csv = mt->DeviceChain->MainSequencer->ClipSlotList.at(j)->InnerClipSlot->Value;
          if (csv != nullptr && csv->MidiClip != nullptr)
          {
            QStandardItem *clipItem = new QStandardItem(csv->MidiClip->Name);
            clipsModel->setItem(j,i,clipItem);

          }
        }
      }
    }

    ui->tableView->setModel(clipsModel);



  }

}

MeltUI::~MeltUI()
{
  delete ui;
}
