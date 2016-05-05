import QtQuick 2.0

Item {

	ListView {
		width: 100; height: 100

		model: platformsModel

		delegate: Item {
			height: 25
			width: 100

			Text {
				id: platformName
				text: name
				font: font
			}

			Text {
				id: platformManufacturerName
				text: manufacturerName
			}
		}
	}
	//    Item
	//    {
	//        Text
	//        {
	//            id: platformName
	//            text: "platform"
	//        }

	//        Image {
	//            id: platformPicture
	//            source: "file"
	//        }

	//        Image {
	//            id: platformLogo
	//            source: "file"
	//        }
	//    }

	//    PathView {
	//        id: platformPathView
	//        delegate: pathdelegate
	//        anchors.fill: parent
	//        model: 18 // provide a range of indices

	//        Keys.onLeftPressed: incrementCurrentIndex()
	//        Keys.onRightPressed: decrementCurrentIndex()

	//        highlightMoveDuration: 200

	//        focus: true
	//        interactive: true

	//        property int itemSize: 256

	//        path: Path {
	//            id: pathElement
	//            startX: 0
	//            startY: thePath.height / 2

	//            PathPercent { value: 0.0 }
	//            PathAttribute { name: "z"; value: 0 }
	//            PathAttribute { name: "origin"; value: 0 }
	//            PathLine {
	//                x: (thePath.width - thePath.itemSize) / 2
	//                y: thePath.height / 2
	//            }

	//            PathAttribute { name: "origin"; value: 0 }
	//            PathPercent { value: 0.49 }
	//            PathAttribute { name: "z"; value: 10 }

	//            PathLine { relativeX: 0; relativeY: 0 }
	//            PathLine {
	//                x: (thePath.width - thePath.itemSize) / 2 + thePath.itemSize
	//                y: thePath.height / 2
	//            }
	//            PathAttribute { name: "angle"; value: 0 }
	//            PathPercent { value: 0.51 }

	//            PathLine { relativeX: 0; relativeY: 0 }

	//            PathAttribute { name: "z"; value: 10 }
	//            PathAttribute { name: "origin"; value: thePath.itemSize }
	//            PathLine {
	//                x: thePath.width
	//                y: thePath.height / 2
	//            }
	//            PathPercent { value: 1 }
	//            PathAttribute { name: "z"; value: 0 }
	//            PathAttribute { name: "origin"; value: thePath.itemSize }
	//        }
	//    }

	//    Rectangle
	//    {
	//        id: platformHorizontalList
	//        width: parent.width
	//        height: parent.height * 0.2
	//    }
}
