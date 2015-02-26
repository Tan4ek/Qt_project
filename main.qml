import QtQuick 2.3
import QtQuick.Window 2.2
import Downloader 1.0;
import QtGraphicalEffects 1.0

Window {
    id: window;
    visible: true
    width: 480
    height: 360
    title: "Image Tooday";

    Downloader{
        id: downloader;
    }

    Item{
        x: window.width * 0.05;
        y: window.y * 0.05;
        width: window.width * 0.9;
        height: window.height * 0.65;
        Image{
            id: imageWallpape
            anchors.fill: parent;
            anchors.verticalCenter: parent.verticalCenter;
            source: "http://yandex.ru/images/today?size=1920x1080"
        }

        DropShadow{
            anchors.fill: imageWallpape
            horizontalOffset: 3
            verticalOffset: 5
            radius: 8.0
            samples: 16
            color: "#aa000000"
            source: imageWallpape
        }

        MouseArea{
            anchors.fill: parent;
            onDoubleClicked: downloader.openImage();
        }
    }

    Rectangle{
        id: buttonSetWallpape
        x: window.width * 0.2;
        y: window.height * 0.75;
        height: window.height * 0.2;
        width: window.width * 0.6;
        color: "green"
        Text{
            anchors.verticalCenter: parent.verticalCenter;
            anchors.horizontalCenter: parent.horizontalCenter;
            text: "Set Wallpape";
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 16
        }
        MouseArea{
            anchors.fill: parent;
            onClicked: downloader.setWallpape();
        }
    }

    DropShadow{
        anchors.fill: buttonSetWallpape
        horizontalOffset: 3
        verticalOffset: 5
        radius: 8.0
        samples: 16
        color: "#aa000000"
        source: buttonSetWallpape
    }
}
