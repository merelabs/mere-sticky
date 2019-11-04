#include "merestickyapp.h"

int main(int argc, char *argv[])
{
    MereStickyApp app(argc, argv);
    app.init();
    app.start();
    return app.exec();
}
