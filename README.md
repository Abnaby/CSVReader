# CSVReader
CSV Reader File Mangment  
![N|Solid](https://img.icons8.com/nolan/2x/csv.png)  
This is a small and easy to use library to Read small CSV files.  
## Motivation  
I'm working on an academic project that depends on taking data from a CSV file. So I thought about making a library that serves this purpose and develop it in the learning road.  
So, In version one (V1) this library serves this project in the first place.  
## C++ Version  
C++11 is the minimum version required.  
## Getting Start with small Example:  
```cpp
#include "CSVReader.h"  
#define FILENAME "fileName.csv"
using namespace std ;  
int main(){  
  CSVReader in (FILENAME);  
  string str_Data[50];  
  //Print All Data in CSV file
  in.printCSV();
  // Get Data from specific column and indexing it in string array
  in.getCol(1,str_Data);
}
```
## Documentation:
The libary provides one class:
| Class | Usage |
| ------ | ------ |
| CSVReader | It's a CSV file management class that helps you to handle small CSV file extension. |  
### `Methods`
| Method Name | Usage |  Parameter | return |  Example |
| ------ | ------ |  ------ |  ------ | ------ |
| CSVReader(string)  | CSVReader Constructor that open file and <a href="#constructor-initialization">initialize</a> some attributes. |`string` - string contains filename with extension.|`void`|<a href="#in-main">Here</a>|
| setRowDelimeter(char) |Set Row Delimeter for CSV file.<br/> By default is `\n`. | `char` - Take single character represent Delimeter.   |`void`|<a href="#in-main">Here</a>|
| setColDelimeter(char) | Set Column Delimeter for CSV file.<br/> By default is `,`. | `char` -  Take single character represent Delimeter.|`void`|<a href="#in-main">Here</a>|
| getfileName(void) |  Get Working File Name. |`void`|`string` - String contains file name.|<a href="#in-main">Here</a>|
| printCSV(void) | Print All CSV file Information.  |`void`|`void` |<a href="#in-main">Here</a>|
| getNumOfCols(void) | Get Number of Columns in CSV File. |`void`  |`int` - Number of Columns in CSV file | <a href="#example-2">Here</a> |
| getNumOfRows(void) | Get Number of Rows in CSV File. | `void`  |`int` - Number of Rows in CSV file  | <a href="#example-2">Here</a> |
| getCol(int,string) | Read Specific Column from CSV file and indexing it on array (every cell in index).  |`int`- integer number represent number of Column.<br/> `string string_resultArr[]` - String array holds **the result**. | `void` | <a href="#example-2">Here</a> |
| getRow(int,string) | Read Specific Row from CSV file and indexing it on array (every cell in index). | `int`- integer number represent number of Row.<br/> `string string_resultArr[]` - String array holds **the result**. | `void` | <a href="#example-2">Here</a> |
| closeFile() | Close Working File.  | `void`  | `void` | <a href="#in-main">Here</a>  |
| ~CSVReader() | CSVReader <a href="#desstructor">Destructor</a> that close file. | `void`  | `void` | |  

# Examples  
### Constructor-Initialization
```cpp
CSVReader:: CSVReader(string string_fileWithExten)
{
	fileName = string_fileWithExten;
	fin.open(string_fileWithExten);
	numberOfRow = 0;
	numberOfCol = 0;
	COL_delimeter = ',';
	ROW_delimeter = '\n';
}
```
### In-main 
```cpp
#include "CSVReader.h"  
using namespace std ;  
int main(){  
 // Make Object from CSVReader Class
  CSVReader in ("fileName.csv");  
  // Re-set Row and Column Delimeter
  in.setRowDelimeter('\n');
  in.setColDelimeter(',');
  // Print File Name On Console screen
  cout << in.getfileName() << endl;
  // print All Info. on Console screen
  in.printCSV();
  fin.closeFile();
}
```
### Example-2
Print CSV file Column by Column using `getCol(int,string)` and  `getRow(int,string)`
```cpp
#include "CSVReader.h"  
using namespace std ;  
int main(){  
 // Make Object from CSVReader Class
  CSVReader in ("fileName.csv");  
  string str_Data[50];
  int numberOfCols = in.getNumOfCols();
  int numberOfRows = in.getNumOfRows();
  for(int i = 1 ; i <= getNumOfCols ; i++)
  {
    getCol(i,str_Data);
    for (int j = 0 ; j<numberOfRows ; j++)
    {
      cout << str_Data[j] << " ";
    }
    cout << endl ; 
  }
}
// Desstructor will close file auto.
```
### Desstructor
```cpp
CSVReader :: ~CSVReader(void)
{
	fin.close();
}
```

## Contributing  
Bug reports, feature requests, and so on are always welcome. Feel free to leave a note in the Issues section.
