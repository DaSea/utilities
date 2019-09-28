import sqlite3

conn = sqlite3.connect('text.db')
cursor = conn.cursor()
cursor.execute('create table user (id varchar(20) primary key, name varchar(20))')
cursor.execute('insert into user (id, name) values(\'1\', \'ding\')')
print(cursor.rowcount)
cursor.close()
conn.commit()
conn.close()
