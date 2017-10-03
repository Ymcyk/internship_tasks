CREATE TABLE temp(
    id integer primary key autoincrement,
    temperature real not null,
    datetime text default(datetime('now'))
);
