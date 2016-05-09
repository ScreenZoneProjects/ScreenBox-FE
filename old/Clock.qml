import QtQuick 2.0

Item {

    var clockLocale = Qt.locale("fr_FR")

    Text
    {
        id: dateTimeText
        color: "#ffffff"
    }

    function timeChanged() {
        var date = new Date;
        hours = internationalTime ? date.getUTCHours() + Math.floor(clock.shift) : date.getHours()
        night = ( hours < 7 || hours > 19 )
        minutes = internationalTime ? date.getUTCMinutes() + ((clock.shift % 1) * 60) : date.getMinutes()
        seconds = date.getUTCSeconds()
        dateTimeText.text = date.toLocaleDateString(clockLocale)
    }

    Timer {
        interval: 100
        running: true
        repeat: true
        onTriggered: clock.timeChanged()
    }
}

