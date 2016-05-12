import QtQuick 2.0

Rectangle {
    function show (system, cb) {
        return cb()
    }

    function hide (cb) {
        return cb()
    }
}
