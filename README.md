ErgoMusic
=========

ErgoMusic is a Qt-based open-source music player and manager.
It is inspired by iTunes for which I haven't found a suitable replacemement.

But why ?
---------

Long term Itunes user, I now share my time between multiple computers, all of them on linux.
Even though there is plenty of valuable music player, none met my requirements :
- Cross-platform (but primary use for Linux).
- No-streaming (I tend to travel and I prefer to have my music on my hard-drive).
- Intuitive music import system based on watch folder.
- Self-hosting server side to sync multiple client on playlist and songs.
- Simple UI : menu on the left, main view in the middle.
- Instant play behavior : when doucle-clik on a song it plays it, it doesn't add it to a queue-list.
- A felling of finished product, since I'm the one creating it, I'll be able to tune the software for the feeling I want.
- Thanks to QML, I should be possible to completly change the UI for touch screens while keeping the backend.

I'm also using this project to keep learning more about Qt, QML and C++.

How to compile
==============

Dependency Client:
Qt >= 5.6
TagLib (tested with TagLib 1.8).
Doxygen for documentation

### Linux:

*How I do it ?*

I am currently using Fedora 23 with QtCreator and Qt 5 SDK from Qt.io.

*How you can do it ?*

Install taglib package
Install Qt SDK from the qt.io website
Open project in Qt Creator.

### OS X

*How I do it ?*

Download and install MacPort/Homebrew
in a console :

   $ sudo port install libtag
   or
   $ brew install libtag

Download and install the Qt5 SDK from qt-project.org
using QtCreator from the SDK open the project and compile

*How you can do it ?*

**TODO**

### Window

not tested but beside some libraries madness it should work without a glitch.

Installation
============

Nothing currently planned

Contributing
============

I don't think it is worth contributing yet but feedback are always welcome.
