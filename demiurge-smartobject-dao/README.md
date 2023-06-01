
### Compiling and installing
    $ cd demiurge-smartobject-dao
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ sudo make install

Once compiled and installed the shared library and header files
are installed in the system.

If you do not have root access off what to install in a your local
argos distribution folder use (if your argos installation is located
in `~/argos-dist`):

    $ cmake .. -DCMAKE_INSTALL_PREFIX=~/argos-dist
    $ make
    $ make install

### How to use
This package is meant to be used as a library to allow unified access
to actuators and sensors for different automatic design methods.
It is used in AutoMoDe, Evostick and other automatic design methods.
