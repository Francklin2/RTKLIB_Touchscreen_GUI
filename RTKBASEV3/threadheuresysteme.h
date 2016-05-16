#ifndef THREADHEURESYSTEME_H
#define THREADHEURESYSTEME_H
 #include <QThread>
#include <QVector>


class ThreadHeureSysteme : public QThread
{
    Q_OBJECT   // mot magique dixit JEAN-MI
    public:

          ThreadHeureSysteme(QObject *parent=NULL);
          virtual ~ThreadHeureSysteme();

     signals:
            void heureretournee(int);

/*     public slots:
           void fermethread();
*/

     protected:
           virtual void run();
           int exec();

  //  ....

};


#endif // THREADHEURESYSTEME_H
