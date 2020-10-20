#include "taskstore.h"

TaskStore::~TaskStore()
{

}

TaskStore::TaskStore(QObject *parent)
    : BaseStore("task", parent)
{

}
