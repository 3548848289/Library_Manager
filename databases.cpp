#include "databases.h"
#include<QElapsedTimer>
databases::databases()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");  //连接本地主机
    db.setPort(3306);
    db.setDatabaseName("datatest12");
    db.setUserName("root");
    db.setPassword("Mysql20039248");
    bool ok = db.open();
    if (ok)
        qDebug()<<" open database";
    else
        qDebug()<<"error";

    QStringList tab = db.tables(QSql::Tables);
    qDebug() << tab;                //打印用户可访问的数据数据表
    query = QSqlQuery(db);          //这个语句很重要

    create();

}

void databases::create()
{
    QElapsedTimer timer;
    timer.start();
    // 检查表是否已经存在
    bool tableExists = false;
    QSqlQuery checkTableQuery("SELECT table_name FROM information_schema.tables WHERE table_schema = 'datatest12' AND table_name = 'book';");
    if (checkTableQuery.next()) {
        tableExists = true; // 表存在
    }

    // 如果表不存在，则创建表
    if (!tableExists) {
        QSqlQuery createTableQuery;
        bool success = createTableQuery.exec("CREATE TABLE book (book_size INT PRIMARY KEY, book_much INT, book_name VARCHAR(10), book_status BOOL, book_price FLOAT)");

        if (!success) {
            QSqlError lastError = createTableQuery.lastError();
            qDebug() << lastError.driverText() << QObject::tr("创建失败");
        } else {
            qDebug() << QObject::tr("创建耗时：%1 ms").arg(timer.elapsed());
        }
    } else {
        qDebug() << "Table already exists.";
    }


}

void databases::insert(book& b)
{
    QSqlQuery query;
    query.prepare("INSERT INTO book (book_size, book_much, book_name, book_status, book_price) "
                  "VALUES (:size, :much, :name, :status, :price)");
    query.bindValue(":much", b.book_much);
    query.bindValue(":name", b.book_name);
    query.bindValue(":status", b.book_status);
    query.bindValue(":price", b.book_price);
    if (!query.exec())
        qDebug() << "Failed to insert data into table.";
    else
        qDebug() << "Data inserted successfully.";


}
