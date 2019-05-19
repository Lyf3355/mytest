#include <mysql/mysql.h>                                                                                      
#include <stdio.h>
#include <string.h>
int insert(int a,int b)
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char* server="localhost";
    char* user="root";
    char* password="123456";
    char* database="couse";
    char query[200]="insert into choose(stuID,couID) values(";
    sprintf(query,"%s%d,%d%s",query,a,b,")");
    int t,r;
    conn=mysql_init(NULL);
    if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
    {
        printf("Error connecting to database:%s\n",mysql_error(conn));

    }else{
        printf("Connected...\n");

    }
    t=mysql_query(conn,query);
    if(t)
    {
        printf("Error making query:%s\n",mysql_error(conn));

    }else{
        printf("insert success\n");

    }
    mysql_close(conn);
    return 0;

}

int myselect()
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char* server="localhost";
    char* user="root";
    char* password="123456";
    char* database="couse";
    char query[300]={0};
    //sprintf(query,"%s%s%s",query, q,"'");
    strcpy(query,"select * from teach");
    puts(query);
    int t;
    conn=mysql_init(NULL);
    if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
    {
        printf("Error connecting to database:%s\n",mysql_error(conn));
        return -1;

    }else{
        printf("Connected...\n");

    }
    t=mysql_query(conn,query);
    if(t)
    {
        printf("Error making query:%s\n",mysql_error(conn));

    }else{
        //  printf("Query made...\n");
        res=mysql_use_result(conn);

        if(res)
        {
            while((row=mysql_fetch_row(res))!=NULL)
            {   
                //printf("num=%d\n",mysql_num_fields(res));//列数
                for(t=0;t<mysql_num_fields(res);t++)
                {
                    printf("%8s ",row[t]);
                }
                printf("\n");
            }

        }else{
            printf("Don't find data\n");

        }
        mysql_free_result(res);
    }
    mysql_close(conn);
    return 0;
}                                

int main(int argc,char*argv[])
{
    if(argc!=3)
    {
        printf("error args\n");
        return -1;
    }
    myselect();
    int a=atoi(argv[1]);
    int b=atoi(argv[2]);
    insert(a,b);
    return 0;
}
