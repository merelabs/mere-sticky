#include "stickyapp.h"

int main(int argc, char *argv[])
{
    StickyApp app(argc, argv);
    app.init();
    app.start();
    return app.exec();
}
