#ifndef MERESTICKYGLOBAL_H
#define MERESTICKYGLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MERE_STICKY_LIB)
#  define MERE_STICKY_LIBSPEC Q_DECL_EXPORT
#else
#  define MERE_STICKY_LIBSPEC Q_DECL_IMPORT
#endif

#endif // MERESTICKYGLOBAL_H
