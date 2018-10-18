#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QCoreApplication>
#include<QList>

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

    private:

        QString file_open;

        QStringList title;

        QList<studData> data;



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

             qDebug()<<"无法打开文件";
     }

     studData nowdata;

     QString titile_t(File.readLine());

         title = titile_t.split(" ", QString::SkipEmptyParts);

     while(!File.atEnd())
     {

         QString str(File.readLine());

         nowdata.sdata = str.split(" ", QString::SkipEmptyParts);

         if((nowdata.sdata).last() == "\n") nowdata.sdata.removeLast();

         if(nowdata.sdata.size()==0) continue;

         data.append(nowdata);

     }
     File.close();

      qDebug()<<title.size();


 }
      void ScoreSorter::doSort()         //排序输出函数
      {
          for(int i=0;i<data.size();i++)
          {
              myCmp cmp(i-1);
              std::sort(data.begin(),data.end(),cmp);
              qDebug().noquote().nospace()<<"排序之后输出数据，目前排序第"<<i<<"列："
              qDebug()<<title;
              for(int i=0;i<data.size();i++)
              {
              qDebug()<<data.at(i);
              }
              qDebug()<<"-------------------------------------------------------\n";

           }
      }



//void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
//{
    // 自定义qDebug
//}

int main()
{
    //qInstallMessageHandler(myMessageOutput);
    QString datafile = "F:/qthomework/homework/homework2/data.txt";

    QFile file("sorted_"+datafile);
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
