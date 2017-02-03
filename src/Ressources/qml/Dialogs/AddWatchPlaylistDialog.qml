import QtQuick 2.4
import QtQuick.Dialogs 1.2

FileDialog {
    id: loadWatchPlaylistDialog
    selectExisting: false
    selectFolder: true
    selectMultiple: false
    onAccepted: uiCore.mediaController.addWatchPlaylist(folder)
    Component.onCompleted: open()
}
