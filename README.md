# CSV2JSON

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
