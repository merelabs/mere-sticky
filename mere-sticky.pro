TEMPLATE = subdirs
CONFIG +=ordered
SUBDIRS = \
        mere-sticky-lib     \  # mere-sticky-lib
        mere-sticky-app     \  # mere-sticky-app

mere-sticky-app.depends   = mere-sticky-lib
