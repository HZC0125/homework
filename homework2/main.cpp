#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QCoreApplication>
#include<QList>
#include <QVector>
namespace SK
{
enum SortKind
{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}



typedef struct
{

    QStringList sdata;

} studData;

        // 请补全结构定义


QDebug operator<< (QDebug d, const studData &data)
{
   for(int i=0;i<data.sdata.size();i++)
    {
       d.noquote()<<data.sdata.at(i);
    }
   qDebug()<<"";
                                                // 请补全运算符重载函数，使其可以直接输出studData结构
    return d;
}

// 比较类，用于std::sort第三个参数
class myCmp
{
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{

   return d1.sdata.at(currentColumn+1)>d2.sdata.at(currentColumn+1);

}
        // ...
    // 请补全运算符重载函数
    // ...
    //





class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);//定义ScoreSorter构造函数
    void readFile();
    void doSort();
    void output(quint8 line);
    private:

        QString file_open;

        QStringList title;

        QList<studData> tdata;

        studData ldata;

    // ...
    // 请补全该类，使其实现上述要求
    // ...
};

// 请补全
ScoreSorter::ScoreSorter(QString dataFile)
{
 file_open=dataFile;
}
 void ScoreSorter::readFile() //读文件函数

 {

     QFile File(file_open);

     if(!File.open(QIODevice::ReadOnly | QIODevice::Text))
     {

             qDebug()<<"无法打开文件"<<endl;
     }



     QString titile_t(File.readLine());

         title = titile_t.split(" ", QString::SkipEmptyParts);

     while(!File.atEnd())
     {

         QString str(File.readLine());

         ldata.sdata = str.split(" ", QString::SkipEmptyParts);

         if((ldata.sdata).last() == "\n") ldata.sdata.removeLast();

         if(ldata.sdata.size()==0) continue;

         tdata.append(ldata);

     }
     File.close();

      qDebug()<<title.size();


 }
      void ScoreSorter::doSort() //排序输出函数
      {
          for(int i=0;i<ldata.sdata.size();i++)
          {
              myCmp cmp(i-1);
              std::sort(tdata.begin(),tdata.end(),cmp);
              qDebug().noquote().nospace()<<"排序之后输出数据，目前排序第"<<i<<"列：";
              qDebug()<<title;
              for(int i=0;i<tdata.size();i++)

              qDebug()<<tdata.at(i);

              qDebug()<<"-------------------------------------------------------\n";
              output(i);

           }
      }

      void ScoreSorter::output(quint8 line)    // 输出信息至文件中

      {



          QFile File("F:/qthomework/homework/build-homework2-Desktop_Qt_5_9_3_MinGW_32bit-Debug/debug/sorted_data.txt");

             //以追加方式打开

             File.open(QIODevice::ReadWrite | QIODevice::Append);

             QTextStream out(&File);

             out.setCodec("UTF-8");

             out<<QString("排序后输出，当前排序第").toUtf8()<<line <<QString(" 列：").toUtf8()<<"\n";

             //输出表头

             for(int i=0;i<ldata.sdata.size();i++)

                 out<<ldata.sdata.at(i)<<"\t";

             out<<'\n';

             //输出数据

             for(int i=0;i<tdata.count();i++)

             {

                 for(int j=0;j<ldata.sdata.count()-1;j++)

                 {

                     out<<tdata.at(i).sdata.at(j)<<"\t"<<"\t";

                 }

                 out<<"\n";

             }

             File.close();
      }

//void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
//{
    // 自定义qDebug
//}

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    //qInstallMessageHandler(myMessageOutput);
    QString datafile = "F:/qthomework/homework/build-homework2-Desktop_Qt_5_9_3_MinGW_32bit-Debug/debug/data.txt";

    QFile file("F:/qthomework/homework/build-homework2-Desktop_Qt_5_9_3_MinGW_32bit-Debug/debug/sorted_data.txt"+datafile);
        if (file.exists())
        {
            file.remove();
        }

        // 如果排序后文件已存在，则删除之


    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}
