.pragma library

var counter = 0;

function buttonPressed()
{
    ++counter;
}

function getDescription()
{
    return qsTr("Click %1").arg(counter);
}
