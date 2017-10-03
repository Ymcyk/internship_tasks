Qt.include("colors.js");

var rectangles = [];
var clock = [1, 2, 5, 8, 7, 6, 3, 0];

function changeAll() {
    for (var i = 0, len = rectangles.length; i < len; ++i) {
        if (i === 4) {
            rectangles[i].color = chooseRandomColor();
        } else {
            rectangles[i].color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
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
    for (var i = 0, len = rectangles.length; i < len; ++i) {
        if (rectangles[i].buttonId === buttonId) {
            return rectangles[i];
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

function createRectangles() {
    var xShift = mainWindow.width / 3;
    var yShift = mainWindow.height / 3;

    for (var i = 0; i < 9; ++i) {
        var obj = rectButton.createObject(mainWindow,
                                          {
                                              "x": Math.floor(i / 3) * xShift,
                                              "y": (i % 3) * yShift,
                                              "buttonId": i
                                          });
        rectangles.push(obj);
    }
}
