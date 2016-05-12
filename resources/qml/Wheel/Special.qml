import QtQuick 2.4

Rectangle {
    property string m_a_active
    property string m_a_default
    property double m_a_delay
    property double m_a_in
    property int m_a_length
    property double m_a_out
    property string m_a_start
    property string m_a_type
    property int m_a_x
    property int m_a_y

    property string m_b_active
    property string m_b_default
    property double m_b_delay
    property double m_b_in
    property int m_b_length
    property double m_b_out
    property string m_b_start
    property string m_b_type
    property int m_b_x
    property int m_b_y

    property string currentSystem: "Main Menu"

    color:  "transparent"

    Image {
        //source: "file:/"+_APP_DIR_+"/Media/"+currentSystem+"/Image/Special/SpecialA1.swf"
    }
    Image {
        //source: "file:/"+_APP_DIR_+"/Media/"+currentSystem+"/Image/Special/SpecialA2.swf"
    }
    Image {
        //source: "file:/"+_APP_DIR_+"/Media/"+currentSystem+"/Image/Special/SpecialB1.swf"
    }
    Image {
        //source: "file:/"+_APP_DIR_+"/Media/"+currentSystem+"/Image/Special/SpecialB2.swf"
    }
}
