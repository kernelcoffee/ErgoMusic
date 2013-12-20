#ifndef SONGSMODEL_H
#define SONGSMODEL_H

#include <QAbstractListModel>

class SongsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SongsModel(QObject *parent = 0);
    QVariant                data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    int                     rowCount(const QModelIndex &index = QModelIndex()) const;
    QHash<int, QByteArray>  roleNames() const;

signals:
    void        countChanged();

public slots:
    void        insert(int, const QString&);
    void        append(const QString&);
    void        remove(int);
    QObject*    get(int); // retrieve an item
    void        setProperty(int index, const QString& property, const QVariant& value);
private:
    enum Roles {
        Index = Qt::UserRole,
        Title,
        Author
    };

    QHash<int, QByteArray>  m_roles;
};

#endif // SONGSMODEL_H
