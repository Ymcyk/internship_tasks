var colors = [
        Qt.rgba(255, 255, 255, 1),
        Qt.rgba(255, 0, 0, 1),
        Qt.rgba(0, 255, 0, 1),
        Qt.rgba(0, 0, 255, 1)
];

function chooseRandomColor() {
    return colors[Math.floor(Math.random() * colors.length)];
}
