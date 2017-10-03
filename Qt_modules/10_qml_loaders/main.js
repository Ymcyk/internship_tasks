Qt.include("colors.js");

var clock = [0, 3, 6, 7, 8, 5, 2, 1];

function changeAll() {
    for (var i = 0, len = 9; i < len; ++i) {
        if (i === 4) {
            repeater.itemAt(i).color = chooseRandomColor();
        } else {
            repeater.itemAt(i).color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
        }
    }
}

function getPair(number) {
    if (number === clock.length - 1) {
        return [clock[clock.length - 1], clock[0]];
    } else {
        return [clock[number], clock[number + 1]];
    }
}

function findElement(buttonId) {
    for (var i = 0, len = repeater.count; i < len; ++i) {
        var rect = repeater.itemAt(i);
        if (rect.buttonId === buttonId) {
            return rect;
        }
    }
}

function changeClockwise() {
    for (var i = 0, len = clock.length; i < len - 1; ++i) {
        var pair = getPair(i);

        var elem1 = findElement(pair[0]);
        var elem2 = findElement(pair[1]);

        var tmp = Qt.rgba(elem1.color.r, elem1.color.g, elem1.color.b, elem1.color.a);
        elem1.color = Qt.rgba(elem2.color.r, elem2.color.g, elem2.color.b, elem2.color.a);
        elem2.color = tmp;
    }
}
