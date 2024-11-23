# CSV2JSON: CSV to JSON Converter in C

CSV2JSON is a command-line application written in C, designed to convert CSV files into JSON format. The application handles both CSV files with and without headers, automatically naming rows and columns when headers are absent.

---

## 📋 Project Requirements

- **Input**: A CSV file and a `header` parameter (`ON` or `OFF`).
- **Output**: A JSON file.
- **Functionality**:
  - When `header=ON`, the first row of the CSV is treated as column names.
  - When `header=OFF`, default names like `column1`, `column2`, ..., `columnN` are assigned.
  - Rows are named sequentially as `row1`, `row2`, etc., when no headers are provided.

---

## 🛠️ Usage Instructions

### 1. **Set Up the Environment**

Navigate to the folder containing the project files:
```bash
cd C:\Users\Sulta\Downloads\CSV2JSON

    .exe  olusturmak icin 
    >gcc -o CSV2JSON main.c
    
    Eger ki projemizde Header=ON ise 
    >CSV2JSON "dosya.csv" "headerON_cikti.json" "header=ON"
    
    CSV dosyamızda header yoksa 
    >CSV2JSON "dosyaHeaderOFF.csv" "headerOFF_cikti.json" "header=OFF"
