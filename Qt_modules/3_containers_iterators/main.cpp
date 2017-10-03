#include "qlistexamples.h"
#include "qmapexamples.h"

int main()
{
    QListExamples list;

    list.indexBasedAccess();
    list.javaStyleIterators();
    list.stlStyleIterator();
    list.removeEven();

    QMapExamples map;

    map.indexBasedAccess();
    map.javaStyleIterators();
    map.stlStyleIterator();
    map.removeEven();
}


