# CSV2JSON

Project requirement:
You are requested to write an application that converts a given CSV formatted file to JSON format in C programming language. The application must get all the necessary parameters for its operation from the command line. The general usage of the application you are developing should be as follows: CSV2JSON <CSV filename> <json filename> <header=ON | OFF>Typical, example usage of the application is shown below: C:\> CSV2JSON test.csv result.jsonheader=OFF Your application should understand from the header parameter given in the command line whether the first line of the given csv file is to be considered as the column names line. If the header parameter is set to OFF, it should automatically use the names row1, row2 and column1, column2,..., columnN.


Available terminal commands
    Projemizin bulunduğu  klasörü belirten alana geçiş yapacagız.
    >cd klasorurl
    >cd C:\Users\Sulta\Downloads\CSV2JSON

    .exe  olusturmak icin 
    >gcc -o CSV2JSON main.c
    
    Eger ki projemizde Header=ON ise 
    >CSV2JSON "dosya.csv" "headerON_cikti.json" "header=ON"
    
    CSV dosyamızda header yoksa 
    >CSV2JSON "dosyaHeaderOFF.csv" "headerOFF_cikti.json" "header=OFF"
