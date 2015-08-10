import QtQuick 2.4

Item {
	id: mainItem
	property int itemAngle: 60

	width: 1920
	height: 1080

	ListModel {
		id: dataModel

		ListElement {
			color: "orange"
			width: 400
		}
		ListElement {
			color: "lightgreen"

		}
		ListElement {
			color: "orchid"

		}
		ListElement {
			color: "tomato"

		}
		ListElement {
			color: "skyblue"

		}
		ListElement {
			color: "hotpink"

		}
		ListElement {
			color: "darkseagreen"

		}

		ListElement {
			color: "darkseagreen"

		}

		ListElement {
			color: "darkseagreen"

		}

		ListElement {
			color: "darkseagreen"

		}

		ListElement {
			color: "darkseagreen"

		}

		ListElement {
			color: "darkseagreen"

		}

		ListElement {
			color: "darkseagreen"

		}
		ListElement {
			color: "darkseagreen"

		}
		ListElement {
			color: "darkseagreen"

		}
		ListElement {
			color: "darkseagreen"

		}
		ListElement {
			color: "darkseagreen"

		}
		ListElement {
			color: "darkseagreen"

		}
		ListElement {
			color: "darkseagreen"

		}
		ListElement {
			color: "darkseagreen"

		}
		ListElement {
			color: "darkseagreen"

		}
		ListElement {
			color: "darkseagreen"

		}
	}

	PathView {
		id: view

		anchors.fill: parent
		model: dataModel
		pathItemCount: 12

		path: Path {
			startX: mainItem.width
			startY: 0

			PathArc {
				x: mainItem.width
				y: mainItem.height
				radiusX: 50
				radiusY: 200
				direction: PathArc.Counterclockwise
			}
		}

		delegate: Rectangle {
			//property real rotationOrigin: PathView.origin

			width: 200
			height: 50
			color: model.color
			border {
				color: "black"
				width: 1
			}

			transform: Rotation {
				axis { x: 0; y: 0; z: 1 }
				angle: - (((y +( height  / 2)) / mainItem.height) - 0.5) * 100
				origin.x: width
				origin.y: height / 2
			}
		}
	}
}

